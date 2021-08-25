CC = g++

CFLAGS = -D DEBUG

all: queue_test fifo
	
queue_test:
	gcc queue_test.c node.c queue.c -o queue_test

fifo: fifo.c
	gcc -o fifo fifo.c queue.c node.c -Wall

	
	

