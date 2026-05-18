typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK LIST_AddFront();     /* extern */
M2C_UNK LIST_RemoveMember(); /* extern */

s32 JitPool_Add(s32 *arg0) {
	s32 tempS0;

	tempS0 = *arg0;

	if (tempS0 != 0) {
		LIST_RemoveMember(arg0, tempS0);
		LIST_AddFront((s8 *)arg0 + 0xC, tempS0);
		return tempS0;
	}

	return 0;
}