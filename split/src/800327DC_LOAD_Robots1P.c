typedef short s16;
typedef int s32;

extern s16 D_80086E84[];

void LOAD_Robots1P(s32 param_1) {
    s32 iVar2;
    s16 *puVar3;
    s32 iVar4;

    iVar4 = 1;
    D_80086E84[0] = param_1;
    iVar2 = 0;
    puVar3 = &D_80086E84[1];

    do {
        if (iVar4 >= 8) {
            return;
        }

        if (iVar2 != param_1) {
            *puVar3 = iVar2;
            puVar3 = puVar3 + 1;
            iVar4 = iVar4 + 1;
        }

        iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
}