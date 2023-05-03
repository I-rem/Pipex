/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:47:08 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/03 11:20:52 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		s1 = ft_strdup("\0");
	if (s2 == NULL)
		s2 = ft_strdup("\0");
	joined = malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;

	len = ft_strlen(s1);
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
