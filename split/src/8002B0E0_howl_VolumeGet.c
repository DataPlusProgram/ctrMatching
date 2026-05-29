typedef unsigned char u8;
typedef int s32;

u8 D_8008D7CC;
u8 howl_metaEngineFX;
u8 ptrHowlHeader;

u8 howl_VolumeGet(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return ptrHowlHeader;
    case 1:
        return D_8008D7CC;
    case 2:
        return howl_metaEngineFX;
    default:
        return 0U;
    }
}