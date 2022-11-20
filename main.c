#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fonctions.h"
#include "arbres.h"
#include "node.h"
#include <time.h>  



int hasard(int aim)
{
	srand(time(NULL));
    int a = 0;
    a = rand() % aim;
	return a;
}

void generate_model_1_base(t_tree nom,t_tree adjectif, t_tree verbe)
{
	int a, b, c, d;
    a = hasard(nom.nbrWord);
    displayWord(nom.root->kids[a],a);
    printf(" ");
	  b = hasard(adjectif.nbrWord);
    displayWord(adjectif.root->kids[b],b);
	  printf(" ");
		c = hasard(verbe.nbrWord);
    displayWord(verbe.root->kids[c],c);
		printf(" ");
    d = hasard(nom.nbrWord);
    while (d==a)
			d = hasard(nom.nbrWord);
   
	  displayWord(nom.root->kids[d],d);
		
		printf("\n");
}
void generate_model_2_base(t_tree nom,t_tree adjectif, t_tree verbe)
{
	int a, b, c, d;
    a = hasard(nom.nbrWord);
    displayWord(nom.root->kids[a],a);
    printf(" qui ");
	  b = hasard(verbe.nbrWord);
    displayWord(verbe.root->kids[b],b);
	  printf(" ");
		c = hasard(verbe.nbrWord);
    c = c + 50;
    displayWord(verbe.root->kids[c],c);
		printf(" ");
		d = hasard(adjectif.nbrWord);
    printf(" ");
	  displayWord(adjectif.root->kids[d],d);
		
		printf("\n");
}
void generate_random_word(t_tree Tree)
{
	int a;
	a = hasard(Tree.nbrWord);
    displayWord(Tree.root->kids[a],a);
    printf(" ");
}

int rechercher_mot2(p_node Node, char *val, int i)
{
	int check = 0, check2 =0;
	int j = 0;
	if((Node != NULL) && (val[i]!='\0'))
	{
		
		if(Node==NULL)
		{
			return check=1;
		}
		if(val[i]!='\0')
		{
			if ((Node->lettre == val[i]) && (check == 0))
			{
				check = rechercher_mot2(Node->kids[j], val, i+1);
			}

				
			else
			{
				
				return check = 0;
			}
		}
		
		
		}
	else{
		return check = 1;
		}
	
	return check;
}



int rechercher_mot(p_node Node, char *val, int i)
{
	int check = 0, realcheck =0;
	int j = 0;
	if(Node->kids[j] != NULL)
	{
		while(i==0 && Node->kids[j] != NULL && Node->kids[j]->lettre != val[i])
			{
			j++;	
			}
		if(Node->kids[j]==NULL)
		{
			return check=1;
		}

		while (realcheck != 1)
		{
			
			while(Node->kids[j] != NULL && Node->kids[j]->lettre != val[i] && realcheck == 0)
			{
				j++;
				
				if(j+1>Node->nbrKids){
					return check;
				}
			}
			
		
			
			
			realcheck = rechercher_mot2(Node->kids[j], val, i);
			j++;
			if(j+1>Node->nbrKids){
					return check;
				}
		}
		
	
	
	}
	check = 1;
	return check;
	}

int main() {
	 
  int cpt = 1;
	t_tree nom;
  t_tree verbe;
  t_tree adverbe;
  t_tree adjectif;
  nom = createEmptyTree();
	verbe = createEmptyTree();
  adverbe = createEmptyTree();
  adjectif = createEmptyTree();
	
	while(cpt!=202)
	{
    char* flechie;
    char* normal;
    char* forme;
    char tab[256];
    recup_mot(cpt, tab);
  
    flechie = strtok(tab, "\t");
    normal = strtok(NULL, "\t");
    forme = strtok(NULL, "\t");

  	if(strstr(forme,"Nom")){
      addWord(&nom,normal,flechie,"Nom");
  		}
  	if(strstr(forme,"Ver")){
      addWord(&verbe,normal,flechie,"Verbe");
  		}
  	if(strstr(forme,"Adj")){
      addWord(&adjectif,normal,flechie,"Adjectif");
  		}
  	if(strstr(forme,"Adv")){
      addWord(&adverbe,normal,flechie,"Adverbe");
  		}
  		
      cpt++;
  }
	menu(nom,adjectif,verbe,adverbe);
}

void menu(t_tree nom, t_tree adjectif, t_tree verbe, t_tree adverbe){
	int choix;
	char mots[34];
	int choix2;
	int choix3;
	int choix4;
    
    printf("Bienvenue sur le generateur de phrase\n1.Générer une phrase avec des mots(forme de base).\n2.Recherche de mot.\n3.Extraire un mot au hasard\n4.Quitter\n-> ");

	scanf("%d",&choix);
	switch(choix)
		{
			case 1:
			printf("Souhaitez-vous lancer \n1.Le modèle N 1\n2.Le modèle N 2\n->");

	scanf("%d",&choix4);
	switch(choix4)
		{
			case 1:
			generate_model_1_base(nom,adjectif,verbe);
			break;
			case 2:
			generate_model_2_base(nom,adjectif,verbe);
			break;
		};
			break;
			
			case 2:
			printf("Souhaitez-vous\n1.Un nom\n2.Un verbe\n3.Un adjectif\n4.Un adverbe ?\n");
			scanf("%d",&choix2);
			printf("Quel mot cherchez-vous ?\n");
			scanf("%s",mots);
				switch(choix2)
		{
			
			
			case 1:
				
				if(rechercher_mot(nom.root, mots, 0) == 1)
				{
					printf("Le mot a bien été trouvé.");
				}
				else
				{
					printf("Le mot n'a pas été trouvé.");
				}
			break;
			case 2:
				
				if(rechercher_mot(verbe.root, mots, 0) == 1)
				{
					printf("Le mot a bien été trouvé.");
				}
				else
				{
					printf("Le mot n'a pas été trouvé.");
				}
			break;
			case 3:
				
				if(rechercher_mot(adjectif.root,mots, 0) == 1)
				{
					printf("Le mot a bien été trouvé.");
				}
				else
				{
					printf("Le mot n'a pas été trouvé.");
				}
			break;
			case 4:
				
				if(rechercher_mot(adverbe.root, mots, 0) == 1)
				{
					printf("Le mot a bien été trouvé.");
				}
				else
				{
					printf("Le mot n'a pas été trouvé.");
				}
				break;
				default:
					printf("Erreur");
			
			}
			break;
			
			case 3:
			printf("Souhaitez-vous\n1.Un nom\n2.Un verbe\n3.Un adjectif\n4.Un adverbe ?\n");
			scanf("%d",&choix3);
			switch(choix3)
				{
					case 1:
					generate_random_word(nom);
					break;
					case 2:
					generate_random_word(verbe);
					break;
					case 3:
					generate_random_word(adjectif);
					break;
					case 4:
					generate_random_word(adverbe);
					break;
				default:
					printf("erreur, fermeture de l'application");
				}
			break;
      case 4:
        EXIT_SUCCESS; 
      break;
			default:
					printf("erreur, fermeture de l'application");
		}
	printf("\nAu revoir les amis !");
}