#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "node.h"

p_node createNode(char val) {

    p_node noeud;
    noeud = (p_node) malloc(sizeof(t_node));
    noeud->lettre = val;
		noeud->nbrKids = 0;
    noeud->kids = (p_node*) malloc (sizeof (p_node));
    noeud->end = 0;

    return noeud;
}

p_node addKid(p_node noeud, char val)
{
    p_node newnoeud = createNode(val);
    noeud->kids[noeud->nbrKids] = newnoeud;
    noeud->nbrKids ++;
    noeud->kids = (p_node*) realloc (noeud->kids,sizeof (p_node) * (noeud->nbrKids+1));

    return newnoeud;
}

