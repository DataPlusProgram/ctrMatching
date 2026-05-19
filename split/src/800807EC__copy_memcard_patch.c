typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

extern M2C_UNK InitCARD2;
extern M2C_UNK InitCARD2_Unknown_800806C0;

void _copy_memcard_patch(void) {
    s8 *varT2;
    s8 *varV0;

    varV0 = (s8 *)0xDF80;
    varT2 = (s8 *)&InitCARD2 + 0x10;

    do {
        *(s32 *)varV0 = *(s32 *)varT2;
        varT2 += 4;
        varV0 += 4;
    } while (varT2 != (s8 *)&InitCARD2_Unknown_800806C0);
}