/*
Name:Chris flores
Date: March 15
Title Lab 2 
Description: Create the program using fork function to display the parent and child process runnning according to milliseconds entered ex: ./lab ???
Also add ls command so the parent process waits until the child process ls
*/
#include <stdio.h>/* printf, stderr */
#include <sys/types.h>/* pid_t */
#include <unistd.h>/* fork */
#include <stdlib.h>/* atoi */
#include <errno.h>/* errno *//* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
	pid_t  pid;
	int i, n = atoi(argv[1]); 
	// n microseconds to input from keyboard for delay
	printf("\n Before forking.\n");
	pid = fork();
	if(pid == -1) {
		fprintf(stderr, "can't fork, error %d\n", errno);
	}
	if(pid){// Parent process
		for(i=0;i<100;i++) {
		printf("\t \t \t Parent Process %d \n",i);
		usleep(n);
	
	}
	}else if(pid == 0)
	{
	execlp("/bin/ls", "ls",NULL);
	}else
	{wait(NULL);
	printf("Child Complete");
	exit(0);}
	}
	
// output : 
