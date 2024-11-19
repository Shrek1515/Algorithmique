#include "graphe_liste_chainee.h"

int main(){
  sommet *g = creerGraphe(0);
  sommet *s1 = creerSommet(1);
  ajouterSommet(g, s1);
  sommet *s2 = creerSommet(2);
  ajouterSommet(g, s2);
  sommet *s3 = creerSommet(3);
  ajouterSommet(g, s3);
  sommet *s4 = creerSommet(4);
  ajouterSommet(g, s4);
  sommet *s5 = creerSommet(5);
  ajouterSommet(g, s5);
  sommet *s6 = creerSommet(6);
  ajouterSommet(g, s6);
  
  ajouterAdjacence(g, 0, 1);
  ajouterAdjacence(g, 0, 2);
  ajouterAdjacence(g, 0, 3);
  
  ajouterAdjacence(g, 6, 1);
  ajouterAdjacence(g, 6, 4);
  ajouterAdjacence(g, 6, 5);
  
  afficherGraphe(g);
  return 0;
}
