/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:14:21 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/25 00:36:02 by edfreder         ###   ########.fr       */
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
	int			i;
	long long	nbr;

	i = 0;
	while (i < argc)
	{
		if (!argv[i][0])
			return (0);
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

void	order_low_three_elems(int **stacks, int b_size)
{
	int	max_index;

	max_index = find_max_index(stacks[0], 3);
	if (max_index == 0)
	{
		if (stacks[1][0] < stacks[1][b_size - 1])
			rr(stacks, 3, b_size, 1);
		else
			rotate(stacks[0], 1, "ra", 3);
	}
	else if (max_index == 1)
	{
		if (stacks[1][0] < stacks[1][b_size - 1])
			rrr(stacks, 3, b_size, 1);
		else
			reverse_rotate(stacks[0], 1, "rra", 3);
	}
	if (stacks[0][0] > stacks[0][1])
	{
		if (stacks[1][0] < stacks[1][1])
			ss(stacks, 3, b_size);
		else
			swap(stacks[0], "sa", 3);
	}
}

void	sort_low(int *stack_a, int *stack_b, int nbr_count)
{
	int	i;
	int	*stacks[2];

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
		while (i < nbr_count - 3)
		{
			push_helper(stacks, nbr_count - i, i, 1);
			i++;
		}
		order_low_three_elems(stacks, nbr_count - 3);
		push_b(stacks, 3, nbr_count - 3);
		rotate_a_min(stack_a, nbr_count);
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
		if (argc < 7)
			sort_low(stack_a, stack_b, argc - 1);
		else
			turkish_sort(stack_a, stack_b, argc);
		return (clean_and_return(stack_a, stack_b, 0, 0));
	}
	return (0);
}
