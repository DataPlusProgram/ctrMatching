typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

extern M2C_UNK D_800990E4;
void *D_8008D434; /* gp + 0x4B4 */

void MEMPACK_SwapPacks(s32 arg0) {
	s32 offset;

	offset = arg0 << 1;
	offset += arg0;
	offset <<= 5;

	D_8008D434 = (void *)(offset + (s32)&D_800990E4);
}