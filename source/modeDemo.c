// Includes
#include <PA9.h>       // Include for PA_Lib
#include "jeux.h"
#include "ia.h"
#include "effects.h"

#include "MusicPong02.h"


void demo(void)
{
    PA_Init2D();
    PA_Init16cBg(1, 2);
    PA_InitRand();

    PA_LoadTiledBg(1, 3, terrainBG);
    PA_LoadTiledBg(0, 3, demoBG);

    s32 raquette1y = 80, raquette2y = 80, ballex = 124, balley = 96;
	bool versLaDroite = PA_RandMinMax(0, 1);
	bool versLeBas = PA_RandMinMax(0, 1);
	bool pause = 1;

	scoreJ1 = 0;
	scoreJ2 = 0;

	u8 iaModeDemo1 = 0, iaModeDemo2 = 0;
	iaChoisirDemo(&iaModeDemo1, &iaModeDemo2);

    PA_LoadSpritePal(1, 0, (void*)balle_Pal);
	PA_CreateSprite(1, 0, (void*)balle_Sprite, OBJ_SIZE_8X8, 1, 0, ballex, balley);

	PA_CreateSprite(1, 1, (void*)raquette_Sprite, OBJ_SIZE_8X32, 1, 0, 10, raquette1y);
	PA_CreateSprite(1, 2, (void*)raquette_Sprite, OBJ_SIZE_8X32, 1, 0, 237, raquette2y);

	PA_PlayMod(MusicPong02);
	fadeIn(2);
	clignoter(2,2);


	while(1)
	{
	   if(PA_StylusInZone(0, 0, 47, 21)) { fadeOut(2); choixNbJoueurs(2); }
	   if(Pad.Newpress.Select) { if(!pause) pause = 1; else pause = 0; }

	   if(!pause)
	   {
            if(versLaDroite) { ballex += DEF_SPEED_BALLE; }
			else { ballex -= DEF_SPEED_BALLE; }
			if(versLeBas) { balley += DEF_SPEED_BALLE; }
			else { balley -= DEF_SPEED_BALLE; }

            iaDemo(iaModeDemo1, iaModeDemo2, &raquette1y, &raquette2y, balley);

			testCollisions(ballex, balley, raquette1y, raquette2y, &versLaDroite, &versLeBas);

			//On replace les sprites
			PA_SetSpriteXY(1, 0, ballex, balley);
			PA_SetSpriteXY(1, 1, 10, raquette1y);
			PA_SetSpriteXY(1, 2, 237, raquette2y);

			//Gestion des Scores
			if(ballex <= -3)
			{
                scoreJ2++;
				raquette1y = 80;
                raquette2y = 80;
                ballex = 124;
                balley = 96;
			}
			else if(ballex >= 250)
			{
                scoreJ1++;
                raquette1y = 80;
                raquette2y = 80;
                ballex = 124;
                balley = 96;
			}
		}

		afficherScore();

		PA_WaitForVBL();
		PA_16cErase(1);
	}
}


