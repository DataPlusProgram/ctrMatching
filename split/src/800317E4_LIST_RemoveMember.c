typedef signed char s8;
typedef int s32;

#define NULL 0

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	char pad0[0x8];
	s32 unk8;
} M2cLISTRemoveMemberArg0;

void *LIST_RemoveMember(M2cLISTRemoveMemberArg0 *arg0, void *arg1) {
    void **temp_v1;
    void *temp_v1_2;

    if (arg1 != NULL) {
        if (M2C_FIELD(arg0, void **, 0) != NULL) {
            temp_v1 = M2C_FIELD(arg1, void ***, 4);
            if (temp_v1 != NULL) {
                *temp_v1 = M2C_FIELD(arg1, void **, 0);
            } else {
                M2C_FIELD(arg0, void **, 0) = (void *) M2C_FIELD(arg1, void **, 0);
            }
            temp_v1_2 = M2C_FIELD(arg1, void **, 0);
            if (temp_v1_2 != NULL) {
                M2C_FIELD(temp_v1_2, void ***, 4) = (void **) M2C_FIELD(arg1, void ***, 4);
            } else {
                M2C_FIELD(arg0, void ***, 4) = (void **) M2C_FIELD(arg1, void ***, 4);
            }
            arg0->unk8 = (s32) (arg0->unk8 - 1);
        }
        M2C_FIELD(arg1, void **, 0) = NULL;
        M2C_FIELD(arg1, void ***, 4) = NULL;
    }
    return arg1;
}