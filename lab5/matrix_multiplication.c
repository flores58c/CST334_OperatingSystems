#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>


// We can divide the work by creating one thread to compute each value (or each row) in C, and then executing thosethreads on different processors in parallel on multi-processor systems.

void *dot(void *arg);
#define N  2
#define M  2
#define L  2
double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];
pthread_t threads[N];
int *a[N];

int main()
{
	
	//make A[]
	srand(time(NULL));
	for (int i= 0; i <N;i++)
		for (int j= 0;j<M;j++)
			matrixA[i][j] = rand();
	
	//make B[]		
	srand(time(NULL));
	for (int i= 0; i <M;i++)
		for (int j= 0;j<L;j++)
			matrixB[i][j] = rand();
	//print A
	for ( int i = 0; i < N; i++ ) {
		for (int j = 0; j < M; j++ ) {
         printf("A[%d][%d] = %f\n", i,j, matrixA[i][j] );
      }
      }
      
      //print B
      for ( int i = 0; i < M; i++ ) {
		for (int j = 0; j < L; j++ ) {
         printf("B[%d][%d] = %f\n", i,j, matrixB[i][j] );
      }
   }
	int i;
for(i=0;i<N;i++){
      
      // initialize a pointer with size of int typecasted into int *
      int *b = (int*) malloc(sizeof(int));
      //point to value of i
      *b=i;
      // make the array at index take int pointer b
      a[i] = b;
      
      // function go on create uses array at index to grab value from heap. 
      pthread_create(&threads[i], NULL, dot, a[i]);
      
      }
      
    
	
	
   
     for(i=0;i<N;i++){
   //printf("Thread %d returned\n", i);
   	pthread_join(threads[i],NULL);
   	}

   printf("Main thread done");
   return 0;
		
}

void *dot(void *arg)
   	{
   	int i = *(int*)arg;
   	//printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int*)arg);
   	 for (int j = 0; j <L; j++)
  	{	double temp = 0;
  	for (int k = 0; k <M; k++)
  	{		
  	temp +=matrixA[i][k] * matrixB[k][j];
  
  	}
  	matrixC[i][j] = temp;
  	printf("C[%d][%d] = %f\n", i,j, matrixC[i][j]);
  	}
  	
   	return 0;
   	
 	}



