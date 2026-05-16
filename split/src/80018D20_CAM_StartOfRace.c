typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008D2AC;

void CAM_StartOfRace(void *arg0) {
    s32 tempV1;
    void *tempA1;
    void *tempV1_2;

    tempA1 = D_8008D2AC;
    tempV1_2 = M2C_FIELD(tempA1, void **, 0x160);

    if (M2C_FIELD(tempV1_2, s32 *, 0x148) >= 3) {
        tempV1 = M2C_FIELD(tempV1_2, s32 *, 0x14C);
        M2C_FIELD(arg0, s32 *, 0x94) = 0;
        M2C_FIELD(arg0, s16 *, 0x8C) = 0;
        M2C_FIELD(arg0, s16 *, 0x9E) = 0x1E;
        M2C_FIELD(arg0, s16 *, 0xA) = 0;
        M2C_FIELD(arg0, s16 *, 0x9A) = 0;
        M2C_FIELD(arg0, s32 *, 0x88) = tempV1 + 0x18;

        if ((u8) M2C_FIELD(tempA1, u8 *, 0x1CA8) >= 2U) {
            M2C_FIELD(arg0, s16 *, 0x8E) = 1;
        } else {
            M2C_FIELD(arg0, s16 *, 0x8E) = 0xA5;
        }
    }

    M2C_FIELD(arg0, s16 *, 0x9A) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = M2C_FIELD(arg0, s32 *, 0x70) & ~0x1004;
}