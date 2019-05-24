#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

// L'ENSEMBLE DES 'DEFINE'
#define tailleMot 50
#define caracMini 10
#define taillecin 19
#define clr(); Sleep(100); system("clear");

#define id_bv(nom) fichier =fopen(nom,"w");\
               if(fichier==NULL){ \
                    printf("le fichier ne peut pas s'ouvrir");\
                    exit(0); /*LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO*/\
               }\
            rewind(fichier);\
            fwrite(&id,sizeof(int),1,fichier);

#define  id_bv_rec(nom)  fichier =fopen(nom,"r");\
               if(fichier==NULL){\
                    printf("le fichier ne peut pas s'ouvrir");\
                    exit(0); /* LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO*/\
               }\
            rewind(fichier);\
            fread(&i,sizeof(int),1,fichier);\
            fclose(fichier);\
            remove(nom);\





// les nouveaux types
struct Adres{
    int rue;
    char nomRue[tailleMot];
    char departement[tailleMot];
};
struct dat{
    int jour;
    int mois;
    int annee;
};
struct Responsables{
    char nom[2*caracMini];
    char prenom[2*caracMini];
};
struct id_can{
 int dependance;
 int propre;
 int departement;
};
struct parti{
    int Id_PP;
    char nom[tailleMot];
    struct dat date_creat;
    struct dat date_ins;
    struct Adres adresse;
    struct Responsables Responsable;
    int telephone;
    char email[tailleMot];
};

             // types candidats

struct candidats {
    struct id_can Id_candid;
    char Nom[tailleMot];
    char Prenom[tailleMot];
    struct dat Dat_Nais;
    struct Adres Adresse;
    char Email[2*caracMini];
    int tel;
    int type;
    struct dat Date_ins;
};
     // TYPES VOTES
struct votes {
   int Id_vote;
   struct dat Date_vote;
   int BV;
   char CIN[50];
   struct id_can id_candid_1;
   struct id_can id_candid_2;
   struct id_can id_candid_3;

};

// types bureau de votes
struct id_biwo{
  int propre;
  int departement;
};

typedef struct Bvote
{
	struct id_biwo Id_BV;
	struct Adres Adresse;
	char Id_President[256];
	char Id_VPresident[256];
	char Id_secret[256];
} Bvote;

//types electeurs
typedef struct elect
{
	struct Adres adresse;
	char CIN[taillecin];
	char Nom[tailleMot];
	char Prenom[tailleMot];
	struct id_biwo BV;
} elect;


// L'ENSEMBLE DES VARIABLES GLOBALES


// L'ENSEMBLE DES PROTOTYPES DES FONCTIONS DEFINIES EN 'ge_parti'
    int entrerAdresse();
    void entrerDate();
    int lireInt();
    int lire();
    void entrerNim();
    void entrerEmail();
    void dateDuJour();
    int bisex();
    void entrerResp();
    void pp_info();
    void majuscule();
    void aff_parti();
    void color();
    void ins_PP();
    int rec_ID();
    void put_ID();
    int rec_candi_ID();
    void put_candi_ID();
    void nombre_enr();
    void modif_PP();
    void menu_PP();

    // ensemble des prototypes de fonctions ayant rapport avec les candidats

    void cand_info();
    void modi_candi_Before();
    void list_candid();
    void list_candid_depar();
    void menu_Candi();
    void affi_candi();
    void ins_cand();
    void modif_cand();

    // ensemble des prototypes de fonctions relatives aux votes
    void menu_vote();

    // ensemble des prototypes de fonctions relatives aux bureaux de votes
    void BV_info();
    void affi_BV();
    void list_BV();
    void list_BV_departement();
    void modif_BV();
    void modif_BV_before();
    void modif_elect();
    int unik_id_BV();
    void menu_BV();


    void menu();
    void cin_pers();
    int if_cin_exist();


    void elect_info();
    void affi_electeur();
    void modif_elect_before();
    void list_electeur();
    void ins_elect();
    void menu_elect();

