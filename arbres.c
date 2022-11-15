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

/*int in_table(p_node noeud, char val) {
    int i = 0, check = 0;
    while ((i < noeud->nbrKids) && (check == 0)) {
        if (noeud->kids[i]->lettre == val) 
				{
						printf("check !\n");
            check = 1;
            printf("C'est %c\n",noeud->kids[i]->lettre);
        }
				
        i++;
    }
		

    return check;
}*/

void addWord(t_tree *Tree, char forme_base[], char forme_flechie[], char type[])
{
    int i=0;
		Tree->nbrWord += 1;
    p_node tmp = Tree->root;
		
    while(forme_base[i+1] != '\0')
    {
			/*if (in_table(tmp, forme_base[i])==0)
        {
						p_node nv_temp = addKid(tmp, forme_base[i]);
						tmp = nv_temp;
           	
            }
        else
        {
						int j = 0;
            while ((tmp->kids[j]->lettre != forme_base[i])){
                j++;
            }
            tmp = tmp->kids[j];
            
        }*/

			tmp = addKid(tmp, forme_base[i]);
			
        i++;
    }
	tmp = addKid(tmp, forme_base[i]);
	tmp->end = 1;
	/*if (tmp->flechie->head->flechie == NULL)
	{
  tmp->flechie->head->flechie = forme_flechie;
		}
	else
	{
		t_std_list tes = tmp->flechie->head->next;
	}
	if (tmp->flechie->head->type == NULL)
	{
	tmp->flechie->head->type = type;
		}


*/
}
void displayWord(p_node Node,int n_word)
	
{

	printf("%c",Node->lettre);
	if (Node->end == 0)
	{
		displayWord(Node->kids[0], n_word);
	}

}
/*
void tableWord(p_node Node,int n_word,char *word)
{

while(i == 0)
{
printf("%c",tmp->kids[i]->lettre);
i = displayWord(tmp->kids[n_word],n_word);
}
	int i=0;
	
	while(word[i]!='\0')
		{
			i++;
		}
	
	word[i] = Node->lettre;
	word[i+1] = '\0';
	if (Node->end == 0)
	{
		
		tableWord(Node->kids[0], n_word, word);
	}
printf("%s\n",word);
}
*/