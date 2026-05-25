typedef int s32;

typedef s32 M2C_UNK;

typedef struct {
    char pad0[0x20];
    s32 unk20;
} M2cPadSetActAlignUnknown8007594CArg0;

M2C_UNK PadSetCmd(); /* extern */

void PadSetActAlign_Unknown_8007594C(M2cPadSetActAlignUnknown8007594CArg0 *arg0) {
    PadSetCmd(arg0, 0x4D, arg0->unk20, 6);
}