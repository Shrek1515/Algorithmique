#ifndef GRAPHE_LISTE_CHAINEE_H
#define GRAPHE_LISTE_CHAINEE_H

typedef struct sommetAdj{
  int val_sommet;
  struct sommetAdj *suivant;
}sommetAdj;

typedef struct sommet{
  int valeur;
  struct sommet *suivant;
  struct sommetAdj *listeAdj;
}sommet;

sommet *creerSommet(int val);
void ajouterSommet(sommet *g, sommet *nouvSommet);
sommet *creerGraphe(int val);
sommet *chercherSommet(sommet *g, int val);
void ajouterAdjacence(sommet *g, int src, int dest);
void afficherGraphe(sommet *g);

#endif
