#include <PA9.h>
#include "effects.h"
#include "jeux.h"
#include "psychadelic.h"

void effetsPsychadelic(u8 toDo)
{
    if(toDo == PSY_WIN)
    {
        clignoter(2, 2);
    }
    else if(toDo == PSY_LOSE)
    {
        clignoter(2, 1);
    }
    else if(toDo == PSY_CHANGED_CONTROLS)
    {
        clignoter(1, 1);
    }
    else if(toDo == PSY_CHANGED_IAMODE)
    {
        windowFadeOut(2, 1);
        windowFadeIn(2, 2);
    }
}

void psychadelic()
{
    u8 nb = PA_RandMax(200);
    if(nb == 50) { changePsychadelicControls(); }

    afficherChangePsyControls();
}

void changePsychadelicControls()
{
    if(motionEnabled)
    {
        u8 nb = PA_RandMax(150);

        if((nb < 25) && (controls != PSY_PAD) && (changed < -5))
        {
            controls = PSY_PAD;
            changed = PSY_JUSTCHANGED;
            afficherChangePsyControls();
            effetsPsychadelic(PSY_CHANGED_CONTROLS);
        }
        else if((nb < 50) && (nb >= 25) && (controls != PSY_STYLUS) && (changed < -5))
        {
            controls = PSY_STYLUS;
            changed = PSY_JUSTCHANGED;
            afficherChangePsyControls();
            effetsPsychadelic(PSY_CHANGED_CONTROLS);
        }
        else if((nb <= 75) && (nb >= 50) && (controls != PSY_MOTION) && (changed < -5))
        {
            controls = PSY_MOTION;
            changed = PSY_JUSTCHANGED;
            afficherChangePsyControls(PSY_JUSTCHANGED);
            effetsPsychadelic(PSY_CHANGED_CONTROLS);
        }
        else if((nb <= 100) && (nb >= 75) && (controls != PAD_INVERSE) && (changed < -5))
        {
            controls = PAD_INVERSE;
            changed = PSY_JUSTCHANGED;
            afficherChangePsyControls(PSY_JUSTCHANGED);
            effetsPsychadelic(PSY_CHANGED_CONTROLS);
        }
        else if((nb <= 125) && (nb >= 100) && (controls != STYLUS_INVERSE) && (changed < -5))
        {
            controls = STYLUS_INVERSE;
            changed = PSY_JUSTCHANGED;
            afficherChangePsyControls(PSY_JUSTCHANGED);
            effetsPsychadelic(PSY_CHANGED_CONTROLS);
        }
        else if((nb <= 150) && (nb >= 125) && (controls != MOTION_INVERSE) && (changed < -5))
        {
            controls = MOTION_INVERSE;
            changed = PSY_JUSTCHANGED;
            afficherChangePsyControls(PSY_JUSTCHANGED);
            effetsPsychadelic(PSY_CHANGED_CONTROLS);
        }

    }
    else
    {
        u8 nb = PA_RandMax(100);

        if((nb < 25) && (controls != PSY_PAD) && (changed < -5))
        {
            controls = PSY_PAD;
            changed = PSY_JUSTCHANGED;
            afficherChangePsyControls();
            effetsPsychadelic(PSY_CHANGED_CONTROLS);
        }
        else if((nb < 50) && (nb >= 25) && (controls != PSY_STYLUS) && (changed < -5))
        {
            controls = PSY_STYLUS;
            changed = PSY_JUSTCHANGED;
            afficherChangePsyControls();
            effetsPsychadelic(PSY_CHANGED_CONTROLS);
        }
        else if((nb <= 75) && (nb >= 50) && (controls != PAD_INVERSE) && (changed < -5))
        {
            controls = PAD_INVERSE;
            changed = PSY_JUSTCHANGED;
            afficherChangePsyControls(PSY_JUSTCHANGED);
            effetsPsychadelic(PSY_CHANGED_CONTROLS);
        }
        else if((nb <= 100) && (nb >= 75) && (controls != STYLUS_INVERSE) && (changed < -5))
        {
            controls = STYLUS_INVERSE;
            changed = PSY_JUSTCHANGED;
            afficherChangePsyControls(PSY_JUSTCHANGED);
            effetsPsychadelic(PSY_CHANGED_CONTROLS);
        }
    }

}

void afficherChangePsyControls()
{
    if(changed > 0) PA_16cText(1, 70, 45, 255, 60, "*!*  C H A N G E D  *!*", 2, 3, 100);
    changed--;

    if(controls == PSY_PAD)
    {
        PA_16cText(1, 0, 17, 255, 60, "P A D", 2, 3, 19);
    }
    else if(controls == PSY_STYLUS)
    {
        PA_16cText(1, 0, 17, 255, 60, "S T Y L U S", 2, 3, 19);
    }
    else if(controls == PSY_MOTION)
    {
        PA_16cText(1, 0, 17, 255, 60, "M O T I O N", 2, 3, 19);
    }
    else if(controls == PAD_INVERSE)
    {
        PA_16cText(1, 0, 17, 255, 60, "PAD  INVERSED", 2, 3, 19);
    }
    else if(controls == STYLUS_INVERSE)
    {
        PA_16cText(1, 0, 17, 255, 60, "STYLUS INVERS", 2, 3, 19);
    }
    else if(controls == MOTION_INVERSE)
    {
        PA_16cText(1, 0, 17, 255, 60, "MOTION INVERS", 2, 3, 19);
    }
}

