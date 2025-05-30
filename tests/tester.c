#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../libft/libft.h"

int exists_in_list(int list[], int size, int num) 
{
    for (int i = 0; i < size; i++) 
	{
        if (list[i] == num) 
            return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
	int size = 0;
	size = atoi(argv[1]);
	int *stack_a = calloc(size + 1, sizeof(int));
	srand(time(NULL));
    for (int i = 0; i < size; i++) 
	{
        int num = 0;
       	do 
	   	{
        	num = rand() % (2 * size + 1) - size;
    	} 
		while (exists_in_list(stack_a, i, num));
        stack_a[i] = num;
    }
	for (int i = 0; i < size; i++)
		ft_printf("%d ", stack_a[i]);
}