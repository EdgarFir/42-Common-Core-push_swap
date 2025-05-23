#!/bin/bash

# Compila o gerador de argumentos e o projeto push_swap
cc tester.c -L ../libft/. -lft -I ../libft/ -o tester
make -C ../ > /dev/null

# Função para correr um teste
run_test()
{
	ARGS=$(./tester "$1")
	echo "Test $1"
	OUTPUT=$(../push_swap $ARGS)

	# Verifica se está OK e quantos movimentos
	echo "$OUTPUT" | ./checker_linux $ARGS
	echo "$OUTPUT" | wc -l
	echo ""
}

echo "Test 1"
OUTPUT=$(../push_swap 1)

../push_swap 1| ./checker_linux 1
../push_swap 1 | wc -l
echo ""

echo "Test 2"
OUTPUT=$(../push_swap 1)

../push_swap 2 1 | ./checker_linux 2 1
../push_swap 2 1 | wc -l
echo ""

echo "Test 3"
OUTPUT=$(../push_swap 2 1 0)

../push_swap 2 1 0 | ./checker_linux 2 1 0
../push_swap 2 1 0 | wc -l
echo ""

echo "Test 4"
OUTPUT=$(../push_swap 4 1 3 2)

../push_swap 4 1 3 2 | ./checker_linux 4 1 3 2
../push_swap 4 1 3 2 | wc -l
echo ""

run_test 5
run_test 10
run_test 25
run_test 50
run_test 61
run_test 100
run_test 331
run_test 500
run_test 1000
