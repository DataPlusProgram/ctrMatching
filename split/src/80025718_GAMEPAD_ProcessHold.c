typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

#define NULL 0
#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    s8 pad0[0x10];
    s32 unk10;
    s8 pad14[0x8];
    s32 unk1C;
    void *unk20;
    s8 pad24[0x4];
    u16 unk28;
} GamepadEntry;

extern s32 D_800824A8;

s32 GAMEPAD_ProcessHold(GamepadEntry *arg0) {
    s8 *varV1;
    s32 tempV0;
    s32 varA2;
    s32 varA3;
    s32 varT0;
    s32 varT1;
    u16 tempV1_2;
    u8 tempV1;
    void *tempA1;

    varT1 = 0;
    varT0 = 0;

    do {
        tempV0 = arg0->unk10;
        tempA1 = arg0->unk20;
        arg0->unk1C = tempV0;

        if (tempA1 != NULL) {
            if (M2C_FIELD(tempA1, u8 *, 0) == 0) {
                varA2 = ((M2C_FIELD(tempA1, u8 *, 2) << 8) | M2C_FIELD(tempA1, u8 *, 3)) ^ 0xFFFF;
                tempV1 = M2C_FIELD(tempA1, u8 *, 1);
                varA3 = 0;

                if (tempV1 != 0x23) {
                    if (tempV1 == 0x53) {
                        varA2 <<= 0x10;
                    }
                } else {
                    if (M2C_FIELD(tempA1, u8 *, 5) >= 0x41U) {
                        varA2 |= 0x40;
                    }
                    if (M2C_FIELD(tempA1, u8 *, 6) >= 0x41U) {
                        varA2 |= 0x80;
                    }
                    if (M2C_FIELD(tempA1, u8 *, 7) >= 0x41U) {
                        varA2 |= 4;
                    }
                }

                tempV0 = D_800824A8;
                if (tempV0 != 0) {
                    varV1 = (s8 *)&D_800824A8;
                    do {
                        if ((varA2 & tempV0) != 0) {
                            varA3 |= M2C_FIELD(varV1, s32 *, 4);
                        }
                        varV1 += 8;
                        tempV0 = M2C_FIELD(varV1, s32 *, 0);
                    } while (tempV0 != 0);
                }

                arg0->unk10 = varA3;
                if (varA3 != 0) {
                    arg0->unk28 = 0;
                } else {
                    tempV1_2 = arg0->unk28;
                    if (tempV1_2 <= 0xFDE7U) {
                        arg0->unk28 = tempV1_2 + 1;
                    }
                }

                varT1 |= varA3;
            }
        } else {
            arg0->unk10 = 0;
            arg0->unk1C = 0;
        }

        varT0++;
        arg0 = (GamepadEntry *)((s8 *)arg0 + 0x50);
    } while (varT0 < 8);

    return varT1;
}