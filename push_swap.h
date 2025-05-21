/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:12:57 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/21 16:46:25 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <time.h>

# define SIZE 50

extern int OPERATIONS;
extern int A_TO_B_MOVES;
extern int B_TO_A_MOVES;

typedef struct s_opers
{
	int r;
	int rr;
} t_opers;

void	calc_best_oper(int *stack_a, int *stack_b, t_opers[2]);
void 	set_oper(t_opers *oper, int r, int rr);
int 	calc_struct_opers(t_opers *opers);
int 	find_min_index(int *stack);
int 	find_max_index(int *stack);
int		is_valid_interval(int *stack, int elem, int stack_elem1, int stack_elem2);
int		get_arr_size(int *arr);
void	print_arr(int *arr, int def_size);
void 	rotate(int *arr, int moves);
void 	reverse_rotate(int *arr, int moves);
void	swap(int *arr);
void	push(int *push_from, int *push_to);
int		calc_moves_a(int nbr, int *stack, int stack_size);
int		calc_moves_b(int nbr, int *stack, int stack_size);

#endif 