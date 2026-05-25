typedef signed char s8;
typedef short s16;
typedef int s32;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s8 unk10;
    s8 unk11;
    s8 unk12;
    s8 unk13;
} M2cSetDefDispEnvArg0;

void SetDefDispEnv(M2cSetDefDispEnvArg0 *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    M2cSetDefDispEnvArg0 *tempV0;

    tempV0 = arg0;
    tempV0->unk0 = arg1;
    tempV0->unk2 = arg2;
    tempV0->unk4 = arg3;
    tempV0->unk8 = 0;
    tempV0->unkA = 0;
    tempV0->unkC = 0;
    tempV0->unkE = 0;
    tempV0->unk11 = 0;
    tempV0->unk10 = 0;
    tempV0->unk13 = 0;
    tempV0->unk12 = 0;
    tempV0->unk6 = arg4;
}