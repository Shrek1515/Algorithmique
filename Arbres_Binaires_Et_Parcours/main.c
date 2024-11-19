#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbre_binaire.h"
#include "parcours.h"

int main(int argc, char **argv){
  srand(time(NULL));
  noeud *arbre = arbre_aleatoire(atoi(argv[1]));
  printf("prefixe 10 niv\n");
  visiter_prefixe(arbre);
  printf("suffixe 10 niv\n");
  visiter_suffixe(arbre);
  printf("infixe 10 niv\n");
  visiter_infixe(arbre);
  
  /*
  printf("------------\n");
  noeud *arbre = nouvNoeud('a');
  noeud *nb = nouvNoeud('b');
  noeud *nc = nouvNoeud('c');
  noeud *nd = nouvNoeud('d');
  noeud *ne = nouvNoeud('e');
  noeud *nf = nouvNoeud('f');
  insererFG(nb, arbre, arbre->id);
  insererFD(nc, arbre, arbre->id);
  insererFG(nf, arbre, nb->id);
  insererFG(nd, arbre, nc->id);
  insererFD(ne, arbre, nc->id);
  printf("prefixe arbre\n");
  visiter_prefixe(arbre);
  printf("suffixe arbre\n");
  visiter_suffixe(arbre);
  printf("infixe arbre\n");
  visiter_infixe(arbre);
  free(nb);
  free(nc);
  free(nd);
  free(ne);
  free(nf);
  */
  free(arbre);

  return 0;
}
