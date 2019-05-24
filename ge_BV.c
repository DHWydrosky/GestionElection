#include "proto_parti.h"

// recuperation des informations
void BV_info(Bvote* biwo){
int id,depart,tem;


    printf("\n Vous allez entrer les differentes informations a propos du bureau de votes");
    printf("\n Vous allez les entrer dans l'ordre suivant");
    printf("\n 1-Adresse du bureau de vote");
    printf("\n 2-L'indentifiant du president du bureau de vote");
    printf("\n 3-L'indentifiant du vice president du bureau de vote");
    printf("\n 4-L'indentifiant du secretaire du bureau de vote");

     color(10,0);
    printf("\n \t \t PRESSEZ UN BOUTON POUR CONTINUER");
     color(15,0);
    getch();


    // ICI POUR ENTRER L'ADRESSE
    printf("\n\t\t\t3-ADRESSE DU BUREAU DE VOTE--");
    depart=entrerAdresse(&biwo->Adresse);
    clr();

    //ICI POUR ENTRER L`IDENTIFIANT DU PRESIDENT

    do{
            printf("\n Entrer L'indentifiant du president du bureau de vote\n \t ->");


             do{
                                tem=1;
                          cin_pers(&biwo->Id_President);
                            tem=if_cin_exist(&biwo->Id_President);
                             if(tem==0){
                                        color(12,0);
                                    printf("\n \t VOTRE CIN DOIT ETRE DANS NOTRE SYSTEME ");
                                         color(10,0);
                                    printf("\n \t Entrer le CIN correspondant ici: ");
                                          color(15,0);
                             }
                          }while(tem!=1);

             if(unik_id_BV(&biwo->Id_President)==1){
                     color(12,0);
                  printf("\n \t VOUS NE POUVEZ ETRE UN PRESIDENT OU UN VICE-PRSIDENT OU UN SECRETAIRE DANS UN AUTRE BUREAU");
                     color(10,0);
                  printf("\n \t Entrer le CIN encore une fois: ");
                      color(15,0);
      }
    }while(unik_id_BV(&biwo->Id_President));


    //ICI POUR ENTRER L`IDENTIFIANT DU VICE PRESIDENT

    do{
            printf("\n Entrer L'indentifiant du vice-president du bureau de vote \n \t ->");

                           do{
                                tem=1;
                           cin_pers(&biwo->Id_VPresident);
                            tem=if_cin_exist(&biwo->Id_VPresident);
                             if(tem==0){
                                        color(12,0);
                                    printf("\n \t VOTRE CIN DOIT ETRE DANS NOTRE SYSTEME ");
                                         color(10,0);
                                    printf("\n \t Entrer le CIN correspondant ici: ");
                                          color(15,0);
                             }
                          }while(tem!=1);


             if(unik_id_BV(&biwo->Id_VPresident)==1){
                     color(12,0);
                  printf("\n \t VOUS NE POUVEZ ETRE UN PRESIDENT OU UN VICE-PRSIDENT OU UN SECRETAIRE DANS UN AUTRE BUREAU");
                     color(10,0);
                  printf("\n \t Entrer le CIN encore une fois: ");
                      color(15,0);
            }
    }while(unik_id_BV(&biwo->Id_VPresident));


    //ICI POUR ENTRER L`IDENTIFIANT DU SECRETAIRE



      do{
            printf("\n Entrer L'indentifiant du secretaire du bureau de vote \n \t ->");



            do{
                                tem=1;
                                    cin_pers(&biwo->Id_secret);
                            tem=if_cin_exist(&biwo->Id_secret);
                             if(tem==0){
                                        color(12,0);
                                    printf("\n \t VOTRE CIN DOIT ETRE DANS NOTRE SYSTEME ");
                                         color(10,0);
                                    printf("\n \t Entrer le CIN correspondant ici: ");
                                          color(15,0);
                             }
                          }while(tem!=1);


             if(unik_id_BV(&biwo->Id_secret)==1){
                     color(12,0);
                  printf("\n \t VOUS NE POUVEZ ETRE UN PRESIDENT OU UN VICE-PRSIDENT OU UN SECRETAIRE DANS UN AUTRE BUREAU");
                     color(10,0);
                  printf("\n \t Entrer le CIN encore une fois: ");
                      color(15,0);
      }
    }while(unik_id_BV(&biwo->Id_secret));

    biwo->Id_BV.departement = depart;

     id=rec_BV_ID(depart);
     id++;
      put_BV_ID(id,depart);

    biwo->Id_BV.propre=id;


}

// fonction permettant d'afficher les informations sur un bureau de vote
void affi_BV(struct Bvote* biwo){

   printf("1-Adresse                      : %d, %s, %s \n", biwo->Adresse.rue, biwo->Adresse.nomRue, biwo->Adresse.departement);
   printf("2-Identifiant president        : %s \n", biwo->Id_President);
   printf("3-Identifiant vice-president   : %s \n",biwo->Id_VPresident);
   printf("4-Identifiant secretaire       : %s \n", biwo->Id_secret);

    printf("\n \t \t \t \t ID         : %03d-%03d \n", biwo->Id_BV.departement, biwo->Id_BV.propre);
}
// fonction ajouter bureau de vote

void ajout_BV(){
   struct Bvote biwo;
   int yes=0;
   BV_info(&biwo);
   affi_BV(&biwo);
   modif_BV_before(&biwo);

     do{
       color(10,0);
       printf("Voulez vous faire cet enregistrement si OUI pressez 1 si NON pressez 0 -> ");
       color(15,0);
       yes= lireInt();
       }while(yes!=1 && yes!=0);


       if(yes==1){

       FILE* fichier= NULL;

           fichier =fopen("Bvote.dat","a");
               if(fichier==NULL){
                    printf("fichier not open");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }
             if(fichier!=NULL){
            fwrite(&biwo,sizeof(struct Bvote),1,fichier);
            printf("ok enr");

             }

            fclose(fichier);

       }

}

// CETTE FONCTION PERMET DE RECUPERER LE DERNIER IDENTIFIANT
int rec_BV_ID(int depart){
    int i=0;

      FILE* fichier= NULL;

           switch(depart){
                   case 1:
                        id_bv_rec("idBv/idbvouest.dat")
                        break;
                    case 2:
                          id_bv_rec("idBv/idbvnord.dat")
                        break;
                    case 3:

                        id_bv_rec("idBv/idbvnordest.dat")
                        break;
                    case 4:

                       id_bv_rec("idBv/idbvnordouest.dat")
                        break;
                    case 5:

                       id_bv_rec("idBv/idbvsud.dat")
                        break;
                    case 6:
                         id_bv_rec("idBv/idbvsudest.dat")
                        break;
                    case 7:
                       id_bv_rec("idBv/idbvbonite.dat")
                        break;
                    case 8:
                        id_bv_rec("idBv/idbvcentre.dat")
                        break;
                    case 9:
                        id_bv_rec("idBv/idbvnippes.dat")
                        break;
                    case 10:
                        id_bv_rec("idBv/idbvanse.dat")
                        break;
                 }

            return i;
}
// CETTE FONCTION PERMET DE METTRE LE DERNIER IDENTIFIANT DONNE A UN BUREAU DE VOTE
void put_BV_ID(int id ,int depart ){

       FILE* fichier= NULL;
                 switch(depart){
                   case 1:
                        id_bv("idBv/idbvouest.dat")
                        break;
                    case 2:
                          id_bv("idBv/idbvnord.dat")
                        break;
                    case 3:

                        id_bv("idBv/idbvnordest.dat")
                        break;
                    case 4:

                       id_bv("idBv/idbvnordouest.dat")
                        break;
                    case 5:

                       id_bv("idBv/idbvsud.dat")
                        break;
                    case 6:
                         id_bv("idBv/idbvsudest.dat")
                        break;
                    case 7:
                       id_bv("idBv/idbvbonite.dat")
                        break;
                    case 8:
                        id_bv("idBv/idbvcentre.dat")
                        break;
                    case 9:
                        id_bv("idBv/idbvnippes.dat")
                        break;
                    case 10:
                        id_bv("idBv/idbvanse.dat")
                        break;
                 }

            fclose(fichier);
}

 // ENTRER CIN
void cin_pers(char* cin){
     int i;
    char chaine[19]= {'\0'};
    struct elect electeur;
    char chaine2[]= "0123456789-";
    char *verificator = NULL;

    re_enter:

    printf("\nVous allez entrer le cin dans le format suivant 12-12-12-34-125678 \n \t-> ");
    if(lire(chaine,19))
    {
        printf("%d",strlen(chaine));
       if(strlen(chaine)!= 18){
            color(12,0);
                printf("\n \t VOTRE ENTREE N'A PAS ETE VALIDE ____ ENTRER ENCORE ");
                 printf("\n \t DOIT AVOIR 18 CARACTERES ");
                     color(10,0);
                printf("\n \t Entrer le cin correspondant ici: ");
                      color(15,0);
                goto re_enter;
       }
       i=0;
        while(i<19)
        {
            verificator = strchr(chaine2,chaine[i]);
            if(verificator == NULL)
            {
                     color(12,0);
                printf("\n \t VOTRE ENTREE N'A PAS ETE VALIDE ____ ENTRER ENCORE ");
                     color(10,0);
                printf("\n \t Entrer le cin correspondant ici: letrre ");
                      color(15,0);
                goto re_enter;
            }
            else
                i++;
        }

    if(chaine[2]!='-' || chaine[5]!='-' || chaine[8]!='-' || chaine[11]!='-'){
                     color(12,0);
                printf("\n \t VOTRE ENTREE N'A PAS ETE VALIDE ____ ENTRER ENCORE ");
                 printf("\n \t TIRET MAL PLACE 1 ");
                     color(10,0);
                printf("\n \t Entrer le cin correspondant ici: ");
                      color(15,0);
                goto re_enter;
    }
    if(chaine[0]=='-' || chaine[1]=='-' || chaine[3]=='-' || chaine[4]=='-' || chaine[6]=='-' || chaine[7]=='-' || chaine[9]=='-' || chaine[10]=='-' || chaine[12]=='-' || chaine[13]=='-' || chaine[14]=='-' ||chaine[15]=='-' ||chaine[16]=='-' ||chaine[17]=='-')
    {
            color(12,0);
                printf("\n \t VOTRE ENTREE N'A PAS ETE VALIDE ____ ENTRER ENCORE ");
                 printf("\n \t TIRET MAL PLACE");
                     color(10,0);
                printf("\n \t Entrer le CIN correspondant ici: ");
                      color(15,0);
                goto re_enter;
    }


        strcpy(cin, chaine);

    }
    else
    {
           color(10,0);
        printf("\n \t VOTRE ENTREE N'A PAS ETE VALIDE");
            color(15,0);
        goto re_enter;
    }

}

int unik_id_BV(char* cin){
    struct Bvote biwo;
    int i=0;
    FILE* fichier= NULL;

           fichier =fopen("Bvote.dat","r");
               if(fichier==NULL){
                    printf("fichier not open");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }

                rewind(fichier);

             while(!feof(fichier)){
                    fread(&biwo,sizeof(struct Bvote),1,fichier);

                    if(strcmp(biwo.Id_President,cin)==0 || strcmp(biwo.Id_secret,cin)==0 || strcmp(biwo.Id_VPresident,cin)==0)
                        i=1;

                 }
            fclose(fichier);

            return i;
}

void modif_BV_before(struct Bvote* biwo){

 int ok;
    int choix;
    clr(); // nettoyer le console
    affi_BV(biwo);// affichage des donnees precedemment entrees
     color(10,0);
    printf("\n voulez vous modifier les valeurs ci-dessus");

    printf("\n si oui presser 1 \n sinon presser 0:-> ");
     color(15,0);
    ok=lireInt();

    while(ok==1){
        clr();
        affi_BV(biwo);
        printf(" \n \t \t Entrer le # du champ que vous voulez modifier ->");
        do{
        choix=lireInt();
        }while(choix<=0 || choix>5);

        switch(choix)
        {
        case 1:
                printf("\nEntrer la nouvelle adresse");
                printf("\ncin->");
                entrerAdresse(&biwo->Adresse);
            break;
        case 2:
                printf("\nEntrer le nouveau identifiant du president");
                printf("\nNom du candidat: ");
                cin_pers(biwo->Id_President);
            break;
        case 3:
                printf("\nEntrer le nouveau identifiant du vice-president");
                printf("\n cin->");
                cin_pers(biwo->Id_VPresident);
            break;
        case 4:
                printf("\nEntrer le nouveau identifiant du secretaire");
                printf("\n cin->");
                cin_pers(biwo->Id_secret);
                break;
        }
        clr();
        affi_BV(biwo);
        color(10,0);
        printf(" \n \t \t Voulez vous faire une autre modification \n si oui presser 1 \n sinon presser 0 :-> ");
        color(15,0);
        ok=lireInt();
    }


}
void list_BV(){
    struct Bvote biwo;
    int i=1,nombre_ite=0;
    FILE* fichier= NULL;

           fichier =fopen("Bvote.dat","r");
               if(fichier==NULL){
                    printf("fichier not open");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }

            while(!feof(fichier)){
              fread(&biwo,sizeof(struct Bvote),1,fichier);
              nombre_ite++;
            }
             printf("%d",nombre_ite);
             printf("\n \n \t \tliste des bureaux de votes");

                rewind(fichier);

             while(!(i==nombre_ite)){
                    fread(&biwo,sizeof(struct Bvote),1,fichier);
                    color(10,0);
                    printf("\n%d-------------------------------------\n",i);
                    color(15,0);
                    affi_BV(&biwo);
                    i++;
             }



            fclose(fichier);
}

void list_BV_departement(int depart){
    struct Bvote biwo;
    int i=1,nombre_ite=0;
    FILE* fichier= NULL;

           fichier =fopen("Bvote.dat","r");
               if(fichier==NULL){
                    printf("fichier not open");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }

            while(!feof(fichier)){
              fread(&biwo,sizeof(struct Bvote),1,fichier);
              nombre_ite++;
            }
             printf("%d",nombre_ite);
             printf("\n \n \t \tliste des bureaux de votes");

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
                    fread(&biwo,sizeof(struct Bvote),1,fichier);

                    if(biwo.Id_BV.departement==depart){
                    color(10,0);
                    printf("\n-------------------------------------\n");
                    color(15,0);
                    affi_BV(&biwo);
                    }
                    i++;
             }



            fclose(fichier);
}

void modif_BV(){

    int id,nombre_ite=0 ,i=1,tem=0;
    struct  Bvote biwo;


   list_BV();// lister

   color(10,0);
   printf("entrer les 3 derniers chiffres de l'ID du bureau de vote que vous voulez modifier: ->");
   color(15,0);
   id = lireInt();


      FILE* fichier= NULL;
      FILE* tampon=NULL;
                //OUVERTURE DU FICHIER Bvotes.dat
           fichier =fopen("Bvote.dat","r");

             while(!feof(fichier)){
                   fread(&biwo,sizeof(struct Bvote),1,fichier);
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
                 fread(&biwo,sizeof(struct Bvote),1,fichier);
                 if(id == biwo.Id_BV.propre){
                         tem=1;
                         printf("trouver");
                         affi_BV(&biwo);
                         modif_BV_before(&biwo);
                         fwrite(&biwo,sizeof(struct Bvote),1,tampon);
                 }else{
                        fwrite(&biwo,sizeof(struct Bvote),1,tampon);
                 }
                 i++;
             }
            fclose(tampon);
            fclose(fichier);

            remove("Bvote.dat");
            rename("tampon.dat","Bvote.dat");

            if(tem==0)
            {
                clr();
                color(12,0);
               printf("\nL'IDENTIFIANT QUE VOUS ESSAYEZ D'ENTRER N'EXISTE PAS");
                color(15,0);
               modif_BV();
            }
}
void menu_BV(){
                int choix;

                  printf("\n \t \t \t MENU ");
                  printf("\n 1-Afficher l'ensemble des bureaux enregistres");
                  printf("\n 2-Ajouter un bureau de vote");
                  printf("\n 3-Modifier un bureau");
                  printf("\n 4-Arriere");

                  //do{
                         printf("\t \t \t --choix -> ");
                         choix = lireInt();
                  //}while(choix<0 || choix>5);

                 switch(choix)
                {
                    case 1:
                            list_BV();
                            menu_BV();
                         break;
                    case 2:
                            clr();
                            ajout_BV();
                            menu_BV();
                        break;
                    case 3:
                           modif_BV();
                           menu_BV();
                        break;
                    case 4:
                            menu();
                        break;
                }
}
