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

long	ft_atoi(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * sign);
}

int	arg_check(char **argv)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (argv[++i] != NULL)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648
			|| argv[i][0] == 0)
			return (0);
		sign = 0;
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				sign++;
				if (sign > 1)
					return (0);
			}
			else if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
		}
	}
	return (1);
}

int	order_check(char **argv)
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
	i = 1;
	while (argv[++i] != NULL)
		if (ft_atoi(argv[i]) < ft_atoi(argv[i - 1]))
			return (0);
	return (1);
}

void	sort(int argc, t_list **a, t_list **b)
{
	if (argc == 3 || argc == 4)
		little_sort(a, --argc, 'a');
	else if (argc == 5 || argc == 6)
		medium_sort(a, b);
	else
	{
		make_positive(a);
		radix_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc > 1)
	{
		if (arg_check(argv) && !order_check(argv))
		{
			a = ft_lstnew(ft_atoi(argv[1]));
			argv++;
			while (*(++argv) != NULL)
				ft_lstadd_back(&a, ft_lstnew(ft_atoi(*argv)));
			b = NULL;
			sort(argc, &a, &b);
			ft_lstclear(&a);
			ft_lstclear(&b);
		}
		else if (!arg_check(argv))
			write(1, "Error\n", 6);
	}
}
