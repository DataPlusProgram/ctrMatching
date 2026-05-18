typedef signed char s8;
typedef int s32;

typedef struct {
	char pad0[0x4];
	s32 unk4;
	s32 unk8;
} M2cLevelSoundLoopFadeArg0;

void Level_SoundLoopSet();

void Level_SoundLoopFade(M2cLevelSoundLoopFadeArg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
	if (arg0->unk8 != arg2) {
		arg0->unk4 = arg2;

		if (arg0->unk8 < arg2) {
			arg0->unk8 = arg0->unk8 + arg3;

			if (arg2 < arg0->unk8) {
				arg0->unk8 = arg2;
			}
		} else if (arg2 < arg0->unk8) {
			arg0->unk8 = arg0->unk8 - arg3;

			if (arg0->unk8 < arg2) {
				arg0->unk8 = arg2;
			}
		}

		Level_SoundLoopSet(((s8 *)arg0) + 0xC, arg1, arg0->unk8);
	}
}