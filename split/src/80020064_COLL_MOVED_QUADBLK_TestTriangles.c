#include "../../common.h"

extern void COLL_FIXED_QUADBLK_GetNormVecs_HiLOD(void *scratch, void *quadBlock);
extern void COLL_FIXED_QUADBLK_GetNormVecs_LoLOD(void *scratch, void *quadBlock);
extern void COLL_MOVED_TRIANGL_TestPoint(void *scratch, void *point0, void *point1, void *point2);
//suspicious 
void COLL_MOVED_QUADBLK_TestTriangles(void *arg0, void *arg1)
{
    s16 tempV1;
    s32 tempV1_2;
    s32 tempMask0;
    s32 tempMask1;
    s32 tempT1;
    s32 tempT1_2;
    s32 tempT1_3;
    u32 tempT1_4;
    u32 tempT1_5;

    M2C_FIELD(arg1, void **, 0x64) = arg0;
    tempV1 = M2C_FIELD(arg0, s16 *, 0x12);
    tempMask0 = M2C_FIELD(arg1, s32 *, 0x24);
    tempMask1 = M2C_FIELD(arg1, s32 *, 0x28);

    if (((tempMask0 & tempV1) != 0) &&
        ((tempMask1 & tempV1) == 0) &&
        ((tempT1 = M2C_FIELD(arg0, s32 *, 0x2C), ((tempT1 >> 0x10) - M2C_FIELD(arg1, s16 *, 0x38))) <= 0) &&
        ((((s16)tempT1 - M2C_FIELD(arg1, s16 *, 0x36)) <= 0) &&
         ((tempT1_2 = M2C_FIELD(arg0, s32 *, 0x30), (M2C_FIELD(arg1, s16 *, 0x30) - (tempT1_2 >> 0x10))) <= 0)) &&
        ((((s16)tempT1_2 - M2C_FIELD(arg1, s16 *, 0x3A)) <= 0) &&
         ((tempT1_3 = M2C_FIELD(arg0, s32 *, 0x34), (M2C_FIELD(arg1, s16 *, 0x34) - (tempT1_3 >> 0x10))) <= 0)) &&
        ((tempV1_2 = M2C_FIELD(arg1, s16 *, 0x22), (M2C_FIELD(arg1, s16 *, 0x32) - (s16)tempT1_3)) <= 0)) {
        if ((tempV1_2 & 2) != 0) {
            if ((tempV1_2 & 8) == 0) {
                COLL_FIXED_QUADBLK_GetNormVecs_HiLOD(arg1, arg0);
            }

            M2C_FIELD(arg1, s8 *, 0x63) = 2;
            COLL_MOVED_TRIANGL_TestPoint(arg1, (void *)((u8 *)arg1 + 0xF0), (void *)((u8 *)arg1 + 0x140), (void *)((u8 *)arg1 + 0x154));
            M2C_FIELD(arg1, s8 *, 0x63) = 3;
            COLL_MOVED_TRIANGL_TestPoint(arg1, (void *)((u8 *)arg1 + 0x140), (void *)((u8 *)arg1 + 0x168), (void *)((u8 *)arg1 + 0x154));
            M2C_FIELD(arg1, s8 *, 0x63) = 4;
            COLL_MOVED_TRIANGL_TestPoint(arg1, (void *)((u8 *)arg1 + 0x168), (void *)((u8 *)arg1 + 0x140), (void *)((u8 *)arg1 + 0x104));
            M2C_FIELD(arg1, s8 *, 0x63) = 5;
            COLL_MOVED_TRIANGL_TestPoint(arg1, (void *)((u8 *)arg1 + 0x154), (void *)((u8 *)arg1 + 0x168), (void *)((u8 *)arg1 + 0x118));

            tempT1_4 = M2C_FIELD(arg0, u32 *, 4);
            M2C_FIELD(arg1, s8 *, 0x63) = 6;
            if ((tempT1_4 >> 0x10) != (tempT1_4 & 0xFFFF)) {
                COLL_MOVED_TRIANGL_TestPoint(arg1, (void *)((u8 *)arg1 + 0x190), (void *)((u8 *)arg1 + 0x168), (void *)((u8 *)arg1 + 0x17C));
                M2C_FIELD(arg1, s8 *, 0x63) = 7;
                COLL_MOVED_TRIANGL_TestPoint(arg1, (void *)((u8 *)arg1 + 0x17C), (void *)((u8 *)arg1 + 0x12C), (void *)((u8 *)arg1 + 0x190));
                M2C_FIELD(arg1, s8 *, 0x63) = 8;
                COLL_MOVED_TRIANGL_TestPoint(arg1, (void *)((u8 *)arg1 + 0x104), (void *)((u8 *)arg1 + 0x17C), (void *)((u8 *)arg1 + 0x168));
                M2C_FIELD(arg1, s8 *, 0x63) = 9;
                COLL_MOVED_TRIANGL_TestPoint(arg1, (void *)((u8 *)arg1 + 0x118), (void *)((u8 *)arg1 + 0x168), (void *)((u8 *)arg1 + 0x190));
            }
        } else {
            COLL_FIXED_QUADBLK_GetNormVecs_LoLOD(arg1, arg0);
            M2C_FIELD(arg1, s8 *, 0x63) = 0;
            COLL_MOVED_TRIANGL_TestPoint(arg1, (void *)((u8 *)arg1 + 0xF0), (void *)((u8 *)arg1 + 0x104), (void *)((u8 *)arg1 + 0x118));

            tempT1_5 = M2C_FIELD(arg0, u32 *, 4);
            M2C_FIELD(arg1, s8 *, 0x63) = 1;
            if ((tempT1_5 >> 0x10) != (tempT1_5 & 0xFFFF)) {
                COLL_MOVED_TRIANGL_TestPoint(arg1, (void *)((u8 *)arg1 + 0x104), (void *)((u8 *)arg1 + 0x12C), (void *)((u8 *)arg1 + 0x118));
            }
        }
    }
}
