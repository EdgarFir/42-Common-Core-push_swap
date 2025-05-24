/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 01:01:50 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/23 16:30:07 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *arr, char *oper, int size)
{
	int	temp;

	if (size > 1)
	{
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
		ft_printf("%s\n", oper);
	}
}

void	reverse_rotate(int *stack, int moves, char *oper, int size)
{
	int	last_elem;
	int	i;
	int	j;

	j = 0;
	while (j < moves)
	{
		last_elem = stack[size - 1];
		i = size - 1;
		while (i >= 1)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[0] = last_elem;
		j++;
		if (oper)
			ft_printf("%s\n", oper);
	}
}

void	rotate(int *stack, int moves, char *oper, int size)
{
	int	first_elem;
	int	i;
	int	j;

	j = 0;
	while (j < moves)
	{
		first_elem = stack[0];
		i = 0;
		while (i < size - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[size - 1] = first_elem;
		j++;
		if (oper)
			ft_printf("%s\n", oper);
	}
}

void	push(int **stacks, int push_from_size, int push_to_size, char *oper)
{
	int	elem_to_push;

	elem_to_push = stacks[0][0];
	if (push_from_size)
	{
		rotate(stacks[0], 1, NULL, push_from_size);
		if (!push_to_size)
			stacks[1][0] = elem_to_push;
		else
		{
			stacks[1][push_to_size] = elem_to_push;
			reverse_rotate(stacks[1], 1, NULL, push_to_size + 1);
		}
		ft_printf("%s\n", oper);
	}
}

void	push_helper(int **stacks, int a_size, int b_size, int mode)
{
	int	*temp[2];

	if (mode == 1)
		push(stacks, a_size, b_size, "pb");
	else
	{
		temp[0] = stacks[1];
		temp[1] = stacks[0];
		push(temp, b_size, a_size, "pa");
	}
}
