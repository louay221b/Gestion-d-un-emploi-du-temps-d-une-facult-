#ifndef ENSEIGNANT_H_INCLUDED
#define ENSEIGNANT_H_INCLUDED

#include "matiere.h"

typedef struct{
char noms [20];
char prenoms [20];
matiere mat ;
char ID[9];
}enseignant ;



int verifCIN(char ch[20]);
void EspaceEnseignant();
enseignant lireEnseignant();
void ajoutEnseignant(enseignant E);
void Afficheenseignants(enseignant E);
void afficherListeEnseignant();
void suppressionEnseignant(enseignant E);


#endif // ENSEIGNANT_H_INCLUDED
