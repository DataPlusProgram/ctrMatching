typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK Bank_Destroy();                       /* extern */
extern M2C_UNK bank;
u8 ptrLastBank;

s32 Bank_DestroyLast(void) {
    u8 temp_v0;

    if (ptrLastBank == 0) {
        return 0;
    }
    temp_v0 = ptrLastBank - 1;
    ptrLastBank = temp_v0;
    Bank_Destroy(((temp_v0 & 0xFF) * 8) + &bank);
    return 1;
}