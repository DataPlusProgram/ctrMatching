typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x4A];
    u8 unk4A;
    char pad4B[0x27D];
    s32 unk2C8;
} M2cGAMEPADJogCon2Arg0;

extern s32 D_8008D2B0;

void GAMEPAD_JogCon2(M2cGAMEPADJogCon2Arg0 *arg0, s8 arg1, s16 arg2) {
    void *tempV0;

    if (!(arg0->unk2C8 & 0x100000)) {
        tempV0 = D_8008D2B0 + (arg0->unk4A * 0x50);
        M2C_FIELD(tempV0, s8 *, 0x42) = arg1;
        M2C_FIELD(tempV0, s16 *, 0x48) = arg2;
    }
}