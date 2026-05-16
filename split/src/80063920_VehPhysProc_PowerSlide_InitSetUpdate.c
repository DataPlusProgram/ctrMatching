typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern M2C_UNK VehPhysProc_PowerSlide_Update;

void VehPhysProc_PowerSlide_InitSetUpdate(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x54) = 0;
    M2C_FIELD(arg1, M2C_UNK **, 0x58) = &VehPhysProc_PowerSlide_Update;
}