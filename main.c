#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "etudiant.h"
#include "administration.h"
#include "date.h"
#include "heure.h"
#include "matiere.h"
#include "crenaux.h"
#include "departement.h"
#include "enseignant.h"
#include "salle.h"
#include <time.h>


void main()

{

    system("color 0D");
    time_t secondes;
    struct tm instant;

    //affichage de la date système
    time(&secondes);
    instant=*localtime(&secondes);
    printf("                                                                            %d/%d / %d:%d:%d\n\n\n", instant.tm_mday+1,
                                 instant.tm_mon+1,
                                  instant.tm_hour,
                                   instant.tm_min,
                                   instant.tm_sec);

    int c;
    char *command = "cls";
    do
    {
        printf("                                                Ministere de l'enseignement superieur et de la recherche scientifique\n                                                                  Universite de Tunis El Manar\n\n");
        printf("                                             --------------------------------------------------------------------------- \n\n");
        printf("                                                                  (1) : Espace Etudiant \n");
        printf("                                                                  (2) : Espace Administration \n");
        printf("                                                                  (3) : Espace Enseignant \n\n\n");

        do
        {
            printf("                                                                      Saisir le choix : ");
            scanf("%d",&c);
            system(command);

        }
        while(c!=1 && c!=2 && c!=3);
        switch(c)
        {
            case 1:EspaceEtudiant();break;
            case 2:EspaceAdministration();break;
            case 3:EspaceEnseignant();break;
        }
        printf("\n\n                                                      --------------------------------------------------\n\n");
    }
    while(c);

}
