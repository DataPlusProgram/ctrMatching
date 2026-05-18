#include "../../common.h"

s32 MainDB_GetClipSize(s32 arg0, s32 arg1) {
	switch (arg0) {
	case 5:
		return 24000;

	case 6:
		return 16;

	case 7:
		return 6000;

	case 8:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 31:
	case 32:
	case 33:
	case 34:
	case 35:
	case 36:
	case 37:
	case 38:
	case 39:
	case 40:
	default:
		return 2500;

	case 9:
		if (arg1 >= 3) {
			return 2500;
		}
		return 3000;
	}
}