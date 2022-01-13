#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0

struct produit
{
    char code[10];
    char libele[10];
    int prix;
};

typedef struct produit PRODUIT;

struct cellule
{
    PRODUIT p;
    struct cellule * suivant;
};

typedef struct cellule * LISTE_P;


//operation sur un produit ********************
PRODUIT * lire_produit()
{
    PRODUIT *p;
    p = (PRODUIT*)malloc(sizeof(PRODUIT));

    printf("Entrer le code du produit :");
    scanf("%s" , p->code);
    printf("Entrer le libele :");
    scanf("%s" , p->libele);
    printf("Entrer le prix :");
    scanf("%d" , &p->prix);

    return p;
}

void lire_produit2(PRODUIT * p)
{
    printf("Entrer le code du produit :");
    scanf("%s" , p->code);
    printf("Entrer le libele :");
    scanf("%s" , p->libele);
    printf("Entrer le prix :");
    scanf("%d" , &p->prix);
    return;
}

void affiche_produit(PRODUIT * p)
{
    printf("%s" , p->code);
    printf("%s" , p->libele);
    printf("%d" , p->prix);
    return;
}


// Partie 2 operation sur une  liste de produit

int liste_vide(LISTE_P lp)
{
    if(lp == NULL)
        return TRUE;
    return FALSE;
}

// PROBLEME D'AJOUT************************************************************************
LISTE_P ajout_en_qeue(LISTE_P lp , PRODUIT  p)
{
   LISTE_P lp1 = (struct cellule *) malloc(sizeof(struct cellule)) ,
                lp2 = (struct cellule *) malloc(sizeof(struct cellule));
   lp1->p = p;
   lp1->suivant = NULL;
    if(lp== NULL)
    {

        printf("Produit ajouter avec succes\n");
        return lp1;
    }
    lp2 = lp;
    while(lp2 ->suivant!= NULL)
    {
        //printf("%s\t%s\t%d\n\n" , lp2->p.code, lp2->p.libele, lp2->p.prix);
        lp2 = lp2->suivant;

    }

    lp2->suivant = lp1;
   
    return lp;

}

void affiche_liste(LISTE_P lp)
{
    if(liste_vide(lp))
    {

        printf("La liste est vide ");
        return;
    }
    printf("Code\tLibele\tPrix\n\n");
    struct cellule *lp1 = (struct cellule*)malloc(sizeof(struct cellule));
    lp1 = lp;
    while(lp1!=NULL)
    {
        printf("%s\t%s\t%d\n" , lp1->p.code,lp1->p.libele,lp1->p.prix);
        lp1 = lp1->suivant;
    }


    printf("\n");
}

LISTE_P search(LISTE_P p , char * code)
{
    struct cellule *p11;
    p11 = p;
    while(p11!=NULL)
    {
        if(strcmp(p11->p.code , code) == 0)
        {
            return p11;
        }
        p11 = p11->suivant;
    }

    return NULL;
}

void search1(LISTE_P p , char * code)
{
    LISTE_P p1 = (struct cellule*)malloc(sizeof(struct cellule));
    p1 = search(p , code);
    if(p1 == NULL)
    {
        printf("Le produit rechercher n'zxiste pas..\n");
        return;
    }
    printf("Code\tLibele\tPrix\n\n");
    printf("%s\t%s\t%d\n\n" , p1->p.code , p1->p.libele , p1->p.prix);
    return;
}

LISTE_P delete_p(LISTE_P lp, char * code){
    struct cellule * p1 ,*p;
    p1 = (struct cellule*)malloc(sizeof(struct cellule));

    p1 = search(lp,code);

    if(p1==NULL)
        printf("Le produit rechercher n'existe pas");
    else
    {
      p = p1;
      p1 = p1->suivant;
      free(p);
      printf("Le produit a ete suprimer avec success");
      return p1;
    }

  }

void menu()
{
    printf("1. Ajouter un produit\n");
    printf("2. Suprimer un produit\n");
    printf("3. Rechercher un produit\n");
    printf("4. Afficher les produit\n");
    printf("5. Enregistrer dans un fichier\n");
    printf("6. Lire a parti d'un fichier\n");
    printf("7. Trier les produit par  prix croissant\n");
    printf("8. Quiter\n\n");
}

int taille(LISTE_P p){
    LISTE_P lp;
    lp = p;
    int compteur = 0;
    while (lp!=NULL)
    {
        compteur = compteur+1;
        lp = lp->suivant;
    }
    return compteur;
}

int trie_bulle(LISTE_P lp){
    int nombre_p = taille(lp);
    int i;
    PRODUIT p;
    LISTE_P lp1 = (struct cellule*)malloc(sizeof(struct cellule));
    LISTE_P lp2 = (struct cellule*)malloc(sizeof(struct cellule));
    lp1 = lp;
    
    while (lp1->suivant!=NULL)
    {
        lp2 = lp1->suivant;
        for(i = 0;i<nombre_p - 1 - i;i++){
            if(lp1->p.prix > lp2->p.prix){

                p = lp1->p;
                lp1->p = lp2->p;
                lp2->p = p;

                // strcpy(code, lp1->p.code);
                // strcpy(libele, lp1->p.libele);
                // prix = lp1->p.prix;

                // strcpy(lp1->p.code , lp2->p.code);
                // strcpy(lp1->p.libele , lp2->p.libele);
                // lp1->p.prix = lp2->p.prix;

                // strcpy(lp2->p.code , code);
                // strcpy(lp2->p.libele , libele);
                // lp2->p.prix = prix;
            }
        }
        lp1 = lp2;
    }
    printf("Trier avec success\n");
    return TRUE;
    
    
}

void liste_to_file(char * nom_ficher , LISTE_P lp)
{
    FILE * fichier;
    if(lp == NULL){
        printf("La liste est vide");
        return;
    }
    fichier = fopen(nom_ficher , "a");
    LISTE_P lp1 = lp;
    while(lp1!=NULL)
    {
        fprintf(fichier , "%s %s %d\n" , lp1->p.code , lp1->p.libele , lp1->p.prix);
        lp1 = lp1->suivant;
    }
    fclose(fichier);
}

LISTE_P file_to_list(char * nom_fichier){
    FILE * fichier;
    fichier = fopen(nom_fichier , "r");
    LISTE_P lp = (LISTE_P)malloc(sizeof(LISTE_P));
    lp = NULL;
    PRODUIT * p = (PRODUIT*)malloc(sizeof(PRODUIT));
    while(fscanf(fichier , "%s %s %d" , p->code , p->libele , &p->prix) != EOF){
        //fscanf(fichier , "%s %s %d" , p->code , p->libele , &p->prix);
        lp = ajout_en_qeue(lp , *p);
    }
    fclose(fichier);
    return lp;
}

int main()
{
    LISTE_P lp , lp1;
    PRODUIT *p;

    lp = (struct cellule*)malloc(sizeof(struct cellule));
    lp = NULL;
    int choix , choi;
    char code[10];

    do
    {
        system("cls");
        menu();

        printf("Entrer votre choix :");
        scanf("%d" , &choix);
        printf("\n");

        switch (choix)
        {
        case 1:
            p = lire_produit();
            lp = ajout_en_qeue(lp , *p);
            printf("Produit ajouter deux avec succes\n");
            break;
        case 2:
            printf("Entrer le code du produit a suprimer :");
            scanf("%s" , code);
            lp = delete_p(lp , code);
            break;
        case 3:
            printf("Entrer le code :");
            scanf("%s" , code);
            search1(lp , code);
            break;
        case 4:
            affiche_liste(lp);
            break;
        case 5:
            printf("Entrez le nom du fichier :");
            scanf("%s" , code);
            liste_to_file(code , lp);
            break;
        case 6:
            printf("Entrez le nom du fichier :");
            scanf("%s" , code);
            lp1 = file_to_list(code);
            affiche_liste(lp1);
            break;
        case 7:
            trie_bulle(lp);
            break;
        case 8:
            return 0;

        default:
            printf("Entrer un chiffre compris entre 1 et 4\n");
            break;
        }

        printf("Entrer 0 pour continuer et 1 pour quiter :");
        scanf("%d" , &choi);
    }
    while(choi != 1);

    return 0;

}
