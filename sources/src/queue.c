#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"
#include "../headers/queue.h"


/*		IMPLEMENTATION	*/

/*	link head and tail to each other	*/
int initialize_queue(Node_t **_head, Node_t **_tail)
{
	*_tail = malloc(sizeof(Node_t));
	*_head = malloc(sizeof(Node_t));
	*_tail = NULL;
	*_head = NULL;
	printf("queue initialization\n");

	return 1;
}


int enqueue(Node_t **_head, Node_t **_tail, Node_t *enq_node)
{	
	Node_t *new_node = malloc(sizeof(Node_t));
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


int dequeue(Node_t **_head, Node_t **dest_node)
{
	/*	check if head == tail	*/
	if(is_empty((*_head)) != 0)
	{
		printf("queue is empty, nothing to dequeue\n");
		return 1;
	}
	
	*dest_node = *_head;
//	printf("(*_head)->next = %p\n", (*_head)->next);
	*_head = (*_head)->next;
	printf("dequeue element [%d][%d]\n", (*dest_node)->x, (*dest_node)->y);

	return 1;
}

int is_empty(Node_t *_head)
{
	/*  in other words: check if head == tail   */
	return ((_head == NULL) ? 1 : 0);
}

