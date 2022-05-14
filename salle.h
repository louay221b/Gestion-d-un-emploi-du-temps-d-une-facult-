#ifndef SALLE_H_INCLUDED
#define SALLE_H_INCLUDED


#include "date.h"
#include "heure.h"
#include "matiere.h"
#include "departement.h"
#include "enseignant.h"



typedef struct {
int num_salle ;
char salle_cren[20] ;
}salle ;


int verif_unicite_salle(salle s);
salle lireSalle();
void ajoutSalle(salle S);
void afficherListeSalle();
void Affichesalle(salle S);
void suppressionSalle(salle S);


#endif // SALLE_H_INCLUDED
