typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK OtherFX_Modify();      /* extern */
s32 OtherFX_Play_LowLevel();   /* extern */
M2C_UNK OtherFX_Stop1();       /* extern */
s32 VehCalc_MapToRange();      /* extern */
extern void *D_8008D2AC;

void CalculateVolumeFromDistance(s32 *arg0, s32 arg1, s32 arg2) {
	s32 *tempS1;
	s32 tempS2;
	s32 tempS0;
	s32 tempA0;
	s32 tempA1;
	s32 tempV0;
	s32 volume;

	tempS1 = arg0;
	tempS2 = arg1;
	tempS0 = arg2;

	if (tempS0 >= 0x1770) {
		tempA0 = *tempS1;
		if (tempA0 != 0) {
			OtherFX_Stop1(tempA0);
			*tempS1 = 0;
		}
		return;
	}

	tempA0 = *tempS1;
	if (tempA0 != 0) {
		if ((tempA0 & 0xFFFF) != tempS2) {
			OtherFX_Stop1(tempA0);
			*tempS1 = 0;
		}
	}

	if (tempS0 < 0x12D) {
		goto fullVolume;
	}

	volume = VehCalc_MapToRange(tempS0, 0x12C, 0x1770, 0xFF, 0);
	goto afterVolume;

fullVolume:
	volume = 0xFF;

afterVolume:
	if (tempS2 == -1) {
		return;
	}

	tempA0 = *tempS1;
	if (tempA0 == 0) {
		*tempS1 = OtherFX_Play_LowLevel(tempS2 & 0xFFFF, 0, ((volume & 0xFF) << 0x10) | 0x8080);
		return;
	}

	if (tempS2 == 0x89) {
		tempA1 = volume & 0xFF;
		tempA1 <<= 0x10;

		tempV0 = M2C_FIELD(D_8008D2AC, s32 *, 0x1CE4);
		tempV0 = ((u32)tempV0 >> 2) & 0x7F;
		tempV0 -= 0x40;

		if (tempV0 < 0) {
			tempV0 = -tempV0;
		}

		tempV0 += 0x64;
		tempV0 &= 0xFF;
		tempV0 <<= 8;
		tempA1 |= tempV0;
		tempA1 |= 0x80;
	} else {
		tempA1 = volume & 0xFF;
		tempA1 <<= 0x10;
		tempA1 |= 0x8080;
	}

	OtherFX_Modify(tempA0, tempA1, volume);
}