typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void *PROC_BirthWithObject(); /* extern */
M2C_UNK memset();           /* extern */
extern M2C_UNK CAM_ThTick;
extern M2C_UNK D_8008CF8C;

void CAM_Init(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(PROC_BirthWithObject(0x30F, &CAM_ThTick, &D_8008CF8C, 0), void **, 0x34) = arg0;
    memset(arg0, 0, 0xDC);
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 0x44) = arg2;
    M2C_FIELD(arg0, s32 *, 0x48) = arg3;
    M2C_FIELD(arg0, s16 *, 0x9A) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) | 8);
}