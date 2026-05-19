typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK InterruptCallback();            /* extern */

void _SpuCallback(s32 arg0) {
    InterruptCallback(9, arg0);
}