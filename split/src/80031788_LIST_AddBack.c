typedef signed char s8;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	char pad0[0x8];
	s32 unk8;
} M2cLISTAddBackArg0;

void LIST_AddBack(M2cLISTAddBackArg0 *arg0, M2C_UNK *arg1) {
    M2C_UNK *temp_v0;

    if (arg1 != NULL) {
        M2C_FIELD(arg1, M2C_UNK **, 0) = NULL;
        temp_v0 = M2C_FIELD(arg0, M2C_UNK **, 4);
        M2C_FIELD(arg1, M2C_UNK **, 4) = temp_v0;
        if (temp_v0 != NULL) {
            *M2C_FIELD(arg0, M2C_UNK **, 4) = arg1;
        } else {
            M2C_FIELD(arg0, M2C_UNK **, 0) = arg1;
        }
        M2C_FIELD(arg0, M2C_UNK **, 4) = arg1;
        arg0->unk8 = (s32) (arg0->unk8 + 1);
    }
}