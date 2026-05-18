typedef signed char s8;

typedef struct {
	char pad0[0x24];
	s8 unk24;
	char pad25[0x11];
	s8 unk36;
	s8 unk37;
} M2cUnknown8007DE58Arg0;

void _Unknown_8007DE58(M2cUnknown8007DE58Arg0 *arg0, s8 arg1) {
	arg0->unk37 = 0x46;
	*(void **)((s8 *)arg0 + 0x2C) = &arg0->unk24;
	arg0->unk24 = arg1;
	arg0->unk36 = 1;
}