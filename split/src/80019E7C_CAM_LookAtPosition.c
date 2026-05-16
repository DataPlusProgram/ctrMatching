#include "../../common.h"


#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} M2cCAMLookAtPositionArg1;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cCAMLookAtPositionArg2;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cCAMLookAtPositionArg3;

s32 SquareRoot0_stub();               /* extern */
s32 ratan2(s32, s32);                 /* extern */

extern s32 D_80080FE8[];
extern void *D_8008D2AC;

void CAM_LookAtPosition(
    void *arg0,
    M2cCAMLookAtPositionArg1 *arg1,
    M2cCAMLookAtPositionArg2 *arg2,
    M2cCAMLookAtPositionArg3 *arg3
) {
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;

    temp_v1 = arg2->unk0 - (arg1->unk0 >> 8);
    M2C_FIELD(arg0, s32 *, 0x24C) = temp_v1;

    temp_a3 = (arg1->unk4 >> 8) + D_80080FE8[M2C_FIELD(D_8008D2AC, u8 *, 0x1CA8)];
    M2C_FIELD(arg0, s32 *, 0x250) = arg2->unk2 - temp_a3;

    temp_a1 = arg2->unk4 - (arg1->unk8 >> 8);
    M2C_FIELD(arg0, s32 *, 0x254) = temp_a1;

    arg3->unk2 = ratan2(M2C_FIELD(arg0, s32 *, 0x24C), temp_a1);

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x24C);
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x254);

    temp_v0 = ratan2(
        M2C_FIELD(arg0, s32 *, 0x250),
        SquareRoot0_stub((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2))
    );

    arg3->unk0 = 0x800 - temp_v0;
    arg3->unk4 = 0;
}