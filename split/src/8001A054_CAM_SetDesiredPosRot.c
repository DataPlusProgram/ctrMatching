typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} M2cCAMSetDesiredPosRotArg1;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} M2cCAMSetDesiredPosRotArg2;

void CAM_SetDesiredPosRot(void *arg0, M2cCAMSetDesiredPosRotArg1 *arg1, M2cCAMSetDesiredPosRotArg2 *arg2)
{
    u16 temp;

    M2C_FIELD(arg0, u16 *, 0xA4) = arg1->unk0;
    M2C_FIELD(arg0, u16 *, 0xA6) = arg1->unk2;
    M2C_FIELD(arg0, u16 *, 0xA8) = arg1->unk4;
    M2C_FIELD(arg0, u16 *, 0xAA) = arg2->unk0;
    M2C_FIELD(arg0, u16 *, 0xAC) = arg2->unk2;

    temp = arg2->unk4;

    M2C_FIELD(arg0, s16 *, 0x9E) = 0x1E;
    M2C_FIELD(arg0, s16 *, 0x8E) = 0;
    M2C_FIELD(arg0, s16 *, 0x8C) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x70) |= 0x200;
    M2C_FIELD(arg0, u16 *, 0xAE) = temp;
}