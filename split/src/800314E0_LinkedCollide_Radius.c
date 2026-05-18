
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef struct 
{
  char pad0[0x18];
  void *unk18;
  char pad1C[0x28];
  s32 unk44;
  s32 unk48;
  s32 unk4C;
} M2cLinkedCollideRadiusArg0;
void *LinkedCollide_Radius(M2cLinkedCollideRadiusArg0 *arg0, s32 arg1, void *arg2, u32 arg3)
{
  void *current;
  void *tempT0;
  s32 baseX;
  s32 baseZ;
  void *typePtr;
  s32 baseY;
  s32 typeConst;
  s16 type;
  s32 rawX;
  s32 rawY;
  s32 rawZ;
  s32 deltaX;
  s32 deltaY;
  s32 deltaZ;
  current = arg2;
  if (current != 0)
  {
    typeConst = 0x21;
    baseX = arg0->unk44;
    baseZ = arg0->unk4C;
    typePtr = arg0->unk18;
    baseY = arg0->unk48;
    type = *((s16 *) (((s8 *) typePtr) + 0x10));
    do
    {
      tempT0 = *((void **) (((s8 *) current) + 0x34));
      rawX = *((s32 *) (((s8 *) tempT0) + 0x44));
      rawY = *((s32 *) (((s8 *) tempT0) + 0x48));
      deltaX = rawX - baseX;
      rawZ = *((s32 *) (((s8 *) tempT0) + 0x4C));
      deltaZ = rawZ - baseZ;
      deltaY = rawY - baseY;
      if (type == typeConst)
      {
        if (((u32) ((deltaX * deltaX) + (deltaZ * deltaZ))) < arg3)
        {
          if (deltaY >= (-0x1F))
          {
            return tempT0;
          }
        }
      }
      else
        if (((u32) (((deltaX * deltaX) + (deltaZ * deltaZ)) + (deltaY * deltaY))) < arg3)
      {
        return tempT0;
      }
      current = *((void **) (((s8 *) current) + 0x10));
    }
    while (current != 0);
  }
  return 0;
}
