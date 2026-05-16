typedef signed char s8;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x24];
    s8 unk18;
    char pad25[0x11];
    s8 unk24;
    s8 unk25;
} M2cPadCmdParaModeArg0;

void _padCmdParaMode(M2cPadCmdParaModeArg0 *arg0, s8 arg1) {
    arg0->unk25 = 0x43;
    M2C_FIELD(arg0, void **, 0x2C) = (void *) &arg0->unk18;
    arg0->unk18 = arg1;
    arg0->unk24 = 1;
}