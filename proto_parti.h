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
#define clr(); printf("\n \t \t Patientez "); Sleep(1500); system("clear");





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
// L'ENSEMBLE DES VARIABLES GLOBALES


// L'ENSEMBLE DES PROTOTYPES DES FONCTIONS DEFINIES EN 'ge_parti'
    void entrerAdresse();
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
    int rec_Nombre_Enr();
    void put_Nombre_Enr();
    void modif_PP();
