typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

extern s8 D_80081088[];

M2C_UNK *COLL_LevModelMeta(u32 arg0) {
	s32 offset;

	if (arg0 >= 0xE2U) {
		return (M2C_UNK *)D_80081088;
	}

	offset = arg0 << 1;
	offset += arg0;
	offset <<= 2;

	return (M2C_UNK *)(D_80081088 + offset);
}