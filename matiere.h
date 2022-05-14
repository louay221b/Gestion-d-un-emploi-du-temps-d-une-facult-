#ifndef MATIERE_H_INCLUDED
#define MATIERE_H_INCLUDED


typedef struct {
char nomm [50];
int coef ;
char mode ;
}matiere ;


int verif_unicite_matiere(matiere m);
matiere lireMatiere();
void ajoutMatiere(matiere m);
void afficherListeMatiere(matiere m);
void AfficheMatiere(matiere M);
void suppressionMatiere(matiere m);


#endif // MATIERE_H_INCLUDED
