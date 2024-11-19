#ifndef PARCOURS_H
#define PARCOURS_H

#include "arbre_binaire.h"

void visiter_prefixe(noeud *arbre);
void visiter_suffixe(noeud *arbre);
void visiter_infixe(noeud *arbre);
noeud *arbre_aleatoire(int niv_noeuds);

#endif
