#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "enseignant.h"
#include "matiere.h"
#include "edt.h"



enseignant lireEnseignant()
{


     enseignant E;
     printf("\n\n                                                                      Nom de l'enseignant: ");
     scanf("%s",E.noms );
     printf("\n\n                                                                      Prenom de l'enseignant: ");
     scanf("%s",E.prenoms );
     printf("\n\n                                                                      donner la matiere: ");
     scanf("%s",E.mat.nomm );
     do
     {
        printf("\n\n                                                                      ID de l'enseignant: ");
        scanf("%s" ,E.ID );
     }
     while(verifCIN(E.ID)!=1);
     return E ;
}

void EspaceEnseignant()

{

    char *command = "cls";
    system("color 8B");
    int c;
    enseignant e;
    do
    {

        printf("\n\n                                                          ------------Espace Enseignant------------\n");
        printf("                                                                  (1) : Afficher EDT \n");
        printf("                                                                  (2) : Retour \n");

        do
        {
            printf("                                                                  Saisir le choix : ");
            scanf("%d",&c);
            system(command);
        }
        while(c!=1 && c!=2);
        switch(c)
        {
            case 1:AfficherEnseignantEDT(e);break;
        }

    } while(c!=2);
}


void ajoutEnseignant(enseignant e)
{
    e=lireEnseignant();
    FILE *fEnseignant  = fopen("fenseignant.txt", "a");
    if(fEnseignant == NULL) { printf("                                                                  Could not open the file."); return -1; }
    fprintf(fEnseignant, "%s %s %s %s\n", e.noms,e.prenoms,e.mat.nomm,e.ID);
    fclose(fEnseignant);

}

void afficherListeEnseignant(enseignant E)
{
    char string[200];
    FILE *fEnseignant  = fopen("fenseignant.txt", "r");
    if(fEnseignant == NULL) { printf("                                                                  Could not open the file."); return -1; }
    enseignant e;
    while (!feof(fEnseignant))
    {
        fscanf(fEnseignant,"%s %s %s %s\n", e.noms,e.prenoms,e.mat.nomm,e.ID);
        Afficheenseignants(e);
    }
    fclose(fEnseignant);
}

void Afficheenseignants(enseignant E)
{
    printf("Nom: %s          ", E.noms);
    printf("Prenom: %s          ", E.prenoms);
    printf("Matiere: %s          ", E.mat.nomm);
    printf("ID: %s   \n\n", E.ID);
}



void suppressionEnseignant(enseignant e)
{
    int exist =0;
    char *command = "cls";
    char id[9];
    printf("                                                                  Saisir l'ID de l'enseignant a supprimer : ");
    scanf("%s",id);
    system(command);

    enseignant T[100];
    int k=0,i;
    FILE *fEnseignant = fopen("fenseignant.txt", "r");
    while (!feof(fEnseignant))
    {
        fscanf(fEnseignant, "%s %s %s %s\n",e.noms,e.prenoms,e.mat.nomm,e.ID);
        if (strcmp(id,e.ID)!=0)
            {T[k]=e;
            k++;
            }
        else
            exist =1;
    }
    fclose(fEnseignant);
    if (exist==0)
        printf("\n\n                                                                      Cet enseignant n'existe pas\n");
    fEnseignant  = fopen("fenseignant.txt", "w");
    for (i=0;i<k;i++)
    {
        fprintf(fEnseignant, "%s %s %s %s\n",T[i].noms,T[i].prenoms,T[i].mat.nomm,T[i].ID);
    }
    fclose(fEnseignant);
}




