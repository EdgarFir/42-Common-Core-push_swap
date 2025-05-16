/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:12:57 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/16 15:07:14 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

# define SIZE 6

int		get_arr_size(int *arr);
void	print_arr(int *arr, int def_size);
void rotate(int *arr);
void reverse_rotate(int *arr);
void	swap(int *arr);
void	push(int *push_from, int *push_to);
int		**create_chunk(int *arr, int arr_size, int chunk_size);


#endif 