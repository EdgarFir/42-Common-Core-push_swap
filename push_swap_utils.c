/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:42:46 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/21 23:54:19 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int clean_and_return(int *stack_a, int *stack_b, int status)
{
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	return (status);
}

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

void set_oper(t_opers *oper, int r, int rr)
{
	oper->r = r;
	oper->rr = rr;
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
