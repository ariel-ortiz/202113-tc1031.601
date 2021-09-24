# Archivo para construir la práctica de pila y filas.

CC = g++ -g

all: main tests

main: main.o stacks_and_queues.o
	$(CC) main.o stacks_and_queues.o -o main

main.o: main.cpp stacks_and_queues.h
	$(CC) -c main.cpp

stacks_and_queues.o: stacks_and_queues.cpp stacks_and_queues.h
	$(CC) -c stacks_and_queues.cpp

tests: tests_main.o tests.o stacks_and_queues.o
	$(CC) tests_main.o tests.o stacks_and_queues.o -o tests

tests.o: tests.cpp stacks_and_queues.h
	$(CC) -c tests.cpp

tests_main.o: tests_main.cpp
	$(CC) -c tests_main.cpp

clean:
	rm -f main main.o tests tests.o tests_main.o stacks_and_queues.o
