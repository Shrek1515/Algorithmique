import java.util.ArrayList;
import java.util.Collections;

public class Graphe {
    private ArrayList<Sommet> sommets;
    private ArrayList<Arete> aretes;

    public Graphe(){
        this.aretes = new ArrayList<>();
        this.sommets = new ArrayList<>();
    }

    public void ajouterSommet(Sommet s){
        for(Sommet v: this.sommets){
            if(v.getID() == s.getID()){
                throw new IllegalArgumentException("Erreur, le sommet "+s.getValeur()+" est déjà présent dans le graphe.");
            }
        }
        this.sommets.add(s);
    }

    public void ajouterArete(Sommet s1, Sommet s2, int poids){
        if(this.sommets.contains(s1) && this.sommets.contains(s2)){
            this.aretes.add(new Arete(s1,s2,poids));
        }
        else{
            throw new IllegalArgumentException("Erreur, l'un des deux sommets("+s1.getValeur()+" ou "+s2.getValeur()+")n'est pas présent dans le graphe, veuillez l'ajouter avant de lui assigner une arête.");
        }
    }

    public ArrayList<Arete> getAretes(){
        return this.aretes;
    }

    public ArrayList<Arete> kruskal(){

        //liste des arêtes triées en fonction de leur poids
        ArrayList<Arete> l = this.aretes;
        Collections.sort(l);

        //forêt f, liste des arêtes de l'arbre retourné par la fonction
        ArrayList<Arete> f = new ArrayList<>();

        //initialisation des composantes connexes des sommets du graphe
        //elles sont toutes différentes au départ, car aucune n'est encore dans f
        for(int i =0; i<sommets.size(); i+=1){
            sommets.get(i).setComposanteConnexe(i);
        }

        int e = 0;
        //dans un arbre il y a n-1 arêtes
        while(f.size() < this.sommets.size() - 1){
            Arete a = l.get(e);
            //si les deux sommets de l'arête n'ont pas la même composante connexe dans f
            //alors on ajoute l'arête dans f
            if(a.getSommet1().getComposanteConnexe() != a.getSommet2().getComposanteConnexe()){
                f.add(a);
                //on met à jour la composante connexe des sommets partageant la même composante connexe
                //que le sommet s2
                for(Sommet s: sommets){
                    if(s.getComposanteConnexe() == a.getSommet2().getComposanteConnexe()){
                        s.setComposanteConnexe(a.getSommet1().getComposanteConnexe());
                    }
                }
            }
            e += 1;
        }
        return f;
    }
}
