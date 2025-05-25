/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:30:51 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/25 00:22:48 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	clean_and_return(int *stack_a, int *stack_b, int status, int error)
{
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	if (error)
		ft_putstr_fd("Error\n", 2);
	return (status);
}

int	apply_operation(int **stacks, int *a_size, int *b_size, char *operation)
{
	if (ft_strcmp(operation, "pb\n") == 0 || ft_strcmp(operation, "pa\n") == 0)
		push_helper(stacks, a_size, b_size, operation);
	else if (ft_strcmp(operation, "sa\n") == 0)
		swap(stacks[0], *a_size);
	else if (ft_strcmp(operation, "sb\n") == 0)
		swap(stacks[1], *b_size);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(stacks, *a_size, *b_size);
	else if (ft_strcmp(operation, "ra\n") == 0)
		rotate(stacks[0], *a_size);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rotate(stacks[1], *b_size);
	else if (ft_strcmp(operation, "rra\n") == 0)
		reverse_rotate(stacks[0], *a_size);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		reverse_rotate(stacks[1], *b_size);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(stacks, *a_size, *b_size);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(stacks, *a_size, *b_size);
	else
		return (0);
	return (1);
}

int	fill_stack_a(int *stack_a, char **argv, int argc)
{
	int			i;
	long long	nbr;

	i = 0;
	while (i < argc)
	{
		if (!argv[i][0])
			return (0);
		if (!is_nbr(argv[i]))
			return (0);
		nbr = ft_atoll(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		if (exists_in_list(stack_a, i, nbr))
			return (0);
		stack_a[i] = nbr;
		i++;
	}
	return (1);
}
