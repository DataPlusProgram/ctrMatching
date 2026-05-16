typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void DropRain_Reset(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x1EC8) = 0;
}