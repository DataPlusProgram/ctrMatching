typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
} M2cRngDeadCoedArg0;

void RngDeadCoed(M2cRngDeadCoedArg0 *arg0) {
    u32 oldHi;
    u32 oldLo;
    u32 shiftedHi;
    u32 newLo;
    u32 carryMix;
    u32 xorConst;

    oldHi = arg0->unk4;
    oldLo = arg0->unk0;

    shiftedHi = oldHi >> 8;
    carryMix = oldLo + shiftedHi;

    newLo = (oldLo >> 8) | (oldHi << 24);
    carryMix += newLo >> 8;

    shiftedHi |= carryMix << 24;

    xorConst = 0xDEADC0ED;
    arg0->unk4 = shiftedHi ^ xorConst;
    arg0->unk0 = newLo;
}