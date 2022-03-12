#include<gtk/gtk.h>


typedef struct capteur 
{ 
  char matricule [30] ;
  char marque[30];
  char type[30];
  char etat_def[30];  
  int val_min;
  int val_max;
}capteur;


void afficher_capteurs(GtkWidget *liste);
void ajouter_capteur(capteur);
void modifier_capteur(capteur);
void supprimer_capteur(capteur);
