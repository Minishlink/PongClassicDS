// Includes
#include <PA9.h>       // Include for PA_Lib
#include "jeux.h"
#include "effects.h"

#include "MusicPong02.h"


void deuxJoueurs(void)
{
    PA_Init2D();
    PA_Init16cBg(1, 2);
    PA_InitRand();

    PA_LoadTiledBg(1, 3, terrainBG);
    PA_LoadTiledBg(0, 3, deuxJoueursBG);

	s32 raquette1y = 80, raquette2y = 80, ballex = 124, balley = 96;
	bool versLaDroite = PA_RandMinMax(0, 1);
	bool versLeBas = PA_RandMinMax(0, 1);
	bool pause = 1;

	scoreJ1 = 0;
	scoreJ2 = 0;

    PA_LoadSpritePal(1, 0, (void*)balle_Pal);
	PA_CreateSprite(1, 0, (void*)balle_Sprite, OBJ_SIZE_8X8, 1, 0, ballex, balley);

	PA_CreateSprite(1, 1, (void*)raquette_Sprite, OBJ_SIZE_8X32, 1, 0, 10, raquette1y);
	PA_CreateSprite(1, 2, (void*)raquette_Sprite, OBJ_SIZE_8X32, 1, 0, 237, raquette2y);

	PA_PlayMod(MusicPong02);
	fadeIn(2);

	while(1)
	{
		if(Pad.Newpress.Start) { fadeOut(2); choixNbJoueurs(2); }
		if(Pad.Newpress.Select) { if(!pause) pause = 1; else pause = 0; }


        if(!pause)
        {
            if(raquette1y == 144) raquette1y -= Pad.Held.Up * DEF_SPEED_RAQUETTE;
			else if (raquette1y == 16) raquette1y += Pad.Held.Down * DEF_SPEED_RAQUETTE;
			else raquette1y += (Pad.Held.Down - Pad.Held.Up) * DEF_SPEED_RAQUETTE;

			if(raquette2y == 144) raquette2y -= Pad.Held.X * DEF_SPEED_RAQUETTE;
			else if (raquette2y == 16) raquette2y += Pad.Held.B * DEF_SPEED_RAQUETTE;
			else raquette2y += (Pad.Held.B - Pad.Held.X) * DEF_SPEED_RAQUETTE;

            if(versLaDroite) { ballex += DEF_SPEED_BALLE; }
			else { ballex -= DEF_SPEED_BALLE; }
			if(versLeBas) { balley += DEF_SPEED_BALLE; }
			else { balley -= DEF_SPEED_BALLE; }

            testCollisions(ballex, balley, raquette1y, raquette2y, &versLaDroite, &versLeBas);

			//On replace les sprites
			PA_SetSpriteXY(1, 0, ballex, balley);
			PA_SetSpriteXY(1, 1, 10, raquette1y);
			PA_SetSpriteXY(1, 2, 237, raquette2y);

			//Gestion des Scores
			if(ballex <= -3)
			{
                scoreJ2++;
				replacerSprites(&balley, &ballex, &raquette1y, &raquette2y, &versLaDroite, 0);
				attendre(0);
			}
			else if(ballex >= 250)
			{
                scoreJ1++;
				replacerSprites(&balley, &ballex, &raquette1y, &raquette2y, &versLaDroite, 0);
				attendre(0);
			}
		}

		afficherScore();

		PA_WaitForVBL();
		PA_16cErase(1);
	}
}


