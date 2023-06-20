/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:28:20 by ikayacio          #+#    #+#             */
/*   Updated: 2023/06/20 11:30:14 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				checked;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
void	little_sort(t_list **lst, int argc, char mode);
void	swap(t_list **stack, char mode);
void	push(t_list **src_stack, t_list **dst_stack, char mode);
void	rotate(t_list **stack, char mode);
void	reverse_rotate(t_list **stack, char mode);
void	medium_sort(t_list **lst, t_list **lst_b);
void	radix_sort(t_list **a, t_list **b);
int		is_sorted(t_list *lst);
int		find_min(t_list *lst);
int		find_max(t_list *lst);
int		find_pos(t_list *lst, int num);
int		is_sorted(t_list *lst);
void	make_positive(t_list **a);
void	right_shift(t_list **a);
int		has_lastbit_zero(t_list *a);
int		all_zero(t_list *a);
#endif
