/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:35:19 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/23 02:12:13 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_min(int *stack_a, int stack_a_size)
{
	int	min_index;

	min_index = find_min_index(stack_a, stack_a_size);
	if (min_index < stack_a_size / 2)
		rotate(stack_a, min_index, "ra", stack_a_size);
	else
		reverse_rotate(stack_a, stack_a_size - min_index, "rra", stack_a_size);
}

void	order_three_elems(int *stack)
{
	int	min_index;
	int	max_index;

	max_index = find_max_index(stack, 3);
	if (max_index == 0)
		rotate(stack, 1, "ra", 3);
	else if (max_index == 1)
		reverse_rotate(stack, 1, "rra", 3);
	min_index = find_min_index(stack, 3);
	if (min_index == 1)
		swap(stack, "sa", 3);
}

void	push_a(int **stacks, int stack_a_size, int stack_b_size)
{
	order_three_elems(stacks[0]);
	push_b(stacks, stack_a_size, stack_b_size);
	rotate_a_min(stacks[0], stack_a_size + stack_b_size);
}

int	count_moves_a(int elem, int *stack, int size)
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
				if (stack[(movs + 1) % size] > elem)
					movs++;
				break ;
			}
		}
		movs++;
	}
	return (movs);
}

void	calc_moves_a(int nbr_index, int stack_a_size, t_opers *oper)
{
	if (nbr_index < stack_a_size / 2)
		set_oper(oper, nbr_index, 0);
	else
		set_oper(oper, 0, stack_a_size - nbr_index);
}
