#include "../../common.h"

extern void SetRotMatrixRegs(void);
extern void TRIG_Unknown_8006C49C(void);

void MatrixRotate(void *output, void *baseMatrix, void *rotationData)
{
    u32 *outputWords;
    u32 *baseWords;
    u32 *rotationWords;
    register u32 t3Reg __asm__("t3");
    register u32 t4Reg __asm__("t4");
    register u32 t5Reg __asm__("t5");
    register u32 t6Reg __asm__("t6");
    register u32 t7Reg __asm__("t7");

    outputWords = (u32 *)output;
    baseWords = (u32 *)baseMatrix;
    rotationWords = (u32 *)rotationData;

    t3Reg = baseWords[0];
    t4Reg = baseWords[1];
    t5Reg = baseWords[2];
    t6Reg = baseWords[3];
    t7Reg = baseWords[4];
    SetRotMatrixRegs();

    t3Reg = rotationWords[0];
    t4Reg = rotationWords[1];
    t5Reg = rotationWords[2];
    t6Reg = rotationWords[3];
    t7Reg = rotationWords[4];
    TRIG_Unknown_8006C49C();

    outputWords[0] = t3Reg;
    outputWords[1] = t4Reg;
    outputWords[2] = t5Reg;
    outputWords[3] = t6Reg;
    outputWords[4] = t7Reg;
}
