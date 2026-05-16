typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

typedef struct {
    char pad0[0x4C];
    s8 unk4C;
    s8 unk4D;
    char pad4E[0x3B2];
    s16 unk400;
} M2cVehStuckProcTumbleUpdateArg1;

M2C_UNK VehPhysProc_Driving_Init(); /* extern */

void VehStuckProc_Tumble_Update(s32 arg0, M2cVehStuckProcTumbleUpdateArg1 *arg1) {
    if (arg1->unk400 == 0) {
        arg1->unk4C = 0;
        arg1->unk4D = 0;
        VehPhysProc_Driving_Init();
    }
}