typedef int s32;

typedef struct {
	char pad0[0x8];
	s32 unk8;
} M2cRECTMENUHideArg0;

void RECTMENU_Hide(M2cRECTMENUHideArg0 *arg0) {
    arg0->unk8 = (s32) (arg0->unk8 | 0x1000);
}