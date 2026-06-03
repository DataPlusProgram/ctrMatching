typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK DecalFont_DrawMultiLine();  /* extern */
M2C_UNK RECTMENU_Hide();            /* extern */
M2C_UNK SelectProfile_ToggleMode(); /* extern */

extern s16 D_8008D92C;
extern s32 lngStrings;
extern s16 menuRowHighlight_Normal;
extern M2C_UNK menuWarning2;
extern M2C_UNK *stringIndexSaveCupProgress;

void TakeCupProgress_MenuProc(void *arg0)
{
    s16 temp_v1;

    if (M2C_FIELD(arg0, s16 *, 0x1E) == 1)
    {
        if (menuRowHighlight_Normal != 0)
        {
            DecalFont_DrawMultiLine(
                M2C_FIELD(lngStrings, M2C_UNK *, menuRowHighlight_Normal * 4),
                0x100,
                0x3C,
                0x1CC,
                1,
                -0x8000);
        }

        return;
    }

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x1A);

    if (temp_v1 == 0)
    {
        D_8008D92C = 1;
        SelectProfile_ToggleMode(0x41, 1);
        stringIndexSaveCupProgress = &menuWarning2;
        return;
    }

    if (temp_v1 > 0)
    {
        if (temp_v1 == 1)
        {
            RECTMENU_Hide();
        }

        return;
    }

    if (temp_v1 == -1)
    {
        RECTMENU_Hide();
    }
}