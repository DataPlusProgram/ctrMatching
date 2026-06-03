typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK Smart_EnterCriticalSection(); /* extern */
M2C_UNK Smart_ExitCriticalSection();  /* extern */
M2C_UNK SongPool_AdvHub2();           /* extern */

extern u8 boolAudioEnabled;
extern void *ptrCseqHeader;
extern M2C_UNK songPool;

void CseqMusic_AdvHubSwap(s32 arg0, M2C_UNK arg1, M2C_UNK arg2)
{
    s8 *var_s0;
    s32 var_s1;
    u32 temp_s0;
    u32 temp_s2;

    if (boolAudioEnabled != 0)
    {
        temp_s0 = arg0 & 0xFFFF;

        if ((ptrCseqHeader != NULL) &&
            (temp_s0 < (u16)M2C_FIELD(ptrCseqHeader, u16 *, 6)))
        {
            Smart_EnterCriticalSection();

            var_s1 = 0;
            temp_s2 = temp_s0;
            var_s0 = (s8 *)&songPool;

            do
            {
                if ((M2C_FIELD(var_s0, u8 *, 0) & 1) &&
                    (M2C_FIELD(var_s0, u16 *, 2) == temp_s2))
                {
                    SongPool_AdvHub2(var_s0, arg1, arg2);
                }

                var_s1 += 1;
                var_s0 += 0x7C;
            } while (var_s1 < 2);

            Smart_ExitCriticalSection();
        }
    }
}