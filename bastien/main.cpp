#include <QCoreApplication>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int placeDansTab(char **tab, char *str, int taille, int* placer)
{
    int x;
    int y;
    int dir;
    int taille_mot = strlen(str);
    int isok = 0;
    int gauche = 0;
    int droit = 0;
    int haut = 0;
    int bas = 0;
    int p;
    int m;
    int compteurDessais = 0;
    *placer = 0;

    x = rand()%(taille);
    y = rand()%(taille);
    dir = rand()%(4);
    switch (dir) {
    case 0:
    {
            while (!isok) {
                ++compteurDessais;
                if (((x + taille_mot) <= taille) || ((x - taille_mot) >= 0))
                {
                    if ((x + taille_mot) <= taille)
                    {
                        droit=1;
                        p = x;
                        m = y;
                        isok = 1;
                        for (int i = 0; i<taille_mot;++i) {
                            if (tab[m][p] != str[i] && tab[m][p] != '.') {
                                isok = 0;
                            }
                            p = p + droit - gauche;
                            m = m + bas - haut;
                        }
                    }
                    else
                    {

                        gauche=1;
                        p = x;
                        m = y;
                        isok = 1;
                        for (int i = 0; i<taille_mot;++i) {
                            if (tab[m][p] != str[i] && tab[m][p] != '.') {
                                isok = 0;
                            }
                            p = p + droit - gauche;
                            m = m + bas - haut;
                        }
                    }

                }
                else
                {
                    x = rand()%(taille);
                    y = rand()%(taille);
                }
                //si on a pas isok a cause de la verif, on random a nouveau
                if (!isok) {
                    x = rand()%(taille);
                    y = rand()%(taille);
                }
                //on verifie que que le mot soit placable
                if (compteurDessais == 50 && !isok) {
                    *placer = 0;
                    return 1;
                }
            }
            break;

    }
    case 1:
    {
        while (!isok) {
            ++compteurDessais;
            if (((y + taille_mot) <= taille) || ((y - taille_mot) >= 0))
            {
               if ((y+taille_mot) <= taille)
               {
                   bas = 1;
                   p = x;
                   m = y;
                   isok = 1;
                   for (int i = 0; i<taille_mot;++i) {
                       if (tab[m][p] != str[i] && tab[m][p] != '.') {
                           isok = 0;
                       }
                       p = p + droit - gauche;
                       m = m + bas - haut;
                   }
               }
               else
               {
                   haut=1;
                   p = x;
                   m = y;
                   isok = 1;
                   for (int i = 0; i<taille_mot;++i) {
                       if (tab[m][p] != str[i] && tab[m][p] != '.') {
                           isok = 0;
                       }
                       p = p + droit - gauche;
                       m = m + bas - haut;
                   }
               }

            }
            else
            {
                x = rand()%(taille);
                y = rand()%(taille);
            }
            //si on a pas isok a cause de la verif, on random a nouveau
            if (!isok) {
                x = rand()%(taille);
                y = rand()%(taille);
            }
            //on verifie que que le mot soit placable
            if (compteurDessais == 50 && !isok) {
                *placer = 0;
                return 1;
            }
        }
        break;
    }
    case 2:
    {
        while (!isok) {
            ++compteurDessais;
            if ((((x - taille_mot) >= 0) && ((y + taille_mot) <= taille)) || (((y - taille_mot) >= 0) && ((x + taille_mot) <= taille)))
            {
                if (((x + taille_mot) <= taille) && ((y - taille_mot) >= 0))
                {
                    haut = 1;
                    droit = 1;
                    p = x;
                    m = y;
                    isok = 1;
                    for (int i = 0; i<taille_mot;++i) {
                        if (tab[m][p] != str[i] && tab[m][p] != '.') {
                            isok = 0;
                        }
                        p = p + droit - gauche;
                        m = m + bas - haut;
                    }
                }
                else if (((x - taille_mot) >= 0) && ((y + taille_mot) <= taille))
                {
                    bas = 1;
                    gauche = 1;
                    p = x;
                    m = y;
                    isok = 1;
                    for (int i = 0; i<taille_mot;++i) {
                        if (tab[m][p] != str[i] && tab[m][p] != '.') {
                            isok = 0;
                        }
                        p = p + droit - gauche;
                        m = m + bas - haut;
                    }
                }
            }
            else
            {
                x = rand()%(taille);
                y = rand()%(taille);
            }
            //si on a pas isok a cause de la verif, on random a nouveau
            if (!isok) {
                x = rand()%(taille);
                y = rand()%(taille);
            }
            //on verifie que que le mot soit placable
            if (compteurDessais == 50 && !isok) {
                *placer = 0;
                return 1;
            }
        }
        break;
    }
    case 3:
    {
        while (!isok) {
            ++compteurDessais;
            if ((((x + taille_mot) <= taille) && ((y + taille_mot) <= taille)) ||(((x - taille_mot) >= 0) && ((y - taille_mot) >= 0)))
            {
                if (((x + taille_mot) <= taille) && ((y + taille_mot) <= taille))
                {
                    droit = 1;
                    bas = 1;
                    p = x;
                    m = y;
                    isok = 1;
                    for (int i = 0; i<taille_mot;++i) {
                        if (tab[m][p] != str[i] && tab[m][p] != '.') {
                            isok = 0;
                        }
                        p = p + droit - gauche;
                        m = m + bas - haut;
                    }
                }
                else if (((x - taille_mot) >= 0) && ((y - taille_mot) >= 0))
                {
                    gauche = 1;
                    haut = 1;
                    p = x;
                    m = y;
                    isok = 1;
                    for (int i = 0; i<taille_mot;++i) {
                        if (tab[m][p] != str[i] && tab[m][p] != '.') {
                            isok = 0;
                        }
                        p = p + droit - gauche;
                        m = m + bas - haut;
                    }
                }
            }
            else
            {
                x = rand()%(taille);
                y = rand()%(taille);
            }
            //si on a pas isok a cause de la verif, on random a nouveau
            if (!isok) {
                x = rand()%(taille);
                y = rand()%(taille);
            }
            //on verifie que que le mot soit placable
            if (compteurDessais == 50 && !isok) {
                *placer = 0;
                return 1;
            }
        }
        break;
    }
    default:
    {
        EXIT_FAILURE;
        break;
    }
    }
    for(int i = 0 ; str[i] != '\0'; i++)
    {
        tab[y][x] = str[i];
        x = x +droit - gauche;
        y = y + bas - haut;
        *placer = 1;
    }
    return 1;
}

void remplir(char** tab, int taille) {
    char caractereAlea;
    for(int i = 0 ; i < taille ; ++i){
        for(int j = 0; j < taille; ++j){
            if (tab[i][j] == '.') {
                caractereAlea = ( rand() % ( ( 90 - 65 ) + 1) ) + 65;
                tab[i][j] = caractereAlea;
            }
        }
    }
}

void placeMot(char** tab, int taille) {
    int placer;
    srand(time(0));
    if(taille >= 3) {
        char caractereLu;
        placer = 0;

        //Ouvre le fichier
        FILE *fichier;
        fichier = fopen("3lettres.txt", "r");
        if (fichier == NULL) {
            perror("Erreur : Pas de fichier valide !");
            exit(EXIT_FAILURE);
        }

        char* mot;
        mot = (char*)malloc(sizeof(char)*4);

        //on prend un mot au pif
        int ligneFichier = rand()%(300 - 1) +1;
        if (fichier != NULL) {
            while (ligneFichier > 0) {
                caractereLu = fgetc(fichier);
                    if (caractereLu == '\n') {
                        ligneFichier--;
                    }
            }
            fgets(mot, 4, fichier);
            printf("%s\n", mot);
        }
        fclose(fichier);

        //place le mot
        placeDansTab(tab, mot, taille, &placer);
        free(mot);
    }
    if(taille >= 4) {
        placer = 0;
        char caractereLu;

        //Ouvre le fichier
        FILE *fichier = fopen("4lettres.txt", "r");
        if (fichier == NULL) {
            perror("Erreur : Pas de fichier valide !");
            exit(EXIT_FAILURE);
        }

        char* mot;
        mot = (char*)malloc(sizeof(char)*5);

        //on prend un mot au pif
        int ligneFichier = rand()%(300 - 1) +1;
        if (fichier != NULL) {
            while (ligneFichier > 0) {
                caractereLu = fgetc(fichier);
                    if (caractereLu == '\n') {
                        ligneFichier--;
                    }
            }
            fgets(mot, 5, fichier);
            printf("%s\n", mot);
        }
        fclose(fichier);

        //place le mot
        placeDansTab(tab, mot, taille, &placer);
        free(mot);
    }
    if(taille >= 5) {
        placer = 0;
        char caractereLu;

        //Ouvre le fichier
        FILE *fichier = fopen("5lettres.txt", "r");
        if (fichier == NULL) {
            perror("Erreur : Pas de fichier valide !");
            exit(EXIT_FAILURE);
        }

        char* mot;
        mot = (char*)malloc(sizeof(char)*6);

        //on prend un mot au pif
        int ligneFichier = rand()%(300 - 1) +1;
        if (fichier != NULL) {
            while (ligneFichier > 0) {
                caractereLu = fgetc(fichier);
                    if (caractereLu == '\n') {
                        ligneFichier--;
                    }
            }
            fgets(mot, 6, fichier);
            printf("%s\n", mot);
        }
        fclose(fichier);

        //place le mot
        placeDansTab(tab, mot, taille, &placer);
        free(mot);
    }
    if(taille >= 6) {
        placer = 0;
        char caractereLu;

        //Ouvre le fichier
        FILE *fichier = fopen("6lettres.txt", "r");
        if (fichier == NULL) {
            perror("Erreur : Pas de fichier valide !");
            exit(EXIT_FAILURE);
        }

        char* mot;
        mot = (char*)malloc(sizeof(char)*7);

        //on prend un mot au pif
        int ligneFichier = rand()%(300 - 1) +1;
        if (fichier != NULL) {
            while (ligneFichier > 0) {
                caractereLu = fgetc(fichier);
                    if (caractereLu == '\n') {
                        ligneFichier--;
                    }
            }
            fgets(mot, 7, fichier);
            printf("%s\n", mot);
        }
        fclose(fichier);

        //place le mot
        placeDansTab(tab, mot, taille, &placer);
        free(mot);
    }
    if(taille >= 7) {
        placer = 0;
        char caractereLu;

        //Ouvre le fichier
        FILE *fichier = fopen("7lettres.txt", "r");
        if (fichier == NULL) {
            perror("Erreur : Pas de fichier valide !");
            exit(EXIT_FAILURE);
        }

        char* mot;
        mot = (char*)malloc(sizeof(char)*8);

        //on prend un mot au pif
        int ligneFichier = rand()%(300 - 1) +1;
        if (fichier != NULL) {
            while (ligneFichier > 0) {
                caractereLu = fgetc(fichier);
                    if (caractereLu == '\n') {
                        ligneFichier--;
                    }
            }
            fgets(mot, 8, fichier);
            printf("%s\n", mot);
        }
        fclose(fichier);

        //place le mot
        placeDansTab(tab, mot, taille, &placer);
        free(mot);
    }
    if(taille >= 8) {
        placer = 0;
        char caractereLu;

        //Ouvre le fichier
        FILE *fichier = fopen("8lettres.txt", "r");
        if (fichier == NULL) {
            perror("Erreur : Pas de fichier valide !");
            exit(EXIT_FAILURE);
        }

        char* mot;
        mot = (char*)malloc(sizeof(char)*9);

        //on prend un mot au pif
        int ligneFichier = rand()%(300 - 1) +1;
        if (fichier != NULL) {
            while (ligneFichier > 0) {
                caractereLu = fgetc(fichier);
                    if (caractereLu == '\n') {
                        ligneFichier--;
                    }
            }
            fgets(mot, 9, fichier);
            printf("%s\n", mot);
        }
        fclose(fichier);

        //place le mot
        placeDansTab(tab, mot, taille, &placer);
        free(mot);
    }
    if(taille >= 9) {
        placer = 0;
        char caractereLu;

        //Ouvre le fichier
        FILE *fichier = fopen("9lettres.txt", "r");
        if (fichier == NULL) {
            perror("Erreur : Pas de fichier valide !");
            exit(EXIT_FAILURE);
        }

        char* mot;
        mot = (char*)malloc(sizeof(char)*10);

        //on prend un mot au pif
        int ligneFichier = rand()%(300 - 1) +1;
        if (fichier != NULL) {
            while (ligneFichier > 0) {
                caractereLu = fgetc(fichier);
                    if (caractereLu == '\n') {
                        ligneFichier--;
                    }
            }
            fgets(mot, 10, fichier);
            printf("%s\n", mot);
        }
        fclose(fichier);

        //place le mot
        placeDansTab(tab, mot, taille, &placer);
        free(mot);
    }
    if(taille >= 10) {
        placer = 0;
        char caractereLu;

        //Ouvre le fichier
        FILE *fichier = fopen("10lettres.txt", "r");
        if (fichier == NULL) {
            perror("Erreur : Pas de fichier valide !");
            exit(EXIT_FAILURE);
        }

        char* mot;
        mot = (char*)malloc(sizeof(char)*11);

        //on prend un mot au pif
        int ligneFichier = rand()%(300 - 1) +1;
        if (fichier != NULL) {
            while (ligneFichier > 0) {
                caractereLu = fgetc(fichier);
                    if (caractereLu == '\n') {
                        ligneFichier--;
                    }
            }
            fgets(mot, 11, fichier);
            printf("%s\n", mot);
        }
        fclose(fichier);

        //place le mot
        placeDansTab(tab, mot, taille, &placer);
        free(mot);
    }
}

char** creationTableau (int taille) {
    //création d'un tableau
    char** tab;
    tab = (char**)malloc(sizeof(char*) * taille);
    for (unsigned int i=0;i<taille;++i) {
        tab[i] = (char*)malloc(sizeof(char) * taille);
    }
    //initialise avec des points
    for (int j=0;j<taille;++j) {
        for (int z=0;z<taille;++z) {
            tab[j][z] = '.';
        }
    }
    return tab;
}

void imprimer (char** tab, int taille) {
    FILE* fichier;
    fichier = fopen("imprimer.txt", "w");
    for (int i=0;i<taille;++i) {
        for (int j=0;j<taille;++j) {
            fputc(tab[i][j], fichier);
        }
        fputc('\n', fichier);
    }
    fclose(fichier);
}



int main()
{
    char** tab;
    int taille;

    //demande de la taille (grille carrée)
    printf("Quelle taille de grille voulez-vous ? ");
    scanf("%d", &taille);
    getchar();

    //création de la grille
    tab = creationTableau(taille);

    //place des mots
    placeMot(tab, taille);

    //remplie les vides
    remplir(tab, taille);

    //créer un fichier texte imprimable
    imprimer(tab, taille);

    //affichage de la grille
    printf("\n\n\n");

    //affiche une ligne au dessus de la grille
    printf("%.*s\n", taille, "_");

    for (int i=0; i<taille; ++i) {
    printf("|");
        for (int j=0; j<taille; ++j) {
            printf("%c", tab[i][j]);
        }
        printf("|\n");
    }

    //affiche une ligne au dessous de la grille
    printf("%.*s\n", taille, "_");

    return 0;
}
