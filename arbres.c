#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbres.h"
#include "list.h"



t_tree createEmptyTree (){
    t_tree mytree;
    mytree.root = createNode(' ');
		mytree.nbrWord = 0;
    return mytree;
}

int in_tree(p_node Node, char *val, int i) {
    int check = 0, check2 =0;
		int j = 0;
	if((Node->kids[j] != NULL) && (val[i]!='\0'))
	{
		while(i==0 && Node->kids[j] != NULL && Node->kids[j]->lettre != val[i])
			{
			j++;
				printf("%d",j);
			}
		if(Node->kids[j]==NULL)
		{
			return check=1;
		}
		if(val[i]!='\0')
		{
			if ((Node->kids[j]->lettre == val[i]) && (check == 0))
			{
				in_tree(Node->kids[j], val, i+1);
			}
	
			else
			{
				check = 1;
			}
		}
		
		
		}
	else{
		check = 1;}
	
	return check;
}


void addWord(t_tree *Tree, char forme_base[], char forme_flechie[], char type[])
{
    int i=0, same = 0;
		Tree->nbrWord ++;
    p_node tmp = Tree->root;
	
		/*if (Tree->nbrWord-1 != 0)
		{
			
		same = in_tree(tmp, forme_base,0);
			}
		else{
			same = 1;
		}
		if (same == 1)
		{
			*/
    	while(forme_base[i+1] != '\0')
    	{
			
				tmp = addKid(tmp, forme_base[i]);


				
				i++;
    	}
			
		tmp = addKid(tmp, forme_base[i]);
		tmp->end = 1;
		}
	




void displayWord(p_node Node,int n_word)
	
{

	printf("%c",Node->lettre);
	if (Node->end == 0)
	{
		displayWord(Node->kids[0], n_word);
	}

}
