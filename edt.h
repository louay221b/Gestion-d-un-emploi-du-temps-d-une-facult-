#ifndef EDT_H_INCLUDED
#define EDT_H_INCLUDED

#include "date.h"
#include "heure.h"
#include "matiere.h"
#include "departement.h"
#include "enseignant.h"
#include "salle.h"

void AfficherClasseEDT(char c[10]);
void AfficherEnseignantEDT(enseignant e);
void AfficherSalleEDT(salle s);
int verifClasse(char c[10],date d,heure heureDeb,heure heureFin);
int verifEns(enseignant ens,date d,heure heureDeb,heure heureFin);
int verifSal(salle s,date d,heure heureDeb,heure heureFin);
int verif_dispo_Classe(char c[20],date d,heure heureDeb,heure heureFin);
int verif_dispo_Enseignant(enseignant ens,date d,heure heureDeb,heure heureFin);
int verif_dispo_Salle(salle s,date d,heure heureDeb,heure heureFin);


#endif
