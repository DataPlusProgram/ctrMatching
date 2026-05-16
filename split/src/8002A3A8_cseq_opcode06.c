#include "../../common.h"

typedef struct {
	char pad0[0x5];
	u8 unk5;
} M2cCseqOpcode06Arg0;

M2C_UNK cseq_opcode_from06and07();

void cseq_opcode06(M2cCseqOpcode06Arg0 *arg0) {
    arg0->unk5 = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), u8 *, 1);
    cseq_opcode_from06and07();
}