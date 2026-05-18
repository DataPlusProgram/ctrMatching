typedef short s16;
typedef int s32;

typedef struct {
    s16 unk0;
    s16 unk2;
} M2cUILerp2DHUDArg0;

void UI_Lerp2D_HUD(M2cUILerp2DHUDArg0 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5, s16 arg6)
{
    s32 temp1;
    s32 temp2;

    temp2 = arg5 * ((s32) arg1 - (s32) arg3);
    temp1 = (s32) arg6;

    arg0->unk0 = arg3 + (s16) (temp2 / temp1);
    arg0->unk2 = arg4 + (s16) ((arg5 * ((s32) arg2 - (s32) arg4)) / temp1);
}