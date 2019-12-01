#include <PA9.h>

#include "effects.h"

void fadeOut(u8 screen)
{
	s8 i = 0;

	for(i = 0; i >= -8; i--)
	{
		PA_WaitForVBL();
		if(screen == 0 || screen == 2) { PA_SetBrightness(0, i); }
		if(screen == 1 || screen == 2) { PA_SetBrightness(1, i); }
	}
}


void fadeIn(u8 screen)
{
	s8 i = 0;

	for(i = -8; i <= 0; i++)
	{
		PA_WaitForVBL();
		if(screen == 0 || screen == 2) { PA_SetBrightness(0, i); }
		if(screen == 1 || screen == 2) { PA_SetBrightness(1, i); }
	}
}


void clignoter(u8 screen, u8 clignotements)
{
    u8 i = 0;
    for(i = 0; i < clignotements; i++)
    {
        PA_WaitForVBL();
        fadeOut(screen);
        fadeIn(screen);
    }
}

void windowFadeOut(u8 screen, u8 fadetype)
{
    s8 i;

    for (i = 0; i <= 32; i++)
    {
        if(screen == 0 || screen == 2) PA_WindowFade(0, fadetype, i);
        if(screen == 1 || screen == 2) PA_WindowFade(1, fadetype, i);
        PA_WaitForVBL();
    }
}

void windowFadeIn(u8 screen, u8 fadetype)
{
    s8 i;

    for (i = 32; i >= 0; i--)
    {
        if(screen == 0 || screen == 2) PA_WindowFade(0, fadetype, i);
        if(screen == 1 || screen == 2) PA_WindowFade(1, fadetype, i);
        PA_WaitForVBL();
    }
}

