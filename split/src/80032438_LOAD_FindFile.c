typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK CDSYS_SetMode_StreamData();                 /* extern */
s32 CdSearchFile();                         /* extern */
M2C_UNK LOAD_StringToUpper();                    /* extern */

s32 LOAD_FindFile(s32 arg0, s32 arg1) {
    if ((arg0 == 0) || (arg1 == 0)) {
        return 0;
    }
    CDSYS_SetMode_StreamData();
    LOAD_StringToUpper(arg0);
    return CdSearchFile(arg1, arg0) != 0;
}