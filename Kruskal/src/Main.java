import java.util.ArrayList;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        Graphe g = new Graphe();

        Sommet s1 = new Sommet(1);
        Sommet s2 = new Sommet(2);
        Sommet s3 = new Sommet(3);
        Sommet s4 = new Sommet(4);
        Sommet s5 = new Sommet(5);
        Sommet s6 = new Sommet(6);
        Sommet s7 = new Sommet(7);
        Sommet s8 = new Sommet(8);

        try{
            g.ajouterSommet(s1);
            g.ajouterSommet(s2);
            g.ajouterSommet(s3);
            g.ajouterSommet(s4);
            g.ajouterSommet(s5);
            g.ajouterSommet(s6);
            g.ajouterSommet(s7);
            g.ajouterSommet(s8);

            g.ajouterArete(s1,s2,3);
            g.ajouterArete(s1,s3,1);
            g.ajouterArete(s2,s3,4);
            g.ajouterArete(s2,s4,3);
            g.ajouterArete(s2,s5,5);
            g.ajouterArete(s3,s6,2);
            g.ajouterArete(s4,s7,2);
            g.ajouterArete(s4,s8,9);
            g.ajouterArete(s5,s7,4);
            g.ajouterArete(s6,s8,6);
            g.ajouterArete(s7,s8,1);

            ArrayList<Arete> a = g.kruskal();
            System.out.println(a);
        }catch(IllegalArgumentException e){
            System.out.println(e.getMessage());
        }




    }
}