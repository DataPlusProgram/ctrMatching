typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

typedef struct {
    char pad0[0x2A];
    s16 unk2A;
    char pad2C[0x2];
    s16 unk2E;
} M2cGAMEPROGNewProfileInsideAdvArg0;

M2C_UNK memset();                   /* extern */

void GAMEPROG_NewProfile_InsideAdv(M2cGAMEPROGNewProfileInsideAdvArg0 *arg0) {
    memset(arg0, 0, 0x50);
    arg0->unk2A = -1;
    arg0->unk2E = 0x1A;
}