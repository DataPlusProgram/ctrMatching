typedef signed char s8;
typedef short s16;
typedef int s32;

#define WORD(ptr) (*(s32 *)(ptr))

void GAMEPROG_SyncGameAndCard(void *arg0, void *arg1) {
	void *tempT2;
	s8 *gamePtr;
	s8 *cardPtr;
	s16 wordIndex;
	s16 rowIndex;
	s32 offset;
	s32 value;

	tempT2 = arg0;

	gamePtr = (s8 *)tempT2 + 4;
	cardPtr = (s8 *)arg1 + 4;
	wordIndex = 0;

	do {
		wordIndex += 1;
		value = (WORD(cardPtr) = WORD(cardPtr) | WORD(gamePtr));
		cardPtr += 4;
		WORD(gamePtr) = value;
		gamePtr += 4;
	} while (wordIndex < 2);

	rowIndex = 0;

	do {
		offset = (rowIndex * 0x124) + 0xC;
		gamePtr = (s8 *)tempT2 + offset + 0x120;
		cardPtr = (s8 *)arg1 + offset + 0x120;
		wordIndex = 0;

		do {
			wordIndex += 1;
			value = (WORD(cardPtr) = WORD(cardPtr) | WORD(gamePtr));
			cardPtr += 4;
			WORD(gamePtr) = value;
			gamePtr += 4;
		} while ((wordIndex << 16) <= 0);

		rowIndex += 1;
	} while (rowIndex < 0x12);
}