#ifndef CRENEAU_H_INCLUDED
#define CRENEAU_H_INCLUDED
#include"matiere.h"
#include"heure.h"
//#include"classe.h"
#include"enseignant.h"
#include"salle.h"
//typedef enum type{td,tp,cours,TD,TP,COURS} type_cr;
typedef struct creneau {
    matiere matiere;
    heure Debut;
    heure Fin;
//    classe Classe;
    enseignant ens;
    salle Salle;
  //  type Type;
}creneau;


creneau saisircreneau();
void affichecreneau(creneau cre );




#endif // CRENEAU_H_INCLUDED
