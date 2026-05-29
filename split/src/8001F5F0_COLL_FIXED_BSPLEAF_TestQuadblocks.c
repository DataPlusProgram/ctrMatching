typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK COLL_FIXED_BSPLEAF_TestInstance(); /* extern */
M2C_UNK COLL_FIXED_QUADBLK_TestTriangles(); /* extern */

void COLL_FIXED_BSPLEAF_TestQuadblocks(void *arg0, void *arg1) {
    void *temp_s2;
    s32 var_s0;
    s32 temp;
    s32 *varPtr;

    temp_s2 = arg0;

    if (*(s32 *)temp_s2 & 2) {
        temp = M2C_FIELD(arg1, s32 *, 0x1A4);
        temp |= 0x8000;
        M2C_FIELD(arg1, s32 *, 0x1A4) = temp;
    }

    varPtr = M2C_FIELD(temp_s2, s32 **, 0x1C);
    var_s0 = M2C_FIELD(temp_s2, s32 *, 0x18);

    do {
        COLL_FIXED_QUADBLK_TestTriangles(varPtr, arg1);
        var_s0--;
        varPtr = (s32 *)((s8 *)varPtr + 0x5C);
    } while (var_s0 > 0);

    temp = M2C_FIELD(arg1, s16 *, 0x22);
    if (temp & 1) {
        COLL_FIXED_BSPLEAF_TestInstance(temp_s2, arg1);
    }
}