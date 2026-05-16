typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	u16 unk0;
	s16 unk2;
	s16 unk4;
	s16 unk6;
} M2cRECTMENUDrawRwdBlueRectSubsetArg0;

typedef struct {
	s32 unk0;
	s32 unk4;
	s32 unk8;
} M2cRECTMENUDrawRwdBlueRectSubsetArg1;

void RECTMENU_DrawRwdBlueRect_Subset(M2cRECTMENUDrawRwdBlueRectSubsetArg0 *arg0, M2cRECTMENUDrawRwdBlueRectSubsetArg1 *arg1, s32 *arg2, void *arg3) {
    u32 temp_v1;
    u32 var_t0;

    temp_v1 = M2C_FIELD(arg3, u32 *, 0xC);
    var_t0 = 0;
    if ((u32) M2C_FIELD(arg3, u32 *, 0x10) >= temp_v1) {
        var_t0 = temp_v1;
        M2C_FIELD(arg3, u32 *, 0xC) = (u32) (var_t0 + 0x24);
    }
    if (var_t0 != 0) {
        M2C_FIELD(var_t0, s32 *, 4) = (s32) ((arg1->unk0 & 0xFFFFFF) | 0x38000000);
        M2C_FIELD(var_t0, s32 *, 0xC) = (s32) (arg1->unk4 & 0xFFFFFF);
        M2C_FIELD(var_t0, s32 *, 0x14) = (s32) (arg1->unk8 & 0xFFFFFF);
        M2C_FIELD(var_t0, s32 *, 0x1C) = (s32) (arg1->unk0 & 0xFFFFFF);
        M2C_FIELD(var_t0, s32 *, 8) = (s32) (arg0->unk0 | (arg0->unk2 << 0x10));
        M2C_FIELD(var_t0, s32 *, 0x10) = (s32) ((((s16) arg0->unk0 + arg0->unk4) & 0xFFFF) | (arg0->unk2 << 0x10));
        M2C_FIELD(var_t0, s32 *, 0x18) = (s32) (arg0->unk0 | ((arg0->unk2 + arg0->unk6) << 0x10));
        M2C_FIELD(var_t0, s32 *, 0x20) = (s32) ((((s16) arg0->unk0 + arg0->unk4) & 0xFFFF) | ((arg0->unk2 + arg0->unk6) << 0x10));
        M2C_FIELD(var_t0, s32 *, 0) = (s32) ((*arg2 & 0xFFFFFF) | 0x08000000);
        *arg2 = var_t0 & 0xFFFFFF;
    }
}