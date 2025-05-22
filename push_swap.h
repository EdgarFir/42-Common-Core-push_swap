/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:12:57 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/22 01:14:18 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "limits.h"
# include <stdio.h>

typedef struct s_opers
{
	int	r;
	int	rr;
}	t_opers;

/* Utils */
void	set_oper(t_opers *oper, int r, int rr);
void	set_min_opers(t_opers *min_opers, t_opers *tmp_opers);
int		find_max_index(int *stack);
int		find_min_index(int *stack);
int		clean_and_return(int *stack_a, int *stack_b, int status);
/* Calc utils */
void	calc_best_oper(int *stack_a, int *stack_b, t_opers min_opers[2]);
int		calc_rr_oper(t_opers *opers);
int		calc_r_oper(t_opers *opers);
int		cal_arr_size(int *arr);
/* Join operations */
void	perfom_rr(int *stack_a, int *stack_b, t_opers min_opers[2]);
void	perfom_r(int *stack_a, int *stack_b, t_opers min_opers[2]);
/* Operations */
void	swap(int *arr, char *oper);
void	reverse_rotate(int *arr, int moves, char *oper);
void	rotate(int *arr, int moves, char *oper);
void	push(int *push_from, int *push_to, char *oper);
/* Stack a utils */
void	calc_moves_a(int nbr_index, int stack_a_size, t_opers *oper);
int		calc_moves_h(int nbr, int *stack, int stack_size);
void	push_a(int *stack_a, int *stack_b, int stack_a_size, int stack_b_size);
/* Stack b utils*/
void	calc_moves_b(int nbr, int *stack_b, int stack_b_size, t_opers *oper);
void	push_b(int *stack_a, int *stack_b, int stack_a_size, int stack_b_size);
/* Checker utils */
int		valid_inter(int *stack, int elem, int stack_n1, int stack_n2);

#endif 