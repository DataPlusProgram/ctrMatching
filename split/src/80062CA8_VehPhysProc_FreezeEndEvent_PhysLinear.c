typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK VehPhysProc_Driving_PhysLinear();

void VehPhysProc_FreezeEndEvent_PhysLinear(void *arg0, void *arg1) {
    s32 tempV0;
    s32 tempA0;
    s32 *tempPtr;

    VehPhysProc_Driving_PhysLinear();

    tempV0 = *((s32 *)(((s8 *)arg1) + 0x2C8));
    tempPtr = (s32 *)(((s8 *)arg1) + 0x2C8);

    *((s16 *)(((s8 *)arg1) + 0x39C)) = 0;
    *((s16 *)(((s8 *)arg1) + 0x39E)) = 0;
    *((s16 *)(((s8 *)arg1) + 0xC0)) = 0;
    *((s8 *)(((s8 *)arg1) + 0x4B)) = 0;
    *((s16 *)(((s8 *)arg1) + 6)) = 0;

    tempV0 |= 8;
    *tempPtr = tempV0;

    tempA0 = *((s16 *)(((s8 *)arg1) + 0x3F0));
    tempV0 &= -5;
    *((s32 *)(((s8 *)arg1) + 0x2C8)) = tempV0;

    if (tempA0 > 0) {
        *((s16 *)(((s8 *)arg1) + 0x3F0)) = 0;
    }
}