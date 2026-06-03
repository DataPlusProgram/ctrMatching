typedef int s32;

s32 GetRCnt(); /* extern */
s32 D_8008D99C;

s32 Timer_GetTime_Total(void)
{
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = D_8008D99C;
    temp_v0 = GetRCnt(0xF2000001);

    temp_s0 += temp_v0;

    if (temp_v0 < 0x64)
    {
        temp_s0 = D_8008D99C;
        temp_s0 += temp_v0;
    }

    return (temp_s0 * 0x3E8) / 5246;
}