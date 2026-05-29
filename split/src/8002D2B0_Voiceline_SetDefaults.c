typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK Music_SetDefaults();                        /* extern */
s16 D_8008D806;
s16 D_8008D80E;
extern s8 WrongWayDirection_bool;
s32 bankLoad54;
s16 bankPodiumStage;
s8 cseqHighestIndex;
extern s32 framesDrivingSameDirection;

void Voiceline_SetDefaults(void) {
    bankPodiumStage = 0;
    bankLoad54 = 0;
    D_8008D806 = 0;
    WrongWayDirection_bool = 0;
    framesDrivingSameDirection = 0;
    D_8008D80E = 0;
    cseqHighestIndex = 0;
    Music_SetDefaults();
}