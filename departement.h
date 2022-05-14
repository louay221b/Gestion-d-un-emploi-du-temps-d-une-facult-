#ifndef DEPARTEMENT_H_INCLUDED
#define DEPARTEMENT_H_INCLUDED



typedef struct {
char nomDep[25];
}departement ;



int verif_unicite_dep(departement d);
departement lireDepartement();
void ajoutDepartement(departement d);
void afficherListeDepartement();
void AfficheDepartement(departement E);
void suppressionDepartement(departement d);


#endif // DEPARTEMENT_H_INCLUDED
