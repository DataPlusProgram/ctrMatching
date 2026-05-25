typedef int s32;

extern s32 D_8009EC0C;
extern s32 D_8009EC10;
extern s32 D_8009EC38;

void StSetMask(s32 arg0, s32 arg1, s32 arg2) {
    D_8009EC10 = arg0;
    D_8009EC38 = arg1;
    D_8009EC0C = arg2;
}