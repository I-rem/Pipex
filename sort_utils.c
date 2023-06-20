/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:40:14 by ikayacio          #+#    #+#             */
/*   Updated: 2023/06/20 11:42:44 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	while (lst->next != NULL)
	{
		if (lst->content > 2147483647
			|| lst->content < -2147483648) // Not sure if this will work
		{
			write(1, "Error\n", 6);
			return (1);
		}
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	find_min(t_list *lst)
{
	int	min;

	min = lst->content;
	while (lst != NULL)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

int	find_max(t_list *lst)
{
	int	max;

	max = lst->content;
	while (lst != NULL)
	{
		if (lst ->content > max)
			max = lst -> content;
		lst = lst -> next;
	}
	return (max);
}

int	find_pos(t_list *lst, int num)
{
	int	pos;

	pos = 0;
	while (lst != NULL)
	{
		if (lst->content == num)
			return (pos);
		lst = lst->next;
		pos++;
	}
	return (-1);
}

/*
int	duplicate_check(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
	}
	return (1);
}
*/
