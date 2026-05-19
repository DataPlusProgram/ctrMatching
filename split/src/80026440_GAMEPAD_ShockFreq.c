typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x4A];
    u8 unk4A;
    char pad4B[0x27D];
    s32 unk2C8;
} M2cGAMEPADShockFreqArg0;

extern s32 *D_8008D2AC;
extern s32 D_8008D2B0;

void GAMEPAD_ShockFreq(M2cGAMEPADShockFreqArg0 *arg0, s32 arg1, s32 arg2) {
    u8 tempA0;
    void *tempV1;

    if (!(arg0->unk2C8 & 0x100000)) {
        tempA0 = arg0->unk4A;
        if (!(*D_8008D2AC & (0x100 << tempA0))) {
            tempV1 = D_8008D2B0 + (tempA0 * 0x50);
            if (((u16) M2C_FIELD(tempV1, u16 *, 0x28) < 0x385U) && (M2C_FIELD(tempV1, s32 *, 0x30) < arg1)) {
                M2C_FIELD(tempV1, s32 *, 0x30) = arg1;
                M2C_FIELD(tempV1, s32 *, 0x3C) = arg2;
            }
        }
    }
}