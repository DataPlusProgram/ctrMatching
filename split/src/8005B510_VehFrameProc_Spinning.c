typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    char pad0[0x4C];
    s8 unk4C;
    s8 unk4D;
    char pad4E[0x534];
    s16 unk582;
} M2cVehFrameProcSpinningArg1;

s32 VehCalc_InterpBySpeed();
s32 VehFrameInst_GetNumAnimFrames();
s32 VehFrameInst_GetStartFrame();

void VehFrameProc_Spinning(void *arg0, M2cVehFrameProcSpinningArg1 *arg1) {
    s32 varS1;
    s32 varS2;
    unsigned long tempV0;
    void *tempS0;

    tempS0 = *((void **)(((s8 *)arg0) + 0x34));
    varS1 = VehFrameInst_GetNumAnimFrames(tempS0, *((u8 *)(((s8 *)tempS0) + 0x52)));
    if (varS1 > 0) {
        if (*((u8 *)(((s8 *)tempS0) + 0x52)) != 0) {
            tempV0 = *((u8 *)(((s8 *)tempS0) + 0x52));
            varS2 = VehFrameInst_GetStartFrame(tempV0, varS1);
            if ((u32)(*((u8 *)(((s8 *)tempS0) + 0x52)) - 2) < 2U) {
                arg1->unk4C = 0;
                arg1->unk4D = 0;
            }
            if (*((s16 *)(((s8 *)tempS0) + 0x54)) == varS2) {
                varS1 = VehFrameInst_GetNumAnimFrames(tempS0, 0U);
                if (varS1 <= 0) {
                    goto block_end;
                }
                *((u8 *)(((s8 *)tempS0) + 0x52)) = 0U;
                goto block_7;
            } else {
block_7:
                if (*((u8 *)(((s8 *)tempS0) + 0x52)) != 0) {
                    goto block_11;
                }
            }
        }
        varS2 = 0;
        if (arg1->unk582 >= 0) {
            varS2 = varS1 - 1;
        }
block_11:
        *((s16 *)(((s8 *)tempS0) + 0x54)) = VehCalc_InterpBySpeed(*((s16 *)(((s8 *)tempS0) + 0x54)), 4, varS2);
    }
block_end:
    return;
}
