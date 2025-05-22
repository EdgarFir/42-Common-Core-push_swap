/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:39:52 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/22 00:34:11 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rr(int *stack_a, int *stack_b, int moves)
{
	int i;

	i = 0;
	while (i < moves)
	{
		printf("rr\n");
		i++;
	}
	rotate(stack_a, moves, NULL);
	rotate(stack_b, moves, NULL);

}

void rrr(int *stack_a, int *stack_b, int moves)
{
	int i;

	i = 0;
	while (i < moves)
	{
		printf("rrr\n");
		i++;
	}
	reverse_rotate(stack_a, moves, NULL);
	reverse_rotate(stack_b, moves, NULL);
}

void perfom_r(int *stack_a, int *stack_b, t_opers min_opers[2])
{
	if (min_opers[0].r && min_opers[1].r)
	{
		if (min_opers[0].r > min_opers[1].r)
		{
			rr(stack_a, stack_b, min_opers[1].r);
			rotate(stack_a, min_opers[0].r - min_opers[1].r, "ra");
		}
		else if (min_opers[0].r < min_opers[1].r)
		{
			rr(stack_a, stack_b, min_opers[0].r);
			rotate(stack_b, min_opers[1].r - min_opers[0].r, "rb");
		}
		else
			rr(stack_a, stack_b, min_opers[0].r);
	}
	else if (min_opers[0].r)
		rotate(stack_a, min_opers[0].r, "ra");
	else if (min_opers[1].r)
		rotate(stack_b, min_opers[1].r, "rb");
}

void perfom_rr(int *stack_a, int *stack_b, t_opers min_opers[2])
{
	if (min_opers[0].rr && min_opers[1].rr)
	{
		if (min_opers[0].rr > min_opers[1].rr)
		{
			rrr(stack_a, stack_b, min_opers[1].rr);
			reverse_rotate(stack_a, min_opers[0].rr - min_opers[1].rr, "rra");
		}
		else if (min_opers[0].rr < min_opers[1].rr)
		{
			rrr(stack_a, stack_b, min_opers[0].rr);
			reverse_rotate(stack_b, min_opers[1].rr - min_opers[0].rr, "rrb");
		}
		else
			rrr(stack_a, stack_b, min_opers[0].rr);
	}
	else if (min_opers[0].rr)
		reverse_rotate(stack_a, min_opers[0].rr, "rra");
	else if (min_opers[1].rr)
		reverse_rotate(stack_b, min_opers[1].rr, "rrb");
}