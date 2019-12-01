// Includes
#include <PA9.h>       // Include for PA_Lib
#include "ia.h"
#include "jeux.h"

s32 f_ia(u8 iaChoice, s32 raquette2y, s32 balley)
{

    if((iaChoice == DEF_FACILE) || (iaChoice == DEF_AVENTURE))
    {
        raquette2y = iaFacile(raquette2y, balley);
    }
    else if((iaChoice == DEF_NORMAL) || (iaChoice == DEF_AVENTURE_NORMAL))
    {
        raquette2y = iaNormale(raquette2y, balley);
    }
    else if((iaChoice == DEF_DIFFICILE) || (iaChoice == DEF_AVENTURE_DIFFICILE))
    {
        raquette2y = iaDifficile(raquette2y, balley);
    }
    else if((iaChoice == DEF_INVINCIBLE) || (iaChoice == DEF_ARCADE))
    {
        raquette2y = iaInvincible(raquette2y, balley);
    }

    return raquette2y;
}

s32 iaFacile(s32 raquette2y, s32 balley)
{
    u8 nb = PA_RandMax(100);

    if(nb <= DEF_NB_FACILE)
    {
        if((balley <= raquette2y) && (raquette2y > 16)) { raquette2y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 2 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
        else if(raquette2y < 144) { raquette2y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 2
    }

    return raquette2y;
}

s32 iaNormale(s32 raquette2y, s32 balley)
{
    u8 nb = PA_RandMax(100);

    if(nb <= DEF_NB_NORMAL)
    {
        if((balley <= raquette2y) && (raquette2y > 16)) { raquette2y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 2 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
        else if(raquette2y < 144) { raquette2y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 2
    }

    return raquette2y;
}

s32 iaDifficile(s32 raquette2y, s32 balley)
{
    u8 nb = PA_RandMax(100);

    if(nb <= DEF_NB_DIFFICILE)
    {
        if((balley <= raquette2y) && (raquette2y > 16)) { raquette2y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 2 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
        else if(raquette2y < 144) { raquette2y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 2
    }

    return raquette2y;
}

s32 iaInvincible(s32 raquette2y, s32 balley)
{
    if((balley <= raquette2y) && (raquette2y > 16)) { raquette2y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 2 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
    else if(raquette2y < 144) { raquette2y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 2

    return raquette2y;
}

void iaChoisirDemo(u8 *iaModeDemo1, u8 *iaModeDemo2)
{
    u8 nb1 = PA_RandMax(100);
    u8 nb2 = PA_RandMax(100);

    if(nb1 <= 25) { *iaModeDemo1 = DEF_IA_FACILE; }
    else if((nb1 <= 50) && (nb1 > 25)) { *iaModeDemo1 = DEF_IA_NORMALE; }
    else if((nb1 <= 75) && (nb1 > 50)) { *iaModeDemo1 = DEF_IA_DIFFICILE; }
    else { *iaModeDemo1 = DEF_IA_INVINCIBLE; }

    if(nb2 <= 25) { *iaModeDemo2 = DEF_IA_FACILE; if(*iaModeDemo1 == *iaModeDemo2) { *iaModeDemo2 = DEF_IA_NORMALE; } }
    else if((nb2 <= 50) && (nb2 > 25)) { *iaModeDemo2 = DEF_IA_NORMALE; if(*iaModeDemo1 == *iaModeDemo2) { *iaModeDemo2 = DEF_IA_DIFFICILE; } }
    else if((nb2 <= 75) && (nb2 > 50)) { *iaModeDemo2 = DEF_IA_DIFFICILE; if(*iaModeDemo1 == *iaModeDemo2) { *iaModeDemo2 = DEF_IA_INVINCIBLE; } }
    else { *iaModeDemo2 = DEF_IA_INVINCIBLE; if(*iaModeDemo1 == *iaModeDemo2) { *iaModeDemo2 = DEF_IA_FACILE; } }
}

void iaDemo(u8 iaModeDemo1, u8 iaModeDemo2, s32 *raquette1y, s32 *raquette2y, s32 balley)
{
    s32 raq1y = *raquette1y;
    s32 raq2y = *raquette2y;

    if(iaModeDemo1 == DEF_IA_FACILE)
    {
        *raquette1y = iaDemoFacile(raq1y, raq2y, balley, 0);
    }
    else if(iaModeDemo1 == DEF_IA_NORMALE)
    {
        *raquette1y = iaDemoNormal(raq1y, raq2y, balley, 0);
    }
    else if(iaModeDemo1 == DEF_IA_DIFFICILE)
    {
        *raquette1y = iaDemoDifficile(raq1y, raq2y, balley, 0);
    }
    else if(iaModeDemo1 == DEF_IA_INVINCIBLE)
    {
        *raquette1y = iaDemoInvincible(raq1y, raq2y, balley, 0);
    }

    if(iaModeDemo2 == DEF_IA_FACILE)
    {
        *raquette2y = iaDemoFacile(raq1y, raq2y, balley, 0);
    }
    else if(iaModeDemo2 == DEF_IA_NORMALE)
    {
        *raquette2y = iaDemoNormal(raq1y, raq2y, balley, 0);
    }
    else if(iaModeDemo2 == DEF_IA_DIFFICILE)
    {
        *raquette2y = iaDemoDifficile(raq1y, raq2y, balley, 0);
    }
    else if(iaModeDemo2 == DEF_IA_INVINCIBLE)
    {
        *raquette2y = iaDemoInvincible(raq1y, raq2y, balley, 0);
    }
}

s32 iaDemoFacile(s32 raquette1y, s32 raquette2y, s32 balley, bool raq)
{
    u8 nb = PA_RandMax(100);
    s32 raquette = 0;

    if((raq == 0) && (nb <= DEF_NB_FACILE))
    {
        if((balley <= raquette1y) && (raquette1y > 16)) { raquette1y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 1 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
        else if(raquette1y < 144) { raquette1y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 1
        raquette = raquette1y;
    }
    else if((raq == 1) && (nb <= DEF_NB_FACILE))
    {
        if((balley <= raquette2y) && (raquette2y > 16)) { raquette2y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 2 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
        else if(raquette2y < 144) { raquette2y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 2
        raquette = raquette2y;
    }
    else
    {
        if(raq == 0) { raquette = raquette1y; }
        else if (raq == 1) { raquette =raquette2y; }
    }

    return raquette;
}

s32 iaDemoNormal(s32 raquette1y, s32 raquette2y, s32 balley, bool raq)
{
    u8 nb = PA_RandMax(100);
    s32 raquette = 0;

    if((raq == 0) && (nb <= DEF_NB_NORMAL))
    {
        if((balley <= raquette1y) && (raquette1y > 16)) { raquette1y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 1 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
        else if(raquette1y < 144) { raquette1y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 1
        raquette = raquette1y;
    }
    else if(nb <= DEF_NB_NORMAL)
    {
        if((balley <= raquette2y) && (raquette2y > 16)) { raquette2y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 2 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
        else if(raquette2y < 144) { raquette2y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 2
        raquette = raquette2y;
    }
    else
    {
        if(raq == 0) { raquette = raquette1y; }
        else if (raq == 1) { raquette =raquette2y; }
    }

    return raquette;
}

s32 iaDemoDifficile(s32 raquette1y, s32 raquette2y, s32 balley, bool raq)
{
    u8 nb = PA_RandMax(100);
    s32 raquette = 0;

    if((raq == 0) && (nb <= DEF_NB_DIFFICILE))
    {
        if((balley <= raquette1y) && (raquette1y > 16)) { raquette1y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 1 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
        else if(raquette1y < 144) { raquette1y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 1
        raquette = raquette1y;
    }
    else if((raq == 1) && (nb <= DEF_NB_DIFFICILE))
    {
        if((balley <= raquette2y) && (raquette2y > 16)) { raquette2y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 2 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
        else if(raquette2y < 144) { raquette2y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 2
        raquette = raquette2y;
    }
    else
    {
        if(raq == 0) { raquette = raquette1y; }
        else if (raq == 1) { raquette =raquette2y; }
    }

    return raquette;
}

s32 iaDemoInvincible(s32 raquette1y, s32 raquette2y, s32 balley, bool raq)
{
    s32 raquette = 0;

    if(raq == 0)
    {
        if((balley <= raquette1y) && (raquette1y > 16)) { raquette1y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 1 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
        else if(raquette1y < 144) { raquette1y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 1
        raquette = raquette1y;
    }
    else if(raq == 1);
    {
        if((balley <= raquette2y) && (raquette2y > 16)) { raquette2y -= DEF_SPEED_RAQUETTE; } //Si la balle est plus haut que la raquette 2 et que la balle n'aille pas hors du mur, alors on monte la raquette 2
        else if(raquette2y < 144) { raquette2y += DEF_SPEED_RAQUETTE; } //Sinon si la balle ne va pas hors du mur, alors on descends la raquette 2
        raquette = raquette2y;
    }

    return raquette;
}

