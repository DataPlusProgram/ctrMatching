typedef short s16;
typedef int s32;

s16 DrawSolidBoxData;

void RaceFlag_SetDrawOrder(s32 arg0) {
    if (arg0 != 0) {
        DrawSolidBoxData = 1;
        return;
    }
    DrawSolidBoxData = -1;
}