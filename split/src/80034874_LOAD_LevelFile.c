#include "../../common.h"

s32 D_8008D104;
extern s32 stage;

extern s32 RaceFlag_IsFullyOffScreen(void);
extern void RaceFlag_BeginTransition(s32 arg0);

void LOAD_LevelFile(u32 levelId)
{
    GameTracker *gGT;
    GameTracker *gGT2;
    u32 oldLevel;
    s32 flags;

    gGT = gT;

    D_8008D104 = 0;

    gGT->hudFlags &= 0xFE;

    oldLevel = gGT->levelID;
    gGT2 = gT;
    gGT->levelID = levelId;
    gGT->prevLevelID = oldLevel;

    flags = gGT2->renderFlags;
    flags &= 0x1000;
    gGT2->renderFlags = flags;

    if (RaceFlag_IsFullyOffScreen() == 1) {
        RaceFlag_BeginTransition(1);
    }

    stage = 0;
}
