#ifndef ARBRE_BINAIRE_H
#define ARBRE_BINAIRE_H

typedef struct noeud{
  char valeur;
  int id;
  struct noeud *fils_droit;
  struct noeud *fils_gauche;
}noeud;

noeud *nouvNoeud(char valeur);
noeud * rechercheNoeud(noeud *arbre, int num_noeud);
void insererFG(noeud *nouveau_noeud, noeud *arbre, int val);
void insererFD(noeud *nouveau_noeud, noeud *arbre, int val);

#endif
