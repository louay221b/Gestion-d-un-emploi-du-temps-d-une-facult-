#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "matiere.h"



int verif_unicite_matiere(matiere m)
{
    matiere mat;
    FILE *fM = fopen("fmatiere.txt","r");
    while (!feof(fM))
    {
       fscanf(fM,"%s %d\n", mat.nomm,&(mat.coef));
       if (strcmp(mat.nomm,m.nomm)==0)
       {
            printf("                                                                      Cette matiere existe deja.\n");
            return 1;
       }

    }
    fclose(fM);
    return 0;
}

matiere lireMatiere()
{
     matiere m;
     do
     {
     printf("                                                                      Nom de la matiere: ");
     scanf("%s",m.nomm);
     }
     while(verif_unicite_matiere(m)!=0);
     printf("                                                                      Donner la coefficient de la matiere: ");
     scanf("%d" ,&(m.coef) );
     return m;
}


void ajoutMatiere(matiere m)
{
    m=lireMatiere();
    FILE *fMatiere  = fopen("fmatiere.txt", "a");
    if(fMatiere == NULL) { printf("                                                                      Could not open the file."); return -1; }
    fprintf(fMatiere, "%s %d\n", m.nomm,m.coef);
    fclose(fMatiere);
}

void afficherListeMatiere(matiere m)
{
    char string[200];
    FILE *fMatiere  = fopen("fmatiere.txt", "r");
    if(fMatiere == NULL) { printf("                                                                      Could not open the file."); return -1; }
    while (!feof(fMatiere))
    {
        fscanf(fMatiere,"%s %d\n", m.nomm,&(m.coef));
        AfficheMatiere(m);
    }
    fclose(fMatiere);
}

void AfficheMatiere(matiere M)
{
    printf("                               Nom de la matiere: %s   ", M.nomm);
    printf("       coefficient: %d\n", M.coef);
}



void suppressionMatiere(matiere m)
{
    int exist=0;
    char nom[20] ;
    printf("                                                                      Saisir le nom de la matiere a supprimer : ");
    scanf("%s",nom);
    matiere T[100];
    int k=0,i;
    FILE *fMatiere= fopen("fmatiere.txt", "r");
    while (!feof(fMatiere))
    {
        fscanf(fMatiere, "%s %d\n", m.nomm,&(m.coef));
        if (strcmp(nom,m.nomm))
            {T[k]=m;
            k++;
            }
        else
            exist=1;
    }
    fclose(fMatiere);
    if (exist==0)
        printf("                                                                      Cette matiere n'existe pas.\n");
    fMatiere = fopen("fmatiere.txt", "w");
    for (i=0;i<k;i++)
    {
        fprintf(fMatiere, "%s %d\n", T[i].nomm,(T[i].coef));
    }
    fclose(fMatiere);
}

