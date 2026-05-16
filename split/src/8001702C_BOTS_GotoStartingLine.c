typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void FUN_80057c8c(s32 arg0, s32 arg1, s32 arg2);
void FUN_80013444(s32 arg0, s32 arg1);
u16 FUN_8006c684(void *arg0);

extern s32 DAT_8008d698;
extern u8 DAT_8008d69c[];
extern u8 DAT_8008d680[];
extern s32 DAT_8008dae0[];
extern s32 DAT_8008cf80;
extern M2C_UNK DAT_8008d668;

void FUN_8001702c(s32 param_1) {
    u8 bVar1;
    s32 iVar2;
    s16 sVar3;
    u16 temp_v0;
    s32 uVar4;

    DAT_8008d698 = 0;
    FUN_80057c8c(param_1, 3, 0);

    bVar1 = DAT_8008d69c[M2C_FIELD(param_1, u8 *, 0x4A)];

    M2C_FIELD(param_1, s32 *, 0x5F8) = M2C_FIELD(param_1, s32 *, 0x2DC);
    M2C_FIELD(param_1, s32 *, 0x5EC) = 0;
    M2C_FIELD(param_1, s32 *, 0x5E8) = 0;
    M2C_FIELD(param_1, s32 *, 0x5E4) = 0;
    M2C_FIELD(param_1, s32 *, 0x5E0) = 0;
    M2C_FIELD(param_1, s32 *, 0x5DC) = 0;
    M2C_FIELD(param_1, s32 *, 0x5D8) = 0;
    M2C_FIELD(param_1, s32 *, 0x5D4) = 0;
    M2C_FIELD(param_1, s32 *, 0x5D0) = 0;
    M2C_FIELD(param_1, s32 *, 0x5CC) = 0;

    M2C_FIELD(param_1, s32 *, 0x5F4) = M2C_FIELD(param_1, s32 *, 0x2D8);
    M2C_FIELD(param_1, s32 *, 0x5F0) = M2C_FIELD(param_1, s32 *, 0x2D4);

    uVar4 = DAT_8008dae0[M2C_FIELD(param_1, s16 *, 0x5B8)];
    M2C_FIELD(param_1, s32 *, 0x5A8) = 0;
    M2C_FIELD(param_1, s32 *, 0x5A4) = uVar4;

    FUN_80013444(param_1, 1);

    iVar2 = DAT_8008cf80;
    bVar1 = DAT_8008d680[bVar1];

    M2C_FIELD(param_1, s16 *, 0x2F0) = 0;
    M2C_FIELD(param_1, s16 *, 0x2F8) = 0;
    M2C_FIELD(param_1, s16 *, 0x600) = 0;
    M2C_FIELD(param_1, s16 *, 0x2EC) = 0;
    M2C_FIELD(param_1, s16 *, 0x2F4) = 0;
    M2C_FIELD(param_1, s16 *, 0x5FC) = 0;
    M2C_FIELD(param_1, s16 *, 0x3C6) = 0;

    sVar3 = M2C_FIELD(param_1, u8 *, 0x613) << 4;

    M2C_FIELD(param_1, u32 *, 0x2C8) |= 0x100000;

    M2C_FIELD(param_1, s16 *, 0x608) = sVar3;
    M2C_FIELD(param_1, s16 *, 0x39A) = sVar3;
    M2C_FIELD(param_1, s16 *, 0x2EE) = sVar3;
    M2C_FIELD(param_1, s16 *, 0x2F6) = sVar3;
    M2C_FIELD(param_1, s16 *, 0x5FE) = sVar3;

    M2C_FIELD(param_1, u32 *, 0x5B4) = iVar2 * bVar1;

    temp_v0 = FUN_8006c684(&DAT_8008d668);
    M2C_FIELD(param_1, u16 *, 0x624) = (temp_v0 & 0xFF) + 300;
}