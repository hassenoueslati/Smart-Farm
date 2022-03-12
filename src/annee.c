#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "annee.h"

enum
{
ANNEE,
TEMPERATURE,
COLUMN
};

//////////////////////////////////////////////////////////
void afficher_annee(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char annee[10] ;
float temperature ;

FILE *f;
store=NULL;
store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ANNEE",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("TEMPERATURE",renderer,"text",TEMPERATURE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_FLOAT);

f=fopen("temperature.txt","r");
if (f == NULL ) {return;}
else
{
while (fscanf(f,"%s %f ",annee,&temperature)!=EOF) {

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,ANNEE,annee,TEMPERATURE,temperature,-1);
}
fclose(f);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
}
}

////////////////////////////////////////////////////////////
void annee_la_plus_seche()
{
FILE* f; 
FILE* f1;
annees a;
float temperature;
char annee[10] ;
float max;

f=fopen("temperature.txt","r");
f1=fopen("anneeseche1.txt","w");
max=0;
char v[10] ;
while (fscanf(f,"%s %f \n",a.annee,&a.temperature)!=EOF)
{
if (max<a.temperature)
{
max=a.temperature;
strcpy(v,a.annee);
}
}
fprintf(f1,"%s %f \n",v,max);


/*while (fscanf(f,"%s %f \n",a.annee,&a.temperature)!=EOF)
{
n=n+1 ;
}
float arr[n];
int i=0;
while (fscanf(f,"%s %f \n",a.annee,&a.temperature)!=EOF)
{
arr[i]=a.temperature;
i=i+1;
}
max=arr[0];
	for (i=1;i<n;i++)
		{
			if (arr[i]>max)
		{
			max=arr[i] ;
		}
		}

while (fscanf(f,"%s %f \n",a.annee,&a.temperature)!=EOF)
{
if (max==a.temperature) 
{
fprintf(f1,"%s %f \n",a.annee,a.temperature);
}
}*/
fclose(f);
fclose(f1);

remove("anneeseche.txt");
rename ("anneeseche1.txt","anneeseche.txt");
}
///////////////////////////////////////////////////////////
void afficher_annee_seche(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char v[10];
float max ;
       
 store=NULL;

        FILE *h;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ANNEE",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("TEMPERATURE",renderer,"text",TEMPERATURE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		
	}


	store=gtk_list_store_new (COLUMN, G_TYPE_STRING,G_TYPE_FLOAT);

	h = fopen("anneeseche.txt","r");

	if(h==NULL)
	{

		return;
	}
	else

	{ h = fopen("anneeseche.txt","a+");
              while(fscanf(h,"%s %f\n",v,&max)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,ANNEE,v,TEMPERATURE,max, -1); 
		}
		fclose(h);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
