// Includes
#include <PA9.h>       // Include for PA_Lib

#include "jeux.h"
#include "scores.h"

void sauverHScores()
{
    FILE* fichier = NULL;
    char text[256] = "";

	fichier = fopen("/PongClassicDS.sav", "w+"); //On ouvre le fichier en mode lecture + écriture

	//Si l'ouverture a fonctionnée
	if (fichier != NULL)
	{
	    rewind(fichier);

	    if(scoreJ1 > hScore[0])
	    {
            sprintf(text, "%ld %ld\n%ld %ld\n%ld %ld", scoreJ1, scoreJ2, hScore[0], hScore[1], hScore[2], hScore[3]);
	    }
	    else if((scoreJ1 > hScore[2]) && (scoreJ1 < hScore[0]))
	    {
	        sprintf(text, "%ld %ld\n%ld %ld\n%ld %ld", hScore[0], hScore[1], scoreJ1, scoreJ2, hScore[2], hScore[3]);
	    }
	    else if((scoreJ1 > hScore[4]) && (scoreJ1 < hScore[2]))
	    {
	        sprintf(text, "%ld %ld\n%ld %ld\n%ld %ld", hScore[0], hScore[1], hScore[2], hScore[3], scoreJ1, scoreJ2);
	    }

        fwrite(text, 256, 1, fichier);
	    fclose(fichier); //On ferme le fichier
	}
    //Si l'ouverture n'a pas fonctionnée
	else
	{
	    while(1)
	    {
            PA_Init2D();
            // On affiche un message d'erreur
            PA_OutputSimpleText(1, 0, 10, "ERREUR: Ouverture du fichier échouée lors de la sauvegarde des Scores");
	    }
	}
}

void chargerHScores() // On peut facilement, grâce à ce pointeur, envoyer les données des highscores à la fonction qui gère l'affichage
{
    FILE *fichier = NULL;
	fichier = fopen("/PongClassicDS.sav", "r"); // On ouvre le fichier en mode lecture

	// Si l'ouverture a fonctionné
	if (fichier != NULL)
	{
        // On prend les valeurs des HighScores
        fscanf(fichier, "%ld %ld\n%ld %ld\n%ld %ld", &hScore[0], &hScore[1], &hScore[2], &hScore[3], &hScore[4], &hScore[5]); // On scan le fichier d'abord, puis on rentre les nombres scannés dans les var du tableau score[0] et score[1]
        fclose(fichier); // On ferme le fichier
	}
	// Si l'ouverture n'a pas fonctionné
	else
	{
        hScore[0] = 0;
        hScore[1] = 0;
        hScore[2] = 0;
        hScore[3] = 0;
        hScore[4] = 0;
        hScore[5] = 0;
	}
}

void afficherHScores()
{
    char text[256] = "";

    sprintf(text, "[1] Echanges :  %ld - Temps : %ld", hScore[0], hScore[1]);
    PA_16cText(0, 20, 120, 255, 192, text, 1, 2, 100);
    sprintf(text, "[2] Echanges :  %ld - Temps : %ld", hScore[2], hScore[3]);
    PA_16cText(0, 20, 140, 255, 192, text, 1, 2, 100);
    sprintf(text, "[3] Echanges :  %ld - Temps : %ld", hScore[4], hScore[5]);
    PA_16cText(0, 20, 160, 255, 192, text, 1, 2, 100);
}
