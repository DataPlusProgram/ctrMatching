typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK JitPool_Clear();      /* extern */
s32 MEMPACK_AllocMem();      /* extern */
M2C_UNK memset();            /* extern */

void JitPool_Init(void *arg0, s32 arg1, s32 arg2, M2C_UNK arg3) {
	s32 tempLo;

	memset(arg0, 0, 0x28);

	tempLo = arg1 * arg2;
	M2C_FIELD(arg0, s32 *, 0x18) = arg1;
	M2C_FIELD(arg0, s32 *, 0x1C) = arg2;
	M2C_FIELD(arg0, s32 *, 0x20) = tempLo;
	M2C_FIELD(arg0, s32 *, 0x24) = MEMPACK_AllocMem(tempLo, arg3);

	JitPool_Clear(arg0);
}