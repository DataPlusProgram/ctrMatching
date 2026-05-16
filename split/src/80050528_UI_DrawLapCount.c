typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x44];
    volatile u8 unk44;
} M2cUIDrawLapCountArg3;

M2C_UNK DecalFont_DrawLine(); /* extern */
s32 sprintf(char *arg0, char *arg1, s32 arg2, s32 arg3); /* extern */
extern void *D_8008D2AC;
extern char D_8008D514[];
extern char D_8008D51C[];
extern void *D_8008D878;

void UI_DrawLapCount(s32 arg0, s32 arg1, s32 arg2, M2cUIDrawLapCountArg3 *arg3) {
    char sp18[24];
    s32 temp_s2;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_s3;
    void *temp_t0;

    temp_t0 = D_8008D2AC;

    temp_s2 = arg3->unk44 + 1;
    temp_v0 = arg3->unk44 + 1;
    if (M2C_FIELD(temp_t0, s8 *, 0x1D33) < temp_v0) {
        temp_s2 = M2C_FIELD(temp_t0, s8 *, 0x1D33);
    }

    temp_s3 = arg1;

    if (M2C_FIELD(temp_t0, u8 *, 0x1CA8) < 3U) {
        temp_s1 = 0x4001;
        DecalFont_DrawLine(M2C_FIELD(D_8008D878, M2C_UNK **, 0x60), (s16) arg0, (s16) temp_s3, 2, temp_s1);
        sprintf(sp18, D_8008D514, temp_s2, M2C_FIELD(D_8008D2AC, s8 *, 0x1D33));
        DecalFont_DrawLine(sp18, (s16) arg0, (s16) (temp_s3 + 8), 1, temp_s1);
    } else {
        D_8008D51C[0] = temp_s2 + 0x30;
        D_8008D51C[2] = M2C_FIELD(temp_t0, u8 *, 0x1D33) + 0x30;
        DecalFont_DrawLine(D_8008D51C, (s16) arg0, (s16) (temp_s3 + 8), 2, 1);
    }
}