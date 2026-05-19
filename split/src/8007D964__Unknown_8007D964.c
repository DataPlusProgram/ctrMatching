typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

typedef struct {
    char pad0[0x46];
    u8 unk46;
    u8 unk47;
    u8 unk48;
} M2cUnknown8007D964Arg0;

M2C_UNK _Unknown_8007DE38(M2cUnknown8007D964Arg0 *arg0, u8 arg1); /* extern */
M2C_UNK _Unknown_8007DE58(M2cUnknown8007D964Arg0 *arg0, u8 arg1); /* extern */
M2C_UNK _Unknown_8007DE78(M2cUnknown8007D964Arg0 *arg0, u8 arg1); /* extern */
M2C_UNK _Unknown_8007DE98();                                      /* extern */

void _Unknown_8007D964(M2cUnknown8007D964Arg0 *arg0) {
    u8 tempV1;

    tempV1 = arg0->unk46;

    switch (tempV1) {
    case 2:
        _Unknown_8007DE38(arg0, arg0->unk47);
        return;

    case 3:
        _Unknown_8007DE58(arg0, arg0->unk47);
        return;

    case 4:
        if (arg0->unk48 == 0) {
            _Unknown_8007DE78(arg0, arg0->unk47);
            return;
        }

        _Unknown_8007DE98();
        return;
    }
}