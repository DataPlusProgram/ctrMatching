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
} M2cCTRBoxDrawClearBoxArg0;

typedef struct {
	u8 unk0;
	u8 unk1;
	u8 unk2;
} M2cCTRBoxDrawClearBoxArg1;

M2C_UNK AddPrim();                   /* extern */

void CTR_Box_DrawClearBox(M2cCTRBoxDrawClearBoxArg0 *arg0, M2cCTRBoxDrawClearBoxArg1 *arg1, s32 arg2, M2C_UNK arg3, void *arg4) {
    u32 temp_v1;
    u32 var_a1;

    temp_v1 = M2C_FIELD(arg4, u32 *, 0xC);
    var_a1 = 0;
    if ((u32) M2C_FIELD(arg4, u32 *, 0x10) >= temp_v1) {
        var_a1 = temp_v1;
        M2C_FIELD(arg4, u32 *, 0xC) = (u32) (var_a1 + 0x20);
    }
    if (var_a1 != 0) {
        M2C_FIELD(var_a1, s8 *, 3) = 7;
        M2C_FIELD(var_a1, s8 *, 0xF) = 0x2A;
        M2C_FIELD(var_a1, s32 *, 4) = (s32) ((arg2 << 5) | 0xE1000A00);
        M2C_FIELD(var_a1, s32 *, 8) = 0;
        M2C_FIELD(var_a1, u8 *, 0xC) = (u8) arg1->unk0;
        M2C_FIELD(var_a1, u8 *, 0xD) = (u8) arg1->unk1;
        M2C_FIELD(var_a1, u8 *, 0xE) = (u8) arg1->unk2;
        M2C_FIELD(var_a1, u16 *, 0x10) = (u16) arg0->unk0;
        M2C_FIELD(var_a1, u16 *, 0x12) = (u16) arg0->unk2;
        M2C_FIELD(var_a1, s16 *, 0x14) = (s16) (arg0->unk0 + arg0->unk4);
        M2C_FIELD(var_a1, u16 *, 0x16) = (u16) arg0->unk2;
        M2C_FIELD(var_a1, u16 *, 0x18) = (u16) arg0->unk0;
        M2C_FIELD(var_a1, s16 *, 0x1A) = (s16) (arg0->unk2 + arg0->unk6);
        M2C_FIELD(var_a1, s16 *, 0x1C) = (s16) (arg0->unk0 + arg0->unk4);
        M2C_FIELD(var_a1, s16 *, 0x1E) = (s16) (arg0->unk2 + arg0->unk6);
        AddPrim(arg3, (void *) var_a1);
    }
}