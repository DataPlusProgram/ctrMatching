#include "../../common.h"

typedef struct BigFile {
    s32 unk0;
} BigFile;

void LOAD_Robots1P(s32 charId);
void LOAD_Robots2P(BigFile *bigfilePtr, s16 p1CharId, s16 p2CharId, s32 arg3);
void LOAD_AppendQueue(BigFile *bigfilePtr, s32 fileType, s32 bigfileIndex, void *saveThere, s32 arg4);

extern s16 D_80086E84[];
extern GameTracker *gGamepads;
extern void *podiumModel_firstPlace;
extern void *ptrBigfileCdPos_2;

#define LT_DRAM 2

void *LOAD_DriverMPK(BigFile *bigfilePtr, s32 lodLevel, s32 arg3)
{
    u32 gameMode1;

    if ((u32)(lodLevel - 3) < 2)
    {
        LOAD_AppendQueue(bigfilePtr, LT_DRAM, D_80086E84[0] + 0x14C, &podiumModel_firstPlace, -2);
        LOAD_AppendQueue(bigfilePtr, LT_DRAM, D_80086E84[1] + 0x14C, (&podiumModel_firstPlace) + 1, -2);
        LOAD_AppendQueue(bigfilePtr, LT_DRAM, D_80086E84[2] + 0x14C, (&podiumModel_firstPlace) + 2, -2);
        LOAD_AppendQueue(bigfilePtr, LT_DRAM, D_80086E84[3] + 0x15C, NULL, arg3);
        goto returnPtr;
    }

    if ((lodLevel == 1) && ((gGamepads->gameMode1 & 0x22000) != 0x20000))
    {
        gameMode1 = gGamepads->gameMode1;

        if (((gameMode1 & 0x20100000) != 0) ||
            ((gGamepads->gameMode2 & 0x80) != 0) ||
            (gGamepads->levelID == 0x28))
        {
            LOAD_AppendQueue(bigfilePtr, LT_DRAM, D_80086E84[0] + 0x114, NULL, arg3);
            goto returnPtr;
        }

        if ((s32)gameMode1 >= 0)
        {
            if (((gameMode1 & 0x10000000) != 0) && (gGamepads->cupID == 4))
            {
                LOAD_AppendQueue(bigfilePtr, LT_DRAM, D_80086E84[0] + 0xF2, &podiumModel_firstPlace, -2);
                LOAD_AppendQueue(bigfilePtr, LT_DRAM, 0x14B, NULL, arg3);

                D_80086E84[1] = 10;
                D_80086E84[2] = 9;
                D_80086E84[3] = 11;
                D_80086E84[4] = 8;
                goto returnPtr;
            }

            if ((gGamepads->gameMode1 & 0x22000) != 0x2000)
            {
                LOAD_Robots1P(D_80086E84[0]);
            }

            LOAD_AppendQueue(bigfilePtr, LT_DRAM, D_80086E84[0] + 0x104, NULL, arg3);
            goto returnPtr;
        }
    }
    else if ((lodLevel != 8) && ((gGamepads->gameMode1 & 0x20000) == 0))
    {
        LOAD_AppendQueue(bigfilePtr, LT_DRAM, D_80086E84[0] + 0x134, &podiumModel_firstPlace, -2);
        LOAD_AppendQueue(bigfilePtr, LT_DRAM, D_80086E84[1] + 0x134, (&podiumModel_firstPlace) + 1, -2);
        LOAD_Robots2P(bigfilePtr, D_80086E84[0], D_80086E84[1], arg3);
        goto returnPtr;
    }

    LOAD_AppendQueue(bigfilePtr, LT_DRAM, D_80086E84[0] + 0xF2, &podiumModel_firstPlace, -2);
    LOAD_AppendQueue(bigfilePtr, LT_DRAM, D_80086E84[1] + 0x124, NULL, arg3);

returnPtr:
    return ptrBigfileCdPos_2;
}