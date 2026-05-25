typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK Audio_SetState();                        /* extern */
M2C_UNK Voiceline_EmptyFunc();                   /* extern */
s16 bankPodiumStage;

void Audio_SetState_Safe(s32 arg0) {
    if (arg0 != bankPodiumStage) {
        Voiceline_EmptyFunc(bankPodiumStage);
        Audio_SetState(arg0);
        bankPodiumStage = arg0;
    }
}