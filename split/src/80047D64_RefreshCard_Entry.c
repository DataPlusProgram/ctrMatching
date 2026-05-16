typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK RefreshCard_Unknown3();                     /* extern */
M2C_UNK RefreshCard_Unknown4();                     /* extern */
extern s32 *D_8008D2AC;

void RefreshCard_Entry(void) {
    if (!(*D_8008D2AC & 0x10)) {
        RefreshCard_Unknown4();
        RefreshCard_Unknown3();
    }
}