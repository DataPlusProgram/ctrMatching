typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK DecalFont_DrawLine(); /* extern */
s32 sprintf(char *arg0, char *arg1, s32 arg2); /* extern */
extern void *D_8008D2AC;
extern char D_8008D520[];
extern M2C_UNK D_8008D528;

void UI_DrawNumRelic(s32 arg0, s32 arg1) {
    char sp18[16];
    s32 var_a2;

    DecalFont_DrawLine(&D_8008D528, (s16) arg0, (s16) (arg1 + 4), 2, 0);

    var_a2 = M2C_FIELD(D_8008D2AC, s32 *, 0x1E34);
    if (M2C_FIELD(D_8008D2AC, s32 *, 8) & 0x01000000) {
        var_a2 -= 1;
    }

    sprintf(sp18, D_8008D520, var_a2);
    DecalFont_DrawLine(sp18, (s16) (arg0 + 0xD), (s16) arg1, 1, 0);
}