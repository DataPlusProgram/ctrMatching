#include "../../common.h"

extern GameTracker *gT;
extern s32 D_8008D104;
extern s32 stage;

extern s32 RaceFlag_IsFullyOffScreen(void);
extern void RaceFlag_BeginTransition(s32 arg0);

void LOAD_LevelFile(s32 levelId)
{
    GameTracker *gGT;

    gGT = gT;

    D_8008D104 = 0;
    gGT->hudFlags &= 0xFE;
    gGT->prevLevelID = gGT->levelID;
    gGT->levelID = levelId;
    M2C_FIELD(gGT, s32 *, 0x256C) &= 0x1000;

    if (RaceFlag_IsFullyOffScreen() == 1) {
        RaceFlag_BeginTransition(1);
    }

    stage = 0;
}
