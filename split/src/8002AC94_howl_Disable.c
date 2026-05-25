typedef unsigned char u8;
typedef int s32;

u8 DAT_8008d05c;

s32 FUN_8002ac94(void) {
    s32 ret;

    ret = 1;
    if (DAT_8008d05c == 0) {
        return 0;
    }

    DAT_8008d05c = 0;
    return ret;
}