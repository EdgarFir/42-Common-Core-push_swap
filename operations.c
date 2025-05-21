#include "push_swap.h"

void	print_arr(int *arr, int def_size)
{
	int i;

	i = 0;
	while (i < def_size)
	{
		printf("%i ", arr[i]);
		i++;
	}
	printf("\n");
}

int		get_arr_size(int *arr)
{
	int	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

void	swap(int *arr)
{
	int	temp;
	
	if (get_arr_size(arr) > 1)
	{
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
}

void reverse_rotate(int *arr, int moves)
{
	int	last_elem;
	int	arr_size;
	int	i;
	int j;

	arr_size = get_arr_size(arr);
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
	}
}

void rotate(int *arr, int moves)
{
	int	first_elem;
	int	arr_size;
	int	i;
	int j;

	arr_size = get_arr_size(arr);
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
	}
}

void	push(int *push_from, int *push_to)
{
	int	push_from_size;
	int	push_to_size;
	int	elem_to_push;

	push_from_size = get_arr_size(push_from);
	push_to_size = get_arr_size(push_to);
	elem_to_push = push_from[0];
	if (push_from_size)
	{
		rotate(push_from, 1);
		if (!push_to_size)
			push_to[0] = elem_to_push;
		else
		{
			push_to[push_to_size] = elem_to_push;
			reverse_rotate(push_to, 1);
		}
		push_from[push_from_size - 1] = 0;
	}
}

// int main()
// {	
// 	// 1 2 3 4 5
// 	// 6 7 8 9 10
// 	// 11 12 13 14 15
//  	int arr1[15 + 1] = {5, 6, 12, 1, 10, 9, 15, 11, 7, 2, 3, 13, 4, 14, 8, 0};
//  	int arr2[15 + 1] = {8, 9, 4};

//  	printf("\n");
// 	// Se numero que entrar, for mais pequeno que o primeiro, roda para ultimo o primeiro ate encontrar ate ser o maior e pushb
// 	if (arr1[0] > arr2[0])
// 		push(arr1, arr2);
// 	else
// 	{
// 		while (arr1[0] < arr2[0])
// 			rotate(arr2, 1);
// 		push(arr1, arr2);
// 	}
// 	//push(arr1, arr2);
	
// 	// 5, 4, 6, 3, 2, 1
//  	print_arr(arr1, 15);
// 	print_arr(arr2, 15);
// 	printf("\n");
// }