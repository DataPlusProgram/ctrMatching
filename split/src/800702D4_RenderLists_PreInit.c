typedef signed char s8;
typedef int s32;

extern s32 D_8008A408;

void RenderLists_PreInit(void)
{
    s8 *base;
    s32 *varT1;
    s32 varT2;
    s32 *varT0;
    s32 tempV1;

    base = (s8 *)0x1F800000;
    varT1 = (s32 *)(base + 0x84);
    varT2 = 7;
    varT0 = &D_8008A408;

    do {
        tempV1 = *varT0;
        varT0 += 1;
        *varT1 = tempV1;
        varT1 += 1;
        varT2 -= 1;
    } while (varT2 != 0);
}