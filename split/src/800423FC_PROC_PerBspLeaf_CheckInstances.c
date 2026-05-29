typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    u8 flags;
    s8 pad1[0xF];
    void *next;
    s16 z;
    s16 y;
    s16 x;
    s8 pad1A[2];
    void *data;
} InstEntry;

void PROC_PerBspLeaf_CheckInstances(void *arg0, void *arg1) {
    InstEntry *inst;
    void *ctx;
    void *data;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 dist;
    s32 square;

    inst = M2C_FIELD(arg0, InstEntry **, 0x14);
    ctx = arg1;

    if (inst == NULL) {
        return;
    }

    if (M2C_FIELD(inst, s32 *, 0) == 0) {
        return;
    }

    do {
        if (inst->flags & 0x80) {
            data = inst->data;

            if ((data == NULL) || (M2C_FIELD(M2C_FIELD(data, void **, 0x2C), s32 *, 0x28) & 0xF)) {
                dz = M2C_FIELD(ctx, s16 *, 0) - inst->z;
                dist = dz * dz;

                dy = M2C_FIELD(ctx, s16 *, 2) - inst->y;
                dx = M2C_FIELD(ctx, s16 *, 4) - inst->x;

                if (dist <= 0x0FFFFFFF) {
                    square = dy * dy;
                    dist += square;

                    if (square <= 0x0FFFFFFF) {
                        square = dx * dx;
                        dist += square;

                        if ((square <= 0x0FFFFFFF) && (dist < M2C_FIELD(ctx, s32 *, 8))) {
                            M2C_FIELD(ctx, s16 *, 0x14) = dx;
                            M2C_FIELD(ctx, s16 *, 0x12) = dy;
                            M2C_FIELD(ctx, s16 *, 0x10) = dz;
                            M2C_FIELD(ctx, M2C_UNK (**)(void *, InstEntry *, s32, s32), 0x28)(ctx, inst, dist, dz);
                        }
                    }
                }
            }
        }

        inst++;
    } while (M2C_FIELD(inst, s32 *, 0) != 0);
}