#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack.h"

/*  stack functions implementation  */

int init(node_t *_head)
{
	_head->value = 0;
	_head->next = NULL;
	return 1;
}


int push(node_t **_head, int _value)
{
	node_t *new_node = malloc(sizeof(node_t));
	new_node->value = _value;
	new_node->next = *_head;
	*_head = new_node;
	printf("push %d\n",(*_head)->value);	

	return 1;
}


int pop(node_t **_head, int *dest)
{
	*dest = (*_head)->value;
	*_head = (*_head)->next;
	return 1;
}


int print(node_t **_head)
{
	while((*_head)->next != NULL)
	{	
		int tempval;
		pop(_head, &tempval);
		printf("%d\n", tempval);
	}
	return 1;
}
