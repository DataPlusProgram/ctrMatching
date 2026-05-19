typedef int s32;

s32 SetDrawEnv_Unknown_80073E28(s32 arg0, s32 arg1, s32 arg2) {
    s32 varV0;
    s32 varV1;

    varV1 = 0xE1000000;
    if (arg1 != 0) {
        varV1 |= 0x200;
    }

    varV0 = arg2 & 0x9FF;
    if (arg0 != 0) {
        varV0 |= 0x400;
    }

    varV0 = varV1 | varV0;
    return varV0 + 0;
}