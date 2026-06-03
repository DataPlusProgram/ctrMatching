typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK StClearRing();                              /* extern */
extern s32 D_8009EC24;
extern s32 D_8009EC34;

void StSetRing(s32 arg0, s32 arg1) {
    D_8009EC24 = arg0;
    D_8009EC34 = arg1;
    StClearRing();
}