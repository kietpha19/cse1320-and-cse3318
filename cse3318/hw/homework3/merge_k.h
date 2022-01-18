
#ifndef MERGE_K_H
#define	MERGE_K_H

#include "list.h"

nodePT sort_list(nodePT L);

void make_heap(int k, nodePT heap[]);
nodePT remove_min(int* k, nodePT heap[]);
nodePT merge_k(int k, nodePT heap[], int debug);


#endif	/* MERGE_K_H */
