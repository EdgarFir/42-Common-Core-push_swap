/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:26:59 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/22 01:14:31 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int exists_in_list(int list[], int size, int num) 
{
    for (int i = 0; i < size; i++) {
        if (list[i] == num) {
            return 1;
        }
    }
    return 0;
}

int is_valid(int *stack, int elem, int higher, int minor)
{
	int	i;
	int stack_size;
	
	i = 0;
	stack_size = cal_arr_size(stack);
	while (i < stack_size)
	{
		if (stack[i] < higher && stack[i] > elem)
			return (0);
		if (stack[i] > minor && stack[i] < elem)
			return (0);
		i++;
	}
	return (1);
}

int valid_inter(int *stack, int elem, int stack_elem1, int stack_elem2)
{
	if (stack_elem1 > stack_elem2)
	{
		if (!is_valid(stack, elem, stack_elem1, stack_elem2))
			return (0);
	}
	else
	{
		if (!is_valid(stack, elem, stack_elem2, stack_elem1))
			return (0);
	}
	return (1);
}
