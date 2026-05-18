typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void DISPLAY_Swap(void);
void DrawOTag(void *);
void DrawSync(s32);
void VSync(s32);

extern void *D_8008D2AC;

void CTR_ErrorScreen(s8 arg0, s8 arg1, s8 arg2) {
	s32 packet[4];
	s32 i;
	void *gameTracker;
	void *rect;

	i = 0;

	do {
		DrawSync(0);
		VSync(0);
		DISPLAY_Swap();

		i++;

		M2C_FIELD(packet, u8 *, 7) = 2;
		M2C_FIELD(packet, s32 *, 0) |= 0xFFFFFF;

		gameTracker = D_8008D2AC;

		M2C_FIELD(packet, u8 *, 4) = arg0;
		M2C_FIELD(packet, u8 *, 5) = arg1;
		M2C_FIELD(packet, u8 *, 6) = arg2;
		M2C_FIELD(packet, u8 *, 3) = 3;

		rect = M2C_FIELD(gameTracker, void **, 0x14);
		M2C_FIELD(packet, u16 *, 0xC) = M2C_FIELD(rect, u16 *, 4);

		rect = M2C_FIELD(gameTracker, void **, 0x14);
		M2C_FIELD(packet, u16 *, 0xE) = M2C_FIELD(rect, u16 *, 6);

		rect = M2C_FIELD(gameTracker, void **, 0x14);
		M2C_FIELD(packet, u16 *, 8) = M2C_FIELD(rect, u16 *, 0);

		rect = M2C_FIELD(gameTracker, void **, 0x14);
		M2C_FIELD(packet, u16 *, 0xA) = M2C_FIELD(rect, u16 *, 2);

		DrawOTag(packet);
	} while (i < 2);

	DrawSync(0);
	VSync(0);
	DISPLAY_Swap();
}