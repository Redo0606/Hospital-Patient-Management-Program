#include <stdio.h>
#include <stdlib.h>
#include "TP3.c"


int main ()
{
   /*T_Patient *pat = NULL;
    char nom [40];
    char prenom [40];
    int idpat;
    scanf("%d", &idpat);
    scanf("%s", nom);
    scanf("%s", prenom);
    pat = ajouterPatient(pat, idpat, nom, prenom);
    lirePatient(pat);*/
    char filename [250];
    T_Ordonnancement *instance;
    scanf("%s", filename);
    instance = creerInstance(filename);
    lirePatient(instance->listePatients);
    lireSoigneurs(instance->listeSoigneurs);
    char filename2 [250];
    scanf("%s", filename2);
    exportSolution(instance, filename2);
}
