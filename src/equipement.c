#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include "equipement.h"
enum
{
	NUMEROSERIE,
	TYPE,
	MARQUE,
	MODELE,
	PANNE,
	STATUS,
	COLUMNS
};
//=========fonction ajouter=======
void ajouter(equipement_agricole E)
{
FILE *f=NULL;
f=fopen("equipement.bin","a+b");
if(f!=NULL)
{
fwrite(&E,sizeof(equipement_agricole),1,f);
}
fclose(f);
}
//=========fonction affichage=========
void afficher(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	
	GtkListStore *store;
	equipement_agricole E;

	char numero_serie[30];
	char type[20];
	char marque[20];
	char modele[20];
	char panne[20];
	char status[20];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("NUMEROSERIE",renderer,"text",NUMEROSERIE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("MARQUE",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("MODELE",renderer,"text",MODELE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("PANNE",renderer,"text",PANNE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("STATUS",renderer,"text",STATUS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("equipement.bin","rb");

if(f==NULL)
{
	return;
}
else
{
f=fopen("equipement.bin","rb");
while(fread(&E,sizeof(equipement_agricole),1,f)!=0)
{
gtk_list_store_append (store,&iter);

gtk_list_store_set(store,&iter,NUMEROSERIE,E.numero_serie,TYPE,E.type,MARQUE,E.marque,MODELE,E.modele,PANNE,E.panne,STATUS,E.status,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
//============fonction supprimer================
void supprimer_equip(equipement_agricole E)
{
FILE *f;
FILE *g;
equipement_agricole N;
f=fopen("equipement.bin","rb");
g=fopen("nv_equipement.bin","ab");
if(f==NULL || g==NULL)
{
return;
}
else
{
while(fread(&N,sizeof(equipement_agricole),1,f)!=0)
{
if(strcmp(E.numero_serie,N.numero_serie)!=0)
fwrite(&N,sizeof(equipement_agricole),1,g);
}
fclose(f);
fclose(g);
remove("equipement.bin");
rename("nv_equipement.bin","equipement.bin");
}
}
//==========fonction recherche===============
void recherche(char num_ss[30],GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	
	GtkListStore *store;
	equipement_agricole E;

	char numero_serie[30];
	char type[20];
	char marque[20];
	char modele[20];
	char panne[20];
	char status[20];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("NUMEROSERIE",renderer,"text",NUMEROSERIE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("MARQUE",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("MODELE",renderer,"text",MODELE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("PANNE",renderer,"text",PANNE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("STATUS",renderer,"text",STATUS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("equipement.bin","rb");
if(f==NULL)
{
return;
}
else
{
f=fopen("equipement.bin","rb");
while(fread(&E,sizeof(equipement_agricole),1,f)!=0)
{
if(strcmp(E.numero_serie,num_ss)==0)
{
gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,NUMEROSERIE,E.numero_serie,TYPE,E.type,MARQUE,E.marque,MODELE,E.modele,PANNE,E.panne,STATUS,E.status,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
//=========fonction panne========
void panne(equipement_agricole E)
{
FILE *f;
FILE *g;
equipement_agricole N;
f=fopen("equipement.bin","rb");
g=fopen("nv_equipement.bin","ab");
if(f==NULL || g==NULL)
{
return;
}
else
{
while(fread(&N,sizeof(equipement_agricole),1,f)!=0)
{
if(strcmp(N.numero_serie,E.numero_serie)==0)
{
strcpy(E.panne,"oui");
fwrite(&E,sizeof(equipement_agricole),1,g);
}
else{fwrite(&N,sizeof(equipement_agricole),1,g);}
}
fclose(f);
fclose(g);
remove("equipement.bin");
rename("nv_equipement.bin","equipement.bin");
}
}
//=======fonction status========
void status(equipement_agricole E)
{
FILE *f;
FILE *g;
equipement_agricole N;
f=fopen("equipement.bin","rb");
g=fopen("nv_equipement.bin","ab");
if(f==NULL || g==NULL)
{
return;
}
else
{
while(fread(&N,sizeof(equipement_agricole),1,f)!=0)
{
if(strcmp(N.numero_serie,E.numero_serie)==0)
{
strcpy(E.status,"occupée");
fwrite(&E,sizeof(equipement_agricole),1,g);
}
else{fwrite(&N,sizeof(equipement_agricole),1,g);}
}
fclose(f);
fclose(g);
remove("equipement.bin");
rename("nv_equipement.bin","equipement.bin");
}
}

