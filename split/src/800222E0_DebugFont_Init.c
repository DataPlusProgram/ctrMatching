#include "../../common.h"

s32 boolGhostsDrawing;
s16 ghostOverflowTextTimer[2];
s32 boolGhostTooBigToSave;

typedef struct DebugGhostStats {
    char unk0[0x14];
    u8 boolGhostsDrawing;
    u8 boolGhostTooBigToSave;
    u16 overflowTimer1;
    u16 unk18;
    u16 overflowTimer2;
} DebugGhostStats;

void DebugFont_Init(GameTracker *gGT)
{
    DebugGhostStats *ghostStats;

    ghostStats = M2C_FIELD(gGT, DebugGhostStats **, 0x1FF4);

    if (ghostStats != NULL) {
        boolGhostsDrawing = ghostStats->boolGhostsDrawing;
        ghostOverflowTextTimer[0] = ghostStats->overflowTimer1;
        ghostOverflowTextTimer[1] = ghostStats->overflowTimer2;
        boolGhostTooBigToSave = ghostStats->boolGhostTooBigToSave;
    }
}
