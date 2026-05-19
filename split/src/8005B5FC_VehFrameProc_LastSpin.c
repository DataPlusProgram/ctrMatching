typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x3C6];
    s16 unk3C6;
    char pad3C8[0xA];
    s16 unk3D2;
} M2cVehFrameProcLastSpinArg1;

s16 VehCalc_InterpBySpeed();
s32 VehFrameInst_GetNumAnimFrames();
M2C_UNK VehFrameProc_Spinning();

void VehFrameProc_LastSpin(void *arg0, M2cVehFrameProcLastSpinArg1 *arg1) {
    s32 varA2;
    s32 tempV0;
    void *tempS0;

    tempS0 = M2C_FIELD(arg0, void **, 0x34);
    if (M2C_FIELD(tempS0, u8 *, 0x52) != 0) {
        VehFrameProc_Spinning();
        return;
    }

    tempV0 = VehFrameInst_GetNumAnimFrames(tempS0, 0);
    if (tempV0 > 0) {
        varA2 = M2C_FIELD(tempS0, s16 *, 0x54);

        if (arg1->unk3C6 > 0) {
            if (arg1->unk3D2 < 0) {
                varA2 = tempV0 - 1;
            }
        }

        if ((arg1->unk3C6 < 0) && (arg1->unk3D2 > 0)) {
            varA2 = 0;
        }

        M2C_FIELD(tempS0, s16 *, 0x54) = VehCalc_InterpBySpeed(M2C_FIELD(tempS0, s16 *, 0x54), 3, varA2);
    }
}