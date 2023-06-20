/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:42:57 by ikayacio          #+#    #+#             */
/*   Updated: 2023/06/20 11:45:38 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium_sort(t_list **lst, t_list **lst_b)
{
	int	min;

	if (is_sorted(*lst) && *lst_b != NULL)
	{
		push(lst_b, lst, 'a');
		medium_sort(lst, lst_b);
	}
	if (!is_sorted(*lst))
	{
		if (ft_lstsize(*lst) == 3)
			little_sort(lst, 3, 'a');
		min = find_min(*lst);
		if ((*lst)->content == min)
			push(lst, lst_b, 'b');
		else if ((*lst)->next->content == min)
			swap(lst, 'a');
		else if (find_pos(*lst, min) > ft_lstsize(*lst) / 2)
			reverse_rotate(lst, 'a');
		else
			rotate(lst, 'a');
		medium_sort(lst, lst_b);
	}
}

void	little_sort(t_list **lst, int argc, char mode)
{
	if (argc == 2 && !is_sorted(*lst))
		swap(lst, mode);
	else if (argc == 3 && !is_sorted(*lst))
	{
		if ((*lst)->content > (*lst)->next->content
			&& (*lst)->content > (*lst)->next->next->content)
		{
			if ((*lst)->next->content > (*lst)->next->next->content)
			{
				swap(lst, mode);
				reverse_rotate(lst, mode);
			}
			else
				rotate(lst, mode);
		}
		else if ((*lst)->content < (*lst)->next->content)
		{
			reverse_rotate(lst, mode);
			if (!is_sorted(*lst))
				swap(lst, mode);
		}
		else
			swap(lst, mode);
	}	
}

void	pa(t_list **a, t_list **b)
{
	while (ft_lstsize(*b) > 0)
		push(b, a, 'a');
}

void	radix_sort(t_list **a, t_list **b)
{
	t_list	*temp;

	while (find_max(*a))
	{
		temp = *a;
		while (temp != NULL && temp -> content % 2 == 0)
			temp = temp -> next;
		if (temp != NULL)
			temp -> checked = 1;
		while (has_lastbit_zero(*a))
		{
			if (((*a)-> content & 1) == 0)
				push(a, b, 'b');
			else
				rotate(a, 'a');
		}
		if (temp != NULL)
		{
			while ((*a)->checked != 1)
				rotate(a, 'a');
			(*a)-> checked = 0;
		}
		pa(a, b);
		right_shift(a);
	}
}
