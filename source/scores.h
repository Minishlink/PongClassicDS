#ifndef DEF_SCORES
#define DEF_SCORES

#include <stdio.h>  // nécessaire pour la gestion fichier
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fat.h"

extern void sauverHScores();
extern void chargerHScores();
extern void afficherHScores();

#endif
