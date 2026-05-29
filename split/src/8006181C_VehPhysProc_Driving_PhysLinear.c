#include "../../common.h"

typedef unsigned char byte;
typedef unsigned char undefined1;
typedef char undefined;
typedef short undefined2;
typedef int undefined4;
typedef unsigned short ushort;
typedef unsigned int uint;

M2C_UNK GAMEPAD_ShockForce1(); /* extern */
M2C_UNK OtherFX_Play();             /* extern */
s16 VehCalc_InterpBySpeed();        /* extern */
s32 VehCalc_MapToRange(); /* extern */
M2C_UNK VehFire_Increment(); /* extern */
s16 VehPhysGeneral_GetBaseSpeed();            /* extern */
M2C_UNK VehPhysGeneral_SetHeldItem();         /* extern */
s8 VehPhysJoystick_GetStrengthAbsolute(); /* extern */
s32 VehPhysJoystick_ReturnToRest(); /* extern */
extern M2C_UNK D_800845A0;
extern GamepadSystem *D_8008D2B0;
extern GameTracker *gT;


void VehPhysProc_Driving_PhysLinear(Thread *thread, Driver *driver) {
  byte bVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  int bVar5;
  undefined *puVar6;
  undefined *puVar7;
  ushort uVar8;
  ushort uVar9;
  undefined2 uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  short sVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  undefined4 uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  uint sp18;
  uint sp1C;
  s8 *driverBytes;
  s8 *threadBytes;
  u8 *gTBytes;
  u8 *gamepadSystemBytes;

  driverBytes = (s8 *)driver;
  threadBytes = (s8 *)thread;
  gTBytes = (u8 *)gT;
  gamepadSystemBytes = (u8 *)D_8008D2B0;

  if ((*(uint *)(driverBytes + 0x2c8) & 0x40000) == 0) {
    *(undefined4 *)(driverBytes + 0x514) = *(undefined4 *)(gTBytes + 0x1d10);
  }
  iVar16 = *(int *)(gTBytes + 0x1d04);
  iVar11 = -iVar16;
  if ((*(int *)(gTBytes + 0x1d10) < 0x8ca00) && ((*(uint *)(driverBytes + 0x2c8) & 0x40000) == 0)) {
    *(int *)(driverBytes + 0x518) =
         *(int *)(driverBytes + 0x518) + (*(short *)(driverBytes + 0x38e) * iVar16 >> 8);
  }
  iVar13 = *(short *)(driverBytes + 0x3e2) + iVar11;
  if (0 < *(short *)(driverBytes + 0x3e2)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x3e2) = (short)iVar13;
    *(int *)(driverBytes + 0x534) = *(int *)(driverBytes + 0x534) + iVar16;
  }
  iVar13 = *(short *)(driverBytes + 0x3de) + iVar11;
  if (0 < *(short *)(driverBytes + 0x3de)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x3de) = (short)iVar13;
  }
  iVar13 = *(short *)(driverBytes + 0x3e0) + iVar11;
  if (0 < *(short *)(driverBytes + 0x3e0)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x3e0) = (short)iVar13;
  }
  iVar13 = *(short *)(driverBytes + 0x3fe) + iVar11;
  if (0 < *(short *)(driverBytes + 0x3fe)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x3fe) = (short)iVar13;
    *(int *)(driverBytes + 0x530) = *(int *)(driverBytes + 0x530) + iVar16;
  }
  iVar13 = *(short *)(driverBytes + 0x3f6) + iVar11;
  if (0 < *(short *)(driverBytes + 0x3f6)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x3f6) = (short)iVar13;
  }
  iVar13 = *(short *)(driverBytes + 0x3f2) + iVar11;
  if (0 < *(short *)(driverBytes + 0x3f2)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x3f2) = (short)iVar13;
  }
  iVar13 = *(short *)(driverBytes + 0x3fa) + iVar11;
  if (0 < *(short *)(driverBytes + 0x3fa)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x3fa) = (short)iVar13;
  }
  iVar13 = *(short *)(driverBytes + 0x402) + iVar11;
  if (0 < *(short *)(driverBytes + 0x402)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x402) = (short)iVar13;
    *(int *)(driverBytes + 0x54c) = *(int *)(driverBytes + 0x54c) + iVar16;
  }
  iVar13 = *(short *)(driverBytes + 0x404) + iVar11;
  if (0 < *(short *)(driverBytes + 0x404)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x404) = (short)iVar13;
    *(int *)(driverBytes + 0x544) = *(int *)(driverBytes + 0x544) + iVar16;
  }
  iVar13 = *(short *)(driverBytes + 0x406) + iVar11;
  if (0 < *(short *)(driverBytes + 0x406)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x406) = (short)iVar13;
  }
  iVar13 = *(short *)(driverBytes + 0x408) + iVar11;
  if (0 < *(short *)(driverBytes + 0x408)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x408) = (short)iVar13;
  }
  if (((*(uint *)(gTBytes + 8) & 0x10000) == 0) &&
     (iVar13 = *(short *)(driverBytes + 0x38) + iVar11, 0 < *(short *)(driverBytes + 0x38))) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x38) = (short)iVar13;
  }
  iVar13 = *(short *)(driverBytes + 0xc) + iVar11;
  if (0 < *(short *)(driverBytes + 0xc)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0xc) = (short)iVar13;
  }
  iVar13 = *(short *)(driverBytes + 0x3c0) + iVar11;
  if (0 < *(short *)(driverBytes + 0x3c0)) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    *(short *)(driverBytes + 0x3c0) = (short)iVar13;
  }
  if (0 < *(short *)(driverBytes + 0x3f0)) {
    *(short *)(driverBytes + 0x3f0) = *(short *)(driverBytes + 0x3f0) + -1;
  }
  if ('\t' < *(char *)(driverBytes + 0x30)) {
    *(int *)(driverBytes + 0x52c) = *(int *)(driverBytes + 0x52c) + iVar16;
  }
  if (*(char *)(driverBytes + 0xc2) == '\x0e') {
    *(int *)(driverBytes + 0x524) = *(int *)(driverBytes + 0x524) + iVar16;
  }
  sVar15 = *(short *)(driverBytes + 0x482);
  if (((((sVar15 == 7) && (gTBytes[0x1ca8] == '\x01')) ||
       ((sVar15 == 5 && (gTBytes[0x1ca8] == '\x02')))) ||
      ((sVar15 == 3 && (2 < (byte)gTBytes[0x1ca8])))) &&
     ((*(uint *)(driverBytes + 0x2c8) & 0x40000) == 0)) {
    *(int *)(driverBytes + 0x528) = *(int *)(driverBytes + 0x528) + iVar16;
  }
  sVar15 = 4;
  if (*(int *)(driverBytes + 0x4a0) != 0) {
    sVar15 = *(short *)(*(int *)(*(int *)(driverBytes + 0x4a0) + 0x30) + 6);
  }
  iVar13 = (int)*(short *)(driverBytes + 0x38e);
  uVar23 = *(uint *)(driverBytes + 0x2c8);
  iVar20 = (int)*(short *)(driverBytes + 0xc);
  *(short *)(driverBytes + 0x50a) = sVar15;
  if (iVar13 < 0) {
    iVar13 = -iVar13;
  }
  if (((iVar20 == 0) && (iVar20 = (int)*(short *)(driverBytes + 0x404), iVar20 == 0)) &&
     ((sVar15 != 0 || (iVar20 = *(int *)(gTBytes + 0x1d10), iVar20 == 0)))) {
    uVar21 = (uint)*(short *)(driverBytes + 0xe);
    if (0x100 < iVar13) {
      uVar21 = uVar21 + iVar11;
    }
    uVar21 = uVar21 & 0xfffffffe;
    if (-1 < (int)uVar21) {
      uVar21 = 0xfffffffe;
    }
    *(short *)(driverBytes + 0xe) = (short)uVar21;
  }
  else {
    if ((uVar23 & 1) == 0) {
      if (iVar13 < 0x101) goto LAB_80061cf8;
      if (iVar20 < 0) {
        iVar20 = -iVar20;
      }
      uVar9 = (ushort)iVar20;
LAB_80061d0c:
      uVar8 = -uVar9 | 1;
    }
    else if (iVar13 < 0x101) {
LAB_80061cf8:
      uVar9 = *(ushort *)(driverBytes + 0xe);
      uVar8 = uVar9 | 1;
      if (0 < (short)uVar9) goto LAB_80061d0c;
    }
    else {
      if (iVar20 < 0) {
        iVar20 = -iVar20;
      }
      iVar11 = (uint)*(ushort *)(driverBytes + 0xc) << 0x10;
      iVar18 = iVar11 >> 0x16;
      if (0x40 < iVar18) {
        iVar18 = 0x40;
      }
      uVar21 = (iVar11 >> 0x10) << 4;
      iVar11 = (&D_800845A0)[uVar21 & 0x3ff];
      if ((uVar21 & 0x400) == 0) {
        iVar11 = iVar11 << 0x10;
      }
      iVar11 = iVar11 >> 0x10;
      if ((uVar21 & 0x800) != 0) {
        iVar11 = -iVar11;
      }
      iVar22 = iVar13 >> 8;
      if (0x20 < iVar22) {
        iVar22 = 0x20;
      }
      GAMEPAD_ShockForce1(driverBytes,4,iVar18 + (iVar11 >> 5) + iVar22 + 0x18);
      uVar8 = (ushort)iVar20 | 1;
    }
    *(ushort *)(driverBytes + 0xe) = uVar8;
  }
  if (*(char *)(driverBytes + 0x36) == '\x10') {
    if (*(short *)(driverBytes + 0x3a) == 0) {
      VehPhysGeneral_SetHeldItem(driverBytes);
      bVar5 = '\t' < *(char *)(driverBytes + 0x30);
      uVar19 = 0x5e;
      if (bVar5) {
        uVar19 = 0x41;
      }
      OtherFX_Play(uVar19,bVar5);
    }
    else {
      *(short *)(driverBytes + 0x3a) = *(short *)(driverBytes + 0x3a) + -1;
    }
  }
  sVar4 = *(short *)(driverBytes + 0x3c);
  if (sVar4 != 0) {
    if ((sVar4 == 1) && (*(char *)(driverBytes + 0x37) == '\0')) {
      if ((2 < (byte)gTBytes[0x1ca8]) &&
         ((((*(uint *)gTBytes & 0x20) == 0 && (*(char *)(driverBytes + 0x36) == '\v')) &&
          (0 < *(int *)(gTBytes + 0x1ec4))))) {
        *(int *)(gTBytes + 0x1ec4) = *(int *)(gTBytes + 0x1ec4) + -1;
      }
      *(undefined1 *)(driverBytes + 0x36) = 0xf;
    }
    *(short *)(driverBytes + 0x3c) = sVar4 + -1;
  }
  if ((*(int *)(driverBytes + 0x24) != 0) &&
     (iVar11 = *(int *)(driverBytes + 0x24) - *(int *)(gTBytes + 0x1d04),
     *(int *)(driverBytes + 0x24) = iVar11, iVar11 < 0)) {
    *(undefined4 *)(driverBytes + 0x24) = 0;
  }
  if ((*(int *)(driverBytes + 0x28) != 0) && ((*(uint *)(gTBytes + 8) & 0x8000) == 0)) {
    iVar11 = *(int *)(driverBytes + 0x28) - *(int *)(gTBytes + 0x1d04);
    *(int *)(driverBytes + 0x28) = iVar11;
    if (iVar11 < 0) {
      *(undefined4 *)(driverBytes + 0x28) = 0;
    }
    if (*(int *)(driverBytes + 0x28) == 0) {
      *(undefined4 *)(*(int *)(driverBytes + 0x1c) + 0x28) = *(undefined4 *)(driverBytes + 0x2c);
      *(undefined2 *)(*(int *)(driverBytes + 0x1c) + 0x22) = 0;
      OtherFX_Play(0x62,1);
    }
  }
  *(undefined4 *)(driverBytes + 0x2f4) = *(undefined4 *)(driverBytes + 0x2ec);
  puVar6 = gTBytes;
  *(uint *)(driverBytes + 0x2cc) = uVar23;
  *(undefined4 *)(driverBytes + 0x2e4) = *(undefined4 *)(driverBytes + 0x2d8);
  *(undefined4 *)(driverBytes + 0x2e8) = *(undefined4 *)(driverBytes + 0x2dc);
  *(undefined2 *)(driverBytes + 0x2f8) = *(undefined2 *)(driverBytes + 0x2f0);
  *(undefined2 *)(driverBytes + 0x392) = *(undefined2 *)(driverBytes + 0x390);
  *(undefined2 *)(driverBytes + 0x3c8) = *(undefined2 *)(driverBytes + 0x3c6);
  *(undefined4 *)(driverBytes + 0x2e0) = *(undefined4 *)(driverBytes + 0x2d4);
  uVar21 = uVar23 & 0x7f1f83d5;
  if ((*(uint *)(puVar6 + 8) & 0x4004) != 0) goto LAB_800629f8;
  iVar20 = *(byte *)(driverBytes + 0x380) + 1;
  iVar11 = iVar20 * 8;
  if (iVar20 != 0) {
    iVar11 = 0;
  }
  puVar14 = (undefined4 *)(driverBytes + iVar11 + 0x378);
  if ((uVar23 & 1) == 0) {
    *puVar14 = *(undefined4 *)(driverBytes + 0x368);
    *(undefined2 *)(puVar14 + 1) = *(undefined2 *)(driverBytes + 0x36c);
  }
  else {
    *puVar14 = *(undefined4 *)(driverBytes + 0x360);
    *(undefined2 *)(puVar14 + 1) = *(undefined2 *)(driverBytes + 0x364);
  }
  *(undefined1 *)(driverBytes + 0x380) = 0;
  puVar6 = gamepadSystemBytes;
  for (iVar11 = *(int *)(threadBytes + 0x14); uVar23 = uVar21, iVar11 != 0;
      iVar11 = *(int *)(iVar11 + 0x10)) {
    if ((*(short *)(iVar11 + 0x44) == 0x3a) || (*(short *)(iVar11 + 0x44) == 0x39)) {
      uVar23 = uVar21 | 0x800000;
      break;
    }
  }
  bVar1 = *(byte *)(driverBytes + 0x4a);
  uVar21 = 0;
  if ((*(uint *)gTBytes & 0x200000) == 0) {
    uVar21 = *(uint *)(gamepadSystemBytes + (uint)bVar1 * 0x50 + 0x10);
  }
  uVar17 = 0;
  if ((*(uint *)gTBytes & 0x200000) == 0) {
    uVar17 = *(uint *)(gamepadSystemBytes + (uint)bVar1 * 0x50 + 0x14);
  }
  sp18 = uVar21 & 0x10;
  sp1C = uVar21 & 0x20;
  cVar2 = *(char *)(driverBytes + 0x376);
  if ((((uVar17 & 0x40) != 0) && (((cVar2 == '\0' || (cVar2 == '\x02')) || (cVar2 == '\t')))) &&
     (*(int *)(driverBytes + 0x18) == 0)) {
    if (*(int *)(driverBytes + 0x10) == 0) {
      if (*(int *)(driverBytes + 0x14) == 0) {
        sVar4 = *(short *)(driverBytes + 0x3a);
        if (sVar4 == 0) {
          cVar3 = *(char *)(driverBytes + 0x36);
          if (((cVar3 != '\x0f') && (cVar3 != '\x10')) &&
             ((*(short *)(driverBytes + 0x3c) == 0 &&
              ((sVar15 != 1 && (*(short *)(driverBytes + 0xc) == 0)))))) {
            uVar23 = uVar23 | 0x8000;
            if (*(char *)(driverBytes + 0x37) == '\0') {
              *(undefined2 *)(driverBytes + 0x3c) = 0x1e;
              goto LAB_800621cc;
            }
            if (cVar3 == '\x05') {
              if (*(short *)(driverBytes + 0x3f4) != 0) {
                uVar12 = (uint)*(short *)(driverBytes + 0x3f2);
                goto LAB_80062188;
              }
            }
            else {
              uVar12 = *(uint *)(gTBytes + 8) & 0x400c00;
LAB_80062188:
              if (uVar12 == 0) {
                *(char *)(driverBytes + 0x37) = *(char *)(driverBytes + 0x37) + -1;
              }
            }
            *(undefined2 *)(driverBytes + 0x3c) = 5;
            goto LAB_800621cc;
          }
          sVar4 = *(short *)(driverBytes + 0x3a);
        }
        if (sVar4 < 0x46) {
          *(undefined2 *)(driverBytes + 0x3a) = 0;
        }
      }
      else {
        iVar11 = *(int *)(*(int *)(*(int *)(driverBytes + 0x14) + 0x6c) + 0x30);
        *(ushort *)(iVar11 + 6) = *(ushort *)(iVar11 + 6) | 2;
        *(undefined4 *)(driverBytes + 0x14) = 0;
      }
    }
    else {
      iVar11 = *(int *)(*(int *)(*(int *)(driverBytes + 0x10) + 0x6c) + 0x30);
      *(ushort *)(iVar11 + 0x16) = *(ushort *)(iVar11 + 0x16) | 2;
      *(undefined4 *)(driverBytes + 0x10) = 0;
    }
  }
LAB_800621cc:
  uVar17 = uVar17 & 0xc00;
  if ((uVar17 == 0) || (*(char *)(driverBytes + 0x376) == '\x02')) {
    if (((uVar21 & 0xc00) != 0) && (sVar15 != 3)) {
      if ((uVar23 & 4) == 0) {
        *(undefined2 *)(driverBytes + 0x3f0) = 10;
      }
      goto LAB_8006222c;
    }
    uVar23 = uVar23 & 0xfffffffb;
    if (0 < *(short *)(driverBytes + 0x3f0)) {
      *(undefined2 *)(driverBytes + 0x3f0) = 0;
    }
  }
  else {
    if (uVar17 == 0xc00) {
      *(undefined2 *)(driverBytes + 0x382) = 0x400;
    }
    else {
      *(short *)(driverBytes + 0x382) = (short)uVar17;
    }
    if (sVar15 != 3) {
      *(undefined2 *)(driverBytes + 0x3f0) = 10;
LAB_8006222c:
      uVar23 = uVar23 | 4;
    }
  }
  if ((sp1C != 0) && ((*(uint *)(driverBytes + 0xbc) & 3) == 0)) {
    *(undefined2 *)(driverBytes + 0x3e2) = 0;
  }
  iVar11 = 0x80;
  if ((*(uint *)gTBytes & 0x200000) == 0) {
    iVar11 = (int)*(short *)(puVar6 + (uint)bVar1 * 0x50 + 0xe);
  }
  if ((*(short *)(driverBytes + 0x3e2) != 0) || (sVar15 == 6)) {
    if ((sp18 == 0) && (iVar20 = VehPhysJoystick_ReturnToRest(iVar11,0x80,0), -iVar20 < 1)) {
      uVar23 = uVar23 | 0x400000;
    }
    if ((sp1C != 0) && (0x300 < iVar13)) {
      uVar23 = uVar23 | 0x800;
    }
    if ((*(uint *)(driverBytes + 0xbc) & 3) != 0) {
      sp1C = 0;
    }
    sp18 = 0x10;
  }
  iVar20 = 0x80;
  if ((*(uint *)gTBytes & 0x200000) == 0) {
    iVar20 = (int)*(short *)(puVar6 + (uint)bVar1 * 0x50 + 6);
  }
  if ((*(char *)(driverBytes + 0x4b) < '\0') ||
     (uVar23 = uVar23 & 0xdfffffff, *(char *)(driverBytes + 0x4b) < '\x01')) {
    uVar23 = uVar23 & 0xbfffffff;
  }
  iVar18 = (int)*(short *)(driverBytes + 0x38e);
  if (iVar18 < 0) {
    iVar18 = -iVar18;
  }
  if (iVar18 < 0x300) {
    uVar23 = uVar23 & 0x9fffffff;
  }
  iVar18 = 0;
  iVar22 = VehPhysGeneral_GetBaseSpeed(driverBytes);
  if (sp1C == 0) {
    iVar24 = iVar22;
    if (sp18 != 0) {
LAB_8006253c:
      uVar23 = uVar23 & 0xfffdffff;
      goto LAB_80062548;
    }
    iVar11 = VehPhysJoystick_ReturnToRest(iVar11,0x80,0);
    iVar11 = -iVar11;
    if (-1 < iVar11) {
      if ((iVar11 == 0) &&
         ((iVar20 = VehPhysJoystick_ReturnToRest(iVar20,0x80,0), 99 < iVar20 ||
          ((0 < iVar20 && ((uVar23 & 0x20000) != 0)))))) {
        uVar23 = uVar23 | 0x20000;
        iVar24 = -(int)*(short *)(driverBytes + 0x434);
        goto LAB_80062548;
      }
      iVar11 = iVar22 * iVar11;
      iVar24 = iVar11 >> 7;
      if (iVar11 < 0) {
        iVar24 = iVar11 + 0x7f >> 7;
      }
      goto LAB_8006253c;
    }
    if ((*(short *)(driverBytes + 0x38e) < 0x301) && ((uVar23 & 0x60000000) == 0)) {
      iVar11 = *(short *)(driverBytes + 0x434) * iVar11;
      if (iVar11 < 0) {
        iVar11 = iVar11 + 0x7f;
      }
      iVar18 = iVar11 >> 7;
      uVar17 = 0x20000;
LAB_800625c4:
      uVar21 = uVar23 | uVar17;
    }
    else {
      uVar21 = uVar23 | 8;
      if ('\0' < *(char *)(driverBytes + 0x4b)) {
        uVar21 = uVar23 | 0x40000008;
      }
      if (*(char *)(driverBytes + 0x4b) < '\0') {
        uVar17 = 0x20000000;
        uVar23 = uVar21;
        goto LAB_800625c4;
      }
    }
  }
  else {
    iVar20 = VehPhysJoystick_ReturnToRest(iVar20,0x80,0);
    if ((iVar20 < 100) && ((iVar20 < 1 || ((uVar23 & 0x20000) == 0)))) {
      if (sp18 == 0) {
        iVar11 = VehPhysJoystick_ReturnToRest(iVar11,0x80,0);
        iVar11 = -iVar11;
        iVar24 = iVar22 * iVar11;
        if (0 < iVar11) {
          if (iVar24 < 0) {
            iVar24 = iVar24 + 0xff;
          }
          iVar24 = iVar24 >> 8;
          uVar23 = uVar23 | 0x20;
          goto LAB_80062548;
        }
        if (iVar11 < 0) {
          iVar11 = *(short *)(driverBytes + 0x434) * iVar11;
          iVar24 = iVar11 >> 8;
          if (iVar11 < 0) {
            iVar24 = iVar11 + 0xff >> 8;
          }
          goto LAB_8006248c;
        }
        uVar23 = uVar23 | 8;
        iVar24 = iVar18;
      }
      else {
        uVar23 = uVar23 | 0x20;
        iVar24 = iVar22 / 2;
      }
      goto LAB_8006253c;
    }
    iVar11 = *(short *)(driverBytes + 0x434) * -3;
    iVar24 = iVar11 >> 2;
    if (iVar11 < 0) {
      iVar24 = iVar11 + 3 >> 2;
    }
LAB_8006248c:
    uVar23 = uVar23 | 0x20020;
LAB_80062548:
    uVar21 = uVar23 & 0x9fffffff;
    iVar18 = iVar24;
  }
  if ((uVar21 & 0x20000) == 0) {
    uVar23 = uVar21 & 8;
    if (*(short *)(driverBytes + 0x38) != 0) {
      if (0 < iVar18) {
        uVar23 = uVar21 & 8;
        if ((uVar21 & 0x400020) != 0) goto LAB_80062648;
        uVar19 = 0x80;
        *(uint *)(driverBytes + 0x2c8) = uVar21;
        if ('\t' < *(char *)(driverBytes + 0x30)) {
          uVar19 = 0x100;
        }
        VehFire_Increment(driverBytes,0x78,0x14,uVar19);
        uVar21 = *(uint *)(driverBytes + 0x2c8);
      }
      goto code_r0x80062644;
    }
  }
  else {
    *(int *)(driverBytes + 0x520) = *(int *)(driverBytes + 0x520) + iVar16;
code_r0x80062644:
    uVar23 = uVar21 & 8;
  }
LAB_80062648:
  if (uVar23 != 0) {
    iVar11 = (int)*(short *)(driverBytes + 0x38e);
    if (iVar11 < 0) {
      iVar11 = -iVar11;
    }
    if (0x300 < iVar11) {
      *(int *)(driverBytes + 0x51c) = *(int *)(driverBytes + 0x51c) + iVar16;
    }
  }
  if ((*(short *)(driverBytes + 0x3c0) == 0) ||
     ((*(char *)(driverBytes + 0x376) != '\0' && (*(char *)(driverBytes + 0x376) != '\t')))) {
    *(undefined2 *)(driverBytes + 0x3c2) = 0;
  }
  if (*(short *)(driverBytes + 0x39e) < 1) {
    if (0 < iVar18) goto LAB_800626d4;
LAB_800626fc:
    *(short *)(driverBytes + 0x39e) = (short)iVar18;
  }
  else {
    if (iVar18 < 1) {
LAB_800626d4:
      if (*(short *)(driverBytes + 0x3c0) != 0) {
        *(short *)(driverBytes + 0x3c2) = *(short *)(driverBytes + 0x3c2) + 1;
      }
      *(undefined2 *)(driverBytes + 0x3c0) = 0x100;
      goto LAB_800626fc;
    }
    *(short *)(driverBytes + 0x39e) = (short)iVar18;
  }
  puVar7 = gTBytes;
  if ((uVar21 & 0x800020) == 0) {
    iVar11 = *(int *)(*(int *)(driverBytes + 0x35c) + 8);
    if (iVar11 != 0x100) {
      iVar18 = iVar11 * iVar18 >> 8;
      iVar22 = iVar11 * iVar22 >> 8;
    }
  }
  *(short *)(driverBytes + 0x3c4) = (short)iVar22;
  *(short *)(driverBytes + 0x39c) = (short)iVar18;
  iVar11 = 0x80;
  if ((*(uint *)puVar7 & 0x200000) == 0) {
    iVar11 = (int)*(short *)(puVar6 + (uint)bVar1 * 0x50 + 4);
  }
  iVar16 = (uint)*(byte *)(driverBytes + 0x43a) + ((int)*(char *)(driverBytes + 0x34) << 1) / 5;
  if ((*(short *)(driverBytes + 0x3c2) < 7) || (0x25ff < iVar13)) {
    if (*(short *)(driverBytes + 0x3fe) == 0) {
      if ((uVar21 & 0x28) == 0) {
        uVar19 = *(undefined4 *)(puVar6 + (uint)bVar1 * 0x50 + 0x4c);
      }
      else if (sp18 == 0) {
        uVar19 = *(undefined4 *)(puVar6 + (uint)bVar1 * 0x50 + 0x4c);
        iVar16 = 0x40;
      }
      else {
        iVar20 = (int)*(short *)(driverBytes + 0x38c);
        if (iVar20 < 0) {
          iVar20 = -iVar20;
        }
        iVar16 = VehCalc_MapToRange(iVar20,0x300,
                                    (int)((uint)*(ushort *)(driverBytes + 0x42c) << 0x10) >> 0x11,0x40,
                                    iVar16);
        uVar19 = *(undefined4 *)(puVar6 + (uint)bVar1 * 0x50 + 0x4c);
      }
    }
    else {
      uVar19 = *(undefined4 *)(puVar6 + (uint)bVar1 * 0x50 + 0x4c);
      iVar16 = 0x30;
    }
  }
  else {
    uVar19 = *(undefined4 *)(puVar6 + (uint)bVar1 * 0x50 + 0x4c);
    iVar16 = 0x5a;
  }
  iVar16 = VehPhysJoystick_GetStrengthAbsolute(iVar11,iVar16,uVar19);
  iVar16 = -iVar16;
  if (iVar16 == 0) {
    *(undefined2 *)(driverBytes + 0x3e6) = 10000;
  }
  else {
    if ((iVar16 < 0) && (-1 < *(char *)(driverBytes + 0x4b))) {
      uVar21 = uVar21 & 0xffffffef;
    }
    else {
      if ((iVar16 < 1) || ('\0' < *(char *)(driverBytes + 0x4b))) goto LAB_800628b0;
      uVar21 = uVar21 | 0x10;
    }
    *(undefined2 *)(driverBytes + 0x3e6) = 0;
  }
LAB_800628b0:
  *(char *)(driverBytes + 0x4b) = (char)iVar16;
  iVar11 = VehPhysJoystick_GetStrengthAbsolute
                     (iVar11,0x40,*(undefined4 *)(puVar6 + (uint)bVar1 * 0x50 + 0x4c));
  uVar10 = VehCalc_InterpBySpeed((int)*(short *)(driverBytes + 6),0x18,-iVar11);
  iVar11 = (int)*(short *)(driverBytes + 0x39e);
  *(undefined2 *)(driverBytes + 6) = uVar10;
  if (iVar11 < 0) {
    iVar11 = -iVar11;
  }
  if (((*(uint *)(driverBytes + 0x2cc) & 1) == 0) || (cVar2 == '\x02')) {
    iVar11 = iVar11 + 0xf00;
  }
  else {
    iVar11 = iVar11 + iVar13 >> 1;
  }
  sVar15 = (short)((iVar11 * 0x89 + *(short *)(driverBytes + 0x3be) * 0x177) * 8 >> 0xc);
  *(short *)(driverBytes + 0x3be) = sVar15;
  if ((*(uint *)(driverBytes + 0x2cc) & 8) == 0) {
    if (iVar18 < 0) {
      iVar18 = -iVar18;
    }
    if ((0x200 < iVar18) || (0x200 < iVar13)) {
      *(short *)(driverBytes + 0x3bc) = *(short *)(driverBytes + 0x3bc) - sVar15;
    }
  }
  if (((*(short *)(driverBytes + 0x3bc) < 1) && ((*(uint *)(driverBytes + 8) & 1) == 0)) &&
     (cVar2 != '\x04')) {
    *(undefined2 *)(driverBytes + 0x3bc) = 0x1e00;
    *(undefined4 *)(driverBytes + 8) = 0x2e606061;
  }
  else {
    *(undefined4 *)(driverBytes + 8) = 0x2e808080;
  }
LAB_800629f8:
  *(uint *)(driverBytes + 0x2c8) = uVar21;
  return;
}



