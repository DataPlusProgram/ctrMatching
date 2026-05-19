typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK CdControl();
M2C_UNK CdIntToPos();
M2C_UNK CdRead();
s32 CdReadSync();

s32 CdSearchFile_Unknown_80072BB4(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK sp10[2];
    s32 zero;

    zero = 0;

    CdIntToPos(arg1, sp10);
    CdControl(2, sp10, zero);
    CdRead(arg0, arg2, 0x80);

    return CdReadSync(0, zero) == 0;
}