typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK RECTMENU_Show();                   /* extern */
extern M2C_UNK D_80085A68;
s16 menuRowHighlight_Normal;

void TakeCupProgress_Activate(s16 arg0) {
    menuRowHighlight_Normal = arg0;
    RECTMENU_Show(&D_80085A68);
}