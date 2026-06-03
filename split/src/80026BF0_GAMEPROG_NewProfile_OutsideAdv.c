typedef int s32;
typedef s32 M2C_UNK;

M2C_UNK GAMEPROG_ResetHighScores();
M2C_UNK memset();

void GAMEPROG_NewProfile_OutsideAdv(s32 arg0)
{
    s32 temp_s0;

    temp_s0 = arg0;

    memset(temp_s0, 0, 0x14BC);
    GAMEPROG_ResetHighScores(temp_s0);
}