/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:30:52 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/16 17:12:25 by edfreder         ###   ########.fr       */
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

	arr_size = get_arr_size(arr);
	min = 0;
	i = 0;
	while (i < arr_size)
	{
		min = find_min(arr, min, arr_size);
		arr_ord_cpy[i] = min;
		i++;
	}
}

int get_min(int curr_n, int post_n, int last_n)
{
	int min;

	min = curr_n;
	if (min > post_n && post_n != 0)
		min = post_n;
	if (min > last_n && last_n != 0)
		min = last_n;
	return (min);
}

int get_max(int curr_n, int post_n, int last_n)
{
	int max;

	max = curr_n;
	if (max < post_n && post_n != 0)
		max = post_n;
	if (max < last_n && last_n != 0)
		max = last_n;
	return (max);
}

int is_from_chunk(int elem, int *chunk)
{
	int start;
	int end;
	int mid;

	start = 0;
	end = get_arr_size(chunk);
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (elem == chunk[mid])
			return (1);
		else if (elem > chunk[mid])
			start = mid + 1;
		else
			end = mid;
	}
	return (0);
	
}

int	check_a(int *arr1, int *chunk)
{
	int arr_size;
	int min;

	arr_size = get_arr_size(arr1);
	min = get_min(arr1[0], arr1[1], arr1[arr_size - 1]);
	if (is_from_chunk(min, chunk))
	{
		if (min == arr1[1])
			swap(arr1);
		else if (min == arr1[arr_size - 1])
			reverse_rotate(arr1);
		return (1);
	}
	return (0);
}

int	check_b(int *arr1, int *chunk)
{
	int arr_size;
	int max;

	arr_size = get_arr_size(arr1);
	max = get_max(arr1[0], arr1[1], arr1[arr_size - 1]);
	if (is_from_chunk(max, chunk))
	{
		if (max == arr1[1])
			swap(arr1);
		else if (max == arr1[arr_size - 1])
			reverse_rotate(arr1);
		return (1);
	}
	return (0);
}

int is_full_ordered(int *arr)
{
	int i = 0;
	int arr_size = get_arr_size(arr);
	if (arr_size != SIZE)
		return (0);
	while (arr[i + 1])
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int calc_moves(int *arr, int *chunk, int start, int end)
{
	int moves;
	
	moves = 0;
	while (start < end)
	{
		if (!is_from_chunk(arr[start], chunk))
			moves++;
		else
			break ;
		start++;
	}
	return (moves);
}

void push_chunk(int *arr, int *chunk)
{
	int half1_moves;
	int half2_moves;
	int mid;
	int end;
	
	end = get_arr_size(arr);
	mid = end / 2;
	half1_moves = calc_moves(arr, chunk, 2, mid) + 2;
	half2_moves = calc_moves(arr, chunk, mid, end - 1) + 1;
	// Comparar as duas halfs
	// Executar rr ou rrr
	return ;s
}

int	main(int argc, char **argv)
{
	int arr1[SIZE + 1] = {6, 5, 4, 3, 2, 1, 0};
	int arr2[SIZE + 1] = {0}; // 
	int ordered[SIZE + 1] = {0};
	order(arr1, ordered);
	int **chunk = create_chunk(ordered, SIZE, 2);
	int chunk_size;
	chunk_size = 0;
	int	is_sorted = 0;
	int j = 0;
	while (!is_sorted)
	{
		while (j < 3)
		{
			// Create chunk
			if (check_a(arr1, chunk[j]))
				push(arr1, arr2);
			else
				push_chunk(arr1, chunk);
		}
		j--;
		while (j >= 0)
		{
			// Create chunk
			while (check_b(arr2, chunk[j]))
				push(arr2, arr1);
			j--;
		}
		if (is_full_ordered(arr1))
			is_sorted = 1;
	}
	printf("\n");
	print_arr(arr1, SIZE);
	print_arr(arr2, SIZE);
}
