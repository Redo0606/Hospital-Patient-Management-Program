
#ifndef TP3_TP3_H
#define TP3_TP3_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Définir le type d'identifiant d'un soigneur comme "unsigned int"
typedef unsigned int Index_Soigneur;
// Définir le type d'identifiant d'un patient comme "unsigned int"
typedef unsigned int Index_Patient;
// Définir le type du temps en minute comme "unsigned int"
typedef unsigned int Time;
// Définir une structure d'une intervalle du temps où elle contient une date de début, une date de fin
// et un pointeur qui pointe l'élément suivant.
typedef struct Intervalle {
    // la date début d'une intervalle en minute, inclus
    Time debut;
    // la date fin d'une intervalle en minute, exclus
    Time fin;
    // un pointeur du type structure Intervalle qui pointe l'élément suivant.
    struct Intervalle *suivant;
} T_Intervalle;
// Définir une structure d'un soigneur où elle contient un identifiant unique,
// un nom et un prénom présenté par une chaîne de caractère,
// une liste d'intervalles du temps disponible,
// et un pointeur qui pointe l'élément suivant.
typedef struct Soigneur{
    // un identifiant unique d'un soigneur.
    Index_Soigneur id_soi;
    // le nom d'un soigneur (Max 40 caractères)
    char* nom;
    // le prenom d'un soigneur (Max 40 caractères)
    char* prenom;
    // une liste d'intervalle du temps disponbile
    T_Intervalle *listeIntervalle;
    // un pointeur du type structure Soigneur qui pointe l'élément suivant.
    struct Soigneur * suivant;
} T_Soigneur;
// Définir une structure d'un RdV médical où elle contient une description brève,
// une date de début souhaitée, une date de fin souhaitée, une date de début affectée, une date de fin affectée,
// le temps de déplacement depuis le rendez-vous précédent, un identifiant du soigneur associé, un pointeur qui pointe l'élément suivant.
typedef struct RendezVous{
    // une description brève (Max 125 caractères)
    char*desc;
    // la date de début souhaitée en minutes, inclus
    Time debut_souhaitee;
    // la date de fin souhaitée en minutes, exclus
    Time fin_souhaitee;
    // la date de début affectée en minutes, inclus
    Time debut_affectee;
    // la date de fin affectée en minutes, exclus
    Time fin_affectee;
    // le temps de déplacement depuis le RdV précédent, s'il existe; zéro sinon.
    Time temps_deplacement;
    // l'identifiant d'un soigneur associé.
    Index_Soigneur id_soi;
    // un pointeur du type structure RendezVous qui pointe l'élément suivant.
    struct RendezVous* suivant;
} T_RendezVous;

// Définir une structure d'un patient où elle contient un identifiant unique,
// un nom et un prénom présenté par une chaîne de caractère,
// une liste de RdV médicaux,
// et un pointeur qui pointe l'élément suivant.
typedef struct Patient{
    // un identifiant unique d'un patient.
    Index_Patient id_pat;
    // le nom d'un patient (Max 40 caractères)
    char* nom;
    // le nom d'un patient (Max 40 caractères)
    char* prenom;
    // la liste de RdV médicaux.
    T_RendezVous *listeRendezVous;
    // un pointeur du type structure Patient qui pointe l'élément suivant.
    struct Patient* suivant;
} T_Patient;

// Définir une structure d'un ordonnancement où elle contient une date de création, une liste de soigneurs, et une liste de patients.
typedef struct Ordonnancement{
    // la date de création d'un ordonnancement, en forme "AAAA-MM-JJ".
    char* date;
    // une liste de soigneurs.
    T_Soigneur*listeSoigneurs;
    // une liste de patients.
    T_Patient *listePatients;
} T_Ordonnancement;

/**
 * Fonction offerte.
 * @brief Ajout d’un soigneur, où la liste des intervalles de temps disponibles pour un nouveau soigneur
 * est initialisée avec un seul intervalle [0, inf[.
 * @param listeSoigneurs une liste de soigneurs laquelle ne doit pas être vide.
 * @param idSoi un identifiant d'un soigneur.
 * @param nom le nom d'un sogineur.
 * @param prenom le prénom d'un soigneur.
 */
void provided_ajouterSoigneur(T_Soigneur* listeSoigneurs, Index_Soigneur idSoi, char* nom, char* prenom);
/**
 * Fonction offerte.
 * @brief Ajout d'un patient, où la liste de rendez-vous médicaux pour un nouveau patient est initialement vide.
 * @param listePatients une liste de patients laquelle ne doit pas être vide.
 * @param idPat un identifiant d'un patient.
 * @param nom le nom d'un patient.
 * @param prenom le prénom d'un patient.
 */
void provided_ajouterPatient(T_Patient* listePatients, Index_Patient idPat, char* nom, char* prenom) ;
/**
 * Fonction offerte.
 * @brief  jout d’un rendez-vous médical pour un patient.
 * @param listeRdV une liste de Rendezvous laquelle ne doit pas être vide.
 * @param idSoi un identifiant d'un soigneur associé.
 * @param dateDebutSouhaitee  la date de début souhaitée d'un RdV.
 * @param dateFinSouhaitee  la date de fin souhaitée d'un RdV.
 * @param tempsDeplacement la temps de déplacement depuis un RdV précédent.
 * @param desc une discription brève.
 */
void provided_ajouterRendezVous(T_RendezVous* listeRdV, Index_Soigneur idSoi, Time dateDebut, Time dateFin, Time tempsDeplacement, char* desc) ;
/**
 * Fonction offerte.
 * @brief Modification d’ un rendez-vous médical pour un patient par une date, le temps de déplacement ou une description nouvelle :
 * @param listeRdV une liste de Rendezvous laquelle ne doit pas être vide.
 * @param idSoi un identifiant d'un soigneur associé.
 * @param dateDebutSouhaitee la date de début souhaitée d'un RdV.
 * @param dateFinSouhaitee la date de fin souhaitée d'un RdV.
 * @param tempsDeplacement la temps de déplacement depuis un RdV précédent.
 * @param desc une discription brève.
 */
void provided_modifierRendezVous(T_RendezVous* listeRdV, Index_Soigneur idSoi, Time dateDebut, Time dateFin, Time tempsDeplacement, char* desc) ;
/**
 * Fonction offerte.
 * @brief Suppression d’un rendez-vous médical pour un patient en donnant l’identifiant du soigneur correspondant.
 * Si un rendez-vous, ni premier ni dernier, est enlevé, le temps de déplacement du traitement suivant doit être mis à jour.
 * Par exemple, un patient ayant trois rendez-vous : rendez-vous 1 chez le soigneur A,
 * rendez-vous 2 chez le soigneur B et rendez-vous 3 chez le soigneur C, temps de déplacement de 1 à 2 de 30 mn,
 * temps de déplacement de 2 à 3 de 40 mn, le temps de déplacement de 1 à 3 est défini
 * par sqrt(30^2+40^2)=50mn quand le rendez-vous 2 est supprimé.
 * @param listeRdV une liste de RdV.
 * @param idSoi identifiant d'un soigneur.
 * @return un pointeur vers la tête de la liste de RdV médicaux après une suppression.
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
 * @brief Afficher un rendez-vous en indiquant l’identifiant du patient et le soigneur correspondant
 * @param listePatients une liste de patients
 * @param idPat identifiant d'un patient assoicié d'un RdV à chercher.
 * @param idSoi identifiant d'un soigneur assoicié d'un RdV à chercher.
 */
void provided_affichage_RendezVous(T_Patient* listePatients, Index_Patient idPat, Index_Soigneur idSoi);

/**
 * Fonction offerte.
 * @brief Créer une instance de l’ordonnancement en important à partir d’un fichier.
 * @param filename le nom d'un fichier importé.
 * @return un pointeur vers l’instance.
 */
T_Ordonnancement* provided_creerInstance(char* filename);

/**
 * Fonction offerte.
 * @brief Affectation d’un rendez-vous en fonction des intervalles de temps disponibles d’un soigneur
 * (mettre à jour la date de début affectée et la date de fin affectée du rendez-vous ) 
 * @param rdv un RdV.
 * @param soigneur un soigneur.
 */
void provided_affecterRdV(T_RendezVous* rdv, T_Soigneur* soigneur);
/**
 * Fonction offerte.
 * @brief Ordonnancer les rendez-vous des patients en fonction des intervalles de temps disponibles
 * pour l’ensemble des soigneurs en minimisant la somme des temps d’attente des patients
 * (le temps d’attente est calculé par la date de début affectée – la date de début souhaitée).
 * L’algorithme glouton d'ordonnancement en minimisant la somme du temps d’attente des patients se construit comme suit :
 * Étape 1 : Trier les patients par ordre décroissant de durée totale des rendez-vous
 *  (la durée d’un rendez-vous est calculée par la date de fin souhaitée – la date de début souhaitée)
 * Étape 2 : Affecter les rendez-vous des patients dans l’ordre ci-dessus aux intervalles de temps disponible des soigneurs.
 * @param solution un instance
 */
void provided_ordonnancer(T_Ordonnancement* solution);
/**
 * Fonction offerte.
 * @brief Exporter la solution d’un ordonnancement.
 * Le nom du fichier exporté a sufix de la date de création  d’un ordonnancement, par exemple filename=’solution.txt’,
 * et la date de creation est ‘2020-10-13’, donc le nom de ficher exporté est ‘solution.txt.2020-10-13.txt’.
 * @param solution une solution d'un ordonnancement.
 * @param filename le nom d'un ficher exporté.
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
 * @brief Compter le nombre de RdV par un patient donné.
 * @param id_pat identifiant d'un patient.
 * @param listePatients la lsite de patients.
 * @return le nombre de RdV correspondant.
 */
unsigned int provided_compter_nb_Rdv_par_patient(Index_Patient id_pat, T_Patient* listePatients);
/**
 * Fonction offerte.
 * @brief Compter le nombre de RdV par un soigneur donné.
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
 * @brief Ajout d’un soigneur, où la liste des intervalles de temps disponibles pour un nouveau soigneur
 * est initialisée avec un seul intervalle [0, inf[.
 * @param listeSoigneurs une liste de soigneurs laquelle ne doit pas être vide.
 * @param idSoi un identifiant d'un soigneur.
 * @param nom le nom d'un sogineur.
 * @param prenom le prénom d'un soigneur.
 */
T_Soigneur* ajouterSoigneur (T_Soigneur* listeSoigneurs, int idSoi, char nom [40], char prenom [40]);

/**
 * @brief Ajout d'un patient, où la liste de rendez-vous médicaux pour un nouveau patient est initialement vide.
 * @param listePatients une liste de patients laquelle ne doit pas être vide.
 * @param idPat un identifiant d'un patient.
 * @param nom le nom d'un patient.
 * @param prenom le prénom d'un patient.
 */
T_Patient* ajouterPatient(T_Patient* listePatients, int idPat, char nom [40], char prenom [40]);

/**
 * @brief Ajout d’un rendez-vous médical pour un patient.
 * @param listeRdV une liste de Rendezvous laquelle ne doit pas être vide.
 * @param idSoi un identifiant d'un soigneur associé.
 * @param dateDebutSouhaitee  la date de début souhaitée d'un RdV.
 * @param dateFinSouhaitee  la date de fin souhaitée d'un RdV.
 * @param tempsDeplacement la temps de déplacement depuis un RdV précédent.
 * @param desc une discription brève.
 */
T_RendezVous* ajouterRendezVous(T_RendezVous* listeRendezVous, int idSoi, int dateDebutSouhaitee, int dateFinSouhaitee, int tempsDeplacement, char desc [125]);

/**
 * @brief Modification d’ un rendez-vous médical pour un patient par une date, le temps de déplacement ou une description nouvelle :
 * @param listeRdV une liste de Rendezvous laquelle ne doit pas être vide.
 * @param idSoi un identifiant d'un soigneur associé.
 * @param dateDebutSouhaitee la date de début souhaitée d'un RdV.
 * @param dateFinSouhaitee la date de fin souhaitée d'un RdV.
 * @param tempsDeplacement la temps de déplacement depuis un RdV précédent.
 * @param desc une discription brève.
 */
void modifierRendezVous(T_RendezVous* listeRendezVous, int idSoi, int dateDebutSouaitee, int dateFinSouaitee, int tempsDeplacement, char desc[125]);

/**
 * @brief Suppression d’un rendez-vous médical pour un patient en donnant l’identifiant du soigneur correspondant.
 * Si un rendez-vous, ni premier ni dernier, est enlevé, le temps de déplacement du traitement suivant doit être mis à jour.
 * Par exemple, un patient ayant trois rendez-vous : rendez-vous 1 chez le soigneur A,
 * rendez-vous 2 chez le soigneur B et rendez-vous 3 chez le soigneur C, temps de déplacement de 1 à 2 de 30 mn,
 * temps de déplacement de 2 à 3 de 40 mn, le temps de déplacement de 1 à 3 est défini
 * par sqrt(30^2+40^2)=50mn quand le rendez-vous 2 est supprimé.
 * @param listeRdV une liste de RdV.
 * @param idSoi identifiant d'un soigneur.
 * @return un pointeur vers la tête de la liste de RdV médicaux après une suppression.
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
 * @brief Afficher un rendez-vous en indiquant l’identifiant du patient et le soigneur correspondant
 * @param listePatients une liste de patients
 * @param idPat identifiant d'un patient assoicié d'un RdV à chercher.
 * @param idSoi identifiant d'un soigneur assoicié d'un RdV à chercher.
 */
void affichage_RendezVous(T_Patient* listePatients, Index_Patient idPat, Index_Soigneur idSoi);

void lireRdv(T_RendezVous* rdv);
void lirePatient(T_Patient* pat);
void lireSoigneurs(T_Soigneur* soi);

/**
 * @brief Créer une instance de l’ordonnancement en important à partir d’un fichier.
 * @param filename le nom d'un fichier importé.
 * @return un pointeur vers l’instance.
 */
T_Ordonnancement* creerInstance(char* filename);

/**
 * @brief Affectation d’un rendez-vous en fonction des intervalles de temps disponibles d’un soigneur
 * (mettre à jour la date de début affectée et la date de fin affectée du rendez-vous ) 
 * @param rdv un RdV.
 * @param soigneur un soigneur.
 */
void affecterRdV(T_RendezVous* rdv, T_Soigneur* soigneur);

/**
 * @brief Ordonnancer les rendez-vous des patients en fonction des intervalles de temps disponibles
 * pour l’ensemble des soigneurs en minimisant la somme des temps d’attente des patients
 * (le temps d’attente est calculé par la date de début affectée – la date de début souhaitée).
 * L’algorithme glouton d'ordonnancement en minimisant la somme du temps d’attente des patients se construit comme suit :
 * Étape 1 : Trier les patients par ordre décroissant de durée totale des rendez-vous
 *  (la durée d’un rendez-vous est calculée par la date de fin souhaitée – la date de début souhaitée)
 * Étape 2 : Affecter les rendez-vous des patients dans l’ordre ci-dessus aux intervalles de temps disponible des soigneurs.
 * @param solution un instance
 */
void ordonnancer(T_Ordonnancement* solution);

/**
 * @brief Exporter la solution d’un ordonnancement.
 * Le nom du fichier exporté a sufix de la date de création  d’un ordonnancement, par exemple filename=’solution.txt’,
 * et la date de creation est ‘2020-10-13’, donc le nom de ficher exporté est ‘solution.txt.2020-10-13.txt’.
 * @param solution une solution d'un ordonnancement.
 * @param filename le nom d'un ficher exporté.
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
