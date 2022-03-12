#ifdef HAVE_CONGIG_H
# include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"
#include <gtk/gtk.h>
enum {
EMAT,
EMARQUE,
ETYPE,
EDEF,
EMIN,
EMAX,
COLUMNS
};



void afficher_capteurs(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
  char matricule[30];
  char marque[30];
  char type[30];
  char etat_def[30];
  int val_min;
  int val_max;
  
 
  store= NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);

if (store==NULL) 
{

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("matricule",renderer,"text",EMAT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("etat_def",renderer,"text",EDEF, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("val_min",renderer,"text",EMIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("val_max",renderer,"text",EMAX, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}
store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT);
 
f=fopen("capteur.txt","r");
if (f==NULL)
{
return;
}
else
 {
	f= fopen("capteur.txt","a+");
	while (fscanf(f,"%s %s %s %s %d %d\n",matricule,marque,type,etat_def,&val_min,&val_max)!=EOF)
	{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, EMAT, matricule, EMARQUE, marque, ETYPE, type, EDEF, etat_def, EMIN, val_min, EMAX, val_max,-1);
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}
}


void ajouter_capteur(capteur capt)
{
	
    FILE *f;
    FILE *a;
	float v=0;
	if(strcmp(capt.type,"Humidite")==0){
		capt.val_min=10;
		capt.val_max=90;	
	}
	else{
		capt.val_min=0;
		capt.val_max=45;
	}
	
    	f=fopen("capteur.txt","a+b");
  	if(f!=NULL)
    	{
     	fprintf(f,"%s %s %s %s %d %d\n",capt.matricule,capt.marque,capt.type,capt.etat_def,capt.val_min,capt.val_max);
	
        fclose(f);
   	}
	a=fopen("alarmante.txt","a+b");
  	if(a!=NULL)
    	{
     	fprintf(a,"%s %f %d %d\n",capt.matricule,v,capt.val_min,capt.val_max);
	
        fclose(a);
   	}
}

void modifier_capteur(capteur c)
{
	capteur capt;
	FILE *f, *tempo;
	f=fopen("capteur.txt","a+");
	tempo=fopen("tempo.txt","a+");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %d\n",capt.matricule,capt.marque,capt.type,capt.etat_def,&capt.val_min,&capt.val_max)!=EOF)
		{
			if(strcmp(capt.matricule,c.matricule)==0)
			{
				if(strcmp(c.type,"Humidite")==0){
					c.val_min=10;
					c.val_max=90;	
				}
				else{
					c.val_min=0;
					c.val_max=45;
				}
  				strcpy(c.etat_def,capt.etat_def);
     				fprintf(tempo,"%s %s %s %s %d %d\n",c.matricule,c.marque,c.type,c.etat_def,c.val_min,c.val_max);
   			
			}
			else{
				fprintf(tempo,"%s %s %s %s %d %d\n",capt.matricule,capt.marque,capt.type,capt.etat_def,capt.val_min,capt.val_max);
			}
		}
	}
	fclose(f);
	fclose(tempo);
	remove("capteur.txt");
	rename("tempo.txt","capteur.txt");
}

void supprimer_capteur(capteur capt)
{
	FILE *f=NULL, *tempo;
	capteur c;
	f=fopen("capteur.txt","a+");
	tempo=fopen("tempo.txt","a+");
	if (f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %d\n",c.matricule,c.marque,c.type,c.etat_def,&c.val_min,&c.val_max)!=EOF)
	
		{
			if(strcmp(c.matricule,capt.matricule)!=0)
			{
				fprintf(tempo,"%s %s %s %s %d %d\n",c.matricule,c.marque,c.type,c.etat_def,c.val_min,c.val_max);
	
			}
		}
	}
fclose(f);
fclose(tempo);
remove("capteur.txt");
rename("tempo.txt","capteur.txt");
	
}






