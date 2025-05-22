/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:35:19 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/22 11:04:06 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_min(int *stack_a, int stack_a_size)
{
	int	min_index;

	min_index = find_min_index(stack_a);
	if (min_index < stack_a_size / 2)
		rotate(stack_a, min_index, "ra");
	else
		reverse_rotate(stack_a, stack_a_size - min_index, "rra");
}

void	order_three_elems(int *stack)
{
	int	min_index;
	int	max_index;

	max_index = find_max_index(stack);
	if (max_index == 0)
		rotate(stack, 1, "ra");
	else if (max_index == 1)
		reverse_rotate(stack, 1, "rra");
	min_index = find_min_index(stack);
	if (min_index == 1)
		swap(stack, "sa");
}

void	push_a(int *stack_a, int *stack_b, int stack_a_size, int stack_b_size)
{
	order_three_elems(stack_a);
	push_b(stack_a, stack_b, stack_a_size, stack_b_size);
	rotate_a_min(stack_a, cal_arr_size(stack_a));
}

int	calc_moves_h(int nbr, int *stack, int size)
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
				if (stack[(movs + 1) % size] > nbr)
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
