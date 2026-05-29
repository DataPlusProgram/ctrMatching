typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK LOAD_RunPtrMap();           /* extern */
M2C_UNK MEMPACK_ClearHighMem();                     /* extern */
M2C_UNK MEMPACK_SwapPacks();                     /* extern */
extern void *gT;
M2C_UNK levBigLodIndex;
s32 queueReady;

void LOAD_Callback_PatchMem(void *arg0) {
    s32 *temp_a1;

    temp_a1 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(&levBigLodIndex, s32 *, 4) = 0;
    LOAD_RunPtrMap(queueReady, temp_a1 + 4, (s32) *temp_a1 >> 2);
    MEMPACK_SwapPacks(0);
    MEMPACK_ClearHighMem();
    MEMPACK_SwapPacks(M2C_FIELD(gT, s16 *, 0x254A));
}