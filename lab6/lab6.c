/**********************************************************************************
*  334 Su 20 Lab6 Step 1                                                          *
*  Description: threadSync.c - simple multi-threaded program with sychronization. *
***********************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 

#define NTHREADS 1
#define bufsize 26

char buffer[bufsize];

//how many threads 2 or one for each letter?
pthread_t threads[NTHREADS];
pthread_t prod[NTHREADS];
pthread_t cons[NTHREADS];
sem_t mutex; 
sem_t full;
sem_t empty;
int fill = 0;
int use = 0;


void* go(void* arg) { 
  sem_wait(&mutex); 
  printf("Thread %lu Entered Critical Section..\n", (size_t)arg); 
  sleep(1); 
  sem_post(&mutex); 
  return (NULL);
} 

//see book for put char
void* put(char c){
sem_wait(&empty);
sem_wait(&mutex);
buffer[fill] = c;
fill = (fill+1) % bufsize;
printf("Producer:  %c\n",c);
sem_post(&empty);
sem_post(&mutex);
return (NULL); 	
}



void* get(char c , void* arg){
//not sure how to grab
sem_wait(&full);
sem_wait(&mutex);
 c = buffer[use];
 use = (use +1) % bufsize;
 printf("Consumer: %c\n" ,c);
 sem_post(&mutex);
sem_post(&empty);
return (NULL); 	
}


//%c to print char
void* producer(void* arg){
	
	
	
 	for(int j = 0;j<bufsize;j++){
	
		
		
		// add item to buffer
		put((char) ('A' + j % 26)); 
		
		//signal mutex & full
		
	}
	return (NULL);

}

void* consumer(void* arg){

	char empty = ' ';
	for(int a = 0;a<bufsize;a++){
	//print iteration as arg
	

	//remove item
	//char temp = get();
	//printf("%c\n",temp);	
	get(empty,arg);
	
	


	}
	return (NULL);
}


//int 65 to 90 = A-Z
int main() { 
sem_init(&mutex,0,1);
sem_init(&full, 0,0);
sem_init(&empty,0,bufsize);
 
 //meant to use for start of alphabet
//static int i = 65;



//loop here to initialize all characters up to 90?
for(int a = 0; a<NTHREADS;a++){
pthread_create(&prod[a], NULL, producer, &a);
pthread_create(&cons[a],NULL, consumer, &a);
};

for(int a = 0; a<NTHREADS;a++){
pthread_join(prod[a], NULL);
pthread_join(cons[a],NULL);
};


printf("Main thread done.\n");

sem_destroy(&mutex); 
sem_destroy(&full);
sem_destroy(&empty);
return 0; 
} 
