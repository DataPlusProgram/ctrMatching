typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	u16 unk0;
	u16 unk2;
	u16 unk4;
	u16 unk6;
} M2cCTRBoxDrawWireBoxArg0;

typedef struct {
	u8 unk0;
	u8 unk1;
	u8 unk2;
} M2cCTRBoxDrawWireBoxArg1;

M2C_UNK AddPrim();                   /* extern */

void CTR_Box_DrawWireBox(M2cCTRBoxDrawWireBoxArg0 *arg0, M2cCTRBoxDrawWireBoxArg1 *arg1, M2C_UNK arg2, void *arg3) {
    u32 temp_v1;
    u32 temp_v1_2;
    u32 var_a1;
    u32 var_a1_2;

    temp_v1 = M2C_FIELD(arg3, u32 *, 0xC);
    var_a1 = 0;
    if ((u32) M2C_FIELD(arg3, u32 *, 0x10) >= temp_v1) {
        var_a1 = temp_v1;
        M2C_FIELD(arg3, u32 *, 0xC) = (u32) (var_a1 + 0x18);
    }
    if (var_a1 != 0) {
        M2C_FIELD(var_a1, s8 *, 3) = 5;
        M2C_FIELD(var_a1, s8 *, 7) = 0x48;
        M2C_FIELD(var_a1, s32 *, 0x14) = 0x55555555;
        M2C_FIELD(var_a1, u8 *, 4) = (u8) arg1->unk0;
        M2C_FIELD(var_a1, u8 *, 5) = (u8) arg1->unk1;
        M2C_FIELD(var_a1, u8 *, 6) = (u8) arg1->unk2;
        M2C_FIELD(var_a1, u16 *, 8) = (u16) arg0->unk0;
        M2C_FIELD(var_a1, u16 *, 0xA) = (u16) arg0->unk2;
        M2C_FIELD(var_a1, s16 *, 0xC) = (s16) (arg0->unk0 + arg0->unk4);
        M2C_FIELD(var_a1, u16 *, 0xE) = (u16) arg0->unk2;
        M2C_FIELD(var_a1, s16 *, 0x10) = (s16) (arg0->unk0 + arg0->unk4);
        M2C_FIELD(var_a1, s16 *, 0x12) = (s16) (arg0->unk2 + arg0->unk6);
        AddPrim(arg2, (void *) var_a1);
        temp_v1_2 = M2C_FIELD(arg3, u32 *, 0xC);
        var_a1_2 = 0;
        if ((u32) M2C_FIELD(arg3, u32 *, 0x10) >= temp_v1_2) {
            var_a1_2 = temp_v1_2;
            M2C_FIELD(arg3, u32 *, 0xC) = (u32) (var_a1_2 + 0x18);
        }
        if (var_a1_2 != 0) {
            M2C_FIELD(var_a1_2, s8 *, 3) = 5;
            M2C_FIELD(var_a1_2, s8 *, 7) = 0x48;
            M2C_FIELD(var_a1_2, s32 *, 0x14) = 0x55555555;
            M2C_FIELD(var_a1_2, u8 *, 4) = (u8) arg1->unk0;
            M2C_FIELD(var_a1_2, u8 *, 5) = (u8) arg1->unk1;
            M2C_FIELD(var_a1_2, u8 *, 6) = (u8) arg1->unk2;
            M2C_FIELD(var_a1_2, u16 *, 8) = (u16) arg0->unk0;
            M2C_FIELD(var_a1_2, u16 *, 0xA) = (u16) arg0->unk2;
            M2C_FIELD(var_a1_2, u16 *, 0xC) = (u16) arg0->unk0;
            M2C_FIELD(var_a1_2, s16 *, 0xE) = (s16) (arg0->unk2 + arg0->unk6);
            M2C_FIELD(var_a1_2, s16 *, 0x10) = (s16) (arg0->unk0 + arg0->unk4);
            M2C_FIELD(var_a1_2, s16 *, 0x12) = (s16) (arg0->unk2 + arg0->unk6);
            AddPrim(arg2, (void *) var_a1_2);
        }
    }
}