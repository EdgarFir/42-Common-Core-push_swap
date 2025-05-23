/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:14:21 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/23 03:09:27 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turkish_sort(int *stack_a, int *stack_b, int argc)
{
	t_opers	min_opers[2];
	int		i;
	int		b_size;
	int		a_size;
	int		*stacks[2];

	stacks[0] = stack_a;
	stacks[1] = stack_b;
	push_helper(stacks, argc - 1, 0, 1);
	push_helper(stacks, argc - 2, 1, 1);
	i = 0;
	a_size = argc - 3;
	b_size = 2;
	while (i++ < argc - 6)
	{
		set_oper(&min_opers[0], -1, -1);
		set_oper(&min_opers[1], -1, -1);
		calc_best_oper(stacks, a_size, b_size, min_opers);
		perfom_r(stacks, a_size, b_size, min_opers);
		perfom_rr(stacks, a_size, b_size, min_opers);
		push_helper(stacks, a_size, b_size, 1);
		a_size--;
		b_size++;
	}
	push_a(stacks, a_size, b_size);
}

int	fill_stack_a(int *stack_a, char **argv, int argc)
{
	int	i;
	int	nbr;

	i = 0;
	while (i < argc)
	{
		if (!is_nbr(argv[i]))
			return (0);
		nbr = ft_atoll(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		if (exists_in_list(stack_a, i, nbr))
			return (0);
		stack_a[i] = nbr;
		i++;
	}
	return (1);
}

void	sort_low(int *stack_a, int *stack_b, int nbr_count)
{
	int	i;
	int *stacks[2];
	int	a_size;
	int	b_size;

	if (nbr_count == 2)
	{
		if (stack_a[0] > stack_a[1])
			swap(stack_a, "sa", 2);
	}
	else if (nbr_count == 3)
		order_three_elems(stack_a);
	else if (nbr_count > 3)
	{
		i = 0;
		stacks[0] = stack_a;
		stacks[1] = stack_b;
		a_size = nbr_count;
		b_size = 0;
		push_helper(stacks, a_size, b_size, 1);
		order_three_elems(stack_a);
		push_b(stacks, 3, 1);
		rotate_a_min(stack_a, a_size);
	}
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	char	**split_nbr;

	if (argc > 1)
	{
		stack_a = ft_calloc(argc - 1, sizeof(int));
		stack_b = ft_calloc(argc - 1, sizeof(int));
		if (!stack_a || !stack_b || !fill_stack_a(stack_a, argv + 1, argc - 1))
			return (clean_and_return(stack_a, stack_b, 1, 1));
		if (is_sorted(stack_a, argc - 1))
			return (clean_and_return(stack_a, stack_b, 0, 0));
		if (argc < 6)
			sort_low(stack_a, stack_b, argc - 1);
		else
			turkish_sort(stack_a, stack_b, argc);
		return (clean_and_return(stack_a, stack_b, 0, 0));
	}
	ft_putstr_fd("Error\n", 2);
	return (1);
}
