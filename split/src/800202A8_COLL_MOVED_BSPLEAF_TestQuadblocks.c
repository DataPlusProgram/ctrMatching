typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK COLL_FIXED_BSPLEAF_TestInstance(); /* extern */
M2C_UNK COLL_MOVED_QUADBLK_TestTriangles(); /* extern */

void COLL_MOVED_BSPLEAF_TestQuadblocks(void *arg0, void *arg1)
{
    s32 varS0;
    s32 temp;
    s32 *varPtr;

    if (*(s32 *)arg0 & 2) {
        temp = *(s32 *)((s8 *)arg1 + 0x1A4);
        temp |= 0x8000;
        *(s32 *)((s8 *)arg1 + 0x1A4) = temp;
    }

    varS0 = *(s32 *)((s8 *)arg0 + 0x18);
    varPtr = (s32 *)*(s32 *)((s8 *)arg0 + 0x1C);

    do {
        COLL_MOVED_QUADBLK_TestTriangles(varPtr, arg1);
        varS0--;
        varPtr = (s32 *)((s8 *)varPtr + 0x5C);
    } while (varS0 > 0);

    temp = *(s16 *)((s8 *)arg1 + 0x22);
    if (temp & 1) {
        COLL_FIXED_BSPLEAF_TestInstance(arg0, arg1);
    }
}