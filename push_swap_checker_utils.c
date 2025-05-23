/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:26:59 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/23 02:34:27 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	exists_in_list(int *list, int size, int nbr)
{
	int	i;

	if (size < 1)
		return (0);
	i = 0;
	while (i < size)
	{
		if (list[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int	is_valid(int *stack, int elem, int *cmp_elems, int size)
{
	int	i;
	int	higher;
	int	minor;

	higher = cmp_elems[0];
	minor = cmp_elems[1];
	i = 0;
	while (i < size)
	{
		if (stack[i] < higher && stack[i] > elem)
			return (0);
		if (stack[i] > minor && stack[i] < elem)
			return (0);
		i++;
	}
	return (1);
}

int	is_nbr(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[0] == '+' || nbr[0] == '-')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_inter(int *stack, int check_elem, int *cmp_elems, int size)
{
	int	temp;

	if (cmp_elems[0] > cmp_elems[1])
	{
		if (!is_valid(stack, check_elem, cmp_elems, size))
			return (0);
	}
	else
	{
		temp = cmp_elems[0];
		cmp_elems[0] = cmp_elems[1];
		cmp_elems[1] = temp;
		if (!is_valid(stack, check_elem, cmp_elems, size))
			return (0);
	}
	return (1);
}
