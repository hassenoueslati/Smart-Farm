#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "plante.h"

enum
{
NOM,
ID,
TYPE,
SAISON,
JOURPLANTATION,
MOISPLANTATION,
ANNEEPLANTATION,
NOMBRE,
COLUMN
};
////////////////////////////////////////////////////////////////////////
//Ajout d'une plante
void ajouter_plante(plante t)
{
 
  FILE *f;
  f=fopen("plante.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %d %d %d %d\n ",t.nom ,t.id ,t.type ,t.saison ,t.d.jour ,t.d.mois ,t.d.annee ,t.nombre) ;
  fclose(f);
  }
}
///////////////////////////////////////////////////////////////
//Affichage d'une plante
void afficher_plante(GtkWidget *liste)
{


GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[30];
char id[30];
char type[30];
char saison[30];
Date d ;
int nombre;

FILE *f;
store=NULL;
store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("NOM",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",TYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("SAISON",renderer,"text",SAISON,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("JOURPLANTATION",renderer,"text",JOURPLANTATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("MOISPLANTATION",renderer,"text",MOISPLANTATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ANNEEPLANTATION",renderer,"text",ANNEEPLANTATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes("NOMBRE",renderer,"text",NOMBRE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	
}
	store=gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

f=fopen("plante.txt","r");
if (f == NULL ) {return;}
else
{
while (fscanf(f,"%s %s %s %s %d %d %d %d",nom,id,type,saison,&d.jour,&d.mois,&d.annee,&nombre)!=EOF) {

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,NOM,nom,ID,id,TYPE,type,SAISON,saison,JOURPLANTATION,d.jour,MOISPLANTATION,d.mois,ANNEEPLANTATION,d.annee,NOMBRE,nombre,-1);
}
fclose(f);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
}
}

////////////////////////////////////////////////////////////////////////
//Rechercher d'une plante
void rechercher_plante(char idp[30])  
{
FILE* f; 
FILE* f1;
char nom1[30];
char id1[30];
char type1[30];
char saison1[30];
int jour1;
int mois1;
int annee1;
int nombre1;

f=fopen("plante.txt","r");
f1=fopen("plantecher.txt","w");
while (fscanf(f,"%s %s %s %s %d %d %d %d \n",nom1,id1,type1,saison1,&jour1,&mois1,&annee1,&nombre1)!=EOF)
	{
		if (strcmp(idp,id1)==0)
		{
		fprintf(f1,"%s %s %s %s %d %d %d %d\n",nom1,id1,type1,saison1,jour1,mois1,annee1,nombre1);
		}
	}
	fclose(f);
	fclose(f1);
remove("plantechercher.txt");
rename ("plantecher.txt","plantechercher.txt");
}
//////////////////////////////////////////////////////////////////////////
//Affichage d'une plante à chercher 
void afficher_plante_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char nom[30];
char id[30];
char type[30];
char saison[30];
Date d;
int nombre;
       
 store=NULL;

        FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("NOM",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",TYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("SAISON",renderer,"text",SAISON,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("JOURPLANTATION",renderer,"text",JOURPLANTATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("MOISPLANTATION",renderer,"text",MOISPLANTATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ANNEEPLANTATION",renderer,"text",ANNEEPLANTATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("NOMBRE",renderer,"text",NOMBRE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}


	store=gtk_list_store_new (COLUMN, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT ,G_TYPE_INT, G_TYPE_INT ,G_TYPE_INT);

	f = fopen("plantechercher.txt","r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("plantechercher.txt","a+");
              while(fscanf(f,"%s %s %s %s %d %d %d %d\n",nom,id,type,saison,&d.jour,&d.mois,&d.annee,&nombre)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,NOM,nom,ID,id,TYPE,type,SAISON,saison,JOURPLANTATION,d.jour,MOISPLANTATION,d.mois,ANNEEPLANTATION,d.annee,NOMBRE,nombre, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
/////////////////////////////////////////////////////////////////////////
//Modification des coordonnées une plante
void modifier_plante(plante t)
{
FILE *f;
FILE *a;
char nom[30];
char id[30];
char type[30];
char saison[30];
int jour;
int mois;
int annee;
int nombre;


f=fopen("plante.txt","r");
a=fopen("plante1.txt","a");

    if (f!=NULL || a!=NULL)
    {
    while(fscanf(f,"%s %s %s %s %d %d %d %d\n",nom,id,type,saison,&jour,&mois,&annee,&nombre)!=EOF)
    {

        if(strcmp(t.id,id)==0)
        {
            fprintf(a,"%s %s %s %s %d %d %d %d \n ",t.nom ,t.id ,t.type ,t.saison ,t.d.jour ,t.d.mois ,t.d.annee ,t.nombre) ;
        }
        else
            fprintf(a,"%s %s %s %s %d %d %d %d\n",nom,id,type,saison,jour,mois,annee,nombre);
        }
    }

fclose(a);
fclose(f);
remove("plante.txt");
rename("plante1.txt","plante.txt");
}

///////////////////////////////////////////////////////////////////////
//Supression d'une plante
void supprimer_plante(char idp[])
{
char nom1[30];
char id1[30];
char type1[30];
char saison1[30];
int jour1;
int mois1;
int annee1;
int nombre1;
FILE *l;
FILE *a;
l=fopen("plante.txt","a+");
a=fopen("plante1.txt","w");
while (fscanf(l,"%s %s %s %s %d %d %d %d\n",nom1,id1,type1,saison1,&jour1,&mois1,&annee1,&nombre1)!=EOF)
	{
		if(strcmp(idp,id1)!=0)
		{
		 fprintf(a,"%s %s %s %s %d %d %d %d\n",nom1,id1,type1,saison1,jour1,mois1,annee1,nombre1);
             
		}
  	}
	fclose(l);
        fclose(a);			
        remove("plante.txt");
        rename("plante1.txt","plante.txt");
}

