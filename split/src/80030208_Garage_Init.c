typedef signed char s8;
typedef short s16;
typedef int s32;

void howl_StopAudio();

extern s8 garageSoundPool[];

void Garage_Init(void)
{
    s8 *var_v1;
    s32 var_a0;
    s32 var_a1;

    howl_StopAudio(1, 0, 1);

    var_a0 = 0;
    var_a1 = 3;
    var_v1 = garageSoundPool;

    do {
        *(s8 *)(var_v1 + 0) = var_a1;
        *(s8 *)(var_v1 + 1) = var_a1;
        *(s16 *)(var_v1 + 2) = 0;
        *(s16 *)(var_v1 + 4) = 0;
        *(s32 *)(var_v1 + 8) = 0;
        var_a0 += 1;
        var_v1 += 12;
    } while (var_a0 < 8);
}