typedef signed char s8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x482];
    s16 unk482;
    char pad484[0x14];
    void *unk498;
    char pad49C[0x4C];
    s32 unk4E8;
} M2cUIDrawPosSuffixArg2;

M2C_UNK DecalFont_DrawLine(); /* extern */
extern M2C_UNK D_8008643C;
extern s32 *gT;
extern s32 lngStrings;

void UI_DrawPosSuffix(s16 arg0, s16 arg1, M2cUIDrawPosSuffixArg2 *arg2, s16 arg3)
{
    s32 var_v0;
    void *var_v1;
    void *temp_v1;

    if (*gT & 0x20)
    {
        var_v0 = M2C_FIELD((s8 *)gT + (arg2->unk4E8 * 4), s32 *, 0x1DA8);
        var_v1 = (void *)0x80080000;
    }
    else
    {
        var_v0 = arg2->unk482;
        var_v1 = &D_8008643C;
    }

    var_v0 = M2C_FIELD(var_v1, s16 *, var_v0 * 2);

    DecalFont_DrawLine(
        M2C_FIELD(lngStrings, M2C_UNK *, var_v0 * 4),
        arg0,
        arg1,
        1,
        (s32)arg3);

    temp_v1 = arg2->unk498;
    if (temp_v1 != NULL)
    {
        M2C_FIELD(temp_v1, s32 *, 0x4C) = arg2->unk482 + 0x100;
    }
}