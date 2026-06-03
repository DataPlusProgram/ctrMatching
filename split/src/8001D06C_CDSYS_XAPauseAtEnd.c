typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK CDSYS_XAPauseForce();                       /* extern */
s32 ptrArray_numSongs;

void CDSYS_XAPauseAtEnd(void) {
    if (ptrArray_numSongs != 0) {
        CDSYS_XAPauseForce();
    }
}