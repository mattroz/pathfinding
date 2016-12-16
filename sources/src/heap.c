#include <stdio.h>
#include <stdlib.h>
#include "../headers/heap.h"

/*
 * initizalize heap head and heap elements for further work 
 */
heap_t *heap_initialize(int maximum_size)
{
	heap_t *heap = malloc(HEAP_TYPE_SIZE);
	if (heap != NULL)
	{
		heap->maxsize = maximum_size;
		heap->elements_number = 0;
		/*	
		 * allocate memory for node_t's array 
		 * (plus one 'cause heap elements start from index 1)	
		 */
		heap->elements = malloc(NODE_TYPE_SIZE * (maximum_size + 1));
		if(heap->elements == NULL)
		{
			free(heap);
			heap->last_error = E_MEMORY_ALLOC;	
			return NULL;
		}
	}

	return heap;
}


/*	swap 2 heap elements	*/
void heap_swap(heapnode_t *node1, heapnode_t *node2)
{
	heapnode_t temp;
	temp = *node1;
	*node1 = *node2;
	*node2 = temp;	

	return E_SUCCESS;
}


int parent_idx_of(int child_idx)
{
	return (child_idx / 2);
}


int lchild_idx_of(int parent_idx)
{
	return (2 * parent_idx);
}


int rchild_idx_of(int parent_idx)
{
	return (2 * parent_idx + 1);
}


/*	implementation of insertion some node_t to heap	*/
int heap_insert(heap_t *heap, node_t src_node, int _priority)
{
	/*	return an error if heap pointer is NULL	*/
	if(heap == NULL)
	{
		heap->last_error = E_NULL_PTR;
		return E_NULL_PTR;
	}
	
	/*	check if heap is full of elements	*/
	if(heap->elements_number >= heap->maxsize)
	{
		heap->last_error = E_HEAP_OVERFLOW;
		return E_HEAP_OVERFLOW;	
	}
	
	/*	if all error cases were checked, add node to heap	*/
	int idx = heap->elements_number++;
	heap->elements[idx].data = src_node;
	heap->elements[idx].priority = _priority;
	
	/*	move this element up if there is min-heap violation	*/
	int i = idx;
	while(heap->elements[i].priority <= 
		  heap->elements[parent_idx_of(i)].priority &&
		  i > 1)
	{
		heap_swap(heap->elements[i], heap->elements[parent_idx_of(i)]);
		i += parent_idx_of(i);
	}
	
	return E_SUCCESS;
}


/*	print last heap error stored in heap data structure pointer	*/
void print_last_error(heap_t *_heap)
{
	int errcode = _heap->last_error;
	printf("HEAP ERROR: [code %d, description: %s]\n",
			errcode, error_description[errcode].msg);
}


/*	free heap and heap elements	*/
int deallocate_heap(heap_t* heap)
{
	free(heap->elements);
	free(heap);
	
	return E_SUCCESS;
}
