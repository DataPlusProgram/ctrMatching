#include "../../common.h"

extern void DecalFont_DrawLine(char *str, s16 posX, s16 posY, s16 fontType, u32 flags);

typedef struct DecalFontGamepads {
    u8 pad[0x147C];
    void *otMem;
} DecalFontGamepads;

void DecalFont_DrawLineOT(char *str, s16 posX, s16 posY, s16 fontType, s16 flags, void *otMem)
{
    void *savedOtMem;

    savedOtMem = ((DecalFontGamepads *)gT)->otMem;
    ((DecalFontGamepads *)gT)->otMem = otMem;

    DecalFont_DrawLine(str, posX, posY, fontType, flags);

    ((DecalFontGamepads *)gT)->otMem = savedOtMem;
}
