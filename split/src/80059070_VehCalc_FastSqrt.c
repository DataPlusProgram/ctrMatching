typedef unsigned int u32;
typedef int s32;

u32 VehCalc_FastSqrt(u32 value, u32 shift)
{
    u32 result;
    u32 testBit;
    u32 bitShift;
    u32 base;
    u32 trial;
    u32 remainder;
    s32 signedShift;

    result = 0;
    base = 1 << shift;
    bitShift = 1;
    remainder = 0;

    while ((base < value) && ((base << 2) != 0))
    {
        bitShift++;
        base <<= 2;
    }

    signedShift = shift - 1;
    testBit = 1 << (bitShift + signedShift);

    while (base != 0)
    {
        trial = result << bitShift;
        if (((s32)bitShift) < 0)
        {
            trial = result >> -bitShift;
        }

        trial += remainder + base;

        if (trial <= value)
        {
            remainder = trial;
            result += testBit;
        }

        testBit >>= 1;
        base >>= 2;
        bitShift--;
    }

    return result;
}