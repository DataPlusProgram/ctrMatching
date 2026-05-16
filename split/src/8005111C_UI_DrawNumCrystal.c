typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x31];
    s8 unk31;
} M2cUIDrawNumCrystalArg2;

M2C_UNK DecalFont_DrawLine(); /* extern */
s32 sprintf(char *arg0, char *arg1, s32 arg2, s32 arg3); /* extern */
extern char D_800116E0[];
extern void *D_8008D2AC;
extern M2C_UNK D_8008D528;

void UI_DrawNumCrystal(s32 arg0, s32 arg1, M2cUIDrawNumCrystalArg2 *arg2) {
    char sp18[16];

    DecalFont_DrawLine(&D_8008D528, (s16) arg0, (s16) (arg1 + 4), 2, 0);
    sprintf(sp18, D_800116E0, arg2->unk31, M2C_FIELD(D_8008D2AC, s32 *, 0x1E28));
    DecalFont_DrawLine(sp18, (s16) (arg0 + 0xD), (s16) arg1, 1, 0);
}