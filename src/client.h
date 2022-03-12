#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct
{ 
	char nom[50];
	char prenom[50];
	char cin[50];
	char adresse[50];
	char email[50];
	char telephone[50];
	int Age;
	char Sexe[50];

}client;


void afficher_client(GtkWidget *liste);
void ajouter_client(client a);
void rechercher(char cin[50]);
void afficher_client_rechercher(GtkWidget *liste);
void supprimer(char cinp[50]);
void modifier_client(client a);
