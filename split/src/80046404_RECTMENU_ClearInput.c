typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

extern M2C_UNK buttonHeldPerPlayer;
extern M2C_UNK buttonTapPerPlayer;
s32 rcntTotalUnits;
s32 unk8008d964;

void RECTMENU_ClearInput(void) {
    s16 temp_v1;
    s16 var_a1;
    s32 temp_a0;
    s32 temp_a0_2;

    var_a1 = 0;
    unk8008d964 = 0;
    rcntTotalUnits = 0;
    do {
        temp_a0 = var_a1 << 0x10;
        temp_v1 = var_a1 + 1;
        var_a1 = temp_v1;
        temp_a0_2 = temp_a0 >> 0xE;
        *(temp_a0_2 + &buttonTapPerPlayer) = 0;
        *(temp_a0_2 + &buttonHeldPerPlayer) = 0;
    } while (temp_v1 < 4);
}