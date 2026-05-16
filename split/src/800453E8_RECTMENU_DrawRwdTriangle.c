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
	u16 unk8;
} M2cRECTMENUDrawRwdTriangleArg0;

typedef struct {
	u8 unk0;
	u8 unk1;
	u8 unk2;
	char pad3[0x1];
	u8 unk4;
	u8 unk5;
	u8 unk6;
	char pad7[0x1];
	u8 unk8;
	u8 unk9;
} M2cRECTMENUDrawRwdTriangleArg1;

M2C_UNK AddPrim();                   /* extern */

void RECTMENU_DrawRwdTriangle(M2cRECTMENUDrawRwdTriangleArg0 *arg0, M2cRECTMENUDrawRwdTriangleArg1 *arg1, M2C_UNK arg2, void *arg3) {
    u32 temp_t0;
    u32 var_a1;

    temp_t0 = M2C_FIELD(arg3, u32 *, 0xC);
    var_a1 = 0;
    if ((u32) M2C_FIELD(arg3, u32 *, 0x10) >= temp_t0) {
        var_a1 = temp_t0;
        M2C_FIELD(arg3, u32 *, 0xC) = (u32) (var_a1 + 0x24);
    }
    if (var_a1 != 0) {
        M2C_FIELD(var_a1, s8 *, 3) = 8;
        M2C_FIELD(var_a1, s8 *, 7) = 0x38;
        M2C_FIELD(var_a1, u8 *, 4) = (u8) arg1->unk0;
        M2C_FIELD(var_a1, u8 *, 5) = (u8) arg1->unk1;
        M2C_FIELD(var_a1, u8 *, 6) = (u8) arg1->unk2;
        M2C_FIELD(var_a1, u8 *, 0xC) = (u8) arg1->unk4;
        M2C_FIELD(var_a1, u8 *, 0xD) = (u8) arg1->unk5;
        M2C_FIELD(var_a1, u8 *, 0xE) = (u8) arg1->unk6;
        M2C_FIELD(var_a1, u8 *, 0x14) = (u8) arg1->unk0;
        M2C_FIELD(var_a1, u8 *, 0x15) = (u8) arg1->unk1;
        M2C_FIELD(var_a1, u8 *, 0x16) = (u8) arg1->unk2;
        M2C_FIELD(var_a1, u8 *, 0x1C) = (u8) arg1->unk8;
        M2C_FIELD(var_a1, u8 *, 0x1D) = (u8) arg1->unk9;
        M2C_FIELD(var_a1, u8 *, 0x1E) = (u8) arg1->unk0;
        M2C_FIELD(var_a1, u16 *, 8) = (u16) arg0->unk0;
        M2C_FIELD(var_a1, s16 *, 0xA) = (s16) (arg0->unk2 - 1);
        M2C_FIELD(var_a1, u16 *, 0x10) = (u16) arg0->unk4;
        M2C_FIELD(var_a1, u16 *, 0x12) = (u16) arg0->unk6;
        M2C_FIELD(var_a1, u16 *, 0x18) = (u16) arg0->unk0;
        M2C_FIELD(var_a1, u16 *, 0x1A) = (u16) arg0->unk2;
        M2C_FIELD(var_a1, u16 *, 0x20) = (u16) arg0->unk8;
        M2C_FIELD(var_a1, u16 *, 0x22) = (u16) arg0->unk0;
        AddPrim(arg2, (void *) var_a1);
    }
}