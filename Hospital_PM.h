
#ifndef TP3_TP3_H
#define TP3_TP3_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// D�finir le type d'identifiant d'un soigneur comme "unsigned int"
typedef unsigned int Index_Soigneur;
// D�finir le type d'identifiant d'un patient comme "unsigned int"
typedef unsigned int Index_Patient;
// D�finir le type du temps en minute comme "unsigned int"
typedef unsigned int Time;
// D�finir une structure d'une intervalle du temps o� elle contient une date de d�but, une date de fin
// et un pointeur qui pointe l'�l�ment suivant.
typedef struct Intervalle {
    // la date d�but d'une intervalle en minute, inclus
    Time debut;
    // la date fin d'une intervalle en minute, exclus
    Time fin;
    // un pointeur du type structure Intervalle qui pointe l'�l�ment suivant.
    struct Intervalle *suivant;
} T_Intervalle;
// D�finir une structure d'un soigneur o� elle contient un identifiant unique,
// un nom et un pr�nom pr�sent� par une cha�ne de caract�re,
// une liste d'intervalles du temps disponible,
// et un pointeur qui pointe l'�l�ment suivant.
typedef struct Soigneur{
    // un identifiant unique d'un soigneur.
    Index_Soigneur id_soi;
    // le nom d'un soigneur (Max 40 caract�res)
    char* nom;
    // le prenom d'un soigneur (Max 40 caract�res)
    char* prenom;
    // une liste d'intervalle du temps disponbile
    T_Intervalle *listeIntervalle;
    // un pointeur du type structure Soigneur qui pointe l'�l�ment suivant.
    struct Soigneur * suivant;
} T_Soigneur;
// D�finir une structure d'un RdV m�dical o� elle contient une description br�ve,
// une date de d�but souhait�e, une date de fin souhait�e, une date de d�but affect�e, une date de fin affect�e,
// le temps de d�placement depuis le rendez-vous pr�c�dent, un identifiant du soigneur associ�, un pointeur qui pointe l'�l�ment suivant.
typedef struct RendezVous{
    // une description br�ve (Max 125 caract�res)
    char*desc;
    // la date de d�but souhait�e en minutes, inclus
    Time debut_souhaitee;
    // la date de fin souhait�e en minutes, exclus
    Time fin_souhaitee;
    // la date de d�but affect�e en minutes, inclus
    Time debut_affectee;
    // la date de fin affect�e en minutes, exclus
    Time fin_affectee;
    // le temps de d�placement depuis le RdV pr�c�dent, s'il existe; z�ro sinon.
    Time temps_deplacement;
    // l'identifiant d'un soigneur associ�.
    Index_Soigneur id_soi;
    // un pointeur du type structure RendezVous qui pointe l'�l�ment suivant.
    struct RendezVous* suivant;
} T_RendezVous;

// D�finir une structure d'un patient o� elle contient un identifiant unique,
// un nom et un pr�nom pr�sent� par une cha�ne de caract�re,
// une liste de RdV m�dicaux,
// et un pointeur qui pointe l'�l�ment suivant.
typedef struct Patient{
    // un identifiant unique d'un patient.
    Index_Patient id_pat;
    // le nom d'un patient (Max 40 caract�res)
    char* nom;
    // le nom d'un patient (Max 40 caract�res)
    char* prenom;
    // la liste de RdV m�dicaux.
    T_RendezVous *listeRendezVous;
    // un pointeur du type structure Patient qui pointe l'�l�ment suivant.
    struct Patient* suivant;
} T_Patient;

// D�finir une structure d'un ordonnancement o� elle contient une date de cr�ation, une liste de soigneurs, et une liste de patients.
typedef struct Ordonnancement{
    // la date de cr�ation d'un ordonnancement, en forme "AAAA-MM-JJ".
    char* date;
    // une liste de soigneurs.
    T_Soigneur*listeSoigneurs;
    // une liste de patients.
    T_Patient *listePatients;
} T_Ordonnancement;

/**
 * Fonction offerte.
 * @brief Ajout d�un soigneur, o� la liste des intervalles de temps disponibles pour un nouveau soigneur
 * est initialis�e avec un seul intervalle [0, inf[.
 * @param listeSoigneurs une liste de soigneurs laquelle ne doit pas �tre vide.
 * @param idSoi un identifiant d'un soigneur.
 * @param nom le nom d'un sogineur.
 * @param prenom le pr�nom d'un soigneur.
 */
void provided_ajouterSoigneur(T_Soigneur* listeSoigneurs, Index_Soigneur idSoi, char* nom, char* prenom);
/**
 * Fonction offerte.
 * @brief Ajout d'un patient, o� la liste de rendez-vous m�dicaux pour un nouveau patient est initialement vide.
 * @param listePatients une liste de patients laquelle ne doit pas �tre vide.
 * @param idPat un identifiant d'un patient.
 * @param nom le nom d'un patient.
 * @param prenom le pr�nom d'un patient.
 */
void provided_ajouterPatient(T_Patient* listePatients, Index_Patient idPat, char* nom, char* prenom) ;
/**
 * Fonction offerte.
 * @brief  jout d�un rendez-vous m�dical pour un patient.
 * @param listeRdV une liste de Rendezvous laquelle ne doit pas �tre vide.
 * @param idSoi un identifiant d'un soigneur associ�.
 * @param dateDebutSouhaitee  la date de d�but souhait�e d'un RdV.
 * @param dateFinSouhaitee  la date de fin souhait�e d'un RdV.
 * @param tempsDeplacement la temps de d�placement depuis un RdV pr�c�dent.
 * @param desc une discription br�ve.
 */
void provided_ajouterRendezVous(T_RendezVous* listeRdV, Index_Soigneur idSoi, Time dateDebut, Time dateFin, Time tempsDeplacement, char* desc) ;
/**
 * Fonction offerte.
 * @brief Modification d� un rendez-vous m�dical pour un patient par une date, le temps de d�placement ou une description nouvelle�:
 * @param listeRdV une liste de Rendezvous laquelle ne doit pas �tre vide.
 * @param idSoi un identifiant d'un soigneur associ�.
 * @param dateDebutSouhaitee la date de d�but souhait�e d'un RdV.
 * @param dateFinSouhaitee la date de fin souhait�e d'un RdV.
 * @param tempsDeplacement la temps de d�placement depuis un RdV pr�c�dent.
 * @param desc une discription br�ve.
 */
void provided_modifierRendezVous(T_RendezVous* listeRdV, Index_Soigneur idSoi, Time dateDebut, Time dateFin, Time tempsDeplacement, char* desc) ;
/**
 * Fonction offerte.
 * @brief Suppression d�un rendez-vous m�dical pour un patient en donnant l�identifiant du soigneur correspondant.
 * Si un rendez-vous, ni premier ni dernier, est enlev�, le temps de d�placement du traitement suivant doit �tre mis � jour.
 * Par exemple, un patient ayant trois rendez-vous�: rendez-vous 1 chez le soigneur A,
 * rendez-vous 2 chez le soigneur B et rendez-vous 3 chez le soigneur C, temps de d�placement de 1 � 2 de 30 mn,
 * temps de d�placement de 2 � 3 de 40 mn, le temps de d�placement de 1 � 3 est d�fini
 * par sqrt(30^2+40^2)=50mn quand le rendez-vous 2 est supprim�.
 * @param listeRdV une liste de RdV.
 * @param idSoi identifiant d'un soigneur.
 * @return un pointeur vers la t�te de la liste de RdV m�dicaux apr�s une suppression.
 */
T_RendezVous* provided_supprimerRendezVous(T_RendezVous* listeRdV, Index_Soigneur idSoi) ;

/**
 * Fonction offerte.
 * @brief Afficher tous les soigneurs et leurs intervalles de temps disponibles
 * @param listeSoigneurs une liste de soigneurs.
 */
void provided_affichage_Soigneurs(T_Soigneur* listeSoigneurs);

/**
 * Fonction offerte.
 * @brief Afficher tous les patients et leurs rendez-vous
 * @param listePatients une liste de patients.
 */
void provided_affichage_Patients(T_Patient* listePatients);

/**
 * Fonction offerte.
 * @brief Afficher un rendez-vous en indiquant l�identifiant du patient et le soigneur correspondant
 * @param listePatients une liste de patients
 * @param idPat identifiant d'un patient assoici� d'un RdV � chercher.
 * @param idSoi identifiant d'un soigneur assoici� d'un RdV � chercher.
 */
void provided_affichage_RendezVous(T_Patient* listePatients, Index_Patient idPat, Index_Soigneur idSoi);

/**
 * Fonction offerte.
 * @brief Cr�er une instance de l�ordonnancement en important � partir d�un fichier.
 * @param filename le nom d'un fichier import�.
 * @return un pointeur vers l�instance.
 */
T_Ordonnancement* provided_creerInstance(char* filename);

/**
 * Fonction offerte.
 * @brief Affectation d�un rendez-vous en fonction des intervalles de temps disponibles d�un soigneur
 * (mettre � jour la date de d�but affect�e et la date de fin affect�e du rendez-vous )�
 * @param rdv un RdV.
 * @param soigneur un soigneur.
 */
void provided_affecterRdV(T_RendezVous* rdv, T_Soigneur* soigneur);
/**
 * Fonction offerte.
 * @brief Ordonnancer les rendez-vous des patients en fonction des intervalles de temps disponibles
 * pour l�ensemble des soigneurs en minimisant la somme des temps d�attente des patients
 * (le temps d�attente est calcul� par la date de d�but affect�e � la date de d�but souhait�e).
 * L�algorithme glouton d'ordonnancement en minimisant la somme du temps d�attente des patients�se construit comme suit :
 * �tape 1�: Trier les patients par ordre d�croissant de dur�e totale des rendez-vous
 *  (la dur�e d�un rendez-vous est calcul�e par la date de fin souhait�e � la date de d�but souhait�e)
 * �tape 2�: Affecter les rendez-vous des patients dans l�ordre ci-dessus aux intervalles de temps disponible des soigneurs.
 * @param solution un instance
 */
void provided_ordonnancer(T_Ordonnancement* solution);
/**
 * Fonction offerte.
 * @brief Exporter la solution d�un ordonnancement.
 * Le nom du fichier export� a sufix de la date de cr�ation  d�un ordonnancement, par exemple filename=�solution.txt�,
 * et la date de creation est �2020-10-13�, donc le nom de ficher export� est �solution.txt.2020-10-13.txt�.
 * @param solution une solution d'un ordonnancement.
 * @param filename le nom d'un ficher export�.
 */
void provided_exportSolution(T_Ordonnancement* solution, char* filename);
/**
 * Fonction offerte.
 * @brief Compter le nombre de patients.
 * @param listePatients la liste de patients.
 * @return le nombre de soigneurs
 */
unsigned int provided_compter_nb_patients(T_Patient* listePatients);
/**
 * Fonction offerte.
 * @brief Compter le nombre de soigneurs.
 * @param listeSoigneurs la liste de soigneurs.
 * @return le nombre de soigneurs
 */
unsigned int provided_compter_nb_soigneurs(T_Soigneur* listeSoigneurs);
/**
 * Fonction offerte.
 * @brief Compter le nombre de RdV par un patient donn�.
 * @param id_pat identifiant d'un patient.
 * @param listePatients la lsite de patients.
 * @return le nombre de RdV correspondant.
 */
unsigned int provided_compter_nb_Rdv_par_patient(Index_Patient id_pat, T_Patient* listePatients);
/**
 * Fonction offerte.
 * @brief Compter le nombre de RdV par un soigneur donn�.
 * @param id_soi identifiant d'un soigneur.
 * @param listePatients la lsite de patients.
 * @return le nombre de RdV correspondant.
 */
unsigned int provided_compter_nb_Rdv_par_soigneur(Index_Soigneur id_soi, T_Patient* listePatients);


/**
 * Fonction offerte.
 * @brief un menu principal du programme.
 */
void provided_menu();

/**
 * @brief Ajout d�un soigneur, o� la liste des intervalles de temps disponibles pour un nouveau soigneur
 * est initialis�e avec un seul intervalle [0, inf[.
 * @param listeSoigneurs une liste de soigneurs laquelle ne doit pas �tre vide.
 * @param idSoi un identifiant d'un soigneur.
 * @param nom le nom d'un sogineur.
 * @param prenom le pr�nom d'un soigneur.
 */
T_Soigneur* ajouterSoigneur (T_Soigneur* listeSoigneurs, int idSoi, char nom [40], char prenom [40]);

/**
 * @brief Ajout d'un patient, o� la liste de rendez-vous m�dicaux pour un nouveau patient est initialement vide.
 * @param listePatients une liste de patients laquelle ne doit pas �tre vide.
 * @param idPat un identifiant d'un patient.
 * @param nom le nom d'un patient.
 * @param prenom le pr�nom d'un patient.
 */
T_Patient* ajouterPatient(T_Patient* listePatients, int idPat, char nom [40], char prenom [40]);

/**
 * @brief Ajout d�un rendez-vous m�dical pour un patient.
 * @param listeRdV une liste de Rendezvous laquelle ne doit pas �tre vide.
 * @param idSoi un identifiant d'un soigneur associ�.
 * @param dateDebutSouhaitee  la date de d�but souhait�e d'un RdV.
 * @param dateFinSouhaitee  la date de fin souhait�e d'un RdV.
 * @param tempsDeplacement la temps de d�placement depuis un RdV pr�c�dent.
 * @param desc une discription br�ve.
 */
T_RendezVous* ajouterRendezVous(T_RendezVous* listeRendezVous, int idSoi, int dateDebutSouhaitee, int dateFinSouhaitee, int tempsDeplacement, char desc [125]);

/**
 * @brief Modification d� un rendez-vous m�dical pour un patient par une date, le temps de d�placement ou une description nouvelle�:
 * @param listeRdV une liste de Rendezvous laquelle ne doit pas �tre vide.
 * @param idSoi un identifiant d'un soigneur associ�.
 * @param dateDebutSouhaitee la date de d�but souhait�e d'un RdV.
 * @param dateFinSouhaitee la date de fin souhait�e d'un RdV.
 * @param tempsDeplacement la temps de d�placement depuis un RdV pr�c�dent.
 * @param desc une discription br�ve.
 */
void modifierRendezVous(T_RendezVous* listeRendezVous, int idSoi, int dateDebutSouaitee, int dateFinSouaitee, int tempsDeplacement, char desc[125]);

/**
 * @brief Suppression d�un rendez-vous m�dical pour un patient en donnant l�identifiant du soigneur correspondant.
 * Si un rendez-vous, ni premier ni dernier, est enlev�, le temps de d�placement du traitement suivant doit �tre mis � jour.
 * Par exemple, un patient ayant trois rendez-vous�: rendez-vous 1 chez le soigneur A,
 * rendez-vous 2 chez le soigneur B et rendez-vous 3 chez le soigneur C, temps de d�placement de 1 � 2 de 30 mn,
 * temps de d�placement de 2 � 3 de 40 mn, le temps de d�placement de 1 � 3 est d�fini
 * par sqrt(30^2+40^2)=50mn quand le rendez-vous 2 est supprim�.
 * @param listeRdV une liste de RdV.
 * @param idSoi identifiant d'un soigneur.
 * @return un pointeur vers la t�te de la liste de RdV m�dicaux apr�s une suppression.
 */
T_RendezVous* supprimerRendezVous(T_RendezVous* listeRendezVous, int idSoi);

/**
 * @brief Afficher tous les soigneurs et leurs intervalles de temps disponibles
 * @param listeSoigneurs une liste de soigneurs.
 */
void affichage_Soigneurs(T_Soigneur* listeSoigneurs);

/**
 * @brief Afficher tous les patients et leurs rendez-vous
 * @param listePatients une liste de patients.
 */
void affichage_Patients(T_Patient* listePatients);

/**
 * @brief Afficher un rendez-vous en indiquant l�identifiant du patient et le soigneur correspondant
 * @param listePatients une liste de patients
 * @param idPat identifiant d'un patient assoici� d'un RdV � chercher.
 * @param idSoi identifiant d'un soigneur assoici� d'un RdV � chercher.
 */
void affichage_RendezVous(T_Patient* listePatients, Index_Patient idPat, Index_Soigneur idSoi);

void lireRdv(T_RendezVous* rdv);
void lirePatient(T_Patient* pat);
void lireSoigneurs(T_Soigneur* soi);

/**
 * @brief Cr�er une instance de l�ordonnancement en important � partir d�un fichier.
 * @param filename le nom d'un fichier import�.
 * @return un pointeur vers l�instance.
 */
T_Ordonnancement* creerInstance(char* filename);

/**
 * @brief Affectation d�un rendez-vous en fonction des intervalles de temps disponibles d�un soigneur
 * (mettre � jour la date de d�but affect�e et la date de fin affect�e du rendez-vous )�
 * @param rdv un RdV.
 * @param soigneur un soigneur.
 */
void affecterRdV(T_RendezVous* rdv, T_Soigneur* soigneur);

/**
 * @brief Ordonnancer les rendez-vous des patients en fonction des intervalles de temps disponibles
 * pour l�ensemble des soigneurs en minimisant la somme des temps d�attente des patients
 * (le temps d�attente est calcul� par la date de d�but affect�e � la date de d�but souhait�e).
 * L�algorithme glouton d'ordonnancement en minimisant la somme du temps d�attente des patients�se construit comme suit :
 * �tape 1�: Trier les patients par ordre d�croissant de dur�e totale des rendez-vous
 *  (la dur�e d�un rendez-vous est calcul�e par la date de fin souhait�e � la date de d�but souhait�e)
 * �tape 2�: Affecter les rendez-vous des patients dans l�ordre ci-dessus aux intervalles de temps disponible des soigneurs.
 * @param solution un instance
 */
void ordonnancer(T_Ordonnancement* solution);

/**
 * @brief Exporter la solution d�un ordonnancement.
 * Le nom du fichier export� a sufix de la date de cr�ation  d�un ordonnancement, par exemple filename=�solution.txt�,
 * et la date de creation est �2020-10-13�, donc le nom de ficher export� est �solution.txt.2020-10-13.txt�.
 * @param solution une solution d'un ordonnancement.
 * @param filename le nom d'un ficher export�.
 */
void exportSolution(T_Ordonnancement* solution, char* filename);

/**
 * @brief menu principal du programme.
 */
void menuPrincipal(void);

/**
 * Fonction offerte
 * @brief Calculer la somme de duration de tous les RdV.
 * @param patient un pointeur qui pointe un patient.
 * @return le temps total de RdV.
 */

Time provided_sommeDeDurationRendezVous(T_Patient* patient);
T_Patient * provided_SortedMerge(T_Patient * a, T_Patient * b);
void provided_FrontBackSplit(T_Patient * source, T_Patient ** frontRef, T_Patient ** backRef);
void provided_MergeSort(T_Patient ** headRef);
#endif //TP3_TP3_H
