#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "departement.h"

int verif_unicite_dep(departement d)
{
    int exist=0;
    departement dep;
    FILE *fD = fopen("fdepartement.txt","r");
    while (!feof(fD))
    {
       fscanf(fD,"%s\n", dep.nomDep);
       if (strcmp(dep.nomDep,d.nomDep)==0)
       {
            printf("ce departement existe deja");
            return 1;
       }

    }
    fclose(fD);

    return 0;
}

departement lireDepartement()
{
     departement d;
     do
     {
         printf("\n\n                                                                      Donner le nom de departement: ");
     scanf("%s",d.nomDep);
     }while (verif_unicite_dep(d)==1);
     return d ;

}


void ajoutDepartement(departement d)
{
    d=lireDepartement();
    FILE *fDepartements  = fopen("fdepartement.txt", "a");
    if(fDepartements == NULL) { printf("\n\n                                                                      Could not open the file."); return -1; }
    fprintf(fDepartements, "%s\n", d.nomDep);
    fclose(fDepartements);
}

void afficherListeDepartement()
{
    char string[200];
    FILE *fDepartement  = fopen("fdepartement.txt", "r");
    if(fDepartement == NULL) { printf("\n\n                                                                      Could not open the file."); return -1; }
    departement e;
    while (!feof(fDepartement))
    {
        fscanf(fDepartement,"%s\n", e.nomDep);
        AfficheDepartement(e);
    }
    fclose(fDepartement);
}

void AfficheDepartement(departement E)
{
    printf("\n\n                                                                      nom: %s    ", E.nomDep);

}



void suppressionDepartement(departement d)
{
    int exist=0;
    char *command = "cls";
    char ch[20];
    printf("                                                                      Saisir le nom du departement a supprimer: ");
    scanf("%s",ch);
    system(command);
    departement T[100];
    int k=0,i;
    FILE *fDepartement = fopen("fdepartement.txt", "r");
    while (!feof(fDepartement))
    {
        fscanf(fDepartement, "%s\n", d.nomDep);
        if ((strcmp(ch,d.nomDep)!=0))
            {T[k]=d;
            k++;
            }
        else
            exist=1;
    }
    fclose(fDepartement);
    if (exist==0)
        printf("\n\n                                                                      Ce departement n'existe pas.\n");
    fDepartement  = fopen("fdepartement.txt", "w");
    for (i=0;i<k;i++)
    {
        fprintf(fDepartement, "%s\n", T[i].nomDep);
    }
    fclose(fDepartement);
}





