typedef short s16;
typedef int s32;

typedef struct {
	s16 unk0;
	s16 unk2;
	s16 unk4;
} M2cMATHVectorNormalizeArg0;

s32 MATH_VectorLength();                            /* extern */

s32 MATH_VectorNormalize(M2cMATHVectorNormalizeArg0 *arg0) {
    s32 temp_v0;

    temp_v0 = MATH_VectorLength();
    if (temp_v0 != 0) {
        arg0->unk0 = (s16) ((s32) (arg0->unk0 << 0xC) / temp_v0);
        arg0->unk2 = (s16) ((s32) (arg0->unk2 << 0xC) / temp_v0);
        arg0->unk4 = (s16) ((s32) (arg0->unk4 << 0xC) / temp_v0);
    }
    return temp_v0;
}