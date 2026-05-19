typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))
#define SAVE_RA() asm volatile("lui $at,%%hi(D_8009F6CC)\n\tsw $ra,%%lo(D_8009F6CC)($at)" : : : "at", "memory")
#define RESTORE_RA() asm volatile("lui $ra,%%hi(D_8009F6CC)\n\tlw $ra,%%lo(D_8009F6CC)($ra)" : : : "ra", "memory")

M2C_UNK EnterCriticalSection(); /* extern */
M2C_UNK ExitCriticalSection();  /* extern */
M2C_UNK FlushCache();           /* extern */

extern s32 D_8009F6CC;
extern s32 D_800808B0;
extern s32 D_800808BC;

void _ExitCard(void) {
    s32 *varT2;
    s32 *endT1;
    void *varV0;

    SAVE_RA();

    EnterCriticalSection();

    varV0 = ((void *(*)())0xB0)();
    varV0 = M2C_FIELD(varV0, void **, 0x18);

    varT2 = &D_800808B0;
    endT1 = &D_800808BC;

    do {
        M2C_FIELD(varV0, s32 *, 0x70) = *varT2;
        varT2 += 1;
        varV0 = (s8 *)varV0 + 4;
    } while (varT2 != endT1);

    FlushCache();
    ExitCriticalSection();

    RESTORE_RA();
}