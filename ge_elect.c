#include "proto_parti.h"

void elect_info(struct elect* electeur){
int id,depart,tem;


    printf("\n Vous allez entrer les differentes informations a propos d'un electeur");
    printf("\n Vous allez les entrer dans l'ordre suivant");
    printf("\n 1-le cin de l'electeur");
    printf("\n 2-Le nom de l'electeur");
    printf("\n 3-Le prenom de l'electeur");
    printf("\n 4-L'adresse de lelecteur");

     color(10,0);
    printf("\n \t \t PRESSEZ UN BOUTON POUR CONTINUER");
     color(15,0);
    getch();

    clr();

    // ICI POUR ENTRER L'ADRESSE

                          do{
                                tem=0;
                             cin_pers(electeur->CIN);
                            tem=if_cin_exist(electeur->CIN);
                             if(tem==1){
                                        color(12,0);
                                    printf("\n \t DEUX PERSONNES NE PEUVENT AVOIR LE MEME CIN ");
                                         color(10,0);
                                    printf("\n \t Entrer le CIN correspondant ici: ");
                                          color(15,0);
                             }
                          }while(tem!=0);



    clr();

    printf("\n\t\t--2-NOM DE L'ELECTEUR -> ");
    lire(electeur->Nom,tailleMot);
    clr();

    printf("\n\t\t--PRENOM DE L'ELECTEUR -> ");
    lire(electeur->Prenom,tailleMot);
    clr();

    printf("\n\t\t\t3-ADRESSE DE L'ELECTEUR--");
    depart=entrerAdresse(&electeur->adresse);
    clr();





        color(10,0);
        printf("\n chwazi biwo ou vle an");
        color(15,0);
        electeur->BV.propre=lireInt();
        //list_BV_departement(depart);

        electeur->BV.departement=depart;


           /*
        do{
                color(10,0);
        printf("\n entrer les 3 derniers chiffres id biwo vot ou vle entre->");
        printf(" \n entrer ID an -> ");
             color(15,0);
        id=lireInt();

                struct Bvote biwo;
                FILE* fichier= NULL;

                   fichier =fopen("Bvote.dat","r");

                    rewind(fichier);

                       if(fichier==NULL){
                            printf("le fichier ne peut pas s'ouvrir");
                            exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
                       }

                        while(!feof(fichier)){
                             fread(&biwo,sizeof(struct Bvote),1,fichier);
                             if(id == biwo.Id_BV.propre){
                                 printf("\nidentifiant trouve\n");
                                 electeur->BV=biwo.Id_BV;
                                 tem=1;
                                 break;
                             }
                       }

                  fclose(fichier);

                  if(tem==0){
                        color(12,0);
                    printf("\nCET IDENTIFIANT NE TROUVE PAS DANS LE FICHIER \n ENTRER ENCORE ");
                        color(15,0);
                  }

        }while(tem!=1);*/

}

void affi_electeur(struct elect* electeur){
   printf("\n1-CIN                   : %s \n", electeur->CIN);
   printf("2-NOM                   : %s \n", electeur->Nom);
   printf("3-PRENOM                : %s \n",electeur->Prenom);
   printf("4-ID BUREAU DE VOTE     : %03d-%03d\n", electeur->BV.departement,electeur->BV.propre);

}
void modif_elect_before(struct elect* electeur){
    int ok;
    int choix,tem;
    clr(); // nettoyer le console
    affi_electeur(electeur);// affichage des donnees precedemment entrees
     color(10,0);
    printf("\n voulez vous modifier les valeurs ci-dessus");

    printf("\n si oui presser 1 \n sinon presser 0:-> ");
     color(15,0);
    ok=lireInt();

    while(ok==1){
        clr();
        affi_electeur(electeur);
        printf(" \n \t \t Entrer le # du champ que vous voulez modifier ->");
        choix=lireInt();

        switch(choix)
        {
        case 1:
                printf("\nEntrer le nouveau cin");
                printf("\nCIN: ");

                 do{
                                tem=0;
                             cin_pers(electeur->CIN);
                            tem=if_cin_exist(electeur->CIN);
                             if(tem==1){
                                        color(12,0);
                                    printf("\n \t DEUX PERSONNES NE PEUVENT AVOIR LE MEME CIN ");
                                         color(10,0);
                                    printf("\n \t Entrer le CIN correspondant ici: ");
                                          color(15,0);
                             }
                }while(tem!=0);
            break;
        case 2:
                printf("\nEntrer le nouveau nom");
                printf("\nNom de l'electeur ");
                lire(&electeur->Nom,tailleMot);
            break;
        case 3:
                printf("\nEntrer le nouveau prenom");
                printf("\nPrenom ");
                lire(&electeur->Prenom, tailleMot);
            break;
        default:
            modif_elect_before(electeur);
            break;
        }
        clr();
        affi_electeur(electeur);
        color(10,0);
        printf(" \n \t \t Voulez vous faire une autre modification \n si oui presser 1 \n sinon presser 0 :-> ");
        color(15,0);
        ok=lireInt();
    }

}
void ins_elect(){
       struct elect electeur;
       int yes;

       elect_info(&electeur);
       modif_elect_before(&electeur);
       affi_electeur(&electeur);


        do{
       color(10,0);
       printf("Voulez vous faire cet enregistrement si OUI pressez 1 si NON pressez 0 -> ");
       color(15,0);
       yes= lireInt();
       }while(yes!=1 && yes!=0);


       if(yes==1){

       FILE* fichier= NULL;

           fichier =fopen("elect.dat","a");
               if(fichier==NULL){
                    printf("fichier not open");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }
             if(fichier!=NULL){
            fwrite(&electeur,sizeof(struct elect),1,fichier);
            printf("ok enr");

             }

            fclose(fichier);

       }


}
void list_electeur(){
 struct elect electeur;
 char departement[25]="";
  int i=1,depart, nombre_ite=0;

       printf("\n \tchoisir un departement");
       printf("\n1-OUEST \n2-NORD \n3-NORD-EST \n4-NORD-OUEST \n5-SUD \n6-SUD-EST \n7-ARTIBONITE \n8-CENTRE \n9-NIPPES \n10-GRAND'ANSE \n \t ->");

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

      FILE* fichier= NULL;

           fichier =fopen("elect.dat","r");
               if(fichier==NULL){
                    printf("le fichier ne peut pas s'ouvrir");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }
            //rewind(fichier);
            while(!feof(fichier)){
              fread(&electeur,sizeof(struct elect),1,fichier);
              nombre_ite++;
            }
             printf("%d",nombre_ite);
             printf("\n \n \t \tliste des electeurs ");
                 // fread(&candidat,sizeof(struct parti),1,fichier);

                 switch(depart){
                   case 1:
                        printf("de l'OUEST");
                        strcpy(departement,"OUEST");
                        break;
                    case 2:
                        printf("du NORD");
                        strcpy(departement,"NORD");
                        break;
                    case 3:
                        printf("pour le NORD-EST");
                        strcpy(departement,"NORD-EST");
                        break;
                    case 4:
                        printf("pour le NORD-OUEST");
                        strcpy(departement,"NORD-OUEST");
                        break;
                    case 5:
                        printf("du SUD");
                        strcpy(departement,"SUD");
                        break;
                    case 6:
                        printf("de SUD-EST");
                        strcpy(departement,"SUD-EST");
                        break;
                    case 7:
                        printf("de l'ARTIBONITE");
                        strcpy(departement,"ARTIBONITE");
                        break;
                    case 8:
                        printf("du CENTRE");
                        strcpy(departement,"CENTRE");
                        break;
                    case 9:
                        printf("pour NIPPES");
                        strcpy(departement,"NIPPES");
                        break;
                    case 10:
                        printf("pour GRAND'ANSE");
                        strcpy(departement,"GRAND'ANSE");
                        break;
                 }



            rewind(fichier);
            while(!(i==nombre_ite)){

                 fread(&electeur,sizeof(struct elect),1,fichier);
                 i++;

                 if (strcmp(electeur.adresse.departement,departement)==0){
                     color(10,0);
                     printf("\n -------------------------------------------\n");
                     color(15,0);
                     affi_electeur(&electeur);

                 }
            }

            fclose(fichier);



}

void modif_elect(){
 int id,nombre_ite=0 ,i=1,tem=0;
 char cin[19]="";
   struct elect electeur;


   list_electeur();// lister

   color(10,0);
   printf("entrer le cin de l'electeur que vous voulez modifier: ->");
   color(15,0);
   cin_pers(cin);


      FILE* fichier= NULL;
      FILE* tampon=NULL;
                //OUVERTURE DU FICHIER part_pol.dat
           fichier =fopen("elect.dat","r");

             while(!feof(fichier)){
                   fread(&electeur,sizeof(struct elect),1,fichier);
                   nombre_ite++;
                  }

               if(fichier==NULL){
                    printf("le fichier candid.dat ne peut pas s'ouvrir");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }
            tampon= fopen("tampon.dat","w");
                        if(tampon==NULL){//while
                            printf("le fichier tampon ne peut pas s'ouvrir");
                            exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
                         }
            rewind(fichier);
            rewind(tampon);
                 // VERIFIER SI id ENTRER PAR LA PERSONNE CORRESPOND A L'UN DE CEUX CONTENUES DANS LE FICHIER
            while(!(i==nombre_ite)){
                 fread(&electeur,sizeof(struct elect),1,fichier);
                 if(strcmp(cin,electeur.CIN)==0){
                         tem=1;
                         printf("trouver");
                         affi_electeur(&electeur);
                         modif_elect_before(&electeur);
                         fwrite(&electeur,sizeof(struct elect),1,tampon);
                 }else{
                        fwrite(&electeur,sizeof(struct elect),1,tampon);
                 }
                 i++;
             }
            fclose(tampon);
            fclose(fichier);

            remove("elect.dat");
            rename("tampon.dat","elect.dat");

            if(tem==0)
            {
                clr();
                color(12,0);
               printf("\nL'IDENTIFIANT QUE VOUS ESSAYEZ D'ENTRER N'EXISTE PAS");
                color(15,0);
               modif_cand();
            }


}
void menu_elect(){
                int choix;

                  printf("\n \t \t \t FONCTIONNALITES RELATIVES AUX ELECTEURS ");
                  printf("\n 1-Afficher l'ensemble des electeurs enregistrer par departement");
                  printf("\n 2-Inscrire un electeur");
                  printf("\n 3-Modifier un electeur");
                  printf("\n 4-Arriere");

                  //do{
                         printf("\t \t \t --choix -> ");
                         choix = lireInt();
                  //}while(choix<0 || choix>5);

                 switch(choix)
                {
                    case 1:
                            list_electeur();
                            menu_elect();
                         break;
                    case 2:
                            clr();
                            ins_elect();
                            menu_elect();
                        break;
                    case 3:
                           modif_elect();
                           menu_elect();
                        break;
                    case 4:
                            menu();
                        break;
                }
}
