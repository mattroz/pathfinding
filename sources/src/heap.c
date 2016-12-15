#include <stdio.h>
#include <stdlib.h>
#include "../headers/heap.h"

/*
 * initizalize heap head and heap nodes for further work 
 */
heap_t *heap_initialize(int maximum_size)
{
	heap_t *heap = malloc(HEAP_TYPE_SIZE);
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
			heap->last_error = E_MEMORY_ALLOC;	
			return NULL;
		}
	}
	
	return heap;
}


/*	swap 2 heap nodes	*/
int heap_swap(heapnode_t *node1, heapnode_t *node2)
{
	heapnode_t temp;
	temp = *node1;
	*node1 = *node2;
	*node2 = temp;	

	return E_SUCCESS;
}


/*	implementation of insertion some node_t to heap	*/
int heap_insert(heap_t *heap, node_t *inserted, int _priority)
{
	//TODO
}


/*	print last heap error stored in heap data structure pointer	*/
void print_last_error(heap_t *_heap)
{
	int errcode = _heap->last_error;
	printf("HEAP ERROR: [code %d, description: %s]\n",
			errcode, error_description[errcode].msg);
}


/*	free heap and heap nodes	*/
int deallocate_heap(heap_t* heap)
{
	free(heap->nodes);
	free(heap);
	
	return E_SUCCESS;
}
