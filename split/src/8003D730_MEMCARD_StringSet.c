typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK MEMCARD_StringInit(); /* extern */

void MEMCARD_StringSet(u8 *arg0, M2C_UNK arg1, u8 *arg2) {
	s32 varA0;
	u8 *varA2;
	u8 tempV0;

	MEMCARD_StringInit(arg1, arg0);

	varA0 = 0;
	if (*arg0 != 0) {
		do {
			varA0 += 1;
		} while (arg0[varA0] != 0);
	}

	if (*arg2 != 0) {
		varA2 = arg2;

loop6:
		if (varA0 < 0x3F) {
			tempV0 = *varA2;
			varA2 += 1;
			arg0[varA0] = tempV0;
			varA0 += 1;

			if (*varA2 != 0) {
				goto loop6;
			}
		}
	}

	arg0[varA0] = 0;
}