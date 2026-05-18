typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	char pad0[0x90];
	s16 unk5A;
	char pad92[0x12];
	s16 unk4;
	u16 unk6;
	s16 unk8;
} M2cCAMFollowDriverSpin360Arg0;

typedef struct {
	s16 unk0;
	s16 unk2;
	s16 unk4;
} M2cCAMFollowDriverSpin360Arg3;

void CAM_LookAtPosition();
s32 MATH_Cos();
s32 MATH_Sin();

void CAM_FollowDriver_Spin360(
	M2cCAMFollowDriverSpin360Arg0 *arg0,
	M2C_UNK arg1,
	void *arg2,
	M2cCAMFollowDriverSpin360Arg3 *arg3,
	s32 arg4
) {
	s32 tempV1;
	s32 varV0;

	tempV1 = arg0->unk5A;

	if (M2C_FIELD(arg2, u8 *, 0x4A) & 1) {
		varV0 = tempV1 - arg0->unk4;
	} else {
		varV0 = tempV1 + arg0->unk4;
	}

	arg0->unk5A = varV0;

	arg3->unk2 = (s16)(arg0->unk6 + (M2C_FIELD(arg2, s32 *, 0x2D8) >> 8));
	arg3->unk0 = (s16)((M2C_FIELD(arg2, s32 *, 0x2D4) >> 8) + ((MATH_Sin(arg0->unk5A) * arg0->unk8) >> 0xC));
	arg3->unk4 = (s16)((M2C_FIELD(arg2, s32 *, 0x2DC) >> 8) + ((MATH_Cos(arg0->unk5A) * arg0->unk8) >> 0xC));

	CAM_LookAtPosition(arg1, (s8 *)arg2 + 0x2D4, arg3, arg4);
}