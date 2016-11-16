#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "sources/headers/queue.h"
#include "sources/headers/stack.h"

#define FLD_SZ 10
#define I_START 0
#define J_START 0

/*	prototypes	*/
//int calculate_heuristics(Node_t*, int, int);
int initialize(Node_t*, int*, int*);


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
	int i_end = atoi(argv[2]), 
		j_end = atoi(argv[3]);	
	
	/*	initialize pathfinding field	*/
	Node_t *map[FLD_SZ][FLD_SZ];
	initialize(map, &i_end, &j_end);	

	

	return 0;
}


/*	
 * initialize all parameters:	
 * _field - map of nodes Node_t
 */
int initialize(Node_t *_field, int *end_i, int *end_j)
{	 
	/*	generate obstacles 	*/
	srand(time(NULL));
	for(int i = 0; i < FLD_SZ; i++)
	{
		for(for j = 0; j < FLD_SZ; j++)
		{
			_field[i][j] = malloc(sizeof(Node_t));
			_field[i][j]->is_obstacle = rand() % 2;
		}
	}

	/*	make startpoint a non-obstacle node	*/
	_field[I_START][J_START]->is_obstacle = 0;

	/*	calculate heuristic values for each node	*/
	for(int i = 0; i < FLD_SZ; i++)
	{
		for(int j = 0; j < FLD_SZ; j++)
		{
			double X = (I_START - *end_i) << 1;
				   Y = (J_START - *end_j) << 1;
			_field[i][j]->heuristic = sqrt(X + Y);
		}
	}	
}
