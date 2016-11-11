#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

/*	PROTOTYPES	*/
int initialize_queue(Node_t**, Node_t**);
int enqueue(Node_t**, Node_t **, int);
int dequeue(Node_t**, int*);
int is_empty(Node_t *);


#endif

