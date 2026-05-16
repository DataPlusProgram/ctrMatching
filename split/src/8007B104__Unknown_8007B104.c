typedef int s32;

extern s32 *D_8008C3C8;

void _Unknown_8007B104(void) {
    *D_8008C3C8 = (*D_8008C3C8 & 0xF0FFFFFF) | 0x22000000;
}