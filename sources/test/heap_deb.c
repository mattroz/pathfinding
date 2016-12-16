#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/heap.h"
#include "../src/heap.c"

int main()
{
	heap_t *pheap;
	node_t *node;
	pheap = heap_initialize(10);
	srand(time(NULL));
	/*	
	if(deallocate_heap(pheap) != E_SUCCESS)
	{
		print_last_error(pheap);
	}
	*/
	for(int i = 0; i < 10; i++)
	{
		node_t node;
		float priority = rand() % 50;
		printf("%f\n", priority);
		
		if ( heap_insert(pheap, node, priority) != E_SUCCESS )
		{
			print_last_error(pheap);
			return 1;
		}
	}

	for(int i = 0; i < 10; i++)
	{
		printf("[%d] = %f\n", i, pheap->elements[i].priority);
	}

	node = heap_remove_min(pheap);
	printf("x of min prior elem is %d\n", node->x);

	for(int i = 0; i < 10; i++)
    {
        printf("[%d] = %f\n", i, pheap->elements[i].priority);
    }


	return 0;
}
