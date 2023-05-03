/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:12:45 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/03 11:22:30 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

void	close_parent(int *pipefd, pid_t pid1, pid_t pid2);
void	check_file_command(char *f1, char *f2, char **cmd1, char **cmd2);
pid_t	check_fork(pid_t pid);
void	check_child(int flag, int *pipefd, int file_fd, char **cmd);
void	print_error(int flag);
void	ft_putstr_fd(char *s, int fd);
void	check_argc(int argc);
char	*ft_strdup(const char *s1);
void	make_cmd(char **cmd, char *argv);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
#endif
