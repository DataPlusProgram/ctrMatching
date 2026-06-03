#include "../../common.h"

void SetTransMatrix(MatrixNd *m)
{
    register s32 tempT0 asm("$8") = m->t[0];
    register s32 tempT1 asm("$9") = m->t[1];
    register s32 tempT2 asm("$10") = m->t[2];

    gte_ldtr(tempT0, tempT1, tempT2);
}