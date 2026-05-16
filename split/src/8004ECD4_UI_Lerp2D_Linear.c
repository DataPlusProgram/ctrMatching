typedef short s16;
typedef int s32;

typedef struct {
    s16 unk0;
    s16 unk2;
} M2cUILerp2DLinearArg0;

void UI_Lerp2D_Linear(M2cUILerp2DLinearArg0 *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s16 arg6) {
    if (arg6 >= arg5) {
        arg0->unk0 = arg1 + ((arg5 * (arg3 - arg1)) / arg6);
        arg0->unk2 = arg2 + ((arg5 * ((s16) arg4 - arg2)) / arg6);
        return;
    }

    arg0->unk0 = arg3;
    arg0->unk2 = arg4;
}