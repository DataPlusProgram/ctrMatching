#include "../../common.h"

s32 MainDB_GetClipSize(s32 arg0, s32 arg1)
{
    switch (arg0) {
    case 40:
        return 24000;

    case 39:
        return 16;

    case 8:
        return 6000;

    case 9:
        return 2500;

    case 5:
    case 12:
        if (arg1 >= 3) {
            return 2500;
        }
        break;
    }

    return 3000;
}