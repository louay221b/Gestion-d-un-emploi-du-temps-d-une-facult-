#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include"etudiant.h"
#include "administration.h"
#include "date.h"
#include "heure.h"
#include "matiere.h"
#include "crenaux.h"
#include "departement.h"
#include "enseignant.h"
#include "salle.h"
#include "classe.h"

void EspaceAdministration()
{
    char *command = "cls";
    system("color 2F");
    int c;
    do
    {

        printf("\n\n                                                          ------------Espace admnistration------------\n\n");
        printf("                                                                  (1) : Administration des etudiants \n");
        printf("                                                                  (2) : Administration des enseignants \n");
        printf("                                                                  (3) : Administration des departements \n");
        printf("                                                                  (4) : Administration des matieres \n");
        printf("                                                                  (5) : Administration des salles \n");
        printf("                                                                  (6) : Retour \n");

        do
        {
            printf("\n\n                                                                      Saisir le choix : ");
            scanf("%d",&c);
            system(command);
        }
        while(c!=1 && c!=2 && c!=3 && c!=4 && c!=5 && c!=6);
        switch(c)
        {
            case 1:AdministrationEtudiant();break;
            case 2:AdministrationEnseignant();break;
            case 3:AdministrationDepartement();break;
            case 4:AdministrationMatiere();break;
            case 5:AdministrationSalle();break;
        }

    } while(c!=6);



}

void AdministrationEtudiant()
{
    char *command = "cls";
    int c;
    etudiant E;
    char classe[20];
    date d;
    heure heureDeb,heureFin;
    do
    {
        printf("\n\n                                                          ------------Espace admnistration : Etudiants------------\n\n");
        printf("                                                                  (1) : Consulter la liste des etudiants \n");
        printf("                                                                  (2) : Ajouter un etudiant \n");
        printf("                                                                  (3) : Supprimer un etudiant \n");
        printf("                                                                  (4) : Verifier la disponibilite de la classe \n");
        printf("                                                                  (5) : Retour \n");
        do
        {
            printf("\n\n                                                                      Saisir le choix : ");
            scanf("%d",&c);
            system(command);
        }
        while(c!=1 && c!=2 && c!=3 && c!=4 && c!=5);
        switch(c)
        {
            case 1:afficherListeEtudiants(classe);break;
            case 2:ajoutEtudiant(E,classe);break;
            case 3:suppressionEtudiant(E,classe);break;
            case 4:verif_dispo_Classe(classe,d,heureDeb,heureFin);break;
        }
    }
    while(c!=5);
}


void AdministrationEnseignant()
{
    char *command = "cls";
    int c;
    enseignant E;
    date d;
    heure heureDeb,heureFin;
    do
    {
        printf("\n\n                                                          ------------Espace admnistration : Enseigants------------\n");
        printf("                                                                  (1) : Consulter la liste des enseigants \n");
        printf("                                                                  (2) : Ajouter un enseigant \n");
        printf("                                                                  (3) : Supprimer un enseigant \n");
        printf("                                                                  (4) : Verifier la disponibilite de l'enseignant \n");
        printf("                                                                  (5) : Retour \n");
        do
        {
            printf("\n\n                                                                      Saisir le choix : ");
            scanf("%d",&c);
            system(command);
        }
        while(c!=1 && c!=2 && c!=3 && c!=4 && c!=5);
        switch(c)
        {
            case 1:afficherListeEnseignant(E);break;
            case 2:ajoutEnseignant(E);break;
            case 3:suppressionEnseignant(E);break;
            case 4:verif_dispo_Enseignant(E,d,heureDeb,heureFin);break;
        }
    }
    while(c!=5);
}

void AdministrationDepartement()
{
    char *command = "cls";
    int c;
    departement d;
    do
    {
        printf("\n\n                                                          ------------Espace administration : Departements------------\n");
        printf("                                                                  (1) : Consulter la liste des departements \n");
        printf("                                                                  (2) : Ajouter un departement \n");
        printf("                                                                  (3) : Supprimer un departement \n");
        printf("                                                                  (4) : Retour \n");
        do
        {
            printf("\n\n                                                                      Saisir le choix : ");
            scanf("%d",&c);
            system(command);
        }
        while(c!=1 && c!=2 && c!=3 && c!=4);
        switch(c)
        {
            case 1:afficherListeDepartement();break;
            case 2:ajoutDepartement(d);break;
            case 3:suppressionDepartement(d);break;
        }
    }
    while(c!=4);
}



void AdministrationMatiere()
{
    char *command = "cls";
    int c;
    matiere m;

    do
    {
        printf("\n\n                                                          ------------Espace administration : matieres------------\n");
        printf("                                                                  (1) : Consulter la liste des matieres \n");
        printf("                                                                  (2) : Ajouter une matiere \n");
        printf("                                                                  (3) : Supprimer une matiere \n");
        printf("                                                                  (4) : Retour \n");
        do
        {
            printf("\n\n                                                                      Saisir le choix : ");
            scanf("%d",&c);
            system(command);
        }
        while(c!=1 && c!=2 && c!=3 && c!=4);
        switch(c)
        {
            case 1:afficherListeMatiere(m);break;
            case 2:ajoutMatiere(m);break;
            case 3:suppressionMatiere(m);break;
        }
    }
    while(c!=4);
}



void AdministrationSalle()
{
    char *command = "cls";
    int c;
    salle S;
    date d;
    heure heureDeb,heureFin;
    do
    {
        printf("\n\n                                                          ------------Espace administration : salles ------------\n");
        printf("                                                                  (1) : Consulter la liste des salles \n");
        printf("                                                                  (2) : Ajouter une salle \n");
        printf("                                                                  (3) : Supprimer une salle \n");
        printf("                                                                  (4) : Verifier la disponibilite de la salle \n");
        printf("                                                                  (5) : Retour \n");
        do
        {
            printf("\n\n                                                                      Saisir le choix : ");
            scanf("%d",&c);
            system(command);
        }
        while(c!=1 && c!=2 && c!=3 && c!=4 && c!=5);
        switch(c)
        {
            case 1:afficherListeSalle(S);break;
            case 2:ajoutSalle(S);break;
            case 3:suppressionSalle(S);break;
            case 4:verif_dispo_Salle(S,d,heureDeb,heureFin);break;
        }
    }
    while(c!=5);
}


