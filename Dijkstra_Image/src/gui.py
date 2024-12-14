import tkinter as tk
from pathlib import Path

from PIL import Image, ImageTk
import image_vers_graphe

class interface_graphique:

    def __init__(self):

        self.racine = tk.Tk()
        self.racine.title("Plus court chemin sur image")
        self.racine.geometry("1600x900")

        self.cadre_image = tk.Frame(self.racine, bd=0, highlightthickness=0, background="#fe8e36")
        self.cadre_image.place(x=0, y=0, relwidth=0.5, relheight=1, anchor="nw")

        self.cadre_entree_uti = tk.Frame(self.racine, bd=0, highlightthickness=0, background="#3da1eb")

        self.cadre_entree_uti.columnconfigure(0, weight=1, uniform='column')
        self.cadre_entree_uti.columnconfigure(1, weight=1, uniform='column')
        self.cadre_entree_uti.columnconfigure(2, weight=1, uniform='column')
        self.cadre_entree_uti.columnconfigure(3, weight=1, uniform='column')

        self.cadre_entree_uti.rowconfigure(0, weight=1, uniform='row')
        self.cadre_entree_uti.rowconfigure(1, weight=1, uniform='row')
        self.cadre_entree_uti.rowconfigure(2, weight=1, uniform='row')
        self.cadre_entree_uti.rowconfigure(3, weight=1, uniform='row')

        self.cadre_entree_uti.place(relx=0.5, y=0, relwidth=0.5, relheight=1, anchor="nw")

        self.bouton_coord = tk.Button(self.cadre_entree_uti, text="démarrer", command=self.afficher_coord)
        self.bouton_chemin = tk.Button(self.cadre_entree_uti, text="choisir", command=self.afficher_image)

        self.chemin = tk.Entry(self.cadre_entree_uti)
        self.chemin_label = tk.Label(self.cadre_entree_uti, text="Chemin vers image :")
        self.chemin_label.grid(row=0,column=0)

        self.chemin.grid(row=0, column=1)
        self.bouton_chemin.grid(row=0, column=2)

        self.entree_x = tk.Entry(self.cadre_entree_uti)
        self.x_label = tk.Label(self.cadre_entree_uti, text="Point de départ :")
        self.x_label.grid(row=1, column=0)
        self.entree_y = tk.Entry(self.cadre_entree_uti)
        self.y_label = tk.Label(self.cadre_entree_uti, text="Point d'arrivée :")
        self.y_label.grid(row=1, column=2)

        self.entree_x.grid(row=1, column=1)
        self.entree_y.grid(row=1,column=3)
        self.bouton_coord.grid(row=2, column=0)

        self.etat_var = tk.StringVar()
        self.etat_var.set("repos")
        self.etat_label = tk.Label(self.cadre_entree_uti, textvariable=self.etat_var)
        self.etat_label.grid(row=2, column=1)

        self.racine.mainloop()

    def afficher_image(self):
        try:
            print("test2")
            print(self.chemin.get())

            repertoire_courant = Path(__file__).parent
            self.chemin_image = repertoire_courant.parent/'res'/self.chemin.get()
            self.image = Image.open(self.chemin_image)
            self.photo = ImageTk.PhotoImage(self.image)
            self.canvas = tk.Canvas(self.cadre_image, width=self.image.width, height=self.image.height, borderwidth=0,highlightthickness=0)
            self.canvas.place(relx=0.5, rely=0.5, anchor="center")
            self.canvas.create_image(0, 0, image=self.photo, anchor=tk.NW)
        except IsADirectoryError:
            self.etat_var.set("Veuillez entrer un chemin valide.")

    def afficher_coord(self):
        try:
            print("test")
            print(self.entree_x.get(), self.entree_y.get())

            self.etat_var.set("Veuillez patienter.")

            x_coord = (int(self.entree_x.get().split(',')[0]), int(self.entree_x.get().split(',')[1]))
            y_coord = (int(self.entree_y.get().split(',')[0]), int(self.entree_y.get().split(',')[1]))

            x = x_coord[1] * self.image.width + x_coord[0]
            y = y_coord[1] * self.image.width + y_coord[0]

            print(x,y)

            graphe = image_vers_graphe.image(self.chemin.get())
            chemin = graphe.a_etoile(x,y)

            self.etat_var.set("Terminé.")

            for pixel in chemin:
                center_x = pixel % self.image.width
                center_y = pixel // self.image.width
                # Dessiner un petit point rouge

                self.canvas.create_oval(
                    center_x - 1,
                    center_y - 1,
                    center_x + 1,
                    center_y + 1,
                    fill="red",
                    outline="red"
                )
        except ValueError:
            self.etat_var.set("Veuillez entrer point correct.")