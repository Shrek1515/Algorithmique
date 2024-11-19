public class Sommet {
    private static int prochain_ID;
    private int valeur;
    private int ID;
    private int composanteConnexe;

    public Sommet(int valeur){
        this.valeur = valeur;
        this.ID = prochain_ID+=1;
        this.composanteConnexe = 0;
    }

    public int getValeur() {
        return this.valeur;
    }

    public int getID() {
        return this.ID;
    }

    public int getComposanteConnexe() {
        return this.composanteConnexe;
    }

    public void setComposanteConnexe(int composanteConnexe) {
        this.composanteConnexe = composanteConnexe;
    }
}
