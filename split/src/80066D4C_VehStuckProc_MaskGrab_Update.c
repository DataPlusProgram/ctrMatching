typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK VehBirth_TeleportSelf();
M2C_UNK VehStuckProc_MaskGrab_FindDestPos();
M2C_UNK VehStuckProc_RevEngine_Init();
extern void *D_8008D2AC;

void VehStuckProc_MaskGrab_Update(s32 arg0, void *arg1) {
    s32 tempV1;
    void *tempV1_2;
    void *tempV1_3;

    tempV1 = M2C_FIELD(arg1, u16 *, 0x400) - M2C_FIELD(D_8008D2AC, u16 *, 0x1D04);
    M2C_FIELD(arg1, u16 *, 0x400) = tempV1;

    if ((s16)tempV1 < 0) {
        M2C_FIELD(arg1, u16 *, 0x400) = 0;
    }

    if (M2C_FIELD(arg1, s16 *, 0x400) == 0) {
        tempV1_2 = M2C_FIELD(arg1, void **, 0x580);
        if (tempV1_2 != NULL) {
            M2C_FIELD(tempV1_2, u16 *, 4) = M2C_FIELD(tempV1_2, u16 *, 4) & 0xFFFE;
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x580), s16 *, 0x12) = 0x1000;
        }

        tempV1_3 = D_8008D2AC + (M2C_FIELD(arg1, u8 *, 0x4A) * 0xDC);
        M2C_FIELD(tempV1_3, s32 *, 0x1508) = M2C_FIELD(tempV1_3, s32 *, 0x1508) | 8;

        VehStuckProc_MaskGrab_FindDestPos(arg1, M2C_FIELD(arg1, s32 *, 0x354));
        VehBirth_TeleportSelf(arg1, 0, 0x80);
        VehStuckProc_RevEngine_Init(arg0, arg1);
    }
}