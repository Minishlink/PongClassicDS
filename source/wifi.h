#ifndef DEF_WIFI
#define DEF_WIFI

#include "MessageQueue.h"	// Includes for liblobby
#include "802.11.h"
#include "lobby.h"

extern void Receive(unsigned char *data, int length, LPLOBBY_USER from);
extern void customVBL(void);

#endif
