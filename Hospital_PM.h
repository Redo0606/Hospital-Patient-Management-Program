
#ifndef HOSPITAL_PM_H
#define HOSPITAL_PM_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Defining Caregiver ID as "unsigned int"
typedef unsigned int Index_Soigneur;
// Defining Patient ID as "unsigned int"
typedef unsigned int Index_Patient;
// Defining Time in minutes as "unsigned int"
typedef unsigned int Time;
// Defining a structure Intervalle
typedef struct Intervalle {
    // la date début d'une intervalle en minute, inclus
    Time debut;
    // la date fin d'une intervalle en minute, exclus
    Time fin;
    // un pointeur du type structure Intervalle qui pointe l'élément suivant.
    struct Intervalle *suivant;
} T_Intervalle;
// Defining the Caregiver Type
typedef struct Soigneur{
    // Caregiver unique ID
    Index_Soigneur id_soi;
    // Caregiver LastName (Max 40 caracters)
    char* nom;
    // Caregiver FirstName (Max 40 caractères)
    char* prenom;
    // Linked List of available intervals
    T_Intervalle *listeIntervalle;
    // Caregiver type pointer pointing to the next caregiver on the list.
    struct Soigneur * suivant;
} T_Soigneur;
// Appointment type structure
typedef struct RendezVous{
    // Brief Description
    char*desc;
    // Wanted start date
    Time debut_souhaitee;
    // Wanted end date
    Time fin_souhaitee;
    // Given start date
    Time debut_affectee;
    // Given end date
    Time fin_affectee;
    // Travel time
    Time temps_deplacement;
    // Associated caregiver ID
    Index_Soigneur id_soi;
    // Appointment type pointer pointing to the next appointment on the list.
    struct RendezVous* suivant;
} T_RendezVous;

// Patient type structure
typedef struct Patient{
    // Unique patient ID
    Index_Patient id_pat;
    // Patient First Name
    char* nom;
    // Patient Last Name
    char* prenom;
    // List of medical appointments
    T_RendezVous *listeRendezVous;
    // Patient type pointer pointing to the next patient on the list
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
