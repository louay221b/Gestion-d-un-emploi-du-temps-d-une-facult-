#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "date.h"


 ////////////////datevalide////////////////////
 int date_valide(date d)
 {
 	if (d.mois<=12 && d.mois>=1 )
 	{
 		switch (d.mois)
 		{
 				case 1:case 3:case 5:case 7:case 8:case 10 : case 12 :
 					if (d.jour <=31 && d.jour >=1)
 					return 1;
 					else
 					return 0;break;
 				case 4: case 6: case 9: case 11:
 				if (d.jour <=30 && d.jour >=1)
 					return 1;
 					else
 					return 0;break;
 				case 2:
 				  if (d.annee%4==0)
 				  {
 				  	if (d.jour <=29 && d.jour >=1)
 				  	return 1;
 				  	else
 				  	return 0;
				   }
				   else
				   {

				   if (d.jour <=28 && d.jour >=1)
				    return 1;
				    return 0;
			}
		 }
	 }
	 else
	 return 0;
 }


 /////////liredate/////////////////
date lire_date( date d)
{
    char *command = "cls";
    do
    {
	printf ("\n\n                                                                      donner le jour: ");
	scanf ("%d",&d.jour);
	printf ("\n\n                                                                      donner le mois: ");
	scanf("%d",&d.mois);
	printf ("\n\n                                                                      donner l'annee: ");
	scanf("%d",&d.annee);
    }
    while(date_valide(d)==0);
    return d;
    system(command);
}


