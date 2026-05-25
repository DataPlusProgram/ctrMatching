typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;
typedef struct 
{
  char pad0[0x36];
  u8 unk36;
  char pad37[0x291];
  s32 unk2C8;
  char pad2CC[0x233];
  u8 unk4FF;
  s32 unk500;
  u8 unk504;
} M2cVehPickupItemShootOnCirclePressArg0;
M2C_UNK VehPickState_NewState();
M2C_UNK VehPickupItem_ShootNow();
void VehPickupItem_ShootOnCirclePress(M2cVehPickupItemShootOnCirclePressArg0 *arg0)
{

  s32 tempV1;
  s32 itemType;
  unsigned short varA1;
  u8 *itemTypePtr;
  if (arg0->unk4FF != 0)
  {
    VehPickState_NewState(arg0, arg0->unk4FF, arg0->unk500, arg0->unk504);
  }

  tempV1 = arg0->unk2C8;
  if (tempV1 & 0x8000)
  {
    arg0->unk2C8 = tempV1 & 0xFFFF7FFF;

    itemTypePtr = &arg0->unk36;
    itemType = *itemTypePtr;
    varA1 = 1;
    if (itemType != 10)
    {
      varA1 = 2;
      if (itemType != 11)
      {
        varA1 = *itemTypePtr;
      }
    }
    if (varA1 == 1)
    {
      varA1 = 2;
    }

    VehPickupItem_ShootNow(arg0, varA1, 0);
  }
}

