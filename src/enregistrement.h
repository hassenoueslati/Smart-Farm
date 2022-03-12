#include<gtk/gtk.h>


typedef struct date {
int jour;
int mois;
int annee;
}date;
typedef struct horaire {
int heure;
int minute;
}horaire;
typedef struct enregistrement{
char matricule[30];
date dateE;
horaire horaireE;
float valeur;
}enregistrement;


void afficher_enregistrement(GtkWidget *liste);
void ajouter_enregistrement(enregistrement);
void afficher_alarmantes(GtkWidget *liste);
