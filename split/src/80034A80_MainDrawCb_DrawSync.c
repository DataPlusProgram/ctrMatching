typedef signed char s8;
typedef unsigned char u8;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void *s_OTMem;

void MainDrawCb_DrawSync(void) {
    if (M2C_FIELD(s_OTMem, u8 *, 0x1D30) == 1) {
        M2C_FIELD(s_OTMem, u8 *, 0x1D30) = 0;
    }
}