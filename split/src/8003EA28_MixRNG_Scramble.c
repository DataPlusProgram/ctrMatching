typedef int s32;

s32 battleSetup_Color_UI_1;

void MixRNG_Scramble(void) {
    battleSetup_Color_UI_1 = ((battleSetup_Color_UI_1 * 0x6255) + 0x3619) & 0xFFFF;
}