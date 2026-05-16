typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	char pad0[0x9];
	u8 unk9;
} M2cCseqOpcode07Arg0;

M2C_UNK cseq_opcode_from06and07();                  /* extern */

void cseq_opcode07(M2cCseqOpcode07Arg0 *arg0) {
    arg0->unk9 = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), u8 *, 1);
    cseq_opcode_from06and07();
}