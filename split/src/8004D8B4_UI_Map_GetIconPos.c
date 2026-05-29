typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
} M2cUIMapGetIconPosArg0;

extern void *gGamepads;

void UI_Map_GetIconPos(M2cUIMapGetIconPosArg0 *arg0, s32 *arg1, s32 *arg2) {
    s16 temp_a3;
    s32 temp_a0;
    s32 temp_t1;
    s32 temp_t2;
    s32 var_a0;
    s32 var_a3;

    temp_t2 = arg0->unkE - 0x10;
    temp_a0 = arg0->unk0 - arg0->unk4;
    temp_a3 = arg0->unk10;
    temp_t1 = arg0->unk2 - arg0->unk6;

    if (temp_a3 == 0) {
        var_a0 = arg0->unkC + ((s32) (*arg1 * arg0->unk8) / temp_a0);
        var_a3 = temp_t2 + ((s32) (*arg2 * arg0->unkA * 2) / temp_t1);
    } else if (temp_a3 == 1) {
        var_a3 = temp_t2 + ((s32) (*arg1 * arg0->unkA * 2) / temp_a0);
        var_a0 = arg0->unkC - ((s32) (*arg2 * arg0->unk8) / temp_t1);
    } else if (temp_a3 == 2) {
        var_a0 = arg0->unkC - ((s32) (*arg1 * arg0->unk8) / temp_a0);
        var_a3 = temp_t2 - ((s32) (*arg2 * arg0->unkA * 2) / temp_t1);
    } else {
        var_a3 = temp_t2 - ((s32) (*arg1 * arg0->unkA * 2) / temp_a0);
        var_a0 = arg0->unkC + ((s32) (*arg2 * arg0->unk8) / temp_t1);
    }

    if (M2C_FIELD(gGamepads, u8 *, 0x1CA8) == 3) {
        var_a0 -= 0x3C;
        var_a3 += 0xA;
    }

    *arg1 = var_a0;
    *arg2 = var_a3;
}