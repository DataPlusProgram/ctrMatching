typedef int s32;

typedef s32 M2C_UNK;

typedef struct {
	char pad0[0x8];
	s32 unk8;
} M2cRECTMENUShowArg0;

M2C_UNK RECTMENU_ClearInput();                      /* extern */
void *advCharSelectIndex_prev;

void RECTMENU_Show(M2cRECTMENUShowArg0 *arg0) {
    RECTMENU_ClearInput();
    advCharSelectIndex_prev = arg0;
    arg0->unk8 = (s32) (arg0->unk8 & ~0x1000);
}