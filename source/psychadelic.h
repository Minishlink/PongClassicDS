#ifndef DEF_PSYCHADELIC_
#define DEF_PSYCHADELIC_

#include "jeux.h"

#define PSY_PAD    0
#define PSY_STYLUS 1
#define PSY_MOTION 2

#define PSY_JUSTCHANGED 30

#define PSY_WIN              0
#define PSY_LOSE             1
#define PSY_CHANGED_CONTROLS 2
#define PSY_CHANGED_IAMODE   3

u8 controls;
s32 changed;
bool motionEnabled;

extern void effetsPsychadelic(u8 toDo);
extern void psychadelic();
extern void changePsychadelicControls();
extern void afficherChangePsyControls();

#endif

