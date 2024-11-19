public class Arete implements Comparable{
    private Sommet sommet1;
    private Sommet sommet2;
    private int poids;

    public Arete(Sommet s1, Sommet s2, int poids){
        this.sommet1= s1;
        this.sommet2 = s2;
        this.poids = poids;
    }

    public Sommet getSommet1(){
        return this.sommet1;
    }

    public Sommet getSommet2() {
        return this.sommet2;
    }

    public int getPoids() {
        return this.poids;
    }

    @Override
    public int compareTo(Object o) {
        //permet d'utiliser la méthode statique sort() de la classe Collections
        Arete a = (Arete)o;
        int verif = 0;
        if(this.poids > a.getPoids()){
            verif = 1;
        } else if (this.poids < a.getPoids()) {
            verif = -1;
        }
        else {
            verif = 0;
        }
        return verif;
    }

    public String toString(){
        return "sommet1 : "+this.sommet1.getID()+" sommet2 : "+this.sommet2.getID()+" poids : "+this.poids+" | ";
    }
}
