/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:42:46 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/21 16:32:53 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max_index(int *stack)
{
	int i;
	int max_index;
	int max;

	i = 0;
	max = stack[0];
	max_index = 0;
	while (stack[i])
	{
		if (max < stack[i])
		{
			max = stack[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int find_min_index(int *stack)
{
	int i;
	int min_index;
	int min;

	i = 1;
	min = stack[0];
	min_index = 0;
	while (stack[i])
	{
		if (min > stack[i])
		{
			min = stack[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int calc_moves_a(int nbr, int *stack, int stack_size)
{
	int moves;

	moves = 0;
	while (moves < stack_size)
	{
		if ((stack[moves] < nbr && stack[(moves + 1) % stack_size] > nbr)
		|| (stack[moves] > nbr && stack[(moves + 1) % stack_size] < nbr))
		{
			if (is_valid_interval(stack, nbr, stack[moves], stack[(moves + 1) % stack_size]))
			{
				if (stack[(moves + 1) % stack_size] > nbr)
					moves++;
				break ;
			}
		}
		moves++;
	}
	return (moves);
}

int calc_moves_b(int nbr, int *stack, int stack_size)
{
	int moves;

	moves = 0;
	while (moves < stack_size)
	{
		if ((stack[moves] < nbr && stack[(moves + 1) % stack_size] > nbr)
		|| (stack[moves] > nbr && stack[(moves + 1) % stack_size] < nbr))
		{
			if (is_valid_interval(stack, nbr, stack[moves], stack[(moves + 1) % stack_size]))
			{
				if (stack[(moves + 1) % stack_size] < nbr)
					moves++;
				break ;
			}
		}
		moves++;
	}
	return (moves);
}

void calc_stack_b_moves(int nbr, int *stack_b, int stack_b_size, t_opers *oper)
{
	int moves;
	int min_i;
	int max_i;

	moves = 0;
	min_i = find_min_index(stack_b);
	max_i = find_max_index(stack_b);
	if (nbr < stack_b[min_i] || nbr > stack_b[max_i])
		moves = max_i;
	else
		moves = calc_moves_b(nbr, stack_b, stack_b_size);
	if (moves < stack_b_size / 2)
		oper->r = moves;
	else
		oper->rr = stack_b_size - moves;
}

void calc_stack_a_moves(int nbr_index, int stack_a_size, t_opers *oper)
{
	if (nbr_index < stack_a_size / 2)
		set_oper(oper, nbr_index, 0);
	else
		set_oper(oper, 0, stack_a_size - nbr_index);
}

int calc_rr_oper(t_opers *opers)
{
	int opers_count;

	opers_count = 0;
	if (opers[0].rr && opers[1].rr)
	{
		if (opers[0].rr < opers[1].rr)
			opers_count = opers[1].rr;
		else
			opers_count = opers[0].rr;
	}
	else if (opers[0].rr)
		opers_count = opers[0].rr;
	else if (opers[1].rr)
		opers_count = opers[1].rr;
	return (opers_count);
}

int calc_r_oper(t_opers *opers)
{
	int opers_count;

	opers_count = 0;
	if (opers[0].r && opers[1].r)
	{
		if (opers[0].r < opers[1].r)
			opers_count = opers[1].r;
		else
			opers_count = opers[0].r;
	}
	else if (opers[0].r)
		opers_count = opers[0].r;
	else if (opers[1].r)
		opers_count = opers[1].r;
	return (opers_count);
}

void set_min_opers(t_opers *min_opers, t_opers *tmp_opers)
{
	int min_opers_count;
	int	tmp_opers_count;

	min_opers_count = calc_r_oper(min_opers) + calc_rr_oper(min_opers);
	tmp_opers_count = calc_r_oper(tmp_opers) + calc_rr_oper(tmp_opers);
	if (min_opers_count < 0)
	{
		set_oper(&min_opers[0], tmp_opers[0].r, tmp_opers[0].rr);
		set_oper(&min_opers[1], tmp_opers[1].r, tmp_opers[1].rr);
	} 
	else if (tmp_opers_count < min_opers_count)
	{
		set_oper(&min_opers[0], tmp_opers[0].r, tmp_opers[0].rr);
		set_oper(&min_opers[1], tmp_opers[1].r, tmp_opers[1].rr);
	}
}

// Calculate best operation for each number
void calc_best_oper(int *stack_a, int *stack_b, t_opers min_opers[2])
{
	t_opers	tmp_opers[2];
	int		stack_a_size;
	int		stack_b_size;
	int		i;

	i = 0;
	stack_a_size = get_arr_size(stack_a);
	stack_b_size = get_arr_size(stack_b);
	while (i < stack_a_size)
	{
		set_oper(&tmp_opers[0], 0, 0);
		set_oper(&tmp_opers[1], 0, 0);
		calc_stack_a_moves(i, stack_a_size, &tmp_opers[0]);
		calc_stack_b_moves(stack_a[i], stack_b, stack_b_size, &tmp_opers[1]);
		set_min_opers(min_opers, tmp_opers);
		i++;
	}
}
/*
int main()
{
	t_opers oper[2];

	oper[0].r = -1;
	oper[0].rr = -1;

	oper[1].r = -1;
	oper[1].rr = -1;

	printf("%d\n", calc_struct_opers(oper));
}
*/