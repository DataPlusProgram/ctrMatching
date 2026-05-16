typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK DecDCToutCallback_Unknown_80079984();    /* extern */
M2C_UNK ResetCallback();                            /* extern */

void DecDCTReset(s32 arg0) {
    if (arg0 == 0) {
        ResetCallback();
    }
    DecDCToutCallback_Unknown_80079984(arg0);
}