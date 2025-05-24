/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:45:49 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/23 02:33:35 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_rr_oper(t_opers *opers)
{
	int	opers_count;

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

int	calc_r_oper(t_opers *opers)
{
	int	opers_count;

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

void	calc_best_oper(int **stacks, int a_size, int b_size, t_opers *opers)
{
	t_opers	tmp_opers[2];
	int		i;

	i = 0;
	while (i < a_size)
	{
		set_oper(&tmp_opers[0], 0, 0);
		set_oper(&tmp_opers[1], 0, 0);
		calc_moves_a(i, a_size, &tmp_opers[0]);
		calc_moves_b(stacks[0][i], stacks[1], b_size, &tmp_opers[1]);
		set_min_opers(opers, tmp_opers);
		i++;
	}
}
