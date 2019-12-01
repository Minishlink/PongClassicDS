// Includes
#include <PA9.h>       // Include for PA_Lib
#include "jeux.h"
#include "ia.h"
#include "scores.h"
#include "effects.h"

#include "MusicPong02.h"


void unJoueur(u8 IAmode, bool classicMode)
{
    PA_Init2D();
    PA_Init16cBg(1, 2);
    PA_Init16cBg(0, 2);
    PA_InitRand();

    PA_LoadTiledBg(1, 3, terrainBG);
    PA_LoadTiledBg(0, 3, unJoueurBG);

    s32 raquette1y = 80, raquette2y = 80, ballex = 124, balley = 96;
    bool versLaDroite = PA_RandMinMax(0, 1);
	bool versLeBas = PA_RandMinMax(0, 1);
	bool pause = 1;

	scoreJ1 = 0;
	scoreJ2 = 0;

    PA_LoadSpritePal(1, 0, (void*)balle_Pal);
	PA_CreateSprite(1, 0, (void*)balle_Sprite, OBJ_SIZE_8X8, 1, 0, ballex, balley);
	PA_SetSpritePrio(1, 0, 3);

	PA_CreateSprite(1, 1, (void*)raquette_Sprite, OBJ_SIZE_8X32, 1, 0, 10, raquette1y);
	PA_SetSpritePrio(1, 1, 3);
	PA_CreateSprite(1, 2, (void*)raquette_Sprite, OBJ_SIZE_8X32, 1, 0, 237, raquette2y);
	PA_SetSpritePrio(1, 2, 3);

	PA_PlayMod(MusicPong02);

    chargerHScores();

    getClassicMode(classicMode);

    if(motion_init()) motionEnabled = true;
    if(!classicMode) controls = PSY_PAD;
    else controls = PAD;

    fadeIn(2);

    while(!pause)
    {
        if(Pad.Released.Select || Pad.Released.Up || Pad.Released.Down || Pad.Released.X || Pad.Released.B || Pad.Released.R || Pad.Released.L || Stylus.Released) if(!pause) pause = 1;

        afficherGameMode(classicMode);
        afficherIAmode(IAmode);
		afficherScore();

		PA_WaitForVBL();
		PA_16cErase(1);
		PA_16cErase(0);
    }


	while(1)
	{
		if(Pad.Newpress.Start) { fadeOut(2); choixMode(1, 2); }
        if(Pad.Newpress.Select) { if(!pause) pause = 1; else pause = 0; }

		if(!pause)
		{
		    if(classicMode)
		    {
                raquette1y = doControls(raquette1y);
		    }
		    else
		    {
		        raquette1y = doControls(raquette1y);
		        psychadelic();
		    }

			if(versLaDroite) { ballex += DEF_SPEED_BALLE; }
			else { ballex -= DEF_SPEED_BALLE; }
			if(versLeBas) { balley += DEF_SPEED_BALLE; }
			else { balley -= DEF_SPEED_BALLE; }

            raquette2y = f_ia(IAmode, raquette2y, balley); //IA

            testCollisions(ballex, balley, raquette1y, raquette2y, &versLaDroite, &versLeBas);

			//On replace les sprites
			PA_SetSpriteXY(1, 0, ballex, balley);
			PA_SetSpriteXY(1, 1, 10, raquette1y);
			PA_SetSpriteXY(1, 2, 237, raquette2y);

			if((IAmode != DEF_ARCADE) && (IAmode < DEF_AVENTURE))
			{
                //Gestion des Scores
                if(ballex <= -3)
                {
                    scoreJ2++;
                    if(!classicMode) effetsPsychadelic(PSY_LOSE);
                    replacerSprites(&balley, &ballex, &raquette1y, &raquette2y, &versLaDroite, IAmode);
                    IAmode = attendre(IAmode);
                }
                else if(ballex >= 250)
                {
                    scoreJ1++;
                    if(!classicMode) effetsPsychadelic(PSY_WIN);
                    replacerSprites(&balley, &ballex, &raquette1y, &raquette2y, &versLaDroite, IAmode);
                    IAmode = attendre(IAmode);
                }
			}
			else if (IAmode == DEF_ARCADE)
			{
			    if(ballex <= -3)
			    {
			        chargerHScores();
			        sauverHScores();
			        chargerHScores();
			        PA_16cText(1, 140, 55, 255, 192, "FINISH", 1, 3, 14);
                    PA_16cText(1, 57, 55, 255, 192, "FINISH", 1, 3, 14);
                    replacerSprites(&balley, &ballex, &raquette1y, &raquette2y, &versLaDroite, IAmode);
                    IAmode = attendre(IAmode);
                    scoreJ1 = 0;
                    scoreJ2 = 0;
			    }
			    else
			    {
                    if((ballex >= 229 && ballex <= 245) && (balley <= raquette2y + 32) && (balley >= raquette2y))
                    {
                        scoreJ1++;
                    }
                    if((ballex <= 18) && (ballex >= 10) && (balley <= raquette1y + 32) && (balley >= raquette1y))
                    {
                        scoreJ1++;
                    }
                    scoreJ2++;
			    }

                afficherHScores();
			}
			else if (IAmode >= DEF_AVENTURE)
			{
			    //Gestion des Scores
                if(ballex <= -3)
                {
                    scoreJ2++;
                    replacerSprites(&balley, &ballex, &raquette1y, &raquette2y, &versLaDroite, IAmode);
                    IAmode = attendre(IAmode);
                }
                else if(ballex >= 250)
                {
                    IAmode = modeAventure(IAmode);
                    replacerSprites(&balley, &ballex, &raquette1y, &raquette2y, &versLaDroite, IAmode);
                    IAmode = attendre(IAmode);
                }
			}

        }

		else if(pause)
		{
            IAmode = changerIAmode(IAmode, 0);
		}

        if(classicMode) changeControls();
        if(classicMode) afficherControls();
		afficherGameMode(classicMode);
        afficherIAmode(IAmode);
		afficherScore();

        if(motionEnabled) PA_MotionVBL();
		PA_WaitForVBL();
		PA_16cErase(1);
		PA_16cErase(0);
	}
}

void changeControls()
{
    if(Pad.Held.A && (Pad.Released.L || Pad.Released.R))
    {
        controls++;
        if(controls == MOTION_INVERSE + 1) controls = PAD;
    }
}

void afficherControls()
{
    PA_16cText(0, 80, 172, 255, 192, "Hold A + release L/R to change controls !", 1, 1, 100);
    if(controls == PAD) PA_16cText(0, 50, 182, 255, 192, "Current : PAD", 1, 2, 100);
    else if (controls == STYLUS) PA_16cText(0, 50, 182, 255, 192, "Current : STYLUS", 1, 2, 100);
    else if (controls == MOTION) PA_16cText(0, 50, 182, 255, 192, "Current : DS MOTION", 1, 2, 100);
    else if (controls == PAD_INVERSE) PA_16cText(0, 50, 182, 255, 192, "Current : PAD INVERSED", 1, 2, 100);
    else if (controls == STYLUS_INVERSE) PA_16cText(0, 50, 182, 255, 192, "Current : STYLUS INVERSED", 1, 2, 100);
    else PA_16cText(0, 50, 182, 255, 192, "Current : DS MOTION INVERSED", 1, 2, 100);
}

s32 doControls(s32 raquette1y)
{
    u8 lastY = 96;

    if(controls == PAD)
    {
        if(raquette1y == 144) raquette1y -= Pad.Held.Up * DEF_SPEED_RAQUETTE;
        else if (raquette1y == 16) raquette1y += Pad.Held.Down * DEF_SPEED_RAQUETTE;
        else raquette1y += (Pad.Held.Down - Pad.Held.Up) * DEF_SPEED_RAQUETTE;
    }
    else if(controls == STYLUS)
    {
        if(Stylus.Held)
        {
            if((raquette1y == 144) && (Stylus.Y >= lastY)) raquette1y -= DEF_SPEED_RAQUETTE;
            else if ((raquette1y == 16) && (Stylus.Y < lastY)) raquette1y += DEF_SPEED_RAQUETTE;
            else if(Stylus.Y >= lastY) raquette1y += 1 * DEF_SPEED_RAQUETTE;
            else if(Stylus.Y < lastY) raquette1y -= 1 * DEF_SPEED_RAQUETTE;

            if(lastY < 10) lastY += 10;
            else if(lastY > 182) lastY -= 10;
        }
    }
    else if(controls == MOTION)
    {
        if(motionEnabled)
        {
            if(raquette1y >= 16 && raquette1y <= 144) raquette1y = Motion.Y;
            /*if(raquette1y == 144) raquette1y -= Motion.Held.Up * DEF_SPEED_RAQUETTE;
            else if (raquette1y == 16) raquette1y += Motion.Held.Down * DEF_SPEED_RAQUETTE;
            else raquette1y += (Motion.Held.Down - Motion.Held.Up) * DEF_SPEED_RAQUETTE;*/
        }
    }
    else if(controls == PAD_INVERSE)
    {
        if(raquette1y == 144) raquette1y -= Pad.Held.Down * DEF_SPEED_RAQUETTE;
        else if (raquette1y == 16) raquette1y += Pad.Held.Up * DEF_SPEED_RAQUETTE;
        else raquette1y -= (Pad.Held.Down - Pad.Held.Up) * DEF_SPEED_RAQUETTE;
    }
    else if(controls == STYLUS_INVERSE)
    {
        if(Stylus.Held)
        {
            if(Stylus.Y < 16) { raquette1y = 16; }
            else if(Stylus.Y > 144) { raquette1y = 144; }
            else raquette1y = Stylus.Y - 16; // 16 = raquette1_height / 2
        }
    }
    else if(controls == MOTION_INVERSE)
    {
        if(motionEnabled)
        {
            if(raquette1y == 144) raquette1y -= Motion.Held.Down * DEF_SPEED_RAQUETTE;
            else if (raquette1y == 16) raquette1y += Motion.Held.Up * DEF_SPEED_RAQUETTE;
            else raquette1y -= (Motion.Held.Down - Motion.Held.Up) * DEF_SPEED_RAQUETTE;
        }
    }

    return raquette1y;
}
