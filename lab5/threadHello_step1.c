#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>


void *go(void *);

#define NTHREADS 10
pthread_t threads[NTHREADS];
int *a[NTHREADS];

int main()
{

   // dynamic array stored in heap
   
   int i;
   
   for(i=0;i<NTHREADS;i++){
      
      // fix here 23 and 24
      int *b = (int*) malloc(sizeof(int));
      *b=i;
      a[i] = b;
      
       
      pthread_create(&threads[i], NULL, go, a[i]);
      
      }
      
   for(i=0;i<NTHREADS;i++){
   printf("Thread %d returned\n", i);
   	pthread_join(threads[i],NULL);
   	}
   	
   	printf("Main thread done.\n");
   	
   	return 0;
}
   	
   	
   	void *go(void *arg)
   	{
   	//pthread_mutex_lock(&lock);
   	printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int*)arg);
   	//pthread_mutex_unlock(&lock);
   	return 0;
 	}
   	
