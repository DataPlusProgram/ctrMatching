#include "../../common.h"

__asm__(
".set noreorder\n"
".globl SetRotMatrixRegs\n"
"SetRotMatrixRegs:\n"
"    ctc2 $t3, $0\n"
"    ctc2 $t4, $1\n"
"    ctc2 $t5, $2\n"
"    ctc2 $t6, $3\n"
"    jr $ra\n"
"     ctc2 $t7, $4\n"
".set reorder\n"
);
