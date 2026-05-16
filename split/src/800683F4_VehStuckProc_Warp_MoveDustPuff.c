typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;


extern uint MixRNG_Scramble(void);


void VehStuckProc_Warp_MoveDustPuff(short *param_1, int param_2, int param_3, short *param_4)
{
  uint uVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iHalf;

  uVar1 = MixRNG_Scramble();
  iHalf = param_3 >> 1;
  iVar5 = (int)((uVar1 & 0xfff) * param_3) >> 0xc;
  if (iVar5 < iHalf) {
    iVar5 = iVar5 - param_3;
  }
  uVar1 = MixRNG_Scramble();
  iVar7 = (int)((uVar1 & 0xfff) * param_3) >> 0xc;
  if (iVar7 < iHalf) {
    iVar7 = iVar7 - param_3;
  }
  uVar1 = MixRNG_Scramble();
  iVar3 = (int)((uVar1 & 0xfff) * param_3) >> 0xc;
  if (iVar3 < iHalf) {
    iVar3 = iVar3 - param_3;
  }
  psVar2 = param_1 + param_2 * 4;
  iVar4 = param_2 >> 1;
  psVar6 = param_1 + iVar4 * 4;
  *psVar6 = (short)((int)*param_1 + (int)*psVar2 >> 1) + (short)(*param_4 * iVar5 >> 0xc);
  psVar6[1] = (short)((int)param_1[1] + (int)psVar2[1] >> 1) + (short)(param_4[1] * iVar7 >> 0xc);
  psVar6[2] = (short)((int)param_1[2] + (int)psVar2[2] >> 1) + (short)(param_4[2] * iVar3 >> 0xc);
  if (2 < param_2) {
    VehStuckProc_Warp_MoveDustPuff(param_1, iVar4, (int)(param_3 * 0xc00) >> 0xc, param_4);
    VehStuckProc_Warp_MoveDustPuff(psVar6, iVar4, (int)(param_3 * 0xc00) >> 0xc, param_4);
  }
  return;
}
