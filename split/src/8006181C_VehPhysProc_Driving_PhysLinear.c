
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
s32 VehCalc_InterpBySpeed();        /* extern */
s32 VehCalc_MapToRange(); /* extern */
M2C_UNK VehFire_Increment(); /* extern */
s32 VehPhysGeneral_GetBaseSpeed();            /* extern */
M2C_UNK VehPhysGeneral_SetHeldItem();         /* extern */
s32 VehPhysJoystick_GetStrengthAbsolute(); /* extern */
s32 VehPhysJoystick_ReturnToRest(); /* extern */
extern M2C_UNK D_800845A0;
extern GamepadSystem *D_8008D2B0;


void VehPhysProc_Driving_PhysLinear(Thread *thread, Driver *driverParam)
{
  int kartState;
  char heldItemId;
  int heldItemCount;
  short timerValue;
  ushort updatedHazardTimer;
  ushort hazardTimerMagnitude;
  ushort clockReceiveRaw;
  int hazardTimerAbs;
  undefined2 newWheelRotation;
  int iVar11;
  uint mask40000;
  uint uVar12;
  int iVar13;
  int absSpeedApprox;
  int rankItemValue;
  int iVar16;
  int turnStrength;
  int turnSpeed;
  uint uVar17;
  int iVar18;
  undefined4 sfxId;
  int iVar20;
  uint uVar21;
  int iVar22;
  int stickRest;
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
  Thread *childThread;
  TrackerWeapon *bomb;
  Shield *shield;
  undefined2 *normalVecDst;
  Driver *driver;

  driver = driverParam;
  mask40000 = 0x40000;
  if ((driver->actionsFlagSet & mask40000) == 0)
  {
    driver->timeElapsedInRace = gT->elapsedEventTime;
  }

  iVar16 = gT->elapsedTimeMS;
  iVar11 = -iVar16;

  if ((0x8ca00 > gT->elapsedEventTime) && ((driver->actionsFlagSet & mask40000) == 0))
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

  if (reservesTimer > 0)
  {
    reservesTimer = reservesTimer + iVar11;
    if (0 > reservesTimer)
    {
      reservesTimer = 0;
    }
    driver->reserves = (short)reservesTimer;
    driver->timeSpentUsingReserves -= iVar11;
  }

  if (turboOutsideTimer > 0)
  {
    turboOutsideTimer = turboOutsideTimer + iVar11;
    if (0 > turboOutsideTimer)
    {
      turboOutsideTimer = 0;
    }
    driver->turboOutsideTimer = (short)turboOutsideTimer;
  }

  if (vehFireAudioCooldown > 0)
  {
    vehFireAudioCooldown = vehFireAudioCooldown + iVar11;
    if (0 > vehFireAudioCooldown)
    {
      vehFireAudioCooldown = 0;
    }
    driver->vehFireAudioCooldown = (short)vehFireAudioCooldown;
  }

  if (wallRubTimer > 0)
  {
    wallRubTimer = wallRubTimer + iVar11;
    if (0 > wallRubTimer)
    {
      wallRubTimer = 0;
    }
    driver->set0xF0OnWallRub = (short)wallRubTimer;
    driver->timeSpentAgainstWall -= iVar11;
  }

  if (jumpForcedTimer > 0)
  {
    jumpForcedTimer = jumpForcedTimer + iVar11;
    if (0 > jumpForcedTimer)
    {
      jumpForcedTimer = 0;
    }
    driver->jumpForcedMs = (short)jumpForcedTimer;
  }

  if (jumpCooldownTimer > 0)
  {
    jumpCooldownTimer = jumpCooldownTimer + iVar11;
    if (0 > jumpCooldownTimer)
    {
      jumpCooldownTimer = 0;
    }
    driver->jumpCooldownMs = (short)jumpCooldownTimer;
  }

  if (jumpUnknownTimer > 0)
  {
    jumpUnknownTimer = jumpUnknownTimer + iVar11;
    if (0 > jumpUnknownTimer)
    {
      jumpUnknownTimer = 0;
    }
    driver->jumpUnknown = (short)jumpUnknownTimer;
  }

  if (burnTimer > 0)
  {
    burnTimer = burnTimer + iVar11;
    if (0 > burnTimer)
    {
      burnTimer = 0;
    }
    driver->burnTimer = (short)burnTimer;
    driver->timeSpentBurnt -= iVar11;
  }

  if (squishTimer > 0)
  {
    squishTimer = squishTimer + iVar11;
    if (0 > squishTimer)
    {
      squishTimer = 0;
    }
    driver->squishTimer = (short)squishTimer;
    driver->timeSpentSquished -= iVar11;
  }

  if (startDrivingTimer > 0)
  {
    startDrivingTimer = startDrivingTimer + iVar11;
    if (0 > startDrivingTimer)
    {
      startDrivingTimer = 0;
    }
    driver->startDriving0x60 = (short)startDrivingTimer;
  }

  if (startRollbackTimer > 0)
  {
    startRollbackTimer = startRollbackTimer + iVar11;
    if (0 > startRollbackTimer)
    {
      startRollbackTimer = 0;
    }
    driver->startRollback0x280 = (short)startRollbackTimer;
  }

  if (((gT->gameMode2 & 0x10000) == 0) && (superEngineTimer > 0))
  {
    superEngineTimer = superEngineTimer + iVar11;
    if (0 > superEngineTimer)
    {
      superEngineTimer = 0;
    }
    driver->superEngineTimer = (short)superEngineTimer;
  }

  if (clockTimer > 0)
  {
    clockTimer = clockTimer + iVar11;
    if (0 > clockTimer)
    {
      clockTimer = 0;
    }
    driver->clockReceive = (short)clockTimer;
  }

  if (mashingTimer > 0)
  {
    mashingTimer = mashingTimer + iVar11;
    if (0 > mashingTimer)
    {
      mashingTimer = 0;
    }
    driver->mashingXMakesItBig = (short)mashingTimer;
  }

  if (jumpTenBufferTimer > 0)
  {
    driver->jumpTenBuffer = jumpTenBufferTimer + -1;
  }

  if (driver->numWumpas > 9)
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
      ((rankItemValue == 3 && ((byte)gT->numPlyrCurrGame > 2)))) &&
     ((driver->actionsFlagSet & 0x40000) == 0))
     {
    driver->timeSpentInLastPlace -= iVar11;
  }
  rankItemValue = 4;

  if (driver->thCloud != 0)
  {
    rankItemValue = ((RainCloud *)driver->thCloud->object)->boolScrollItem;
  }
  iVar13 = (int)driver->speedApprox;
  actionFlags = driver->actionsFlagSet;
  iVar20 = (int)driver->clockReceive;
  driver->driverRankItemValue = rankItemValue;
  absSpeedApprox = abs(iVar13);
  iVar13 = absSpeedApprox;
  if (iVar20 == 0)
  {
    iVar20 = (int)driver->squishTimer;
    if (iVar20 == 0)
    {
      if (rankItemValue == 0)
      {
        iVar20 = gT->elapsedEventTime;
      }
    }
  }

  if ((rankItemValue != 0) || (iVar20 == 0))
  {
    iVar20 = (int)driver->hazardTimer;
    iVar22 = -2;
    if (iVar13 < 0x101)
    {
      iVar20 = iVar22;
    }
    else
    {
      iVar20 = iVar20 + iVar11;
      iVar20 = iVar20 & iVar22;
      if (iVar20 > -1)
      {
        iVar20 = iVar22;
      }
    }
    driver->hazardTimer = (short)iVar20;
  }
  else if (iVar13 < 0x101)
  {
    hazardTimerMagnitude = (ushort)driver->hazardTimer;
    updatedHazardTimer = hazardTimerMagnitude | 1;
    if ((short)hazardTimerMagnitude > 0)
    {
      updatedHazardTimer = -hazardTimerMagnitude | 1;
    }
    driver->hazardTimer = (s16)updatedHazardTimer;
  }
  else if ((actionFlags & 1) != 0)
  {
    clockReceiveRaw = (ushort)driver->clockReceive;
    hazardTimerAbs = iVar20;
    if (0 > hazardTimerAbs)
    {
      hazardTimerAbs = -hazardTimerAbs;
    }
    iVar11 = (int)(short)clockReceiveRaw;
    iVar18 = iVar11 >> 6;
    if (iVar18 > 0x40)
    {
      iVar18 = 0x40;
    }
    uVar21 = (uint)iVar11 << 4;
    iVar11 = uVar21 & 0x3ff;
    iVar11 = (&D_800845A0)[iVar11];
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
    if (iVar22 > 0x20)
    {
      iVar22 = 0x20;
    }
    iVar18 = iVar18 + (iVar11 >> 5);
    iVar18 = iVar18 + iVar22;
    GAMEPAD_ShockForce1(driver,4,iVar18 + 0x18);
    updatedHazardTimer = (ushort)hazardTimerAbs | 1;
    driver->hazardTimer = (s16)updatedHazardTimer;
  }
  else
  {
    hazardTimerAbs = iVar20;
    if (0 > hazardTimerAbs)
    {
      hazardTimerAbs = -hazardTimerAbs;
    }
    updatedHazardTimer = -(ushort)hazardTimerAbs | 1;
    driver->hazardTimer = (s16)updatedHazardTimer;
  }

  if ((u8)driver->heldItemId == 0x10)
  {
    if (driver->itemRollTimer != 0)
    {
      driver->itemRollTimer = driver->itemRollTimer + -1;
    }
    else
    {
      VehPhysGeneral_SetHeldItem(driver);
      if (driver->numWumpas > 9)
      {
        OtherFX_Play(0x41,1);
      }
      else
      {
        OtherFX_Play(0x5e,0);
      }
    }
  }
  timerValue = driver->noItemTimer;
  if (timerValue != 0)
  {
    if ((timerValue == 1) && ((u8)driver->numHeldItems == 0))
    {
      if (((byte)gT->numPlyrCurrGame > 2) &&
         (((gT->gameMode1 & 0x20) == 0 && ((u8)driver->heldItemId == 0xb)) &&
          (gT->unk1EC4 > 0)))
          {
        gT->unk1EC4 = gT->unk1EC4 + -1;
      }
      driver->heldItemId = 0xf;
    }
    driver->noItemTimer = timerValue + -1;
  }
  if ((driver->invincibleTimer != 0) &&
     (iVar11 = driver->invincibleTimer - gT->elapsedTimeMS,
     driver->invincibleTimer = iVar11, 0 > iVar11))
     {
    driver->invincibleTimer = 0;
  }
  if ((driver->invisibleTimer != 0) && ((gT->gameMode2 & 0x8000) == 0))
  {
    iVar11 = driver->invisibleTimer - gT->elapsedTimeMS;
    driver->invisibleTimer = iVar11;
    if (0 > iVar11)
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
 
  *(uint *)&driver->rotPrev[0] = *(uint *)&driver->rotCurr[0];
  driver->actionsFlagSetPrevFrame = actionFlags;
  driver->posPrev.x = driver->posCurr.x;
  driver->posPrev.y = driver->posCurr.y;
  driver->posPrev.z = driver->posCurr.z;
  driver->rotPrev[2] = driver->rotCurr[2];
  driver->jumpHeightPrev = driver->jumpHeightCurr;
  driver->turnAnglePrev = driver->turnAngleCurr;
  uVar21 = actionFlags & 0x7f1f83d5;

  

  if ((gT->gameMode2 & 0x4004) != 0)
  {
    driver->actionsFlagSet = uVar21;
    return;
  }

  iVar20 = (uint)(byte)driver->normalVecId + 1;
  if (iVar20 > 0)
  {
    iVar20 = 0;
  }

  normalVecDst = (undefined2 *)((s8 *)&driver->axisAngle4NormalVec[0] + (iVar20 * 8));

  if ((actionFlags & 1) != 0)
  {
    *(uint *)&normalVecDst[0] = *(uint *)&driver->axisAngle1NormalVec.x;
    normalVecDst[2] = driver->axisAngle1NormalVec.z;
  }
  else
  {
    *(uint *)&normalVecDst[0] = *(uint *)&driver->axisAngle2NormalVec[0];
    normalVecDst[2] = driver->axisAngle2NormalVec[2];
  }

  childThread = thread->childThread;
  driver->normalVecId = (char)iVar20;

  actionFlags = uVar21;
  while (childThread != 0)
  {
    iVar20 = childThread->modelIndex;
    if (iVar20 == 0x3a) goto LAB_80061fc8_childFound;
    if (iVar20 != 0x39) goto LAB_80061fc0_childNext;
LAB_80061fc8_childFound:
    actionFlags = actionFlags | 0x800000;
    break;
LAB_80061fc0_childNext:
    childThread = childThread->siblingThread;
  }

  gamepad = &D_8008D2B0->gamepad[(uint)(u8)driver->driverId];
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

  if ((uVar17 & 0x40) != 0)
  {
    if (((kartState == 0) || (kartState == 2) || (kartState == 9)) && (driver->instTntRecv == 0))
    {
      if (driver->instBombThrow != 0)
      {
        bomb = driver->instBombThrow->thread->object;
        bomb->flags |= TRACKER_WEAPON_FLAG_DETONATE;
        driver->instBombThrow = 0;
      }
      else if (driver->instBubbleHold != 0)
      {
        shield = driver->instBubbleHold->thread->object;
        shield->flags |= SHIELD_FLAG_SHOOTING;
        driver->instBubbleHold = 0;
      }
      else
      {
        heldItemId = driver->heldItemId;
        if ((driver->itemRollTimer != 0) || (heldItemId == 0xf) || (heldItemId == 0x10) ||
            (driver->noItemTimer != 0) || (rankItemValue == 1) || (driver->clockReceive != 0))
        {
          if (driver->itemRollTimer < 0x46)
          {
            driver->itemRollTimer = 0;
          }
        }
        else
        {
          heldItemCount = (u8)driver->numHeldItems;
          actionFlags = actionFlags | 0x8000;
          if (heldItemCount != 0)
          {
            if ((heldItemId != 5) || (driver->jumpCoyoteTimerMs != 0))
            {
              if (heldItemId == 5)
              {
                uVar12 = driver->jumpCooldownMs;
              }
              else
              {
                uVar12 = gT->gameMode2 & 0x400c00;
              }

              if (uVar12 == 0)
              {
                driver->numHeldItems = heldItemCount - 1;
              }
            }

            driver->noItemTimer = 5;
          }
          else
          {
            driver->noItemTimer = 0x1e;
          }
        }
      }
    }
  }
  uVar17 = uVar17 & 0xc00;

  if ((uVar17 != 0) && (driver->kartState != 2))
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
  else
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
      if (driver->jumpTenBuffer > 0)
      {
        driver->jumpTenBuffer = 0;
      }
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
    if ((accelButtonHeld == 0) && (iVar20 = VehPhysJoystick_ReturnToRest(iVar11,0x80,0), 1 > -iVar20))
    {
      actionFlags = actionFlags | 0x400000;
    }
    if ((brakeButtonHeld != 0) && (iVar13 > 0x300))
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
  if ((0 > driver->simpTurnState) ||
     (actionFlags = actionFlags & 0xdfffffff, 1 > driver->simpTurnState))
     {
    actionFlags = actionFlags & 0xbfffffff;
  }
  absSpeedApprox = (int)driver->speedApprox;
  if (absSpeedApprox < 0)
  {
    absSpeedApprox = -absSpeedApprox;
  }
  if (absSpeedApprox < 0x300)
  {
    actionFlags = actionFlags & 0x9fffffff;
  }
  iVar18 = 0;
  iVar22 = VehPhysGeneral_GetBaseSpeed(driver);

  do
  {
    if (brakeButtonHeld != 0)
    {
      iVar20 = VehPhysJoystick_ReturnToRest(iVar20,0x80,0);
      if ((iVar20 >= 100) || ((iVar20 > 0) && ((actionFlags & 0x20000) != 0)))
      {
        iVar11 = -(int)driver->constBackwardSpeed;
        iVar11 = iVar11 + iVar11 + iVar11;
        targetSpeed = iVar11 >> 2;
        if (iVar11 < 0)
        {
          targetSpeed = (iVar11 + 3) >> 2;
        }
        actionFlags = actionFlags | 0x20020;
        uVar21 = actionFlags & 0x9fffffff;
        iVar18 = targetSpeed;
        break;
      }

      if (accelButtonHeld != 0)
      {
        iVar18 = iVar22 / 2;
        actionFlags = actionFlags | 0x20;
        actionFlags = actionFlags & 0xfffdffff;
        uVar21 = actionFlags & 0x9fffffff;
        break;
      }

      iVar11 = VehPhysJoystick_ReturnToRest(iVar11,0x80,0);
      iVar11 = -iVar11;
      if (iVar11 > 0)
      {
        iVar18 = iVar22 * iVar11;
        if (0 > iVar18)
        {
          iVar18 = iVar18 + 0xff;
        }
        iVar18 = iVar18 >> 8;
        actionFlags = actionFlags | 0x20;
        uVar21 = actionFlags & 0x9fffffff;
        break;
      }
      if (0 > iVar11)
      {
        iVar11 = driver->constBackwardSpeed * iVar11;
        targetSpeed = iVar11 >> 8;
        if (0 > iVar11)
        {
          targetSpeed = (iVar11 + 0xff) >> 8;
        }
        actionFlags = actionFlags | 0x20020;
        uVar21 = actionFlags & 0x9fffffff;
        iVar18 = targetSpeed;
        break;
      }
      targetSpeed = iVar18;
      actionFlags = actionFlags | 8;
      actionFlags = actionFlags & 0xfffdffff;
      uVar21 = actionFlags & 0x9fffffff;
      iVar18 = targetSpeed;
      break;
    }

    if (accelButtonHeld != 0)
    {
      targetSpeed = iVar22;
      actionFlags = actionFlags & 0xfffdffff;
      uVar21 = actionFlags & 0x9fffffff;
      iVar18 = targetSpeed;
      break;
    }
    iVar11 = VehPhysJoystick_ReturnToRest(iVar11,0x80,0);
    iVar11 = -iVar11;
    if (iVar11 > -1)
    {
      if (iVar11 == 0)
      {
        stickRest = VehPhysJoystick_ReturnToRest(iVar20,0x80,0);
        if ((stickRest > 99) || ((stickRest > 0) && ((actionFlags & 0x20000) != 0)))
        {
          targetSpeed = -(int)driver->constBackwardSpeed;
          actionFlags = actionFlags | 0x20000;
          uVar21 = actionFlags & 0x9fffffff;
        iVar18 = targetSpeed;
        break;
        }
      }
      iVar11 = iVar22 * iVar11;
      iVar18 = iVar11 >> 7;
      if (0 > iVar11)
      {
        iVar18 = (iVar11 + 0x7f) >> 7;
      }
      actionFlags = actionFlags & 0xfffdffff;
      uVar21 = actionFlags & 0x9fffffff;
      break;
    }
    if (driver->speedApprox < 0x301)
    {
      if ((actionFlags & 0x60000000) == 0)
      {
        iVar11 = driver->constBackwardSpeed * iVar11;
        if (0 > iVar11)
        {
          iVar11 = iVar11 + 0x7f;
        }
        iVar18 = iVar11 >> 7;
        uVar21 = actionFlags | 0x20000;
        break;
      }
    }

    uVar21 = actionFlags | 8;
    if (driver->simpTurnState > 0)
    {
      uVar21 = uVar21 | 0x40000000;
    }
    if (0 > driver->simpTurnState)
    {
      uVar21 = uVar21 | 0x20000000;
    }
    break;
  } while (0);

  if ((uVar21 & 0x20000) != 0)
  {
    driver->timeSpentReversing -= iVar11;
  }
  else if ((driver->superEngineTimer != 0) && (iVar18 > 0) && ((uVar21 & 0x400020) == 0))
  {
    sfxId = 0x80;
    driver->actionsFlagSet = uVar21;
    if (driver->numWumpas > 9)
    {
      sfxId = 0x100;
    }
    VehFire_Increment(driver,0x78,0x14,sfxId);
    uVar21 = driver->actionsFlagSet;
  }

  if ((uVar21 & 8) != 0)
  {
    iVar11 = (int)driver->speedApprox;
    if (0 > iVar11)
    {
      iVar11 = -iVar11;
    }
    if (iVar11 > 0x300)
    {
      driver->timeSpentWithHighSpeed -= iVar11;
    }
  }

  if ((driver->mashingXMakesItBig == 0) || ((driver->kartState != 0 && (driver->kartState != 9))))
  {
    driver->mashXUnknown = 0;
  }

  if (((1 > driver->fireSpeed) && (iVar18 > 0)) ||
     ((driver->fireSpeed > 0) && (1 > iVar18)))
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
  turnStrength = (uint)(byte)driver->constTurnRate + ((int)driver->turnConst << 1) / 5;
  if ((7 <= driver->mashXUnknown) && (0x2600 > iVar13))
  {
    turnStrength = VehPhysJoystick_GetStrengthAbsolute(iVar11,0x5a,gamepad->rwd);
  }
  else
  {
    if (driver->set0xF0OnWallRub != 0)
    {
      turnStrength = VehPhysJoystick_GetStrengthAbsolute(iVar11,0x30,gamepad->rwd);
    }
    else
    {
      if ((uVar21 & 0x28) != 0)
      {
        if (accelButtonHeld != 0)
        {
          turnSpeed = (int)driver->speed;
          if (0 > turnSpeed)
          {
            turnSpeed = -turnSpeed;
          }
          turnStrength = VehCalc_MapToRange(turnSpeed,0x300,(int)((uint)(u16)driver->constSpeedClassStat << 0x10) >> 0x11,0x40,turnStrength);
          turnStrength = VehPhysJoystick_GetStrengthAbsolute(iVar11,turnStrength,gamepad->rwd);
        }
        else
        {
          turnStrength = VehPhysJoystick_GetStrengthAbsolute(iVar11,0x40,gamepad->rwd);
        }
      }
      else
      {
        turnStrength = VehPhysJoystick_GetStrengthAbsolute(iVar11,turnStrength,gamepad->rwd);
      }
    }
  }

  turnStrength = -turnStrength;

  if (turnStrength == 0)
  {
    driver->numFramesSpentSteering = 10000;
  }
  else
  {
    if ((0 > turnStrength) && (driver->simpTurnState > -1))
    {
      uVar21 = uVar21 & 0xffffffef;
      driver->numFramesSpentSteering = 0;
    }
    else
    {
      if ((turnStrength > 0) && (1 > driver->simpTurnState))
      {
        uVar21 = uVar21 | 0x10;
        driver->numFramesSpentSteering = 0;
      }
    }
  }

  driver->simpTurnState = (char)turnStrength;
  iVar11 = VehPhysJoystick_GetStrengthAbsolute(iVar11,0x40,gamepad->rwd);
  newWheelRotation = VehCalc_InterpBySpeed(driver->wheelRotation,0x18,-iVar11);
  iVar11 = (int)driver->fireSpeed;
  driver->wheelRotation = newWheelRotation;
  uVar12 = driver->actionsFlagSetPrevFrame;
  if (0 > iVar11)
  {
    iVar11 = -iVar11;
  }
  if (((uVar12 & 1) != 0) && (kartState != 2))
  {
    iVar11 = (iVar11 + iVar13) >> 1;
  }
  else
  {
    iVar11 = iVar11 + 0xf00;
  }
  iVar11 = iVar11 * 0x89;
  rankItemValue = (short)((iVar11 + driver->unkSpeedValue2 * 0x177) * 8 >> 0xc);
  driver->unkSpeedValue2 = rankItemValue;
  if ((driver->actionsFlagSetPrevFrame & 8) == 0)
  {
    if (0 > iVar18)
    {
      iVar18 = -iVar18;
    }
    if ((iVar18 > 0x200) || (iVar13 > 0x200))
    {
      driver->unkSpeedValue1 = driver->unkSpeedValue1 - rankItemValue;
    }
  }
  if ((driver->unkSpeedValue1 > 0) || ((driver->tireColor & 1) != 0) || (kartState == 4))
  {
    driver->tireColor = 0x2e808080;
  }
  else
  {
    driver->unkSpeedValue1 = 0x1e00;
    driver->tireColor = 0x2e606061;
  }

  driver->actionsFlagSet = uVar21;
  return;
}
