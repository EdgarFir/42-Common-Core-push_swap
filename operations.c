#include "push_swap.h"

void	swap(int *arr, char *oper)
{
	int	temp;
	
	if (cal_arr_size(arr) > 1)
	{
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
		printf("%s\n", oper);
	}
}

void reverse_rotate(int *arr, int moves, char *oper)
{
	int	last_elem;
	int	arr_size;
	int	i;
	int j;

	arr_size = cal_arr_size(arr);
	j = 0;
	while (j < moves)
	{
		last_elem = arr[arr_size - 1];
		i = arr_size - 1;
		while (i >= 0)
		{
			arr[i] = arr[i - 1];
			i--;
		}
		arr[0] = last_elem;
		j++;
		if (oper)
			printf("%s\n", oper);
	}
}

void rotate(int *arr, int moves, char *oper)
{
	int	first_elem;
	int	arr_size;
	int	i;
	int j;

	arr_size = cal_arr_size(arr);
	j = 0;
	while (j < moves)
	{
		first_elem = arr[0];
		i = 0;
		while (i < arr_size - 1)
		{
			arr[i] = arr[i + 1];
			i++;
		}
		arr[arr_size - 1] = first_elem;
		j++;
		if (oper)
			printf("%s\n", oper);
	}
}

void	push(int *push_from, int *push_to, char *oper)
{
	int	push_from_size;
	int	push_to_size;
	int	elem_to_push;

	push_from_size = cal_arr_size(push_from);
	push_to_size = cal_arr_size(push_to);
	elem_to_push = push_from[0];
	if (push_from_size)
	{
		rotate(push_from, 1, NULL);
		if (!push_to_size)
			push_to[0] = elem_to_push;
		else
		{
			push_to[push_to_size] = elem_to_push;
			reverse_rotate(push_to, 1, NULL);
		}
		push_from[push_from_size - 1] = 0;
		printf("%s\n", oper);
	}
}
