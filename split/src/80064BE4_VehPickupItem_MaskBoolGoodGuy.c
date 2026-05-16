typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct {
    char pad0[0x4A];
    u8 unk4A;
} M2cVehPickupItemMaskBoolGoodGuyArg0;

extern s16 D_80086E84[];

s32 VehPickupItem_MaskBoolGoodGuy(M2cVehPickupItemMaskBoolGoodGuyArg0 *arg0) {
    s16 temp_v1;
    s32 var_a0;

    temp_v1 = D_80086E84[arg0->unk4A];
    var_a0 = 0;

    if ((temp_v1 == 0) || (temp_v1 == 3) || (temp_v1 == 6) || (temp_v1 == 7) || (temp_v1 == 0xD)) {
        var_a0 = 1;
    }

    return var_a0;
}