#ifndef NODE
#define NODE

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "cell.h"

typedef struct s_node
{
    struct s_node **kids;
    char lettre;
		int nbrKids;
		int end;
		

} t_node, *p_node ;

p_node createNode(char);
p_node addKid(p_node, char);

#endif