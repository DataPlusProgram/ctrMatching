typedef signed char s8;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK LIST_AddFront();              /* extern */
extern s32 D_8008D2AC;

void Particle_OnDestroy(void *arg0) {
    M2C_UNK *temp_s0;
    M2C_UNK *var_a1;

    var_a1 = M2C_FIELD(arg0, M2C_UNK **, 4);
    if (var_a1 != NULL) {
        do {
            temp_s0 = *var_a1;
            LIST_AddFront(D_8008D2AC + 0x19C0, var_a1);
            var_a1 = temp_s0;
        } while (var_a1 != NULL);
    }
}