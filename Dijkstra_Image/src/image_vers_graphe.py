import math
import graphe
from PIL import Image
from pathlib import Path

class image:

    def __init__(self, chemin_image:str):
        repertoire_courant = Path(__file__).parent
        self.chemin = repertoire_courant.parent/'res'/chemin_image
        self.image = Image.open(self.chemin).convert("L") #convertit l'image en niveaux de gris
        self.graphe = graphe.Graphe()

        #permet d'ajouter chaque pixel comme un sommet du graphe
        for y in range(self.image.height):
            for x in range(self.image.width):
                valeur_pixel = self.image.getpixel((x,y))
                self.graphe.ajouter_sommet(
                    valeur_pixel
                )

        print(len(self.graphe.liste_sommet))

        nlignes = self.image.height
        ncol = self.image.width
        #pour ajouter les arêtes
        for ligne in range(nlignes):
            for col in range(ncol):
                source = ligne*ncol+col
                if ligne > 0: #si ce n'est pas la première ligne on peut ajouter une arête vers le haut
                    dest = (ligne-1)*ncol+col
                    poids = abs(self.graphe.liste_sommet[dest].val - self.graphe.liste_sommet[source].val)
                    self.graphe.ajouter_arete(source, dest, poids)
                if col > 0: #si ce n'est pas la première colonne on peut ajouter une arête vers la gauche
                    dest = ligne*ncol+(col-1)
                    poids = abs(self.graphe.liste_sommet[dest].val - self.graphe.liste_sommet[source].val)
                    self.graphe.ajouter_arete(source, dest, poids)
                if ligne < (nlignes - 1): #si ce n'est pas la dernière ligne on peut ajouter une arête vers le bas
                    dest = (ligne+1)*ncol+col
                    poids = abs(self.graphe.liste_sommet[dest].val - self.graphe.liste_sommet[source].val)
                    self.graphe.ajouter_arete(source, dest, poids)
                if col < (ncol - 1): #si ce n'est pas la dernière colonne on peut ajouter une arête vers la droite
                    dest = ligne*ncol+(col+1)
                    poids = abs(self.graphe.liste_sommet[dest].val - self.graphe.liste_sommet[source].val)
                    self.graphe.ajouter_arete(source, dest, poids)

    def dijkstra(self, debut, fin):

        self.graphe.liste_sommet[debut].temps_depuis_source = 0
        tentatives = 0

        liste_noeuds_a_visiter = {sommet.num for sommet in self.graphe.liste_sommet}

        while fin in liste_noeuds_a_visiter:
            min_v = -1
            dist = float("inf")

            for v in liste_noeuds_a_visiter:
                if self.graphe.liste_sommet[v].temps_depuis_source < dist:
                    min_v = v
                    dist = self.graphe.liste_sommet[v].temps_depuis_source

            liste_noeuds_a_visiter.remove(min_v)

            tentatives += 1
            for i in range(len(self.graphe.liste_sommet[min_v].liste_adj)):
                a_tester = self.graphe.liste_sommet[min_v].liste_adj[i].dest

                if self.graphe.liste_sommet[a_tester].temps_depuis_source > self.graphe.liste_sommet[min_v].temps_depuis_source + self.graphe.liste_sommet[min_v].liste_adj[i].pds:
                    self.graphe.liste_sommet[a_tester].temps_depuis_source = self.graphe.liste_sommet[min_v].temps_depuis_source + self.graphe.liste_sommet[min_v].liste_adj[i].pds
                    self.graphe.liste_sommet[a_tester].precedent = self.graphe.liste_sommet[min_v]

        liste_chemin = list()
        sommet_c = self.graphe.liste_sommet[fin]
        while sommet_c:
            liste_chemin.insert(0,sommet_c.num)
            sommet_c = sommet_c.precedent

        print("Dijkstra terminé")
        return liste_chemin

    def a_etoile(self, debut, fin):

        self.graphe.liste_sommet[debut].temps_depuis_source = 0
        tentatives = 0

        liste_noeuds_a_visiter = {sommet.num for sommet in self.graphe.liste_sommet}

        x_fin = fin % self.image.width
        y_fin = fin // self.image.height

        for v in liste_noeuds_a_visiter:
            x_v = v % self.image.width
            y_v = v // self.image.height
            self.graphe.liste_sommet[v].heuristique = math.sqrt(math.pow(x_fin - x_v, 2)+math.pow(y_fin - y_v, 2))

        while fin in liste_noeuds_a_visiter:
            min_v = -1
            dist = float("inf")

            for v in liste_noeuds_a_visiter:
                if self.graphe.liste_sommet[v].temps_depuis_source +self.graphe.liste_sommet[v].heuristique < dist:
                    min_v = v
                    dist = self.graphe.liste_sommet[v].temps_depuis_source + self.graphe.liste_sommet[v].heuristique

            liste_noeuds_a_visiter.remove(min_v)

            tentatives += 1
            for i in range(len(self.graphe.liste_sommet[min_v].liste_adj)):
                a_tester = self.graphe.liste_sommet[min_v].liste_adj[i].dest

                if self.graphe.liste_sommet[a_tester].temps_depuis_source > self.graphe.liste_sommet[min_v].temps_depuis_source + self.graphe.liste_sommet[min_v].liste_adj[i].pds:
                    self.graphe.liste_sommet[a_tester].temps_depuis_source = self.graphe.liste_sommet[min_v].temps_depuis_source + self.graphe.liste_sommet[min_v].liste_adj[i].pds
                    self.graphe.liste_sommet[a_tester].precedent = self.graphe.liste_sommet[min_v]

        liste_chemin = list()
        sommet_c = self.graphe.liste_sommet[fin]
        while sommet_c:
            liste_chemin.insert(0,sommet_c.num)
            sommet_c = sommet_c.precedent

        print("A étoile terminé")
        return liste_chemin