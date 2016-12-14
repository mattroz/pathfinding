#include <stdio.h>
#include <stdlib.h>
#include "../headers/heap.h"
#include "../src/heap.c"

int main()
{
	heap_t *heap;
	heap_initialize(heap, 10);
	heap->last_error = 0x1;
	print_last_error(heap);
	printf("%d, %d, %d\n", HEAP_TYPE_SIZE, NODE_TYPE_SIZE, HEAPNODE_TYPE_SIZE);
	return 0;
}
