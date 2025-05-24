#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'
LIGHT_BLUE="\033[1;34m"

cc tester.c -L ../libft/. -lft -I ../libft/ -o tester
make -C ../ > /dev/null
make -C ../ > /dev/null bonus

norminette_test()
{
	if norminette $(find ../. -name '*.c' ! -name 'tester.c') | grep -q "Error!"; then
		echo -e "Norminette: ${RED}KO${NC}"
	else
		echo -e "Norminette: ${GREEN}OK${NC}"
	fi
}

run_mem_test()
{
	DIR="leaks_results/$1"
	PATTERN="All heap blocks were freed -- no leaks are possible"

	RESULT=$(grep "All heap blocks were freed" ${DIR})

	if [ -z "$RESULT" ]; then
		echo -e "❌ ${RED}KO${NC}"
	else
		echo -e "✅ ${GREEN}OK${NC}"
	fi
}

run_test()
{
	ARGS=$(./tester "$1")
	echo -e "${LIGHT_BLUE}Test $1${NC}"
	OUTPUT=$(../push_swap $ARGS)
	RESULT_42=$(echo "$OUTPUT" | ./checker_linux $ARGS)
	RESULT_MY=$(echo "$OUTPUT" | .././checker $ARGS)
	OPERATIONS_COUNT=$(echo "$OUTPUT" | wc -l)
	OK="OK"
	KO="KO"
	echo -e "${YELLOW}42 CHECKER ${NC}"
		if [ "$RESULT_42" == "$OK" ]; then
		echo -e "✅ ${GREEN}OK${NC}"
	else
		echo -e "❌ ${RED}KO${NC}"
	fi
	echo -e "${YELLOW}MY CHECKER ${NC}"
	if [ "$RESULT_MY" == "$OK" ]; then
		echo -e "✅ ${GREEN}OK${NC}"
	else
		 echo -e "❌ ${RED}KO${NC}"
	fi
	echo -e "${YELLOW}LINES COUNTED${NC}"
	echo "${OPERATIONS_COUNT}"
	valgrind --leak-check=full -s ../push_swap $ARGS > leaks_results/$1 2>&1
	echo -e "${YELLOW}LEAKS${NC}"
	run_mem_test $1
	echo ""
}

run_low_test()
{
	TEST_N=$1
	ARGS="${@:2}"
	echo -e "${LIGHT_BLUE}$1${NC}"
	if [ $1 == 1 ]; then
		OUTPUT=$(../push_swap 1)
		RESULT_42=$(../push_swap 1 | ./checker_linux 1)
		RESULT_MY=$(../push_swap 1 | ../checker 1)
	else
		OUTPUT=$(../push_swap $ARGS)
		RESULT_42=$(echo "$OUTPUT" | ./checker_linux $ARGS)
		RESULT_MY=$(echo "$OUTPUT" | ../checker $ARGS)
	fi
	OPERATIONS_COUNT=$(echo "$OUTPUT" | wc -l)
	OK="OK"
	KO="KO"
	echo -e "${YELLOW}42 CHECKER ${NC}"
	if [ "$RESULT_42" == "$OK" ]; then
		echo -e "✅ ${GREEN}OK${NC}"
	else
		echo -e "❌ ${RED}KO${NC}"
	fi
	echo -e "${YELLOW}MY CHECKER ${NC}"
	if [ "$RESULT_MY" == "$OK" ]; then
		echo -e "✅ ${GREEN}OK${NC}"
	else
		 echo -e "❌ ${RED}KO${NC}"
	fi
	echo -e "${YELLOW}LINES COUNTED${NC}"
	echo "${OPERATIONS_COUNT}"
	valgrind --leak-check=full -s ../push_swap $ARGS > leaks_results/$1 2>&1
	echo -e "${YELLOW}LEAKS${NC}"
	run_mem_test $1
	echo ""
}

run_error_test()
{
    TEST_N="$1"
    OUTPUT_FILE="$2"
    EXPECTED="$3"
    ARGS="${@:4}"

    echo -e "${LIGHT_BLUE}$TEST_N${NC}"
	RESULT=$(../push_swap $ARGS 2>&1)
	CLEAN_RESULT=$(echo "$RESULT" | tr -d '\n' | xargs)
    if [ "$CLEAN_RESULT" == "$EXPECTED" ]; then
        echo -e "✅ ${GREEN}OK${NC}"
    else
        echo -e "❌ ${RED}KO${NC}"
    fi
    valgrind --leak-check=full -s ../push_swap $ARGS > leaks_results/$OUTPUT_FILE 2>&1
    echo -e "${YELLOW}LEAKS${NC}"
	run_mem_test $2
	echo ""
}

run_checker_error_test()
{
    TEST_N="$1"
    OUTPUT_FILE="$2"
    ARGS="${@:3}"

    echo -e "${LIGHT_BLUE}$TEST_N${NC}"
	RESULT=$(../push_swap $ARGS 2>&1)
	RESULT_42=$(./checker_linux $ARGS 2>&1)
    if [ "$RESULT" == "$RESULT_42" ]; then
        echo -e "✅ ${GREEN}OK${NC}"
    else
        echo -e "❌ ${RED}KO${NC}"
    fi
    valgrind --leak-check=full -s ../checker $ARGS > leaks_results/$OUTPUT_FILE 2>&1
    echo -e "${YELLOW}LEAKS${NC}"
	run_mem_test $2
	echo ""
}

echo -e "${RED}NORMINETTE TEST${NC}"
norminette_test

echo ""

echo -e "${RED}TEST 1 - 4${NC}"
run_low_test 1 42
run_low_test 2 2 1
run_low_test 3 2 1 0
run_low_test 4 4 1 3 2

echo ""

echo -e "${RED}TEST 5 - 1000${NC}"
run_test 5
run_test 10
run_test 25
run_test 50
run_test 61
run_test 100
run_test 331
run_test 500
run_test 1000

echo -e "${RED}TEST ERRORS${NC}"
run_error_test "No parameters" "noparams1" ""
run_error_test "Duplicated numeric values 1" "duplicated1" "Error" 10 5 1 0 3 1
run_error_test "Duplicated numeric values 2" "duplicated2" "Error" 10 1 5 1 0 3
run_error_test "Duplicated numeric values 3" "duplicated3" "Error" 0 1 5 15 0 3 10 9 2
run_error_test "Non numeric values 1" "non_numeric1" "Error" 10 5 a 0 3 1
run_error_test "Non numeric values 2" "non_numeric2" "Error" abc 10 5 1 0 3
run_error_test "Non numeric values 3" "non_numeric3" "Error" 10 1 5 15 0 3 10 9 abc
run_error_test "Overflow values 1" "overflow1" "Error" 10 5 4 0 3 2147483648
run_error_test "Overflow values 2" "overflow2" "Error" 40 10 -2147483649 1 0 3
run_error_test "Overflow values 3" "overflow3" "Error" 10 2147483648 5 15 0 3 -2147483649 9 1
run_error_test "Sorted values 1" "sorted1" "" 0 1 2 3 4 5
run_error_test "Sorted values 2" "sorted2" "" 0 1 2 3 4 5 6 7 8 9
run_error_test "Sorted values 3" "sorted3" "" -4 -3 -2 -1 0 1 2 3 4 5 6 7

echo ""

echo -e "${RED}MY CHECKER ERRORS${NC}"

run_checker_error_test "Duplicated numeric values 1" "c_duplicated1" 10 5 1 0 3 1
run_checker_error_test "Duplicated numeric values 2" "c_duplicated2" 10 1 5 1 0 3
run_checker_error_test "Duplicated numeric values 3" "c_duplicated3" 0 1 5 15 0 3 10 9 2
run_checker_error_test "Non numeric values 1" "c_non_numeric1" 10 5 a 0 3 1
run_checker_error_test "Non numeric values 2" "c_non_numeric2" abc 10 5 1 0 3
run_checker_error_test "Non numeric values 3" "c_non_numeric3" 10 1 5 15 0 3 10 9 abc
run_checker_error_test "Overflow values 1" "c_overflow1" 10 5 4 0 3 2147483648
run_checker_error_test "Overflow values 2" "c_overflow2" 40 10 -2147483649 1 0 3
run_checker_error_test "Overflow values 3" "c_overflow3" 10 2147483648 5 15 0 3 -2147483649 9 1
