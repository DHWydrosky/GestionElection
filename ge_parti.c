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
                printf("\n \t VOTRE ENTREE N'A PAS ETE VALIDE ____ ENTRER ENCORE ");
                printf("\n Entrer le nombre correspondant ici: ");
                goto re_enter;
            }
            else
                i++;
        }


        return strtol(chaine,NULL,caracMini);

    }
    else
    {
        printf("\n \t VOTRE ENTREE N'A PAS ETE VALIDE");
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
   lire(adresse->departement,caracMini);
   majuscule(adresse->departement);
    /*char de[]="OUEST";
   if(strcmp(adresse->departement,de)!=0){
    printf("lkkk bkksksk");
   }*/

    printf("\nvous habitez a %d, %s, %s \n", adresse->rue, adresse->nomRue, adresse->departement);
}

//FONTION NOUS PERMETTANT D'ENTRER LES DATES
void entrerDate(struct dat *sdate, struct dat *actuel){
    printf("\nVous aller entrer la date dans le format AAAA/MM/JJ exemple 1996/08/10 \n");

        do{
            printf("\n \t Annee: ");
            sdate->annee = lireInt();
            if(sdate->annee>2019){
                printf("\n \t ERREUR: L'ANNEE DE CREATION NE PEUT ETRE SUPERIEUR A 2019");
            }
        }while(sdate->annee<=1000 || sdate->annee>2019);

        do{

            printf("\n \t Mois: ");
            sdate->mois = lireInt();
            if(sdate->mois>12){
            printf("\n \t ERREUR: IL Y A 12 MOIS DANS UNE ANNEE");
           }
        }while(sdate->mois<=0 || sdate->mois>12);

         sinonjour://ETIQUETTE
           printf(" \n\t Jour: ");
           sdate->jour = lireInt();

        if (sdate->jour<=0){
            printf("\n \t \t ERREUR: ON NE PREND PAS DE VALEUR NEGATIF");
            printf("\n \t \t Entrer le jour encore une fois");
            goto sinonjour;
        }
        if (sdate->jour>31){
            printf("\n \t \t ERREUR: AUCUN MOIS NE CONTIENT PLUS DE 31 JOURS");
            printf("\n \t \t Entrer le jour encore une fois");
            goto sinonjour;
        }
        if (sdate->mois%2==0 && sdate->jour>30 && sdate->mois<8){
            printf("\n \t \t ERREUR: CE MOIS NE CONTIENT PAS PLUS DE 30 JOURS");
            printf("\n \t \t Entrer le jour encore une fois");
            goto sinonjour;
        }
        if (sdate->mois%2==1 && sdate->jour>30 && sdate->mois>8){
            printf("\n \t \t ERREUR: CE MOIS NE CONTIENT PAS PLUS DE 30 JOURS");
            printf("\n \t \t Entrer le jour encore une fois");
            goto sinonjour;
        }
        if(sdate->mois==2 && sdate->jour >30 && bisex(sdate->annee)==1){
            printf("\n \t \t ERREUR: CE MOIS NE CONTIENT PAS PLUS DE 28 JOURS");
            printf("\n \t \t Entrer le jour encore une fois");
            goto sinonjour;
        }
        if(sdate->mois==2 && sdate->jour>28 && bisex(sdate->annee)==0){
            printf("\n \t \t ERREUR: CE MOIS NE CONTIENT PAS PLUS DE 29 JOURS");
            printf("\n \t \t Entrer le jour encore une fois");
            goto sinonjour;
        }

      if(sdate->annee == actuel->annee && sdate->mois == actuel->mois && sdate->jour == sdate->jour ){
        printf("ERREUR: LA DATE DE CREATION NE PEUT SE CONFONDRE AVEC LA DATE D'INSCRIPTION");
      }


    printf("\n \t La date de creation est %02d/%02d/%d \n ", sdate->jour, sdate->mois, sdate->annee);
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
    printf("\nVous allez entrer le nom du Responsable");

    printf("\n \t Nom: ");
    lire(resp->nom,2*caracMini);

    printf("\n \t Prenom: ");
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
        printf("\n \t \t ERREUR: VOTRE EMAIL NE PEUT CONTENIR LES CARACTERES SUIVANTS");
        printf("\n \t \t !$&*-^\=`#%'+/?_{}");
        printf("\n Entrer l'email encore une fois");
        goto sinonemail;
    } // SI EMAIL RECUPERE CONTIENT LES CARACTERES REPRESENTES CI-DESSUS ON REDEMANDE A L'UTILISATEUR L'EMAIL
     voir=NULL;
     voir = strpbrk(email, "@"); // RECUPERER L'ADRESSE DU CARACTERE @

     if(voir==NULL){
        printf("\n \t \t ERREUR: VOUS N'AVEZ PAS INSERER DE NOM D'EXTENSION");
        printf("\n \t Entrer l'email encore une fois");
        goto sinonemail;
     }// VOIR S'IL Y A UN EXTENSION

      // VERIFIER SI IL Y A PLUS DE 6 CARACTERE AVANT L'EXTENSION
     i=0;
     while(email[i]!='@' && i<49){
        i++;
     }
     if(i<6){
        printf("\n \t \t ERREUR: VOUS DEVEZ AVOIR PLUS DE 6 CARACTERES AVANT L'EXTENSION");
        printf("\n Entrer l'email encore une fois");
        goto sinonemail;
     }
     //VERIFIER SI IL Y A PLUS DE 6 CARACTERE APRES @
     if(strlen(voir)<6){
        printf("\n \t \t ERREUR: VOUS DEVEZ AVOIR PLUS DE 6 CARACTERES APRES L'EXTENSION");
        printf("\n Entrer l'email encore une fois");
        goto sinonemail;
     }
     //RECHERCHE D'UN NOM  DE DOMAINE
     if(strchr(voir, '.')==NULL){
        printf("\n \t \t ERREUR: VOUS DEVEZ AVOIR UN NOM DE DOMAINE");
        printf("\n \t \t ERREUR: TEL QUE .com .fr .org");
        printf("\n Entrer l'email encore une fois");
        goto sinonemail;
     }

}

void entrerNim(int *num){

    sinonNim: // ETIQUETTE
    printf("Telephone: ");
    *num=lireInt();
    //CONDITION POUR VERIFIER SI LE NUMERO EST VALABLE EN HATITI
    if(! (*num>22000000 && *num<22999999) && (*num>28100000&&*num<28199999) && (*num>25000000&&*num<25999999) && (*num>31000000&&*num<43999999) && (*num>46000000&&*num<48999999) ){
        printf("ERREUR: VOTRE NUREMO DOIT COMMENCER PAR:");
        printf("\n 22 25 entre (31 et 39) entre(40 et 43) entre(46 et 48)");
        goto sinonNim;
    }
}
void pp_info(struct parti *lavalas){
    printf("\n Vous allez entrer les differentes informations a propos de votre parti politique");
    printf("\n Vous allez les entrer dans l'ordre suivant");
    printf("\n 1-Nom du parti politique ");
    printf("\n 2-Date de creation de cet parti");
    printf("\n 3-Adresse du parti politique");
    printf("\n 4-Responsable du parti");
    printf("\n 5-Email");
    printf("\n 6-Telephone");

    printf("\n \t \t PRESSEZ UN BOUTON POUR CONTINUER");
    getch();

    clr();
    // GENERER UN ID POUR CHAQUE ENTREE RETENUE
    lavalas->Id_PP=1;
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
    printf("\n\t \t \t4-RESPONSABLE DU PARTI--");
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

// CETTE FONCTION EST DEFINIE POUR POUVOIR DETERMINER SI UNE ANNEE EST BISEXTILE OU PAS
int bisex(int A){

    if((A%4==0)&&((A%100>0)||(A%400==0))){
        return 1;
    }
     else return 0;
}
void majuscule(char *chaine){
int i=0;
    while(chaine[i]!='\0'){
        chaine[i]= toupper(chaine[i]);
        i++;
    }
}
