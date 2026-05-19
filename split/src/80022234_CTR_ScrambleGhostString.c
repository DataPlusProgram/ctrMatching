typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u16 D_80081DFC[];

void CTR_ScrambleGhostString(s8 *arg0, u8 *arg1) {
    register u16 *varA2 asm("$6");
    s32 varA3;
    u16 tempV1;
    u16 varV1;
    u16 firstSentinel;
    u16 loopSentinel;
    u8 tempV0;

    tempV0 = *arg1;
    if (tempV0 != 0) {
        do {
            varA3 = 0;
            if (tempV0 < 4U) {
                tempV0 = *arg1;
                arg1++;
                varA3 = tempV0 << 8;
            }

            tempV0 = *arg1;
            arg1++;

            varA2 = D_80081DFC;
            varV1 = varA2[1];
            firstSentinel = 0xFFFF;

            if (varV1 != firstSentinel) {
                varA3 = (varA3 | tempV0) & 0xFFFF;
                loopSentinel = 0xFFFF;

loop_6:
                if ((varV1 == varA3) && (tempV1 = varA2[0], ((tempV1 & 0xFF00) != 0))) {
                    *arg0 = tempV1 >> 8;
                    arg0++;
                    *arg0 = tempV1;
                    arg0++;
                } else {
                    varA2 += 2;
                    varV1 = varA2[1];
                    if (varV1 != loopSentinel) {
                        goto loop_6;
                    }
                }
            }

            tempV0 = *arg1;
        } while (tempV0 != 0);
    }

    *arg0 = 0;
}