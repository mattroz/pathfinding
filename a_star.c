#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "sources/headers/heap.h"
#include "sources/src/heap.c"

#define FLD_SZ 15
#define MOV_COST 1	/*	assume that node size is 1x1 meters	*/
#define I_START 1
#define J_START 1


/*	prototypes	*/
int initialize(node_t[][FLD_SZ], int, int);
void print_field(node_t[][FLD_SZ]);
int a_star(node_t[][FLD_SZ], int, int);


int main(int argc, char *argv[])
{	
	/*  
     *  get endpoint coordinates and set 
     *  this node to endpoint   
	 */   
	if(argc != 3)
	{
        printf("usage: ./search_to.out <i-coord> <j-coord>\n");
        exit(EXIT_FAILURE);
	}
	int i_end = atoi(argv[1]), 
		j_end = atoi(argv[2]);	
	
	/*	initialize pathfinding field	*/
	node_t map[FLD_SZ][FLD_SZ];
	if (initialize(map, i_end, j_end) != 1)
	{
		perror("initialize()");
		exit(EXIT_FAILURE);
	}	
	
	print_field(map);
	
	if(a_star(map, i_end, j_end) != 1)
	{
		printf("Endpoint is unreachable\n");
		exit(EXIT_FAILURE);
	}
	
	print_field(map);

	return 0;
}


/*	
 * initialize all parameters:	
 * _field - map of nodes node_t
 */
int initialize(node_t _field[][FLD_SZ], int end_i, int end_j)
{	 
	/*	generate obstacles	*/
	srand(time(NULL));
	for(int i = 1; i < (FLD_SZ - 1); i++)
		for(int j = 1; j < (FLD_SZ - 1); j++)
			_field[i][j].is_obstacle = 0;	

	/*
	 *	fill outer ring with obstacles
	 *	to prevent out-of-index error
	 */
	for(int i = 0; i < FLD_SZ; i++)
	{
		_field[0][i].is_obstacle = 1;
		_field[i][0].is_obstacle = 1;
	}
	
	for(int i = FLD_SZ - 1; i >= 0; i--)
	{
		_field[FLD_SZ - 1][i].is_obstacle = 1;
		_field[i][FLD_SZ - 1].is_obstacle = 1;
	}

	/*	make startpoint and endpoint a non-obstacle node	*/
	_field[I_START][J_START].is_obstacle = 0;
	_field[I_START][J_START].is_visited = 1;
	_field[end_i][end_j].is_obstacle = 0;	

	/*	
	 *	calculate heuristic estimates for each node	
	 *	(Manhattan distance)
	 *	and assign each node it's own index 
	 *	according to field,
	 *	assign to every node its movement cost
	 */
	for(int i = 0; i < FLD_SZ; i++)
	{
		for(int j = 0; j < FLD_SZ; j++)
		{
			double X = abs(end_i - i),
				   Y = abs(end_j - j);
			_field[i][j].heuristic = X + Y;
			_field[i][j].is_visited = 0;
			_field[i][j].movement_cost = MOV_COST;
			/*	need this assignments for queue	*/
			_field[i][j].x = i;
			_field[i][j].y = j;
		}
	}	
	return 1;
}


/*	print all nodes' attributes */
void print_field(node_t _field[][FLD_SZ])
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
	
	printf("\n********* VISITED ********\n");
    
	for(int i = 0; i < FLD_SZ; i++)
    {
        for(int j = 0; j < FLD_SZ; j++)
            printf("%d ", _field[i][j].is_visited);
        printf("\n");
	}
}


int a_star(node_t _field[][FLD_SZ], int end_i, int end_j)
{
	/*	initialize queue	*/
	heap_t *pheap = heap_initialize(FLD_SZ);
	float start_estimation = _field[I_START][J_START].heuristic + 
					 		 _field[I_START][J_START].movement_cost;

	if(heap_insert(pheap, _field[I_START][J_START], start_estimation) != E_SUCCESS)
	{
		print_last_error(pheap);
		return 0;
	}

	/*	initialize some data structures	for A*	*/
	//float current_cost[FLD_SZ * FLD_SZ];
	node_t came_from[FLD_SZ * FLD_SZ];
	_field[I_START][J_START].cost_from_start = 0;
	int step_x[4] = {0, 1, 0, -1}, 
		step_y[4] = {1, 0, -1, 0};

	/*	start searching	*/		
	while(is_heap_empty(pheap) != 1)
	{
		/*	get node from open list	*/
		node_t current = heap_remove_min(pheap);
		
		_field[current.x][current.y].is_visited = 1;	
		
		/*	check if current node is an endpoint	*/
		if(current.x == end_i && current.y == end_j)
		{
			printf("finished at [%d][%d]\n", current.x, current.y);
			return 1;	
		}
	
		/*	add current node's neghbours to an open list	*/
		for(int i = 0; i < 4; i++)
		{
			/*	move up/right/down/left	*/
			int X = current.x + step_x[i];
			int Y = current.y + step_y[i];			
			
			/*	calculate cost from start point to current neighbour	*/ 
			_field[X][Y].cost_from_start = current.cost_from_start + 
											_field[X][Y].movement_cost;
			printf("cost from start to [%d][%d] = %f\n", X, Y, _field[X][Y].cost_from_start);			

			/*	
			 *	if this neighbour isn't obstacle and 
			 *	haven't visited yet, add it
			 */
			if(_field[X][Y].is_obstacle == 0 && _field[X][Y].is_visited == 0)
			{
				//	NEED: enqueue(&queue_head, &queue_tail, &_field[X][Y], estimation);
				float estimation = _field[X][Y].heuristic + 
								   _field[X][Y].cost_from_start;
				if(heap_insert(pheap, _field[X][Y], estimation) != E_SUCCESS)
				{
					print_last_error(pheap);
					return 0;
				}
			}
		}
	}
	return 0;

}
