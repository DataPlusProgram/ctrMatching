typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

extern s8 D_80087F94[];

void *VehAfterColl_GetSurface(u32 arg0) {
    s32 var_v1;

    if (arg0 < 7U) {
        goto valid;
    }

    arg0 = 0;

valid:
    var_v1 = arg0 << 4;
    return D_80087F94 + var_v1;
}