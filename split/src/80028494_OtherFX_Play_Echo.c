typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK OtherFX_Play_LowLevel();   /* extern */

void OtherFX_Play_Echo(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK varV0;

    varV0 = 0xFF8080;
    arg0 &= 0xFFFF;
    arg1 &= 0xFF;

    if (arg2 != 0) {
        varV0 = 0x01FF8080;
    }

    OtherFX_Play_LowLevel(arg0, arg1, varV0);
}