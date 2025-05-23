/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:12:57 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/23 02:46:25 by edfreder         ###   ########.fr       */
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
int		find_max_index(int *stack, int size);
int		find_min_index(int *stack, int size);
int		clean_and_return(int *stack_a, int *stack_b, int status, int error);
/* Calc utils */
void	calc_best_oper(int **stacks, int a_size, int b_size, t_opers *opers);
int		calc_rr_oper(t_opers *opers);
int		calc_r_oper(t_opers *opers);
/* Join operations */
void	perfom_rr(int **stacks, int a_size, int b_size, t_opers *opers);
void	perfom_r(int **stacks, int a_size, int b_size, t_opers *opers);
/* Operations */
void	swap(int *arr, char *oper, int size);
void	reverse_rotate(int *stack, int moves, char *oper, int size);
void	rotate(int *stack, int moves, char *oper, int size);
void	push(int **stacks, int push_from_size, int push_to_size, char *oper);
void	push_helper(int **stacks, int a_size, int b_size, int mode);
/* Stack a utils */
void	calc_moves_a(int nbr_index, int stack_a_size, t_opers *oper);
int		count_moves_a(int nbr, int *stack, int stack_size);
void	push_a(int **stacks, int stack_a_size, int stack_b_size);
void	order_three_elems(int *stack);
void	rotate_a_min(int *stack_a, int stack_a_size);
/* Stack b utils*/
void	calc_moves_b(int nbr, int *stack_b, int stack_b_size, t_opers *oper);
void	push_b(int **stacks, int a_size, int b_size);
/* Checker utils */
int		valid_inter(int *stack, int check_elem, int *cmp_elems, int size);
int		is_nbr(char *nbr);
int		exists_in_list(int *list, int size, int nbr);
int		is_sorted(int *stack, int size);

#endif 