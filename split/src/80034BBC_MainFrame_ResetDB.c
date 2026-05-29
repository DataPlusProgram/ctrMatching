typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK CTR_EmptyFunc_MainFrame_ResetDB();          /* extern */
M2C_UNK ClearOTagR();                       /* extern */
M2C_UNK DecalGlobal_EmptyFunc_MainFrame_ResetDB(); /* extern */
M2C_UNK LOAD_Hub_Main();                         /* extern */
void *s_OTMem;
s32 videoSTR_src_vramRect;

void MainFrame_ResetDB(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a0;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_a1;
    void *var_v1;

    LOAD_Hub_Main(videoSTR_src_vramRect);
    temp_v1 = 1 - M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg0, void **, 0x10) = (void *) (arg0 + ((temp_v1 * 0xA4) + 0x18));
    M2C_FIELD(arg0, s32 *, 0xC) = temp_v1;
    M2C_FIELD(arg0, s32 *, 0x1CF8) = (s32) (M2C_FIELD(arg0, s32 *, 0x1CF8) + 1);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s8 *, 0x70) = 0;
    temp_v1_2 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(temp_v1_2, s32 *, 0x80) = (s32) M2C_FIELD(temp_v1_2, s32 *, 0x78);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x88) = 0;
    temp_v1_3 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(temp_v1_3, s32 *, 0x9C) = (s32) M2C_FIELD(temp_v1_3, s32 *, 0x94);
    CTR_EmptyFunc_MainFrame_ResetDB();
    DecalGlobal_EmptyFunc_MainFrame_ResetDB(arg0);
    ClearOTagR(M2C_FIELD((arg0 + (M2C_FIELD(arg0, s32 *, 0xC) * 4)), s32 *, 0x18C8), (M2C_FIELD(s_OTMem, u8 *, 0x1CA8) << 0xA) | 6);
    var_a0 = 0;
    if (M2C_FIELD(s_OTMem, u8 *, 0x1CA8) != 0) {
        var_a1 = arg0;
        do {
            temp_v0 = M2C_FIELD(s_OTMem, u8 *, 0x1CA8) - var_a0;
            var_a0 += 1;
            M2C_FIELD(var_a1, s32 *, 0x25C) = (s32) (M2C_FIELD((arg0 + (M2C_FIELD(arg0, s32 *, 0xC) * 4)), s32 *, 0x18C8) + (((temp_v0 - 1) << 0xC) + 0x18));
            var_a1 += 0x110;
        } while (var_a0 < (s32) M2C_FIELD(s_OTMem, u8 *, 0x1CA8));
    }
    if (var_a0 < 4) {
        var_v1 = (var_a0 * 0x110) + arg0;
        do {
            var_a0 += 1;
            M2C_FIELD(var_v1, s32 *, 0x25C) = (s32) (M2C_FIELD((arg0 + (M2C_FIELD(arg0, s32 *, 0xC) * 4)), s32 *, 0x18C8) + 0x3018);
            var_v1 += 0x110;
        } while (var_a0 < 4);
    }
    temp_v0_2 = M2C_FIELD((arg0 + (M2C_FIELD(arg0, s32 *, 0xC) * 4)), s32 *, 0x18C8) + 4;
    M2C_FIELD(arg0, s32 *, 0x147C) = temp_v0_2;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xA0) = temp_v0_2;
}