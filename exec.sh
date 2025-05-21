#!/bin/bash

cc push_swap.c push_swap_utils.c operations.c -I libft/. -L libft/. -lft
./a.out
