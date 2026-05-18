
typedef signed char s8;
typedef short s16;
typedef int s32;
s32 MixRNG_Scramble(void);
void Particle_FuncPtr_SpitTire(void *arg0)
{
  s32 tempRet;
  s32 tempRet2;
  s32 tempV1;
  s32 varV0;
  s32 nextState;
  if (((*((s32 *) (((s8 *) arg0) + 0x2C))) >> 8) < ((*((s32 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0x20)))) + 0x48))) + 0x10))
  {
    tempRet = MixRNG_Scramble();
    *((s16 *) (((s8 *) arg0) + 0x28)) = (s16) ((tempRet % 5696) - 0xB20);
    tempRet2 = MixRNG_Scramble();
    *((s16 *) (((s8 *) arg0) + 0x38)) = (s16) ((tempRet2 % 5696) - 0xB20);
    tempV1 = *((s32 *) (((s8 *) arg0) + 0x4C));
    if (tempV1 == 0x1000)
    {
      *((s16 *) (((s8 *) arg0) + 0x30)) = (s16) ((MixRNG_Scramble() % 4800) + 0x1900);
      varV0 = *((s32 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0x20)))) + 0x48));
      nextState = 0xFFF;
      *((s32 *) (((s8 *) arg0) + 0x4C)) = nextState;
      *((s32 *) (((s8 *) arg0) + 0x2C)) = (varV0 + 0x10) << 8;
    }
    else
      if (tempV1 == 0xFFF)
    {
      *((s16 *) (((s8 *) arg0) + 0x30)) = (s16) ((MixRNG_Scramble() % 800) + 0x1F40);
      varV0 = *((s32 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0x20)))) + 0x48));
      nextState = 0xFFE;
      *((s32 *) (((s8 *) arg0) + 0x4C)) = nextState;
      *((s32 *) (((s8 *) arg0) + 0x2C)) = (varV0 + 0x10) << 8;
    }
    else
      if (tempV1 == 0xFFE)
    {
      *((s16 *) (((s8 *) arg0) + 0x30)) = (s16) ((MixRNG_Scramble() % 800) + 0x1770);
      nextState = -0x7FF;
      varV0 = *((s32 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0x20)))) + 0x48));
      *((s16 *) (((s8 *) arg0) + 0x50)) = nextState;
      *((s32 *) (((s8 *) arg0) + 0x2C)) = (varV0 + 0x10) << 8;
    }
  }
}
