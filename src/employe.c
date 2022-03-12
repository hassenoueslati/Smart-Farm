#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "employe.h"
//fonction afficher employe:
enum
{
NOM,
PRENOM,
CIN,
ADRESSE,
EMAIL,
TELEPHONE,
AGE,
SEXE,
COLUMN
};
void afficher_employe(GtkWidget *liste)
{


GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[50];
char prenom[50];
char cin[50];
char adresse[50];
char email[50];
char telephone[50];
int Age;
char Sexe [50];

FILE *f;
store=NULL;
store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("NOM",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("PRENOM",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ADRESSE",renderer,"text",ADRESSE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("EMAIL",renderer,"text",EMAIL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes("TELEPHONE",renderer,"text",TELEPHONE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("AGE",renderer,"text",AGE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("SEXE",renderer,"text",SEXE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	
}
	store=gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);

f=fopen("employe.txt","r");
if (f == NULL ) {return;}
else
{
while (fscanf(f,"%s %s %s %s %s %s %d %s",nom,prenom,cin,adresse,email,telephone,&Age,Sexe)!=EOF) {

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,NOM,nom,PRENOM,prenom,CIN,cin,ADRESSE,adresse,EMAIL,email,TELEPHONE,telephone,AGE,Age,SEXE,Sexe,-1);
}
fclose(f);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
}
}
//fonction ajouter employe :
void ajouter_employe(employe a)
{
 
  FILE *f;
  f=fopen("employe.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s  %s %d %s \n ",a.nom ,a.prenom ,a.cin ,a.adresse ,a.email ,a.telephone,a.Age,a.Sexe) ;
  fclose(f);
  }
}
//fonction chercher employe selon le critére CIN :

void rechercher_employe(char cin[20])  
{
FILE* f; 
FILE* f1;
char nom1[50];
char prenom1[50];
char cin1[50];
char adresse1[50];
char email1[50];
char telephone1[50];
int Age1;
char Sexe1[50];


f=fopen("employe.txt","r");
f1=fopen("employecher.txt","w");
while (fscanf(f,"%s %s %s %s %s %s %d %s \n",nom1,prenom1,cin1,adresse1,email1,telephone1,&Age1,Sexe1)!=EOF)
	{
		if (strcmp(cin,cin1)==0)
		{
		fprintf(f1,"%s %s %s %s %s %s %d %s\n",nom1,prenom1,cin1,adresse1,email1,telephone1,Age1,Sexe1);
		}
	}
	fclose(f);
	fclose(f1);
remove("employechercher.txt");
rename ("employecher.txt","employechercher.txt");
}
//affichage de l'employe à chercher :
void afficher_employe_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char nom[50];
char prenom[50];
char cin[50];
char adresse[50];
char email[50];
char telephone[50];
int Age;
char Sexe[50];
       
 store=NULL;

        FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  NOM", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" PRENOM", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" CIN", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" ADRESSE", renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" EMAIL", renderer, "text",EMAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		column = gtk_tree_view_column_new_with_attributes("  TELEPHONE", renderer, "text",
TELEPHONE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" AGE", renderer, "text",AGE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" SEXE", renderer, "text",SEXE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();

	}

	store=gtk_list_store_new (COLUMN, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);

	f = fopen("employechercher.txt","r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("employechercher.txt","a+");
              while(fscanf(f,"%s %s %s %s %s %s %d %s\n",nom,prenom,cin,adresse,email,telephone,&Age,Sexe)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM,nom,PRENOM,prenom,CIN,cin,ADRESSE,adresse,EMAIL,email,
TELEPHONE,telephone,AGE,Age,SEXE,Sexe,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
void supprimer_employe(char cinp[50])
{
char nom1[40];
char prenom1[40];
char adresse1[40];
char email1[40];
char telephone1[40];
char cin1[40];
int Age1;
char Sexe1[40];
FILE *l;
FILE *t;
l=fopen("employe.txt","a+");
t=fopen("employe1.txt","w");
while (fscanf(l,"%s %s %s %s %s %s %d %s\n",nom1,prenom1,cin1,adresse1,email1,telephone1,&Age1,Sexe1)!=EOF)
	{
		if(strcmp(cinp,cin1)!=0)
		{
		 fprintf(t,"%s %s %s %s %s %s %d %s \n",nom1,prenom1,cin1,adresse1,email1,telephone1,Age1,Sexe1);
             
		}
  	}
	fclose(l);
        fclose(t);			
        remove("employe.txt");
        rename("employe1.txt","employe.txt");

}
// fonction modifier employe
void modifier_employe(employe a)
{
FILE *f;
FILE *t;
char nom[50];
char prenom[50];
char cin[50];
char adresse[50];
char email[50];
char telephone[50];
int Age;
char Sexe[50];

f=fopen("employe.txt","r");
t=fopen("utilis.txt","a");

    if (f!=NULL || t!=NULL)
    {
    while(fscanf(f,"%s %s %s %s %s %s %d %s\n",nom,prenom,cin,adresse,email,telephone,&Age,Sexe)!=EOF)
    {

        if(strcmp(a.cin,cin)==0)
        {
            fprintf(t,"%s %s %s %s %s  %s %d %s\n ",a.nom ,a.prenom ,a.cin ,a.adresse ,a.email ,a.telephone,a.Age,a.Sexe) ;
        }
        else
            fprintf(t,"%s %s %s %s %s %s %d %s\n",nom,prenom,cin,adresse,email,telephone,Age,Sexe);
        }
    }

fclose(t);
fclose(f);
remove("employe.txt");
rename("utilis.txt","employe.txt");
}
