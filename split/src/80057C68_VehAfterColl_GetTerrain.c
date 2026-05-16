typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

extern s8 D_800884CC[];

void *VehAfterColl_GetTerrain(u32 arg0) {
    s32 var_v1;

    if (arg0 < 0x15U) {
        goto valid;
    }

    arg0 = 0;

valid:
    var_v1 = arg0 << 6;
    return D_800884CC + var_v1;
}