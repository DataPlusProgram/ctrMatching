typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK _SpuInit();                          /* extern */

void SpuInit(void) {
    _SpuInit(0);
}