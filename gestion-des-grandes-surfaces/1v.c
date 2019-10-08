#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct liste_des_caissiers{
    int code_caissier;
    char nom_caissier[200];
    int code_caisse;
    struct liste_des_caissiers * next;
}liste_des_caissiers;

liste_des_caissiers *head_sur_caissiers = NULL;
int lastValueCodeCaissier = 0;
int nombreCaissiers = 0;

typedef struct liste_des_rayons{
    char nom_rayon[200];
    char etat[200];
    int code_rayon;
    int nombre_de_produits;
    struct liste_des_rayons *next;
}liste_des_rayons;

liste_des_rayons *head_sur_rayons = NULL;
int lastValueCodeRayon = 0;
int nombreRayons = 0;


typedef struct liste_des_produits{
    char nom_produit[200];
    int code_produit, stock_produit;
    float prix_Unitaire;
    char nom_rayon[200];
    int tva;
    struct liste_des_produits *next;
}liste_des_produits;

liste_des_produits *head_sur_produits = NULL;
int lastValueCodeProduit = 0;
int nombreProduits = 0;

typedef struct liste_des_commandes{
    int code_commande;
    int code_produit;
    char date_commande[200], nom_commande[200];
    int quantite_commande;
    struct liste_des_commandes *next;
}liste_des_commandes;

liste_des_commandes *head_sur_commandes = NULL;
int lastValueCodeCommande = 0;
int nombreCommandes = 0;

typedef struct liste_des_tickets{
    int code_caiss;
    int code_ticket;
    int code_produit;
    char date_ticket[200];
    int quantite_ticket;
    char payement[200];
    float grandTotal;
    struct liste_des_tickets *next;
}liste_des_tickets;

typedef struct LigneTicket{
    char nomproduit[200];
    int quantiteproduit;
    float prixu;
    struct LigneTicket *next;
}Ticket;

typedef struct chiffre{
    int codecaisse;
    char datecaisse[200];
    float grandtot;
    struct chiffre *next;
}liste_des_chiffres;

liste_des_chiffres *head_sur_chiffres = NULL;

Ticket *head = NULL;
liste_des_tickets *head_sur_tickets = NULL;
int lastValueCodeTicket = 0;
int nombreTickets = 0;
int nombreChiffres = 0;
int cc = 0;
char nomProduitTicket[200];
float prixUnitaireTicket = 0;
int qteEnStockProduit = 0;
void ajouterLigneTicket(int qte_vendue);
int searchProduitTicket(int codeRecherche);
float AfficherDetailTicket();

void openChiffres();
void openCaissiers();
void openProduits();
void openRayons();
void openCommandes();
void openTickets();

void AfficherCommandes();
void AfficherProduits();
void AfficherRayons();
void AfficherCaissiers();

void AfficherMenuRayons();
void AfficherMenuProduits();
void AfficherMenuCommandes();
void AfficherMenuCaissiers();
void AfficherMenuCaisses();
void AfficherMenuGestionStock();
void AfficherMenuProduits();
void AfficherMenuPrincipal();

void ajouterProduit();
void ajouterRayon();
void ajouterTicket();
void ajouterCommande();
void ajouterCaissier();

void modifierProduit();
void modifierCommande();
void modifierRayon();
void modifierCaissier();

void rechercherProduit();
void rechercherCommande();
void rechercherRayon();
void rechercherCaissier();
void logincaissier(int codeCaisse, int codeCaissier);

void supprimerProduit();
void supprimerTicket();
void supprimerCommande();
void supprimerRayon();
void supprimerCaissier();

void modifier_Produit_rayon();
void reapp_stock();
void displaayProduits();
void chiffreAffaireCaisse();
void chiffreAffaireJour();

int main(){
    AfficherMenuPrincipal();
    return 0;
}

void AfficherMenuPrincipal(){
    char choix = 'A', chaine_choix[20];
    int a, codeCaisse, codeCaissier;
    while ( choix != 'Q' ){
        printf("\n\n    ************************************************************************************************** \n");
        printf("     * Bienvenue a QuickManagement Application de gestion de Caisse, et Stocks d'une Grande Surface * \n");
        printf("    ************************************************************************************************** \n\n\n");
        printf("      Entrez || 1 Si Vous etes Administrateur || 2 Si Vous etes Caissier || Q pour Quitter ");
        printf("\n\n        login           :    ");
        scanf("%s", chaine_choix);
        choix = chaine_choix[0];
        switch ( choix ){
            case '1' :
                printf("        Password        :    ");
                scanf("%d", &a);
                if( a == 333333){
                    AfficherMenuGestionStock();
                    break ;
                }else{
                    printf("\n\nVotre Password est Incorrect Recommencez\n\n");
                    break ;
                }
            case '2' :
                printf("        Votre Caisse    :    C");
                scanf("%d", &codeCaisse);
                cc = codeCaisse;
                printf("        Password        :    ");
                scanf("%d", &codeCaissier);
                logincaissier(codeCaisse, codeCaissier);
                    break;
            case 'Q' :
                printf("\n\n          Au revoir \n\n");
                break ;
            default:
                printf("              Choix invalide! Recommencez\n\n");
                break;
            }
    }
}

void AfficherMenuCaisses(){
    char choix = 'A', chaine_choix[20];
    openProduits();
    openTickets();
    openChiffres();
    while ( choix != 'R' ){
        printf("\n\nMenu Caisse\n");
        printf("------------------------------------------------------------------------\n");
        printf("1. Etablir un Ticket\n");
        printf("2. Supprimer un Ticket\n");
        printf("3. Chiffre d'Affaire Par Caisse\n");
        printf("4. Chiffre D'affaire par Jours\n");
        printf("R. Revenir au menu principal\n");
        printf("------------------------------------------------------------------------\n\n");
        printf("Entrez votre choix : ");
        scanf("%s", chaine_choix);
        choix = chaine_choix[0];
        switch( choix ){
            case '1':
                ajouterTicket();
                break;
            case '2':
                supprimerTicket();
                break;
            case '3':
                chiffreAffaireCaisse();
                break;
            case '4':
                chiffreAffaireJour();
                break;
            case 'R':
                AfficherMenuPrincipal();
                break;
            default:
                printf("Choix invalide! Recommencer\n\n");
                break;
            break;
        }
    }
}

void AfficherMenuGestionStock(){
    char choix = 'A', chaine_choix[20];
    while ( choix != 'R' ){
        printf("\n\nMenu Gestion de Stock\n");
        printf("------------------------------------------------------------------------\n");
        printf("1. Produits\n");
        printf("2. Rayons\n");
        printf("3. Commandes\n");
        printf("4. Caissiers\n");
        printf("R. Revenir au menu principal\n");
        printf("------------------------------------------------------------------------\n\n");
        printf("Entrez votre choix : ");
        scanf("%s", chaine_choix);
        choix = chaine_choix[0];
        switch( choix ){
            case '1':
                AfficherMenuProduits();
                break;
            case '2':
                AfficherMenuRayons();
                break;
            case '3':
                AfficherMenuCommandes();
                break;
            case '4':
                AfficherMenuCaissiers();
                break;
            case 'R':
                AfficherMenuPrincipal();
                break;
            default:
                printf("Choix invalide! Recommencer\n\n");
                break;
            break;
        }
    }
}

void AfficherMenuCaissiers(){
    char choix = 'A', chaine_choix[20];
    openProduits();
    while ( choix != 'R' ){
        printf("\n\nMenu Caissiers\n");
        printf("------------------------------------------------------------------------\n");
        printf("1. Ajouter un caissier\n");
        printf("2. Modifier un caissier\n");
        printf("3. Supprimer un caissier\n");
        printf("4. Rechercher un caissier\n");
        printf("5. Consulter les caissiers\n");
        printf("R. Revenir au menu gestion de stock\n");
        printf("------------------------------------------------------------------------\n\n");
        printf("Entrez votre choix : ");
        scanf("%s", chaine_choix);
        choix = chaine_choix[0];
        switch( choix ){
            case '1':
                ajouterCaissier();
                break;
            case '2':
                modifierCaissier();
                break;
            case '3':
                supprimerCaissier();
                break;
            case '4':
                rechercherCaissier();
                break;
            case '5':
                AfficherCaissiers();
                break;
            case 'R':
                AfficherMenuGestionStock();
                break;
            default:
                printf("Choix invalide! Recommencer\n\n");
                break;
            break;
        }
    }
}


void AfficherMenuProduits(){
    char choix = 'A', chaine_choix[20];
    openProduits();
    while ( choix != 'R' ){
        printf("\n\nMenu Produits\n");
        printf("------------------------------------------------------------------------\n");
        printf("1. Ajouter un Produit\n");
        printf("2. Modifier un Produit\n");
        printf("3. Supprimer un Produit\n");
        printf("4. Rechercher un Produit\n");
        printf("5. Consulter les Produits\n");
        printf("6. Trouver Les Produits necessitant un Reaprovisionnement\n");
        printf("R. Revenir au menu gestion de stock\n");
        printf("------------------------------------------------------------------------\n\n");
        printf("Entrez votre choix : ");
        scanf("%s", chaine_choix);
        choix = chaine_choix[0];
        switch( choix ){
            case '1':
                ajouterProduit();
                break;
            case '2':
                modifierProduit();
                break;
            case '3':
                supprimerProduit();
                break;
            case '4':
                rechercherProduit();
                break;
            case '5':
                AfficherProduits();
                break;
            case '6':
                reapp_stock();
                break;
            case 'R':
                AfficherMenuGestionStock();
                break;
            default:
                printf("Choix invalide! Recommencer\n\n");
                break;
            break;
        }
    }
}

void AfficherMenuRayons(){
    char choix = 'A', chaine_choix[20];
    openProduits();
    openRayons();
    while ( choix != 'R' ){
        printf("\n\nMenu Rayons\n");
        printf("------------------------------------------------------------------------\n");
        printf("1. Ajouter un Rayon\n");
        printf("2. Modifier un Rayon\n");
        printf("3. Supprimer un Rayon\n");
        printf("4. Rechercher un Rayon\n");
        printf("5. Consulter les Rayons\n");
        printf("6. Ajouter une quantite de produit dans le Rayon\n");
        printf("7. Lister les Quantites en Stock\n");
        printf("R. Revenir au menu gestion de stock\n");
        printf("------------------------------------------------------------------------\n\n");
        printf("Entrez votre choix : ");
        scanf("%s", chaine_choix);
        choix = chaine_choix[0];
        switch( choix ){
            case '1':
                ajouterRayon();
                break;
            case '2':
                modifierRayon();
                break;
            case '3':
                supprimerRayon();
                break;
            case '4':
                rechercherRayon();
                break;
            case '5':
                AfficherRayons();
                break;
            case '6':
                modifier_Produit_rayon();
                break;
            case '7':
                displaayProduits();
                break;
            case 'R':
                AfficherMenuGestionStock();
                break;
            default:
                printf("Choix invalide! Recommencer\n\n");
                break;
            break;
        }
    }
}

void AfficherMenuCommandes(){
    char choix = 'A', chaine_choix[20];
    openCommandes();
    while ( choix != 'R' ){
        printf("\n\nMenu Commandes\n");
        printf("------------------------------------------------------------------------\n");
        printf("1. Ajouter une commande\n");
        printf("2. Modifier une commande\n");
        printf("3. Supprimer une commande\n");
        printf("4. Rechercher une commande\n");
        printf("5. Consulter les commandes\n");
        printf("R. Revenir au menu gestion de stock\n");
        printf("------------------------------------------------------------------------\n\n");
        printf("Entrez votre choix : ");
        scanf("%s", chaine_choix);
        choix = chaine_choix[0];
        switch( choix ){
            case '1':
                ajouterCommande();
                break;
            case '2':
                modifierCommande();
                break;
            case '3':
                supprimerCommande();
                break;
            case '4':
                rechercherCommande();
                break;
            case '5':
                AfficherCommandes();
                break;
            case 'R':
                AfficherMenuGestionStock();
                break;
            default:
                printf("Choix invalide! Recommencer\n\n");
                break;
            break;
        }
    }
}

void openChiffres(){
    liste_des_chiffres *tmp = NULL, *l = NULL;
    FILE *entree;
    int ligne, i = 0;
    entree = fopen ("dataChiffres.txt", "r");
    if(entree != NULL){
        if(head_sur_chiffres != NULL){
              nombreChiffres = 0;
              tmp = head_sur_chiffres;
              while(tmp -> next != NULL){
                   head_sur_chiffres = head_sur_chiffres -> next;
                   free(head_sur_chiffres);
                   tmp = head_sur_chiffres;
              }
              if(tmp -> next == NULL && tmp != NULL ){
                    free(tmp);
                    head_sur_chiffres = NULL;
              }
        }
        while(!feof(entree)){
            l = (liste_des_chiffres*)malloc(sizeof(liste_des_chiffres));
            l -> next = NULL;
            ligne = fscanf(entree,"%d %s %f\n", &l ->codecaisse, l ->datecaisse, &l ->grandtot);
            if(ligne != EOF){
                i++;
            }
        }
    }
    fclose(entree);
    nombreChiffres = i;
}


void openCaissiers(){
    liste_des_caissiers *tmp = NULL, *l = NULL;
    FILE *entree;
    int ligne, i = 0;
    entree = fopen ("dataCaissiers.txt", "r");
    if(entree != NULL){
        if(head_sur_caissiers != NULL){
              nombreCaissiers = 0;
              lastValueCodeCaissier = 0;
              tmp = head_sur_caissiers;
              while(tmp -> next != NULL){
                   head_sur_caissiers = head_sur_caissiers -> next;
                   free(head_sur_caissiers);
                   tmp = head_sur_caissiers;
              }
              if(tmp -> next == NULL && tmp != NULL ){
                    free(tmp);
                    head_sur_caissiers = NULL;
              }
        }
        if(!feof(entree)){
            lastValueCodeCaissier = 0;
        }
        while(!feof(entree)){
            l = (liste_des_caissiers*)malloc(sizeof(liste_des_caissiers));
            l -> next = NULL;
            ligne = fscanf(entree,"%d %s %d\n", &l -> code_caisse, l -> nom_caissier, &l -> code_caissier);
            if(ligne != EOF){
                i++;
                if(head_sur_caissiers == NULL){
                        head_sur_caissiers = l;
                        tmp = head_sur_caissiers;
                        tmp -> next = NULL;
                        lastValueCodeCaissier = l -> code_caisse;
                        l = NULL;
                    } else{
                        tmp -> next = l;
                        tmp = l;
                        tmp -> next = NULL;
                        lastValueCodeCaissier = l -> code_caisse;
                        l = NULL;
                    }
            }
        }
    }
    fclose(entree);
    nombreCaissiers = i;
}

void ajouterCaissier(){
    FILE * entree;
    int i = 1;
    liste_des_caissiers  *tmp;
    tmp = head_sur_caissiers;
        entree = fopen("dataCaissiers.txt", "a");
        liste_des_caissiers * l = (liste_des_caissiers *)malloc(sizeof(liste_des_caissiers));
        l -> code_caisse = lastValueCodeCaissier + 1;
        printf("Code Caisse  C%d", l -> code_caisse);
        printf("\n\nAjout d'un Nouveau Caissier\n");
        printf("------------------------------------------------------------------------\n");
        printf("Nom Caissier     :   ");
        scanf("%s", l -> nom_caissier);
        printf("Code Caissier    :   ");
        scanf("%d",&l -> code_caissier);
        printf("------------------------------------------------------------------------\n");
        fprintf(entree,"%d %s %d\n", l -> code_caisse, l -> nom_caissier, l -> code_caissier);
        fclose(entree);
    while(nombreCaissiers > i++){
        tmp = tmp -> next;
        }
    if(nombreCaissiers == 0){
        head_sur_caissiers = l;
        }else{
            tmp -> next = l;
        }
    nombreCaissiers++;
    lastValueCodeCaissier = l -> code_caisse;
    printf("Nombre de Caissiers lus : %d\n\n", nombreCaissiers);
}

void logincaissier(int codeCaisse, int codeCaissier){
    openCaissiers();
    int trouve = 0, i = 0;
    liste_des_caissiers *l = NULL;
    if(head_sur_caissiers != NULL){
        l = head_sur_caissiers;
        while(i < nombreCaissiers){
            if(l -> code_caisse == codeCaisse && l -> code_caissier == codeCaissier){
                trouve++;
                }
            l = l -> next;
            i++;
            }
        if(trouve == 1){
                AfficherMenuCaisses();
            }else{
            printf("\n\nVotre Password est Incorrect Recommencez\n\n");
            }
    }else {
        printf("\n\nVous devrez creer un compte!!\n\n");
    }
}

void rechercherCaissier(){
    int codeRecherche, trouve = 0, i = 0;
    liste_des_caissiers *l = NULL;

    if(head_sur_caissiers != NULL){
        printf("\n\nRechercher Caissier\n");
        printf("------------------------------------------------------------------------\n");
        printf("Entrez le code du Caisse concerne :   C");
        scanf("%d", &codeRecherche);
        l = head_sur_caissiers;
        while(i < nombreCaissiers){
            if(l -> code_caisse == codeRecherche){
                trouve++;
                printf("\nCode Caisse               :   C%d", l -> code_caisse);
                printf("\nNom Caissier              :   %s", l -> nom_caissier );
                printf("\nCode Caissier             :   %d\n", l-> code_caissier);
                printf("------------------------------------------------------------------------\n");
                }
            l = l -> next;
            i++;
            }
        if(trouve == 0){
            printf("\n\nLe Caissier avec le code  caisse C%d n'existe pas\n\n\n",codeRecherche);
            }
        }else{
        printf("Informations sur les Caissiers inexistantes\n\n");
        }
}

void modifierCaissier(){
    int codeRecherche;
    FILE *entree;
    int trouve = 0, i = 0;
    liste_des_caissiers *l = NULL, *tmp = NULL;

    printf("\n\n Modification Caissier\n");
    printf("------------------------------------------------------------------------\n");
    printf("Entrez le code Caisse concerne :   C");
    scanf("%d", &codeRecherche);

    if(head_sur_caissiers != NULL)
        {
        entree = fopen("dataCaissiers.txt", "w+");
        l = head_sur_caissiers;
        while(nombreCaissiers > i)
            {
            if(codeRecherche == l -> code_caisse)
                {
                printf("\nC%d ", l -> code_caisse);
                    printf("%s ", l -> nom_caissier);
                    printf("%d\n", l -> code_caissier);
                    printf("Nom Caissier          :   ");
                    scanf("%s", l -> nom_caissier);
                    printf("Code Caissier         :   ");
                    scanf("%d", &l -> code_caissier);
                    printf("------------------------------------------------------------------------\n");
                trouve++;
                }
            fprintf(entree, "%d %s %d\n", l -> code_caisse, l -> nom_caissier, l -> code_caissier);
            tmp = l;

            if(l == head_sur_caissiers)
                {
                head_sur_caissiers = NULL;
                }

            l = l -> next;
            i++;
            free(tmp);
            }
        fclose(entree);
        openCaissiers();
        }
    if(trouve == 0)
        {
        printf("\nLe Caissiers avec le code  caisse C%d n'existe pas\n\n",codeRecherche);
        }
    else
        {
        printf("Nombre de Caissiers lus : %d\n\n", nombreCaissiers);
        }
}

void AfficherCaissiers(){
    int i = 0;
    liste_des_caissiers *l = NULL;
    if(head_sur_caissiers!=NULL){
        l = head_sur_caissiers;
        printf("\n\nConsultation Caissier\n");
        printf("------------------------------------------------------------------------\n");
        while(i < nombreCaissiers){
            printf("Code Caisse      :   C%d\n", l -> code_caisse);
            printf("Nom Caissier     :   %s\n", l -> nom_caissier);
            printf("Code Caissier    :   %d\n", l -> code_caissier);
            printf("------------------------------------------------------------------------\n\n");
            l = l -> next;
            i++;
            }
        printf("Nombre de Caissiers lus : %d\n\n", nombreCaissiers);
        }else{
        printf("Informations sur les Caissiers inexistantes\n\n");
        }
}

void supprimerCaissier(){
    int codeRecherche, trouve = 0, i = 0;
    FILE *entree;
    liste_des_caissiers *l, *tmp;

    printf("\n\nSuppresion Caissier\n");
    printf("------------------------------------------------------------------------\n");
    printf("Entrez le Code Caisse concerne :   C");
    scanf("%d", &codeRecherche);

    if(head_sur_caissiers != NULL)
        {
        entree = fopen("dataCaissiers.txt","w+");
        l = head_sur_caissiers;
        while(nombreCaissiers > i)
            {
            if(codeRecherche != l -> code_caisse)
                {
                 fprintf(entree, "%d %s %d\n", l -> code_caisse, l -> nom_caissier, l -> code_caissier);
                }
            else
                {
                printf("\nC%d %s %d(Supprime)\n\n", l -> code_caisse, l -> nom_caissier, l -> code_caissier);
                printf("------------------------------------------------------------------------\n\n");
                trouve++;
                }
            tmp = l;

            if(l == head_sur_caissiers)
                {
                head_sur_caissiers = NULL;
                }

            l = l -> next;
            i++;
            free(tmp);
            }
        fclose(entree);
        openCaissiers();

        }
    if(!trouve)
        {
        printf("\nLe Caissier avec code caisse C%d n'existe pas\n\n", codeRecherche);
        }
    else
        {
        printf("\nNombre de Caissiers lus : %d\n\n", nombreCaissiers);
        }
    }

void openRayons(){
    liste_des_rayons *tmp = NULL, *l = NULL;
    FILE *entree;
    int ligne, i = 0;
    entree = fopen ("dataRayons.txt", "r");
    if(entree != NULL){
        if(head_sur_rayons != NULL){
              nombreRayons = 0;
              lastValueCodeRayon = 0;
              tmp = head_sur_rayons;
              while(tmp -> next != NULL){
                   head_sur_rayons = head_sur_rayons -> next;
                   free(head_sur_rayons);
                   tmp = head_sur_rayons;
              }
              if(tmp -> next == NULL && tmp != NULL ){
                    free(tmp);
                    head_sur_rayons = NULL;
              }
        }
        if(!feof(entree)){
            lastValueCodeRayon = 0;
        }
        while(!feof(entree)){
            l = (liste_des_rayons*)malloc(sizeof(liste_des_rayons));
            l -> next = NULL;
            ligne = fscanf(entree,"%d %s %d %s\n", &l -> code_rayon, l -> nom_rayon, &l -> nombre_de_produits,
            l -> etat);
            if(ligne != EOF){
                i++;
                if(head_sur_rayons == NULL){
                        head_sur_rayons = l;
                        tmp = head_sur_rayons;
                        tmp -> next = NULL;
                        lastValueCodeRayon = l -> code_rayon;
                        l = NULL;
                    } else{
                        tmp -> next = l;
                        tmp = l;
                        tmp -> next = NULL;
                        lastValueCodeRayon = l -> code_rayon;
                        l = NULL;
                    }
            }
        }
    }
    fclose(entree);
    nombreRayons = i;
}

void ajouterRayon(){
    FILE * entree;
    int i = 1;
    liste_des_rayons  *tmp;
    tmp = head_sur_rayons;
        entree = fopen("dataRayons.txt", "a");
        liste_des_rayons * l = (liste_des_rayons *)malloc(sizeof(liste_des_rayons));
        l -> code_rayon = lastValueCodeRayon + 1;
        printf("le code du Rayon est R%d", l -> code_rayon);
        printf("\n\nAjout d'un Nouveau Rayon\n");
        printf("------------------------------------------------------------------------\n");
        printf("Nom Rayon                                       :   ");
        scanf("%s", l -> nom_rayon);
        printf("Nombre de Produits en Stock                     :   ");
        scanf("%d", &l -> nombre_de_produits);
        if(l->nombre_de_produits >= 5000){

            strcpy(l -> etat, "Satisfaisant");
        } else {
            strcpy(l -> etat, "insatisfaisant");
        }
        printf("l'Etat du rayon est selon le Stock du Produits  :   %s\n", l -> etat);
        printf("------------------------------------------------------------------------\n\n");
        fprintf(entree, "%d %s %d %s\n", l -> code_rayon, l -> nom_rayon, l -> nombre_de_produits, l -> etat);
        fclose(entree);
    while(nombreRayons > i++){
        tmp = tmp -> next;
        }
    if(nombreRayons == 0){
        head_sur_rayons = l;
        }else{
            tmp -> next = l;
        }
    nombreRayons++;
    lastValueCodeRayon = l -> code_rayon;
    printf("Nombre de Rayons lus : %d\n\n", nombreRayons);
}

void rechercherRayon(){
    int codeRecherche, trouve = 0, i = 0;
    liste_des_rayons *l = NULL;
    if(head_sur_rayons != NULL){
        printf("\n\nRechercher Rayon\n");
        printf("------------------------------------------------------------------------\n");
        printf("Entrez le code du Rayon concerne :   R");
        scanf("%d", &codeRecherche);
        l = head_sur_rayons;
        while(i < nombreRayons){
            if(l -> code_rayon == codeRecherche){
                trouve++;
                printf("\nCode Rayon                       :   R%d", l -> code_rayon);
                printf("\nNom Rayon                        :   %s", l -> nom_rayon);
                printf("\nNombre de Produits dans ce rayon :   %d", l -> nombre_de_produits);
                printf("\nEtat Rayon                       :   %s\n", l -> etat);
                printf("------------------------------------------------------------------------\n");
                }
            l = l -> next;
            i++;
            }
        if(trouve == 0){
            printf("\n\n Le Rayon portant le Code R%d n'existe pas \n\n\n",codeRecherche);
            }
        }else{
        printf("\nInformations sur les Rayons inexistantes \n\n");
        }
}

void modifierRayon(){
    int codeRecherche;
    FILE *entree;
    int trouve = 0, i = 0;
    liste_des_rayons *l = NULL, *tmp = NULL;

    printf("\n\n Modification Rayon\n");
    printf("------------------------------------------------------------------------\n");
    printf("\n Entrez le code du Rayon concerne :   R");
    scanf("%d", &codeRecherche);

    if(head_sur_rayons != NULL)
        {
        entree = fopen("dataRayons.txt", "w+");
        l = head_sur_rayons;
        while(nombreRayons > i)
            {
            if(codeRecherche == l -> code_rayon)
                {
                    printf("R%d %s %d %s\n", l -> code_rayon, l -> nom_rayon, l -> nombre_de_produits, l -> etat);
                    printf("Nom Rayon                                       :   ");
                    scanf("%s", l -> nom_rayon);
                    printf("nombre de produits                              :   ");
                    scanf("%d", &l ->  nombre_de_produits);
                    if(l->nombre_de_produits >= 5000){
                        strcpy(l -> etat, "Satisfaisant");
                    }else {
                        strcpy(l -> etat, "insatisfaisant");
                    }
                    printf("l'Etat du rayon est selon le Stock du Produits  :   %s\n", l -> etat);
                    printf("------------------------------------------------------------------------\n");
                trouve++;
                }
                fprintf(entree, "%d %s %d %s\n", l -> code_rayon, l -> nom_rayon, l-> nombre_de_produits, l -> etat);
            tmp = l;

            if(l == head_sur_rayons)
                {
                head_sur_rayons = NULL;
                }

            l = l -> next;
            i++;
            free(tmp);
            }
        fclose(entree);
        openRayons();
        }
    if(trouve == 0)
        {
        printf("\nLe Rayon portant le code R%d n'existe pas\n\n",codeRecherche);
        }
    else
        {
        printf("Nombre de Rayons lus : %d\n\n", nombreRayons);
        }
}

void supprimerRayon(){
    int codeRecherche, trouve = 0, i = 0;
    FILE *entree;
    liste_des_rayons *l, *tmp;
    printf("\n\nSuppresion Rayon\n");
    printf("------------------------------------------------------------------------\n");
    printf("Entrez le code du Rayon concerne :   R");
    scanf("%d", &codeRecherche);

    if(head_sur_rayons != NULL)
        {
        entree = fopen("dataRayons.txt","w+");
        l = head_sur_rayons;
        while(nombreRayons > i)
            {
            if(codeRecherche != l -> code_rayon)
                {
                fprintf(entree, "%d %s %d %s\n",l -> code_rayon, l -> nom_rayon, l -> nombre_de_produits, l -> etat);
                }
            else
                {
                printf("\nR%d %s %d %s(Supprime)\n",l -> code_rayon, l -> nom_rayon, l -> nombre_de_produits, l -> etat);
                printf("------------------------------------------------------------------------\n");
                trouve++;
                }
            tmp = l;

            if(l == head_sur_rayons)
                {
                head_sur_rayons = NULL;
                }

            l = l -> next;
            i++;
            free(tmp);
            }
        fclose(entree);
        openRayons();

        }
    if(!trouve)
        {
        printf("\nLe Rayon portant le code R%d n'existe pas\n\n", codeRecherche);
        }
    else
        {
        printf("\nNombre de Rayons lus : %d\n\n", nombreRayons);
        }
    }

void AfficherRayons(){
    int i = 0;
    liste_des_rayons *l = NULL;
    if(head_sur_rayons!=NULL){
        l = head_sur_rayons;
        printf("\n\nConsultation rayons\n");
        printf("------------------------------------------------------------------------\n");
        while(i < nombreRayons){
            printf("Nom Rayon             :   %s\n", l -> nom_rayon);
            printf("Etat du rayon         :   %s\n", l -> etat);
            printf("Code Rayon            :   R%d\n", l -> code_rayon);
            printf("nombre de produits    :   %d\n", l -> nombre_de_produits);
            printf("------------------------------------------------------------------------\n\n");
            l = l -> next;
            i++;
            }
        printf("Nombre de Rayons lus : %d\n\n", nombreRayons);
        }else{
        printf("Informations sur les Rayons inexistantes\n\n");
        }
}

void openProduits(){
    liste_des_produits *tmp = NULL, *l = NULL;
    FILE *entree;
    int ligne, i = 0;
    entree = fopen ("dataProduits.txt", "r");
    if(entree != NULL){
        if(head_sur_produits != NULL){
              nombreProduits = 0;
              lastValueCodeProduit = 0;
              tmp = head_sur_produits;
              while(tmp -> next != NULL){
                   head_sur_produits = head_sur_produits -> next;
                   free(head_sur_produits);
                   tmp = head_sur_produits;
              }
              if(tmp -> next == NULL && tmp != NULL ){
                    free(tmp);
                    head_sur_produits = NULL;
              }
        }
        if(!feof(entree)){
            lastValueCodeProduit = 0;
        }
        while(!feof(entree)){
            l = (liste_des_produits*)malloc(sizeof(liste_des_produits));
            l -> next = NULL;
            ligne = fscanf(entree,"%d %s %s %d %f %d\n", &l -> code_produit, l -> nom_produit,
            l -> nom_rayon, &l -> stock_produit, &l -> prix_Unitaire, &l -> tva);
            if(ligne != EOF){
                i++;
                if(head_sur_produits == NULL){
                        head_sur_produits = l;
                        tmp = head_sur_produits;
                        tmp -> next = NULL;
                        lastValueCodeProduit = l -> code_produit;
                        l = NULL;
                    } else{
                        tmp -> next = l;
                        tmp = l;
                        tmp -> next = NULL;
                        lastValueCodeProduit = l -> code_produit;
                        l = NULL;
                    }
            }
        }
    }
    fclose(entree);
    nombreProduits = i;
}

void ajouterProduit(){
    FILE * entree;
    int i = 1;
    liste_des_produits  *tmp;
    tmp = head_sur_produits;
        entree = fopen("dataProduits.txt", "a");
        liste_des_produits * l = (liste_des_produits *)malloc(sizeof(liste_des_produits));
        l -> code_produit = lastValueCodeProduit + 1;
        printf("le code du produit est P%d", l -> code_produit);
        printf("\n\nAjout d'un Nouveau Produit\n");
        printf("------------------------------------------------------------------------\n");
        printf("Nom produit              :   ");
        scanf("%s", l -> nom_produit);
        printf("Nom Rayon                :   ");
        scanf("%s", l -> nom_rayon);
        printf("Quantite en stock        :   ");
        scanf("%d", &l -> stock_produit);
        printf("Prix unitaire produit    :   ");
        scanf("%f", &l -> prix_Unitaire);
        printf("------------------------------------------------------------------------\n\n");
        l -> tva = 10;
        fprintf(entree,"%d %s %s %d %f %d\n", l -> code_produit, l -> nom_produit,
        l -> nom_rayon, l -> stock_produit, l -> prix_Unitaire, l -> tva);
        fclose(entree);
    while(nombreProduits > i++){
        tmp = tmp -> next;
        }
    if(nombreProduits == 0){
        head_sur_produits = l;
        }else{
            tmp -> next = l;
        }
    nombreProduits++;
    lastValueCodeProduit = l -> code_produit;
    printf("Nombre de produits lus : %d\n\n", nombreProduits);
}

void rechercherProduit(){
    int codeRecherche, trouve = 0, i = 0;
    liste_des_produits *l = NULL;

    if(head_sur_produits != NULL){
        printf("\n\nRechercher produit\n");
        printf("------------------------------------------------------------------------\n");
        printf("Entrez le code du produit concerne :   P");
        scanf("%d", &codeRecherche);
        l = head_sur_produits;
        while(i < nombreProduits){
            if(l -> code_produit == codeRecherche){
                trouve++;
                printf("Code produit              :   P%d\n", l -> code_produit);
                printf("Nom produit               :   %s\n", l -> nom_produit );
                printf("Nom Rayon                 :   %s\n", l -> nom_rayon );
                printf("Prix unitaire produit     :   %f\n", l -> prix_Unitaire);
                printf("Stock produit             :   %d\n", l-> stock_produit);
                printf("Tva                       :   %d\n", l -> tva);
                printf("------------------------------------------------------------------------\n");
                }
            l = l -> next;
            i++;
            }
        if(trouve == 0){
            printf("\n\nLe produit portant le code P%d n'existe pas\n\n",codeRecherche);
            }
        }else{
        printf("Informations sur les produits inexistantes\n\n");
        }
}

void modifierProduit(){
    int codeRecherche;
    FILE *entree;
    int trouve = 0, i = 0;
    liste_des_produits *l = NULL, *tmp = NULL;

    printf("\n\n Modification produit\n");
    printf("------------------------------------------------------------------------\n");
    printf("Entrez le code du produit concerne :   P");
    scanf("%d", &codeRecherche);

    if(head_sur_produits != NULL)
        {
        entree = fopen("dataProduits.txt", "w+");
        l = head_sur_produits;
        while(nombreProduits > i)
            {
            if(codeRecherche == l -> code_produit)
                {
                printf("\nP%d ", l -> code_produit);
                    printf("%s ", l -> nom_produit);
                    printf("%s ", l -> nom_rayon);
                    printf("%d ", l -> stock_produit);
                    printf("%f ", l -> prix_Unitaire);
                    printf("%d\n", l -> tva);
                    printf("Nom produit           :   ");
                    scanf("%s", l -> nom_produit);
                    printf("le nom du rayon est   :   ");
                    scanf("%s", l -> nom_rayon);
                    printf("Quantite en stock     :   ");
                    scanf("%d", &l -> stock_produit);
                    printf("Prix unitaire produit :   ");
                    scanf("%f", &l -> prix_Unitaire);
                    printf("------------------------------------------------------------------------\n\n");
                trouve++;
                }
            fprintf(entree, "%d %s %s %d %f %d\n", l -> code_produit, l -> nom_produit, l -> nom_rayon,
            l -> stock_produit, l -> prix_Unitaire, l -> tva);
            tmp = l;

            if(l == head_sur_produits)
                {
                head_sur_produits = NULL;
                }

            l = l -> next;
            i++;
            free(tmp);
            }
        fclose(entree);
        openProduits();
        }
    if(trouve == 0)
        {
        printf("\nLe produit portant le code P%d n'existe pas\n\n",codeRecherche);
        }
    else
        {
        printf("Nombre de Produits lus : %d\n\n", nombreProduits);
        }
}

void AfficherProduits(){
    int i = 0;
    liste_des_produits *l = NULL;
    if(head_sur_produits!=NULL){
        l = head_sur_produits;
        printf("\n\nConsultation produit\n");
        printf("------------------------------------------------------------------------\n");
        while(i < nombreProduits){
            printf("Nom produit     :   %s\n", l -> nom_produit);
            printf("Nom rayon       :   %s\n", l -> nom_rayon);
            printf("Code Produit    :   P%d\n", l -> code_produit);
            printf("Stock Produit   :   %d\n", l -> stock_produit);
            printf("Prix Unitaire   :   %f\n", l -> prix_Unitaire);
            printf("tva             :   %d\n", l -> tva);
            printf("------------------------------------------------------------------------\n\n");
            l = l -> next;
            i++;
            }
        printf("Nombre de Produits lus : %d\n\n", nombreProduits);
        }else{
        printf("Informations sur les produits inexistantes\n\n");
        }
}

void supprimerProduit(){
    int codeRecherche, trouve = 0, i = 0;
    FILE *entree;
    liste_des_produits *l, *tmp;

    printf("\n\nSuppresion produit\n");
    printf("------------------------------------------------------------------------\n");
    printf("Entrez le code du produit concerne :   P");
    scanf("%d", &codeRecherche);

    if(head_sur_produits != NULL)
        {
        entree = fopen("dataProduits.txt","w+");
        l = head_sur_produits;
        while(nombreProduits > i)
            {
            if(codeRecherche != l -> code_produit)
                {
                 fprintf(entree, "%d %s %s %d %f %d\n", l -> code_produit, l -> nom_produit, l -> nom_rayon, l -> stock_produit, l -> prix_Unitaire, l -> tva);
                }
            else
                {
                printf("\nP%d %s %s %d %f %d (Supprime)\n", l -> code_produit, l -> nom_produit, l -> nom_rayon,
                l -> stock_produit, l -> prix_Unitaire, l -> tva);
                printf("------------------------------------------------------------------------\n\n");
                trouve++;
                }
            tmp = l;

            if(l == head_sur_produits)
                {
                head_sur_produits = NULL;
                }

            l = l -> next;
            i++;
            free(tmp);
            }
        fclose(entree);
        openProduits();

        }
    if(!trouve)
        {
        printf("\nLe Produit portant le code P%d n'existe pas\n\n", codeRecherche);
        }
    else
        {
        printf("\nNombre de Produits lus : %d\n\n", nombreProduits);
        }
    }


void openCommandes(){
    liste_des_commandes *tmp = NULL, *l = NULL;
    FILE *entree;
    int ligne, i = 0;
    entree = fopen ("dataCommandes.txt", "r");
    if(entree != NULL){
        if(head_sur_commandes != NULL){
              nombreCommandes = 0;
              lastValueCodeCommande = 0;
              tmp = head_sur_commandes;
              while(tmp -> next != NULL){
                   head_sur_commandes = head_sur_commandes -> next;
                   free(head_sur_commandes);
                   tmp = head_sur_commandes;
              }
              if(tmp -> next == NULL && tmp != NULL ){
                    free(tmp);
                    head_sur_commandes = NULL;
              }
        }
        if(!feof(entree)){
            lastValueCodeCommande = 0;
        }
        while(!feof(entree)){
            l = (liste_des_commandes*)malloc(sizeof(liste_des_commandes));
            l -> next = NULL;
            ligne = fscanf(entree,"%d %s %d %d %s\n", &l -> code_commande,l -> nom_commande, &l -> code_produit,
            &l -> quantite_commande, l -> date_commande);
            if(ligne != EOF){
                i++;
                if(head_sur_commandes == NULL){
                        head_sur_commandes = l;
                        tmp = head_sur_commandes;
                        tmp -> next = NULL;
                        lastValueCodeCommande = l -> code_produit;
                        l = NULL;
                    } else{
                        tmp -> next = l;
                        tmp = l;
                        tmp -> next = NULL;
                        lastValueCodeCommande = l -> code_produit;
                        l = NULL;
                    }
            }
        }
    }
    fclose(entree);
    nombreCommandes = i;
}

void ajouterCommande(){
    FILE * entree;
    int i = 1;
    liste_des_commandes  *tmp;
    tmp = head_sur_commandes;
        entree = fopen("dataCommandes.txt", "a");
        liste_des_commandes * l = (liste_des_commandes *)malloc(sizeof(liste_des_commandes));
        l -> code_commande = lastValueCodeCommande + 1;
        printf("le code du Commande est C%d", l -> code_commande);
        printf("\n\nAjout d'une Nouvelle Commande\n");
        printf("------------------------------------------------------------------------\n");
        printf("Entrer le Nom      :   ");
        scanf("%s", l-> nom_commande);
        printf("Code produit       :   P");
        scanf("%d", &l -> code_produit);
        printf("Quantite commandee :   ");
        scanf("%d", &l -> quantite_commande);
        printf("Date commande      :   ");
        scanf("%s", l -> date_commande);
        printf("------------------------------------------------------------------------\n\n");
        fprintf(entree,"%d %s %d %d %s\n",l -> code_commande,l -> nom_commande,l -> code_produit,
        l -> quantite_commande, l -> date_commande);
        fclose(entree);
    while(nombreCommandes > i++){
        tmp = tmp -> next;
        }
    if(nombreCommandes == 0){
        head_sur_commandes = l;
        }else{
            tmp -> next = l;
        }
    nombreCommandes++;
    lastValueCodeCommande = l -> code_commande;
    printf("Nombre de Commandes lus : %d\n\n", nombreCommandes);
}

void rechercherCommande(){
    int codeRecherche, trouve = 0, i = 0;
    liste_des_commandes *l = NULL;

    if(head_sur_commandes != NULL){
        printf("\n\nRechercher Commande\n");
        printf("------------------------------------------------------------------------\n");
        printf("Entrez le Code du Commande concerne :   C");
        scanf("%d", &codeRecherche);
        l = head_sur_commandes;
        while(i < nombreCommandes){
            if(l -> code_commande == codeRecherche){
                trouve++;
                printf("\nCode Commande             :   C%d", l -> code_commande);
                printf("\nNom Commande              :   %s", l -> nom_commande );
                printf("\nCode Produit              :   P%d", l -> code_produit);
                printf("\nQuantite Commande         :   %d", l-> quantite_commande);
                printf("\nDate Commande             :   %s\n", l -> date_commande);
                printf("------------------------------------------------------------------------\n\n");
                }
            l = l -> next;
            i++;
            }
        if(trouve == 0){
            printf("\n\nLa Commande portant le code C%d n'existe pas\n\n\n",codeRecherche);
            }
        }else{
        printf("Informations sur les Commandes inexistantes\n\n");
        }
}

void modifierCommande(){
    int codeRecherche;
    FILE *entree;
    int trouve = 0, i = 0;
    liste_des_commandes *l = NULL, *tmp = NULL;

    printf("\n\n Modification Commande\n");
    printf("------------------------------------------------------------------------\n");
    printf("Entrez le code de la Commande concerne :   C");
    scanf("%d", &codeRecherche);

    if(head_sur_commandes != NULL)
        {
        entree = fopen("dataCommandes.txt", "w+");
        l = head_sur_commandes;
        while(nombreCommandes > i)
            {
            if(codeRecherche == l -> code_commande)
                {
                    printf("\nC%d ", l -> code_commande);
                    printf("%s ", l -> nom_commande);
                    printf("P%d ", l -> code_produit);
                    printf("%d ", l -> quantite_commande);
                    printf("%s\n", l -> date_commande);
                    printf("Votre Nom           :   ");
                    scanf("%s", l -> nom_commande);
                    printf("Code Produit        :   P");
                    scanf("%d", &l -> code_produit);
                    printf("Quantite Commande   :   ");
                    scanf("%d", &l -> quantite_commande);
                    printf("date Commande       :   ");
                    scanf("%s", l -> date_commande);
                    printf("------------------------------------------------------------------------\n\n");
                trouve++;
                }
            fprintf(entree,"%d %s %d %d %s\n",l -> code_commande, l -> nom_commande, l -> code_produit,
            l -> quantite_commande, l -> date_commande);
            tmp = l;

            if(l == head_sur_commandes)
                {
                head_sur_commandes = NULL;
                }

            l = l -> next;
            i++;
            free(tmp);
            }
        fclose(entree);
        openCommandes();
        }
    if(trouve == 0)
        {
        printf("\nLa Commande portant le code C%d n'existe pas\n\n",codeRecherche);
        }
    else
        {
        printf("Nombre Commandes lus : %d\n\n", nombreCommandes);
        }
}

void AfficherCommandes(){
    int i = 0;
    liste_des_commandes *l = NULL;
    if(head_sur_commandes != NULL){
        l = head_sur_commandes;
        printf("\n\nConsultation Commande\n");
        printf("------------------------------------------------------------------------\n");
        while(i < nombreCommandes){
            printf("Code Commande    :   C%d\n", l -> code_commande);
            printf("Nom Commande     :   %s\n", l -> nom_commande);
            printf("Code Produit     :   P%d\n", l -> code_produit);
            printf("Code Commande    :   %d\n", l -> quantite_commande);
            printf("Code Commande    :   %s\n", l -> date_commande);
            printf("------------------------------------------------------------------------\n\n");
            l = l -> next;
            i++;
            }
        printf("Nombre de Commandes lus : C%d\n\n", nombreCommandes);
        }else{
        printf("Informations sur les Commandes inexistantes\n\n");
        }
}

void supprimerCommande(){
    int codeRecherche, trouve = 0, i = 0;
    FILE *entree;
    liste_des_commandes *l, *tmp;

    printf("\n\nSuppresion Commande\n");
    printf("------------------------------------------------------------------------\n");
    printf("Entrez le Code du Commande concerne :   C");
    scanf("%d", &codeRecherche);

    if(head_sur_commandes != NULL)
        {
        entree = fopen("dataCommandes.txt","w+");
        l = head_sur_commandes;
        while(nombreCommandes > i)
            {
            if(codeRecherche != l -> code_commande)
                {
                fprintf(entree,"%d %s %d %d %s\n",l -> code_commande,l -> nom_commande,l -> code_produit,
                l -> quantite_commande, l -> date_commande);
                }
            else
                {
                printf("\nC%d  %s  P%d  %d  %s(Supprime)\n",l -> code_commande,l -> nom_commande,l -> code_produit,
                l -> quantite_commande, l -> date_commande);
                printf("------------------------------------------------------------------------\n");
                trouve++;
                }
            tmp = l;

            if(l == head_sur_commandes)
                {
                head_sur_commandes = NULL;
                }

            l = l -> next;
            i++;
            free(tmp);
            }
        fclose(entree);
        openCommandes();

        }
    if(!trouve)
        {
        printf("\nLa Commande portant le code C%d n'existe pas\n\n", codeRecherche);
        }
    else
        {
        printf("\nNombre de Commandes lus : %d\n\n", nombreCommandes);
        }
    }

void openTickets()
    {
    liste_des_tickets *tmp = NULL, *l = NULL;
    FILE *entree;
    int ligne, i = 0;
    entree = fopen ("dataTickets.txt", "r");
    if(entree != NULL)
        {
        if(head_sur_tickets != NULL)
        {
          nombreTickets = 0;
          lastValueCodeTicket = 0;
          tmp = head_sur_tickets;
          while(tmp -> next != NULL)
          {
           head_sur_tickets = head_sur_tickets -> next;
           free(head_sur_tickets);
           tmp = head_sur_tickets;
          }
          if(tmp -> next == NULL && tmp!=NULL)
          {
            free(head_sur_tickets);
            head_sur_tickets = NULL;
          }
        }
        if(!feof(entree))
            {
            lastValueCodeTicket=0;
            }
        while(!feof(entree))
            {
            l = (liste_des_tickets*)malloc(sizeof(liste_des_tickets));
            l -> next = NULL;
            ligne = fscanf(entree,"%d %s %d %d %s %d\n", &l -> code_ticket , l -> date_ticket, &l -> code_produit,
            &l -> quantite_ticket, l -> payement, &l -> code_caiss);
            if(ligne != EOF)
                {
                i++;
                if(head_sur_tickets == NULL)
                    {
                    head_sur_tickets = l;
                    tmp = head_sur_tickets;
                    tmp -> next = NULL;
                    lastValueCodeTicket = l -> code_ticket;
                    l = NULL;
                    }
                else
                    {
                    tmp -> next = l;
                    tmp = l;
                    lastValueCodeTicket = l -> code_ticket;
                    l = NULL;
                    }
                }
            }
        }
    fclose(entree);
    nombreTickets = i;
    }


void ajouterLigneTicket(int qte_vendue)
    {
    Ticket *la, *llll;
    la = NULL;
    llll = NULL;
    llll = (Ticket*)malloc(sizeof(Ticket));
    llll -> next = NULL;

    strcpy(llll -> nomproduit, nomProduitTicket);
    llll -> prixu = prixUnitaireTicket;
    llll -> quantiteproduit = qte_vendue;

    if(head != NULL)
        {
        la = head;
        while(la -> next != NULL)
            {
            la = llll -> next;
            }
        if(la -> next == NULL && la != NULL)
            {
            la -> next = llll;
            }
        }
    else
        {
        head = llll;
        head -> next = NULL;
        }
    }



float AfficherDetailTicket()
    {
    Ticket *donnee, *p;
    donnee = head;
    float totGl = 0;
    if(head != NULL)
        {
        while(donnee -> next != NULL)
            {
            p = donnee;
            printf("Produits         :   %s\n", donnee -> nomproduit);
            printf("Prix Unitaire    :   %f\n", donnee -> prixu);
            printf("Quantite         :   %d\n", donnee -> quantiteproduit);
            printf("Total            :   %f\n", donnee -> quantiteproduit * donnee -> prixu );
            totGl = totGl + (donnee -> quantiteproduit* donnee -> prixu);
            donnee = donnee -> next;
            head = donnee;
            free(p);
            }
        if(donnee -> next == NULL && donnee != NULL)
            {
            p = donnee;
            printf("Produits         :   %s\n", donnee -> nomproduit);
            printf("Prix Unitaire    :   %f\n", donnee -> prixu);
            printf("Quantite         :   %d\n", donnee -> quantiteproduit);
            printf("Total            :   %f\n", donnee -> quantiteproduit * donnee -> prixu );
            totGl = totGl + (donnee -> quantiteproduit * donnee -> prixu);
            free(p);
            head = NULL;
            }
        }
    printf("\n------------------------------------------------------------------------\n");
    printf("Grand total      :   %f\n", totGl);
    printf("------------------------------------------------------------------------\n\n");
    return totGl;
    }



void ajouterTicket()
    {
    FILE *entree;
    float v;
    int i = 1, termine = 0, p;
    liste_des_tickets *l, *tmp;

    l = (liste_des_tickets*)malloc(sizeof(liste_des_tickets));
    l -> code_ticket = lastValueCodeTicket + 1;
    l -> code_caiss = cc;
    entree = fopen("dataTickets.txt","a");

    printf("\n\nEtablissement Ticket\n");
    printf("------------------------------------------------------------------------\n");
    printf("Ticket numero                                    :   NT%d\n", l -> code_ticket);
    printf("Date Ticket                                      :   ");
    scanf("%s", l -> date_ticket);
    printf("Payement par  1.Carte Bancaire/ 2.Cheque/ 3.Cash :   ");
    scanf("%d", &p);
     if(p == 1){
            strcpy(l -> payement, "Carte_Bancaire");
        }
        if (p == 2){
            strcpy(l -> payement, "Cheque");
        }
         if (p == 3){
            strcpy(l -> payement, "Cash");
        }
    printf("vous avez choisez le mode de payement par        :   %s\n", l -> payement);
    while (!termine)
        {
        printf("Code produit (code = P0 pour terminer)           :   P");
        scanf("%d", &l -> code_produit);
        termine = (l -> code_produit == 0) ;

        if (!termine)
            {
            if(searchProduitTicket(l -> code_produit))
                {
                printf("Nom Produit      : %s    Prix Unitaire : %f    Quantite en Stock : %d \n", nomProduitTicket, prixUnitaireTicket, qteEnStockProduit);
                printf("Quantite Vendue  :    ");
                scanf("%d", &l -> quantite_ticket);

                ajouterLigneTicket(l -> quantite_ticket);

                fprintf(entree,"%d %s %d %d %s %d\n", l -> code_ticket , l -> date_ticket, l -> code_produit,
                l -> quantite_ticket, l -> payement, l->code_caiss);

                tmp = head_sur_tickets;

                while(nombreTickets > i++)
                    {
                    tmp = tmp -> next;
                    }

                if(nombreTickets == 0)
                    {
                    head_sur_tickets = l;
                    }
                else
                    {
                    tmp -> next = l;
                    }

                nombreTickets++;
                lastValueCodeTicket = l -> code_ticket;
                } else {
                    printf("\n\nLe Produit portant le code P%d n'existe pas\n\n\n", l -> code_produit);
                }
            }
        }
    printf("\n\n------------------------------------------------------------------------");
    printf("\n Ticket Numero   :   NT%d", l -> code_ticket);
    printf("\n Date Ticket     :   %s", l -> date_ticket);
    printf("\n Payement        :   %s", l -> payement);
    v = AfficherDetailTicket();
    fclose(entree);
    printf("\n");
    printf("Nombre de Tickets lues :   %d", nombreTickets);

    FILE * entr;
    int d = 1;
    liste_des_chiffres *tmpc, *tmpcc;
    tmpcc = head_sur_chiffres;
    entr = fopen("dataChiffres.txt", "a");
    tmpc = (liste_des_chiffres*)malloc(sizeof(liste_des_chiffres));
    tmpc -> codecaisse = cc;
    strcpy(tmpc->datecaisse, l -> date_ticket);
    tmpc ->grandtot = v;
    fprintf(entr,"%d %s %f\n", tmpc ->codecaisse, tmpc ->datecaisse, tmpc ->grandtot);
    fclose(entr);
    while(nombreChiffres > d++){
        tmpcc = tmpcc -> next;
        }
    if(nombreChiffres == 0){
        head_sur_chiffres = tmpc;
        }else{
            tmpcc -> next = tmpc;
        }
    nombreChiffres++;

    }

void supprimerTicket()
    {
    int codeRecherche, trouve = 0, i = 0;
    FILE *entree;
    liste_des_tickets *l, *tmp;

    printf("\n\nSuppresion Ticket\n");
    printf("------------------------------------------------------------------------\n");
    printf("Entrez le numero de la Ticket concerne :   NT");
    scanf("%d", &codeRecherche);

    if(head_sur_tickets != NULL)
        {
        entree = fopen("dataTickets.txt", "w+");
        l = head_sur_tickets;
        while(nombreTickets > i)
            {
            if(codeRecherche != l -> code_ticket)
                {
                fprintf(entree, "%d %s %d %d %s %d\n", l -> code_ticket , l -> date_ticket, l -> code_produit,
                l -> quantite_ticket, l -> payement, l ->code_caiss);
                }
            else
                {
                printf("\nNT%d %s P%d %d %s (supprime)\n", l -> code_ticket, l -> date_ticket, l -> code_produit,
                l -> quantite_ticket, l -> payement);
                printf("------------------------------------------------------------------------\n\n");
                trouve++;
                }
            tmp = l;

            if(l == head_sur_tickets)
                {
                head_sur_tickets = NULL;
                }

            l = l -> next;
            i++;
            free(tmp);
            }
        fclose(entree);
        openTickets();
        }
    if(trouve == 0)
        {
        printf("\nLa Ticket portant le numero NT%d n'existe pas\n\n", codeRecherche);
        }
    else
        {
        printf("\nNombre de Tickets lues : %d\n\n", nombreTickets);
        }
    }

int searchProduitTicket(int codeRecherche)
    {
    int trouve = 0, i = 0;
    liste_des_produits *produit = NULL;

    if(head_sur_produits != NULL)
        {
        produit = head_sur_produits;
        while(i < nombreProduits)
            {
            if(produit -> code_produit == codeRecherche)
                {
                trouve++;
                strcpy(nomProduitTicket, produit -> nom_produit);
                prixUnitaireTicket = produit -> prix_Unitaire;
                qteEnStockProduit = produit -> stock_produit;
                }
            produit = produit -> next;
            i++;
            }
        }
    return trouve;
    }

void modifier_Produit_rayon(){
    char nomRecherche[200];
    FILE *entree;
    char n[200];
    int trouve = 0, i = 0, k;
    liste_des_produits *l = NULL, *tmp = NULL;
    printf("\n\n Modification du Quantite de produit selon le Rayon \n");
    printf("---------------------------------------------------------------------------\n");
    printf("Entrez le nom du produit     :   ");
    scanf("%s", nomRecherche);
    printf("Entrer le nom  du  rayon     :   ");
    scanf("%s",n);

    if(head_sur_produits != NULL)
        {
        entree = fopen("dataProduits.txt", "w+");
        l = head_sur_produits;
        while(nombreProduits > i)
            {
            if(strcmp(nomRecherche,l -> nom_produit) == 0 && strcmp(n,l->nom_rayon)==0)
                {
                     printf("Entrer la Nouvelle Quantite      :  ");
                     scanf("%d",&k);
                     l->stock_produit = l -> stock_produit + k;
                     printf("la Nouvelle Quantite est %d", l-> stock_produit);
                    printf("\n");
                trouve++;
                }
            fprintf(entree, "%d %s %s %d %f %d\n", l -> code_produit, l -> nom_produit, l -> nom_rayon,
            l -> stock_produit, l -> prix_Unitaire, l -> tva);
            tmp = l;

            if(l == head_sur_produits)
                {
                head_sur_produits = NULL;
                }

            l = l -> next;
            i++;
            free(tmp);
            }
        fclose(entree);
        openProduits();
        }
    if(trouve == 0)
        {
        printf("\nLe produit portant le nom %s  n'existe pas\n\n", l -> nom_produit);
        }
    else
        {
        printf("Nombre de Produits lus : %d\n\n", nombreProduits);
        }
}

void reapp_stock(){
    int i = 0, m = 5;
    char nom[200];
    liste_des_produits *l = NULL;
    if(head_sur_produits != NULL){
        l = head_sur_produits;
        printf("Entrer le nom de Rayon : ");
        scanf("%s", nom);
        while(i < nombreProduits){
        	if(strcmp(nom, l->nom_rayon)==0 && l->stock_produit < m){
            printf("la Quantite de Produit %s est %d  dans le Rayon de %s a besoin de Reapprovisionnemt", l->nom_produit, l->stock_produit, l->nom_rayon);
            }
            l = l -> next;
            i++;}
         }
        else{
        printf("Informations sur les Produits inexistantes\n\n");
        }
}

void displaayProduits(){
    int i = 0;
    char nom[200];
    liste_des_produits *l = NULL;
    if(head_sur_produits!=NULL){
        l = head_sur_produits;
        printf("\nEntrer le nom de rayon  :   ");
        scanf("%s",nom);
        while(i < nombreProduits){
        	if(strcmp(nom,l->nom_rayon)==0){
            printf("nom Produit             :   %s\n", l -> nom_produit);
            printf("Code Produit            :   %d\n", l -> code_produit);
            printf("Quantite Produit        :   %d\n\n", l -> stock_produit);
            }
            l=l->next;
            i++;}
         }
        else{
        printf("Informations sur les produits inexistantes\n\n");
        }
}

void chiffreAffaireCaisse(){
    int i = 0;
    float chiffre;
    liste_des_chiffres *l = NULL;
    if(head_sur_chiffres != NULL){
        l = head_sur_chiffres;
        while(i < nombreChiffres){
        	if(l -> codecaisse == cc){
                chiffre = chiffre + l -> grandtot;
            }
            l = l -> next;
            i++;}
            printf("Chiffre d'Affaire de La Caisse %d est : %f", cc, chiffre);
         }
        else{
        printf("Informations sur les Tickets inexistantes\n\n");
        }
}

void chiffreAffaireJour(){
    int i = 0;
    float chiffre;
    char nom[200];
    liste_des_chiffres *l = NULL;
    if(head_sur_chiffres != NULL){
        l = head_sur_chiffres;
        printf("Entrer la date du Jour : ");
        scanf("%s", nom);
        while(i < nombreChiffres){
        	if(strcmp(nom, l -> datecaisse)==0){
                  chiffre = chiffre + l -> grandtot;
            }
            l = l -> next;
            i++;}
            printf("Chiffre d'Affaire Par jour %s est : %f", nom, chiffre);
         }
        else{
        printf("Informations sur les Tickets inexistantes\n\n");
        }
}

