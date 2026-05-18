typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern s16 D_80080EE0[];

s16 BOTS_Adv_NumTimesLostEvent(s32 arg0)
{
    if ((u32)(arg0 & 0xFFFF) >= 11) {
        arg0 = 10;
    }

    return D_80080EE0[(s16)arg0];
}