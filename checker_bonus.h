/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:12:57 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/25 00:09:11 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H

# define CHECKER_BONUS_H

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
int		clean_and_return(int *stack_a, int *stack_b, int status, int error);
int		apply_operation(int **stacks, int *a_size, int *b_size, char *oper);
int		fill_stack_a(int *stack_a, char **argv, int argc);
/* Basic operations */
void	swap(int *stack, int size);
void	push(int **stacks, int *push_from_size, int *push_to_size);
void	push_helper(int **stacks, int *a_size, int *b_size, char *oper);
void	ss(int **stacks, int a_size, int b_size);
/* Complex operations */
void	rr(int **stacks, int a_size, int b_size);
void	rrr(int **stacks, int a_size, int b_size);
void	reverse_rotate(int *stack, int size);
void	rotate(int *stack, int size);
/* Checker utils */
int		is_nbr(char *nbr);
int		exists_in_list(int *list, int size, int nbr);
int		is_sorted(int *stack, int size);

#endif