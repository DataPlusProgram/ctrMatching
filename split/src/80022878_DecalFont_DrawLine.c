typedef short s16;
typedef int s32;
typedef unsigned int u32;
void DecalFont_DrawLineStrlen();
void DecalFont_DrawLine(s32 arg0, s16 arg1, s16 arg2, s16 arg3, u32 arg4)
{
  u32 *arg4Ptr;
  s32 tempArg4;
  arg4Ptr = &arg4;
  tempArg4 = *arg4Ptr;
  tempArg4 <<= 0x10;
  
  DecalFont_DrawLineStrlen(arg0, -1, arg1, arg2, arg3, tempArg4 >> 0x10);
}
