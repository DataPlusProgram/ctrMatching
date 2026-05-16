typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK UI_DrawNumKey();               /* extern */
M2C_UNK UI_DrawNumRelic();             /* extern */
M2C_UNK UI_DrawNumTrophy();            /* extern */
extern void *D_8008625C[];
extern void *D_8008D2AC;

void UI_RenderFrame_AdvHub(void) {
    s32 temp_s1;
    void *temp_s0;
    s32 temp_v0;

    temp_v0 = M2C_FIELD(D_8008D2AC, u8 *, 0x1CA8) - 1;
    temp_s1 = M2C_FIELD(D_8008D2AC, s32 *, 0x24EC);
    temp_s0 = D_8008625C[temp_v0];

    UI_DrawNumRelic((s16)(M2C_FIELD(temp_s0, u16 *, 0x70) + 0x10), (s16)(M2C_FIELD(temp_s0, u16 *, 0x72) - 0xA), temp_s1);
    UI_DrawNumKey((s16)(M2C_FIELD(temp_s0, u16 *, 0x78) + 0x10), (s16)(M2C_FIELD(temp_s0, u16 *, 0x7A) - 0xA), temp_s1);
    UI_DrawNumTrophy((s16)(M2C_FIELD(temp_s0, u16 *, 0x80) + 0x10), (s16)(M2C_FIELD(temp_s0, u16 *, 0x82) - 0xA), temp_s1);
}