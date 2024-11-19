#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graphe_liste_chainee.h"

//http://www.discmath.ulg.ac.be/cours/main_graphes.pdf

sommet *creerSommet(int val){
  sommet *nouvSommet = (sommet*)malloc(sizeof(sommet));
  if(nouvSommet == NULL){
    printf("erreur lors de la creation du sommet");
    return NULL;
  }
  nouvSommet->suivant = NULL;
  nouvSommet->listeAdj = NULL;
  nouvSommet->valeur = val;
  return nouvSommet;
}

void ajouterSommet(sommet *g, sommet *nouvSommet){
  if(g == NULL){
    return;
  }
  if(g->suivant == NULL){
    g->suivant = nouvSommet;
  }
  else{
    ajouterSommet(g->suivant, nouvSommet);
  }
}

sommet *creerGraphe(int val){
  sommet *nouv_graphe = creerSommet(val);
  return nouv_graphe;
}

sommet *chercherSommet(sommet *g, int val){
  if(g == NULL){
    return NULL;
  }
  if(g->valeur == val){
    return g;
  }
  return(chercherSommet(g->suivant, val));
}

void ajouterAdjacence(sommet *g, int src, int dest){
  if(chercherSommet(g, src) != NULL && chercherSommet(g, dest) != NULL){
    //adj entre src et dest
    sommet *source = chercherSommet(g, src);
    sommetAdj *listeAdj = source->listeAdj;
    if(listeAdj == NULL){
      sommetAdj *nouvAdj = (sommetAdj*)malloc(sizeof(sommetAdj));
      nouvAdj->suivant = NULL;
      nouvAdj->val_sommet = dest;
      source->listeAdj = nouvAdj;
    }
    else{
      while(listeAdj->suivant != NULL && listeAdj->val_sommet != dest){
        listeAdj = listeAdj->suivant;
      }
      if(listeAdj->val_sommet != dest){
        sommetAdj *nouvAdj = (sommetAdj*)malloc(sizeof(sommetAdj));
        nouvAdj->suivant = NULL;
        nouvAdj->val_sommet = dest;
        listeAdj->suivant = nouvAdj;
      }
    }
    //adj entre dest et src
    sommet *destination = chercherSommet(g, dest);
    sommetAdj *listeAdj2 = destination->listeAdj;
    if(listeAdj2 == NULL){
      sommetAdj *nouvAdj2 = (sommetAdj*)malloc(sizeof(sommetAdj));
      nouvAdj2->suivant = NULL;
      nouvAdj2->val_sommet = src;
      destination->listeAdj = nouvAdj2;
    }
    else{
      while(listeAdj2->suivant != NULL && listeAdj2->val_sommet != src){
        listeAdj2 = listeAdj2->suivant;
      }
      if(listeAdj2->val_sommet != src){
        sommetAdj *nouvAdj2 = (sommetAdj*)malloc(sizeof(sommetAdj));
        nouvAdj2->suivant = NULL;
        nouvAdj2->val_sommet = src;
        listeAdj2->suivant = nouvAdj2;
      }
    }
  }
}

void afficherGraphe(sommet *g){
  printf("sommet : %d, adjacence :\n", g->valeur);
  sommetAdj *liste = g->listeAdj;
  while(liste != NULL){
    printf("sommet %d\n", liste->val_sommet);
    liste = liste->suivant;
  }
  if(g->suivant != NULL){
    afficherGraphe(g->suivant);
  }
}

