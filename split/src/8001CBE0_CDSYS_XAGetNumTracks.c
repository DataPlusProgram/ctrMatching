typedef int s32;

s32 *D_8008D6E0;
s32 irqAddr;

s32 CDSYS_XAGetNumTracks(s32 arg0)
{
    if (irqAddr == 0)
    {
        return 0;
    }

    if (arg0 < 3)
    {
        return D_8008D6E0[arg0];
    }

    return 0;
}