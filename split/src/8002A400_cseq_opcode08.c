typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#define NULL 0

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x1];
    u8 unk1;
} M2cCseqOpcode08Arg0;

extern s32 D_8008FC6C[];
extern u8 D_8008FCCC[];
extern void *D_8009056C;

void cseq_opcode08(M2cCseqOpcode08Arg0 *arg0) {
    void *var_a1;
    void *temp_a2;
    s32 temp_v1;

    var_a1 = D_8009056C;
    temp_a2 = M2C_FIELD(arg0, void **, 0x18);

    if (var_a1 != NULL) {
        do {
            if ((M2C_FIELD(var_a1, u8 *, 0xB) == 2) && (M2C_FIELD(var_a1, s32 *, 0x18) == arg0->unk1)) {
                M2C_FIELD(&D_8008FCCC[M2C_FIELD(var_a1, u8 *, 9) * 0x10], s16 *, 0xA) = M2C_FIELD(temp_a2, u8 *, 1);

                temp_v1 = M2C_FIELD(var_a1, u8 *, 9);
                D_8008FC6C[temp_v1] |= 0x20;
            }

            var_a1 = M2C_FIELD(var_a1, void **, 0);
        } while (var_a1 != NULL);
    }
}