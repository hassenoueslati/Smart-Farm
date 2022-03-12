#include <gtk/gtk.h>
GtkWidget *gestion;
typedef struct troupeaux troupeaux ;
struct troupeaux{
char id[30];
char sexe[30];
char type[30];
char date[30];
char prix[9];
};


void
on_connect_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_decon_emp_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_plant_emp_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_troup_emp_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_equip_emp_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_client_emp_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_capt_emp_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ouvr_emp_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_troup_admin_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_defect_admin_clicked                (GtkWidget       *button,
                                        gpointer         user_data);


void
on_seche_admin_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_decon_admin_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_capt_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouter_capt_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modifier_capt_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supprimer_capt_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_gestion_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_enreg_clicked                       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajout_ok_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_ajout_clicked                (GtkWidget       *button,
                                        gpointer         user_data);


void
on_modif_ok_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_modif_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supprim_ok_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_rb_ajout1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb_ajout2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb_modif1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb_modif2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview_enreg_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajout_enreg_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_enreg_ok_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_enreg_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_alarm_admin_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_alarm_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_client_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button14_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button5_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_capt_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button7_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button8_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button9_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button10_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_emp_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_rech_admin_emp_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_affich_admin_emp_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajout_admin_emp_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modif_admin_emp_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supp_admin_emp_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_gest_admin_emp_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajout_ok_emp_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_annuler_ajout_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supp_ok_emp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_annuler_supp_emp_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modif_emp_ok_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_annuler_modif_emp_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_kkkk_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_plant_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supprimer_plant_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modifier_plant_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_afficher_plant_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajouter_plant_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_plant_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_chercher_plant_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_ajout_plant_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajout_plant_ok_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_modifier_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modifier_ok_plant_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_supprimer_plant_clicked      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supp_ok_plant_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_annee_seche_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_annee_plus_seche_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_afficher_annee_clicked              (GtkWidget       *button,
                                        gpointer         user_data);


void
on_retour_annee_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_equip_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_equip_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercher_equip_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_afficher_equip_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supp_equip_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modifier_equip_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_equip_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajouter_equip_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modif_ok_equip_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_modif_equip_clicked          (GtkWidget       *button,
                                        gpointer         user_data);


void
on_AFAC_clicked                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_BF_clicked                          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonAJ_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonCHR_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_SUP_clicked                         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_CHAB_clicked                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_MeillOUVR_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobuttonH_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonF_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MQAB_clicked                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonMOD_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_ouvr_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Ajoutertroupeaux_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_troup_clicked                (GtkWidget       *button,
                                        gpointer         user_data);



void
on_Modifiertroupeaux_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_troup_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_cherchertroupeaux_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_bmodifier_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_bsupprimer_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_bafficher_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);
