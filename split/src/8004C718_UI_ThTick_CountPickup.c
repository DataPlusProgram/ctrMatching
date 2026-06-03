typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK ConvertRotToMatrix(); /* extern */
M2C_UNK MatrixRotate();       /* extern */

u16 D_8008D9A8;
extern void *gT;

void UI_ThTick_CountPickup(void *arg0)
{
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;
    void *temp_a0;

    temp_s2 = M2C_FIELD(arg0, void **, 0x30);
    temp_s1 = M2C_FIELD(arg0, void **, 0x34);

    temp_a0 = gT;
    M2C_FIELD(temp_s1, s32 *, 0x24) = 0xFFFF0000;

    if (M2C_FIELD(temp_a0, u8 *, 0x1CA8) == 1)
    {
        if (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x18), s16 *, 0x10) != 0x5C)
        {
            if (M2C_FIELD(M2C_FIELD(temp_a0, void **, 0x24EC), s8 *, 0x30) >= 0xA)
            {
                M2C_FIELD(temp_s1, s16 *, 0x22) = (s16)((D_8008D9A8 - 0x80) * 0x10);
            }
            else
            {
                M2C_FIELD(temp_s1, s16 *, 0x22) = 0;
            }

            goto block_5;
        }

        goto block_6;
    }

block_5:
    if (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x18), s16 *, 0x10) == 0x5C)
    {
block_6:
        M2C_FIELD(temp_s2, u16 *, 2) = (u16)(M2C_FIELD(temp_s2, u16 *, 2) + 0x40);
    }
    else
    {
        M2C_FIELD(temp_s2, u16 *, 2) = (u16)(M2C_FIELD(temp_s2, u16 *, 2) + 0x80);
    }

    temp_s0 = temp_s1 + 0x30;
    ConvertRotToMatrix(temp_s0, temp_s2);
    MatrixRotate(temp_s0, temp_s2 + 8, temp_s0);

    if ((M2C_FIELD(gT, s32 *, 0x1D30) & 0xFF0100) != 0x100)
    {
        M2C_FIELD(temp_s1, s32 *, 0x28) =
            M2C_FIELD(temp_s1, s32 *, 0x28) | 0x80;
    }
    else
    {
        M2C_FIELD(temp_s1, s32 *, 0x28) =
            M2C_FIELD(temp_s1, s32 *, 0x28) & ~0x80;
    }
}