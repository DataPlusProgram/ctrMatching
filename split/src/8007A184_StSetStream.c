typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK StSetMask();                         /* extern */
extern volatile s32 D_8009EBEC;
extern volatile s32 D_8009EBF0;
extern volatile s32 D_8009EBF4;
extern volatile s32 D_8009EBFC;
extern volatile s32 D_8009EC00;
extern volatile s32 D_8009EC04;
extern volatile s32 D_8009EC08;
extern volatile s16 D_8009EC18;

void StSetStream(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;

    temp_s0 = arg0;
    temp_s1 = arg3;
    temp_s2 = arg4;

    StSetMask(1);

    temp_s0 &= 1;
    D_8009EBF4 = 0;
    D_8009EBEC = temp_s1;
    D_8009EC08 = temp_s0;
    D_8009EBFC = 0;
    D_8009EC00 = 0;
    D_8009EC18 = 0;
    D_8009EC04 = 0;
    D_8009EBF0 = temp_s2;
}