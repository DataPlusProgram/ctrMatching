typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void VehPhysProc_PowerSlide_Finalize(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0x3EA) = (u16) M2C_FIELD(arg0, u16 *, 0x3DA);
    M2C_FIELD(arg0, s16 *, 0x3EC) = (s16) (M2C_FIELD(arg0, u8 *, 0x46B) << 5);
}