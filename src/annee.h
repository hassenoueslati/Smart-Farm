#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char annee[10] ;
	float temperature;

}annees;

void afficher_annee(GtkWidget *liste);
void annee_la_plus_seche();
void afficher_annee_seche();
