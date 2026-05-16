typedef signed char s8;
typedef unsigned char u8;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	char pad0[0x3];
	u8 unk3;
} M2cCseqOpcode09Arg0;

void cseq_opcode09(M2cCseqOpcode09Arg0 *arg0) {
    arg0->unk3 = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), u8 *, 1);
}