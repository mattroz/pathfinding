#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"
#include "../headers/queue.h"


/*		IMPLEMENTATION	*/

/*	link head and tail to each other	*/
int initialize_queue(node_t **_head, node_t **_tail)
{
	*_tail = malloc(sizeof(node_t));
	*_head = malloc(sizeof(node_t));
	*_tail = NULL;
	*_head = NULL;
	printf("queue initialization\n");

	return 1;
}


int enqueue(node_t **_head, node_t **_tail, node_t *enq_node)
{	
	node_t *new_node = malloc(sizeof(node_t));
	new_node = enq_node;
	enq_node->next = NULL;
	

	if(is_empty(*_head) == 1)
	{
		*_tail = new_node;
		*_head = new_node;
		printf("queue is empty, enqueue element [%d][%d]\n", 
				(*_tail)->x, (*_tail)->y);
		
		return 1;
	}

	(*_tail)->next =  new_node;
	*_tail = new_node;
	printf("enqueue element[%d][%d]\n", (*_tail)->x, (*_tail)->y);

	return 1;
}


int dequeue(node_t **_head, node_t **dest_node)
{
	/*	check if head == tail	*/
	if(is_empty((*_head)) != 0)
	{
		printf("queue is empty, nothing to dequeue\n");
		return 1;
	}
	
	*dest_node = *_head;
	*_head = (*_head)->next;
	printf("dequeue element [%d][%d]\n", (*dest_node)->x, (*dest_node)->y);

	return 1;
}

int is_empty(node_t *_head)
{
	/*  in other words: check if head == tail   */
	return ((_head == NULL) ? 1 : 0);
}

