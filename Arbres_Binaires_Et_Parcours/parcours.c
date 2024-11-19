#include <stdio.h>
#include <stdlib.h>
#include "parcours.h"
#include "arbre_binaire.h"

//on affiche chaque sommet la première fois qu’on le rencontre
void visiter_prefixe(noeud *arbre){
  printf("noeud : %c\n", arbre->valeur);
  if(arbre->fils_gauche != NULL){
    visiter_prefixe(arbre->fils_gauche);
  }
  if(arbre->fils_droit != NULL){
    visiter_prefixe(arbre->fils_droit);
  }
}

//on affiche chaque sommet la dernière fois qu’on le rencontre
void visiter_suffixe(noeud *arbre){
  if(arbre->fils_gauche != NULL){
    visiter_suffixe(arbre->fils_gauche);
  }
  if(arbre->fils_droit != NULL){
    visiter_suffixe(arbre->fils_droit);
  }
  printf("noeud : %c\n", arbre->valeur);
}

//on affiche chaque sommet ayant un fils gauche la seconde fois qu’on le voit et chaque sommet sans fils gauche la première fois qu’on le voit
void visiter_infixe(noeud *arbre){
  if(arbre->fils_gauche != NULL){
    visiter_infixe(arbre->fils_gauche);
  }
  printf("noeud : %c\n", arbre->valeur);
  if(arbre->fils_droit != NULL){
    visiter_infixe(arbre->fils_droit);
  }
}

noeud *arbre_aleatoire(int niv_noeuds){
  if(niv_noeuds <= 0){
    return NULL;
  }
  noeud *nouv_noeud = nouvNoeud('A' + rand()%26);
  int booleen_1 = rand()%2;
  int booleen_2 = rand()%2;
  if(booleen_1 == 1){
    nouv_noeud->fils_droit = arbre_aleatoire(niv_noeuds-1);
  }
  if(booleen_2 == 1){
    nouv_noeud->fils_gauche = arbre_aleatoire(niv_noeuds-1);
  }
  if(booleen_1 == 0 && booleen_2 == 0){
    int choix = rand()%2;
    if(choix == 1){
      nouv_noeud->fils_droit = arbre_aleatoire(niv_noeuds-1);
    }
    else{
      nouv_noeud->fils_gauche = arbre_aleatoire(niv_noeuds-1);
    }
  }
  return nouv_noeud;
}

