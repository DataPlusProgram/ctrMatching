typedef int s32;

s32 MEMCARD_CRC16(s32 arg0, s32 arg1)
{
    s32 bit;
    s32 counter = 7;
    s32 mask = 0x10000;
    s32 poly = 0x11021;

    do {
        arg0 <<= 1;
        bit = (arg1 >> counter) & 1;
        arg0 |= bit;

        if (arg0 & mask) {
            arg0 ^= poly;
        }

        counter--;
    } while (counter >= 0);

    return arg0;
}