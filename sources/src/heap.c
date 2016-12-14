#include <stdio.h>
#include <stdlib.h>
#include "../headers/heap.h"

/*
 * initizalize heap head and heap nodes for further work 
 */
int heap_initialize(heap_t *heap, int maximum_size)
{
	heap = malloc(HEAP_TYPE_SIZE);
	if (heap != NULL)
	{
		heap->maxsize = maximum_size;
		heap->nodes_number = 0;
		/*	
		 * allocate memory for node_t's array 
		 * (plus one 'cause heap nodes start from index 1)	
		 */
		heap->nodes = malloc(NODE_TYPE_SIZE * (maximum_size + 1));
		if(heap->nodes == NULL)
		{
			free(heap);
			perror("memory allocation at initialization");
			return 0;
		}
	}
	
	return 1;
}

/*	swap 2 heap nodes	*/
int heap_swap(heapnode_t *node1, heapnode_t *node2)
{
	heapnode_t temp;
	temp = *node1;
	*node1 = *node2;
	*node2 = temp;
}


/*	implementation of insertion some node_t to heap	*/
int heap_insert(heap_t *heap, node_t *inserted, int _priority)
{
	//TODO
}
