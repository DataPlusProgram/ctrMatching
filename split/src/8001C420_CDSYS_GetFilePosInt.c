typedef int s32;

typedef s32 M2C_UNK;

s32 CdPosToInt();                     /* extern */
s32 CdSearchFile();                   /* extern */

s32 CDSYS_GetFilePosInt(s32 arg0, s32 *arg1) {
    M2C_UNK sp10[5];

    if (CdSearchFile(sp10, arg0) == 0) {
        return 0;
    } else {
        *arg1 = CdPosToInt(sp10);
        return 1;
    }
}