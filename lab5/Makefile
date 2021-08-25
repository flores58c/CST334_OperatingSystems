CC = g++

CFLAGS = -D DEBUG

all: threadHello_Step1 threadHelloFixed_Step1 matrix_multiplication

threadHello_Step1:
	gcc -o threadHello_Step1 threadHello_Step1.c -l pthread -Wall -Werror 

threadHelloFixed_Step1:
	gcc -o threadHelloFixed_Step1 threadHelloFixed_Step1.c -l pthread -Wall -Werror

matrix_multiplication:
	gcc -o matrix_multiplication matrix_multiplication.c -l pthread -Wall -Werror
	
clean: 
	rm -f threadHello_Step1 threadHelloFixed_Step1 matrix_multiplication 

