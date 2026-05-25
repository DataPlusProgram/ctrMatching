typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	char pad0[0x4];
	u8 unk4;
	char pad5[0x27];
	s32 unk2C;
	s32 unk30;
} M2cUIDrawBattleScoresArg2;

M2C_UNK DecalFont_DrawLine(); /* extern */
M2C_UNK DecalHUD_DrawPolyFT4();   /* extern */
M2C_UNK sprintf();    /* extern */
extern M2C_UNK D_8008644C;
extern M2C_UNK D_8008D520;
extern void *gGamepads;

void UI_DrawBattleScores(s16 arg0, s16 arg1, M2cUIDrawBattleScoresArg2 *arg2) {
    M2C_UNK sp20;
    s32 temp_a3;
    s32 var_a0;
    s32 var_a3;
    u16 temp_s2;

    temp_a3 = M2C_FIELD(gGamepads, s32 *, 0);
    temp_s2 = *((arg2->unk4 * 2) + ((M2C_FIELD(gGamepads, u8 *, 0x1CA8) - 1) * 8) + &D_8008644C);
    if (temp_a3 & 0x4000) {
        sprintf(&sp20, &D_8008D520, M2C_FIELD((gGamepads + (arg2->unk30 * 4)), s32 *, 0x1D90), temp_a3);
        DecalFont_DrawLine(&sp20, (s16) (arg0 + 0x25), (s16) (arg1 + 4), 2, (s32) (s16) temp_s2);
        var_a3 = M2C_FIELD(gGamepads, s32 *, 0x10);
        var_a0 = M2C_FIELD(gGamepads, s32 *, 0x2100);
        goto block_4;
    }
    if (temp_a3 & 0x8000) {
        sprintf(&sp20, &D_8008D520, arg2->unk2C, temp_a3);
        DecalFont_DrawLine(&sp20, (s16) (arg0 + 0x25), (s16) (arg1 + 4), 2, (s32) (s16) temp_s2);
        var_a3 = M2C_FIELD(gGamepads, s32 *, 0x10);
        var_a0 = M2C_FIELD(gGamepads, s32 *, 0x20FC);
block_4:
        DecalHUD_DrawPolyFT4(var_a0, arg0, arg1, var_a3 + 0x74);
    }
}