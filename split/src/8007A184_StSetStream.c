typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK StSetMask();                         /* extern */
extern s32 D_8009EBEC;
extern s32 D_8009EBF0;
extern s32 D_8009EBF4;
extern s32 D_8009EBFC;
extern s32 D_8009EC00;
extern s32 D_8009EC04;
extern s32 D_8009EC08;
extern s16 D_8009EC18;

void StSetStream(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register s32 temp_s0 asm("$16");
    register s32 temp_s1 asm("$17");
    register s32 temp_s2 asm("$18");

    temp_s0 = arg0;
	temp_s2 = arg4;
    temp_s1 = arg3;
   

    StSetMask(1);

    temp_s0 &= 1;
    D_8009EBF4 = 0;
	D_8009EBFC = 0;
    D_8009EBEC = temp_s1;
    D_8009EC08 = temp_s0;
    
    D_8009EC00 = 0;
    D_8009EC18 = 0;
    D_8009EC04 = 0;
    D_8009EBF0 = temp_s2;
}