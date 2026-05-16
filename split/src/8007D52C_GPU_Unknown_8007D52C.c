typedef signed char s8;
typedef unsigned short u16;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008C7E4;

void GPU_Unknown_8007D52C(void) {
    void *temp_v1;
    u16 temp_v0;

    temp_v1 = D_8008C7E4;
loop:
    temp_v0 = M2C_FIELD(temp_v1, u16 *, 4);
    if (!(temp_v0 & 2)) {
        goto loop;
    }
}