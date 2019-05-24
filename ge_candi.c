#include "proto_parti.h"

void cand_info(struct candidats* candidat){

    int id,tem=0,type,prop,depart;
    struct parti part_temp;

    prop=rec_candi_ID();
    prop++;
    put_candi_ID(prop);

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
    entrerDate(&candidat->Dat_Nais, &candidat->Date_ins,18);
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
     color(10,0);
    printf("\n \tchoisir un departement");
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
    candidat->Id_candid.departement=depart;



    do{
        printf("Etes vous independant si oui pressez 1 sinon pressez 0 -> ");
       type=lireInt();

       if(!(type==1 || type==0)){
            color(10,0);
         printf(" il faut 1 ou 0\n");
            color(15,0);
       }
    }while(!(type==1 || type==0));

    if(type==1){

        color(10,0);
        printf("\n chwazi pati ou ladanl");
        color(15,0);
        list_PP(1);

        do{
        printf(" \n entrer ID an -> ");
        id=lireInt();

                struct parti lavalas;
                FILE* fichier= NULL;

                   fichier =fopen("part_pol.dat","r");

                    rewind(fichier);

                       if(fichier==NULL){
                            printf("le fichier ne peut pas s'ouvrir");
                            exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
                       }

                        while(!feof(fichier)){
                             fread(&part_temp,sizeof(struct parti),1,fichier);
                             if(id == part_temp.Id_PP){
                                 printf("identifiant trouve");
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

        }while(tem!=1);
          candidat->type=id;
          candidat->Id_candid.dependance=id;
    }
    else{
         candidat->Id_candid.dependance=0;
         candidat->type=0;
    }
     candidat->Id_candid.propre=prop;

    /* */
}


void affi_candi(struct candidats* candi){
   printf("\n1-Nom du candidat          : %s \n", candi->Nom);
   printf("2-Prenom du candidat         : %s \n", candi->Prenom);
   printf("3-La date de naissance est   : %d/%d/%d \n", candi->Dat_Nais.jour, candi->Dat_Nais.mois, candi->Dat_Nais.annee);
   printf("4-Adresse                    : %d, %s, %s \n", candi->Adresse.rue, candi->Adresse.nomRue, candi->Adresse.departement);
   printf("5-Telephone                  : +509 %d \n",candi->tel);
   printf("6-Email                      : %s \n", candi->Email);
   printf("7-type                       : %d \n", candi->type);


    printf("\n \t \t \t \t Inscrit le : %d/%d/%d \n", candi->Date_ins.jour, candi->Date_ins.mois, candi->Date_ins.annee);
    printf("\t \t \t \t ID         : %03d-%03d-%03d \n", candi->Id_candid.dependance, candi->Id_candid.departement, candi->Id_candid.propre);

}

void modi_candi_Before(struct candidats* candis){
    int ok;
    int choix;
    clr(); // nettoyer le console
    affi_candi(candis);// affichage des donnees precedemment entrees
     color(10,0);
    printf("\n voulez vous modifier les valeurs ci-dessus");

    printf("\n si oui presser 1 \n sinon presser 0:-> ");
     color(15,0);
    ok=lireInt();

    while(ok==1){
        clr();
        affi_candi(candis);
        printf(" \n \t \t Entrer le # du champ que vous voulez modifier ->");
        choix=lireInt();

        switch(choix)
        {
        case 1:
                printf("\nEntrer le nouveau nom");
                printf("\nNom du candidat: ");
                lire(&candis->Nom,tailleMot);
            break;
        case 2:
                printf("\nEntrer le nouveau Prenom");
                printf("\nNom du candidat: ");
                lire(&candis->Prenom,tailleMot);
            break;
        case 3:
                printf("\nEntrer la nouvelle date de naissance");
                printf("\n Date creation ");
                entrerDate(&candis->Dat_Nais,&candis->Date_ins,0);
            break;
        case 4:
                printf("\nEntrer la nouvelle adresse");
                printf("\n adresse");
                entrerAdresse(&candis->Adresse);
            break;
        case 5:
                printf("\nEntrer le nouveau numero");
                entrerNim(&candis->tel);
            break;
        case 6:
                printf("\nEntrer le nouveau email");
                entrerEmail(&candis->Email);
            break;
         case 7:
                printf("\n Modification du type");
                printf("\n type");
                entrerResp(&candis->type);
            break;
        }
        clr();
        affi_candi(candis);
        color(10,0);
        printf(" \n \t \t Voulez vous faire une autre modification \n si oui presser 1 \n sinon presser 0 :-> ");
        color(15,0);
        ok=lireInt();
    }

}


void ins_cand(){
         int yes=0,prop=0;
         struct candidats lavalas;


        cand_info(&lavalas);
        affi_candi(&lavalas);
        modi_candi_Before(&lavalas);

        //ecriture en fichier

       // struct parti* PP = (struct parti*)malloc(sizeof(struct parti));

       do{
       color(10,0);
       printf("Voulez vous faire cet enregistrement si OUI pressez 1 si NON pressez 0 -> ");
       color(15,0);
       yes= lireInt();
       }while(yes!=1 && yes!=0);


       if(yes==1){

       FILE* fichier= NULL;

           fichier =fopen("candid.dat","a");
               if(fichier==NULL){
                    printf("fichier not open");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }
             if(fichier!=NULL){
            fwrite(&lavalas,sizeof(struct candidats),1,fichier);
            printf("ok enr");

             }

            fclose(fichier);

       }

}

void list_candid(int mode){
      int i=1;
      int nombre_ite=0;



     struct candidats candidat;
      FILE* fichier= NULL;

           fichier =fopen("candid.dat","r");
               if(fichier==NULL){
                    printf("le fichier ne peut pas s'ouvrir");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }
            //rewind(fichier);
            while(!feof(fichier)){
              fread(&candidat,sizeof(struct candidats),1,fichier);
              nombre_ite++;
            }
             printf("%d",nombre_ite);
             printf("\n \n \t \tliste des candidats");
                 // fread(&candidat,sizeof(struct parti),1,fichier);



            rewind(fichier);
            while(!(i==nombre_ite)){

                 fread(&candidat,sizeof(struct candidats),1,fichier);
                 color(10,0);
                 printf("\n %d-------------------------------------------", i);
                 color(15,0);
                 i++;
                 if(mode==0)
                 affi_candi(&candidat);
                 else{
                     printf("\n1-Nom du candidat      : %s %s\n", candidat.Nom, candidat.Prenom);
                     printf("\t  Inscrit le : %d/%d/%d \n", candidat.Date_ins.jour, candidat.Date_ins.mois, candidat.Date_ins.annee);
                     printf("\t  ID         : %03d-%03d-%03d \n", candidat.Id_candid.dependance,candidat.Id_candid.departement, candidat.Id_candid.propre);
                 }
            }

            fclose(fichier);

}

void list_candid_depar(int mode,int depart){
      int i=1;
      int nombre_ite=0;



     struct candidats candidat;
      FILE* fichier= NULL;

           fichier =fopen("candid.dat","r");
               if(fichier==NULL){
                    printf("le fichier ne peut pas s'ouvrir");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }
            //rewind(fichier);
            while(!feof(fichier)){
              fread(&candidat,sizeof(struct candidats),1,fichier);
              nombre_ite++;
            }
             printf("%d",nombre_ite);
             printf("\n \n \t \tliste des candidats ");
                 // fread(&candidat,sizeof(struct parti),1,fichier);

                 switch(depart){
                   case 1:
                        printf("de l'OUEST");
                        break;
                    case 2:
                        printf("du NORD");
                        break;
                    case 3:
                        printf("pour le NORD-EST");
                        break;
                    case 4:
                        printf("pour le NORD-OUEST");
                        break;
                    case 5:
                        printf("du SUD");
                        break;
                    case 6:
                        printf("de SUD-EST");
                        break;
                    case 7:
                        printf("de l'ARTIBONITE");
                        break;
                    case 8:
                        printf("du CENTRE");
                        break;
                    case 9:
                        printf("pour NIPPES");
                        break;
                    case 10:
                        printf("pour GRAND'ANSE");
                        break;
                 }



            rewind(fichier);
            while(!(i==nombre_ite)){

                 fread(&candidat,sizeof(struct candidats),1,fichier);
                 i++;

                 if(candidat.Id_candid.departement==depart){
                     color(10,0);
                     printf("\n -------------------------------------------");
                     color(15,0);

                     if(mode==0)
                     affi_candi(&candidat);
                     else{
                         printf("\n1-Nom du candidat      : %s %s\n", candidat.Nom, candidat.Prenom);
                         printf("\t  Inscrit le : %d/%d/%d \n", candidat.Date_ins.jour, candidat.Date_ins.mois, candidat.Date_ins.annee);
                         printf("\t  ID         : %03d-%03d-%03d \n", candidat.Id_candid.dependance,candidat.Id_candid.departement, candidat.Id_candid.propre);
                     }
                 }
            }

            fclose(fichier);

}
void modif_cand(){
   int id,nombre_ite=0 ,i=1,tem=0;
   struct candidats candidat;


   list_candid(1);// lister

   color(10,0);
   printf("entrer les 3 dernier chiffres de l'ID du candidat que vous voulez modifier: ->");
   color(15,0);
   id = lireInt();


      FILE* fichier= NULL;
      FILE* tampon=NULL;
                //OUVERTURE DU FICHIER part_pol.dat
           fichier =fopen("candid.dat","r");

             while(!feof(fichier)){
                   fread(&candidat,sizeof(struct candidats),1,fichier);
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
                 fread(&candidat,sizeof(struct candidats),1,fichier);
                 if(id == candidat.Id_candid.propre){
                         tem=1;
                         printf("trouver");
                         affi_candi(&candidat);
                         modi_candi_Before(&candidat);
                         fwrite(&candidat,sizeof(struct candidats),1,tampon);
                 }else{
                        fwrite(&candidat,sizeof(struct candidats),1,tampon);
                 }
                 i++;
             }
            fclose(tampon);
            fclose(fichier);

            remove("candid.dat");
            rename("tampon.dat","candid.dat");

            if(tem==0)
            {
                clr();
                color(12,0);
               printf("\nL'IDENTIFIANT QUE VOUS ESSAYEZ D'ENTRER N'EXISTE PAS");
                color(15,0);
               modif_cand();
            }
}
void menu_Candi(){
                int choix;

                  printf("\n \t \t \t FONCTIONNALITES RELATIVES AUX CANDIDATS ");
                  printf("\n 1-Afficher l'ensemble des candidats enregistrer");
                  printf("\n 2-Inscrire un candidats");
                  printf("\n 3-Modifier un candidats");
                  printf("\n 4-Arriere");

                  //do{
                         printf("\t \t \t --choix -> ");
                         choix = lireInt();
                  //}while(choix<0 || choix>5);

                 switch(choix)
                {
                    case 1:
                            list_candid(0);
                            menu_Candi();
                         break;
                    case 2:
                            clr();
                            ins_cand();
                            menu_Candi();
                        break;
                    case 3:
                           modif_cand();
                           menu_Candi();
                        break;
                    case 4:
                            menu();
                        break;
                }
}

