typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK DMACallback(); /* extern */
extern M2C_UNK SetDrawEnv_Unknown_80074BBC;

void SetDrawEnv_Unknown_800752C0(void) {
    void *callback = &SetDrawEnv_Unknown_80074BBC;

    DMACallback(2, callback);
}