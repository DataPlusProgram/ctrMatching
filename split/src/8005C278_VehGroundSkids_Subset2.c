typedef signed char s8;
typedef short s16;
typedef unsigned short u16;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	u16 unk0;
	u16 unk2;
	u16 unk4;
} M2cVehGroundSkidsSubset2Arg1;

typedef struct {
	u16 unk0;
	u16 unk2;
	u16 unk4;
} M2cVehGroundSkidsSubset2Arg2;

typedef struct {
	u16 unk0;
	u16 unk2;
	u16 unk4;
} M2cVehGroundSkidsSubset2Arg3;

void VehGroundSkids_Subset2(void *arg0, M2cVehGroundSkidsSubset2Arg1 *arg1, M2cVehGroundSkidsSubset2Arg2 *arg2, M2cVehGroundSkidsSubset2Arg3 *arg3) {
    M2C_FIELD(arg0, s16 *, 0) = (s16) ((arg1->unk0 - M2C_FIELD(arg0, u16 *, 0xB8)) * 4);
    M2C_FIELD(arg0, s16 *, 2) = (s16) ((arg1->unk2 - M2C_FIELD(arg0, u16 *, 0xBC)) * 4);
    M2C_FIELD(arg0, s16 *, 4) = (s16) ((arg1->unk4 - M2C_FIELD(arg0, u16 *, 0xC0)) * 4);
    M2C_FIELD(arg0, s16 *, 8) = (s16) ((arg2->unk0 - M2C_FIELD(arg0, u16 *, 0xB8)) * 4);
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) ((arg2->unk2 - M2C_FIELD(arg0, u16 *, 0xBC)) * 4);
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) ((arg2->unk4 - M2C_FIELD(arg0, u16 *, 0xC0)) * 4);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) ((arg3->unk0 - M2C_FIELD(arg0, u16 *, 0xB8)) * 4);
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) ((arg3->unk2 - M2C_FIELD(arg0, u16 *, 0xBC)) * 4);
    M2C_FIELD(arg0, s16 *, 0x14) = (s16) ((arg3->unk4 - M2C_FIELD(arg0, u16 *, 0xC0)) * 4);
}