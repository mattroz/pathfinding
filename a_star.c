#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "sources/headers/queue.h"
#include "sources/src/queue.c"

#define FLD_SZ 30
#define I_START 0
#define J_START 0

/*	prototypes	*/
int initialize(Node_t[][FLD_SZ], int*, int*);
void print_field(Node_t[][FLD_SZ]);
int a_star(Node_t[][FLD_SZ], int, int);


int main(int argc, char *argv[])
{	
	/*  
     *  get endpoint coordinates and set 
     *  this node to endpoint   
	 */   
	if(argc != 3)
	{
        printf("usage: ./search_to <i-coord> <j-coord>");
        exit(EXIT_FAILURE);
	}
	int i_end = atoi(argv[1]), 
		j_end = atoi(argv[2]);	
	
	/*	initialize pathfinding field	*/
	Node_t map[FLD_SZ][FLD_SZ];
	if (initialize(map, &i_end, &j_end) != 1)
	{
		perror("initialize()");
		exit(EXIT_FAILURE);
	}	
	
	print_field(map);
	
	if(a_star(map, i_end, j_end) != 1)
	{
		perror("a_star()");
		exit(EXIT_FAILURE);
	}

	return 0;
}


/*	
 * initialize all parameters:	
 * _field - map of nodes Node_t
 */
int initialize(Node_t _field[][FLD_SZ], int *end_i, int *end_j)
{	 
	/*	generate obstacles 	*/
	srand(time(NULL));
	for(int i = 0; i < FLD_SZ; i++)
		for(int j = 0; j < FLD_SZ; j++)
			_field[i][j].is_obstacle = rand() % 2;

	/*	make startpoint a non-obstacle node	*/
	_field[I_START][J_START].is_obstacle = 0;

	/*	
	 *	calculate heuristic estimates for each node	
	 *	(Manhattan distance)
	 */
	for(int i = 0; i < FLD_SZ; i++)
	{
		for(int j = 0; j < FLD_SZ; j++)
		{
			double X = abs(*end_i - i),
				   Y = abs(*end_j - j);
			_field[i][j].heuristic = X + Y;
		}
	}	
	return 1;
}


/*	print all nodes' attributes */
void print_field(Node_t _field[][FLD_SZ])
{
	printf("******* HEURISTIC *******\n");
	for(int i = 0; i < FLD_SZ; i++)
	{
		for(int j = 0; j < FLD_SZ; j++)
			printf("%.1f ", _field[i][j].heuristic);
		printf("\n");
	}

	printf("\n********* OBSTACLES ********\n");
	for(int i = 0; i < FLD_SZ; i++)
	{
		for(int j = 0; j < FLD_SZ; j++)
			printf("%d ", _field[i][j].is_obstacle);
		printf("\n");
	}
}


int a_star(Node_t _field[][FLD_SZ], int end_i, int end_j)
{
	/*	initialize queue	*/
	Node_t *queue_head, *queue_tail;
	initialize_queue(&queue_head, &queue_tail);
	enqueue(&queue_head, &queue_tail, _field[I_START][J_START]);	

	/*	initialize some data structures	for A*	*/
	float current_cost[FLD_SZ * FLD_SZ];
	Node_t came_from[FLD_SZ * FLD_SZ];

	/*	start searching	*/		
	while(queue_head != 1)
	{
		/*	get node from open list	*/
		Node_t current_node;
		dequeue(&queue_head, &current_node);
		
		if(current_node.x == end_i && 
		   current_node.y == end_j)
		{
			printf("finished at [%d][%d]\n", current_node.x, current_node.y);
			return 1;	
		}
	
		
	}

}
