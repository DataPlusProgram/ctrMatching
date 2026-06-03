typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern M2C_UNK gameProgress;

void GAMEPROG_SaveCupProgress(void)
{
    s16 var_a1;
    s16 var_v0_2;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_v0;
    void *base;
    void *temp_a0_2;

    var_a1 = 0;
    var_v0 = 0 << 0x10;
    base = &gameProgress;

    do
    {
        temp_a0 = var_v0 >> 0x10;
        temp_v1 = temp_a0 + 0xC;
        var_v0_2 = var_a1 + 1;

        if ((M2C_FIELD((s8 *)base + ((temp_v1 >> 5) * 4), u32 *, 4) >> (temp_v1 & 0x1F)) & 1)
        {
            temp_v0 = temp_a0 + 0x18;
            temp_a0_2 = (s8 *)base + ((temp_v0 >> 5) * 4);

            M2C_FIELD(temp_a0_2, s32 *, 4) =
                M2C_FIELD(temp_a0_2, s32 *, 4) | (1 << (temp_v0 & 0x1F));

            var_v0_2 = var_a1 + 1;
        }

        var_a1 = var_v0_2;
        var_v0 = var_a1 << 0x10;
    } while (var_v0_2 < 0xC);
}