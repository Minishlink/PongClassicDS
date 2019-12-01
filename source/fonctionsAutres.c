// Includes
#include <PA9.h>       // Include for PA_Lib
#include "jeux.h"
#include "scores.h"
#include "effects.h"
#include "psychadelic.h"

#include "MusicPong01.h"

u8 getClassicMode(bool classicMode)
{
    if(classicMode) { psyMode = 0; return 1; }
    else psyMode = 1; return 0;
}

u8 attendre(u8 IAmode)
{
   bool continuer = 0;

   while(!continuer)
   {
        if((controls != PSY_MOTION) && (Pad.Released.Up || Pad.Released.Down || Pad.Released.X || Pad.Released.B || Pad.Released.R || Pad.Released.L || Stylus.Released))
        {
            continuer = 1;
        }
        else if((controls == PSY_MOTION) && (Motion.Held.Up || Motion.Held.Down || Motion.Held.Left || Motion.Held.Right || Pad.Held.L || Pad.Held.R || Pad.Held.Up || Pad.Held.Down || Pad.Held.Left || Pad.Held.Right))
        {
            continuer = 1;
        }
        else if(Pad.Newpress.Start)
		{
		    if(IAmode) { fadeOut(2); choixMode(1, 2); }
		    else { fadeOut(2); choixNbJoueurs(2); }
		}

        afficherScore();

        if(IAmode == DEF_ARCADE) { afficherHScores(); }

		IAmode = changerIAmode(IAmode, 1);


		PA_WaitForVBL();
		if(IAmode != 0) { PA_16cErase(0); }
	}

	return IAmode;
}

void testCollisions(s32 ballex, s32 balley, s32 raquette1y, s32 raquette2y, bool *versLaDroite, bool *versLeBas)
{
   //Test des collisions avec les raquettes (bool versLaDroite)
	if((ballex >= 229 && ballex <= 245) && (balley <= raquette2y + 32) && (balley >= raquette2y))
	{
		*versLaDroite = 0;
	}
	else if((ballex <= 18) && (ballex >= 10) && (balley <= raquette1y + 32) && (balley >= raquette1y))
	{
		*versLaDroite = 1;
	}
	//Test des collisions avec les murs
	else if(balley >= 168)
	{
		*versLeBas = 0;
	}
	else if(balley <= 16)
	{
		*versLeBas = 1;
	}
	//Test des collisions avec la raquette 2 (bool versleBas)
	else if((balley >= raquette2y + 8) && (balley <= raquette2y) && (ballex <= 237) && (balley >= 239))
	{
		*versLeBas = 0;
	}
	else if((balley <= raquette2y + 32) && (balley >= raquette2y + 30) && (ballex <= 237) && (balley >= 239))
	{
		*versLeBas = 1;
	}
	//Test des collisions avec la raquette 1 (bool versleBas)
	else if((balley <= raquette1y + 8) && (balley >= raquette1y) && (ballex <= 10) && (balley >= 12))
	{
		*versLeBas = 0;
	}
	else if((balley <= raquette1y + 32) && (balley >= raquette1y + 30) && (ballex <= 10) && (balley >= 12))
	{
		*versLeBas = 1;
	}
}

void replacerSprites(s32 *balley, s32 *ballex, s32 *raquette1y, s32 *raquette2y, bool *versLaDroite, u8 IAmode)
{
    bool continuer = 0;
	while(!continuer)
    {
        if(IAmode == DEF_ARCADE) { afficherHScores(); }

        if(Pad.Released.Up || Pad.Released.Down || Pad.Released.X || Pad.Released.B || Stylus.Newpress || Motion.Newpress.Down)
        {
            *raquette1y = 80;
            *raquette2y = 80;
            if(*versLaDroite) { *ballex = 84; }
            else if(!*versLaDroite) { *ballex = 164; }
            *balley = 96;
        }

        if(*balley < 96) { *balley += DEF_R_BALLE; }
        else if (*balley > 96) { *balley -= DEF_R_BALLE; }

        if(*versLaDroite)
        {
            if(*ballex < 84) { *ballex += DEF_R_BALLE; }
            else if (*ballex > 84) { *ballex -= DEF_R_BALLE; }
        }
        else
        {
            if(*ballex < 164) { *ballex += DEF_R_BALLE; }
            else if (*ballex > 164) { *ballex -= DEF_R_BALLE; }
        }

        PA_SetSpriteXY(1, 0, *ballex, *balley);

        if(*raquette1y < 80) { *raquette1y += DEF_R_RAQUETTE; }
        else if(*raquette1y > 80) { *raquette1y -= DEF_R_RAQUETTE; }

        if(*raquette2y < 80) { *raquette2y += DEF_R_RAQUETTE; }
        else if (*raquette2y > 80) { *raquette2y -= DEF_R_RAQUETTE; }

        PA_SetSpriteXY(1, 1, 10, *raquette1y);
        PA_SetSpriteXY(1, 2, 237, *raquette2y);

        if((*versLaDroite) && (*raquette1y == 80) && (*raquette2y == 80) && (*ballex == 84) && (*balley == 96))
        {
            *versLaDroite = 1;
            continuer = 1;
        }
        else if((*raquette1y == 80) && (*raquette2y == 80) && (*ballex == 164) && (*balley == 96))
        {
            *versLaDroite = 0;
            continuer = 1;
        }

        PA_WaitForVBL();
    }
}

u8 changerIAmode(u8 IAmode, bool afficher)
{
    if(IAmode != 0)
    {
        if(IAmode == DEF_ARCADE) { afficherHScores(); }

        if(Pad.Released.L && (!Pad.Held.A))
        {
            IAmode = confirmationChangerIAmode(IAmode, DEF_L);
        }
        else if(Pad.Released.R && (!Pad.Held.A))
        {
            IAmode = confirmationChangerIAmode(IAmode, DEF_R);
        }

        if(afficher)
        {
            afficherIAmode(IAmode);
        }
    }

    return IAmode;
}

void afficherIAmode(u8 IAmode)
{
    if(IAmode == DEF_FACILE)                      { PA_16cText(0, 70, 45, 255, 60, "Easy Mode               ", 1, 3, 19); }
    else if(IAmode == DEF_NORMAL)                 { PA_16cText(0, 70, 45, 255, 60, "Normal Mode             ", 1, 3, 19); }
    else if(IAmode == DEF_DIFFICILE)              { PA_16cText(0, 70, 45, 255, 60, "Hard Mode               ", 1, 3, 19); }
    else if(IAmode == DEF_INVINCIBLE)             { PA_16cText(0, 70, 45, 255, 60, "Invincible Mode         ", 1, 3, 19); }
    else if(IAmode == DEF_ARCADE)                 { PA_16cText(0, 70, 45, 255, 60, "Arcade Mode             ", 1, 3, 19); }
    else if(IAmode == DEF_AVENTURE)               { PA_16cText(0, 10, 45, 255, 60, "Adventure Mode - Level 1", 1, 3, 30); }
    else if(IAmode == DEF_AVENTURE_NORMAL)        { PA_16cText(0, 10, 45, 255, 60, "Adventure Mode - Level 2", 1, 3, 30); }
    else if(IAmode == DEF_AVENTURE_DIFFICILE)     { PA_16cText(0, 10, 45, 255, 60, "Adventure Mode - Level 3", 1, 3, 30); }
}

u8 confirmationChangerIAmode(u8 IAmode, bool RL)
{
    bool continuer = 0, confirmation = 0;

    while(!continuer)
    {
        if(IAmode == DEF_ARCADE) { afficherHScores(); }
        afficherIAmode(IAmode);
        afficherScore();
        PA_16cText(1, 22, 77, 120, 192, "Are you sure to change the IA mode ?", 9, 2, 50);
        PA_16cText(1, 21, 110, 255, 192, "Points will be lost...", 9, 1, 50);
        PA_16cText(1, 140, 100, 255, 192, "A: Yes - B: No", 9, 1, 14);
        if(Pad.Newpress.A) { confirmation = 1; continuer = 1; }
        else if(Pad.Newpress.B) { confirmation = 0; continuer = 1; }

        PA_WaitForVBL();
    }

    if((RL == DEF_L) && (confirmation))
    {
        IAmode--;
        if(IAmode == 0) { IAmode = DEF_AVENTURE; }
        scoreJ1 = 0;
        scoreJ2 = 0;
        PA_16cErase(0);
        afficherScore();
        afficherIAmode(IAmode);
        if(psyMode) effetsPsychadelic(PSY_CHANGED_IAMODE);
    }

    else if((RL == DEF_R) && (confirmation))
    {
        if(IAmode >= DEF_AVENTURE) { IAmode = DEF_FACILE; }
        else { IAmode++; }
        scoreJ1 = 0;
        scoreJ2 = 0;
        PA_16cErase(0);
        afficherScore();
        afficherIAmode(IAmode);
        if(psyMode) effetsPsychadelic(PSY_CHANGED_IAMODE);
    }

    return IAmode;
}

void afficherScore()
{
    char text[5] = "";

    sprintf(text, "%ld", scoreJ1);
    PA_16cText(1, 80, 25, 255, 192, text, 1, 4, 4);
    sprintf(text, "%ld", scoreJ2);
    PA_16cText(1, 162, 25, 255, 192, text, 1, 4, 4);
}

u8 modeAventure(u8 IAmode)
{
    scoreJ1++;
    if (scoreJ1 == 25)
    {
        IAmode++;
        scoreJ1 = 0;
        scoreJ2 = 0;
        if(IAmode == DEF_AVENTURE_DIFFICILE + 1)
        {
            while(!Pad.Released.A)
            {
                PA_16cText(1, 22, 100, 120, 192, "You have finish the Adventure Mode !", 9, 2, 100);
                PA_16cText(1, 35, 40, 255, 192, "CONGRATULATIONS !!!", 1, 3, 100);
                PA_16cText(1, 140, 100, 240, 192, "The Game will skip to Hard Mode when you will press A.", 9, 1, 100);
            }
            IAmode = DEF_DIFFICILE;
        }
    }

    return IAmode;
}

void afficherGameMode(bool classicMode)
{
    if(classicMode) PA_16cText(0, 40, 65, 256, 192, "Game Mode : Classic", 9, 2, 100);
    else PA_16cText(0, 40, 65, 256, 192, "Game Mode : Psychadelic", 9, 2, 100);
}
