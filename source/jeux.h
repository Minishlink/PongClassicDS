#ifndef DEF_JEUX
#define DEF_JEUX

#include "main.h"
#include "psychadelic.h"

#define DEF_SPEED_RAQUETTE 4
#define DEF_SPEED_BALLE    4

#define DEF_R_RAQUETTE 1
#define DEF_R_BALLE    2

#define DEF_FACILE     1
#define DEF_NORMAL     2
#define DEF_DIFFICILE  3
#define DEF_INVINCIBLE 4
#define DEF_ARCADE     5
#define DEF_AVENTURE   6

#define DEF_AVENTURE_NORMAL      7
#define DEF_AVENTURE_DIFFICILE   8

#define DEF_MODE_J1 1
#define DEF_MODE_J2 2

#define DEF_L 1
#define DEF_R 2

#define DEF_CLASSIC     1
#define DEF_PSYCHADELIC 0

#define PAD              0
#define STYLUS           1
#define MOTION           2
#define PAD_INVERSE      3
#define STYLUS_INVERSE   4
#define MOTION_INVERSE   5

u32 scoreJ1;
u32 scoreJ2;
u32 hScore[6];
u8 psyMode;

extern void unJoueur(u8 IAmode, bool classicMode);

extern void deuxJoueurs(void);

extern void wifiPlay(void);

extern void demo(void);

extern u8 getClassicMode(bool classicMode);
extern u8 attendre(u8 IAMode);
extern void testCollisions(s32 ballex, s32 balley, s32 raquette1y, s32 raquette2y, bool *versLaDroite, bool *versLeBas);
extern void replacerSprites(s32 *balley, s32 *ballex, s32 *raquette1y, s32 *raquette2y, bool *versLaDroite, u8 IAmode);
extern u8 changerIAmode(u8 IAmode, bool afficher);
extern void afficherIAmode(u8 IAmode);
extern u8 confirmationChangerIAmode(u8 IAmode, bool RL);
extern void afficherScore(void);
extern u8 modeAventure(u8 IAmode);
extern void afficherGameMode(bool classicMode);
extern void effetsGameMode(u8 toDo);
extern s32 doControls(s32 raquette1y);
extern void changeControls();
extern void afficherControls();

#endif
