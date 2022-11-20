//
// Created by princ on 27/10/2022.
//

#include "Fonctions.h"
#include "arbres.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


void verif(char *nom, char *ligne){
  char buffer[256];
  int cpt = 202;
  FILE* fichier = NULL;
  fichier = fopen("dictionnaire_non_accentue.txt", "r");

    if(fichier != NULL){
      for(int i=0;i<cpt;i++){
        fgets(buffer, 256, fichier);
        if((strstr(buffer, nom) != NULL) && (strstr(buffer, "Nom:Mas") != NULL)){
          strcpy(ligne, buffer);
        }
      }
    }

  fclose(fichier);

}


  