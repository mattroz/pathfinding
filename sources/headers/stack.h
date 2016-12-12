#ifndef STACK_H
#define STACK_H

#include "node.h"

int init(node_t*);
int push(node_t**, int);
int pop(node_t**, int*);
int print(node_t **);

#endif
