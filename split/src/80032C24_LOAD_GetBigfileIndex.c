#include "../../common.h"

extern u8 D_8008D0B3[];

s32 LOAD_GetBigfileIndex(u32 levelId, s32 lodIndex, s32 bigfileIndexBase)
{
    u32 tempA3;
    u32 tempV1;
    u32 tempV1_2;
    u32 tempV1_3;

    tempA3 = levelId - 0x12;
    if ((u32)levelId < 0x12) {
        return (levelId * 8) + D_8008D0B3[lodIndex] + bigfileIndexBase;
    }

    tempV1_3 = levelId - 0x1E;
    if (tempA3 < 7) {
        return (tempA3 * 8) + D_8008D0B3[lodIndex] + bigfileIndexBase + 0x90;
    }

    if (tempV1_3 < 9) {
        return (tempV1_3 * 3) + bigfileIndexBase + 0x203;
    }

    tempV1_2 = levelId - 0x2A;
    if (tempV1_2 < 2) {
        return (tempV1_2 * 2) + bigfileIndexBase + 0x21E;
    }

    if (levelId == ADVENTURE_GARAGE) {
        return bigfileIndexBase + 0xD9;
    }

    tempV1 = levelId - 0x2C;
    if (levelId == NAUGHTY_DOG_CRATE) {
        return bigfileIndexBase + 0x201;
    }

    if (tempV1 < 0x14) {
        return (tempV1 * 3) + bigfileIndexBase + 0x222;
    }

    if (levelId == MAIN_MENU_LEVEL) {
        return bigfileIndexBase + 0xD7;
    }

    if (levelId == SCRAPBOOK) {
        return bigfileIndexBase + 0x25E;
    }

    return ((levelId - 0x19) * 3) + bigfileIndexBase + 0xC8;
}
