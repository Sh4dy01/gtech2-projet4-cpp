# gtech2-proj4-cpp
*4th project of my 2nd year GTECH 2.*

## PROBLEM :  
> After a little analysis, we realized that there was no application for parents to record their babies' bottle feeds.

## SOFTWARE FEATURES: 
	- Possibility to add the hours of taking the baby's bottle
	- Ability to add the amount of milk ingested by the baby 
	- Create a variable interval reminder to give the baby a bottle
	- Take into account the possibility that the baby regurgitates his bottle
	- Create a shopping list for the baby

## APP STRUCTURE :
```cpp
class Bib {
    private:
        int max_bib;
        int actual_quantity;
        int max_feed;
        int min_feed;

        int reminder;  
        int take_time;
        boolean IsRegurgitated;
    public:
        Bib();
        Bib(int, )
        void Refill();
        void BottleReduction(int);
};

Bib() {
    take_time = 7; //hour
    IsRegurgitated = false;
    min_feed = 10; //cl
    max_feed = 15;
    max_bib = 100;
    actual_quantity = max_bib;
}

Bib(int, int, int, int) {
    //afficher(donner les éléments suivants : ...)
    //saisir(element_par_element)
}

class Product() {
    private:
        string product_list[];
        int product_quantity[];
        int left_product[];
        string shop_list[];
}

// Liste des courses pour le nourisson
// Liste de produit utilisés par les parents

/*
    procedure Prise_biberon(heure_de_prise, heure_de_rappel) {
        precontion : on doit avoir du lait ; bib disponible
        données : heure_de_prise, intervalle_de_prise
        donné -> résultat : heure_de_prise, heure_de_rappel
        variable locale : 
            possibilité de ne pas avoir de variables;
    }

    DEBUT
        SI (heure == heure_de_prise + intervalle_de_prise) ALORS
            afficher("C'est l'heure de donner le biberon")
        FIN SI

        SI oui_bib == 1 ALORS
            heure_de_prise += intervalle_de_prise;
            afficher("Dans cb de temps souhaiterez-vous le lui redonner ?")
            saisir(intervalle_de_prise)
        FIN SI
    FIN
*/
```

## SUMMARY
1. ** Bottle feeding **
    - Same quantity taken each time for the baby.
    - Check if the quantity_min is sufficient for the next feeding:
        -> if yes: recall for the next feeding
        -> if not: refill
2. ** Regurgitation **
    - Note the quantity regurgitated and the date
3. ** Reminder **
    - Next intake = time of intake + reminder
    - Notification
4. ** Add milk quantity **
    - If actual_quantity < quantity_min && If we are not after 20H
        -> refill
5. ** Shopping List **
    - Keep tracks of the remaining & necessary products
    - Indicates when to buy the products