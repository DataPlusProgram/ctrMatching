
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
typedef s32 M2C_UNK;
s32 MEMPACK_AllocMem();
extern M2C_UNK D_8008D2C0;
void MainDB_OTMem(void *arg0, u32 arg1)
{
  u32 tempS0;
  void *tempS1;
  s32 tempV0;
  tempS0 = arg1;
  tempS1 = arg0;
  *((u32 *) (((s8 *) tempS1) + 0)) = arg1;
  tempV0 = MEMPACK_AllocMem(tempS0, &D_8008D2C0);
  tempS0 = tempS0 >> 2;
  tempS0 = tempS0 << 2;
  *((s32 *) (((s8 *) tempS1) + 0xC)) = tempV0;
  *((s32 *) (((s8 *) tempS1) + 4)) = tempV0;
  *((s32 *) (((s8 *) tempS1) + 8)) = tempV0 + tempS0;
}
