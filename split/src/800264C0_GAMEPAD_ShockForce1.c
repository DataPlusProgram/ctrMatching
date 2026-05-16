typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x4A];
    u8 unk4A;
    char pad4B[0x2C8 - 0x4B];
    s32 unk2C8;
} M2cGAMEPADShockForce1Arg0;

extern s32 *D_8008D2AC;
extern s32 D_8008D2B0;

void GAMEPAD_ShockForce1(M2cGAMEPADShockForce1Arg0 *arg0, s32 arg1, s32 arg2) {
    u8 temp_a0;
    void *temp_v1;

    if (!(arg0->unk2C8 & 0x100000)) {
        temp_a0 = arg0->unk4A;
        if (!(*D_8008D2AC & (0x100 << temp_a0))) {
            temp_v1 = D_8008D2B0 + (temp_a0 * 0x50);
            if (((u16) M2C_FIELD(temp_v1, u16 *, 0x28) < 0x385U) && ((s32) M2C_FIELD(temp_v1, u8 *, 0x40) < arg2)) {
                M2C_FIELD(temp_v1, s32 *, 0x34) = arg1;
                M2C_FIELD(temp_v1, u8 *, 0x40) = (u8) arg2;
            }
        }
    }
}