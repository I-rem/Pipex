/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:18:48 by ikayacio          #+#    #+#             */
/*   Updated: 2023/06/20 11:27:24 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi(char *str, t_list **a)
{
	long long	result;
	long long	sign;

	while (*str != '\0')
	{
		result = 0;
		sign = 1;
		while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '-')
			sign *= -1;
		if (*str == '-' || *str == '+')
			str++;	
		while (*str >= '0' && *str <= '9')
		{
			result = result * 10 + *str - 48;
			str++;
		}
		while (*str == 32 || (*str >= 9 && *str <= 12))
			str++;
		ft_lstadd_back(a, ft_lstnew(result * sign));
	}
}

int	arg_check(char **argv) // TO DO: Needs to work with the new system
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i] != NULL)
	{
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& (argv[i][j + 1] > '9' || argv[i][j + 1] < '0'))
			   return (0);
			else if (argv[i][j] != ' ' &&
				(argv[i][j] < '0' || argv[i][j] > '9'))
			return (0);
		}
	}
	return (1);
}

void	sort(int argc, t_list **a, t_list **b)
{
	if (argc == 2 || argc == 3)
		little_sort(a, argc, 'a');
	else if (argc == 4 || argc == 5)
		medium_sort(a, b);
	else
	{
		if (!is_sorted(*a))
		{
			make_positive(a);
			radix_sort(a, b);
		}
	};
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		return (0);
	if (arg_check(argv))
	{
		a = NULL;
		argv++;
		while (*(argv) != NULL)
		{	
			ft_atoi(*argv, &a);
			argv++;
		}
		b = NULL;
		sort(ft_lstsize(a), &a, &b);
		ft_lstclear(&a);
		ft_lstclear(&b);
	}
	else
		write(1, "Error\n", 6);
}
