typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	char pad0[0x83];
	u8 unk83;
	char pad84[0x7C];
	s32 unk100;
} M2cElimBGActivateArg0;

M2C_UNK s_ghost;
M2C_UNK s_ghost1;

void ElimBG_Activate(M2cElimBGActivateArg0 *arg0) {
    M2C_FIELD(&s_ghost1, s16 *, 2) = 1;
    M2C_FIELD(&s_ghost, s32 *, 4) = (s32) arg0->unk100;
    M2C_FIELD(&s_ghost1, s16 *, 0) = (s16) arg0->unk83;
}