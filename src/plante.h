#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Date{
	int jour;
	int mois;
	int annee;
}Date;
typedef struct plante{ 
	char nom[30];
	char id[30];
	char type[30];
	char saison[30];
	Date d ;
	int nombre;
	
}plante;


void afficher_plante(GtkWidget *liste);
void ajouter_plante(plante t);
void rechercher_plante(char idp[30]);
void afficher_plante_rechercher(GtkWidget *liste);
void supprimer_plante(char idp[]);
void modifier_plante(plante t);
