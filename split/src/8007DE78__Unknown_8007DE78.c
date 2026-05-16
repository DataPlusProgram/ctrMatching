typedef signed char s8;

typedef struct {
    char pad0[0x24];
    s8 unk24;
    char pad25[0x7];
    void *unk2C;
    char pad30[0x6];
    s8 unk36;
    s8 unk37;
} M2cUnknown8007DE78Arg0;

void _Unknown_8007DE78(M2cUnknown8007DE78Arg0 *arg0, s8 arg1) {
    arg0->unk37 = 0x47;
    arg0->unk2C = (void *)((s8 *)arg0 + 0x24);
    arg0->unk24 = arg1;
    arg0->unk36 = 1;
}