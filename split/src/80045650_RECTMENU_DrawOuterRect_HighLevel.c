typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK RECTMENU_DrawOuterRect_LowLevel(); /* extern */

void RECTMENU_DrawOuterRect_HighLevel(M2C_UNK unused, M2C_UNK arg1, s16 arg2, s32 arg3) {
    RECTMENU_DrawOuterRect_LowLevel(unused, 3, 2, arg1, (s32)arg2, arg3);
}