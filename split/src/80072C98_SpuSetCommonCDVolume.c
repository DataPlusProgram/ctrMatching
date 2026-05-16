typedef signed char s8;
typedef short s16;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008C3B4;

void SpuSetCommonCDVolume(s16 arg0, s16 arg1) {
    M2C_FIELD(D_8008C3B4, s16 *, 0x1B0) = arg0;
    M2C_FIELD(D_8008C3B4, s16 *, 0x1B2) = arg1;
}