typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

typedef struct {
    char pad0[0x46];
    u8 unk46;
    char pad47[0xC];
    u8 unk53;
} M2cPadSetMainModeUnknown80075B34Arg0;

extern M2C_UNK (*D_8008C770)();

s32 PadSetMainMode_Unknown_80075B34(M2cPadSetMainModeUnknown80075B34Arg0 *arg0) {
    if (arg0->unk53 != 0) {
        if (arg0->unk46 == 2) {
            return 1;
        }

        arg0->unk46 = 0xFEU;
        return 0;
    }

    D_8008C770();
    return 0;
}