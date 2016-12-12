#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/*
 * initizalize heap head and heap nodes for further work 
 */
int heap_initialize(heap_t *heap, int maximum_size)
{
	if (heap = malloc(sizeof(heap_t*)) != NULL)
	{
		heap->maxsize = maximum_size;
		heap->node_number = 0;
		/*	
		 * allocate memory for node_t's array 
		 * (plus one 'cause heap nodes start from index 1)	
		 */
		heap->nodes = malloc(sizeof(node_t) * (maximum_size + 1));
		if(heap->nodes == NULL)
		{
			free(heap);
			perror("memory allocation at initialization");
			return 0;
		}
	}
	
	return 1;
}


/*
 * implementation of insertion some node_t to heap
 */
int heap_insert(heap_t *heap, node_t *inserted, int _priority)
{
	//TODO
}
