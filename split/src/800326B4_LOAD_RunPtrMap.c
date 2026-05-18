typedef int s32;
typedef unsigned int u32;

void LOAD_RunPtrMap(s32 arg0, s32 *arg1, s32 arg2) {
	s32 *tempV0;
	s32 tempV1;
	s32 *end;
	s32 offset;

	end = arg1 + arg2;

	if (arg1 < end) {
		do {
			offset = (*arg1 >> 2) << 2;
			tempV0 = (s32 *)(offset + arg0);
			tempV1 = *tempV0;
			arg1++;
			*tempV0 = tempV1 + arg0;
		} while (arg1 < end);
	}
}