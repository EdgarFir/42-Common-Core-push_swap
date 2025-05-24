/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_complex_opers_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 22:03:24 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/24 00:02:36 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rr(int **stacks, int a_size, int b_size)
{
	rotate(stacks[0], a_size);
	rotate(stacks[1], b_size);
}

void	rrr(int **stacks, int a_size, int b_size)
{
	reverse_rotate(stacks[0], a_size);
	reverse_rotate(stacks[1], b_size);
}

void	reverse_rotate(int *stack, int size)
{
	int	last_elem;
	int	i;

	last_elem = stack[size - 1];
	i = size - 1;
	while (i >= 1)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last_elem;
}

void	rotate(int *stack, int size)
{
	int	first_elem;
	int	i;

	first_elem = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = first_elem;
}
