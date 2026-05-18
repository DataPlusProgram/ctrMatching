typedef int s32;
typedef short s16;

s16 DecalFont_GetLineWidthStrlen();

s16 DecalFont_GetLineWidth(s32 arg0, s16 arg1)
{
    return DecalFont_GetLineWidthStrlen(arg0, -1, arg1);
}