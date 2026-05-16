typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 D_8008D0B3;

s32 LOAD_GetBigfileIndex(u32 arg0, s32 arg1, s32 arg2) {
    u32 tempA3;
    u32 tempV1;
    u32 tempV1_2;
    u32 tempV1_3;

    tempA3 = arg0 - 0x12;
    if (arg0 < 0x12U) {
        return (arg0 * 8) + *(&D_8008D0B3 + arg1) + arg2;
    }

    tempV1_3 = arg0 - 0x1E;
    if (tempA3 < 7U) {
        return (tempA3 * 8) + *(&D_8008D0B3 + arg1) + arg2 + 0x90;
    }

    if (tempV1_3 < 9U) {
        return (tempV1_3 * 3) + arg2 + 0x203;
    }

    tempV1_2 = arg0 - 0x2A;
    if (tempV1_2 < 2U) {
        return (tempV1_2 * 2) + arg2 + 0x21E;
    }

    if (arg0 == 0x28) {
        return arg2 + 0xD9;
    }

    tempV1 = arg0 - 0x2C;
    if (arg0 == 0x29) {
        return arg2 + 0x201;
    }

    if (tempV1 < 0x14U) {
        return (tempV1 * 3) + arg2 + 0x222;
    }

    if (arg0 == 0x27) {
        return arg2 + 0xD7;
    }

    if (arg0 == 0x40) {
        return arg2 + 0x25E;
    }

    return ((arg0 - 0x19) * 3) + arg2 + 0xC8;
}