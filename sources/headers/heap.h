#ifndef HEAP_H
#define HEAP_H

#include "node.h"

int heap_initialize(heap_t*, int);
int heap_swap(heapnode_t*, heapnode_t*);
int deallocate_heap(heap_t*);
int heap_insert(heap_t*, node_t*, int);
int heap_remove_min(heap_t*, node_t*);
int get_parent(heap_t*, int);
int get_rchild(heap_t*, int);
int get_lchild(heap_t*, int);
void print_last_error(heap_t*);

#endif
