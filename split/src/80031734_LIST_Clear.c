typedef int s32;

typedef struct {
	s32 unk0;
	s32 unk4;
	s32 unk8;
} M2cLISTClearArg0;

void LIST_Clear(M2cLISTClearArg0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
}