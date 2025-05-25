/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_basic_opers_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:47:17 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/25 00:38:35 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ss(int **stacks, int a_size, int b_size)
{
	swap(stacks[0], a_size);
	swap(stacks[1], b_size);
}

void	swap(int *arr, int size)
{
	int	temp;

	if (size > 1)
	{
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
}

void	push(int **stacks, int *push_from_size, int *push_to_size)
{
	int	elem_to_push;

	elem_to_push = stacks[0][0];
	if (*push_from_size)
	{
		rotate(stacks[0], *push_from_size);
		stacks[0][*push_from_size - 1] = 0;
		if (!push_to_size)
			stacks[1][0] = elem_to_push;
		else
		{
			stacks[1][*push_to_size] = elem_to_push;
			(*push_to_size)++;
			reverse_rotate(stacks[1], *push_to_size);
		}
		(*push_from_size)--;
	}
}

void	push_helper(int **stacks, int *a_size, int *b_size, char *oper)
{
	int	*temp[2];

	if (ft_strcmp(oper, "pb\n") == 0)
		push(stacks, a_size, b_size);
	else
	{
		temp[0] = stacks[1];
		temp[1] = stacks[0];
		push(temp, b_size, a_size);
	}
}
