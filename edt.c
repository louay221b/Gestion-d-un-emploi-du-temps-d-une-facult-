#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "date.h"
#include "heure.h"
#include "enseignant.h"
#include "salle.h"


void AfficherClasseEDT(char c[10])
{
    char ligne[100];
    char ch [20];
    printf("\n\n                                                                     Donner la classe: ");
    scanf("%s",c);
    strcpy(ch,"fEDT");
    strcat(ch,c);
    strcat(ch,".txt");
    FILE *fEDT  = fopen(ch,"r");
    if(fEDT == NULL) { printf("\n\n                                                                      Could not open the file."); return -1; }
    while (!feof(fEDT))
    {
        fgets(ligne,100,fEDT);
        printf("%s",ligne);
    }
    fclose(fEDT);
}


void AfficherEnseignantEDT(enseignant e)
{
    char ligne[100];
    char ch [20];
    printf("\n\n                                                                      Donner le nom de l'enseignant: ");
    scanf("%s",e.noms);
    strcpy(ch,"fEDT");
    strcat(ch,e.noms);
    strcat(ch,".txt");
    FILE *fEDT  = fopen(ch, "r");
    if(fEDT == NULL) { printf("\n\n                                                                      Could not open the file."); return -1; }
    while (!feof(fEDT))
    {
        fgets(ligne,100,fEDT);
        printf("%s",ligne);
    }
    fclose(fEDT);
}


void AfficherSalleEDT(salle s)
{

    char *command = "cls";
    char ligne[100];
    char ch [20];
    char c[5];
    printf("\n\n                                                                      Donner le numeros de la salle: ");
    scanf("%d",&(s.num_salle));
    itoa(s.num_salle,c,10);
    strcpy(ch,"fEDTsalle");
    strcat(ch,c);
    strcat(ch,".txt");
    FILE *fEDT  = fopen(ch, "r");
    if(fEDT == NULL) { printf("\n\n                                                                      Could not open the file."); return -1; }
    while (!feof(fEDT))
    {
        fgets(ligne,100,fEDT);
        printf("%s",ligne);
    }
    fclose(fEDT);
    system(command);


}


int verifClasse(char c[10],date d,heure heureDeb,heure heureFin)
{
    date Day;
    char day[12];
    char buffer [120];
    char temps [12];
    char ch [20];
    char dayA [5],dayM[3],dayJ[3];
    char hourA[3], hourB[3], minutesA[3], minutesB[3];
    heure HDebut,HFin;
    int valide=1;
    strcpy(ch,"fEDT");
    strcat(ch,c);
    strcat(ch,".txt");
    FILE *fEDT  = fopen(ch, "r");
    if(fEDT == NULL) { printf("\n\n                                                                      Could not open the file."); return -1; }
    while (!feof(fEDT))
    {
        fgets(buffer,120,fEDT);
        strncpy(day,buffer,11);
        strncpy(dayJ, day, 2);
        strncpy(dayM,day+3, 2);
        strncpy(dayA,day+6, 4);
        Day.annee=atoi(dayA);
        Day.mois=atoi(dayM);
        Day.jour=atoi(dayJ);
        if( Day.jour==d.jour && Day.mois==d.mois && Day.annee==d.annee)
        {
        strncpy(temps,buffer+11,11);
        strncpy(hourA, temps, 2);
        strncpy(minutesA, temps+3, 2);
        strncpy(hourB, temps+6, 2);
        strncpy(minutesB, temps+9, 2);
        HDebut.h=atoi(hourA);
        HDebut.m=atoi(minutesA);
        HFin.h=atoi(hourB);
        HFin.m=atoi(minutesB);
        if ((HDebut.h<heureDeb.h && heureDeb.h<HFin.h)||(HDebut.h<heureFin.h && heureFin.h<HFin.h)||(heureDeb.h<HDebut.h && HDebut.h<heureFin.h)||(heureDeb.h<HFin.h && HFin.h<heureFin.h))
            return 0;
        if (HDebut.h==heureDeb.h )
            if (HDebut.m<=heureDeb.m || heureDeb.m<=HFin.m)
                return 0;
        if (HFin.h==heureFin.h)
            if (HDebut.m<=heureFin.m || heureFin.m<=HFin.m)
                return 0;
        if (HDebut.h==heureFin.h)
            if (HDebut.m<=heureFin.m)
                return 0;
        if (HFin.h==heureDeb.h)
            if (HFin.m>=heureDeb.m)
                return 0;
        }
    }
    return 1;
}


int verifEns(enseignant ens,date d,heure heureDeb,heure heureFin)
{
    date Day;
    char day[12];
    char buffer [120];
    char temps [12];
    char ch [20];
    char dayA [5],dayM[3],dayJ[3];
    char hourA[3], hourB[3], minutesA[3], minutesB[3];
    heure HDebut,HFin;
    int valide=1;
    strcpy(ch,"fEDT");
    strcat(ch,ens.noms);
    strcat(ch,".txt");
    FILE *fEDT  = fopen(ch, "r");
    if(fEDT == NULL) { printf("                                                                      Could not open the file."); return -1; }
    while (!feof(fEDT))
    {
        fgets(buffer,120,fEDT);
        strncpy(day,buffer,11);
        strncpy(dayJ, day, 2);
        strncpy(dayM,day+3, 2);
        strncpy(dayA,day+6, 4);
        Day.annee=atoi(dayA);
        Day.mois=atoi(dayM);
        Day.jour=atoi(dayJ);
        if( Day.jour==d.jour && Day.mois==d.mois && Day.annee==d.annee)
        {
        strncpy(temps,buffer+11,11);
        strncpy(hourA, temps, 2);
        strncpy(minutesA, temps+3, 2);
        strncpy(hourB, temps+6, 2);
        strncpy(minutesB, temps+9, 2);
        HDebut.h=atoi(hourA);
        HDebut.m=atoi(minutesA);
        HFin.h=atoi(hourB);
        HFin.m=atoi(minutesB);
        if ((HDebut.h<heureDeb.h && heureDeb.h<HFin.h)||(HDebut.h<heureFin.h && heureFin.h<HFin.h)||(heureDeb.h<HDebut.h && HDebut.h<heureFin.h)||(heureDeb.h<HFin.h && HFin.h<heureFin.h))
            return 0;
        if (HDebut.h==heureDeb.h )
            if (HDebut.m<=heureDeb.m || heureDeb.m<=HFin.m)
                return 0;
        if (HFin.h==heureFin.h)
            if (HDebut.m<=heureFin.m || heureFin.m<=HFin.m)
                return 0;
        if (HDebut.h==heureFin.h)
            if (HDebut.m<=heureFin.m)
                return 0;
        if (HFin.h==heureDeb.h)
            if (HFin.m>=heureDeb.m)
                return 0;
        }
    }
    return 1;
}


int verifSal(salle s,date d,heure heureDeb,heure heureFin)
{
    date Day;
    char day[12];
    char buffer[120];
    char temps[12];
    char ch[20];
    char c[7];
    char dayA [5],dayM[3],dayJ[3];
    char hourA[3], hourB[3], minutesA[3], minutesB[3];
    heure HDebut,HFin;
    int valide=1;
    itoa(s.num_salle,c,10);
    strcpy(ch,"fEDTsalle");
    strcat(ch,c);
    strcat(ch,".txt");
    FILE *fEDT  = fopen(ch, "r");
    if(fEDT == NULL) { printf("                                                                      Could not open the file."); return -1; }
    while (!feof(fEDT))
    {
        fgets(buffer,120,fEDT);
        strncpy(day,buffer,11);
        strncpy(dayJ, day, 2);
        strncpy(dayM,day+3, 2);
        strncpy(dayA,day+6, 4);
        Day.annee=atoi(dayA);
        Day.mois=atoi(dayM);
        Day.jour=atoi(dayJ);
        if( Day.jour==d.jour && Day.mois==d.mois && Day.annee==d.annee)
        {
        strncpy(temps,buffer+11,11);
        strncpy(hourA, temps, 2);
        strncpy(minutesA, temps+3, 2);
        strncpy(hourB, temps+6, 2);
        strncpy(minutesB, temps+9, 2);
        HDebut.h=atoi(hourA);
        HDebut.m=atoi(minutesA);
        HFin.h=atoi(hourB);
        HFin.m=atoi(minutesB);
        if ((HDebut.h<heureDeb.h && heureDeb.h<HFin.h)||(HDebut.h<heureFin.h && heureFin.h<HFin.h)||(heureDeb.h<HDebut.h && HDebut.h<heureFin.h)||(heureDeb.h<HFin.h && HFin.h<heureFin.h))
            return 0;
        if (HDebut.h==heureDeb.h )
            if (HDebut.m<=heureDeb.m || heureDeb.m<=HFin.m)
                return 0;
        if (HFin.h==heureFin.h)
            if (HDebut.m<=heureFin.m || heureFin.m<=HFin.m)
                return 0;
        if (HDebut.h==heureFin.h)
            if (HDebut.m<=heureFin.m)
                return 0;
        if (HFin.h==heureDeb.h)
            if (HFin.m>=heureDeb.m)
                return 0;
        }
    }
    return 1;
}



void verif_dispo_Classe(char c[20],date d,heure heureDeb,heure heureFin)
{
    char ch [20];
    d=lire_date(d);
    heureDeb=lire_heureDeb(heureDeb);
    do
    {
        heureFin=lire_heureFin(heureFin);
    }
    while(heureFin.h<heureDeb.h+1);
    printf("donner la classe: ");
    scanf("%s",c);
    if (verifClasse(c,d,heureDeb,heureFin) ==0)
        printf("                                                                      Vous ne pouvez pas ajouter cette seance\n");
    if (verifClasse(c,d,heureDeb,heureFin)==1)
        printf("                                                                      Vous pouvez ajouter cette seance\n");
}


void verif_dispo_Enseignant(enseignant ens,date d,heure heureDeb,heure heureFin)
{
    d=lire_date(d);
    heureDeb=lire_heureDeb(heureDeb);
    do
    {
        heureFin=lire_heureFin(heureFin);
    }
    while(heureFin.h<heureDeb.h+1);
    printf("                                                                      Donner le nom de l'enseignant: ");
    scanf("%s",ens.noms);
    if (verifEns(ens,d,heureDeb,heureFin)==0)
        printf("                                                                      Mr\Mme %s est occupè(e)\n",ens.noms);
    if (verifEns(ens,d,heureDeb,heureFin)==1)
        printf("                                                                      Mr\Mme %s est disonible\n",ens.noms);
}


 void verif_dispo_Salle(date d,heure heureDeb,heure heureFin)
   {
    salle s;
    d=lire_date(d);
    heureDeb=lire_heureDeb(heureDeb);
    do
    {
        heureFin=lire_heureFin(heureFin);
    }
    while(heureFin.h<heureDeb.h+1);
    printf("                                                                      donner le numero de la salle: ");
    scanf("%d",&(s.num_salle));
    if (verifSal(s,d,heureDeb,heureFin)==0)
        printf("                                                                      Cette salle est occupee\n");
    if (verifSal(s,d,heureDeb,heureFin)==1)
        printf("                                                                      Cette salle est libre\n");
    }




