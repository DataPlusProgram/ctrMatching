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
} M2cGAMEPADJogCon1Arg0;

extern s32 D_8008D2B0;

void GAMEPAD_JogCon1(M2cGAMEPADJogCon1Arg0 *arg0, s32 arg1, s16 arg2) {
    void *tempA0;
    s32 tempV1;

    if (!(arg0->unk2C8 & 0x100000)) {
        tempV1 = arg0->unk4A;
        tempA0 = D_8008D2B0 + (tempV1 * 0x50);
        tempV1 = M2C_FIELD(tempA0, u8 *, 0x45);

        if ((arg1 & 0xF) >= (tempV1 & 0xF)) {
            M2C_FIELD(tempA0, u8 *, 0x45) = arg1;
            M2C_FIELD(tempA0, s16 *, 0x46) = arg2;
        }
    }
}