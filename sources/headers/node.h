#ifndef NODE_H
#define NODE_H

/*  Queue element definition    */
typedef struct Node
{
    int value;
    struct Node *next;
    int is_visited;
    int is_obstacle;
    int movement_cost;
    int heurisic;
}Node_t;

#endif
