// Includes
#include <PA9.h>       // Include for PA_Lib
#include "gfx/all_gfx.c"
#include "MessageQueue.h"	// Includes for liblobby
#include "802.11.h"
#include "lobby.h"

#include "main.h"
#include "effects.h"

#include "MusicPong01.h"
#include "matrix.h"

//function : main()
int main(int argc, char ** argv)
{
	PA_Init();    // Initializes PA_Lib

	PA_InitText(1, 2);
	PA_OutputSimpleText(1, 0, 0, "PAlib -> Ok");
	PA_OutputSimpleText(1, 0, 1, "Init VBL   ");
	PA_InitVBL(); // Initializes a standard VBL
	PA_OutputSimpleText(1, 0, 1, "VBL -> Ok  ");
	PA_OutputSimpleText(1, 0, 2, "Init Rand  ");
	PA_InitRand();
	PA_OutputSimpleText(1, 0, 2, "Rand -> Ok ");
	PA_OutputSimpleText(1, 0, 3, "Init Sound ");
	PA_InitSound();
	PA_OutputSimpleText(1, 0, 3, "Sound -> Ok");
	PA_OutputSimpleText(1, 0, 4, "Init IPC ");
	IPC_Init();
	PA_OutputSimpleText(1, 0, 4, "IPC -> Ok");
    PA_OutputSimpleText(1, 0, 5, "Init DLDI  ");
    if(!fatInitDefault()) while(1);
    PA_OutputSimpleText(1, 0, 5, "DLDI -> Ok ");

    splashScreen();

	return 0;
} // End of main()

void splashScreen(void)
{
    PA_Init2D();

    PA_PlayMod(matrix);

    PA_LoadTiledBg(1, 3, splash_haut);
	PA_LoadTiledBg(0, 3, splash_bas);

	fadeIn(2);

	bool clic = false;
	while(!clic)
	{
	    if((Stylus.Released) || (Pad.Released.Start) || (Pad.Released.A)) { clic = true; }
		PA_WaitForVBL();
	}

    fadeOut(0);
	ecranTitre();

}

void ecranTitre(void)
{
    PA_Init2D();

    PA_PlayMod(MusicPong01);

    PA_LoadTiledBg(1, 3, ecran_titre_haut);
	PA_LoadTiledBg(0, 3, ecran_titre_bas);

	bool clic = false;
	fadeIn(2);

	while(1)
	{
	    if(Stylus.Released) { clic = true; }
        if((Pad.Released.A) || (Pad.Newpress.Start) || ((Stylus.Newpress) && (clic))) { choixNbJoueurs(2); }

		PA_WaitForVBL();
	}
}


void choixNbJoueurs(u8 ecranAlpha)
{
	PA_Init2D();

	PA_PlayMod(MusicPong01);

	PA_LoadTiledBg(1, 3, menu_haut);
	PA_LoadTiledBg(0, 3, menu_bas);

	fadeIn(ecranAlpha);

	while(1)
	{
        if((Pad.Newpress.X) || (((PA_StylusInZone(30, 87, 88, 103)) && (Stylus.Released)))) { fadeOut(0); choixMode(1, 0); }
		else if((Pad.Newpress.Y) || ((PA_StylusInZone(30, 105, 142, 121)) && (Stylus.Released))) { fadeOut(2); deuxJoueurs(); }
		else if((Pad.Held.A) || ((PA_StylusInZone(30, 122, 84, 137)) && (Stylus.Released))) { fadeOut(2); wifiPlay(); }
		else if((Stylus.Released) && (PA_StylusInZone(0, 178, 176, 192))) { fadeOut(2); demo(); }
		else if((Pad.Newpress.B) || ((PA_StylusInZone(30, 140, 145, 155) && (Stylus.Released)))) { fadeOut(2); ecranTitre(); }

		PA_WaitForVBL();
	}
}

void choixMode(bool modeUnJoueur, u8 ecranAlpha)
{
    PA_Init2D();

    PA_LoadTiledBg(1, 3, menu_haut);
	PA_LoadTiledBg(0, 3, menu_choix_mode);

    PA_LoadSpritePal(0, 0, (void*)IA_easy_Pal);
	PA_CreateSprite(0, 0, (void*)IA_easy_Sprite, OBJ_SIZE_64X32, 1, 0, 0, 76); //Classic
	PA_CreateSprite(0, 6, (void*)IA_easy_Sprite, OBJ_SIZE_64X32, 1, 0, 135, 80); //Psychadelic
	PA_SetSpritePrio(0, 6, 3);
	PA_LoadSpritePal(0, 1, (void*)IA_normal_Pal);
	PA_CreateSprite(0, 1, (void*)IA_normal_Sprite, OBJ_SIZE_64X32, 1, 1, 0, 115); //Classic
	PA_CreateSprite(0, 7, (void*)IA_normal_Sprite, OBJ_SIZE_64X32, 1, 1, 135, 119); //Psychadelic
	PA_SetSpritePrio(0, 7, 3);
	PA_LoadSpritePal(0, 2, (void*)IA_hard_Pal);
	PA_CreateSprite(0, 2, (void*)IA_hard_Sprite, OBJ_SIZE_64X32, 1, 2, 67, 76); //Classic
	PA_CreateSprite(0, 8, (void*)IA_hard_Sprite, OBJ_SIZE_64X32, 1, 2, 195, 80); //Psychadelic
	PA_SetSpritePrio(0, 8, 0);
	PA_LoadSpritePal(0, 3, (void*)IA_invincible_Pal);
	PA_CreateSprite(0, 3, (void*)IA_invincible_Sprite, OBJ_SIZE_64X32, 1, 3, 67, 115); //Classic
	PA_CreateSprite(0, 9, (void*)IA_invincible_Sprite, OBJ_SIZE_64X32, 1, 3, 195, 119); //Psychadelic
	PA_SetSpritePrio(0, 9, 0);
	PA_LoadSpritePal(0, 4, (void*)arcade_spr_Pal);
	PA_CreateSprite(0, 4, (void*)arcade_Sprite, OBJ_SIZE_64X32, 1, 4, 0, 152); //Classic
	PA_CreateSprite(0, 10, (void*)arcade_Sprite, OBJ_SIZE_64X32, 1, 4, 135, 156); //Psychadelic
	PA_SetSpritePrio(0, 10, 3);
	PA_LoadSpritePal(0, 5, (void*)adventure_spr_Pal);
	PA_CreateSprite(0, 5, (void*)adventure_Sprite, OBJ_SIZE_64X32, 1, 5, 67, 152); //Classic
	PA_CreateSprite(0, 11, (void*)adventure_Sprite, OBJ_SIZE_64X32, 1, 5, 195, 156); //Psychadelic
	PA_SetSpritePrio(0, 11, 0);

	PA_PlayMod(MusicPong01);
	fadeIn(ecranAlpha);

	while(1)
	{
		if((Pad.Released.B) && (!Pad.Held.A)) { fadeOut(0); choixNbJoueurs(0); }
		// -------------- Classic Mode --------------
		else if (((Pad.Held.A) && (Pad.Released.X) && (!Pad.Held.L)) || (PA_SpriteTouched(0))) { fadeOut(2); unJoueur(DEF_FACILE, DEF_CLASSIC); }
		else if (((Pad.Released.A)  && (!Pad.Held.L)) || (PA_SpriteTouched(1))) { fadeOut(2); unJoueur(DEF_NORMAL, DEF_CLASSIC); }
		else if (((Pad.Held.A) && (Pad.Released.B) && (!Pad.Held.L)) || (PA_SpriteTouched(2))) { fadeOut(2); unJoueur(DEF_DIFFICILE, DEF_CLASSIC); }
		else if (((Pad.Held.A) && (Pad.Released.Y) && (!Pad.Held.L)) || (PA_SpriteTouched(3))) { fadeOut(2); unJoueur(DEF_INVINCIBLE, DEF_CLASSIC); }
		else if (((Pad.Released.X) && (!Pad.Held.A) && (!Pad.Held.L)) || (PA_SpriteTouched(4))) { fadeOut(2); unJoueur(DEF_ARCADE, DEF_CLASSIC); }
		else if (((Pad.Released.Y) && (!Pad.Held.A) && (!Pad.Held.L)) || (PA_SpriteTouched(5))) { fadeOut(2); unJoueur(DEF_AVENTURE, DEF_CLASSIC); }
		// -------------- Psychadelic Mode --------------
		else if (((Pad.Held.L) && (Pad.Held.A) && (Pad.Released.X)) || (PA_SpriteTouched(6))) { fadeOut(2); unJoueur(DEF_FACILE, DEF_PSYCHADELIC); }
		else if (((Pad.Held.L) && (Pad.Released.A)) || (PA_SpriteTouched(1))) { fadeOut(7); unJoueur(DEF_NORMAL, DEF_PSYCHADELIC); }
		else if (((Pad.Held.L) && (Pad.Held.A) && (Pad.Released.B)) || (PA_SpriteTouched(8))) { fadeOut(2); unJoueur(DEF_DIFFICILE, DEF_PSYCHADELIC); }
		else if (((Pad.Held.L) && (Pad.Held.A) && (Pad.Released.Y)) || (PA_SpriteTouched(9))) { fadeOut(2); unJoueur(DEF_INVINCIBLE, DEF_PSYCHADELIC); }
		else if (((Pad.Held.L) && (Pad.Released.X) && (!Pad.Held.A)) || (PA_SpriteTouched(10))) { fadeOut(2); unJoueur(DEF_ARCADE, DEF_PSYCHADELIC); }
		else if (((Pad.Held.L) && (Pad.Released.Y) && (!Pad.Held.A)) || (PA_SpriteTouched(11))) { fadeOut(2); unJoueur(DEF_AVENTURE, DEF_PSYCHADELIC); }

		PA_WaitForVBL();
	}
}





