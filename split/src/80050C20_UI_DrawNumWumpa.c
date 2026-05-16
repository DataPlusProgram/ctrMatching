typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))
#define M2C_UNALIGNED32(expr) (expr)

typedef struct {
	char pad0[0x1E];
	s8 unk1E;
} M2cUIDrawNumWumpaArg2;

M2C_UNK DecalFont_DrawLine(); /* extern */
M2C_UNK DecalHUD_DrawPolyGT4(); /* extern */
M2C_UNK sprintf();          /* extern */
extern void *D_80081D70;
extern void *D_8008D2AC;
extern M2C_UNK D_8008D510;
extern M2C_UNK D_8008D528;

void UI_DrawNumWumpa(s16 arg0, s16 arg1, M2cUIDrawNumWumpaArg2 *arg2) {
    M2C_UNK sp30;
    s32 temp_s1;

    if ((u8) M2C_FIELD(D_8008D2AC, u8 *, 0x1CA8) < 3U) {
        DecalFont_DrawLine(&D_8008D528, arg0, (s16) (arg1 + 4), 2, 0);
        sprintf(&sp30, &D_8008D510, arg2->unk1E);
        DecalFont_DrawLine(&sp30, (s16) (arg0 + 0xD), arg1, 1, 0);
        return;
    }
    temp_s1 = arg2->unk1E % 10;
    DecalHUD_DrawPolyGT4(M2C_FIELD((M2C_FIELD(D_8008D2AC, s32 *, 0x2128) + ((s8) (arg2->unk1E / 10) * 4)), s32 *, 0x14), arg0, arg1, M2C_FIELD(D_8008D2AC, s32 *, 0x10) + 0x74, M2C_FIELD(D_8008D2AC, s32 *, 0x147C), M2C_UNALIGNED32(M2C_FIELD(D_80081D70, M2C_UNK *, 0)), M2C_UNALIGNED32(M2C_FIELD(D_80081D70, M2C_UNK *, 4)), M2C_UNALIGNED32(M2C_FIELD(D_80081D70, M2C_UNK *, 8)), M2C_UNALIGNED32(M2C_FIELD(D_80081D70, M2C_UNK *, 0xC)), 0, 0x1000);
    DecalHUD_DrawPolyGT4(M2C_FIELD((M2C_FIELD(D_8008D2AC, s32 *, 0x2128) + (temp_s1 * 4)), s32 *, 0x14), arg0 + 0xC, arg1, M2C_FIELD(D_8008D2AC, s32 *, 0x10) + 0x74, M2C_FIELD(D_8008D2AC, s32 *, 0x147C), M2C_UNALIGNED32(M2C_FIELD(D_80081D70, M2C_UNK *, 0)), M2C_UNALIGNED32(M2C_FIELD(D_80081D70, M2C_UNK *, 4)), M2C_UNALIGNED32(M2C_FIELD(D_80081D70, M2C_UNK *, 8)), M2C_UNALIGNED32(M2C_FIELD(D_80081D70, M2C_UNK *, 0xC)), 0, 0x1000);
}