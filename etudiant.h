#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED


typedef struct {
char nome [20];
char prenome [20];
char nomcl [10];
char ID[9] ;
}etudiant ;



void EspaceEtudiant();
etudiant lireEtudiant();
void ajoutEtudiant(etudiant e,char classe[20]);
void Afficheetudiant(etudiant e);
void afficherListeEtudiants(char classe[20]);
void suppressionEtudiant(etudiant e,char classe[20]);



#endif // ETUDIANT_H_INCLUDED
