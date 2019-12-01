// Includes
#include <PA9.h>       // Include for PA_Lib
#include "jeux.h"
#include "effects.h"
#include "wifi.h"

#include "MusicPong01.h"

//##################################################################################################
//#-------------------------------------- WIFI MODE -----------------------------------------------#
//##################################################################################################

void wifiPlay(void)
{
    PA_Init2D();

    PA_InitText(1, 0);
    PA_InitText(0, 0);

    PA_PlayMod(MusicPong01);
    fadeIn(2);

    //-------------------------------
    PA_OutputSimpleText(1, 0, 0,"PA_VBLFunctionInit");
    PA_VBLFunctionInit(customVBL);
	PA_OutputSimpleText(1, 0, 2,"IPC_SetChannelCallback");
	IPC_SetChannelCallback(0, &LWIFI_IPC_Callback);
	PA_OutputSimpleText(1, 0, 3,"LOBBY_Init");
	LOBBY_Init();
	PA_OutputSimpleText(1, 0, 4,"LOBBY_SetStreamHandler");
	LOBBY_SetStreamHandler(0x0001, &Receive);
    int selected = 0;
    PA_OutputSimpleText(1, 0, 5,"LOBBY_GetNumberOfKnownUsers");
    PA_OutputSimpleText(1, 0, 7,"OK avant while(1)");
    //-------------------------------

	while(1)
	{
        if(Pad.Newpress.Start) { fadeOut(2); choixNbJoueurs(2); }

        // Print the number of connections
		int max = LOBBY_GetNumberOfKnownUsers();
		PA_OutputText(0, 1, 22, "Users: %d  ", max);

		// Allow the selection of the destination
		if (Pad.Newpress.Down)
			selected++;
		if (Pad.Newpress.Up)
			selected--;
		if (max > 0)
			selected %= max;

		// On button presses, send text to the selected connection
		if (Pad.Newpress.A)
		{
			LOBBY_SendToUser(LOBBY_GetUserByID(selected),0x0001,(unsigned char *)"Key [A] pressed.",17) ;
		}
		if (Pad.Newpress.B)
		{
			LOBBY_SendToUser(LOBBY_GetUserByID(selected),0x0001,(unsigned char *)"Key [B] pressed.",17) ;
		}
		if (Pad.Newpress.X)
		{
			LOBBY_SendToUser(LOBBY_GetUserByID(selected),0x0001,(unsigned char *)"Key [X] pressed.",17) ;
		}
		if (Pad.Newpress.Y)
		{
			LOBBY_SendToUser(LOBBY_GetUserByID(selected),0x0001,(unsigned char *)"Key [Y] pressed.",17) ;
		}

		// Write all connections to the screen
		int i;
		for (i = 0; i < max; i++)
		{
			LPLOBBY_USER user = LOBBY_GetUserByID(i);
			if (i == selected)
			{
				PA_OutputText(0, 1, 5+i, "->%s (%s)       ", LOBBY_GetUserName(user), LOBBY_IsTimedOut(user) ? "TIMEOUT" : "OK");
			}
			else
			{
				PA_OutputText(0, 1, 5+i, "  %s (%s)       ", LOBBY_GetUserName(user), LOBBY_IsTimedOut(user) ? "TIMEOUT" : "OK");
			}
		}

		PA_WaitForVBL();
	}
}

void Receive(unsigned char *data, int length, LPLOBBY_USER from)
{
	PA_OutputText(0, 1, 20, "Received: %s       ", (char*)data);
}

void customVBL(void)
{
	IPC_RcvCompleteCheck();
	LOBBY_Update();
}

