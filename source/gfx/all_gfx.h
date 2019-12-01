//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif


// Sprite files : 
extern const unsigned char balle_Sprite[64] __attribute__ ((aligned (4))) ;  // Pal : balle_Pal
extern const unsigned char raquette_Sprite[256] __attribute__ ((aligned (4))) ;  // Pal : raquette_Pal
extern const unsigned char IA_easy_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : IA_easy_Pal
extern const unsigned char IA_normal_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : IA_normal_Pal
extern const unsigned char IA_hard_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : IA_hard_Pal
extern const unsigned char IA_invincible_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : IA_invincible_Pal
extern const unsigned char arcade_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : arcade_spr_Pal
extern const unsigned char adventure_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : adventure_spr_Pal

// Background files : 
extern const int demoBG_Info[3]; // BgMode, Width, Height
extern const unsigned short demoBG_Map[768] __attribute__ ((aligned (4))) ;  // Pal : demoBG_Pal
extern const unsigned char demoBG_Tiles[8640] __attribute__ ((aligned (4))) ;  // Pal : demoBG_Pal
extern PAGfx_struct demoBG; // background pointer

extern const int deuxJoueursBG_Info[3]; // BgMode, Width, Height
extern const unsigned short deuxJoueursBG_Map[768] __attribute__ ((aligned (4))) ;  // Pal : deuxJoueursBG_Pal
extern const unsigned char deuxJoueursBG_Tiles[7872] __attribute__ ((aligned (4))) ;  // Pal : deuxJoueursBG_Pal
extern PAGfx_struct deuxJoueursBG; // background pointer

extern const int ecran_titre_bas_Info[3]; // BgMode, Width, Height
extern const unsigned short ecran_titre_bas_Map[768] __attribute__ ((aligned (4))) ;  // Pal : ecran_titre_bas_Pal
extern const unsigned char ecran_titre_bas_Tiles[26816] __attribute__ ((aligned (4))) ;  // Pal : ecran_titre_bas_Pal
extern PAGfx_struct ecran_titre_bas; // background pointer

extern const int ecran_titre_haut_Info[3]; // BgMode, Width, Height
extern const unsigned short ecran_titre_haut_Map[768] __attribute__ ((aligned (4))) ;  // Pal : ecran_titre_haut_Pal
extern const unsigned char ecran_titre_haut_Tiles[15296] __attribute__ ((aligned (4))) ;  // Pal : ecran_titre_haut_Pal
extern PAGfx_struct ecran_titre_haut; // background pointer

extern const int menu_bas_Info[3]; // BgMode, Width, Height
extern const unsigned short menu_bas_Map[768] __attribute__ ((aligned (4))) ;  // Pal : menu_bas_Pal
extern const unsigned char menu_bas_Tiles[13760] __attribute__ ((aligned (4))) ;  // Pal : menu_bas_Pal
extern PAGfx_struct menu_bas; // background pointer

extern const int menu_haut_Info[3]; // BgMode, Width, Height
extern const unsigned short menu_haut_Map[768] __attribute__ ((aligned (4))) ;  // Pal : menu_haut_Pal
extern const unsigned char menu_haut_Tiles[19328] __attribute__ ((aligned (4))) ;  // Pal : menu_haut_Pal
extern PAGfx_struct menu_haut; // background pointer

extern const int menu_choix_mode_Info[3]; // BgMode, Width, Height
extern const unsigned short menu_choix_mode_Map[768] __attribute__ ((aligned (4))) ;  // Pal : menu_choix_mode_Pal
extern const unsigned char menu_choix_mode_Tiles[9856] __attribute__ ((aligned (4))) ;  // Pal : menu_choix_mode_Pal
extern PAGfx_struct menu_choix_mode; // background pointer

extern const int terrainBG_Info[3]; // BgMode, Width, Height
extern const unsigned short terrainBG_Map[768] __attribute__ ((aligned (4))) ;  // Pal : terrainBG_Pal
extern const unsigned char terrainBG_Tiles[1984] __attribute__ ((aligned (4))) ;  // Pal : terrainBG_Pal
extern PAGfx_struct terrainBG; // background pointer

extern const int unJoueurBG_Info[3]; // BgMode, Width, Height
extern const unsigned short unJoueurBG_Map[768] __attribute__ ((aligned (4))) ;  // Pal : unJoueurBG_Pal
extern const unsigned char unJoueurBG_Tiles[6912] __attribute__ ((aligned (4))) ;  // Pal : unJoueurBG_Pal
extern PAGfx_struct unJoueurBG; // background pointer

extern const int splash_haut_Info[3]; // BgMode, Width, Height
extern const unsigned short splash_haut_Map[768] __attribute__ ((aligned (4))) ;  // Pal : splash_haut_Pal
extern const unsigned char splash_haut_Tiles[47424] __attribute__ ((aligned (4))) ;  // Pal : splash_haut_Pal
extern PAGfx_struct splash_haut; // background pointer

extern const int splash_bas_Info[3]; // BgMode, Width, Height
extern const unsigned short splash_bas_Map[768] __attribute__ ((aligned (4))) ;  // Pal : splash_bas_Pal
extern const unsigned char splash_bas_Tiles[48896] __attribute__ ((aligned (4))) ;  // Pal : splash_bas_Pal
extern PAGfx_struct splash_bas; // background pointer


// Palette files : 
extern const unsigned short balle_Pal[2] __attribute__ ((aligned (4))) ;
extern const unsigned short raquette_Pal[2] __attribute__ ((aligned (4))) ;
extern const unsigned short IA_easy_Pal[33] __attribute__ ((aligned (4))) ;
extern const unsigned short IA_normal_Pal[33] __attribute__ ((aligned (4))) ;
extern const unsigned short IA_hard_Pal[33] __attribute__ ((aligned (4))) ;
extern const unsigned short IA_invincible_Pal[33] __attribute__ ((aligned (4))) ;
extern const unsigned short arcade_spr_Pal[33] __attribute__ ((aligned (4))) ;
extern const unsigned short adventure_spr_Pal[33] __attribute__ ((aligned (4))) ;
extern const unsigned short demoBG_Pal[14] __attribute__ ((aligned (4))) ;
extern const unsigned short deuxJoueursBG_Pal[14] __attribute__ ((aligned (4))) ;
extern const unsigned short ecran_titre_bas_Pal[48] __attribute__ ((aligned (4))) ;
extern const unsigned short ecran_titre_haut_Pal[33] __attribute__ ((aligned (4))) ;
extern const unsigned short menu_bas_Pal[33] __attribute__ ((aligned (4))) ;
extern const unsigned short menu_haut_Pal[33] __attribute__ ((aligned (4))) ;
extern const unsigned short menu_choix_mode_Pal[186] __attribute__ ((aligned (4))) ;
extern const unsigned short terrainBG_Pal[14] __attribute__ ((aligned (4))) ;
extern const unsigned short unJoueurBG_Pal[14] __attribute__ ((aligned (4))) ;
extern const unsigned short splash_haut_Pal[188] __attribute__ ((aligned (4))) ;
extern const unsigned short splash_bas_Pal[188] __attribute__ ((aligned (4))) ;


#endif

