/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:38:34 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/22 01:15:56 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_moves(int nbr, int *stack, int size)
{
	int	movs;

	movs = 0;
	while (movs < size)
	{
		if ((stack[movs] < nbr && stack[(movs + 1) % size] > nbr)
			|| (stack[movs] > nbr && stack[(movs + 1) % size] < nbr))
		{
			if (valid_inter(stack, nbr, stack[movs], stack[(movs + 1) % size]))
			{
				if (stack[(movs + 1) % size] < nbr)
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
	min_i = find_min_index(stack_b);
	max_i = find_max_index(stack_b);
	if (nbr < stack_b[min_i] || nbr > stack_b[max_i])
		moves = max_i;
	else
		moves = calc_moves(nbr, stack_b, stack_b_size);
	if (moves < stack_b_size / 2)
		oper->r = moves;
	else
		oper->rr = stack_b_size - moves;
}

void	push_b(int *stack_a, int *stack_b, int stack_a_size, int stack_b_size)
{
	int	i;
	int	insert_i;
	int	min_index;
	int	max_index;

	i = 0;
	while (i < stack_b_size)
	{
		insert_i = 0;
		min_index = find_min_index(stack_a);
		max_index = find_max_index(stack_a);
		if (stack_b[0] < stack_a[min_index])
			insert_i = min_index;
		else if (stack_b[0] > stack_a[max_index])
			insert_i = min_index;
		else
			insert_i = calc_moves_h(stack_b[0], stack_a, stack_a_size);
		if (insert_i < stack_a_size / 2)
			rotate(stack_a, insert_i, "ra");
		else
			reverse_rotate(stack_a, stack_a_size - insert_i, "rra");
		push(stack_b, stack_a, "pa");
		stack_a_size++;
		i++;
	}
}
