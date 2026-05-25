typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0xC];
    s32 unkC;
    char pad10[0x27];
    u8 unk37;
    u8 unk38;
} M2cUnknown8007E9E4Arg0;

void _Unknown_8007E9E4(M2cUnknown8007E9E4Arg0 *arg0) {
    s32 varA2;
    u8 tempV0;
    u8 tempV1;
    u8 *varA1;

    tempV1 = arg0->unk37;
    varA1 = (u8 *)(arg0->unkC + 0x37);
    varA2 = 0;
    arg0->unk37 = 0;
    arg0->unk38 = tempV1;

    do {
        tempV0 = varA1[1];
        tempV1 = varA1[0];

        varA2 += 1;

        varA1[0] = 0;
        varA1[2] = tempV0;
        varA1[1] = tempV1;

        varA1 += 0xF0;
    } while (varA2 < 4);
}