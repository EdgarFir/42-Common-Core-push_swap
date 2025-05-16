/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:06:00 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/16 15:09:51 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *fill_chunk(int *arr, int chunk_size)
{
	int i;
	int *chunk;
	int	arr_size;
	int size;

	arr_size = get_arr_size(arr);
	if (chunk_size * 2 <= arr_size)
		size = chunk_size;
	else
		size = arr_size;
	chunk = calloc(size + 1, sizeof(int));
	if (!chunk)
		return (NULL); // Limpar lista array
	i = 0;
	printf("SIZE: %i\n", size);
	while (i < size)
	{
		chunk[i] = arr[i];
		i++;
	}
	return (chunk);
}

int **create_chunk(int *arr, int arr_size, int chunk_size)
{
	int **chunk;
	int n_chunks;
	int i;

	n_chunks =  arr_size / chunk_size;
	chunk = malloc(sizeof(int *) * (n_chunks + 1));
	if (!chunk)
		return (NULL);
	i = 0;
	int j = 0;
	while (i < n_chunks)
	{
		chunk[i] = fill_chunk(&arr[j], chunk_size);
		j+= chunk_size;
		i++;
	}
	chunk[n_chunks] = 0;
	return (chunk);
}