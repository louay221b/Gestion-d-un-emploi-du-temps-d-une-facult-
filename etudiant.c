#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "etudiant.h"
#include "edt.h"


int verifCIN(char ch[9])
{
    int valide=1;
    int i;
    char buffer [20];
    char CIN [9];

        if (strlen(ch)!=8)
            valide =-1;
      for (i=0;i<8;i++)
            if(ch[i]<48 || ch[i]>57)
                valide=-1;

    if (valide==-1)
        printf("\n\n                                                                      Donner un entier de 8 chiffres\n");
    return valide;
    }



etudiant lireEtudiant()
{
     int x;
     etudiant E;
     printf("\n\n                                                                      Nom de l'etudiant: ");
     scanf("%s",E.nome);
     printf("\n\n                                                                      Prenom de l'etudiant: ");
     scanf("%s",E.prenome);
     do
     {
         printf("\n\n                                                                      ID de l'etudiant: ");
         scanf("%s" ,E.ID );
     }while(verifCIN(E.ID)!=1);
     printf("\n\n                                                                      Classe: ");
     scanf("%s",E.nomcl);



     return E ;
}

void EspaceEtudiant()
{
    char *command = "cls";
    system("color 8E");
    int c;
    char classe[10];
    do
    {

        printf("\n\n                                                          ------------Espace Etudiant------------\n");
        printf("                                                                  (1) : Afficher EDT \n");
        printf("                                                                  (2) : Retour \n");

        do
        {
            printf("\n\n                                                                      Saisir le choix : ");
            scanf("%d",&c);
        }
        while(c!=1 && c!=2);
        switch(c)
        {
            case 1:AfficherClasseEDT(classe);break;
        }

    } while(c!=2);
    system(command);
}

void ajoutEtudiant(etudiant e,char c[10])
{
    char ch[29];
    e=lireEtudiant();
    strcpy(c,e.nomcl);
    strcpy(ch,"fetudiant");
    strcat(ch,c);
    strcat(ch,".txt");
    FILE *fEtudiants  = fopen(ch, "a");
    if(fEtudiants == NULL) { printf("\n\n                                                                      Could not open the file."); return -1; }
    fprintf(fEtudiants, "%s %s %s %s\n",e.nome,e.prenome,e.ID,e.nomcl);
    fclose(fEtudiants);
}


void afficherListeEtudiants(char c[10])
{
    char string[500];
    char ch[30];
    etudiant e;
    printf("donner la classe: ");
    scanf("%s",c);
    strcpy(ch,"fetudiant");
    strcat(ch,c);
    strcat(ch,".txt");
    FILE *fEtudiants  = fopen(ch, "r");
    if(fEtudiants == NULL) { printf("\n\n                                                                      Could not open the file."); return -1; }
    while (!feof(fEtudiants))
    {
        fscanf(fEtudiants, "%s %s %s %s\n",e.nome,e.prenome,e.ID,e.nomcl);
        Afficheetudiant(e);
    }
    fclose(fEtudiants);
}


void Afficheetudiant(etudiant E)
{
    printf("nom: %s   ", E.nome);
    printf("prenom: %s   ", E.prenome);
    printf("ID: %s   ", E.ID);
    //printf("classe: %s\n", E.nomcl);
}



void suppressionEtudiant(etudiant e,char c[10])
{
    int exist = 0;
    char ch[30];
    char id[9];
    int k=0,i;
    printf("\n\n                                                                      Saisir l'id de l'etudiant a supprimer : ");
    scanf("%s",id);
    etudiant T[100];
    printf("\n\n                                                                      donner la classe: ");
    scanf("%s",c);
    strcpy(ch,"fetudiant");
    strcat(ch,c);
    strcat(ch,".txt");
    FILE *fEtudiants  = fopen(ch, "r");
    while (!feof(fEtudiants))
    {
        fscanf(fEtudiants, "%s %s %s %s\n", e.nome,e.prenome,e.ID,e.nomcl);
        if (strcmp(id,e.ID)!=0)
            {T[k]=e;
            k++;
            }
        else
            exist=1;
    }
    fclose(fEtudiants);
    if (exist==0)
        printf("\n\n                                                                      Cet etudiant n'existe pas\n");
    fEtudiants  = fopen(ch, "w");
    for (i=0;i<k;i++)
    {
        fprintf(fEtudiants, "%s %s %s %s\n", T[i].nome,T[i].prenome,T[i].ID,e.nomcl);
    }
    fclose(fEtudiants);
}

