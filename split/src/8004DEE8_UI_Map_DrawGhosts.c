typedef signed char s8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK UI_Map_DrawRawIcon();

extern void *D_8008D2AC;
extern s8 D_8008E6E8[];

void UI_Map_DrawGhosts(s32 arg0, void *arg1) {
    M2C_UNK var_a3;
    void *temp_v1;
    void *var_s0;
    void *temp_v1_2;
    s32 temp_a1;

    var_s0 = arg1;

    if (var_s0 != NULL) {
        do {
            temp_v1 = M2C_FIELD(var_s0, void **, 0x30);
            temp_a1 = M2C_FIELD(var_s0, s32 *, 0x34);

            if (M2C_FIELD(temp_v1, s16 *, 0x632) != 0) {
                if (M2C_FIELD(temp_v1, s16 *, 0x630) != 0) {
                    var_a3 = 0x11;

                    temp_v1_2 = &D_8008E6E8[M2C_FIELD(D_8008D2AC, s32 *, 0x1A10) * 0x124];

                    if (M2C_FIELD(temp_v1_2, s32 *, 0x12C) & 2) {
                        var_a3 = 3;

                        if (M2C_FIELD(D_8008D2AC, s32 *, 0x1CEC) & 1) {
                            var_a3 = 4;
                        }
                    }
                } else {
                    var_a3 = 6;

                    if (M2C_FIELD(D_8008D2AC, s32 *, 0x1CEC) & 1) {
                        var_a3 = 5;
                    }
                }

                UI_Map_DrawRawIcon(arg0, temp_a1 + 0x44, 0x31, var_a3, 0, 0x1000);
            }

            var_s0 = M2C_FIELD(var_s0, void **, 0x10);
        } while (var_s0 != NULL);
    }
}