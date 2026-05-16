typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK INSTANCE_Birth(); /* extern */
s32 JitPool_Add();                               /* extern */
extern s32 D_8008D2AC;

s32 INSTANCE_Birth3D(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_v0;

    temp_v0 = JitPool_Add(D_8008D2AC + 0x18F8);
    if (temp_v0 != 0) {
        INSTANCE_Birth(temp_v0, arg0, arg1, arg2, 0xF);
    }
    return temp_v0;
}