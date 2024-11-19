----------------------------------------------------------
Pour compiler : 
faire : gcc graphe_liste_chainee.c main.c -o programme
Pour lancer :
faire : ./programme

Pour changer le graphe, il faut se rendre dans le fichier main, 

Pour créer un graphe utiliser la fonction "creerGraphe()" qui prend en argument un entier : la valeur du premier sommet, cette fonction retourne un pointeur sommet (sommet *s par exemple).

Pour créer un sommet faire "creerSommet();" cette fonction prend en argument un entier : la valeur du sommet et retourne aussi un pointeur de sommet.

Pour ajouter un sommet faire "ajouterSommet(, );" cette fonction prend en argument deux pointeur de sommet, le premier représente l'arbre (le premier sommet créé via creerGraphe) et le deuxième et le sommet que l'on souhaite ajouter.

Pour ajourer une adjacence faire "ajouterAdjacence(, , )" cette fonction a trois arguments, le premier un pointeur de sommets pour le graphe, les deux autres des entiers pour désigner les valeurs des deux sommets, ces valeurs doivent être OBLIGATOIREMENT les valeurs de sommets existants dans le graphe.

Pour afficher le graphe faire "afficherGraphe()" et donner en argument le pointeur du graphe et le niveau (mettre 0 pour afficher l'arbre complètement).
