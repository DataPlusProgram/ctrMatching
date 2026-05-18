typedef unsigned int undefined4;

extern char *D_8008D2AC;
extern char D_8008D528;

extern void DecalFont_DrawLine(char *str, int x, int y, int p4, int p5);
extern int sprintf(char *buf, const char *fmt, ...);

void UI_DrawNumRelic(int param_1, int param_2, int param_3)
{
    char acStack32[16];

    DecalFont_DrawLine(&D_8008D528, (param_1 + 0x14) * 0x10000 >> 0x10, (param_2 + -10) * 0x10000 >> 0x10, 2, 0);

    sprintf(acStack32, "%2.02d/%ld",
                  (int)*(signed char *)(param_3 + 0x32),
                  *(undefined4 *)(D_8008D2AC + 0x1E2C));

    DecalFont_DrawLine(acStack32, (param_1 + 0x21) * 0x10000 >> 0x10, (param_2 + -0xE) * 0x10000 >> 0x10, 1, 0);
}