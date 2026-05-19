typedef unsigned short u16;
typedef int s32;

extern u16 *D_8008C028;

s32 StopCallback_Unknown_800772C8(u16 arg0) {
    s32 tempV0;

    tempV0 = *D_8008C028;
    *D_8008C028 = arg0;
    return tempV0;
}