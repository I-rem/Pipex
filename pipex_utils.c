/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:00:37 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/03 14:42:27 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_parent(int *pipefd, pid_t pid1, pid_t pid2)
{
	if (close(pipefd[0]) == -1 || close(pipefd[1]) == -1)
		print_error(0);
	if (waitpid(pid1, NULL, 0) == -1 || waitpid(pid2, NULL, 0) == -1)
		print_error(3);
}

void	check_file_command(char *f1, char *f2, char **cmd1, char **cmd2)
{
	int		input_fd;
	int		output_fd;

	input_fd = open (f1, O_RDONLY);
	if (input_fd == -1)
	{
		close(input_fd);
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	output_fd = open(f2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
	{
		close(input_fd);
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	if ((access(cmd1[0], (F_OK & X_OK)) == -1)
		|| (access(cmd2[0], (F_OK & X_OK)) == -1))
	{
		close(input_fd);
		close(output_fd);
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void	check_child(int flag, int *pipefd,	int file_fd, char **cmd)
{
	if (flag == 1)
	{
		close (pipefd[0]);
		dup2(file_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		execve(cmd[0], cmd, NULL);
		print_error(2);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		dup2 (file_fd, STDOUT_FILENO);
		execve(cmd[0], cmd, NULL);
		print_error(2);
	}
}

void	print_error(int flag)
{
	if (flag == 0)
		perror("pipe");
	else if (flag == 1)
		perror("dup2");
	else if (flag == 2)
		perror("execvp");
	exit(EXIT_FAILURE);
}
