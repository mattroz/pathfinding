#ifndef HEAP_H
#define HEAP_H

#include "node.h"

heap_t *heap_initialize(int);
void heap_swap(heapnode_t*, heapnode_t*);
int deallocate_heap(heap_t*);
int heap_insert(heap_t*, node_t, int);
node_t heap_remove_min(heap_t*);
int parent_idx_of(int);
int rchild_idx_of(int);
int lchild_idx_of(int);
void print_last_error(heap_t*);
int is_heap_empty(heap_t*);

#endif
