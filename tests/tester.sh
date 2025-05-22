cc tester.c
make

ARGS=$(./a.out 1)
echo "Test 1"
.././push_swap 1 | ./checker_linux 1
.././push_swap 1 | wc -l

ARGS=$(./a.out 2)
echo "Test 2"
.././push_swap "2 1" | ./checker_linux "2 1"
.././push_swap "2 1" | wc -l

ARGS=$(./a.out 3)
echo "Test 3"
.././push_swap "3 1 2"  | ./checker_linux "3 1 2"
.././push_swap "3 1 2" | wc -l

ARGS=$(./a.out 4)
echo "Test 4"
.././push_swap "4 2 1 3" | ./checker_linux "4 2 1 3"
.././push_swap "4 2 1 3" | wc -l

ARGS=$(./a.out 10)
echo "Test 10"
.././push_swap ${ARGS} | ./checker_linux ${ARGS}
.././push_swap ${ARGS} | wc -l

ARGS=$(./a.out 25)
echo "Test 30"
.././push_swap ${ARGS} | ./checker_linux ${ARGS}
.././push_swap ${ARGS} | wc -l

ARGS=$(./a.out 50)
echo "Test 50"
.././push_swap ${ARGS} | ./checker_linux ${ARGS}
.././push_swap ${ARGS} | wc -l

ARGS=$(./a.out 61)
echo "Test 61"
.././push_swap ${ARGS} | ./checker_linux ${ARGS}
.././push_swap ${ARGS} | wc -l

ARGS=$(./a.out 100)
echo "Test 100"
.././push_swap ${ARGS} | ./checker_linux ${ARGS}
.././push_swap ${ARGS} | wc -l

ARGS=$(./a.out 331)
echo "Test 331"
.././push_swap ${ARGS} | ./checker_linux ${ARGS}
.././push_swap ${ARGS} | wc -l

ARGS=$(./a.out 500)
echo "Test 500"
.././push_swap ${ARGS} | ./checker_linux ${ARGS}
.././push_swap ${ARGS} | wc -l

ARGS=$(./a.out 1000)
echo "Test 1000"
.././push_swap ${ARGS} | ./checker_linux ${ARGS}
.././push_swap ${ARGS} | wc -l