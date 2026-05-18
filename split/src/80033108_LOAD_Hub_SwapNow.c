
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef s32 M2C_UNK;
M2C_UNK Audio_AdvHub_SwapSong();
M2C_UNK DecalGlobal_Store();
M2C_UNK INSTANCE_LevInitAll();
M2C_UNK LOAD_GlobalModelPtrs_MPK();
M2C_UNK LOAD_HubSwapPtrs();
M2C_UNK LOAD_NextQueuedFile();
M2C_UNK LevInstDef_RePack();
M2C_UNK LevInstDef_UnPack();
M2C_UNK LibraryOfModels_Clear();
M2C_UNK LibraryOfModels_Store();
M2C_UNK MEMPACK_SwapPacks();
M2C_UNK MainInit_VisMem();
M2C_UNK VSync();
extern void *D_8008D2AC;
extern s32 D_8008D870;
void LOAD_Hub_SwapNow(void)
{
  s16 temp_a0;
  s32 *temp_v0;
  s32 *temp_v0_2;
  void *new_var;
  if ((*((s32 *) (((s8 *) D_8008D2AC) + 0x164))) == 0)
  {
    do
    {
      LOAD_NextQueuedFile();
      VSync(0);
    }
    while ((*((s32 *) (((s8 *) D_8008D2AC) + 0x164))) == 0);
  }
  LevInstDef_RePack(*(*((s32 **) (((s8 *) D_8008D2AC) + 0x160))), 1);
  LOAD_HubSwapPtrs(D_8008D2AC, 1);
  *((u16 *) (((s8 *) D_8008D2AC) + 0x254A)) = (u16) (3 - (*((u16 *) (((s8 *) D_8008D2AC) + 0x254A))));
  *((s32 *) (((s8 *) D_8008D2AC) + 0x1EB4)) = (s32) (*((s32 *) (((s8 *) D_8008D2AC) + 0x1A10)));
  temp_a0 = *((s16 *) (((s8 *) (new_var = D_8008D2AC + (((s16) (*((u16 *) (((s8 *) D_8008D2AC) + 0x254A)))) * 2))) + 0x254C));
  *((s32 *) (((s8 *) D_8008D2AC) + 0x1A10)) = (s32) temp_a0;
  Audio_AdvHub_SwapSong(temp_a0);
  LibraryOfModels_Clear(D_8008D2AC);
  if (D_8008D870 != 0)
  {
    LOAD_GlobalModelPtrs_MPK();
  }
  temp_v0 = *((s32 **) (((s8 *) D_8008D2AC) + 0x160));
  if (temp_v0 != 0)
  {
    LibraryOfModels_Store(D_8008D2AC, *((s32 *) (((s8 *) temp_v0) + 0x14)), *((s32 *) (((s8 *) temp_v0) + 0x18)));
    temp_v0_2 = *((s32 **) (((s8 *) D_8008D2AC) + 0x160));
    temp_a0 = 0xC;
    INSTANCE_LevInitAll(*((s32 *) (((s8 *) temp_v0_2) + 0x10)), *((s32 *) (((s8 *) temp_v0_2) + temp_a0)));
    LevInstDef_UnPack(*(*((s32 **) (((s8 *) D_8008D2AC) + 0x160))));
    DecalGlobal_Store(D_8008D2AC, *((s32 *) (((s8 *) (*((s32 **) (((s8 *) D_8008D2AC) + 0x160)))) + 0x3C)));
  }
  MEMPACK_SwapPacks((s16) (*((u16 *) (((s8 *) D_8008D2AC) + 0x254A))));
  MainInit_VisMem(D_8008D2AC);
  *((s32 *) (((s8 *) D_8008D2AC) + 0x14B4)) = 0;
  *((s32 *) (((s8 *) D_8008D2AC) + 0x14C0)) = 0;
  *((s32 *) (((s8 *) D_8008D2AC) + 0x14B8)) = 0;
  *((s32 *) (((s8 *) D_8008D2AC) + 0x14BC)) = 0;
  *((s32 *) (((s8 *) D_8008D2AC) + 0x14C4)) = 0;
  *((s32 *) (((s8 *) D_8008D2AC) + 0x14C8)) = 0;
  *((s32 *) (((s8 *) (*((void **) (((s8 *) D_8008D2AC) + 0x1A38)))) + 0x40)) = 0;
  *((s32 *) (((s8 *) (*((void **) (((s8 *) D_8008D2AC) + 0x1A38)))) + 0x50)) = 0;
  *((s32 *) (((s8 *) (*((void **) (((s8 *) D_8008D2AC) + 0x1A38)))) + 0x60)) = 0;
  *((s32 *) (((s8 *) (*((void **) (((s8 *) D_8008D2AC) + 0x1A38)))) + 0x70)) = 0;
  *((s32 *) (((s8 *) (*((void **) (((s8 *) D_8008D2AC) + 0x24EC)))) + 0x350)) = 0;
  *((s32 *) (((s8 *) D_8008D2AC) + 0x1CFC)) = 0;
  *((s32 *) (((s8 *) D_8008D2AC) + 0x1D00)) = 0;
}
