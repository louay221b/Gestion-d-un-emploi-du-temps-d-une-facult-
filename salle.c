#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "salle.h"
#include "edt.h"
#include "crenaux.h"



int verif_unicite_salle(salle s)
{
    char ligne [50];
    char ch_num[10];
    int valide=1;
    int numero;
    if ( s.num_salle <=100 || s.num_salle >1000)
        valide=-1;
    FILE *fS =fopen("fsalle.txt","r");
    while(!feof(fS))
    {
       fgets(ligne,20,fS);
       strncpy(ch_num,ligne,4);
       numero=atoi(ch_num);
       if (numero==s.num_salle)
            valide=0;
    }
    if (valide==-1)
        printf("                                                                      Vous devez Choisir un entier de 3 chiffres.\n");
    if (valide ==0)
        printf("                                                                      Cette salle existe deja.\n");
    return valide;
}












salle lireSalle()
{
     salle S;
     do
     {
        printf("                                                                      Numero de la salle: ");
        scanf("%d", &(S.num_salle) );
     }
     while(verif_unicite_salle(S) !=1);
     do
     {
         printf("                                                                      Type de la salle (cours/TD/TP): ");
         scanf("%s",S.salle_cren);
     }
     while(strcmp(S.salle_cren,"TD")!=0 && strcmp(S.salle_cren,"TP")!=0 && strcmp(S.salle_cren,"tp")!=0 && strcmp(S.salle_cren,"td")!=0 &&  strcmp(S.salle_cren,"cours")!=0);
     return S;
}



void ajoutSalle(salle s)
{
    s=lireSalle();
    FILE *fSalle = fopen("fsalle.txt", "a");
    if(fSalle == NULL) { printf("                                                                      Could not open the file."); return -1; }
    fprintf(fSalle, "%d %s\n",s.num_salle,s.salle_cren);
    fclose(fSalle);
}

void afficherListeSalle(salle s)
{
    char string[500];
    FILE *fSalle = fopen("fsalle.txt", "r");
    if(fSalle == NULL) { printf("                                                                      Could not open the file."); return -1; }
    while (!feof(fSalle))
    {
        fscanf(fSalle, "%d %s\n", &(s.num_salle),s.salle_cren);
        Affichesalle(s);
    }
    fclose(fSalle);
}

void Affichesalle(salle S)
{
    printf("                                                                      Numero de la salle: %d      ", S.num_salle);
    printf("type de la salle: %s\n", S.salle_cren);
}



void suppressionSalle(salle s)
{
    int num;
    int exist=0;
    printf("                                                                      Saisir le numero de la salle a supprimer : ");
    scanf("%d",&num);
    salle T[100];
    int k=0,i;
    FILE *fSalle = fopen("fsalle.txt", "r");
    while (!feof(fSalle))
    {
        fscanf(fSalle, "%d %s\n", &(s.num_salle),s.salle_cren);
        if (num!=s.num_salle)
            {T[k]=s;
            k++;
            }
        else
            exist=1;
    }
    fclose(fSalle);
    if (exist==0)
        printf("                                                                      cette salle n'existe pas\n");
    fSalle = fopen("fsalle.txt", "w");
    for (i=0;i<k;i++)
    {
        fprintf(fSalle, "%d %s\n",( T[i].num_salle),T[i].salle_cren);
    }
    fclose(fSalle);
}




