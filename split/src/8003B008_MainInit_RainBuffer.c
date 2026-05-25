#include "../../common.h"

void MainInit_RainBuffer(GameTracker *gGT)
{
    s32 i;
    s8 *currGt;
    s32 *dst;
    s32 *src;
    s32 *end;
    s32 temp0;
    s32 temp1;
    s32 temp2;
    s32 temp3;
    u16 tempV1;

    if (gGT->numPlyrCurrGame != 0)
    {
        i = 0;
        currGt = (s8 *)gGT;

        do
        {
            src = (s32 *)((s8 *)gGT->level1 + 0x104);
            dst = (s32 *)(currGt + 0x1A40);
            end = (s32 *)((s8 *)gGT->level1 + 0x134);

            do
            {
                temp0 = src[0];
                temp1 = src[1];
				temp3 = src[3];
                temp2 = src[2];
                

                dst[0] = temp0;
                dst[1] = temp1;
                dst[2] = temp2;
                dst[3] = temp3;

                src += 4;
                dst += 4;
            } while (src != end);

            M2C_FIELD(currGt, s32 *, 0x1A40) =
                M2C_FIELD(currGt, s32 *, 0x1A40) / gGT->numPlyrCurrGame;

            tempV1 = M2C_FIELD(currGt, u16 *, 0x1A44);

            M2C_FIELD(currGt, u16 *, 0x1A44) = tempV1 / gGT->numPlyrCurrGame;

            i++;
            currGt += 0x30;
        } while (i < gGT->numPlyrCurrGame);
    }
}