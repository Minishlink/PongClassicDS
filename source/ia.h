#ifndef DEF_IA
#define DEF_IA

#define DEF_IA_FACILE     1
#define DEF_IA_NORMALE    2
#define DEF_IA_DIFFICILE  3
#define DEF_IA_INVINCIBLE 4

#define DEF_NB_FACILE     56
#define DEF_NB_NORMAL     71
#define DEF_NB_DIFFICILE  91

extern s32 f_ia(u8 iaChoice, s32 raquette2y, s32 balley);
extern s32 iaFacile(s32 raquette2y, s32 balley);
extern s32 iaNormale(s32 raquette2y, s32 balley);
extern s32 iaDifficile(s32 raquette2y, s32 balley);
extern s32 iaInvincible(s32 raquette2y, s32 balley);

extern void iaChoisirDemo(u8 *iaModeDemo1, u8 *iaModeDemo2);
extern void iaDemo(u8 iaModeDemo1, u8 iaModeDemo2, s32 *raquette1y, s32 *raquette2y, s32 balley);
extern s32 iaDemoFacile(s32 raquette1y, s32 raquette2y, s32 balley, bool raq);
extern s32 iaDemoNormal(s32 raquette1y, s32 raquette2y, s32 balley, bool raq);
extern s32 iaDemoDifficile(s32 raquette1y, s32 raquette2y, s32 balley, bool raq);
extern s32 iaDemoInvincible(s32 raquette1y, s32 raquette2y, s32 balley, bool raq);

#endif
