typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

s32 Bank_AssignSpuAddrs();                          /* extern */
M2C_UNK Bank_Load();              /* extern */
s32 howl_LoadSong();                                /* extern */
M2C_UNK howl_SetSong();                      /* extern */
s8 D_8008D848;

void Music_SetIntro(void) {
    M2C_UNK sp10;

    D_8008D848 = 0;
    Bank_Load(0x21, &sp10);
    do {

    } while (Bank_AssignSpuAddrs() == 0);
    howl_SetSong(0x1C);
    do {

    } while (howl_LoadSong() == 0);
}