#include <stdio.h>
#include <stdlib.h>
#include "../headers/heap.h"
#include "../src/heap.c"

int main()
{
	heap_t *pheap;
	
	pheap = heap_initialize(10);
	
	if(deallocate_heap(pheap) != E_SUCCESS)
	{
		print_last_error(pheap);
	}
	
	return 0;
}
