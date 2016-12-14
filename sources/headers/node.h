#ifndef NODE_H
#define NODE_H

#ifdef __unix__
#	include <limits.h>
#	define HEAP_TYPE_SIZE \
	({ heap_t h; \
		(char*)(&h + 1) - (char*)&h; \
	})
#	define NODE_TYPE_SIZE \
	({ node_t n; \
		(char*)(&n + 1) - (char*)&n; \
	})
#	define HEAPNODE_TYPE_SIZE \
	({ heapnode_t hn; \
		(char*)(&hn + 1) - (char*)&hn; \
	})
#endif

/****************************/
/*  QUEUE DATA CONTAINERS   */
/****************************/
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


/*************************/
/*	HEAP DATA CONTAINERS */
/*************************/
typedef struct heapnode
{
	node_t data;
	float priority;
}heapnode_t;


typedef struct heap
{
	int maxsize;	/*	heap implementation based on array, so we need to know max array size	*/
	int nodes_number;
	int last_error;
	heapnode_t *nodes;
}heap_t;


/****************************/
/*	HEAP ERRORS DEFINITION	*/
/****************************/
enum _heap_err
{
	E_SUCCESS = 0x00,
	E_MEMORY_ALLOC,
	E_MEMORY_DEALLOC,
	E_NODE_INSERT	
};


typedef struct _heap_err_desc
{
	int code;
	char *msg;	
}err_desc_t;


err_desc_t error_description[] = 
{
	{ E_SUCCESS, 		"success" },
	{ E_MEMORY_ALLOC, 	"memory allocation" },
	{ E_MEMORY_DEALLOC, "memory deallocation" },
	{ E_NODE_INSERT, 	"node insertion" }
};


#endif
