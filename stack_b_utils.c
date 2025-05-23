/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:38:34 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/23 02:13:43 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_moves_b(int elem, int *stack, int size)
{
	int	movs;
	int	elems[2];

	movs = 0;
	while (movs < size)
	{
		if ((stack[movs] < elem && stack[(movs + 1) % size] > elem)
			|| (stack[movs] > elem && stack[(movs + 1) % size] < elem))
		{
			elems[0] = stack[movs];
			elems[1] = stack[(movs + 1) % size];
			if (valid_inter(stack, elem, elems, size))
			{
				if (stack[(movs + 1) % size] < elem)
					movs++;
				break ;
			}
		}
		movs++;
	}
	return (movs);
}

void	calc_moves_b(int nbr, int *stack_b, int stack_b_size, t_opers *oper)
{
	int	moves;
	int	min_i;
	int	max_i;

	moves = 0;
	min_i = find_min_index(stack_b, stack_b_size);
	max_i = find_max_index(stack_b, stack_b_size);
	if (nbr < stack_b[min_i] || nbr > stack_b[max_i])
		moves = max_i;
	else
		moves = count_moves_b(nbr, stack_b, stack_b_size);
	if (moves < stack_b_size / 2)
		oper->r = moves;
	else
		oper->rr = stack_b_size - moves;
}

void	push_b(int **stacks, int a_size, int b_size)
{
	int	i;
	int	insert_i;
	int	min_index;
	int	max_index;

	i = 0;
	while (i < b_size)
	{
		insert_i = 0;
		min_index = find_min_index(stacks[0], a_size);
		max_index = find_max_index(stacks[0], a_size);
		if (stacks[1][0] < stacks[0][min_index])
			insert_i = min_index;
		else if (stacks[1][0] > stacks[0][max_index])
			insert_i = min_index;
		else
			insert_i = count_moves_a(stacks[1][0], stacks[0], a_size);
		if (insert_i < a_size / 2)
			rotate(stacks[0], insert_i, "ra", a_size);
		else
			reverse_rotate(stacks[0], a_size - insert_i, "rra", a_size);
		push_helper(stacks, a_size, b_size, 2);
		a_size++;
		i++;
	}
}
