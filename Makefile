CC = g++
CFLAGS = -O0 -Wall -Wextra

build:

	g++ ./algo1.cpp -g -o test_algo_1 $(CFLAGS)
	g++ ./algo2.cpp -g -o test_algo_2 $(CFLAGS)


run-best:
	./test_algo_1

run-p1:
	./test_algo_1

run-p2:
	./test_algo_2

.PHONY: clean

clean:
	rm -rf *.o test1 test2 test.in test.out

