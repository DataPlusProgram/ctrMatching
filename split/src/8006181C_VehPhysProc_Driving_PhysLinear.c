#include "../../common.h"

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
extern s32 D_8008D2B0;
extern void *gGamepads;

void VehPhysProc_Driving_PhysLinear(Thread *thread, Driver *driver) {
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    M2C_UNK var_a0_2;
    M2C_UNK var_a1_2;
    M2C_UNK var_a3_2;
    s16 temp_a0_2;
    s16 temp_a0_3;
    s16 temp_a1;
    s16 temp_a2;
    s16 temp_a3;
    s16 temp_s0;
    s16 temp_s0_3;
    s16 temp_s0_4;
    s16 temp_s0_5;
    s16 temp_s2;
    s16 temp_s3;
    s16 temp_t0;
    s16 temp_t1;
    s16 temp_t2;
    s16 temp_t3;
    s16 temp_t4;
    s16 temp_t5;
    s16 temp_t6;
    s16 temp_t7;
    s16 temp_v0_8;
    s16 temp_v1;
    s16 temp_v1_12;
    s16 var_a0;
    s16 var_a0_5;
    s16 var_a1;
    s16 var_a2;
    s16 var_a3;
    s16 var_s0;
    s16 var_s0_2;
    s16 var_s0_5;
    s16 var_s0_6;
    s16 var_s0_7;
    s16 var_s3;
    s16 var_s3_2;
    s16 var_s4;
    s16 var_s4_2;
    s16 var_s5;
    s16 var_s7;
    s16 var_t0;
    s16 var_t1;
    s16 var_t2;
    s16 var_t3;
    s16 var_t4;
    s16 var_t5;
    s16 var_t6;
    s16 var_t7;
    s16 var_t8;
    s16 var_v0_11;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 var_v0_4;
    s16 var_v0_7;
    s16 var_v0_8;
    s16 var_v1;
    s16 var_v1_2;
    s16 var_v1_3;
    s32 temp_a0;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_s0_2;
    s32 temp_s0_7;
    s32 temp_s0_8;
    s32 temp_s0_9;
    s32 temp_s2_2;
    s32 temp_s6;
    s32 temp_v0_10;
    s32 temp_v0_11;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_9;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 var_a0_4;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_a2_2;
    s32 var_lo;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s0_8;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s3_3;
    s32 var_v0;
    s32 var_v0_10;
    s32 var_v0_12;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_9;
    s32 var_v1_4;
    s32 var_v1_5;
    s8 temp_v1_11;
    s8 temp_v1_8;
    s8 temp_v1_9;
    u16 temp_a3_2;
    u16 temp_v0_2;
    u8 temp_s0_6;
    u8 temp_t8;
    u8 temp_v1_10;
    u8 temp_v1_7;
    void *temp_fp;
    void *temp_v0;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v1_3;
    void *temp_v1_5;
    void *temp_v1_6;
    void *var_a0_3;

    if (!(driver->actionsFlagSet & 0x40000)) {
        driver->timeElapsedInRace = (s32)M2C_FIELD(gGamepads, s32 *, 0x1D10);
    }
    temp_a0 = M2C_FIELD(gGamepads, s32 *, 0x1D04);
    temp_s6 = -temp_a0;
    if ((M2C_FIELD(gGamepads, s32 *, 0x1D10) <= 0x8C9FF) && !(driver->actionsFlagSet & 0x40000)) {
        driver->distanceDriven = (s32)(driver->distanceDriven + ((s32)(driver->speedApprox * temp_a0) >> 8));
    }
    temp_v1 = driver->reserves;
    temp_a0_2 = driver->turboOutsideTimer;
    temp_a1 = driver->vehFireAudioCooldown;
    temp_a2 = driver->set0xF0OnWallRub;
    temp_a3 = driver->jumpForcedMs;
    temp_t0 = driver->jumpCooldownMs;
    temp_t1 = driver->jumpUnknown;
    temp_t2 = driver->burnTimer;
    temp_t3 = driver->squishTimer;
    temp_t7 = driver->clockReceive;
    temp_s0 = driver->mashingXMakesItBig;
    temp_t4 = driver->startDriving0x60;
    temp_t5 = driver->startRollback0x280;
    temp_t6 = driver->superEngineTimer;
    temp_s2 = driver->jumpTenBuffer;
    var_v1 = temp_v1 + temp_s6;
    if (temp_v1 > 0) {
        if (var_v1 < 0) {
            var_v1 = 0;
        }
        driver->reserves = var_v1;
        driver->timeSpentUsingReserves = (s32)(driver->timeSpentUsingReserves - temp_s6);
    }
    var_a0 = temp_a0_2 + temp_s6;
    if (temp_a0_2 > 0) {
        if (var_a0 < 0) {
            var_a0 = 0;
        }
        driver->turboOutsideTimer = var_a0;
    }
    var_a1 = temp_a1 + temp_s6;
    if (temp_a1 > 0) {
        if (var_a1 < 0) {
            var_a1 = 0;
        }
        driver->vehFireAudioCooldown = var_a1;
    }
    var_a2 = temp_a2 + temp_s6;
    if (temp_a2 > 0) {
        if (var_a2 < 0) {
            var_a2 = 0;
        }
        driver->set0xF0OnWallRub = var_a2;
        driver->timeSpentAgainstWall = (s32)(driver->timeSpentAgainstWall - temp_s6);
    }
    var_a3 = temp_a3 + temp_s6;
    if (temp_a3 > 0) {
        if (var_a3 < 0) {
            var_a3 = 0;
        }
        driver->jumpForcedMs = var_a3;
    }
    var_t0 = temp_t0 + temp_s6;
    if (temp_t0 > 0) {
        if (var_t0 < 0) {
            var_t0 = 0;
        }
        driver->jumpCooldownMs = var_t0;
    }
    var_t1 = temp_t1 + temp_s6;
    if (temp_t1 > 0) {
        if (var_t1 < 0) {
            var_t1 = 0;
        }
        driver->jumpUnknown = var_t1;
    }
    var_t2 = temp_t2 + temp_s6;
    if (temp_t2 > 0) {
        if (var_t2 < 0) {
            var_t2 = 0;
        }
        driver->burnTimer = var_t2;
        driver->timeSpentBurnt = (s32)(driver->timeSpentBurnt - temp_s6);
    }
    var_t3 = temp_t3 + temp_s6;
    if (temp_t3 > 0) {
        if (var_t3 < 0) {
            var_t3 = 0;
        }
        driver->squishTimer = var_t3;
        driver->timeSpentSquished = (s32)(driver->timeSpentSquished - temp_s6);
    }
    var_t4 = temp_t4 + temp_s6;
    if (temp_t4 > 0) {
        if (var_t4 < 0) {
            var_t4 = 0;
        }
        driver->startDriving0x60 = var_t4;
    }
    var_t5 = temp_t5 + temp_s6;
    if (temp_t5 > 0) {
        if (var_t5 < 0) {
            var_t5 = 0;
        }
        driver->startRollback0x280 = var_t5;
    }
    if (!(M2C_FIELD(gGamepads, s32 *, 8) & 0x10000)) {
        var_t6 = temp_t6 + temp_s6;
        if (temp_t6 > 0) {
            if (var_t6 < 0) {
                var_t6 = 0;
            }
            driver->superEngineTimer = var_t6;
        }
    }
    var_t7 = temp_t7 + temp_s6;
    if (temp_t7 > 0) {
        if (var_t7 < 0) {
            var_t7 = 0;
        }
        driver->clockReceive = var_t7;
    }
    var_s0 = temp_s0 + temp_s6;
    if (temp_s0 > 0) {
        if (var_s0 < 0) {
            var_s0 = 0;
        }
        driver->mashingXMakesItBig = var_s0;
    }
    if (temp_s2 > 0) {
        driver->jumpTenBuffer = (s16)(temp_s2 - 1);
    }
    if (driver->numWumpas >= 0xA) {
        driver->timeSpentInTenWumpa = (s32)(driver->timeSpentInTenWumpa - temp_s6);
    }
    if ((u8)driver->currentTerrain == 0xE) {
        driver->timeSpentInMud = (s32)(driver->timeSpentInMud - temp_s6);
    }
    temp_a0_3 = driver->driverRank;
    switch (temp_a0_3) {                            /* irregular */
    case 7:
        if (M2C_FIELD(gGamepads, u8 *, 0x1CA8) != 1) {
            if (((temp_a0_3 == 5) && (M2C_FIELD(gGamepads, u8 *, 0x1CA8) == 2)) || ((temp_a0_3 == 3) && ((u8) M2C_FIELD(gGamepads, u8 *, 0x1CA8) >= 3U))) {
                goto block_74;
            }
        } else {
block_74:
            if (!(driver->actionsFlagSet & 0x40000)) {
                driver->timeSpentInLastPlace = (s32)(driver->timeSpentInLastPlace - temp_s6);
            }
        }
        break;
    }
    temp_v0 = driver->thCloud;
    var_s4 = 4;
    if (temp_v0 != NULL) {
        var_s4 = M2C_FIELD(M2C_FIELD(temp_v0, void **, 0x30), s16 *, 6);
    }
    var_t8 = driver->speedApprox;
    temp_s2_2 = driver->actionsFlagSet;
    var_s0_2 = driver->clockReceive;
    driver->driverRankItemValue = var_s4;
    if (var_t8 < 0) {
        var_t8 = -var_t8;
    }
    sp20 = (s32) var_t8;
    if (var_s0_2 == 0) {
        var_s0_2 = driver->squishTimer;
        var_v0 = temp_s2_2 & 1;
        if (var_s0_2 == 0) {
            if (var_s4 == 0) {
                var_s0_2 = (s16) M2C_FIELD(gGamepads, s32 *, 0x1D10);
                if (var_s0_2 != 0) {
                    goto block_84;
                }
            }
            var_v1_2 = driver->hazardTimer;
            if (sp20 >= 0x101) {
                var_v1_2 += temp_s6;
            }
            var_v1_3 = var_v1_2 & ~1;
            if (var_v1_3 >= 0) {
                var_v1_3 = -2;
            }
            driver->hazardTimer = var_v1_3;
        } else {
            goto block_85;
        }
    } else {
block_84:
        var_v0 = temp_s2_2 & 1;
block_85:
        if (var_v0 != 0) {
            if (sp20 >= 0x101) {
                temp_v0_2 = (u16)driver->clockReceive;
                var_s3 = var_s0_2;
                if (var_s0_2 < 0) {
                    var_s3 = -var_s3;
                }
                var_a2_2 = (s32) (temp_v0_2 << 0x10) >> 0x16;
                if (var_a2_2 >= 0x41) {
                    var_a2_2 = 0x40;
                }
                temp_s0_2 = (s16) temp_v0_2 * 0x10;
                var_v1_4 = *(((temp_s0_2 & 0x3FF) * 4) + &D_800845A0);
                if (!(temp_s0_2 & 0x400)) {
                    var_v1_4 <<= 0x10;
                }
                var_v1_5 = var_v1_4 >> 0x10;
                if (temp_s0_2 & 0x800) {
                    var_v1_5 = -var_v1_5;
                }
                var_s0_3 = sp20 >> 8;
                if (var_s0_3 >= 0x21) {
                    var_s0_3 = 0x20;
                }
                GAMEPAD_ShockForce1(driver, 4, var_a2_2 + (var_v1_5 >> 5) + var_s0_3 + 0x18, var_a3);
                var_v0_2 = var_s3 | 1;
            } else {
                goto block_102;
            }
        } else {
            if (sp20 >= 0x101) {
                var_v0_3 = var_s0_2;
                if (var_s0_2 < 0) {
                    var_v0_3 = -var_v0_3;
                }
                var_s3_2 = -var_v0_3;
                goto block_104;
            }
block_102:
            temp_s3 = driver->hazardTimer;
            var_v0_2 = temp_s3 | 1;
            if (temp_s3 > 0) {
                var_s3_2 = -temp_s3;
block_104:
                var_v0_2 = var_s3_2 | 1;
            }
        }
        driver->hazardTimer = var_v0_2;
    }
    if ((u8)driver->heldItemId == 0x10) {
        temp_s0_3 = driver->itemRollTimer;
        if (temp_s0_3 != 0) {
            driver->itemRollTimer = (s16)(temp_s0_3 - 1);
        } else {
            VehPhysGeneral_SetHeldItem(driver);
            var_a0_2 = 0x5E;
            if (driver->numWumpas >= 0xA) {
                var_a0_2 = 0x41;
                var_a1_2 = 1;
            } else {
                var_a1_2 = 0;
            }
            OtherFX_Play(var_a0_2, var_a1_2);
        }
    }
    temp_s0_4 = driver->noItemTimer;
    if (temp_s0_4 != 0) {
        var_v0_4 = temp_s0_4 - 1;
        if (temp_s0_4 == 1) {
            var_v0_4 = temp_s0_4 - 1;
            if ((u8)driver->numHeldItems == 0) {
                if (((u8)M2C_FIELD(gGamepads, u8 *, 0x1CA8) >= 3U) && !(M2C_FIELD(gGamepads, s32 *, 0) & 0x20) && ((u8)driver->heldItemId == 0xB)) {
                    temp_v0_3 = M2C_FIELD(gGamepads, s32 *, 0x1EC4);
                    if (temp_v0_3 > 0) {
                        M2C_FIELD(gGamepads, s32 *, 0x1EC4) = (s32) (temp_v0_3 - 1);
                    }
                }
                driver->heldItemId = 0xF;
                var_v0_4 = temp_s0_4 - 1;
            }
        }
        driver->noItemTimer = var_v0_4;
    }
    temp_v1_2 = driver->invincibleTimer;
    if (temp_v1_2 != 0) {
        temp_v0_4 = temp_v1_2 - M2C_FIELD(gGamepads, s32 *, 0x1D04);
        driver->invincibleTimer = temp_v0_4;
        if (temp_v0_4 < 0) {
            driver->invincibleTimer = 0;
        }
    }
    temp_a0_4 = driver->invisibleTimer;
    if ((temp_a0_4 != 0) && !(M2C_FIELD(gGamepads, s32 *, 8) & 0x8000)) {
        temp_v0_5 = temp_a0_4 - M2C_FIELD(gGamepads, s32 *, 0x1D04);
        driver->invisibleTimer = temp_v0_5;
        if (temp_v0_5 < 0) {
            driver->invisibleTimer = 0;
        }
        if (driver->invisibleTimer == 0) {
            M2C_FIELD(driver->instSelf, s32 *, 0x28) = (s32)driver->instFlagsBackup;
            M2C_FIELD(driver->instSelf, s16 *, 0x22) = 0;
            OtherFX_Play(0x62, 1);
        }
    }
    temp_a3_2 = (u16)driver->turnAngleCurr;
    driver->rotPrev[0] = driver->rotCurr[0];
    driver->actionsFlagSetPrevFrame = temp_s2_2;
    driver->posPrev.y = driver->posCurr.y;
    driver->posPrev.z = driver->posCurr.z;
    driver->rotPrev[2] = driver->rotCurr[2];
    driver->jumpHeightPrev = (u16)driver->jumpHeightCurr;
    driver->turnAnglePrev = temp_a3_2;
    driver->posPrev.x = driver->posCurr.x;
    var_s2 = temp_s2_2 & 0x7F1F83D5;
    if (!(M2C_FIELD(gGamepads, s32 *, 8) & 0x4004)) {
        var_s0_4 = (u8)driver->normalVecId + 1;
        var_v0_5 = var_s0_4 * 8;
        if (var_s0_4 > 0) {
            var_s0_4 = 0;
            var_v0_5 = 0 * 8;
        }
        temp_v1_3 = ((s8 *)driver) + (var_v0_5 + 0x378);
        if (var_s2 & 1) {
            M2C_FIELD(temp_v1_3, s16 *, 0) = driver->axisAngle1NormalVec.x;
            M2C_FIELD(temp_v1_3, s16 *, 2) = driver->axisAngle1NormalVec.y;
            M2C_FIELD(temp_v1_3, s16 *, 4) = driver->axisAngle1NormalVec.z;
        } else {
            M2C_FIELD(temp_v1_3, s16 *, 0) = driver->axisAngle2NormalVec[0];
            M2C_FIELD(temp_v1_3, s16 *, 2) = driver->axisAngle2NormalVec[1];
            M2C_FIELD(temp_v1_3, s16 *, 4) = driver->axisAngle2NormalVec[2];
        }
        driver->normalVecId = (u8)var_s0_4;
        var_a0_3 = thread->childThread;
        if (var_a0_3 != NULL) {
loop_146:
            temp_s0_5 = ((Thread *)var_a0_3)->modelIndex;
            if ((temp_s0_5 == 0x3A) || (temp_s0_5 == 0x39)) {
                var_s2 |= 0x800000;
            } else {
                var_a0_3 = ((Thread *)var_a0_3)->siblingThread;
                if (var_a0_3 != NULL) {
                    goto loop_146;
                }
            }
        }
        temp_fp = D_8008D2B0 + (((u8)driver->driverId) * 0x50);
        temp_v1_4 = M2C_FIELD(gGamepads, s32 *, 0) & 0x200000;
        var_a1_3 = 0;
        if (temp_v1_4 == 0) {
            var_a1_3 = M2C_FIELD(temp_fp, s32 *, 0x10);
        }
        var_a0_4 = 0;
        if (temp_v1_4 == 0) {
            var_a0_4 = M2C_FIELD(temp_fp, s32 *, 0x14);
        }
        sp18 = var_a1_3 & 0x10;
        sp1C = var_a1_3 & 0x20;
        temp_t8 = (u8)driver->kartState;
        sp24 = (s32) temp_t8;
        if (var_a0_4 & 0x40) {
            if ((temp_t8 == 0) || (temp_t8 == 2) || (var_s0_5 = var_a0_4 & 0xC00, (temp_t8 == 9))) {
                var_s0_5 = var_a0_4 & 0xC00;
                if (driver->instTntRecv == 0) {
                    temp_v0_6 = driver->instBombThrow;
                    if (temp_v0_6 != NULL) {
                        temp_v1_5 = M2C_FIELD(M2C_FIELD(temp_v0_6, void **, 0x6C), void **, 0x30);
                        M2C_FIELD(temp_v1_5, u16 *, 0x16) = (u16) (M2C_FIELD(temp_v1_5, u16 *, 0x16) | 2);
                        driver->instBombThrow = NULL;
                    } else {
                        temp_v0_7 = driver->instBubbleHold;
                        if (temp_v0_7 != NULL) {
                            temp_v1_6 = M2C_FIELD(M2C_FIELD(temp_v0_7, void **, 0x6C), void **, 0x30);
                            M2C_FIELD(temp_v1_6, u16 *, 6) = (u16) (M2C_FIELD(temp_v1_6, u16 *, 6) | 2);
                            driver->instBubbleHold = NULL;
                            goto block_181;
                        }
                        temp_v0_8 = driver->itemRollTimer;
                        var_v0_6 = temp_v0_8 < 0x46;
                        if (temp_v0_8 == 0) {
                            temp_v1_7 = (u8)driver->heldItemId;
                            if ((temp_v1_7 != 0xF) && (temp_v1_7 != 0x10) && (driver->noItemTimer == 0) && (var_s4 != 1) && (driver->clockReceive == 0)) {
                                temp_s0_6 = (u8)driver->numHeldItems;
                                var_s2 |= 0x8000;
                                if (temp_s0_6 != 0) {
                                    if (temp_v1_7 == 5) {
                                        if (driver->jumpCoyoteTimerMs != 0) {
                                            var_v0_7 = driver->jumpCooldownMs;
                                            goto block_174;
                                        }
                                    } else {
                                        var_v0_7 = M2C_FIELD(gGamepads, s32 *, 8) & 0x400C00;
block_174:
                                        if (var_v0_7 == 0) {
                                            driver->numHeldItems = (u8)(temp_s0_6 - 1);
                                        }
                                    }
                                    driver->noItemTimer = 5;
                                } else {
                                    driver->noItemTimer = 0x1E;
                                }
                                goto block_181;
                            }
                            var_v0_6 = driver->itemRollTimer < 0x46;
                            goto block_179;
                        }
block_179:
                        var_s0_5 = var_a0_4 & 0xC00;
                        if (var_v0_6 != 0) {
                            driver->itemRollTimer = 0;
                            goto block_181;
                        }
                    }
                }
            }
        } else {
block_181:
            var_s0_5 = var_a0_4 & 0xC00;
        }
        if ((var_s0_5 != 0) && ((u8)driver->kartState != 2)) {
            if (var_s0_5 == 0xC00) {
                driver->buttonUsedToStartDrift = 0x400;
            } else {
                driver->buttonUsedToStartDrift = var_s0_5;
            }
            if (var_s4 != 3) {
                driver->jumpTenBuffer = 0xA;
                goto block_193;
            }
        } else if ((var_a1_3 & 0xC00) && (var_s4 != 3)) {
            if (!(var_s2 & 4)) {
                driver->jumpTenBuffer = 0xA;
            }
block_193:
            var_s2 |= 4;
        } else {
            var_s2 &= ~4;
            if (driver->jumpTenBuffer > 0) {
                driver->jumpTenBuffer = 0;
            }
        }
        if ((sp1C != 0) && !(driver->stepFlagSet & 3)) {
            driver->reserves = 0;
        }
        var_s5 = 0x80;
        if (!(M2C_FIELD(gGamepads, s32 *, 0) & 0x200000)) {
            var_s5 = M2C_FIELD(temp_fp, s16 *, 0xE);
        }
        if ((driver->reserves != 0) || (var_s4 == 6)) {
            if ((sp18 == 0) && (-VehPhysJoystick_ReturnToRest(var_s5, 0x80, 0, temp_a3_2) <= 0)) {
                var_s2 |= 0x400000;
            }
            if ((sp1C != 0) && (sp20 >= 0x301)) {
                var_s2 |= 0x800;
            }
            if (driver->stepFlagSet & 3) {
                sp1C = 0;
            }
            sp18 = 0x10;
        }
        var_s4_2 = 0x80;
        if (!(M2C_FIELD(gGamepads, s32 *, 0) & 0x200000)) {
            var_s4_2 = M2C_FIELD(temp_fp, s16 *, 6);
        }
        temp_v1_8 = driver->simpTurnState;
        if ((temp_v1_8 < 0) || (var_s2 &= 0xDFFFFFFF, (temp_v1_8 <= 0))) {
            var_s2 &= 0xBFFFFFFF;
        }
        var_v0_8 = driver->speedApprox;
        if (var_v0_8 < 0) {
            var_v0_8 = -var_v0_8;
        }
        if (var_v0_8 < 0x300) {
            var_s2 &= 0x9FFFFFFF;
        }
        var_s3_3 = 0;
        var_s7 = VehPhysGeneral_GetBaseSpeed(driver);
        if (sp1C != 0) {
            temp_v0_9 = VehPhysJoystick_ReturnToRest(var_s4_2, 0x80, 0);
            if ((temp_v0_9 >= 0x64) || ((temp_v0_9 > 0) && (var_s2 & 0x20000))) {
                temp_v0_10 = driver->constBackwardSpeed * -3;
                var_s3_3 = temp_v0_10 >> 2;
                if (temp_v0_10 < 0) {
                    var_s3_3 = (s32) (temp_v0_10 + 3) >> 2;
                }
                goto block_236;
            }
            var_s3_3 = var_s7 / 2;
            if (sp18 != 0) {
                var_s2 |= 0x20;
                goto block_249;
            }
            temp_s0_7 = -VehPhysJoystick_ReturnToRest(var_s5, 0x80, 0);
            temp_lo = var_s7 * temp_s0_7;
            if (temp_s0_7 > 0) {
                var_s3_3 = temp_lo >> 8;
                if (temp_lo < 0) {
                    var_s3_3 = (s32) (temp_lo + 0xFF) >> 8;
                }
                var_s2_2 = var_s2 | 0x20;
            } else if (temp_s0_7 < 0) {
                temp_lo_2 = driver->constBackwardSpeed * temp_s0_7;
                var_s3_3 = temp_lo_2 >> 8;
                if (temp_lo_2 < 0) {
                    var_s3_3 = (s32) (temp_lo_2 + 0xFF) >> 8;
                }
block_236:
                var_s2_2 = var_s2 | 0x20020;
            } else {
                var_s2 |= 8;
                goto block_249;
            }
            goto block_250;
        }
        if (sp18 != 0) {
            var_s3_3 = (s32) var_s7;
            goto block_249;
        }
        temp_s0_8 = -VehPhysJoystick_ReturnToRest(var_s5, 0x80, 0);
        if (temp_s0_8 >= 0) {
            var_lo = var_s7 * temp_s0_8;
            if (temp_s0_8 == 0) {
                temp_v0_11 = VehPhysJoystick_ReturnToRest(var_s4_2, 0x80, 0);
                if (temp_v0_11 < 0x64) {
                    if (temp_v0_11 > 0) {
                        var_lo = var_s7 * temp_s0_8;
                        if (var_s2 & 0x20000) {
                            goto block_245;
                        }
                        goto block_247;
                    }
                    var_lo = var_s7 * temp_s0_8;
                    goto block_247;
                }
block_245:
                var_s2_2 = var_s2 | 0x20000;
                var_s3_3 = (s32)-driver->constBackwardSpeed;
            } else {
block_247:
                var_s3_3 = var_lo >> 7;
                if (var_lo < 0) {
                    var_s3_3 = (s32) (var_lo + 0x7F) >> 7;
                }
block_249:
                var_s2_2 = var_s2 & 0xFFFDFFFF;
            }
block_250:
            var_s2 = var_s2_2 & 0x9FFFFFFF;
        } else if ((driver->speedApprox >= 0x301) || (var_s2 & 0x60000000)) {
            temp_v1_9 = driver->simpTurnState;
            var_s2 |= 8;
            if (temp_v1_9 > 0) {
                var_s2 |= 0x40000000;
            }
            if (temp_v1_9 < 0) {
                var_v0_9 = 0x20000000;
                goto block_260;
            }
        } else {
            temp_lo_3 = driver->constBackwardSpeed * temp_s0_8;
            var_s3_3 = temp_lo_3 >> 7;
            if (temp_lo_3 < 0) {
                var_s3_3 = (s32) (temp_lo_3 + 0x7F) >> 7;
            }
            var_v0_9 = 0x20000;
block_260:
            var_s2 |= var_v0_9;
        }
        if (var_s2 & 0x20000) {
            driver->timeSpentReversing = (s32)(driver->timeSpentReversing - temp_s6);
            goto block_270;
        }
        var_v0_10 = var_s2 & 8;
        if (driver->superEngineTimer != 0) {
            if (var_s3_3 > 0) {
                var_v0_10 = var_s2 & 8;
                if (!(var_s2 & 0x400020)) {
                    var_a3_2 = 0x80;
                    driver->actionsFlagSet = var_s2;
                    if (driver->numWumpas >= 0xA) {
                        var_a3_2 = 0x100;
                    }
                    VehFire_Increment(driver, 0x78, 0x14, var_a3_2);
                    var_s2 = driver->actionsFlagSet;
                    goto block_270;
                }
            } else {
block_270:
                var_v0_10 = var_s2 & 8;
            }
        }
        if (var_v0_10 != 0) {
            var_v0_11 = driver->speedApprox;
            if (var_v0_11 < 0) {
                var_v0_11 = -var_v0_11;
            }
            if (var_v0_11 >= 0x301) {
                driver->timeSpentWithHighSpeed = (s32)(driver->timeSpentWithHighSpeed - temp_s6);
            }
        }
        if ((driver->mashingXMakesItBig == 0) || ((temp_v1_10 = (u8)driver->kartState, (temp_v1_10 != 0)) && (temp_v1_10 != 9))) {
            driver->mashXUnknown = 0U;
        }
        if (driver->fireSpeed > 0) {
            if (var_s3_3 > 0) {
                driver->fireSpeed = (s16)var_s3_3;
            } else {
                goto block_284;
            }
        } else {
            if (var_s3_3 > 0) {
block_284:
                if (driver->mashingXMakesItBig != 0) {
                    driver->mashXUnknown = (u16)(driver->mashXUnknown + 1);
                }
                driver->mashingXMakesItBig = 0x100;
            }
            driver->fireSpeed = (s16)var_s3_3;
        }
        if (!(var_s2 & 0x800020)) {
            temp_s0_9 = M2C_FIELD(driver->terrainMeta2, s32 *, 8);
            if (temp_s0_9 != 0x100) {
                var_s3_3 = (s32) (temp_s0_9 * var_s3_3) >> 8;
                var_s7 = (s16) ((s32) (temp_s0_9 * var_s7) >> 8);
            }
        }
        driver->unknownDriverBaseSpeed = var_s7;
        driver->baseSpeed = (s16)var_s3_3;
        var_s0_6 = 0x80;
        if (!(M2C_FIELD(gGamepads, s32 *, 0) & 0x200000)) {
            var_s0_6 = M2C_FIELD(temp_fp, s16 *, 4);
        }
        if (((s16)driver->mashXUnknown >= 7) && (sp20 < 0x2600)) {
            var_a1_4 = 0x5A;
        } else if (driver->set0xF0OnWallRub != 0) {
            var_a1_4 = 0x30;
        } else {
            var_a1_4 = (u8)driver->constTurnRate + ((driver->turnConst * 2) / 5);
            if (var_s2 & 0x28) {
                if (sp18 != 0) {
                    var_a0_5 = driver->speed;
                    if (var_a0_5 < 0) {
                        var_a0_5 = -var_a0_5;
                    }
                    var_a1_4 = VehCalc_MapToRange(var_a0_5, 0x300, (s32)((u16)driver->constSpeedClassStat << 0x10) >> 0x11, 0x40);
                } else {
                    var_a1_4 = 0x40;
                }
            }
        }
        temp_v1_11 = -VehPhysJoystick_GetStrengthAbsolute(var_s0_6, var_a1_4, M2C_FIELD(temp_fp, s32 *, 0x4C));
        if (temp_v1_11 == 0) {
            driver->numFramesSpentSteering = 0x2710;
        } else {
            if ((temp_v1_11 < 0) && (driver->simpTurnState >= 0)) {
                var_s2 &= ~0x10;
                goto block_313;
            }
            if ((temp_v1_11 > 0) && (driver->simpTurnState <= 0)) {
                var_s2 |= 0x10;
block_313:
                driver->numFramesSpentSteering = 0;
            }
        }
        driver->simpTurnState = temp_v1_11;
        temp_v1_12 = driver->fireSpeed;
        driver->wheelRotation = VehCalc_InterpBySpeed(driver->wheelRotation, 0x18, -VehPhysJoystick_GetStrengthAbsolute(var_s0_6, 0x40, M2C_FIELD(temp_fp, s32 *, 0x4C)));
        var_s0_7 = temp_v1_12;
        if (temp_v1_12 < 0) {
            var_s0_7 = -var_s0_7;
        }
        if ((driver->actionsFlagSetPrevFrame & 1) && (sp24 != 2)) {
            var_s0_8 = (s32) (var_s0_7 + sp20) >> 1;
        } else {
            var_s0_8 = var_s0_7 + 0xF00;
        }
        temp_a0_5 = (s32)(((var_s0_8 * 0x89) + (driver->unkSpeedValue2 * 0x177)) * 8) >> 0xC;
        driver->unkSpeedValue2 = (s16)temp_a0_5;
        if (!(driver->actionsFlagSetPrevFrame & 8)) {
            var_v0_12 = var_s3_3;
            if (var_s3_3 < 0) {
                var_v0_12 = -var_v0_12;
            }
            if ((var_v0_12 >= 0x201) || (sp20 >= 0x201)) {
                driver->unkSpeedValue1 = (u16)(driver->unkSpeedValue1 - temp_a0_5);
            }
        }
        if (((s16)driver->unkSpeedValue1 <= 0) && !(driver->tireColor & 1)) {
            if (sp24 == 4) {
                goto block_331;
            }
            driver->unkSpeedValue1 = 0x1E00U;
            driver->tireColor = 0x2E606061;
        } else {
block_331:
            driver->tireColor = 0x2E808080;
        }
    }
    driver->actionsFlagSet = var_s2;
}
