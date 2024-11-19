#ifndef ARBRE_LISTE_CHAINEE_H
#define ARBRE_LISTE_CHAINEE_H

typedef struct noeud{
  int id;
  int valeur;
  struct noeud *premierFils; //on met le premier fils ici, quand on en aura d'autre on les mettra dans les freres de lui
  struct noeud *freres;
}noeud;

noeud *creerNoeud(int val);
noeud *chercherNoeud(noeud *arbre, int val_noeud);
void ajouterFils(noeud *arbre, int val_pere, noeud *fils);
void afficherArbre(noeud *racine, int niveau);

#endif
