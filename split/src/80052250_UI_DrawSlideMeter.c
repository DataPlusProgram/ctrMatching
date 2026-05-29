#include "../../common.h"

typedef struct SlideMeterBox {
    u16 x;
    u16 y;
    u16 width;
    u16 height;
} SlideMeterBox;

typedef struct SlideMeterColor {
    u8 r;
    u8 g;
    u8 b;
    u8 pad;
} SlideMeterColor;

extern GameTracker *gGamepads;

extern M2C_UNK memset();
extern void CTR_Box_DrawWireBox(SlideMeterBox *box, SlideMeterColor *color, void *otMem, void *primMem);

void UI_DrawSlideMeter(s32 posX, s32 posY, Driver *driver)
{
    SlideMeterBox box;
    SlideMeterColor color;
    void *db;
    void *poly;
    u32 *ot;
    s32 boxHeight;
    s32 fillOffset;
    s32 yTop;

    boxHeight = 7;
    fillOffset = 0;

    if ((u8)gGamepads->numPlyrCurrGame >= 3)
    {
        boxHeight = 3;
    }

    if (driver->turboMeterRoomLeft != 0)
    {
        fillOffset = 0x31 - ((driver->turboMeterRoomLeft * 0x31) / ((u8)driver->constTurboMaxRoom << 5));
    }

    box.x = posX - 0x31;
    box.y = posY - boxHeight;
    box.width = 0x31;
    box.height = boxHeight;

    memset(&color, 0, 4);

    CTR_Box_DrawWireBox(
        &box,
        &color,
        M2C_FIELD(gGamepads, void **, 0x147C),
        (s8 *)gGamepads->backBuffer + 0x74
    );

    db = gGamepads->backBuffer;
    poly = 0;
    if ((u32)M2C_FIELD(db, u32 *, 0x84) >= M2C_FIELD(db, u32 *, 0x80))
    {
        poly = M2C_FIELD(db, void **, 0x80);
        M2C_FIELD(db, u32 *, 0x80) = M2C_FIELD(db, u32 *, 0x80) + 0x18;
    }

    if (poly != 0)
    {
        if (((u8)driver->constTurboLowRoomWarning << 5) < driver->turboMeterRoomLeft)
        {
            M2C_FIELD(poly, u32 *, 4) = 0x2800FF00;
        }
        else
        {
            M2C_FIELD(poly, u32 *, 4) = 0x280000FF;
        }

        yTop = posY - boxHeight;

        M2C_FIELD(poly, s16 *, 8) = posX - fillOffset;
        M2C_FIELD(poly, s16 *, 0xA) = yTop;
        M2C_FIELD(poly, s16 *, 0xC) = posX;
        M2C_FIELD(poly, s16 *, 0xE) = yTop;
        M2C_FIELD(poly, s16 *, 0x12) = posY;
        M2C_FIELD(poly, s16 *, 0x14) = posX;
        M2C_FIELD(poly, s16 *, 0x16) = posY;
        M2C_FIELD(poly, s16 *, 0x10) = posX - fillOffset;

        ot = M2C_FIELD(gGamepads, u32 **, 0x147C);
        M2C_FIELD(poly, u32 *, 0) = *ot | 0x05000000;
        *ot = (u32)poly & 0xFFFFFF;

        db = gGamepads->backBuffer;
        poly = 0;
        if ((u32)M2C_FIELD(db, u32 *, 0x84) >= M2C_FIELD(db, u32 *, 0x80))
        {
            poly = M2C_FIELD(db, void **, 0x80);
            M2C_FIELD(db, u32 *, 0x80) = M2C_FIELD(db, u32 *, 0x80) + 0x18;
        }

        if (poly != 0)
        {
            M2C_FIELD(poly, u32 *, 4) = 0x28808080;

            M2C_FIELD(poly, s16 *, 8) = posX - 0x31;
            M2C_FIELD(poly, s16 *, 0xA) = yTop;
            M2C_FIELD(poly, s16 *, 0xC) = posX;
            M2C_FIELD(poly, s16 *, 0xE) = yTop;
            M2C_FIELD(poly, s16 *, 0x12) = posY;
            M2C_FIELD(poly, s16 *, 0x14) = posX;
            M2C_FIELD(poly, s16 *, 0x16) = posY;
            M2C_FIELD(poly, s16 *, 0x10) = posX - 0x31;

            ot = M2C_FIELD(gGamepads, u32 **, 0x147C);
            M2C_FIELD(poly, u32 *, 0) = *ot | 0x05000000;
            *ot = (u32)poly & 0xFFFFFF;
        }
    }
}