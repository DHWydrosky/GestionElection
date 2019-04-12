#include "proto_parti.h"


//fonction pour entrer l`ADRESSE
/*int lire(char* chaine,int taille){
     char *pos=NULL;
     int itsok=0;
     char vide[]="";

     while(itsok==0){
         if(fgets(chaine,taille,stdin)!=NULL)
         {

            pos= strchr(chaine,'\n');
            if(pos!=NULL)
            {
                *pos='\0';
            }
         }

         if(strcmp(chaine,vide)!=0){
            printf("making");
            itsok=1;
         }
     }
    return 1;
}*/


void viderBuffer()   // comme son nom l'indique
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int lire(char *chaine,int longeuer_chaine)
{

    char *position_cursor = NULL,*chaine_verificator = NULL;
    char chaine2[30]= {'\0'};
    int i,j=0,temoin = 0;





    if(fgets(chaine,longeuer_chaine,stdin) != NULL)
    {


        position_cursor = strchr(chaine,'\n');
        if(position_cursor != NULL)
        {
            *position_cursor = '\0';
        }
        else
        {
            viderBuffer();
        }



        for(i=strlen(chaine); i>=0; i--)
        {
            if(chaine[i-1] == ' ')
            {
                chaine[i-1] = '\0';
            }
            else
                break;
        }

        i=0;
        while(chaine[i]==' ')
            i++;

        for(i=i; i<strlen(chaine); i++)
        {
            if((chaine[i]==' ') && (temoin == 0))
            {
                chaine2[j] = ' ';
                temoin = 1;
                j++;
            }
            if(chaine[i]!= ' ')
            {
                chaine2[j] = chaine[i];
                j++;
                temoin = 0;
            }
        }


        for(i=0; i<strlen(chaine); i++)
        {
            chaine[i] = '\0';
        }
        strcpy(chaine,chaine2);



for(i=0; i<longeuer_chaine; i++)
        {
            chaine[i] = toupper(chaine[i]);
        }





        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }

}

// CETTE FONCTION PERMET D'ENTRER DES VALEURS NUMERIQUES SOUS FORMES DE CARACTERES ET DE RETOUNER LA CONVERSION EN INT
/*
int lireInt(){ // bay yon ti modification sou fonction verifier si chak grenn karakte yo se chif
 char *pos=NULL;
 char chaine[caracMini];
 char entier[]= "01234567";
 int i;
     if(fgets(chaine,caracMini,stdin)!=NULL)
     {
        pos= strchr(chaine,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        printf("%d",atoi(chaine));
        return atoi(chaine);
     }
     else {return -1;}
}*/

int lireInt()
{
    int i= 0;
    char chaine[caracMini]= {'\0'};
    char chaine2[]= "0123456789";
    char *verificator = NULL;

    re_enter:

    if(lire(chaine,caracMini))
    {
        while(i<caracMini)
        {
            verificator = strchr(chaine2,chaine[i]) ;
            if(verificator == NULL){
                     color(12,0);
                printf("\n \t VOTRE ENTREE N'A PAS ETE VALIDE ____ ENTRER ENCORE ");
                     color(10,0);
                printf("\n \t Entrer le nombre correspondant ici: ");
                      color(15,0);
                goto re_enter;
            }
            else
                i++;
        }



        return strtol(chaine,NULL,caracMini);

    }
    else
    {
           color(10,0);
        printf("\n \t VOTRE ENTREE N'A PAS ETE VALIDE");
            color(15,0);
        goto re_enter;
    }

}
// CETTE FONCTION NOUS PERMET DE RECUPERER LES ADRESSES
void entrerAdresse(struct Adres *adresse){

   printf("\nvous allez l'adresse a linstant  format #rue, Nom de rue , Departement\n");

   printf(" \t #rue: ");
   adresse->rue=lireInt();//fok ou met yon ti verifikasyon la

   printf("\n \t nom de rue: ");
   lire(adresse->nomRue, tailleMot);

   printf("\n \t enter le departement: ");
  // do{

   lire(adresse->departement,caracMini);
  // }
   //while((adresse->departement=="OUEST" || adresse->departement=="SUD" || adresse->departement=="GRAND'ANSE" || adresse->departement=="CENTRE" || adresse->departement=="NORD" || adresse->departement=="NORD-EST" || adresse->departement=="NORD-OUEST"));
    printf("\nvous habitez a #%d,Rue %s, %s \n", adresse->rue, adresse->nomRue, adresse->departement);
}

//FONTION NOUS PERMETTANT D'ENTRER LES DATES
void entrerDate(struct dat *sdate, struct dat *actuel){
    printf("\nVous aller entrer la date dans le format AAAA/MM/JJ exemple 1996/08/10 \n");

        do{
            printf("\n \t Annee: ");
            sdate->annee = lireInt();
            if(sdate->annee > actuel->annee){
                color(12,0);
                printf("\n \t ERREUR: L'ANNEE DE CREATION NE PEUT ETRE SUPERIEUR A %d", actuel->annee);
                color(10,0);
                printf("\n \t \t Entrer l'annee encore une fois");
                color(15,0);
            }
         }while(sdate->annee<=1804 || sdate->annee > actuel->annee);

        do{

            printf("\n \t Mois: ");
            sdate->mois = lireInt();
            if(sdate->mois>12){
            color(12,0);
            printf("\n \t ERREUR: IL Y A 12 MOIS DANS UNE ANNEE");
            color(10,0);
            printf("\n \t \t Entrer le mois encore une fois");
            color(15,0);
           }
        }while(sdate->mois<=0 || sdate->mois>12);

         sinonjour://ETIQUETTE
           printf(" \n\t Jour: ");
           sdate->jour = lireInt();

        if (sdate->jour<=0){
                color(12,0);
            printf("\n \t \t ERREUR: ON NE PREND PAS DE VALEUR NEGATIF");
                color(10,0);
            printf("\n \t \t Entrer le jour encore une fois");
                color(15,0);
            goto sinonjour;
        }
        if (sdate->jour>31){
                color(12,0);
            printf("\n \t \t ERREUR: AUCUN MOIS NE CONTIENT PLUS DE 31 JOURS");
                color(10,0);
            printf("\n \t \t Entrer le jour encore une fois");
                color(15,0);
            goto sinonjour;
        }
        if (sdate->mois%2==0 && sdate->jour>30 && sdate->mois<8){
                color(12,0);
            printf("\n \t \t ERREUR: CE MOIS NE CONTIENT PAS PLUS DE 30 JOURS");
                color(10,0);
            printf("\n \t \t Entrer le jour encore une fois");
                color(15,0);
            goto sinonjour;
        }
        if (sdate->mois%2==1 && sdate->jour>30 && sdate->mois>8){
                 color(12,0);
            printf("\n \t \t ERREUR: CE MOIS NE CONTIENT PAS PLUS DE 30 JOURS");
                 color(10,0);
            printf("\n \t \t Entrer le jour encore une fois");
                 color(15,0);
            goto sinonjour;
        }
        if(sdate->mois==2 && sdate->jour >29 && bisex(sdate->annee)==1){
                 color(12,0);
            printf("\n \t \t ERREUR: CE MOIS NE CONTIENT PAS PLUS DE 28 JOURS");\
                  color(10,0);
            printf("\n \t \t Entrer le jour encore une fois");
                   color(15,0);
            goto sinonjour;
        }
        if(sdate->mois==2 && sdate->jour>28 && bisex(sdate->annee)==0){
                 color(12,0);
            printf("\n \t \t ERREUR: CE MOIS NE CONTIENT PAS PLUS DE 29 JOURS");
                  color(10,0);
            printf("\n \t \t Entrer le jour encore une fois");
                   color(15,0);
            goto sinonjour;
        }

      if(sdate->annee == actuel->annee && sdate->mois == actuel->mois && sdate->jour == sdate->jour ){
             color(12,0);
        printf("ERREUR: LA DATE DE CREATION NE PEUT SE CONFONDRE AVEC LA DATE D'INSCRIPTION");
             color(15,0);
             entrerDate(sdate,actuel);
      }

            color(4,0);
    printf("\n \t La date de creation est %02d/%02d/%d \n ", sdate->jour, sdate->mois, sdate->annee);
            color(15,0);
}

// RECUPERER ET AFFICHER LA DATE DU JOUR
void dateDuJour(struct dat *sdate){

    SYSTEMTIME today;
    GetLocalTime(&today);

    sdate->jour=today.wDay;
    sdate->mois=today.wMonth;
    sdate->annee=today.wYear;

   // printf("\n \t Inscription faite le: %02d/%02d/%02d: \n", sdate->jour, sdate->mois, sdate->annee);
}

void entrerResp(struct Responsables *resp){

    printf("\n \t Nom du responsable: ");
    lire(resp->nom,2*caracMini);

    printf("\n \t Prenom du responsable: ");
    lire(resp->prenom,2*caracMini);

    printf("\tle responsable est %s, %s \n", resp->prenom ,resp->nom);
}

// CETTE FONCTION PERMET DE RECUPERER L'EMAIL ET DE VERIFIER SI L'EMAIL EST VALIDE
void entrerEmail(char *email){
    int i;
        sinonemail:// ETIQUETTE

    printf("\n \t \t \t email: ");
    lire(email,tailleMot);// RECUPERER L'EMAIL

    char *voir = NULL;

    voir = strpbrk(email, "!$&*-^\=`#%'+/?_{}"); // VOIR SI DANS L'EMAIL RECUPERE S'IL N'Y A PAS LES CARACTERES SUIVANTS "!$&*-^\=`#%'+/?_{}"

    if(voir!= NULL){
             color(12,0);
        printf("\n \t \t ERREUR: VOTRE EMAIL NE PEUT CONTENIR LES CARACTERES SUIVANTS");
        printf("\n \t \t !$&*-^\=`#%'+/?_{}");
             color(10,0);
        printf("\n Entrer l'email encore une fois");
             color(15,0);
        goto sinonemail;
    } // SI EMAIL RECUPERE CONTIENT LES CARACTERES REPRESENTES CI-DESSUS ON REDEMANDE A L'UTILISATEUR L'EMAIL
     voir=NULL;
     voir = strpbrk(email, "@"); // RECUPERER L'ADRESSE DU CARACTERE @

     if(voir==NULL){
             color(12,0);
        printf("\n \t \t ERREUR: VOUS N'AVEZ PAS INSERER DE NOM D'EXTENSION");
              color(10,0);
        printf("\n \t Entrer l'email encore une fois");
                color(15,0);
        goto sinonemail;
     }// VOIR S'IL Y A UN EXTENSION

      // VERIFIER SI IL Y A PLUS DE 6 CARACTERE AVANT L'EXTENSION
     i=0;
     while(email[i]!='@' && i<49){
        i++;
     }
     if(i<6){
             color(12,0);
        printf("\n \t \t ERREUR: VOUS DEVEZ AVOIR PLUS DE 6 CARACTERES AVANT L'EXTENSION");
              color(10,0);
        printf("\n Entrer l'email encore une fois");
              color(15,0);
        goto sinonemail;
     }
     //VERIFIER SI IL Y A PLUS DE 6 CARACTERE APRES @
     if(strlen(voir)<6){
             color(12,0);
        printf("\n \t \t ERREUR: VOUS DEVEZ AVOIR PLUS DE 6 CARACTERES APRES L'EXTENSION");
             color(10,0);
        printf("\n Entrer l'email encore une fois");
              color(15,0);
        goto sinonemail;
     }
     //RECHERCHE D'UN NOM  DE DOMAINE
     if(strchr(voir, '.')==NULL){
             color(12,0);
        printf("\n \t \t ERREUR: VOUS DEVEZ AVOIR UN NOM DE DOMAINE");
        printf("\n \t \t ERREUR: TEL QUE .com .fr .org");
               color(10,0);
        printf("\n Entrer l'email encore une fois");
                color(15,0);
        goto sinonemail;
     }

}

void entrerNim(int *num){

    sinonNim: // ETIQUETTE
    printf("\nTelephone: ");
    *num=lireInt();
    //CONDITION POUR VERIFIER SI LE NUMERO EST VALABLE EN HATITI
    if(*num<10000000 || *num>99999999){
             color(12,0);
        printf("\t \t ERREUR: VOTRE NUREMO DOIT AVOIR 8 CHIFFRES");
             color(15,0);
        goto sinonNim;
    }
    if(! ((*num>22000000 && *num<22999999) || (*num>28100000&&*num<28199999) || (*num>25000000&&*num<25999999) || (*num>31000000&&*num<43999999) || (*num>46000000&&*num<48999999)) ){
               color(12,0);
        printf("ERREUR: VOTRE NUREMO DOIT COMMENCER PAR:");
        printf("\n 22 25 entre (31 et 39) entre(40 et 43) entre(46 et 48)");
               color(15,0);
        goto sinonNim;
    }
         color(4,0);
    printf("\n le numero telephone est: +509 %d", *num);
         color(15,0);
}
void pp_info(struct parti *lavalas){
    int id;

    printf("\n Vous allez entrer les differentes informations a propos de votre parti politique");
    printf("\n Vous allez les entrer dans l'ordre suivant");
    printf("\n 1-Nom du parti politique ");
    printf("\n 2-Date de creation de cet parti");
    printf("\n 3-Adresse du parti politique");
    printf("\n 4-Responsable du parti");
    printf("\n 5-Email");
    printf("\n 6-Telephone");

     color(10,0);
    printf("\n \t \t PRESSEZ UN BOUTON POUR CONTINUER");
     color(15,0);
    getch();

    clr();
    // GENERER UN ID POUR CHAQUE ENTREE RETENUE
    id=rec_ID();
    id++;
    lavalas->Id_PP=id;
    put_ID(id);
    // RECUPERATION DE LA DATE DU JOUR
    dateDuJour(&lavalas->date_ins);
    // DEMANDER A L'UTILISATEUR D'ENTRER LE NOM DU PARTI
    printf("\n\t\t--NOM DU PARTI;");
    lire(lavalas->nom,2*tailleMot);
    clr();


    // DEMANDER A L'UTILISATEUR D'ENTRER LA DATE DE CREATION DE CE PARTI
    printf("\n\t\t\t2-DATE DE CREATION--");
    entrerDate(&lavalas->date_creat, &lavalas->date_ins);
    clr();
    // ICI POUR ENTRER L'ADRESSE
    printf("\n\t\t\t3-ADRESSE DU PARTI POLITIQUE--");
    entrerAdresse(&lavalas->adresse);
    clr();
    // ENTRER LE NOM DU RESPONSABLE
    printf("\n\t \t \t4-NOM DU RESPONSABLE DU PARTI--");
    entrerResp(&lavalas->Responsable);
    clr();
    // RECUPERATION DE L'EMAIL
    printf("\n \t \t \t5-EMAIL--");
    printf("\n \t Entrer l'email du parti politique: ");
    entrerEmail(&lavalas->email);
    clr();
     // RECUPERATION DU # TELEPHONE
    printf("\n \t \t \t 6-TELEPHONE--");
    printf("\n \t Entrer le telephone du parti politique: ");
    entrerNim(&lavalas->telephone);
    clr();

}
// CETTE FONCTION PERMET L'AFFICHAGE DES VALEURS
void aff_parti(struct parti* lavalas){

   printf("\n\n1-Nom du parti              : %s \n", lavalas->nom);
   printf("2-La date de creation est   : %d/%d/%d \n", lavalas->date_creat.jour, lavalas->date_creat.mois, lavalas->date_creat.annee);
   printf("3-Adresse                   : %d, %s, %s \n", lavalas->adresse.rue, lavalas->adresse.nomRue, lavalas->adresse.departement);
   printf("4-Responsable               : %s %s \n", lavalas->Responsable.nom, lavalas->Responsable.prenom);
   printf("5-Telephone                 : +509 %d \n",lavalas->telephone);
   printf("6-Email                     : %s \n", lavalas->email);

    printf("\n \t \t \t \t Inscrit le : %d/%d/%d \n", lavalas->date_ins.jour, lavalas->date_ins.mois, lavalas->date_ins.annee);
    printf("\t \t \t \t ID         : %d \n", lavalas->Id_PP);
}

// CETTE FONCTION DEMANDE A LUTILISATEUR S'IL NE VEUT PAS MODIFIER LES DONNEES AVANT LENREFISTREMENT
int modiBefore(struct parti* lavalas){
    int ok;
    int choix;
    clr(); // nettoyer le console
    aff_parti(lavalas);// affichage des donnees precedemment entrees
     color(10,0);
    printf("\n voulez vous modifier les valeurs ci-dessus");

    printf("\n si oui presser 1 \n sinon presser 0:-> ");
     color(15,0);
    ok=lireInt();

    while(ok==1){
        clr();
        aff_parti(lavalas);
        printf(" \n \t \t Entrer le # du champ que vous voulez modifier ->");
        choix=lireInt();

        switch(choix)
        {
        case 1:
                printf("\nEntrer le nouveau nom");
                printf("\nNom du parti: ");
                lire(&lavalas->nom,tailleMot);
            break;
        case 2:
                printf("\nEntrer la nouvelle date de creation");
                printf("\n Date creation ");
                entrerDate(&lavalas->date_creat,&lavalas->date_ins);
            break;
        case 3:
                printf("\nEntrer la nouvelle adresse");
                printf("\n adresse");
                entrerAdresse(&lavalas->adresse);
            break;
        case 4:
                printf("\nEntrer la nouvelle valeur");
                printf("\n Responsable");
                entrerResp(&lavalas->Responsable);
            break;
        case 5:
                printf("\nEntrer le nouveau numero");
                entrerNim(&lavalas->telephone);
            break;
        case 6:
                printf("\nEntrer le nouveau email");
                entrerEmail(&lavalas->email);
            break;
        }
        clr();
        aff_parti(lavalas);
        color(10,0);
        printf(" \n \t \t Voulez vous faire une autre modification \n si oui presser 1 \n sinon presser 0 :-> ");
        color(15,0);
        ok=lireInt();
    }

}

//FONCTION ENREGISTRER PARTI
void ins_PP(){
         struct parti lavalas;

        pp_info(&lavalas);
        aff_parti(&lavalas);
        modiBefore(&lavalas);

        //ecriture en fichier

       // struct parti* PP = (struct parti*)malloc(sizeof(struct parti));

       FILE* fichier= NULL;

           fichier =fopen("part_pol.dat","a");
               if(fichier==NULL){
                    printf("fichier not open");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }

            fwrite(&lavalas,sizeof(struct parti),1,fichier);

            fclose(fichier);

}

void list_PP(){
      int i=1;
       struct parti lavalas;
      FILE* fichier= NULL;

           fichier =fopen("part_pol.dat","r");
               if(fichier==NULL){
                    printf("le fichier ne veut pas s'ouvrir");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }
            rewind(fichier);

            printf("\n \n \t \tliste des partis politiques");
            while( i< 4){
                 fread(&lavalas,sizeof(struct parti),1,fichier);
                 printf("\n %d-------------------------------------------", i);
                 i++;
                 aff_parti(&lavalas);
            }


            fclose(fichier);
}

// ENSEMBLE DES FONCTIONS BASIQUES
// CETTE FONCTION EST DEFINIE POUR POUVOIR DETERMINER SI UNE ANNEE EST BISEXTILE OU PAS
int bisex(int A){

    if((A%4==0)&&((A%100>0)||(A%400==0))){
        return 1;
    }
     else return 0;
}

void color(int t, int f){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,f*16+t);
}

int rec_ID(){
    int i=0;

      FILE* fichier= NULL;

           fichier =fopen("ID.dat","r");
               if(fichier==NULL){
                    printf("le fichier ne veut pas s'ouvrir");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }
            rewind(fichier);

            fread(&i,sizeof(int),1,fichier);

            fclose(fichier);

            remove("ID.dat");

            return i;
}

void put_ID(int i){

       FILE* fichier= NULL;

           fichier =fopen("ID.dat","w");
               if(fichier==NULL){
                    printf("le fichier ne veut pas s'ouvrir");
                    exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
               }
            rewind(fichier);

            fwrite(&i,sizeof(int),1,fichier);

            fclose(fichier);
}
