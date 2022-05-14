#ifndef HEURE_H_INCLUDED
#define HEURE_H_INCLUDED
typedef struct {
int h ;
int m ;

} heure ;


int heure_valide(heure heures);
heure lire_heureDeb(heure heureDeb);
heure lire_heureFin(heure heureFin);
void affiche_heure(heure heures);

#endif
