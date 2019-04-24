#include "proto_parti.h"

void cand_info(struct candidats* candidat){
     printf("\n Vous allez entrer les differentes informations a propos du candidat");
    printf("\n Vous allez les entrer dans l'ordre suivant");
    printf("\n 1-Nom du candidat ");
    printf("\n 2-Prenom du candidat");
    printf("\n 3-Date de naissance");
    printf("\n 4-Adresse");
    printf("\n 5-Emai");
    printf("\n 6-Telephone");
    printf("\n 7-Type");

        color(10,0);
    printf("\n \t \t PRESSEZ UN BOUTON POUR CONTINUER");
        color(15,0);
    getch();

    clr();

    // RECUPERATION DE LA DATE DU JOUR
    dateDuJour(&candidat->Date_ins);
    // DEMANDER A L'UTILISATEUR D'ENTRER LE NOM DU CANDIDAT
    printf("\n\t\t1-NOM DU CANDIDAT -> ");
    lire(candidat->Nom,tailleMot);
    clr();

    printf("\n\t\t2-PRENOM DU CANDIDAT -> ");
    lire(candidat->Prenom,tailleMot);
    clr();


    // DEMANDER A L'UTILISATEUR D'ENTRER LA DATE DE CREATION DE CE PARTI
    printf("\n\t\t\t3-DATE DE NAISSANCE-- -> ");
    entrerDate(&candidat->Dat_Nais, &candidat->Date_ins);
    clr();
    // ICI POUR ENTRER L'ADRESSE
    printf("\n\t\t\t4-ADRESSE DU CANDIDAT-- -> ");
    entrerAdresse(&candidat->Adresse);
    clr();
    // RECUPERATION DE L'EMAIL
    printf("\n \t \t \t5-EMAIL--");
    printf("\n \t Entrer l'email du candidat en question: ");
    entrerEmail(&candidat->Email);
    clr();
     // RECUPERATION DU # TELEPHONE
    printf("\n \t \t \t 6-TELEPHONE--");
    printf("\n \t Entrer le telephone du candidat en question: ");
    entrerNim(&candidat->tel);
    clr();




    do{
        printf("Etes vous independant si oui pressez 1 sinon pressez 0 -> ");
       candidat->type=lireInt();

       if(!(candidat->type==1 || candidat->type==0)){
            color(10,0);
         printf(" il faut 1 ou 0\n");
            color(15,0);
       }
    }while(!(candidat->type==1 || candidat->type==0));
    /* */
}
