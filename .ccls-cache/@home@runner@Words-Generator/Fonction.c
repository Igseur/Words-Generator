//
// Created by princ on 27/10/2022.
//

#include "fonction.h"
#include "arbres.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void menu(){
    printf("   ************HELLO************\n");
    printf("Bienvenue sur le generateur de phrase\n");
}




void recup_mot(int cpt, char* ligne_out ){

  char mots;
  int i = 0;
  FILE* fichier = NULL;
  fichier = fopen("mini_dico.txt", "r");
  if(fichier != NULL){
    for(i=0;i<cpt;i++){
      fgets(ligne_out, 256, fichier);

    }
		
  }  
	
  fclose(fichier);
}





  