#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/heap.h"
#include "../src/heap.c"

int main()
{
	float prior_array[10] = {2.0, 7.0, 26.0, 25.0, 19.0, 17.0, 1.0, 90.0, 3.0, 36.0};
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
		printf("%f\n", prior_array[i]);
		
		if ( heap_insert(pheap, node, prior_array[i]) != E_SUCCESS )
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
	heap_insert(pheap, *node, 4);
	printf("x of min prior elem is %d\n", node->x);

	for(int i = 0; i < 10; i++)
    {
        printf("[%d] = %f\n", i, pheap->elements[i].priority);
    }


	return 0;
}
