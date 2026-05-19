typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

M2C_UNK Smart_EnterCriticalSection();
M2C_UNK Smart_ExitCriticalSection();
M2C_UNK SongPool_ChangeTempo();

extern u8 D_8008D05C;
extern void *D_8008D7B0;
extern M2C_UNK D_80095D84;

void CseqMusic_ChangeTempo(s32 arg0, M2C_UNK arg1) {
    M2C_UNK *var_s0;
    u32 new_var;
    s32 var_s1;
    u32 temp_s0;
    u32 temp_v0;

    if (D_8008D05C != 0) {
        temp_s0 = arg0 & 0xFFFF;

        if ((D_8008D7B0 != 0) && (temp_s0 < ((*((u16 *) ((D_8008D7B0) + 6))))))
		{
            var_s1 = 0;
            Smart_EnterCriticalSection();
            new_var = temp_s0;
            var_s0 = (M2C_UNK *) &D_80095D84;

            do {
                if (((*(s8 *) var_s0) & 1) && ((*((u16 *) (((s8 *) var_s0) + 2))) == new_var))
				{
                    SongPool_ChangeTempo(var_s0, arg1);
                }

                var_s1 += 1;
                var_s0 = (M2C_UNK *) (((s8 *) var_s0) + 0x7C);
            } while (var_s1 < 2);

            Smart_ExitCriticalSection();
        }
    }
}