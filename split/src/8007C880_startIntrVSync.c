typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK GPU_Unknown_8007C970();   /* extern */
M2C_UNK InterruptCallback();      /* extern */
extern M2C_UNK D_8008C734;
extern s32 D_8008C754;
extern s32 *D_8008C758;
extern M2C_UNK GPU_Unknown_8007C8D8;
extern M2C_UNK GPU_Unknown_8007C944;

M2C_UNK *startIntrVSync(void) {
    *D_8008C758 = 0x100;
    D_8008C754 = 0;
    GPU_Unknown_8007C970(&D_8008C734, 8);
    InterruptCallback(0, &GPU_Unknown_8007C8D8);
    return &GPU_Unknown_8007C944;
}
