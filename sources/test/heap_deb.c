#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/heap.h"
#include "../src/heap.c"

int main()
{
	float prior_array[5] = {2.0, 7.0, 26.0, 25.0, 19.0};
	heap_t *pheap;
	node_t *node;
	pheap = heap_initialize(6);
	srand(time(NULL));
	
	for(int i = 0; i < 5; i++)
	{
		node_t node;
		printf("%f\n", prior_array[i]);
		
		if ( heap_insert(pheap, node, prior_array[i]) != E_SUCCESS )
		{
			print_last_error(pheap);
			return 1;
		}
	}

	for(int i = 1; i <= pheap->elements_number; i++)
	{
		printf("[%d] = %f\n", i, pheap->elements[i].priority);
	}

	node = heap_remove_min(pheap);

	for(int i = 1; i <= pheap->elements_number; i++)
    {
        printf("[%d] = %f\n", i, pheap->elements[i].priority);
    }


	return 0;
}
