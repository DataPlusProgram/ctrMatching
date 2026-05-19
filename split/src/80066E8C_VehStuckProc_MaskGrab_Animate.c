typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK OtherFX_Play();
s32 VehFrameInst_GetNumAnimFrames();
s16 VehFrameInst_GetStartFrame();
M2C_UNK VehStuckProc_MaskGrab_Particles();

extern void *D_8008D2AC;

void VehStuckProc_MaskGrab_Animate(void *arg0, void *arg1) {
    s16 tempA0;
    s16 tempV0;
    s16 varV0_2;
    s32 tempV0_4;
    s32 tempV1_2;
    s8 varV0;
    u16 tempV0_2;
    u16 tempV0_3;
    void *tempA0_2;
    void *tempA0_3;
    void *tempS1;
    void *tempV1;

    tempS1 = M2C_FIELD(arg0, void **, 0x34);

    if (M2C_FIELD(arg1, u8 *, 0x58D) != 0) {
        if ((M2C_FIELD(arg1, u8 *, 0x58F) == 0) && (M2C_FIELD(arg1, s16 *, 0x400) < 0x3C0)) {
            OtherFX_Play(0x55, 1);
            M2C_FIELD(arg1, u8 *, 0x58F) = 1U;
        }

        M2C_FIELD(arg1, s8 *, 0x4C) = 4;
        if (M2C_FIELD(arg1, s16 *, 0x58A) >= 3) {
            varV0 = (u8)M2C_FIELD(arg1, s16 *, 0x58A) + 5;
        } else {
            varV0 = 7;
        }

        M2C_FIELD(arg1, s8 *, 0x4D) = varV0;
        M2C_FIELD(tempS1, s8 *, 0x52) = 2;

        varV0_2 = 7;
        if (M2C_FIELD(arg1, s16 *, 0x58A) >= 3) {
            varV0_2 = (u16)M2C_FIELD(arg1, s16 *, 0x58A) + 5;
        }

        M2C_FIELD(tempS1, s16 *, 0x54) = varV0_2;

        tempV0 = (u16)M2C_FIELD(arg1, s16 *, 0x58A) + 1;
        M2C_FIELD(arg1, s16 *, 0x58A) = tempV0;
        if (tempV0 >= 8) {
            M2C_FIELD(arg1, s16 *, 0x58A) = 7;
        }

        if (M2C_FIELD(arg1, s16 *, 0x400) >= 0x510) {
            M2C_FIELD(arg1, s16 *, 0x38C) = 0;
            M2C_FIELD(arg1, s16 *, 0x38E) = 0;
            M2C_FIELD(arg1, s32 *, 0x2D4) = M2C_FIELD(arg1, s32 *, 0x2E0);
            M2C_FIELD(arg1, s32 *, 0x2D8) = M2C_FIELD(arg1, s32 *, 0x2E4);
            M2C_FIELD(arg1, s32 *, 0x2DC) = M2C_FIELD(arg1, s32 *, 0x2E8);
        } else {
            M2C_FIELD(arg1, s8 *, 0x4C) = 4;
            M2C_FIELD(arg1, s8 *, 0x4D) = 0xC;
            M2C_FIELD(tempS1, s8 *, 0x52) = 2;
            M2C_FIELD(tempS1, s16 *, 0x54) = 0xC;

            if (M2C_FIELD(arg1, s16 *, 0x400) >= 0x3C1) {
                if (M2C_FIELD(arg1, u8 *, 0x58C) == 0) {
                    VehStuckProc_MaskGrab_Particles(arg1);
                    M2C_FIELD(arg1, u8 *, 0x58C) = 1U;
                }

                tempV0_2 = M2C_FIELD(arg1, u16 *, 0x40C) + 0x2D0;
                M2C_FIELD(arg1, u16 *, 0x40C) = tempV0_2;
                if ((s16)tempV0_2 >= 0x1F41) {
                    M2C_FIELD(arg1, u16 *, 0x40C) = 0x1F40U;
                }
            } else {
                tempV0_3 = M2C_FIELD(arg1, u16 *, 0x40C) - 0x320;
                M2C_FIELD(arg1, u16 *, 0x40C) = tempV0_3;
                if ((s32)(tempV0_3 << 0x10) < 0) {
                    M2C_FIELD(arg1, u16 *, 0x40C) = 0U;
                }
            }
        }
    } else {
        M2C_FIELD(arg1, s8 *, 0x4C) = 0;
        M2C_FIELD(arg1, s8 *, 0x4D) = 0;
        M2C_FIELD(tempS1, s8 *, 0x52) = 0;
        M2C_FIELD(tempS1, s16 *, 0x54) = VehFrameInst_GetStartFrame(0, VehFrameInst_GetNumAnimFrames(tempS1, 0));
        M2C_FIELD(arg1, u16 *, 0x368) = M2C_FIELD(arg1, u16 *, 0x584);
        M2C_FIELD(arg1, u16 *, 0x36A) = M2C_FIELD(arg1, u16 *, 0x586);
        M2C_FIELD(arg1, u16 *, 0x36C) = M2C_FIELD(arg1, u16 *, 0x588);
    }

    tempV1 = M2C_FIELD(arg1, void **, 0x580);
    if (tempV1 != NULL) {
        M2C_FIELD(tempV1, s16 *, 6) = 0x1E00;

        if (M2C_FIELD(arg1, s16 *, 0x400) >= 0x3C1) {
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x580), s16 *, 0x12) = 0;
            return;
        }

        if (M2C_FIELD(arg1, u8 *, 0x58E) != 0) {
            tempV0_4 = M2C_FIELD(D_8008D2AC, s32 *, 0x1D04);
            tempV0_4 = tempV0_4 << 7;
            tempV1_2 = M2C_FIELD(arg1, s32 *, 0x2D8);
            M2C_FIELD(arg1, s16 *, 0x38C) = 0;
            tempV0_4 = tempV1_2 + tempV0_4;
            M2C_FIELD(arg1, s32 *, 0x2D8) = tempV0_4;
            M2C_FIELD(arg1, s32 *, 0x2E4) = tempV0_4;
        } else {
            tempA0_2 = M2C_FIELD(arg1, void **, 0x580);
            M2C_FIELD(tempA0_2, u16 *, 0xE) = M2C_FIELD(tempA0_2, u16 *, 0xE) - (u16)M2C_FIELD(D_8008D2AC, s32 *, 0x1D04);
        }

        M2C_FIELD(M2C_FIELD(arg1, void **, 0x580), s16 *, 0x10) = M2C_FIELD(arg1, s32 *, 0x2DC) >> 8;

        tempA0_3 = M2C_FIELD(arg1, void **, 0x580);
        tempV1_2 = M2C_FIELD(arg1, s32 *, 0x2D8) >> 8;
        if (M2C_FIELD(tempA0_3, s16 *, 0xE) < tempV1_2) {
            M2C_FIELD(tempA0_3, u16 *, 0xE) = tempV1_2;
            M2C_FIELD(arg1, u8 *, 0x58E) = 1U;
        }

        M2C_FIELD(M2C_FIELD(arg1, void **, 0x580), s16 *, 0xC) = M2C_FIELD(arg1, s32 *, 0x2D4) >> 8;

        tempA0 = M2C_FIELD(arg1, s16 *, 0x400);
        if (tempA0 >= 0x2D1) {
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x580), s16 *, 0x12) = ((0x3C0 - tempA0) << 0xC) / 240;
            return;
        }

        M2C_FIELD(M2C_FIELD(arg1, void **, 0x580), s16 *, 0x12) = 0x1000;
    }
}