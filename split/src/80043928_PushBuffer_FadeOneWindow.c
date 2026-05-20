typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x12];
    s16 unk12;
    s16 unk14;
    u16 unk16;
    char pad18[0x8];
    u16 unk20;
    u16 unk22;
    char pad24[0xD0];
    s32 unkF4;
} M2cPushBufferFadeOneWindowArg0;

M2C_UNK AddPrim();
extern void *D_8008D2AC;

void PushBuffer_FadeOneWindow(M2cPushBufferFadeOneWindowArg0 *arg0) {
    s16 tempV02;
    s16 tempV1;
    s32 tempV0;
    s32 varV0;
    u16 tempU0;
    void *tempV12;
    void *varA1;

    tempV1 = arg0->unk12;
    if (tempV1 != 0x1000) {
        if (tempV1 >= 0x1001) {
            varA1 = M2C_FIELD(M2C_FIELD(D_8008D2AC, void **, 0x10), void **, 0x80);
            M2C_FIELD(varA1, s8 *, 3) = 7;
            M2C_FIELD(varA1, s8 *, 0xF) = 0x2A;
            M2C_FIELD(varA1, s32 *, 4) = 0xE1000A20;
            M2C_FIELD(varA1, s32 *, 8) = 0;

            varV0 = arg0->unk12 - 0x1000;

            M2C_FIELD(varA1, s16 *, 0x10) = 0;
            M2C_FIELD(varA1, s16 *, 0x12) = 0;
        } else {
            varA1 = M2C_FIELD(M2C_FIELD(D_8008D2AC, void **, 0x10), void **, 0x80);
            M2C_FIELD(varA1, s8 *, 3) = 7;
            M2C_FIELD(varA1, s8 *, 0xF) = 0x2A;
            M2C_FIELD(varA1, s32 *, 4) = 0xE1000A40;
            M2C_FIELD(varA1, s32 *, 8) = 0;

            tempV1 = arg0->unk12;
            varV0 = 0xFFF - tempV1;

            M2C_FIELD(varA1, s16 *, 0x10) = 0;
            M2C_FIELD(varA1, s16 *, 0x12) = 0;
        }

        tempV0 = varV0 >> 4;
        M2C_FIELD(varA1, s8 *, 0xE) = tempV0;
        M2C_FIELD(varA1, s8 *, 0xD) = tempV0;
        M2C_FIELD(varA1, s8 *, 0xC) = tempV0;

        tempU0 = arg0->unk20;

        M2C_FIELD(varA1, s16 *, 0x16) = 0;
        M2C_FIELD(varA1, s16 *, 0x18) = 0;

        M2C_FIELD(varA1, u16 *, 0x14) = tempU0;
        M2C_FIELD(varA1, u16 *, 0x1A) = arg0->unk22;
        M2C_FIELD(varA1, u16 *, 0x1C) = arg0->unk20;
        M2C_FIELD(varA1, u16 *, 0x1E) = arg0->unk22;

        AddPrim(arg0->unkF4, varA1);

        tempV12 = M2C_FIELD(D_8008D2AC, void **, 0x10);
        M2C_FIELD(tempV12, s32 *, 0x80) = M2C_FIELD(tempV12, s32 *, 0x80) + 0x20;
    }

    tempV02 = (u16)arg0->unk12 + arg0->unk16;
    arg0->unk12 = tempV02;

    if ((s16)arg0->unk16 > 0) {
        if (arg0->unk14 < tempV02) {
            arg0->unk12 = (u16)arg0->unk14;
        }
    } else if (tempV02 < arg0->unk14) {
        arg0->unk12 = (u16)arg0->unk14;
    }
}