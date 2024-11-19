#include "arbre_liste_chainee.h"

//main généré par chatGPT faute de temps
int main(){
    // Création de la racine de l'arbre
    noeud *racine = creerNoeud(1);

    // Ajout des nœuds fils et frères
    noeud *n2 = creerNoeud(2);
    noeud *n3 = creerNoeud(3);
    noeud *n4 = creerNoeud(4);
    ajouterFils(racine, 1, n2);
    ajouterFils(racine, 1, n3);
    ajouterFils(racine, 1, n4);

    // Ajout de fils à nœud 2
    noeud *n5 = creerNoeud(5);
    noeud *n6 = creerNoeud(6);
    ajouterFils(racine, 2, n5);
    ajouterFils(racine, 2, n6);

    // Ajout de fils à nœud 3
    noeud *n7 = creerNoeud(7);
    noeud *n8 = creerNoeud(8);
    ajouterFils(racine, 3, n7);
    ajouterFils(racine, 3, n8);

    // Ajout de fils à nœud 4
    noeud *n9 = creerNoeud(9);
    noeud *n10 = creerNoeud(10);
    ajouterFils(racine, 4, n9);
    ajouterFils(racine, 4, n10);

    // Affichage de l'arbre
    afficherArbre(racine, 0);

    return 0;
}
