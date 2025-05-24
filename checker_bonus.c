/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:34:22 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/24 20:38:58 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	start_checker(int *stack_a, int *stack_b, int argc)
{
	char	*operation;
	int		*stacks[2];
	int		a_size;
	int		b_size;

	stacks[0] = stack_a;
	stacks[1] = stack_b;
	a_size = argc - 1;
	b_size = 0;
	while (1)
	{
		operation = get_next_line(0);
		if (!operation)
			break ;
		if (!apply_operation(stacks, &a_size, &b_size, operation))
		{
			clean_and_return(stack_a, stack_b, 1, 1);
			free(operation);
			exit(1);
		}
		free(operation);
	}
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;

	if (argc > 1)
	{
		stack_a = ft_calloc(argc -1, sizeof(int));
		stack_b = ft_calloc(argc -1, sizeof(int));
		if (!stack_a || !stack_b || !fill_stack_a(stack_a, argv + 1, argc - 1))
			return (clean_and_return(stack_a, stack_b, 1, 1));
		start_checker(stack_a, stack_b, argc);
		if (is_sorted(stack_a, argc - 1))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		return (clean_and_return(stack_a, stack_b, 0, 0));
	}
	return (0);
}
