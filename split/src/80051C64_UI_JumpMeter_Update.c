typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef s32 M2C_UNK;
M2C_UNK VehFire_Increment();
M2C_UNK Voiceline_RequestPlay();
extern s16 D_80086E84[];
extern void *D_8008D2AC;
void UI_JumpMeter_Update(void *arg0)
{
  s16 temp_v0_2;
  s16 temp_v1;
  s16 temp_v1_2;
  u16 temp_v0;
  if ((*((s32 *) (((s8 *) arg0) + 0x2C8))) & 0x80000)
  {
    if (((*((s16 *) (((s8 *) arg0) + 0x3FC))) >= 0x481) && ((*((s16 *) (((s8 *) arg0) + 0x46))) < 0x481))
    {
      Voiceline_RequestPlay(7, D_80086E84[*((u8 *) (((s8 *) arg0) + 0x4A))], 0x10);
    }
    temp_v0 = *((s16 *) (((s8 *) arg0) + 0x3FC));
    *((s16 *) (((s8 *) arg0) + 0x46)) = temp_v0;
    if (((s16) temp_v0) >= 0x961)
    {
      *((s16 *) (((s8 *) arg0) + 0x46)) = 0x960;
    }
    *((s16 *) (((s8 *) arg0) + 0x48)) = 0x5A0;
    return;
  }
  if ((*((s32 *) (((s8 *) arg0) + 0x2CC))) & 0x80000)
  {
    temp_v1 = *((s16 *) (((s8 *) arg0) + 0x46));
    if (temp_v1 >= 0x151)
    {
      *((s32 *) (((s8 *) arg0) + 0x53C)) = (*((s32 *) (((s8 *) arg0) + 0x53C))) + temp_v1;
    }
    temp_v1 = *((s16 *) (((s8 *) arg0) + 0x46));
    if (temp_v1 > (*((s16 *) (((s8 *) arg0) + 0x550))))
    {
      *((s16 *) (((s8 *) arg0) + 0x550)) = (u16) temp_v1;
    }
    temp_v1_2 = *((s16 *) (((s8 *) arg0) + 0x46));
    if (temp_v1_2 >= 0x5A0)
    {
      VehFire_Increment(arg0, 0x3C0, 2, 0x100);
      return;
    }
    if (temp_v1_2 >= 0x3C0)
    {
      VehFire_Increment(arg0, 0x3C0, 2, 0x80);
      return;
    }
    if (temp_v1_2 >= 0x280)
    {
      VehFire_Increment(arg0, 0x3C0, 2, 0);
    }
  }
  else
    if ((*((s16 *) (((s8 *) arg0) + 0x48))) != 0)
  {
    temp_v0_2 = ((u16) (*((s16 *) (((s8 *) arg0) + 0x48)))) - (*((u16 *) (((s8 *) D_8008D2AC) + 0x1D04)));
    *((s16 *) (((s8 *) arg0) + 0x48)) = temp_v0_2;
    if (temp_v0_2 < 0)
    {
      *((s16 *) (((s8 *) arg0) + 0x48)) = 0;
    }
  }
  else
  {
    *((s16 *) (((s8 *) arg0) + 0x46)) = 0;
  }
}
