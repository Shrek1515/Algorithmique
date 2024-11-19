----------------------------------------------------------
Pour compiler : 
faire : gcc arbre_liste_chainee.c main.c -o programme
Pour lancer :
faire : ./programme

Pour changer d'arbre, il faut se rendre dans le fichier main, 

Pour créer un arbre utiliser la fonction "creerNoeud()" qui prend en argument un entier : la valeur du noeud, cette fonction retourne un pointeur de noeud (noeud *n par exemple).

Pour ajouter un sommet faire "ajouterFils(, );" cette fonction prend en argument trois arguments, le premier un pointeur de noeud désignant la racine de l'arbre, le deuxième un entier désignant la valeur d'un noeud de l'arbre, qui doit être OBLIGATOIREMENT déjà présent dans l'arbre, le troisième un pointeur de noeud que l'on souhaite ajouter.

Pour afficher le graphe faire "afficherArbre()" et donner en argument le pointeur du graphe.
