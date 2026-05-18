typedef unsigned char u8;
typedef short s16;
typedef int s32;

s32 UI_VsQuipReadDriver(void *arg0, s32 arg1, s32 arg2)
{
    if (arg2 == 2) {
        goto readShort;
    }

    if (arg2 >= 3) {
        goto checkWord;
    }

    if (arg2 == 1) {
        goto readByte;
    }

    goto returnZero;

checkWord:
    if (arg2 == 4) {
        goto readWord;
    }

    goto returnZero;

readByte:
    return *(u8 *)((char *)arg0 + arg1);

readShort:
    return *(s16 *)((char *)arg0 + arg1);

readWord:
{
    void *ptr = (char *)arg0 + arg1;
    return *(s32 *)ptr;
}

returnZero:
    return 0;
}