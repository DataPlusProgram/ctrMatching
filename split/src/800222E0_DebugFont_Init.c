#include "../../common.h"

s32 boolGhostsDrawing;
s16 ghostOverflowTextTimer[2];
s32 boolGhostTooBigToSave;

typedef struct DebugGhostStats {
    u8 pad0[0x14];
    u8 boolGhostsDrawing;
    u8 boolGhostTooBigToSave;
    u16 overflowTimer1;
    u16 unk18;
    u16 overflowTimer2;
} DebugGhostStats;

void DebugFont_Init(GameTracker *gGT)
{
    DebugGhostStats *ghostStats;
    u32 ghostsDrawing;
    u32 overflowTimer1;
    u32 ghostTooBigToSave;
    u32 overflowTimer2;

    ghostStats = M2C_FIELD(gGT, DebugGhostStats **, 0x1FF4);

    if (ghostStats != NULL)
    {
        ghostsDrawing = ghostStats->boolGhostsDrawing;
        overflowTimer1 = ghostStats->overflowTimer1;
        boolGhostsDrawing = ghostsDrawing;

        ghostTooBigToSave = ghostStats->boolGhostTooBigToSave;
        overflowTimer2 = ghostStats->overflowTimer2;

        ghostOverflowTextTimer[0] = overflowTimer1;
        ghostOverflowTextTimer[1] = overflowTimer2;
        boolGhostTooBigToSave = ghostTooBigToSave;
    }
}