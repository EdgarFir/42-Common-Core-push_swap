/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:12:04 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/16 15:39:38 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arr(int *arr, int def_size)
{
	int i;

	i = 0;
	while (i < def_size)
	{
		printf("%i ", arr[i]);
		i++;
	}
	printf("\n");
}

int		get_arr_size(int *arr)
{
	int	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

void	swap(int *arr)
{
	int	temp;
	
	if (get_arr_size(arr) > 1)
	{
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
}

void reverse_rotate(int *arr)
{
	int	last_elem;
	int	arr_size;
	int	i;

	arr_size = get_arr_size(arr);
	last_elem = arr[arr_size - 1];
	i = arr_size - 1;
	while (i >= 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = last_elem;
}

void rotate(int *arr)
{
	int	first_elem;
	int	arr_size;
	int	i;

	arr_size = get_arr_size(arr);
	first_elem = arr[0];
	i = 0;
	while (i < arr_size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[arr_size - 1] = first_elem;
}

void	push(int *push_from, int *push_to)
{
	int	push_from_size;
	int	push_to_size;
	int	elem_to_push;

	push_from_size = get_arr_size(push_from);
	push_to_size = get_arr_size(push_to);
	elem_to_push = push_from[0];
	if (push_from_size)
	{
		rotate(push_from);
		if (!push_to_size)
			push_to[0] = elem_to_push;
		else
		{
			push_to[push_to_size] = elem_to_push;
			reverse_rotate(push_to);
		}
		push_from[push_from_size - 1] = 0;
	}
}

// int main()
// {
// 	int arr1[SIZE] = {6, 5, 4, 3, 2, 1};
// 	int arr2[SIZE] = {0};

	
// 	print_arr(arr1, SIZE);
// 	print_arr(arr2, SIZE);
// 	printf("\n");
	
// 	push(arr1, arr2); // 5, 4, 6, 3, 2, 1
// 	print_arr(arr1, SIZE);
// 	print_arr(arr2, SIZE);
// 	printf("\n");
	

// }