#include "tp3.h"

T_Patient* ajouterPatient(T_Patient* listePatients, int idPat, char nom [40], char prenom [40])
{
  /* Création d'un nouveau patient */
  T_Patient *p = malloc(sizeof(T_Patient));
  p->id_pat = idPat;
  strcpy(p->nom, nom);
  strcpy(p->prenom, prenom);
  p->listeRendezVous = NULL;
  p->suivant = listePatients;
  return p;
}
T_Soigneur* ajouterSoigneur (T_Soigneur* listeSoigneurs, int idSoi, char nom [40], char prenom [40])
{
  /* Création d'un nouveau soigneur */
  T_Soigneur *s = malloc(sizeof(T_Soigneur));
  s->id_soi = idSoi;
  strcpy(s->nom, nom);
  strcpy(s->prenom, prenom);

  /* Insertion du nouveau soigneur en tête de liste */
  s->suivant = listeSoigneurs;
  return s;
}

T_RendezVous* ajouterRendezVous(T_RendezVous* listeRendezVous, int idSoi, int dateDebutSouhaitee,
int dateFinSouhaitee, int tempsDeplacement, char desc [125])
{
    T_RendezVous *r = malloc (sizeof (T_RendezVous));
    r->id_soi = idSoi;
    r->debut_souhaitee = dateDebutSouhaitee;
    r->fin_souhaitee = dateFinSouhaitee;
    r->temps_deplacement = tempsDeplacement;
    r->temps_deplacement = tempsDeplacement;
    strcpy(r->desc, desc);

    r->suivant = listeRendezVous;
    return r;
}

void modifierRendezVous(T_RendezVous* listeRendezVous, int idSoi, int dateDebutSouaitee, int dateFinSouaitee, int tempsDeplacement, char desc[125])
{
    T_RendezVous *r;
    r = listeRendezVous;
    while(r != 0)
    {
        if (idSoi = r->id_soi)
        {
            printf("Veuillez saisir la nouvelle date de debut du rendez-vous :\n");
            scanf("%d", &dateDebutSouaitee);
            r->debut_souhaitee = dateDebutSouaitee;
            printf("Veuillez saisir la nouvelle date de fin du rendez-vous :\n");
            scanf("%d", &dateFinSouaitee);
            r->fin_souhaitee = dateFinSouaitee;
            printf("Veuillez saisir la nouvelle description du rendez-vous :\n");
            scanf("%s", &desc);
            strcpy(r->desc, desc);
        }
        else
        {
            r = r->suivant;
        }
    }
    return r;
}

T_RendezVous* supprimerRendezVous(T_RendezVous* listeRendezVous, int idSoi)
{
    T_RendezVous *r;
    r = listeRendezVous;
    T_RendezVous *asupprimer;
    T_RendezVous *precedent;
    if (idSoi = r->id_soi)
    {
        asupprimer = r;
        r = r->suivant;
    }
    else
    {

        while(r != 0)
        {
            if (idSoi = r->id_soi)
            {
                asupprimer = r;
                precedent->suivant = asupprimer->suivant;
            }
            else
            {
                precedent = r;
                r = r->suivant;
            }
        }
    }
    free(asupprimer);
    return r;
}

T_Ordonnancement* creerInstance(char filename [250]){
    //Initialisation arguments type ordonnancement
    T_Patient* listePatients = NULL;
    T_Soigneur * listeSoigneurs = NULL;
    T_Ordonnancement* ordonnancement = NULL;
    T_RendezVous* listeRDV = NULL;
    //Initialisation variables utiles
    char ligne [200];
    int nbDePatient, nbDeSoignant, i, j, idPat, idSoi, nbRendezVous;
    Time dateDebut, dateFin, tempsDeplacement;
    T_Patient * premierPatient;
    T_RendezVous * premierRdv;
    T_Soigneur * premierSoigneur;

    //On récupère la date actuelle avec le format YYYY-MM-JJ
    char date[30];
    time_t dateAjd = time(0);
    strftime(date,30,"%Y-%m-%d", localtime(&dateAjd));

    FILE* fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Empty File Error");
        exit(EXIT_FAILURE);
    }

    fgets(ligne, 200, fp);
    sscanf(ligne, "%d %d", &nbDePatient, &nbDeSoignant);
    fflush(stdout);

    //Création de la liste de patients et liste rendez-vous
    for (i=0; i<nbDePatient; i++) {
        fflush(stdout);
        char*nomPat=malloc(sizeof(char)*40);
        char*prenomPat=malloc(sizeof(char)*40);
        fgets(ligne, 200, fp);
        sscanf(ligne, "%d %d %s %s", &idPat, &nbRendezVous, nomPat, prenomPat);

        if (!listePatients){
            premierPatient = ajouterPatient(listePatients, idPat, nomPat, prenomPat);
            listePatients = premierPatient;
        }
        else listePatients = ajouterPatient(listePatients, idPat, nomPat, prenomPat);
        listeRDV = listePatients->listeRendezVous;

        for (j=0; j<nbRendezVous; j++) {
            fflush(stdout);
            char* Une_description =malloc(sizeof(char)*125);
            fgets(ligne, 200, fp);
            sscanf(ligne, "%d %d %d %d %s", &idSoi, &dateDebut, &dateFin, &tempsDeplacement, Une_description);
            if(!listeRDV) {
                listeRDV = ajouterRendezVous(listeRDV, idSoi, dateDebut, dateFin, tempsDeplacement, Une_description);
                premierRdv = listeRDV;
            }else {
                listeRDV = ajouterRendezVous(listeRDV, idSoi, dateDebut, dateFin, tempsDeplacement, Une_description);
            }
        }
        listePatients->listeRendezVous = listeRDV;
    }

    //création liste de soignants
    for (i=0; i<nbDeSoignant; i++) {
        fflush(stdout);
        char*nomSoi=malloc(sizeof(char)*40);
        char*prenomSoi=malloc(sizeof(char)*40);
        fgets(ligne, 200, fp);
        sscanf(ligne, "%d %s %s", &idSoi, nomSoi, prenomSoi);
        if(!listeSoigneurs){
            premierSoigneur = ajouterSoigneur(listeSoigneurs, idSoi, nomSoi, prenomSoi);
            listeSoigneurs = premierSoigneur;
        }else {
            listeSoigneurs = ajouterSoigneur(listeSoigneurs, idSoi, nomSoi, prenomSoi);
        }
    }
    ordonnancement = malloc(sizeof(T_Ordonnancement));
    ordonnancement->listePatients =listePatients;
    ordonnancement->listeSoigneurs = listeSoigneurs;
    ordonnancement->date = date;
    fclose(fp);
    return ordonnancement;
}


void affecterRdV(T_RendezVous* rdv, T_Soigneur* soigneur)
{
    int stop=0;
    T_Intervalle *header=soigneur->listeIntervalle;
    while(header!=NULL && stop!=1){
        if(rdv->debut_souhaitee>=(header->debut+rdv->temps_deplacement) && rdv->fin_souhaitee<=header->fin){
            rdv->debut_affectee=rdv->debut_souhaitee;
            rdv->fin_affectee=rdv->fin_souhaitee;
            T_Intervalle * nouv=(T_Intervalle *)malloc(sizeof(T_Intervalle));
            nouv->debut=rdv->fin_affectee;
            nouv->fin=header->fin;
            nouv->suivant=header->suivant;
            header->fin=rdv->debut_affectee;
            header->suivant=nouv;
            printf("intervalle affecté");
            stop=1;
        }
        header=header->suivant;
    }
    header=soigneur->listeIntervalle;
    while(stop!=1 && header!=NULL){
        if((rdv->fin_souhaitee-rdv->debut_souhaitee)<=(header->fin)-(header->debut+rdv->temps_deplacement)){
            rdv->debut_affectee=header->debut;
            rdv->fin_affectee=(rdv->debut_affectee+(rdv->fin_souhaitee-rdv->debut_souhaitee));
            T_Intervalle * nouv=(T_Intervalle *)malloc(sizeof(T_Intervalle));
            nouv->debut=rdv->fin_affectee;
            nouv->fin=header->fin;
            nouv->suivant=header->suivant;
            header->fin=rdv->debut_affectee;
            header->suivant=nouv;
            stop=1;
        }
        header=header->suivant;
    }
    soigneur->listeIntervalle=soigneur->listeIntervalle->suivant;
}

void ordonnancer(T_Ordonnancement* solution){

    T_Patient **listepat=(T_Patient**)malloc(sizeof(T_Patient*));
    if(!listepat)exit(EXIT_FAILURE);
    listepat=solution->listePatients;


    provided_MergeSort(listepat); //etape 1

    T_Patient *header=solution->listePatients;
    while(header!=NULL){ //etape 2
        T_RendezVous *header2=header->listeRendezVous;
        while(header2!=NULL){
            T_Soigneur *soigneur=solution->listeSoigneurs;
            while(header2->id_soi!=soigneur->id_soi)soigneur=soigneur->suivant;
            affecterRdV(header2, soigneur);
        }
    }

}
void exportSolution(T_Ordonnancement* solution, char* filename)
{
    int nbrPat = 0, nbrSoi = 0, nbrRdv = 0, i, j;
    FILE *newfile;
    newfile = fopen(filename, "w+");
    T_Patient *listeP = solution -> listePatients;
    T_Soigneur *listeS = solution ->listeSoigneurs;
    T_RendezVous *rdv = listeP->listeRendezVous;
    while (listeP != NULL)
    {
        nbrPat ++;
        listeP = listeP ->suivant;
    }
    listeP = solution->listePatients;
    while (listeS != NULL)
    {
        nbrSoi ++;
        listeS = listeS->suivant;
    }
    listeS = solution->listeSoigneurs;
    fprintf(newfile, "%d %d \n", nbrPat, nbrSoi);
    fflush(stdout);
    for (i=0; i<nbrPat; i++)
    {
        rdv = listeP->listeRendezVous;
        while(rdv!=NULL)
        {
            nbrRdv ++;
            rdv = rdv->suivant;
        }
        fprintf(newfile, "%d %d \n", listeP->id_pat, nbrRdv);
        fflush(stdout);
        rdv = listeP->listeRendezVous;
        for (j=0; j<nbrRdv; j++)
        {
            fprintf(newfile, "%d %d %d %d \n", rdv->id_soi, rdv->debut_affectee, rdv->fin_affectee, rdv->temps_deplacement);
            fflush(stdout);
            rdv = rdv->suivant;
        }
      listeP = listeP->suivant;
      nbrRdv = 0;
    }
    fclose(newfile);
    return newfile;
}
void lireRdv(T_RendezVous* rdv){
    for (int i = 0; rdv != NULL; i++)
{
    printf("________________\n");
    printf("RDV %d :\n", i+1);
    printf("ID Soigneur : %d\n", rdv->id_soi);
    printf("Debut souhaite : %d\n", rdv->debut_souhaitee);
    printf("Fin souhaite : %d\n", rdv->fin_souhaitee);
    printf("Temps deplacement : %d\n", rdv->temps_deplacement);
    printf("Description : %s\n", rdv->desc);
    rdv = rdv->suivant;
}
}

 void lirePatient (T_Patient* pat){
    while (pat != NULL)
{
    printf("------------------------------\n");
    printf("Patient ID : %d\n", pat->id_pat);
    printf("Nom : %s\n", pat->nom);
    printf("Prenom : %s\n", pat->prenom);
    lireRdv(pat->listeRendezVous);
    fflush(stdout);
    pat = pat->suivant;
}
}

void lireSoigneurs (T_Soigneur* soi){
    while (soi != NULL)
{
    printf("------------------------------\n");
    printf("Soigneur ID : %d\n", soi->id_soi);
    printf("Nom : %s\n", soi->nom);
    printf("Prenom : %s\n", soi->prenom);
    soi = soi->suivant;
}
}

void menuPrincipal(void)
{
    printf("________________________________________________________________________________\n");
    printf("||    Bienvenue au menu principal d'une application d'ordonnancement medicale    ||\n");
    printf("__________________________________________________________________________________\n");
    printf("||  1. Creer une instance a partir d'un fichier.                               ||\n");
    printf("||  2. Afficher tous les patients et leurs rendez-vous.                         ||\n");
    printf("||  3. Afficher tous les soigneurs et leurs intervalles de temps disponibles.   ||\n");
    printf("||  4. Afficher un rendez-vous en indiquant id du patient et du soigneur.       ||\n");
    printf("||  5. Modifier un rendez-vous en indiquant id du patient et du soigneur.       ||\n");
    printf("||  6. Supprimer un rendez-vous en indiquant id du patient et du soigneur.      ||\n");
    printf("||  7. Ordonnancer.                                                             ||\n");
    printf("||  8. Exporter la solution d'un ordonnancement.                                ||\n");
    printf("||  9. Quitter.                                                                 ||\n");
    printf("__________________________________________________________________________________\n");

int choix, idpat, idsoi;
char answer = '1';
static T_Ordonnancement * ordonnancement;
T_Patient *pat, *copiePat;
T_Soigneur *soi, *copieSoi;
char filename [250];
scanf("%d", &choix);
switch (choix)
{
case 1 :
    while (answer != '0')
    {
        if (answer != '1')
        {
            printf("Voulez-vous creer une instance ? O = 1 / N = 0 \n");
            scanf("%c",&answer);
        }
        else
        {
            printf ("Saisissez un nom de fichier : \n");
            scanf("%s", &filename);
            if (fopen(filename, "r") == NULL)
            {
                printf ("Le fichier n'existe pas, continuer ? O = 1/ N = 0 \n");
                scanf("%c", &answer);
            }
            else
            {
                creerInstance(filename);
                answer = '0';
            }
        }
    }
    menuPrincipal();
    break;

case 2 :
    if(ordonnancement->listePatients == NULL)
    {
        menuPrincipal();
        break;
    }
    else
    {
        lirePatient(ordonnancement->listePatients);
        menuPrincipal();
        break;
    }

case 3 :
    if (ordonnancement->listeSoigneurs == NULL)
    {
        menuPrincipal();
        break;
    }
    else
    {
        lireSoigneurs(ordonnancement ->listeSoigneurs);
        menuPrincipal();
        break;
    }
case 4 :
    copiePat = ordonnancement->listePatients;
    lirePatient(copiePat);
    copiePat = ordonnancement->listePatients;
    printf("Choissisez un patient\n");
    scanf("%d", &idpat);
    copieSoi = ordonnancement->listeSoigneurs;
    lireSoigneurs(copieSoi);
    copieSoi = ordonnancement->listeSoigneurs;
    printf("Choissisez un soigneur\n");
    scanf("%d", &idsoi);
    while(copiePat->listeRendezVous->id_soi != idsoi)
    {
      copiePat->listeRendezVous = copiePat->listeRendezVous->suivant;
    }
    printf("Description du rendez-vous : %s \n", copiePat->listeRendezVous->desc);
    printf("Debut souhaite : %d\n", copiePat->listeRendezVous->debut_souhaitee);
    printf("Fin souhaitee : %d\n", copiePat->listeRendezVous->fin_souhaitee);
    printf("Debut affecte : %d\n", copiePat->listeRendezVous->debut_affectee);
    printf("Fin affectee : %d\n", copiePat->listeRendezVous->fin_affectee);
    printf("Temps de deplacement : %d\n", copiePat->listeRendezVous->temps_deplacement);
    printf("Soignant : %d \n", copiePat->listeRendezVous->id_soi);
    printf("\n");
    menuPrincipal();
    break;

case 5 :
    if(ordonnancement->listePatients == NULL)
    {
        menuPrincipal();
        break;
    }
    else
    {
        copieSoi = ordonnancement->listeSoigneurs;
        lireSoigneurs(copieSoi);
        copieSoi = ordonnancement->listeSoigneurs;
        printf("Choisissez un soigneur associé à votre rendez-vous \n");
        scanf("%d", idsoi);
        modifierRendezVous(ordonnancement->listePatients->listeRendezVous,
          idsoi,
          ordonnancement->listePatients->listeRendezVous->debut_souhaitee,
          ordonnancement->listePatients->listeRendezVous->fin_souhaitee,
          ordonnancement->listePatients->listeRendezVous->temps_deplacement,
          ordonnancement->listePatients->listeRendezVous->desc);
        menuPrincipal();
        break;
    }

case 6 :
    printf("Saisissez l'id du patient dont vous souhaitez supprimer un rdv : \n");
    scanf("%d", &idpat);
    printf("saisissez l'id du soigneur dont vous souhaitez supprimer un rdv :\n");
    scanf("%d", &idsoi);
    copiePat = ordonnancement->listePatients;
    while(copiePat != NULL && copiePat->id_pat != idpat)
    {
      copiePat = copiePat->suivant;
    }
    T_RendezVous *pntRDV = copiePat->listeRendezVous;
    while (pntRDV != NULL)
    {
        if (pntRDV->id_soi == idsoi)
        {
            printf("Voulez-vous supprimer ce rendez vous ?\n");
            printf("ID Soigneur : %d\n", pntRDV->id_soi);
            printf("Debut souhaite : %d\n", pntRDV->debut_souhaitee);
            printf("Fin souhaite : %d\n", pntRDV->fin_souhaitee);
            printf("Temps deplacement : %d\n", pntRDV->temps_deplacement);
            printf("Description : %s\n", pntRDV->desc);
            if (answer = '1')
            {
                supprimerRendezVous(ordonnancement->listePatients->listeRendezVous, idsoi);
                menuPrincipal();
                break;
            }
            if (answer = '0')
            {
                menuPrincipal();
                break;
            }
        }
    }
    printf("Aucun rendezvous trouve\n");
    menuPrincipal();
    break;

case 7 :
    ordonnancer(ordonnancement);
    menuPrincipal();
    break;
case 8 :
    printf("Saisissez le nom du fichier à exporter\n");
    scanf("%s", filename);
    exportSolution(ordonnancement, filename);
    menuPrincipal();
    break;
case 9 :
    break;
default :
    menuPrincipal();
    break;
}
}

