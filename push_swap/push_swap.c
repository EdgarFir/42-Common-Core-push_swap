/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:30:52 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/15 15:58:09 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *arr, int min_limit, int arr_size)
{
	int i;
	int min;

	min = arr[0];
	i = 1;
	while (i < arr_size)
	{
		if (arr[i] > min_limit && arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

void	order(int *arr, int *arr_ord_cpy)
{
	int	min;
	int i;
	int arr_size;

	arr_size = get_arr_size(arr, SIZE);
	min = 0;
	i = 0;
	while (i < arr_size)
	{
		min = find_min(arr, min, arr_size);
		arr_ord_cpy[i] = min;
		i++;
	}
}

void check_a(int *arr)
{
	int arr_size;
	int post_n;
	int last_n;

	arr_size = get_arr_size(arr, SIZE);
	post_n = arr[1];
	last_n = arr[2];
	if (arr[0] > post_n || arr[0] > last_n)
	{
		if (post_n < last_n)
			reverse_rotate(arr);
		else
			swap(arr);
	}
}

void check_b(int *arr)
{
	int arr_size;
	int post_n;
	int last_n;

	arr_size = get_arr_size(arr, SIZE);
	post_n = arr[1];
	last_n = arr[2];
	if (arr[0] < post_n || arr[0] < last_n)
	{
		if (post_n > last_n)
			reverse_rotate(arr);
		else
			swap(arr);
	}
}

void check_changes(int *arr1, int *arr2)
{
	check_a(arr1);
	check_b(arr2);
}

int	find_index(int *arr, int search_num)
{
	int i;
	
	i = 0;
	while (arr[i] != search_num)
		i++;
	return i;
}

void push_index(int *arr1, int *arr2, int search_num)
{
	int index;

	index = find_index(arr1, search_num);
	printf("%i\n", index);
}

int	main(int argc, char **argv)
{
	int arr1[SIZE] = {6, 5, 4, 3, 2, 1};
	int arr2[SIZE] = {0};
	int ordered[SIZE] = {0};
	
	order(arr1, ordered);
	int	is_sorted = 0;
	int i = 0;
	while (i < SIZE)
	{
		check_changes(arr1, arr2);
		push_index(arr1, arr2, ordered[i]);
		is_sorted = 1;
		break;
	}
	print_arr(arr1, SIZE);
	print_arr(arr2, SIZE);
}