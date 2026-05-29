typedef signed char s8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    s8 bytes[4];
} UnalignedS32;

extern void (*D_8009EBEC)(void);
extern s32 D_8009EC1C;
extern s32 D_8009EC24;
extern s32 D_8009EC28;
extern s32 D_8009EC2C;
extern UnalignedS32 D_8009EC3C;
extern s32 D_8009EC40;

void data_ready_callback(void) {
    void *temp_v1;

    temp_v1 = D_8009EC24 + (D_8009EC2C << 5);
    M2C_FIELD(temp_v1, s16 *, 0) = 2;
    D_8009EC3C = M2C_FIELD(temp_v1, UnalignedS32 *, 0x1C);
    D_8009EC40 = M2C_FIELD(temp_v1, s32 *, 8);
    D_8009EC2C = D_8009EC28;
    if (D_8009EBEC != NULL) {
        D_8009EBEC();
    }
    D_8009EC1C = 0;
}