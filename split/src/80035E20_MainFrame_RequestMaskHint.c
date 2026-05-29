typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK VehPhysProc_FreezeEndEvent_Init;
s16 boolDraw3D_AdvMask;
M2C_UNK posY_MultiLine;
void *s_OTMem;

void MainFrame_RequestMaskHint(s16 arg0, s16 arg1) {
    if (!(M2C_FIELD(s_OTMem, s32 *, 0) & 0xF) && (M2C_FIELD(&posY_MultiLine, s16 *, 0) == -1)) {
        boolDraw3D_AdvMask = 1;
        M2C_FIELD(&posY_MultiLine, s16 *, 0) = arg0;
        M2C_FIELD(&posY_MultiLine, s16 *, 2) = arg1;
        M2C_FIELD(M2C_FIELD(s_OTMem, void **, 0x24EC), M2C_UNK **, 0x54) = &VehPhysProc_FreezeEndEvent_Init;
    }
}