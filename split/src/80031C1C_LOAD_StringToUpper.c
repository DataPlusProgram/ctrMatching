typedef unsigned char u8;
typedef unsigned int u32;

void LOAD_StringToUpper(u8 *arg0) {
    u8 varV1;

    varV1 = *arg0;
    if (varV1 != 0) {
        do {
            if ((u32)(varV1 - 0x61) < 0x1A) {
                *arg0 = varV1 + 0xE0;
            }

            arg0 += 1;
            varV1 = *arg0;
        } while (varV1 != 0);
    }
}