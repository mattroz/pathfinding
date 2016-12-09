#include <stdio.h>
#include <stdlib.h>
#include "../headers/queue.h"
#include "../src/queue.c"
#include "../headers/node.h"

#define SIZE 10

int main()
{
	Node_t node[SIZE];
	Node_t *head, *tail;
	initialize_queue(&head, &tail);	
	
	for(int i = 0; i < SIZE; i++)
	{	
		node[i].x = i;
		node[i].y = i + 1;
		enqueue(&head, &tail, &node[i]);
	}

	for(int i = 0; i < SIZE; i++)
	{
		Node_t *empty_node = malloc(sizeof(Node_t));
		dequeue(&head, &empty_node);
		printf("node.x = %d, node.y = %d\n", empty_node->x, empty_node->y);
	}


	return 0;
}
