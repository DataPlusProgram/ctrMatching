typedef short s16;
typedef int s32;

extern s32 p1_Min1s[];
extern s32 p1_Ms10s[];
extern s32 p1_Ms1s[];
extern s32 p1_Sec10s[];
extern s32 p1_Sec1s[];

void UI_SaveLapTime(s32 arg0, s32 arg1, s16 arg2)
{
    s32 *base_v1;
    s32 *temp_v1;
    s32 *sec1Ptr;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    unsigned int temp_t1;

    base_v1 = p1_Min1s;
    temp_t1 = (arg2 * 7) + arg0;
    temp_v1 = base_v1 + temp_t1;

    temp_a1 = arg1 / 57600;
    *temp_v1 = temp_a1;

    if (temp_a1 >= 10)
    {
        *temp_v1 = 9;
        p1_Sec10s[temp_t1] = 5;
        p1_Sec1s[temp_t1] = 9;
        p1_Ms10s[temp_t1] = 9;
        p1_Ms1s[temp_t1] = 9;
        return;
    }

    temp_a2 = arg1 / 9600;
    p1_Sec10s[temp_t1] = temp_a2 - (temp_a1 * 6);

    sec1Ptr = p1_Sec1s + temp_t1;

    temp_a1_2 = arg1 / 960;
    *sec1Ptr = temp_a1_2 - (temp_a2 * 10);

    p1_Ms10s[temp_t1] = (arg1 / 96) - (temp_a1_2 * 10);
    p1_Ms1s[temp_t1] = ((arg1 * 100) / 960) % 10;
}