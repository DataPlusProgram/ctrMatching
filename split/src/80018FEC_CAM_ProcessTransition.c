typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cCAMProcessTransitionArg0;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cCAMProcessTransitionArg1;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cCAMProcessTransitionArg2;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cCAMProcessTransitionArg3;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cCAMProcessTransitionArg4;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cCAMProcessTransitionArg5;

void CAM_ProcessTransition(
    M2cCAMProcessTransitionArg0 *arg0,
    M2cCAMProcessTransitionArg1 *arg1,
    M2cCAMProcessTransitionArg2 *arg2,
    M2cCAMProcessTransitionArg3 *arg3,
    M2cCAMProcessTransitionArg4 *arg4,
    M2cCAMProcessTransitionArg5 *arg5,
    s32 arg6
) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_lo;
    s32 var_lo_2;
    s32 var_lo_3;

    arg0->unk0 = (s16) ((u16) arg2->unk0 + (((arg4->unk0 - arg2->unk0) * arg6) >> 0xC));
    arg0->unk2 = (s16) ((u16) arg2->unk2 + (((arg4->unk2 - arg2->unk2) * arg6) >> 0xC));
    arg0->unk4 = (s16) ((u16) arg2->unk4 + (((arg4->unk4 - arg2->unk4) * arg6) >> 0xC));

    temp_v1 = (arg5->unk0 - arg3->unk0) & 0xFFF;
    var_lo = temp_v1 * arg6;
    if (temp_v1 >= 0x800) {
        temp_v1 -= 0x1000;
        var_lo = temp_v1 * arg6;
    }
    arg1->unk0 = (s16) (((u16) arg3->unk0 + (var_lo >> 0xC)) & 0xFFF);

    temp_v1_2 = (arg5->unk2 - arg3->unk2) & 0xFFF;
    var_lo_2 = temp_v1_2 * arg6;
    if (temp_v1_2 >= 0x800) {
        temp_v1_2 -= 0x1000;
        var_lo_2 = temp_v1_2 * arg6;
    }
    arg1->unk2 = (s16) (((u16) arg3->unk2 + (var_lo_2 >> 0xC)) & 0xFFF);

    temp_v1_3 = (arg5->unk4 - arg3->unk4) & 0xFFF;
    var_lo_3 = temp_v1_3 * arg6;
    if (temp_v1_3 >= 0x800) {
        temp_v1_3 -= 0x1000;
        var_lo_3 = temp_v1_3 * arg6;
    }
    arg1->unk4 = (s16) (((u16) arg3->unk4 + (var_lo_3 >> 0xC)) & 0xFFF);
}