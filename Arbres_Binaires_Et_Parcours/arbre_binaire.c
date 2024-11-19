#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbre_binaire.h"

noeud *nouvNoeud(char valeur){
  static int id = 0;
  noeud *nouveau_noeud = (noeud*)malloc(sizeof(noeud));
  if (nouveau_noeud == NULL) {
    perror("Erreur d'allocation de mémoire");
    exit(EXIT_FAILURE);
  }
  id+=1;
  nouveau_noeud->valeur = valeur;
  nouveau_noeud->id = id;
  nouveau_noeud->fils_droit = NULL;
  nouveau_noeud->fils_gauche = NULL;
  return nouveau_noeud;
}

noeud *rechercheNoeud(noeud *arbre, int num_noeud){
  noeud *tmpNoeud;
  if(arbre == NULL){
    return NULL;
  }
  if(arbre->id == num_noeud){
    return arbre;
  }
  tmpNoeud = rechercheNoeud(arbre->fils_gauche,num_noeud);
  if(tmpNoeud!=NULL){
    return tmpNoeud;
  }
  return(rechercheNoeud(arbre->fils_droit, num_noeud));
} 

void insererFG(noeud *nouveau_noeud, noeud *arbre, int val){
  noeud *pere = rechercheNoeud(arbre, val);
  if(pere != NULL){
    nouveau_noeud->fils_gauche = pere->fils_gauche;
    pere->fils_gauche = nouveau_noeud;
  }
}

void insererFD(noeud *nouveau_noeud, noeud *arbre, int val){
  noeud *pere = rechercheNoeud(arbre, val);
  if(pere != NULL){
    nouveau_noeud->fils_droit = pere->fils_droit;
    pere->fils_droit = nouveau_noeud;
  }
}




