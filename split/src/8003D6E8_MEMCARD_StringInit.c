typedef signed char s8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern M2C_UNK D_8008D414;

M2C_UNK *MEMCARD_StringInit(s32 arg0, M2C_UNK *arg1) {
	M2C_UNK *varA1;
	s32 upperPart;
	s32 lowerPart;

	varA1 = arg1;

	if (varA1 == NULL) {
		varA1 = &D_8008D414;
	}

	upperPart = (((arg0 >> 4) & 1) + 0x30) << 0x10;
	lowerPart = (((arg0 & 3) + 0x30) << 0x18) | 0x7562;

	M2C_FIELD(varA1, s32 *, 0) = upperPart | lowerPart;
	M2C_FIELD(varA1, s16 *, 4) = 0x3A;

	return varA1;
}