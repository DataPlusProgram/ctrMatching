typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK LIST_AddFront();              /* extern */
M2C_UNK LIST_RemoveMember();          /* extern */
extern M2C_UNK Voiceline1;
extern M2C_UNK Voiceline2;

void Voiceline_StopAll(void)
{
    void *temp_a0;
    void *temp_s1;
    void *temp_s2;
    s32 temp_s0;

    temp_a0 = &Voiceline2;
    temp_s0 = M2C_FIELD(temp_a0, s32 *, 4);
    temp_s1 = temp_a0;

    if (temp_s0 != 0)
    {
        temp_s2 = &Voiceline1;

        do
        {
            LIST_RemoveMember(temp_s1, temp_s0);
            LIST_AddFront(temp_s2, temp_s0);

            temp_s0 = M2C_FIELD(temp_s1, s32 *, 4);
        } while (temp_s0 != 0);
    }
}