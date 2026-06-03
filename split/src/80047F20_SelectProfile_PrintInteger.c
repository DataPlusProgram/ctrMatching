typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK DecalFont_DrawLine(); /* extern */
M2C_UNK sprintf();            /* extern */
extern M2C_UNK D_8008D48C;
extern M2C_UNK stringFormat1;

void SelectProfile_PrintInteger(s32 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4)
{
    char sp18[0x40];
    u16 s0_arg4;

    s0_arg4 = arg4;

    if (arg3 == 1)
    {
        sprintf(sp18, &stringFormat1, arg0, arg3);
    }
    else
    {
        sprintf(sp18, &D_8008D48C, arg0, arg3);
    }

    DecalFont_DrawLine(sp18, arg1, arg2, 1, (s32)(s16)s0_arg4);
}