typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

typedef struct {
    char pad0[0x46];
    u8 unk46;
    u8 unk47;
    char pad48[0x9C];
    u8 unkE4;
} M2cPadSendAtLoadInfoArg0;

M2C_UNK _Unknown_8007DE24();        /* extern */
M2C_UNK _Unknown_8007DE38();        /* extern */
M2C_UNK _Unknown_8007DE78();        /* extern */

void _padSendAtLoadInfo(M2cPadSendAtLoadInfoArg0 *arg0) {
    u8 temp_v1;

    temp_v1 = arg0->unk46;
    switch (temp_v1) {
    case 2:
        _Unknown_8007DE24();
        return;
    case 3:
        _Unknown_8007DE38(arg0, arg0->unkE4);
        return;
    case 4:
        _Unknown_8007DE78(arg0, arg0->unk47);
        return;
    }
}