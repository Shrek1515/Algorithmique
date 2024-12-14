class Graphe:

    def __init__(self):
        self.liste_sommet = list()
        self.num = 0

    def ajouter_sommet(self, valeur):
        self.liste_sommet.append(Sommet(valeur, self.num))
        self.num += 1

    def ajouter_arete(self, sommet1, sommet2, poids):
        self.liste_sommet[sommet1].liste_adj.append(Arete(sommet1, sommet2, poids))

class Sommet:

    def __init__(self, valeur, num):
        self.num = num
        self.val = valeur #intensité de gris
        self.liste_adj: list = list() #c'est la liste des arêtes
        self.precedent = None
        self.temps_depuis_source = float("inf")
        self.heuristique = -1

class Arete:

    def __init__(self, sommet1, sommet2, poids):
        self.src = sommet1
        self.dest = sommet2
        self.pds = poids