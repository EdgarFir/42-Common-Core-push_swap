/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:39:52 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/23 02:33:15 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(int **stacks, int a_size, int b_size, int moves)
{
	int	i;

	i = 0;
	while (i < moves)
	{
		ft_printf("rr\n");
		i++;
	}
	rotate(stacks[0], moves, NULL, a_size);
	rotate(stacks[1], moves, NULL, b_size);
}

void	rrr(int **stacks, int a_size, int b_size, int moves)
{
	int	i;

	i = 0;
	while (i < moves)
	{
		ft_printf("rrr\n");
		i++;
	}
	reverse_rotate(stacks[0], moves, NULL, a_size);
	reverse_rotate(stacks[1], moves, NULL, b_size);
}

void	perfom_r(int **stacks, int a_size, int b_size, t_opers *opers)
{
	if (opers[0].r && opers[1].r)
	{
		if (opers[0].r > opers[1].r)
		{
			rr(stacks, a_size, b_size, opers[1].r);
			rotate(stacks[0], opers[0].r - opers[1].r, "ra", a_size);
		}
		else if (opers[0].r < opers[1].r)
		{
			rr(stacks, a_size, b_size, opers[0].r);
			rotate(stacks[1], opers[1].r - opers[0].r, "rb", b_size);
		}
		else
			rr(stacks, a_size, b_size, opers[0].r);
	}
	else if (opers[0].r)
		rotate(stacks[0], opers[0].r, "ra", a_size);
	else if (opers[1].r)
		rotate(stacks[1], opers[1].r, "rb", b_size);
}

void	perfom_rr(int **stacks, int a_size, int b_size, t_opers *opers)
{
	if (opers[0].rr && opers[1].rr)
	{
		if (opers[0].rr > opers[1].rr)
		{
			rrr(stacks, a_size, b_size, opers[1].rr);
			reverse_rotate(stacks[0], opers[0].rr - opers[1].rr, "rra", a_size);
		}
		else if (opers[0].rr < opers[1].rr)
		{
			rrr(stacks, a_size, b_size, opers[0].rr);
			reverse_rotate(stacks[1], opers[1].rr - opers[0].rr, "rrb", b_size);
		}
		else
			rrr(stacks, a_size, b_size, opers[0].rr);
	}
	else if (opers[0].rr)
		reverse_rotate(stacks[0], opers[0].rr, "rra", a_size);
	else if (opers[1].rr)
		reverse_rotate(stacks[1], opers[1].rr, "rrb", b_size);
}
