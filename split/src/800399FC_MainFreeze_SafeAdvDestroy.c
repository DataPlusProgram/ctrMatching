typedef int s32;

typedef s32 M2C_UNK;

s32 LOAD_IsOpen_AdvHub();                           /* extern */
M2C_UNK func_800B1EF8();                            /* extern */
s32 *s_OTMem;

void MainFreeze_SafeAdvDestroy(void) {
    if ((*s_OTMem & 0x100000) && (LOAD_IsOpen_AdvHub() != 0)) {
        func_800B1EF8();
    }
}