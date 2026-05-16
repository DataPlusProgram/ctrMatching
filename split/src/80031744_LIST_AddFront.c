typedef signed char s8;
typedef int s32;

#define NULL 0

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	char pad0[0x8];
	s32 unk8;
} M2cLISTAddFrontArg0;

typedef struct {
	char pad0[0x4];
	s32 unk4;
} M2cLISTAddFrontArg1;

void LIST_AddFront(M2cLISTAddFrontArg0 *arg0, M2cLISTAddFrontArg1 *arg1) {
    void *temp_v0;

    if (arg1 != NULL) {
        arg1->unk4 = 0;
        temp_v0 = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(arg1, void **, 0) = temp_v0;
        if (temp_v0 != NULL) {
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 4) = arg1;
        } else {
            M2C_FIELD(arg0, void **, 4) = arg1;
        }
        M2C_FIELD(arg0, void **, 0) = arg1;
        arg0->unk8 = (s32) (arg0->unk8 + 1);
    }
}