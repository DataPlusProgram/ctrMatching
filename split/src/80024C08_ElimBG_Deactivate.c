typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x1D31];
    u8 unk1D31;
    char pad1D32[0x83A];
    s32 unk256C;
} M2cElimBGDeactivateArg0;

extern M2C_UNK s_ghost __attribute__((section(".sdata")));
extern M2C_UNK s_ghost1 __attribute__((section(".sdata")));

void ElimBG_Deactivate(M2cElimBGDeactivateArg0 *arg0) {
    s32 tempA0;

    if (M2C_FIELD(&s_ghost1, s16 *, 2) != 0) {
        M2C_FIELD(&s_ghost1, s16 *, 2) = 3;

        tempA0 = arg0->unk256C & 0x1000;
        arg0->unk256C = tempA0 | (M2C_FIELD(&s_ghost, s32 *, 4) & ~0x1000);

        arg0->unk1D31 = M2C_FIELD(&s_ghost1, u8 *, 0);
    }
}