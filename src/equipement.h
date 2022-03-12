#include<gtk/gtk.h>
typedef struct equipement_agricole{
char type[20];
char marque[20];
char modele[20];
char numero_serie[30];
char panne[20];
char status[20];
}equipement_agricole;
void ajouter(equipement_agricole E);
void afficher(GtkWidget *liste);
void supprimer_equip(equipement_agricole E);
void modifier(equipement_agricole E);
void recherche(char numero_serie[30],GtkWidget *liste);
void panne(equipement_agricole E);
void status(equipement_agricole E);
