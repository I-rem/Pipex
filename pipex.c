/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:50:05 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/02 18:21:24 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_argc(int argc)
{
	if (argc != 5)
	{
		write (2, "Usage: file1 cmd1 cmd2 file2\n", 29);
		exit(EXIT_FAILURE);
	}
}

pid_t	check_fork(pid_t pid)
{
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		print_error(4);
	}
	return (pid);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	p = (char *) malloc(len + 1);
	if (!p)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		p[len] = s1[len];
		len++;
	}
	p[len] = '\0';
	return (p);
}

void	make_cmd(char **cmd, char *argv)
{
	cmd[0] = ft_strdup("/bin/sh");
	cmd[1] = ft_strdup("-c");
	cmd[2] = ft_strdup(argv);
	cmd[3] = NULL;
}

int	main(int argc, char **argv)
{
	char			*cmd1[4];
	char			*cmd2[4];
	int				pipefd[2];
	static pid_t	pid1;
	static pid_t	pid2;

	check_argc(argc);
	make_cmd(cmd1, argv[2]);
	make_cmd(cmd2, argv[3]);
	check_file_command(argv[1], argv[4], cmd1, cmd2);
	if (pipe (pipefd) == -1)
		print_error(0);
	pid1 = check_fork(pid1);
	if (pid1 == 0)
		check_child(1, pipefd, open(argv[1], O_RDONLY), cmd1);
	pid2 = check_fork(pid2);
	if (pid2 == 0)
		check_child(2, pipefd, open (argv[4], O_WRONLY | O_CREAT
				| O_TRUNC, 0644), cmd2);
	close_parent(pipefd, pid1, pid2);
	return (0);
}
