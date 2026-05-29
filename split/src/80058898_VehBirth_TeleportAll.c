typedef signed char s8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK BOTS_GotoStartingLine();         /* extern */
M2C_UNK VehBirth_TeleportSelf();         /* extern */
extern s32 gGamepads;

void VehBirth_TeleportAll(s32 arg0, s32 arg1) {
    s32 var_s0;
    s32 var_v0;
    s32 temp_a1;
    void *temp_a0;

    var_s0 = 0;
    do {
        temp_a0 = M2C_FIELD((gGamepads + ((var_s0 << 0x10) >> 0xE)), void **, 0x24EC);
        var_v0 = var_s0 + 1;
        if (temp_a0 != NULL) {
            temp_a1 = arg1 | 1;
            if (M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a0, void **, 0x1C), void **, 0x6C), s16 *, 0x44) == 0x3F) {
                BOTS_GotoStartingLine(temp_a0, temp_a1);
                var_v0 = var_s0 + 1;
            } else {
                VehBirth_TeleportSelf(temp_a0, temp_a1, 0);
                var_v0 = var_s0 + 1;
            }
        }
        var_s0 = var_v0;
    } while (var_v0 < 8);
}