typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s16 ratan2();
extern u16 D_80080FD4[];
extern void *D_8008D2AC;

void CAM_EndOfRace_Battle(void *arg0, void *arg1) {
    void *tempV0;
    s32 tempA0;
    s32 tempA1;

    M2C_FIELD(arg0, s16 *, 0xA4) = -0x1B;
    M2C_FIELD(arg0, s32 *, 0x70) = M2C_FIELD(arg0, s32 *, 0x70) | 4;

    M2C_FIELD(arg0, u16 *, 0xA6) = D_80080FD4[M2C_FIELD(D_8008D2AC, u8 *, 0x1CA8) * 2];

    M2C_FIELD(arg0, s16 *, 0xA8) = 0xC0;
    tempV0 = M2C_FIELD(arg0, void **, 0x48);

    tempA0 = M2C_FIELD(arg1, s32 *, 0x2D4);
    tempA1 = M2C_FIELD(arg1, s32 *, 0x2DC);

    M2C_FIELD(arg0, s16 *, 0x90) = ratan2(
        M2C_FIELD(tempV0, s16 *, 0) - (tempA0 >> 8),
        M2C_FIELD(tempV0, s16 *, 4) - (tempA1 >> 8)
    );

    M2C_FIELD(arg0, s16 *, 0x8C) = 0;
    M2C_FIELD(arg0, s16 *, 0x8E) = 0x3C;
    M2C_FIELD(arg0, s16 *, 0x9E) = 0x3C;
}