/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:31:09 by ikayacio          #+#    #+#             */
/*   Updated: 2023/06/20 11:37:02 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char mode)
{
	t_list	*temp;

	temp = *stack;
	*stack = (*stack)-> next;
	temp -> next = (*stack)-> next;
	(*stack)-> next = temp;
	write(1, "s", 1);
	write(1, &mode, 1);
	write(1, "\n", 1);
}

void	push(t_list **src_stack, t_list **dst_stack, char mode)
{
	int		element;
	t_list	*temp;
	t_list	*newnode;

	temp = *src_stack;
	element = (*src_stack)->content;
	*src_stack = (*src_stack)->next;
	free(temp);
	newnode = (t_list *)malloc(sizeof(t_list));
	newnode->content = element;
	newnode->next = *dst_stack;
	*dst_stack = newnode;
	write(1, "p", 1);
	write(1, &mode, 1);
	write(1, "\n", 1);
}

void	rotate(t_list **stack, char mode)
{
	t_list	*temp;
	t_list	*temp2;

	temp = ft_lstlast(*stack);
	temp2 = *stack;
	temp -> next = *stack;
	*stack = (*stack)-> next;
	temp2 -> next = NULL;
	write(1, "r", 1);
	write(1, &mode, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_list **stack, char mode)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack;
	temp2 = *stack;
	while (temp2 -> next -> next != NULL)
		temp2 = temp2 -> next;
	*stack = ft_lstlast(*stack);
	(*stack)-> next = temp;
	temp2 -> next = NULL;
	write(1, "rr", 2);
	write(1, &mode, 1);
	write(1, "\n", 1);
}
