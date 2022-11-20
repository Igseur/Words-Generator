#ifndef ARBRES
#define ARBRES

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct 
{
		p_node root;
		int nbrWord;
} t_tree;

t_tree createEmptyTree ();
void addWord(t_tree *, char *, char *, char *);
int in_tree(p_node , char*, int);
void displayWord(p_node ,int);
#endif