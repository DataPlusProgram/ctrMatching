typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK Particle_UpdateList();           /* extern */
extern void *D_8008D2AC;

void Particle_UpdateAllParticles(void) {
    if (!(M2C_FIELD(D_8008D2AC, s32 *, 0) & 0x10)) {
        Particle_UpdateList(D_8008D2AC + 0x1C9C, M2C_FIELD(D_8008D2AC, s32 *, 0x1C9C));
        Particle_UpdateList(D_8008D2AC + 0x1CA0, M2C_FIELD(D_8008D2AC, s32 *, 0x1CA0));
    }
}