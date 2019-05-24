#include "proto_parti.h"

void menu_vote(){
    make_vote();
}

void make_vote(){
    struct votes vote;
    int depart;
    // recuperation de la date du vote
    dateDuJour(&vote.Date_vote);

    // DEPARTEMENT
    color(10,0);
    printf("\n Vous etes dans quel departement ->");
    printf("\n1-OUEST \n2-NORD \n3-NORD-EST \n4-NORD-OUEST \n5-SUD \n6-SUD-EST \n7-ARTIBONITE \n8-CENTRE \n9-NIPPES \n10-GRAND'ANSE \n \t ->");
    color(15,0);

    do{
      depart = lireInt();

      if(depart<=0 || depart>10){
        color(12,0);
        printf("\n \tERREUR: VOUS DEVEZ CHOISIR UN CHIFFRE ENTRE 1 ET 10");
        color(10,0);
        printf("\n \tEntrer encore une fois->");
        color(15,0);
      }

    }while(depart<=0 || depart>10);
    ///////////////////////////////////////////////////////

    //entrer le bureau de vote
    // wap met fonksyon kap lister biwo vot yo
    // recuperer id biwo an

    // elekte an ap entre cin li an
    // verifier sil nan list moun ki nan biwo sa

    // choisir les candidat
    list_candid_depar(1,depart);

}

void choisir_candid(struct id_can* id){


}
