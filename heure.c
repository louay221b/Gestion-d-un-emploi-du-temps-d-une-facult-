#include<stdio.h>
#include<conio.h>
#include<string.h>
#include "heure.h"

int heure_valide(heure heures)
{
	if (heures.h>23)
		return 0;
	else
		if (heures.m>59)
			return 0;
		else
			return 1;
}

heure lire_heureDeb(heure heureDeb)
{
    do
    {
	printf ("                                                                      Donner l'heure du debut:  ");
	scanf ("%d",&heureDeb.h);
	printf ("                                                                      Donner les minutes: ");
	scanf("%d",&heureDeb.m);
    }
    while(heure_valide(heureDeb)==0);
    return heureDeb;
}
heure lire_heureFin(heure heureFin)
{
    do
    {
    printf ("                                                                      Donner l'heure de la fin: ");
    scanf("%d",&heureFin.h);
	printf ("                                                                      Donner les minutes: ");
	scanf("%d",&heureFin.m);
    }
    while(heure_valide(heureFin)==0 );
    return heureFin;
}

void affiche_heure(heure heures)
{
	printf("%d:%d",heures.h,heures.m);
}
