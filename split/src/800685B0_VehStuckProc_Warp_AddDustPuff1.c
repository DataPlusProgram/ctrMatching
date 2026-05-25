typedef signed char s8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cVehStuckProcWarpAddDustPuff1Arg0;

void *Particle_Init(s32 arg0, s32 arg1, void *arg2);       /* extern */

extern M2C_UNK emSet_Warppad;
extern void *gGamepads;

void VehStuckProc_Warp_AddDustPuff1(M2cVehStuckProcWarpAddDustPuff1Arg0 *arg0) {
    void *tempV0;
    void *tempV1;

    tempV1 = gGamepads;

    if (!(M2C_FIELD(tempV1, s32 *, 0x1CEC) & 1)) {
        tempV0 = Particle_Init(0, M2C_FIELD(tempV1, s32 *, 0x2118), &emSet_Warppad);

        if (tempV0 != NULL) {
            M2C_FIELD(tempV0, s32 *, 0x24) += arg0->unk0 << 8;
            M2C_FIELD(tempV0, s32 *, 0x2C) += arg0->unk2 << 8;
            M2C_FIELD(tempV0, s32 *, 0x34) += arg0->unk4 << 8;
        }
    }
}