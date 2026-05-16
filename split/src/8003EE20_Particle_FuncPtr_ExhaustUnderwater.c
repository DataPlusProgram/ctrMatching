typedef signed char s8;
typedef short s16;
typedef int s32;

#define NULL 0

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s32 MixRNG_Scramble();                              /* extern */
extern void *D_8008D2AC;

void Particle_FuncPtr_ExhaustUnderwater(void *arg0) {
    void *temp_v0;

    if (((((s32) M2C_FIELD(arg0, s32 *, 0x2C) >> 8) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x48)) >= 4) && (M2C_FIELD(arg0, s16 *, 0x10) < 0x1B)) {
        temp_v0 = M2C_FIELD(D_8008D2AC, void **, 0x2134);
        M2C_FIELD(arg0, void **, 0xC) = temp_v0;
        if (temp_v0 != NULL) {
            M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(temp_v0, s32 *, 0x14);
        }
        M2C_FIELD(arg0, s32 *, 0x44) = (s32) (MixRNG_Scramble() & 0xFFF);
        M2C_FIELD(arg0, s16 *, 0x10) = 0;
    }
}