#ifdef HAVE_CONGIG_H
# include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enregistrement.h"
#include "capteur.h"
#include <gtk/gtk.h>

enum {
EMAT,
EDATE,
EHORAIRE,
EVALEUR,
COLUMNS
};

enum {
Mat,
Valeur,
Columns
};


void afficher_enregistrement(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	date date_enreg;
	horaire horaire_enreg;
	char mat[30];
	char date[30];
	char horaire[30];
	float valeur;

  	store= NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

if (store==NULL) 
{

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("matricule",renderer,"text",EMAT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("date",renderer,"text",EDATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("horaire",renderer,"text",EHORAIRE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}
store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT);
 
f=fopen("enregistrement.txt","r");
if (f==NULL)
{
return;
}
else
 {
	f= fopen("enregistrement.txt","a+");
	while (fscanf(f," %s %s %s %f \n",mat,date,horaire,&valeur)!=EOF)
	{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,EMAT, mat, EDATE, date, EHORAIRE, horaire,EVALEUR, valeur, -1);
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}
}
//-------------------------------------------------------------
void afficher_alarmantes(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
  	char matricule[30];
	float valeur;
  int val_min;
  int val_max;
  
 
  store= NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);

if (store==NULL) 
{

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("matricule",renderer,"text",Mat, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",Valeur, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


}
store=gtk_list_store_new (Columns,G_TYPE_STRING,G_TYPE_FLOAT);
 
f=fopen("alarmante.txt","r");
if (f==NULL)
{
return;
}
else
 {
	f= fopen("alarmante.txt","a+");
	while (fscanf(f,"%s %f %d %d\n",matricule,&valeur,&val_min,&val_max)!=EOF)
	{
		if((valeur>val_min && valeur<val_min+5) || (valeur<val_max && valeur>val_max-5))
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter, Mat, matricule, Valeur, valeur,-1);
		}
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}
}
//------------------------------------------
void ajouter_enregistrement(enregistrement enr)
{
	FILE *f;
	FILE *c;
	capteur capt;
	FILE *tempo;
	FILE *a;
	FILE *atempo;
	FILE *def;
	FILE *deftemp;
	int defTest=0;
	int nbr;
	char date[30];
	char horaire[30];
	char matricule[30];
	char marqueTest[30];
	char Dmarque[30];
	float val;
// MISE A JOUR CAPTEUR.TXT
	tempo=fopen("tempo.txt","a+");
	c=fopen("capteur.txt","a+");
	def=fopen("defect.txt","a+");
	while(fscanf(c,"%s %s %s %s %d %d\n",capt.matricule,capt.marque,capt.type,capt.etat_def,&capt.val_min,&capt.val_max)!=EOF)
	{
		if(strcmp(capt.matricule,enr.matricule)==0)
		{
			if((enr.valeur<capt.val_min) || (enr.valeur>capt.val_max))
			{
				strcpy(capt.etat_def,"Defectueux");
				fprintf(def,"%s\n",capt.marque);
				
			}
			else
			{
				strcpy(capt.etat_def,"Correct");
			}
		}
		fprintf(tempo,"%s %s %s %s %d %d\n",capt.matricule,capt.marque,capt.type,capt.etat_def,capt.val_min,capt.val_max);
		
	}
	fclose(c);
	fclose(tempo);
	remove("capteur.txt");
	rename("tempo.txt","capteur.txt");
	fclose(def);
// FIN MISE A JOUR CAPTEUR.TXT
// MISE A JOUR ALARMANTE.TXT
	atempo=fopen("alatempo.txt","a+");
	a=fopen("alarmante.txt","a+");
	while(fscanf(a,"%s %f %d %d\n",capt.matricule,&val,&capt.val_min,&capt.val_max)!=EOF)
	{
		if(strcmp(capt.matricule,enr.matricule)==0)
		{
			val=enr.valeur;
			
		}
		fprintf(atempo,"%s %f %d %d\n",capt.matricule,val,capt.val_min,capt.val_max);
		
	}
	fclose(a);
	fclose(atempo);
	remove("alarmante.txt");
	rename("alatempo.txt","alarmante.txt");
// FIN MISE A JOUR ALARMANTE.TXT
	sprintf(date,"%d/%d/%d", enr.dateE.jour,enr.dateE.mois,enr.dateE.annee);
	if(enr.horaireE.minute<10){
		sprintf(horaire,"%d:0%d",enr.horaireE.heure,enr.horaireE.minute);
	}
	else
	{
	sprintf(horaire,"%d:%d",enr.horaireE.heure,enr.horaireE.minute);
	}
	
    	f=fopen("enregistrement.txt","a+b");
  	if(f!=NULL)
    	{
     	fprintf(f,"%s %s %s %f\n",enr.matricule,date,horaire,enr.valeur);
	
        fclose(f);
   	}
}



