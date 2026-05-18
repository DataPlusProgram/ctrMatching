typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	char pad0[0x8];
	u16 unk8;
	s16 unkA;
} EngineAudioAttr;

void *Channel_SearchFX_EditAttr();     /* extern */
M2C_UNK Channel_SetVolume();           /* extern */
M2C_UNK Smart_EnterCriticalSection();  /* extern */
M2C_UNK Smart_ExitCriticalSection();   /* extern */

extern M2C_UNK D_800825AC;
extern u8 D_8008D05C;
extern void *D_8008D2AC;
extern u8 D_8008D7AC;
extern void *D_8008D7C0;
extern s32 D_8008D7D0;

s32 EngineAudio_Recalculate(s32 arg0, u32 arg1) {
	EngineAudioAttr sp10;
	u32 tempA0;
	u32 tempV0;
	u32 tempV1;
	u32 tempT0;
	u32 tempS0;
	u32 tempS2;
	u32 tempS3;
	u32 tempS4;
	void *tempS1;
	void *attr;

	if (D_8008D05C == 0) {
		return 0;
	}

	tempA0 = arg0 & 0xFFFF;

	if (tempA0 >= M2C_FIELD(D_8008D7C0, u32 *, 0x18)) {
		return 0;
	}

	tempS0 = (arg1 >> 0x10) & 0xFF;
	tempS1 = (void *)(D_8008D7D0 + (tempA0 * 8));
	tempS4 = arg1 >> 0x18;
	tempS2 = (arg1 >> 8) & 0xFF;
	tempS3 = arg1 & 0xFF;

	tempV1 = M2C_FIELD(D_8008D2AC, u8 *, 0x1CA8);

	if (tempV1 == 2) {
		tempV0 = tempS0 << 3;
		tempV0 -= tempS0;
		tempV0 <<= 3;
		tempV0 -= tempS0;
		tempS0 = tempV0 >> 8;
	} else if (tempV1 >= 3) {
		tempV1 = tempS0 << 1;
		tempV1 += tempS0;
		tempV0 = tempV1 << 4;
		tempV0 -= tempV1;
		tempV0 <<= 2;
		tempS0 = tempV0 >> 8;
	}

	tempT0 = D_8008D7AC * M2C_FIELD(tempS1, u8 *, 1);
	tempT0 *= tempS0;
	Channel_SetVolume(&sp10, tempT0 >> 0xA, tempS3);

	if (tempS2 != 0x80) {
		tempV0 = (u32)&D_800825AC;
		tempV1 = tempS2 << 2;
		tempV1 += tempV0;
		tempT0 = M2C_FIELD(tempS1, u16 *, 2) * M2C_FIELD(tempV1, s32 *, 0);
		tempV0 = tempT0 >> 0x10;
	} else {
		tempV0 = M2C_FIELD(tempS1, u16 *, 2);
	}

	sp10.unk8 = tempV0;
	sp10.unkA = tempS4;

	Smart_EnterCriticalSection();

	attr = Channel_SearchFX_EditAttr(0, arg0 & 0xFFFF, 0x70, &sp10);

	if (attr != NULL) {
		M2C_FIELD(attr, s8 *, 0xE) = tempS4;
		M2C_FIELD(attr, s8 *, 0xF) = tempS0;
		M2C_FIELD(attr, s8 *, 0x10) = tempS2;
		M2C_FIELD(attr, s8 *, 0x11) = tempS3;
	}

	Smart_ExitCriticalSection();
	return 1;
}