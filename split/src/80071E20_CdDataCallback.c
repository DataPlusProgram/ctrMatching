typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK DMACallback();                  /* extern */

void CdDataCallback(s32 arg0) {
    DMACallback(3, arg0);
}