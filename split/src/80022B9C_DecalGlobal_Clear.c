typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK memset();              /* extern */

void DecalGlobal_Clear(s32 arg0) {
    memset(arg0 + 0x1EEC, 0, 0x220);
    memset(arg0 + 0x2114, 0, 0x44);
}