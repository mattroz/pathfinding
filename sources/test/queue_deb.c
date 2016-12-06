#include <stdio.h>
#include <stdlib.h>
#include "../headers/queue.h"
#include "../src/queue.c"
#include "../headers/node.h"

#define SIZE 5

int main()
{
	Node_t nodes[SIZE];
	Node_t empty_nodes[SIZE];
	Node_t *head, *tail;
	initialize_queue(&head, &tail);	
	
	for(int i = 0; i < SIZE; i++)
	{
		nodes[i].x = i;
		nodes[i].y = i + 1;
		enqueue(&head, &tail, &nodes[i]);
	}

	for(int i = 0; i < SIZE; i++)
		dequeue(&head, &empty_nodes[i]);
	
	return 0;
}
