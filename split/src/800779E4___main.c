typedef int s32;

typedef s32 M2C_UNK;

extern s32 D_8008C050;
extern M2C_UNK (*D_8008D668)();
extern s32 D_00000000;

void __main(void) {
    M2C_UNK (**varS0)();
    M2C_UNK (*tempT0)();
    s32 varS1;

    if (D_8008C050 == 0) {
        D_8008C050 = 1;
        varS0 = &D_8008D668;
        varS1 = D_00000000;

        if (varS1 != 0) {
            do {
                tempT0 = *varS0;
                varS0 += 1;
                varS1 -= 1;
                tempT0();
            } while (varS1 != 0);
        }
    }
}