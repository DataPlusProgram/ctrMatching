#include "../../common.h"


#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	s32 unk0;
	char pad4[0xE];
	u8 unk12;
} M2cCAMClearScreenArg0;

void CAM_ClearScreen(M2cCAMClearScreenArg0 *arg0) {
    s16 temp_a2;
    s16 temp_t3;
    s16 temp_t5;
    s16 temp_t6;
    s16 var_a0;
    s16 var_v1;
    s32 *var_t0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_t4;
    s32 var_t8;
    u16 temp_v0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_v1;
    void *temp_v1_2;
    void *var_a3;

    var_t0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 **, 0x80);
    var_t4 = 0;
    if (arg0->unk12 != 0) {
        var_t8 = 0x168;
        var_a3 = var_t0 + 4;
        do {
            temp_a1 = arg0 + var_t8;
            temp_v0 = M2C_FIELD(temp_a1, u16 *, 0x22);
            temp_t3 = M2C_FIELD(temp_a1, s16 *, 0x20);
            temp_t6 = M2C_FIELD(temp_a1, s16 *, 0x1C);
            temp_t5 = M2C_FIELD(temp_a1, s16 *, 0x1E);
            temp_a2 = ((s32) (M2C_FIELD(temp_a1, s16 *, 6) - 0x800) >> 3) + ((s32) ((s16) temp_v0 + ((u32) (temp_v0 << 0x10) >> 0x1F)) >> 1);
            var_a0 = temp_a2;
            if (temp_a2 < 0) {
                var_a0 = 0;
            }
            var_v1 = (s16) temp_v0;
            if (var_a0 < (s16) temp_v0) {
                var_v1 = var_a0;
            }
            temp_a1_2 = M2C_FIELD(temp_a1, void **, 0xF4);
            if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x160), u8 *, 0x163) != 0) && (var_v1 > 0)) {
                M2C_FIELD(var_a3, s32 *, 8) = (s32) (temp_t3 | (var_v1 << 0x10));
                M2C_FIELD(var_a3, s32 *, 4) = (s32) (temp_t6 | ((temp_t5 + (arg0->unk0 * 0x128)) << 0x10));
                temp_v1 = M2C_FIELD(arg0, void **, 0x160);
                M2C_FIELD(var_a3, s32 *, 0) = (s32) (M2C_FIELD(temp_v1, u8 *, 0x160) | (M2C_FIELD(temp_v1, u8 *, 0x161) << 8) | (M2C_FIELD(temp_v1, u8 *, 0x162) << 0x10) | 0x02000000);
                var_a3 += 0x10;
                *var_t0 = M2C_FIELD(temp_a1_2, s32 *, 0xFFC) | 0x03000000;
                temp_v0_2 = (s32) var_t0 & 0xFFFFFF;
                var_t0 += 0x10;
                M2C_FIELD(temp_a1_2, s32 *, 0xFFC) = temp_v0_2;
            }
            if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x160), u8 *, 0x167) != 0) && (var_v1 < (s16) temp_v0)) {
                M2C_FIELD(var_a3, s32 *, 8) = (s32) (temp_t3 | (((s16) temp_v0 - var_v1) << 0x10));
                M2C_FIELD(var_a3, s32 *, 4) = (s32) (temp_t6 | ((temp_t5 + (arg0->unk0 * 0x128) + var_v1) << 0x10));
                temp_v1_2 = M2C_FIELD(arg0, void **, 0x160);
                M2C_FIELD(var_a3, s32 *, 0) = (s32) (M2C_FIELD(temp_v1_2, u8 *, 0x164) | (M2C_FIELD(temp_v1_2, u8 *, 0x165) << 8) | (M2C_FIELD(temp_v1_2, u8 *, 0x166) << 0x10) | 0x02000000);
                var_a3 += 0x10;
                *var_t0 = M2C_FIELD(temp_a1_2, s32 *, 0xFFC) | 0x03000000;
                temp_v0_3 = (s32) var_t0 & 0xFFFFFF;
                var_t0 += 0x10;
                M2C_FIELD(temp_a1_2, s32 *, 0xFFC) = temp_v0_3;
            }
            var_t4 += 1;
            var_t8 += 0x110;
        } while (var_t4 < (s32) arg0->unk12);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 **, 0x80) = var_t0;
}