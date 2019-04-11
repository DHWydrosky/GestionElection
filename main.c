#include "proto_parti.h"

int main()
{
   struct parti lavj;

     pp_info(&lavj);
     aff_parti(&lavj);


   /*FILE* fichier= NULL;

   fichier =fopen("part_pol.dat","w");
       if(fichier==NULL){
            printf("fichier not open");
            exit(0);
       }
        fwrite(&lavj,sizeof(struct parti),1,fichier);
    fclose(fichier);
   */
    return 0;
}

