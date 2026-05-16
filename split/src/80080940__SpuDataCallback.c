typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK DMACallback();                  /* extern */

void _SpuDataCallback(s32 arg0) {
    DMACallback(4, arg0);
}