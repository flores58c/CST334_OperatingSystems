// CST 334 Lab 4 – FIFO Page Replacement Simulation File I/O Template

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "node.h"
#include "queue.h"

typedef struct {//to 
    int pageno;
} ref_page;


int main(int argc, char *argv[]){
	struct queue* cache_queue = queue_create();
	
	int C_SIZE = atoi(argv[1]); // Size of Cache passed by user 
   // ref_page cache[C_SIZE]; // Cache that stores pages 
  
    char pageCache[100]; // Cache that holds the input from test file

    int i;
    int totalFaults = 0; // keeps track of the total page faults
    
   /* for (i = 0; i < C_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
    }*/

    while (fgets(pageCache, 100, stdin)){
    	// check if it is a digit or character skip if not
    	
    	if(isdigit(pageCache[0])){
    	int page_num = atoi(pageCache); //Stores number read from file as int

 
	if(queue_find(cache_queue,page_num) == NULL )
	// if the queue is full deque. if it is a fault add to the queue
	{	
		if(queue_length(cache_queue) >= C_SIZE)
		{
			dequeue(cache_queue);
		}
		
		enqueue(cache_queue,page_num);
		totalFaults++;
		
	}
	}

    	
    }

	// how many pages read = counter for lines == while loop 
   
    printf("%d Total Page Faults", totalFaults );
    printf("\n");
    //queue_traverse(cache_queue);
    return 0;

}

