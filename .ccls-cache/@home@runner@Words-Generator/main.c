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

void rechercher_mot(t_tree Tree, char *mot)
{
	int i = 0;
	int j = 0;
	int check = 0;
	
	while (Tree.root->kids[i] != NULL)
		{
			if (Tree.root->kids[i]->lettre == mot[j]){
				check = 1;
				j++;
				printf("%c %c",Tree.root->kids[i]->lettre, mot[j]);
			}
	i++;
		}
	
	
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
	
	while(cpt!=200)
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
	int choix2;
	int choix3;
	int choix4;
    printf("************HELLO************\n");
    printf("Bienvenue sur le generateur de phrase\n1.Générer une phrase avec des mots(forme de base).\n2.Recherche de mot        (H.S).\n3.Extraire un mot au hasard\n4.Quitter\n-> ");

	scanf("%d",&choix);
	switch(choix)
		{
			case 1:
			printf("Souhaitez-vous lancer \n1.Le modèle N 1\n2.Le modèle N 2\n");

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
			/*case 2:
			printf("Souhaitez-vous\n1.Un nom\n2.Un verbe\n3.Un adjectif\n4.Un adverbe ?\n");
			scanf("%d",&choix2);
			switch(choix2)
				{
					case 1:
					printf("quel mot souhaitez-vous ?");
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
			break;*/
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