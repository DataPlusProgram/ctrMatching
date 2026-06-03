#include "../../common.h"

typedef unsigned int uint;
typedef unsigned short ushort;
typedef u8 undefined;
typedef s16 undefined2;
typedef s32 undefined4;

typedef struct {
	u16 unk0;
	char pad2[0x2];
	u32 unk4;
} M2cUIVsQuipAssignArg1;

s32 MixRNG_Scramble();                           /* extern */


void UI_VsQuipAssign(Driver *driver, uint *param_2, int param_3, undefined4 param_4)

{
  int iVar3;
  int iVar6;
  int iVar7;
  uint uVar4;
  uint uVar5;
  
  if ((driver != 0) && (((*(ushort *)((int)param_2 + 10) & 4) == 0 || ((int)driver == param_3)))) {
    uVar5 = *param_2;
    uVar4 = uVar5 + 8;
    if (uVar4 < param_2[1]) {
      do {
        iVar3 = *(int *)(uVar4 + 4);
        iVar6 = *(int *)(uVar5 + 4);
        if ((iVar6 < iVar3) ||
           ((iVar3 == iVar6 &&
            (iVar7 = MixRNG_Scramble(), (iVar7 >> 3 & 0xff) < 0x40)))) {
          uVar5 = uVar4;
        }
        uVar4 = uVar4 + 8;
      } while (uVar4 < param_2[1]);
    }
    if (driver->endOfRaceCommentPtrQuip != 0) {
      iVar3 = *(int *)(uVar5 + 4);
      iVar6 = *(int *)(driver->endOfRaceCommentPtrQuip + 2);
      if (iVar3 <= iVar6) {
        if (iVar3 != iVar6) {
          return;
        }
      iVar3 = MixRNG_Scramble();
      if (0x3f < (iVar3 >> 3 & 0xff)) {
        return;
      }
      }
      iVar3 = (int)driver->endOfRaceCommentPtrQuip;
      if ((iVar3 != 0) && (*(int *)(iVar3 + 4) < 0)) {
        *(int *)(iVar3 + 4) = -*(int *)(iVar3 + 4);
      }
    }
    if (0 < *(int *)(uVar5 + 4)) {
      *(int *)(uVar5 + 4) = -*(int *)(uVar5 + 4);
    }
    driver->endOfRaceCommentPtrQuip = (s16 *)uVar5;
    driver->endOfRaceCommentCharacterId = param_4;
    iVar3 = 0x96;
    if ((gT->gameMode1 & 0x20) == 0) {
      iVar3 = 300;
    }
    gT->timerEndOfRaceVS = iVar3;
  }
  return;
}
