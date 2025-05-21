/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:14:21 by edfreder          #+#    #+#             */
/*   Updated: 2025/05/21 16:48:56 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int OPERATIONS = 0;

void set_oper(t_opers *oper, int r, int rr)
{
	oper->r = r;
	oper->rr = rr;
}

void perform_oper(int *stack_a, int *stack_b, t_opers min_opers[2])
{
	if (min_opers[0].r && min_opers[1].r)
	{
		rotate(stack_a, min_opers[0].r);
		rotate(stack_b, min_opers[1].r);
		if (min_opers[0].r > min_opers[1].r)
			OPERATIONS += min_opers[0].r;
		else
			OPERATIONS += min_opers[1].r;
	}
	else if (min_opers[0].r)
	{
		rotate(stack_a, min_opers[0].r);
		OPERATIONS += min_opers[0].r;
	}
	else if (min_opers[1].r)
	{
		rotate(stack_b, min_opers[1].r);
		OPERATIONS += min_opers[1].r;
	}
	if (min_opers[0].rr && min_opers[1].rr)
	{
		reverse_rotate(stack_a, min_opers[0].rr);
		reverse_rotate(stack_b, min_opers[1].rr);
		if (min_opers[0].rr > min_opers[1].rr)
			OPERATIONS += min_opers[0].rr;
		else
			OPERATIONS += min_opers[1].rr;
	}
	else if (min_opers[0].rr)
	{
		reverse_rotate(stack_a, min_opers[0].rr);
		OPERATIONS += min_opers[0].rr;
	}
	else if (min_opers[1].rr)
	{
		reverse_rotate(stack_b, min_opers[1].rr);
		OPERATIONS += min_opers[1].rr;
	}
}

int is_valid(int *stack, int elem, int higher, int minor)
{
	int	i;
	int stack_size;
	
	i = 0;
	stack_size = get_arr_size(stack);
	while (i < stack_size)
	{
		if (stack[i] < higher && stack[i] > elem)
			return (0);
		if (stack[i] > minor && stack[i] < elem)
			return (0);
		i++;
	}
	return (1);
}

int is_valid_interval(int *stack, int elem, int stack_elem1, int stack_elem2)
{
	int i;
	int stack_size;
	
	i = 0;
	stack_size = get_arr_size(stack);
	if (stack_elem1 > stack_elem2)
	{
		if (!is_valid(stack, elem, stack_elem1, stack_elem2))
			return (0);
	}
	else
	{
		if (!is_valid(stack, elem, stack_elem2, stack_elem1))
			return (0);
	}
	return (1);
}
void order_three_elems(int *stack)
{
	int i = 0;
	int min_index;
	int max_index;

	max_index = find_max_index(stack);
	if (max_index == 0)
	{
		rotate(stack, 1);
		OPERATIONS++;
	}
	else if (max_index == 1)
	{
		reverse_rotate(stack, 1);
		OPERATIONS++;
	}
	min_index = find_min_index(stack);
	if (min_index == 1)
	{
		swap(stack);
		OPERATIONS++;
	}
}

void rotate_a_min(int *stack_a, int stack_a_size)
{
	int min_index;
	
	min_index = find_min_index(stack_a);
	if (min_index < stack_a_size / 2)
		rotate(stack_a, min_index);
	else
		reverse_rotate(stack_a, stack_a_size - min_index);
}
void push_b(int *stack_a, int *stack_b, int stack_a_size, int stack_b_size)
{
	int i;
	int insert_i;
	int min_index;
	int max_index;
	
	i = 0;
	while (i < stack_b_size)
	{
		insert_i = 0;
	 	min_index = find_min_index(stack_a);
		max_index = find_max_index(stack_a);
	 	if (stack_b[0] < stack_a[min_index])
			insert_i = min_index;
		else if (stack_b[0] > stack_a[max_index])
			insert_i = min_index;
	 	else
			insert_i = calc_moves_a(stack_b[0], stack_a, stack_a_size);
	 	if (insert_i < stack_a_size / 2)
			rotate(stack_a, insert_i);
		else
			reverse_rotate(stack_a, stack_a_size - insert_i);
	 	push(stack_b, stack_a);
		stack_a_size++;
		i++;
	}
}

void order_to_a(int *stack_a, int *stack_b, int stack_a_size, int stack_b_size)
{
	order_three_elems(stack_a);
	push_b(stack_a, stack_b, stack_a_size, stack_b_size);
	rotate_a_min(stack_a, get_arr_size(stack_a));
}

int exists_in_list(int list[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (list[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main()
{
	int stack_a[SIZE + 1] = {7, 9, 4, 2, 5, 3, 6, 8, 1};
	int stack_b[SIZE + 1] = {0};
	t_opers min_opers[2];
	
	srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        int num = 0;
       do {
            num = (rand() % SIZE) + 1;
        } while (exists_in_list(stack_a, i, num));

        stack_a[i] = num;
    }
	
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	OPERATIONS = 2;
	print_arr(stack_a, SIZE);
	print_arr(stack_b, SIZE);
	printf("\n\n");
	int i = 0;
	int stack_a_size = get_arr_size(stack_a);
	while (i < stack_a_size - 3)
	{
		set_oper(&min_opers[0], -1, -1);
		set_oper(&min_opers[1], -1, -1);
		calc_best_oper(stack_a, stack_b, min_opers);
		perform_oper(stack_a, stack_b, min_opers);
		push(stack_a, stack_b);
		OPERATIONS++;
		i++;
	}
	order_to_a(stack_a, stack_b, 3, get_arr_size(stack_b));
	print_arr(stack_a, SIZE);
	print_arr(stack_b, SIZE);
	printf("\n");
	printf("OPERATIONS: %d\n", OPERATIONS);
}
