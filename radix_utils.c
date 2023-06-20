/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:37:25 by ikayacio          #+#    #+#             */
/*   Updated: 2023/06/20 11:39:47 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_positive(t_list **a)
{
	t_list	*temp;
	int		min;

	min = find_min(*a);
	temp = *a;
	while (temp)
	{
		temp -> content -= min;
		temp = temp -> next;
	}
}

void	right_shift(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp)
	{
		temp->content = (temp->content >> 1);
		temp = temp->next;
	}
}

int	has_lastbit_zero(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp)
	{
		if ((temp -> content & 1) == 0)
			return (1);
		temp = temp -> next;
	}
	return (0);
}

int	all_zero(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp)
	{
		if (temp -> content != 0)
			return (0);
		temp = temp -> next;
	}
	return (1);
}
