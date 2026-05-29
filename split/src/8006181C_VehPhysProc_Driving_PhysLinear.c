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


void VehPhysProc_Driving_PhysLinear(Thread *thread, Driver *driver)
{
  byte driverId;
  char kartState;
  char heldItemId;
  short timerValue;
  int hasTenWumpa;
  ushort updatedHazardTimer;
  ushort hazardTimerMagnitude;
  undefined2 newWheelRotation;
  int iVar11;
  uint uVar12;
  int iVar13;
  short rankItemValue;
  int iVar16;
  uint uVar17;
  int iVar18;
  undefined4 sfxId;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint actionFlags;
  int targetSpeed;
  uint accelButtonHeld;
  uint brakeButtonHeld;
  int reservesTimer;
  int turboOutsideTimer;
  int vehFireAudioCooldown;
  int wallRubTimer;
  int jumpForcedTimer;
  int jumpCooldownTimer;
  int jumpUnknownTimer;
  int burnTimer;
  int squishTimer;
  int clockTimer;
  int mashingTimer;
  int startDrivingTimer;
  int startRollbackTimer;
  int superEngineTimer;
  int jumpTenBufferTimer;
  GamepadBuffer *gamepad;
  RacingWheelData *wheelData;
  Thread *childThread;
  void *heldObj;

  if ((driver->actionsFlagSet & 0x40000) == 0)
  {
    driver->timeElapsedInRace = gT->elapsedEventTime;
  }

  iVar16 = gT->elapsedTimeMS;
  iVar11 = -iVar16;

  if ((gT->elapsedEventTime < 0x8ca00) && ((driver->actionsFlagSet & 0x40000) == 0))
  {
    driver->distanceDriven = driver->distanceDriven + ((driver->speedApprox * iVar16) >> 8);
  }

  reservesTimer = driver->reserves;
  turboOutsideTimer = driver->turboOutsideTimer;
  vehFireAudioCooldown = driver->vehFireAudioCooldown;
  wallRubTimer = driver->set0xF0OnWallRub;
  jumpForcedTimer = driver->jumpForcedMs;
  jumpCooldownTimer = driver->jumpCooldownMs;
  jumpUnknownTimer = driver->jumpUnknown;
  burnTimer = driver->burnTimer;
  squishTimer = driver->squishTimer;
  clockTimer = driver->clockReceive;
  mashingTimer = driver->mashingXMakesItBig;
  startDrivingTimer = driver->startDriving0x60;
  startRollbackTimer = driver->startRollback0x280;
  superEngineTimer = driver->superEngineTimer;
  jumpTenBufferTimer = driver->jumpTenBuffer;

  if (0 < reservesTimer)
  {
    reservesTimer = reservesTimer + iVar11;
    if (reservesTimer < 0)
    {
      reservesTimer = 0;
    }
    driver->reserves = (short)reservesTimer;
    driver->timeSpentUsingReserves -= iVar11;
  }

  if (0 < turboOutsideTimer)
  {
    turboOutsideTimer = turboOutsideTimer + iVar11;
    if (turboOutsideTimer < 0)
    {
      turboOutsideTimer = 0;
    }
    driver->turboOutsideTimer = (short)turboOutsideTimer;
  }

  if (0 < vehFireAudioCooldown)
  {
    vehFireAudioCooldown = vehFireAudioCooldown + iVar11;
    if (vehFireAudioCooldown < 0)
    {
      vehFireAudioCooldown = 0;
    }
    driver->vehFireAudioCooldown = (short)vehFireAudioCooldown;
  }

  if (0 < wallRubTimer)
  {
    wallRubTimer = wallRubTimer + iVar11;
    if (wallRubTimer < 0)
    {
      wallRubTimer = 0;
    }
    driver->set0xF0OnWallRub = (short)wallRubTimer;
    driver->timeSpentAgainstWall -= iVar11;
  }

  if (0 < jumpForcedTimer)
  {
    jumpForcedTimer = jumpForcedTimer + iVar11;
    if (jumpForcedTimer < 0)
    {
      jumpForcedTimer = 0;
    }
    driver->jumpForcedMs = (short)jumpForcedTimer;
  }

  if (0 < jumpCooldownTimer)
  {
    jumpCooldownTimer = jumpCooldownTimer + iVar11;
    if (jumpCooldownTimer < 0)
    {
      jumpCooldownTimer = 0;
    }
    driver->jumpCooldownMs = (short)jumpCooldownTimer;
  }

  if (0 < jumpUnknownTimer)
  {
    jumpUnknownTimer = jumpUnknownTimer + iVar11;
    if (jumpUnknownTimer < 0)
    {
      jumpUnknownTimer = 0;
    }
    driver->jumpUnknown = (short)jumpUnknownTimer;
  }

  if (0 < burnTimer)
  {
    burnTimer = burnTimer + iVar11;
    if (burnTimer < 0)
    {
      burnTimer = 0;
    }
    driver->burnTimer = (short)burnTimer;
    driver->timeSpentBurnt -= iVar11;
  }

  if (0 < squishTimer)
  {
    squishTimer = squishTimer + iVar11;
    if (squishTimer < 0)
    {
      squishTimer = 0;
    }
    driver->squishTimer = (short)squishTimer;
    driver->timeSpentSquished -= iVar11;
  }

  if (0 < startDrivingTimer)
  {
    startDrivingTimer = startDrivingTimer + iVar11;
    if (startDrivingTimer < 0)
    {
      startDrivingTimer = 0;
    }
    driver->startDriving0x60 = (short)startDrivingTimer;
  }

  if (0 < startRollbackTimer)
  {
    startRollbackTimer = startRollbackTimer + iVar11;
    if (startRollbackTimer < 0)
    {
      startRollbackTimer = 0;
    }
    driver->startRollback0x280 = (short)startRollbackTimer;
  }

  if (((gT->gameMode2 & 0x10000) == 0) && (0 < superEngineTimer))
  {
    superEngineTimer = superEngineTimer + iVar11;
    if (superEngineTimer < 0)
    {
      superEngineTimer = 0;
    }
    driver->superEngineTimer = (short)superEngineTimer;
  }

  if (0 < clockTimer)
  {
    clockTimer = clockTimer + iVar11;
    if (clockTimer < 0)
    {
      clockTimer = 0;
    }
    driver->clockReceive = (short)clockTimer;
  }

  if (0 < mashingTimer)
  {
    mashingTimer = mashingTimer + iVar11;
    if (mashingTimer < 0)
    {
      mashingTimer = 0;
    }
    driver->mashingXMakesItBig = (short)mashingTimer;
  }

  if (0 < jumpTenBufferTimer)
  {
    driver->jumpTenBuffer = jumpTenBufferTimer + -1;
  }

  if (9 < driver->numWumpas)
  {
    driver->timeSpentInTenWumpa -= iVar11;
  }

  if ((u8)driver->currentTerrain == 0xe)
  {
    driver->timeSpentInMud -= iVar11;
  }

  rankItemValue = driver->driverRank;
  if (((((rankItemValue == 7) && (gT->numPlyrCurrGame == 1)) ||
       ((rankItemValue == 5 && (gT->numPlyrCurrGame == 2)))) ||
      ((rankItemValue == 3 && (2 < (byte)gT->numPlyrCurrGame)))) &&
     ((driver->actionsFlagSet & 0x40000) == 0))
     {
    driver->timeSpentInLastPlace -= iVar11;
  }
  rankItemValue = 4;

  if (driver->thCloud != 0)
  {
    rankItemValue = M2C_FIELD(driver->thCloud->object, s16 *, 6);
  }
  iVar13 = (int)driver->speedApprox;
  actionFlags = driver->actionsFlagSet;
  iVar20 = (int)driver->clockReceive;
  driver->driverRankItemValue = rankItemValue;
  if (iVar13 < 0)
  {
    iVar13 = -iVar13;
  }
  if (((iVar20 == 0) && (iVar20 = (int)driver->squishTimer, iVar20 == 0)) &&
     ((rankItemValue != 0 || (iVar20 = gT->elapsedEventTime, iVar20 == 0))))
     {
    iVar20 = (int)driver->hazardTimer;
    iVar20 = iVar20 + iVar11;
    if (iVar13 < 0x101)
    {
      iVar20 = -2;
    }
    else
    {
      iVar20 = iVar20 & -2;
      if (-1 < iVar20)
      {
        iVar20 = -2;
      }
    }
    driver->hazardTimer = (short)iVar20;
  }
  else
  {
    if ((actionFlags & 1) != 0)
    {
      if (iVar13 < 0x101) goto LAB_80061cf8;
      if (iVar20 < 0)
      {
        iVar20 = -iVar20;
      }
      iVar11 = (uint)(ushort)driver->clockReceive << 0x10;
      iVar18 = iVar11 >> 0x16;
      if (0x40 < iVar18)
      {
        iVar18 = 0x40;
      }
      uVar21 = (iVar11 >> 0x10) << 4;
      iVar11 = (&D_800845A0)[uVar21 & 0x3ff];
      if ((uVar21 & 0x400) == 0)
      {
        iVar11 = iVar11 << 0x10;
      }
      iVar11 = iVar11 >> 0x10;
      if ((uVar21 & 0x800) != 0)
      {
        iVar11 = -iVar11;
      }
      iVar22 = iVar13 >> 8;
      if (0x20 < iVar22)
      {
        iVar22 = 0x20;
      }
      GAMEPAD_ShockForce1(driver,4,iVar18 + (iVar11 >> 5) + iVar22 + 0x18);
      updatedHazardTimer = (ushort)iVar20 | 1;
    }
    else
    {
      if (iVar13 < 0x101) goto LAB_80061cf8;
      if (iVar20 < 0)
      {
        iVar20 = -iVar20;
      }
      updatedHazardTimer = -(ushort)iVar20 | 1;
    }
    goto LAB_80061d44;

LAB_80061cf8:
    hazardTimerMagnitude = (ushort)driver->hazardTimer;
    updatedHazardTimer = hazardTimerMagnitude | 1;
    if (0 < (short)hazardTimerMagnitude)
    {
      updatedHazardTimer = -hazardTimerMagnitude | 1;
    }

LAB_80061d44:
    driver->hazardTimer = (s16)updatedHazardTimer;
  }
  if (driver->heldItemId == 0x10)
  {
    if (driver->itemRollTimer != 0)
    {
      driver->itemRollTimer = driver->itemRollTimer + -1;
    }
    else
    {
      VehPhysGeneral_SetHeldItem(driver);
      hasTenWumpa = 9 < driver->numWumpas;
      sfxId = 0x5e;
      if (hasTenWumpa)
      {
        sfxId = 0x41;
      }
      OtherFX_Play(sfxId,hasTenWumpa);
    }
  }
  timerValue = driver->noItemTimer;
  if (timerValue != 0)
  {
    if ((timerValue == 1) && (driver->numHeldItems == 0))
    {
      if ((2 < (byte)gT->numPlyrCurrGame) &&
         (((gT->gameMode1 & 0x20) == 0 && (driver->heldItemId == 0xb)) &&
          (0 < gT->unk1EC4)))
          {
        gT->unk1EC4 = gT->unk1EC4 + -1;
      }
      driver->heldItemId = 0xf;
    }
    driver->noItemTimer = timerValue + -1;
  }
  if ((driver->invincibleTimer != 0) &&
     (iVar11 = driver->invincibleTimer - gT->elapsedTimeMS,
     driver->invincibleTimer = iVar11, iVar11 < 0))
     {
    driver->invincibleTimer = 0;
  }
  if ((driver->invisibleTimer != 0) && ((gT->gameMode2 & 0x8000) == 0))
  {
    iVar11 = driver->invisibleTimer - gT->elapsedTimeMS;
    driver->invisibleTimer = iVar11;
    if (iVar11 < 0)
    {
      driver->invisibleTimer = 0;
    }
    if (driver->invisibleTimer == 0)
    {
      driver->instSelf->flags = driver->instFlagsBackup;
      driver->instSelf->alphaScale = 0;
      OtherFX_Play(0x62,1);
    }
  }
  driver->rotPrev[3] = driver->rotCurr[3];
  driver->actionsFlagSetPrevFrame = actionFlags;
  driver->posPrev.x = driver->posCurr.x;
  driver->posPrev.y = driver->posCurr.y;
  driver->jumpHeightPrev = driver->jumpHeightCurr;
  driver->turnAnglePrev = driver->turnAngleCurr;
  driver->rotPrev[0] = driver->rotCurr[0];
  driver->posPrev.z = driver->posCurr.z;
  driver->rotPrev[1] = driver->rotCurr[1];
  driver->rotPrev[2] = driver->rotCurr[2];
  uVar21 = actionFlags & 0x7f1f83d5;

  if ((gT->gameMode2 & 0x4004) != 0) goto LAB_800629f8;

  iVar20 = (uint)(byte)driver->normalVecId + 1;
  if (0 < iVar20)
  {
    iVar20 = 0;
  }

  if ((actionFlags & 1) == 0)
  {
    *(uint *)&driver->axisAngle4NormalVec[0] = *(uint *)&driver->axisAngle2NormalVec[0];
    driver->axisAngle4NormalVec[2] = driver->axisAngle2NormalVec[2];
  }
  else
  {
    *(uint *)&driver->axisAngle4NormalVec[0] = *(uint *)&driver->axisAngle1NormalVec.x;
    driver->axisAngle4NormalVec[2] = driver->axisAngle1NormalVec.z;
  }

  driver->normalVecId = (char)iVar20;

  actionFlags = uVar21;
  childThread = thread->childThread;
  while (childThread != 0)
  {
    iVar20 = childThread->modelIndex;
    if (iVar20 == 0x3a) goto LAB_80061fc8_childFound;
    if (iVar20 != 0x39)
    {
      childThread = childThread->siblingThread;
      continue;
    }
LAB_80061fc8_childFound:
    actionFlags = uVar21 | 0x800000;
    break;
  }

  driverId = driver->driverId;
  gamepad = &D_8008D2B0->gamepad[(uint)driverId];
  wheelData = gamepad->rwd;
  uVar21 = 0;

  if ((gT->gameMode1 & 0x200000) == 0)
  {
    uVar21 = gamepad->buttonsHeldCurrFrame;
  }

  uVar17 = 0;
  if ((gT->gameMode1 & 0x200000) == 0)
  {
    uVar17 = gamepad->buttonsTapped;
  }

  accelButtonHeld = uVar21 & 0x10;
  brakeButtonHeld = uVar21 & 0x20;
  kartState = driver->kartState;

  if ((((uVar17 & 0x40) != 0) && (((kartState == 0 || (kartState == 2)) || (kartState == 9)))) && (driver->instTntRecv == 0))
     {
    if (driver->instBombThrow != 0)
    {
      heldObj = driver->instBombThrow->thread->object;
      M2C_FIELD(heldObj, u16 *, 0x16) = M2C_FIELD(heldObj, u16 *, 0x16) | 2;
      driver->instBombThrow = 0;
    }
    else if (driver->instBubbleHold != 0)
    {
      heldObj = driver->instBubbleHold->thread->object;
      M2C_FIELD(heldObj, u16 *, 6) = M2C_FIELD(heldObj, u16 *, 6) | 2;
      driver->instBubbleHold = 0;
    }
    else
    {
      timerValue = driver->itemRollTimer;
      if (timerValue == 0)
      {
        heldItemId = driver->heldItemId;
        if (((heldItemId != 0xf) && (heldItemId != 0x10)) &&
           ((driver->noItemTimer == 0 &&
            ((rankItemValue != 1 && (driver->clockReceive == 0))))))
            {
          actionFlags = actionFlags | 0x8000;
          if (driver->numHeldItems == 0)
          {
            driver->noItemTimer = 0x1e;
          }
          else
          {
            if (heldItemId == 5)
            {
              if (driver->jumpCoyoteTimerMs != 0)
              {
                uVar12 = (uint)driver->jumpCooldownMs;
                if (uVar12 == 0)
                {
                  driver->numHeldItems = driver->numHeldItems + -1;
                }
              }
            }
            else
            {
              uVar12 = gT->gameMode2 & 0x400c00;
              if (uVar12 == 0)
              {
                driver->numHeldItems = driver->numHeldItems + -1;
              }
            }
            driver->noItemTimer = 5;
          }
        }
        else if (timerValue < 0x46)
        {
          driver->itemRollTimer = 0;
        }
      }
      else if (timerValue < 0x46)
      {
        driver->itemRollTimer = 0;
      }
    }
  }
  uVar17 = uVar17 & 0xc00;
  if ((uVar17 == 0) || (driver->kartState == 2))
  {
    if (((uVar21 & 0xc00) != 0) && (rankItemValue != 3))
    {
      if ((actionFlags & 4) == 0)
      {
        driver->jumpTenBuffer = 10;
      }
      actionFlags = actionFlags | 4;
    }
    else
    {
      actionFlags = actionFlags & 0xfffffffb;
      if (0 < driver->jumpTenBuffer)
      {
        driver->jumpTenBuffer = 0;
      }
    }
  }
  else
  {
    if (uVar17 == 0xc00)
    {
      driver->buttonUsedToStartDrift = 0x400;
    }
    else
    {
      driver->buttonUsedToStartDrift = (short)uVar17;
    }
    if (rankItemValue != 3)
    {
      driver->jumpTenBuffer = 10;
      actionFlags = actionFlags | 4;
    }
  }
  if ((brakeButtonHeld != 0) && ((driver->stepFlagSet & 3) == 0))
  {
    driver->reserves = 0;
  }
  iVar11 = 0x80;
  if ((gT->gameMode1 & 0x200000) == 0)
  {
    iVar11 = (int)gamepad->stickRY;
  }
  if ((driver->reserves != 0) || (rankItemValue == 6))
  {
    if ((accelButtonHeld == 0) && (iVar20 = VehPhysJoystick_ReturnToRest(iVar11,0x80,0), -iVar20 < 1))
    {
      actionFlags = actionFlags | 0x400000;
    }
    if ((brakeButtonHeld != 0) && (0x300 < iVar13))
    {
      actionFlags = actionFlags | 0x800;
    }
    if ((driver->stepFlagSet & 3) != 0)
    {
      brakeButtonHeld = 0;
    }
    accelButtonHeld = 0x10;
  }
  iVar20 = 0x80;
  if ((gT->gameMode1 & 0x200000) == 0)
  {
    iVar20 = (int)gamepad->stickLY;
  }
  if ((driver->simpTurnState < 0) ||
     (actionFlags = actionFlags & 0xdfffffff, driver->simpTurnState < 1))
     {
    actionFlags = actionFlags & 0xbfffffff;
  }
  iVar18 = (int)driver->speedApprox;
  if (iVar18 < 0)
  {
    iVar18 = -iVar18;
  }
  if (iVar18 < 0x300)
  {
    actionFlags = actionFlags & 0x9fffffff;
  }
  iVar18 = 0;
  iVar22 = VehPhysGeneral_GetBaseSpeed(driver);
  if (brakeButtonHeld == 0)
  {
    targetSpeed = iVar22;
    if (accelButtonHeld != 0)
    {
LAB_8006253c:
      actionFlags = actionFlags & 0xfffdffff;
      goto LAB_80062548;
    }
    iVar11 = VehPhysJoystick_ReturnToRest(iVar11,0x80,0);
    iVar11 = -iVar11;
    if (-1 < iVar11)
    {
      if ((iVar11 == 0) &&
         ((iVar20 = VehPhysJoystick_ReturnToRest(iVar20,0x80,0), 99 < iVar20 ||
          ((0 < iVar20 && ((actionFlags & 0x20000) != 0))))))
          {
        actionFlags = actionFlags | 0x20000;
        targetSpeed = -(int)driver->constBackwardSpeed;
        goto LAB_80062548;
      }
      iVar11 = iVar22 * iVar11;
      targetSpeed = iVar11 >> 7;
      if (iVar11 < 0)
      {
        targetSpeed = (iVar11 + 0x7f) >> 7;
      }
      goto LAB_8006253c;
    }
    if ((driver->speedApprox < 0x301) && ((actionFlags & 0x60000000) == 0))
    {
      iVar11 = driver->constBackwardSpeed * iVar11;
      if (iVar11 < 0)
      {
        iVar11 = iVar11 + 0x7f;
      }
      iVar18 = iVar11 >> 7;
      uVar17 = 0x20000;
LAB_800625c4:
      uVar21 = actionFlags | uVar17;
    }
    else
    {
      uVar21 = actionFlags | 8;
      if (0 < driver->simpTurnState)
      {
        uVar21 = actionFlags | 0x40000008;
      }
      if (driver->simpTurnState < 0)
      {
        uVar17 = 0x20000000;
        actionFlags = uVar21;
        goto LAB_800625c4;
      }
    }
  }
  else
  {
    iVar20 = VehPhysJoystick_ReturnToRest(iVar20,0x80,0);
    if ((iVar20 < 100) && ((iVar20 < 1 || ((actionFlags & 0x20000) == 0))))
    {
      if (accelButtonHeld == 0)
      {
        iVar11 = VehPhysJoystick_ReturnToRest(iVar11,0x80,0);
        iVar11 = -iVar11;
        targetSpeed = iVar22 * iVar11;
        if (0 < iVar11)
        {
          if (targetSpeed < 0)
          {
            targetSpeed = targetSpeed + 0xff;
          }
          targetSpeed = targetSpeed >> 8;
          actionFlags = actionFlags | 0x20;
          goto LAB_80062548;
        }
        if (iVar11 < 0)
        {
          iVar11 = driver->constBackwardSpeed * iVar11;
          targetSpeed = iVar11 >> 8;
          if (iVar11 < 0)
          {
            targetSpeed = (iVar11 + 0xff) >> 8;
          }
          goto LAB_8006248c;
        }
        actionFlags = actionFlags | 8;
        targetSpeed = iVar18;
      }
      else
      {
        actionFlags = actionFlags | 0x20;
        targetSpeed = iVar22 / 2;
      }
      goto LAB_8006253c;
    }
    iVar11 = driver->constBackwardSpeed * -3;
    targetSpeed = iVar11 >> 2;
    if (iVar11 < 0)
    {
      targetSpeed = (iVar11 + 3) >> 2;
    }
LAB_8006248c:
    actionFlags = actionFlags | 0x20020;
LAB_80062548:
    uVar21 = actionFlags & 0x9fffffff;
    iVar18 = targetSpeed;
  }
  if ((uVar21 & 0x20000) == 0)
  {
    actionFlags = uVar21 & 8;
    if (driver->superEngineTimer != 0)
    {
      if (0 < iVar18)
      {
        actionFlags = uVar21 & 8;
        if ((uVar21 & 0x400020) != 0) goto LAB_80062648;
        sfxId = 0x80;
        driver->actionsFlagSet = uVar21;
        if (9 < driver->numWumpas)
        {
          sfxId = 0x100;
        }
        VehFire_Increment(driver,0x78,0x14,sfxId);
        uVar21 = driver->actionsFlagSet;
      }
      goto code_r0x80062644;
    }
  }
  else
  {
    driver->timeSpentReversing -= iVar11;
code_r0x80062644:
    actionFlags = uVar21 & 8;
  }
LAB_80062648:
  if (actionFlags != 0)
  {
    iVar11 = (int)driver->speedApprox;
    if (iVar11 < 0)
    {
      iVar11 = -iVar11;
    }
    if (0x300 < iVar11)
    {
      driver->timeSpentWithHighSpeed -= iVar11;
    }
  }

  if ((driver->mashingXMakesItBig == 0) || ((driver->kartState != 0 && (driver->kartState != 9))))
  {
    driver->mashXUnknown = 0;
  }

  if (((driver->fireSpeed < 1) && (0 < iVar18)) ||
     ((0 < driver->fireSpeed) && (iVar18 < 1)))
  {
    if (driver->mashingXMakesItBig != 0)
    {
      driver->mashXUnknown = driver->mashXUnknown + 1;
    }
    driver->mashingXMakesItBig = 0x100;
  }
  driver->fireSpeed = (short)iVar18;

  if ((uVar21 & 0x800020) == 0)
  {
    iVar11 = driver->terrainMeta2->unk0x8;
    if (iVar11 != 0x100)
    {
      iVar18 = iVar11 * iVar18 >> 8;
      iVar22 = iVar11 * iVar22 >> 8;
    }
  }

  driver->unknownDriverBaseSpeed = (short)iVar22;
  driver->baseSpeed = (short)iVar18;
  iVar11 = 0x80;

  if ((gT->gameMode1 & 0x200000) == 0)
  {
    iVar11 = (int)gamepad->stickLX;
  }
  iVar16 = (uint)(byte)driver->constTurnRate + ((int)driver->turnConst << 1) / 5;
  if (driver->mashXUnknown < 7 || (0x25ff < iVar13))
  {
    if (driver->set0xF0OnWallRub == 0)
    {
      if ((uVar21 & 0x28) == 0)
      {
      }
      else if (accelButtonHeld == 0)
      {
        iVar16 = 0x40;
      }
      else
      {
        iVar20 = (int)driver->speed;
        if (iVar20 < 0)
        {
          iVar20 = -iVar20;
        }
        iVar16 = VehCalc_MapToRange(iVar20,0x300,(int)((uint)(u16)driver->constSpeedClassStat << 0x10) >> 0x11,0x40,iVar16);
      }
    }
    else
    {
      iVar16 = 0x30;
    }
  }

  else
  {
    iVar16 = 0x5a;
  }

  iVar16 = VehPhysJoystick_GetStrengthAbsolute(iVar11,iVar16,wheelData);
  iVar16 = -iVar16;

  if (iVar16 == 0)
  {
    driver->numFramesSpentSteering = 10000;
  }
  else
  {
    if ((iVar16 < 0) && (-1 < driver->simpTurnState))
    {
      uVar21 = uVar21 & 0xffffffef;
    }
    else
    {
      if ((iVar16 < 1) || (0 < driver->simpTurnState)) goto LAB_800628b0;
      uVar21 = uVar21 | 0x10;
    }
    driver->numFramesSpentSteering = 0;
  }

LAB_800628b0:
  driver->simpTurnState = (char)iVar16;
  iVar11 = VehPhysJoystick_GetStrengthAbsolute(iVar11,0x40,wheelData);
  newWheelRotation = VehCalc_InterpBySpeed(driver->wheelRotation,0x18,-iVar11);
  iVar11 = (int)driver->fireSpeed;
  driver->wheelRotation = newWheelRotation;
  if (iVar11 < 0)
  {
    iVar11 = -iVar11;
  }
  if (((driver->actionsFlagSetPrevFrame & 1) == 0) || (kartState == 2))
  {
    iVar11 = iVar11 + 0xf00;
  }
  else
  {
    iVar11 = (iVar11 + iVar13) >> 1;
  }
  rankItemValue = (short)((iVar11 * 0x89 + driver->unkSpeedValue2 * 0x177) * 8 >> 0xc);
  driver->unkSpeedValue2 = rankItemValue;
  if ((driver->actionsFlagSetPrevFrame & 8) == 0)
  {
    if (iVar18 < 0)
    {
      iVar18 = -iVar18;
    }
    if ((0x200 < iVar18) || (0x200 < iVar13))
    {
      driver->unkSpeedValue1 = driver->unkSpeedValue1 - rankItemValue;
    }
  }
  if (((driver->unkSpeedValue1 < 1) && ((driver->tireColor & 1) == 0)) &&
     (kartState != 4))
     {
    driver->unkSpeedValue1 = 0x1e00;
    driver->tireColor = 0x2e606061;
  }
  else
  {
    driver->tireColor = 0x2e808080;
  }
LAB_800629f8:
  driver->actionsFlagSet = uVar21;
  return;
}
