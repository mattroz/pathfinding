#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

/*	PROTOTYPES	*/
int initialize_queue(node_t**, node_t**);
int enqueue(node_t**, node_t **, node_t*);
int dequeue(node_t**, node_t**);
int is_empty(node_t *);


#endif

