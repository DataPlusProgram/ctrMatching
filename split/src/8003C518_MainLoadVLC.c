typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK LOAD_AppendQueue(); /* extern */
s32 MEMPACK_AllocMem();               /* extern */
extern M2C_UNK MainLoadVLC_Callback;
s32 memcard_remainingAttempts;
extern void *ptrBigfileCdPos_2;
extern M2C_UNK s_VlcTable;
s32 s_memcardDirHeader;

void MainLoadVLC(void) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a0;

    temp_v0 = M2C_FIELD(ptrBigfileCdPos_2, s32 *, 0xF0C);
    s_memcardDirHeader = 0;
    temp_a0 = temp_v0 + 0x7FF;
    var_a0 = temp_a0 >> 0xB;
    if (temp_a0 < 0) {
        var_a0 = (s32) (temp_v0 + 0xFFE) >> 0xB;
    }
    temp_v0_2 = MEMPACK_AllocMem(var_a0 << 0xB, &s_VlcTable);
    memcard_remainingAttempts = temp_v0_2;
    LOAD_AppendQueue(ptrBigfileCdPos_2, 1, 0x1E0, temp_v0_2, &MainLoadVLC_Callback);
}