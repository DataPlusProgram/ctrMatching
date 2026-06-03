typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern u16 distortConst_Music[];
extern u16 noteFrequency[];

s32 howl_InstrumentPitch(s32 arg0, s32 arg1, s32 arg2)
{
    s32 temp_index;
    int new_var;
    u32 var_a0;

    temp_index = arg2 >> 6;
    temp_index -= 2;

    var_a0 = ((u32)(noteFrequency[arg1 + temp_index] * arg0)) >> 0xC;

    if ((arg2 & 0x3F) != 0)
    {
        new_var = distortConst_Music[arg2 & 0x3F] + 0x100000;
        var_a0 = ((u32)((var_a0 & 0xFFFF) * new_var)) >> 0x14;
    }

    return var_a0 & 0xFFFF;
}