#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>


void *go(void *);

#define NTHREADS 10
pthread_t threads[NTHREADS];

// dynamic array stored in heap
int *a[NTHREADS];

int main()
{
   int i;
   
   for(i=0;i<NTHREADS;i++){
      
      // initialize a pointer with size of int typecasted into int *
      int *b = (int*) malloc(sizeof(int));
      //point to value of i
      *b=i;
      // make the array at index take int pointer b
      a[i] = b;
      
      // function go on create uses array at index to grab value from heap. 
      pthread_create(&threads[i], NULL, go, a[i]);
      
      }
      
   for(i=0;i<NTHREADS;i++){
   printf("Thread %d returned\n", i);
   	pthread_join(threads[i],NULL);
   	}
   	
   	printf("Main thread done.\n");
   	
   	return 0;
}
   	
   	// void * accepts any pointer of any type
   	void *go(void *arg)
   	{
   	//double ** shows the integer value 
   	printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int*)arg);
   	
   	return 0;
 	}
   	
