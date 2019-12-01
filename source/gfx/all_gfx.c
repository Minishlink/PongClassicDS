//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .c, for easier inclusion in a project

#ifdef __cplusplus
extern "C" {
#endif

#include "all_gfx.h"


// Sprite files : 
#include "balle.c"
#include "raquette.c"
#include "IA_easy.c"
#include "IA_normal.c"
#include "IA_hard.c"
#include "IA_invincible.c"
#include "arcade.c"
#include "adventure.c"

// Background files : 
#include "demoBG.c"
PAGfx_struct demoBG = {(void*)demoBG_Map, 768, (void*)demoBG_Tiles, 8640, (void*)demoBG_Pal, (int*)demoBG_Info };
#include "deuxJoueursBG.c"
PAGfx_struct deuxJoueursBG = {(void*)deuxJoueursBG_Map, 768, (void*)deuxJoueursBG_Tiles, 7872, (void*)deuxJoueursBG_Pal, (int*)deuxJoueursBG_Info };
#include "ecran_titre_bas.c"
PAGfx_struct ecran_titre_bas = {(void*)ecran_titre_bas_Map, 768, (void*)ecran_titre_bas_Tiles, 26816, (void*)ecran_titre_bas_Pal, (int*)ecran_titre_bas_Info };
#include "ecran_titre_haut.c"
PAGfx_struct ecran_titre_haut = {(void*)ecran_titre_haut_Map, 768, (void*)ecran_titre_haut_Tiles, 15296, (void*)ecran_titre_haut_Pal, (int*)ecran_titre_haut_Info };
#include "menu_bas.c"
PAGfx_struct menu_bas = {(void*)menu_bas_Map, 768, (void*)menu_bas_Tiles, 13760, (void*)menu_bas_Pal, (int*)menu_bas_Info };
#include "menu_haut.c"
PAGfx_struct menu_haut = {(void*)menu_haut_Map, 768, (void*)menu_haut_Tiles, 19328, (void*)menu_haut_Pal, (int*)menu_haut_Info };
#include "menu_choix_mode.c"
PAGfx_struct menu_choix_mode = {(void*)menu_choix_mode_Map, 768, (void*)menu_choix_mode_Tiles, 9856, (void*)menu_choix_mode_Pal, (int*)menu_choix_mode_Info };
#include "terrainBG.c"
PAGfx_struct terrainBG = {(void*)terrainBG_Map, 768, (void*)terrainBG_Tiles, 1984, (void*)terrainBG_Pal, (int*)terrainBG_Info };
#include "unJoueurBG.c"
PAGfx_struct unJoueurBG = {(void*)unJoueurBG_Map, 768, (void*)unJoueurBG_Tiles, 6912, (void*)unJoueurBG_Pal, (int*)unJoueurBG_Info };
#include "splash_haut.c"
PAGfx_struct splash_haut = {(void*)splash_haut_Map, 768, (void*)splash_haut_Tiles, 47424, (void*)splash_haut_Pal, (int*)splash_haut_Info };
#include "splash_bas.c"
PAGfx_struct splash_bas = {(void*)splash_bas_Map, 768, (void*)splash_bas_Tiles, 48896, (void*)splash_bas_Pal, (int*)splash_bas_Info };

// Palette files : 
#include "balle.pal.c"
#include "raquette.pal.c"
#include "IA_easy.pal.c"
#include "IA_normal.pal.c"
#include "IA_hard.pal.c"
#include "IA_invincible.pal.c"
#include "arcade_spr.pal.c"
#include "adventure_spr.pal.c"
#include "demoBG.pal.c"
#include "deuxJoueursBG.pal.c"
#include "ecran_titre_bas.pal.c"
#include "ecran_titre_haut.pal.c"
#include "menu_bas.pal.c"
#include "menu_haut.pal.c"
#include "menu_choix_mode.pal.c"
#include "terrainBG.pal.c"
#include "unJoueurBG.pal.c"
#include "splash_haut.pal.c"
#include "splash_bas.pal.c"


#ifdef __cplusplus
}
#endif

