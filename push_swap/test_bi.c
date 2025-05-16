#include "push_swap.h"

int		get_arr_size(int *arr)
{
	int	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

int is_from_chunk(int elem, int *chunk)
{
	int start;
	int end;
	int mid;

	start = 0;
	end = get_arr_size(chunk);
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (elem == chunk[mid])
			return (1);
		else if (elem > chunk[mid])
			start = mid + 1;
		else
			end = mid;
	}
	return (0);
	
}

int main()
{
	int arr[11] = {1, 2, 0};
	printf("%i\n", is_from_chunk(4, arr));
}
