typedef int s32;
typedef unsigned int u32;

typedef struct {
	char pad0[0x8];
	u32 unk8;
} M2cRECTMENUBoolHiddenArg0;

s32 RECTMENU_BoolHidden(M2cRECTMENUBoolHiddenArg0 *arg0) {
    return ((u32) arg0->unk8 >> 0xC) & 1;
}