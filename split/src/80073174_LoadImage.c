typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK DrawSync_Unknown_80073058();  /* extern */
extern M2C_UNK D_80011DAC;
extern void *D_8008AD78;

void LoadImage(s32 arg0, M2C_UNK arg1) {
    DrawSync_Unknown_80073058(&D_80011DAC, arg0);
    M2C_FIELD(D_8008AD78, M2C_UNK (**)(s32, s32, M2C_UNK, M2C_UNK), 8)(M2C_FIELD(D_8008AD78, s32 *, 0x20), arg0, 8, arg1);
}