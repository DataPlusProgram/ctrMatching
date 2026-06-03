typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK SelectProfile_Destroy(); /* extern */
M2C_UNK SelectProfile_Init();    /* extern */
extern s16 D_80085B9C[];

void SelectProfile_InitAndDestroy(void) {
    SelectProfile_Init(D_80085B9C[0]);
    SelectProfile_Destroy();
}