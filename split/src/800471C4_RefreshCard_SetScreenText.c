typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK RefreshCard_Unknown1();                     /* extern */
s16 D_8008D48E;

void RefreshCard_SetScreenText(s16 arg0) {
    D_8008D48E = arg0;
    RefreshCard_Unknown1();
}