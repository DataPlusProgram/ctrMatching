typedef signed char s8;
typedef short s16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s32 MixRNG_Scramble(void); /* extern */

void Particle_FuncPtr_PotionShatter(void *arg0) {
	s32 tempRet;
	s32 tempRet2;
	s32 rngValue;
	s32 divValue;
	s32 fadeValue;

	if (M2C_FIELD(arg0, s16 *, 0x30) < 0x578) {
		if (M2C_FIELD(arg0, s16 *, 0x28) == 0) {
			tempRet = MixRNG_Scramble();
			M2C_FIELD(arg0, s16 *, 0x28) = (s16)((tempRet % 800) - 0x190);

			tempRet2 = MixRNG_Scramble();
			M2C_FIELD(arg0, s16 *, 0x38) = (s16)((tempRet2 % 800) - 0x190);

			rngValue = MixRNG_Scramble();
			divValue = rngValue >> 8;

			if (rngValue < 0) {
				divValue = (rngValue + 0xFF) >> 8;
			}

			M2C_FIELD(arg0, s16 *, 0x50) = (s16)((rngValue - (divValue << 8)) + 0x100);
		}
	}

	if (M2C_FIELD(arg0, s16 *, 0x28) != 0) {
		if (M2C_FIELD(arg0, s32 *, 0x20) == 0x45) {
			fadeValue = M2C_FIELD(arg0, s32 *, 0x64);

			if (fadeValue > 0) {
				M2C_FIELD(arg0, s32 *, 0x64) = fadeValue - 0x1200;
			}
		} else {
			fadeValue = M2C_FIELD(arg0, s32 *, 0x5C);

			if (fadeValue > 0) {
				M2C_FIELD(arg0, s32 *, 0x5C) = fadeValue - 0x1200;
			}
		}
	}
}