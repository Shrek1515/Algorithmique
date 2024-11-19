#include <stdio.h>
#include <stdlib.h>
#include "arbre_liste_chainee.h"

noeud *creerNoeud(int val){
  static int id = 0;
  noeud *nouvNoeud = (noeud*)malloc(sizeof(noeud));
  if(nouvNoeud == NULL){
    printf("erreur lors de la creation du noeud");
    return NULL;
  }
  nouvNoeud->id = id;
  id+=1;
  nouvNoeud->valeur = val;
  nouvNoeud->premierFils = NULL;
  nouvNoeud->freres = NULL;
  return nouvNoeud;
}

noeud *chercherNoeud(noeud *arbre, int val_noeud){
  if(arbre->valeur == val_noeud){
    return arbre;
  }
  if(arbre->freres != NULL){
    return chercherNoeud(arbre->freres, val_noeud);
  }
  if(arbre->premierFils != NULL){
    return chercherNoeud(arbre->premierFils, val_noeud);
  }
}

void ajouterFils(noeud *arbre, int val_pere, noeud *fils){
  if(chercherNoeud(arbre, val_pere) != NULL && chercherNoeud(arbre, fils->valeur) == NULL){ //je pense que le fils ne doit pas être déjà dans l'arbre, logique en fait
    noeud *pere = chercherNoeud(arbre, val_pere);
    if(pere->premierFils == NULL){
      pere->premierFils = fils;
    }
    else{
      noeud *filsPere = pere->premierFils;
      while(filsPere->freres != NULL){
        filsPere = filsPere->freres;      
      }
      filsPere->freres = fils;
    }
  }
}

//fonction générée par chatGPT, faute de temps
void afficherArbre(noeud *racine, int niveau) {
    if (racine == NULL) {
        return;
    }
    
    // Affichage du niveau d'indentation pour la structure de l'arbre
    for (int i = 0; i < niveau; i++) {
        printf("  ");
    }
    
    // Affichage du nœud actuel
    printf("Noeud ID: %d, Valeur: %d\n", racine->id, racine->valeur);
    
    // Appel récursif pour afficher tous les fils
    if (racine->premierFils != NULL) {
        afficherArbre(racine->premierFils, niveau + 1);
    }
    
    // Appel récursif pour afficher les frères
    if (racine->freres != NULL) {
        afficherArbre(racine->freres, niveau);
    }
}




