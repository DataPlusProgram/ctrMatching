typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK VehStuckProc_PlantEaten_Init(); /* extern */

void VehStuckProc_RIP_Init(M2C_UNK arg0, void *arg1) {
    VehStuckProc_PlantEaten_Init();
    M2C_FIELD(arg1, s32 *, 0x58) = 0;
    M2C_FIELD(arg1, s32 *, 0x80) = 0;
    M2C_FIELD(arg1, s32 *, 0x28) = 0;
}