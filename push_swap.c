/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:14:21 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/22 01:08:38 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turkish_sort(int *stack_a, int *stack_b)
{
	t_opers	min_opers[2];
	int		i;
	int		stack_a_size;

	push(stack_a, stack_b, "pb");
	push(stack_a, stack_b, "pb");
	i = 0;
	stack_a_size = cal_arr_size(stack_a);
	while (i < stack_a_size - 3)
	{
		set_oper(&min_opers[0], -1, -1);
		set_oper(&min_opers[1], -1, -1);
		calc_best_oper(stack_a, stack_b, min_opers);
		perfom_r(stack_a, stack_b, min_opers);
		perfom_rr(stack_a, stack_b, min_opers);
		push(stack_a, stack_b, "pb");
		i++;
	}
	push_a(stack_a, stack_b, 3, cal_arr_size(stack_b));
}

int	fill_stack_a(int *stack_a, char **argv, int argc)
{
	int	i;
	int	nbr;

	i = 0;
	while (i < argc - 1)
	{
		nbr = ft_atoll(argv[i]);
		if (!nbr || nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		stack_a[i] = nbr;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	char	**split_nbr;
	int		n_size;

	if (argc > 1)
	{
		stack_a = ft_calloc((argc - 1) + 1, sizeof(int));
		stack_b = ft_calloc((argc - 1) + 1, sizeof(int));
		if (!stack_a || !stack_b || !fill_stack_a(stack_a, argv + 1, argc))
			return (clean_and_return(stack_a, stack_b, 1));
		turkish_sort(stack_a, stack_b);
		return (0);
	}
	ft_putstr_fd("Error\n", 2);
	return (1);
}
