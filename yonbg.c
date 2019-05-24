#include "proto_parti.h"


int if_cin_exist(char* cin){
     struct elect temporaire;
     int tem=0;
      FILE* fichier= NULL;


               fichier =fopen("elect.dat","r");
                   if(fichier==NULL){
                        printf("le fichier ne peut pas s'ouvrir");
                        exit(0);// LA NOU TA SIPOZE METE YON RETOUR NAN REEKRI INFO YO ANKO
                   }
                //rewind(fichier);
                while(!feof(fichier)){
                      fread(&temporaire,sizeof(struct elect),1,fichier);
                      if(strcmp(temporaire.CIN,cin)==0){
                            tem=1;
                     }
                }
    fclose(fichier);
    return tem;
}
