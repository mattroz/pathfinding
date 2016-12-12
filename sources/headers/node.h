#ifndef NODE_H
#define NODE_H

/*  Queue element definition    */
typedef struct fieldnode
{
    float cost_from_start;
    struct fieldnode *next;
    int is_visited;
    int is_obstacle;
    float movement_cost;
    float heuristic;
	int x;
	int y;
}node_t;

/*	Heap data containers */
typedef struct heapnode
{
	node_t data;
	float priority;
}heapnode_t;

typedef struct Heap
{
	int maxsize;	/*	head implementation based on array, so we need to know max array size	*/
	int nodes_number;
	heapnode_t *nodes;
}heap_t;
#endif
