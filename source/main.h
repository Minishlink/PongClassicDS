#ifndef DEF_MAIN
#define DEF_MAIN

#include "gfx/all_gfx.h"
#include "jeux.h"

#include <stdio.h>  // nécessaire pour la gestion fichier
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fat.h"

extern void ecranTitre(void);
extern void splashScreen(void);
extern void choixNbJoueurs(u8 ecranAlpha);
extern void choixMode(bool modeUnJoueur, u8 ecranAlpha);

#endif
