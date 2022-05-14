#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
typedef struct {
int annee  ;
int jour ;
int mois ;
} date ;

date lire_date( date d);
int date_valide(date d);

#endif // DATE_H_INCLUDED
