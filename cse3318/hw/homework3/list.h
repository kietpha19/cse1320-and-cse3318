/* 
 * Updated 2/25/2021 - Alexandra Stefan
 */


#ifndef LIST_H
#define	LIST_H

typedef struct node * nodePT;  // POINTER to NODE (memory address of NODE)
struct node {
    int data;
    struct node * next;  // it is the same as: nodePT next;
};

nodePT array_2_list(int arr[], int N);
struct node * build_list_N(int N, FILE* fp);
    
/* Creates a new node, that contains the value specified in the argument, 
 * and that points to next_in. 
 */
nodePT new_node(int value_in);

/*  Note that these functions may not have all the security checks.
E.g. not all the functions reading and setting members of a node pointer, 
check that the node is not NULL  */


/*  --------  LIST  */

void destroy_list(nodePT L);

// Iterates through list and counts nodes.
int compute_length(nodePT L);  


/* Inserts new_node to the specified list, at the position right after
  the node called "previous".
  Inserting at the begining (as new first node) is not handled by this function.
 */
void insert_node_after(nodePT previous, nodePT new_node);

/* Inserts in list L, a the new node newP, after the node prev.
 If prev is NULL it means newP must be linked to the beginning of L
 It uses the list representation (L points to the first node with data)
 */
nodePT insert_node(nodePT L, nodePT prev, nodePT newP);

/* Delete the node after the node "prev".
   Note that this is works on nodes. It does not matter how a list is represented.
   prev is just a node.
*/
void delete_node_after(nodePT prev);

/* Deletes from list L, the node after prev. 
 If prev is NULL it means that the first node of L must be deleted.
 It uses the list representation (L points to the first node with data).
 */
nodePT delete_node(nodePT L, nodePT prev);

void print_list_vert(nodePT my_list);

void print_list_horiz(nodePT my_list);

// for each node prints both data field and the mem address of that node
// (not the field next, but address of the node)
void print_list_pointer(nodePT my_list);

#endif	/* LIST_H */

