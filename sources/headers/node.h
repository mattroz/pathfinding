#ifndef NODE_H
#define NODE_H

/*  Queue element definition    */
typedef struct Node
{
    float value;
    struct Node *next;
    int is_visited;
    int is_obstacle;
    float movement_cost;
    float heuristic;
	int x;
	int y;
}Node_t;

#endif
