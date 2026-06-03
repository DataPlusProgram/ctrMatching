#include "../../common.h"

typedef struct COLL_FIXED_PlayerSearchScratch {
    s16 startX;
    s16 startY;
    s16 startZ;
    u8 pad06[0x10 - 0x06];
    s16 endX;
    s16 endY;
    s16 endZ;
    u8 pad16[0x1C - 0x16];
    s16 hitPosX;
    s16 hitPosY;
    s16 hitPosZ;
    u16 collisionFlags;
    s32 collisionScale;
    s32 searchDepth;
    void *levelRoot;
    s16 bboxMinX;
    s16 bboxMinY;
    s16 bboxMinZ;
    s16 bboxMaxX;
    s16 bboxMaxY;
    s16 bboxMaxZ;
    s16 unk3C;
    s16 foundQuadblock;
    u8 pad40[0x70 - 0x40];
    s16 normalX;
    s16 normalY;
    s16 normalZ;
    u8 pad76[0x80 - 0x76];
    QuadBlock *quadblockHit;
    u8 pad84[0x88 - 0x84];
    void *seenInstances[15];
    s32 seenInstanceCount;
    s16 colorLerpA;
    s16 colorLerpB;
    u8 *color0;
    u8 *color1;
    u8 *color2;
    u8 padD8[0x1A4 - 0xD8];
    s32 stepFlags;
} COLL_FIXED_PlayerSearchScratch;

extern void COLL_FIXED_QUADBLK_TestTriangles(QuadBlock *quadBlock, COLL_FIXED_PlayerSearchScratch *scratch);
extern void COLL_SearchBSP_CallbackPARAM(void *bspRoot, void *bbox, void *callback, void *scratch);
extern void COLL_FIXED_BSPLEAF_TestQuadblocks(void *leaf, COLL_FIXED_PlayerSearchScratch *scratch);
extern void OtherFX_Play(s32 soundId, s32 count);
extern s32 OtherFX_Play_LowLevel(s32 soundId, s32 count, s32 flags);
extern Terrain *VehAfterColl_GetTerrain(u32 terrainId);
extern s32 VehCalc_MapToRange(s32 value, s32 inMin, s32 inMax, s32 outMin, s32 outMax);
extern void VehStuckProc_MaskGrab_Init(Thread *thread, Driver *driver);
extern s16 ratan2(s32 x, s32 y);
extern s32 D_800845A0[];
extern s32 HudAndDebugFlags;

void COLL_FIXED_PlayerSearch(Thread *thread, Driver *driver)
{
    COLL_FIXED_PlayerSearchScratch *scratch;
    GameTracker *gameTracker;
    Instance *inst;
    QuadBlock *currentBlock;
    QuadBlock *quadBlock;
    Terrain *terrainMeta;
    void *bspRoot;
    void *checkpointBase;
    void *checkpointEntry;
    s32 blendWeight;
    s32 blendX;
    s32 blendY;
    s32 blendZ;
    s32 deltaYSpeed;
    s32 vecX;
    s32 vecY;
    s32 vecZ;
    s32 absScreenOffset;
    s32 absSpeed;
    s32 terrainType;
    s32 soundFlags;
    s32 brightness;
    s32 clampedBrightness;
    s32 alphaTarget;
    s32 alphaDelta;
    s32 checkpointIndex;
    s32 tableWord;
    s32 spinX;
    s32 spinZ;
    s32 vecLength;
    u16 quadFlags;

    scratch = (COLL_FIXED_PlayerSearchScratch *)0x1F800108;
    gameTracker = gT;
    inst = thread->inst;

    driver->actionsFlagSet &= 0xFFFEFFFF;

    scratch->endX = (s16)(driver->posCurr.x >> 8);
    scratch->endY = (s16)((driver->posCurr.y >> 8) + 0x80);
    scratch->endZ = (s16)(driver->posCurr.z >> 8);

    scratch->startX = (s16)(driver->posCurr.x >> 8);
    scratch->startY = (s16)((driver->posCurr.y >> 8) - 0x100);
    scratch->startZ = (s16)(driver->posCurr.z >> 8);

    scratch->levelRoot = *(void **)gameTracker->level1;
    scratch->searchDepth = 0x10;
    scratch->collisionScale = 0x3000;
    scratch->collisionFlags = 0;

    if ((u8)gameTracker->numPlyrCurrGame < 3) {
        scratch->collisionFlags = 2;
    }

    scratch->unk3C = 0;
    scratch->foundQuadblock = 0;

    scratch->bboxMinX = scratch->endX;
    if (scratch->startX < scratch->endX) {
        scratch->bboxMinX = scratch->startX;
    }

    scratch->bboxMinY = scratch->endY;
    if (scratch->startY < scratch->endY) {
        scratch->bboxMinY = scratch->startY;
    }

    scratch->bboxMinZ = scratch->endZ;
    if (scratch->startZ < scratch->endZ) {
        scratch->bboxMinZ = scratch->startZ;
    }

    scratch->bboxMaxX = scratch->endX;
    if (scratch->endX < scratch->startX) {
        scratch->bboxMaxX = scratch->startX;
    }

    scratch->bboxMaxY = scratch->endY;
    if (scratch->endY < scratch->startY) {
        scratch->bboxMaxY = scratch->startY;
    }

    scratch->bboxMaxZ = scratch->endZ;
    if (scratch->endZ < scratch->startZ) {
        scratch->bboxMaxZ = scratch->startZ;
    }

    scratch->hitPosX = scratch->startX;
    scratch->hitPosY = scratch->startY;
    scratch->hitPosZ = scratch->startZ;

    if (driver->underDriver != NULL) {
        COLL_FIXED_QUADBLK_TestTriangles(driver->underDriver, scratch);
    }

    if ((scratch->foundQuadblock == 0) && (scratch->levelRoot != NULL)) {
        bspRoot = M2C_FIELD(scratch->levelRoot, void **, 0x18);
        if (bspRoot != NULL) {
            COLL_SearchBSP_CallbackPARAM(bspRoot, &scratch->bboxMinX, COLL_FIXED_BSPLEAF_TestQuadblocks, scratch);
        }
    }

    if (scratch->foundQuadblock == 0) {
        inst->bitCompressed_NormalVector_AndDriverIndex = ((driver->driverId + 1) << 24) | 0x4000;
        inst->flags &= ~0x4000;
        driver->quadBlockHeight = driver->posCurr.y - 0x10000;
    } else {
        quadBlock = scratch->quadblockHit;
        quadFlags = quadBlock->quadFlags;

        inst->bitCompressed_NormalVector_AndDriverIndex =
            (((u16)scratch->normalX >> 6) & 0xFF) |
            ((((u16)scratch->normalY >> 6) & 0xFF) << 8) |
            ((((u16)scratch->normalZ >> 6) & 0xFF) << 16) |
            ((driver->driverId + 1) << 24);

        driver->quadBlockHeight = ((s32)scratch->hitPosY) << 8;
        driver->unkAA |= 4;

        terrainType = quadBlock->terrainType;
        if ((terrainType == 0xE) || (terrainType == 4) || (terrainType == 0xD)) {
            inst->vertSplit = 0;
            inst->flags |= 0x2000;
        }

        if (((u8)gameTracker->numPlyrCurrGame < 2) && ((quadFlags & 0x2000) == 0)) {
            if ((quadFlags & 1) != 0) {
                inst->flags |= 0x4000;
                inst->vertSplit = M2C_FIELD(gameTracker->level1, u16 *, 0x186);
            } else if ((quadFlags & 4) != 0) {
                inst->flags |= 0x4000;
                inst->vertSplit = M2C_FIELD(gameTracker->level1, u16 *, 0x184);
            } else {
                inst->flags &= ~0x4000;
            }
        }

        vecX = (driver->axisAngle3NormalVec[0] * 5) + (scratch->normalX * 3);
        vecY = (driver->axisAngle3NormalVec[1] * 5) + (scratch->normalY * 3);
        vecZ = (driver->axisAngle3NormalVec[2] * 5) + (scratch->normalZ * 3);
        vecLength = VehCalc_FastSqrt((vecX * vecX) + (vecY * vecY) + (vecZ * vecZ), 0x18) >> 0xC;
        if (vecLength != 0) {
            driver->axisAngle3NormalVec[0] = (s16)((vecX << 0xC) / vecLength);
            driver->axisAngle3NormalVec[1] = (s16)((vecY << 0xC) / vecLength);
            driver->axisAngle3NormalVec[2] = (s16)((vecZ << 0xC) / vecLength);
        }

        if ((quadFlags & 0x80) != 0) {
            driver->actionsFlagSet |= 0x10000;
        }

        driver->underDriver = quadBlock;

        if ((driver->posCurr.y <= (driver->quadBlockHeight + 0x1000)) || ((terrainType == 0xE) && (driver->posCurr.y < 1))) {
            if ((quadFlags & 0x1000) != 0) {
                driver->normalVecUp.x = scratch->normalX;
                driver->normalVecUp.y = scratch->normalY;
                driver->normalVecUp.z = scratch->normalZ;
                driver->unkAA |= 8;
            }

            if (driver->currBlockTouching == NULL) {
                driver->currBlockTouching = quadBlock;
                driver->axisAngle1NormalVec.x = scratch->normalX;
                driver->axisAngle1NormalVec.y = scratch->normalY;
                driver->axisAngle1NormalVec.z = scratch->normalZ;
            }

            if ((scratch->color0 != NULL) && (scratch->color1 != NULL) && (scratch->color2 != NULL)) {
                s32 color0R;
                s32 color0G;
                s32 color0B;
                s32 colorR;
                s32 colorG;
                s32 colorB;

                color0R = scratch->color0[8];
                color0G = scratch->color0[9];
                color0B = scratch->color0[10];

                colorR =
                    ((scratch->colorLerpA * (scratch->color1[8] - color0R)) >> 12) +
                    ((scratch->colorLerpB * (scratch->color2[8] - color0R)) >> 12) +
                    color0R;

                colorG =
                    ((scratch->colorLerpA * (scratch->color1[9] - color0G)) >> 12) +
                    ((scratch->colorLerpB * (scratch->color2[9] - color0G)) >> 12) +
                    color0G;

                colorB =
                    ((scratch->colorLerpA * (scratch->color1[10] - color0B)) >> 12) +
                    ((scratch->colorLerpB * (scratch->color2[10] - color0B)) >> 12) +
                    color0B;

                if (colorR < 0) {
                    colorR = 0;
                }
                if (colorR > 0xFF) {
                    colorR = 0xFF;
                }

                if (colorG < 0) {
                    colorG = 0;
                }
                if (colorG > 0xFF) {
                    colorG = 0xFF;
                }

                if (colorB < 0) {
                    colorB = 0;
                }
                if (colorB > 0xFF) {
                    colorB = 0xFF;
                }

                brightness = 0xC00 - ((((colorR * 0x4C) >> 8) + ((colorG * 0x96) >> 8) + ((colorB * 0x1E) >> 8)) * 0x20);
                clampedBrightness = brightness;
                if (clampedBrightness < 0) {
                    clampedBrightness = 0;
                }

                alphaTarget = clampedBrightness << 3;
                if (brightness > 0x1000) {
                    clampedBrightness = 0x1000;
                    alphaTarget = 0x8000;
                }

                alphaDelta = (alphaTarget - clampedBrightness) * 8;
                driver->alphaScaleBackup = (s16)((((u16)driver->alphaScaleBackup * 200) + alphaDelta) >> 8);
                inst->alphaScale = (s16)((((u16)inst->alphaScale * 200) + alphaDelta) >> 8);
            }
        }
    }

    if ((driver->quadBlockHeight + 0x8000) < driver->posCurr.y) {
        driver->terrainMeta2 = VehAfterColl_GetTerrain(10);
    }

    if (driver->posCurr.y < ((M2C_FIELD(M2C_FIELD(scratch->levelRoot, void **, 0x18), s16 *, 6) - 0x40) << 8)) {
        driver->unkAA |= 1;
    }

    deltaYSpeed = driver->velocity.y - driver->ySpeed;

    if ((driver->currBlockTouching != NULL) && ((driver->unkAA & 9) == 0) && (driver->kartState != 5)) {
        driver->velocity.x += ((s32)driver->axisAngle1NormalVec.x) >> 1;
        driver->velocity.y += ((s32)driver->axisAngle1NormalVec.y) >> 1;
        driver->velocity.z += ((s32)driver->axisAngle1NormalVec.z) >> 1;
    }

    driver->xSpeed = driver->velocity.x;
    driver->ySpeed = driver->velocity.y;
    driver->zSpeed = driver->velocity.z;

    currentBlock = driver->currBlockTouching;
    if (currentBlock == NULL) {
        if (driver->jumpCooldownMs != 0) {
            driver->actionsFlagSet |= 0x80000;
        }

        if (driver->jumpUnknown != 0) {
            driver->actionsFlagSet |= 0x40;
        }

        driver->terrainMeta1 = VehAfterColl_GetTerrain(10);
        driver->currentTerrain = 10;
        driver->actionsFlagSet &= ~1;

        driver->jumpLandingBoost += gameTracker->elapsedTimeMS;
        driver->jumpCoyoteTimerMs -= gameTracker->elapsedTimeMS;
        if (driver->jumpCoyoteTimerMs < 0) {
            driver->jumpCoyoteTimerMs = 0;
        }

        blendWeight = 7;
        if (driver->jumpCoyoteTimerMs == 0) {
            driver->jumpCooldownMs = 0;
            driver->jumpUnknown = 0;
        }
    } else {
        quadFlags = currentBlock->quadFlags;

        if ((quadFlags & 0x200) == 0) {
            if ((driver->kartState != 5) && ((driver->unkAA & 1) == 0) && ((quadFlags & 0x1000) != 0)) {
                checkpointIndex = currentBlock->checkpointIndex;

                if (checkpointIndex == 0xFF) {
                    if ((u32)(gameTracker->levelID - 0x19) < 5U) {
                        driver->lastValid = currentBlock;
                    }
                } else {
                    checkpointBase = M2C_FIELD(gameTracker->level1, void **, 0x14C);
                    checkpointEntry = (s8 *)checkpointBase + (checkpointIndex * 0xC);

                    if (((driver->actionsFlagSet & 0x01000000) == 0) &&
                        (M2C_FIELD(checkpointEntry, u8 *, 8) > 1) &&
                        ((((u32)M2C_FIELD(checkpointBase, u16 *, 6) >> 2) << 3) < (driver->distanceToFinishCheckpoint - (M2C_FIELD(checkpointEntry, u16 *, 6) * 8)))) {
                        driver->unkAA |= 1;
                    } else {
                        u16 startCheckpointDist;

                        startCheckpointDist = M2C_FIELD(checkpointBase, u16 *, 6);
                        if ((driver->lastValid != NULL) &&
                            (M2C_FIELD(checkpointEntry, u16 *, 6) < (u16)(((u32)startCheckpointDist * 0xF) >> 4)) &&
                            (driver->lastValid->checkpointIndex != 0xFF) &&
                            ((u32)M2C_FIELD((s8 *)checkpointBase + (driver->lastValid->checkpointIndex * 0xC), u16 *, 6) + ((u32)startCheckpointDist >> 2) < (u32)M2C_FIELD(checkpointEntry, u16 *, 6))) {
                            driver->unkAA |= 1;
                        } else {
                            driver->lastValid = currentBlock;
                        }
                    }
                }
            }
        } else {
            driver->unkAA |= 1;
        }

        driver->jumpLandingBoost = 0;
        driver->actionsFlagSet &= 0xFFF7FFBF;

        if ((driver->unkAA & 8) == 0) {
            if (driver->jumpCooldownMs != 0) {
                driver->actionsFlagSet |= 0x80000;
            }

            if (driver->jumpUnknown != 0) {
                driver->actionsFlagSet |= 0x40;
            }

            driver->terrainMeta1 = VehAfterColl_GetTerrain(10);
            driver->currentTerrain = 10;
            driver->actionsFlagSet &= ~1;

            driver->jumpLandingBoost += gameTracker->elapsedTimeMS;
            driver->jumpCoyoteTimerMs -= gameTracker->elapsedTimeMS;
            if (driver->jumpCoyoteTimerMs < 0) {
                driver->jumpCoyoteTimerMs = 0;
            }

            blendWeight = 7;
            if (driver->jumpCoyoteTimerMs == 0) {
                driver->jumpCooldownMs = 0;
                driver->jumpUnknown = 0;
            }
        } else {
            if ((driver->driverRankItemValue == 2) || ((gameTracker->gameMode2 & 0x80000) != 0)) {
                driver->currentTerrain = 6;
                terrainType = 6;
            } else {
                terrainType = currentBlock->terrainType;
                if ((terrainType != 6) && (driver->currentTerrain == 6)) {
                    driver->fillerShort = -0x140;
                }

                driver->currentTerrain = (s8)terrainType;
            }

            terrainMeta = VehAfterColl_GetTerrain((u32)terrainType);
            driver->terrainMeta1 = terrainMeta;
            driver->terrainMeta2 = terrainMeta;
            driver->jumpCoyoteTimerMs = 0xA0;

            driver->actionsFlagSet |= 1;
            if ((driver->actionsFlagSetPrevFrame & 1) == 0) {
                absSpeed = deltaYSpeed;
                if (absSpeed < 0) {
                    absSpeed = -absSpeed;
                }
                driver->actionsFlagSet |= 0x83;
                driver->fillerShort = 0x140;

                soundFlags = VehCalc_MapToRange(absSpeed, 0x100, 0x3C00, 0x78, 0xFA) & 0xFF;
                if (driver->kartState != 5) {
                    soundFlags <<= 16;
                    if ((driver->actionsFlagSet & 0x10000) == 0) {
                        soundFlags |= 0x8080;
                    } else {
                        soundFlags |= 0x1008080;
                    }

                    OtherFX_Play_LowLevel(7, 1, soundFlags);
                }
            }

            blendWeight = 6;
        }
    }

    blendX = ((blendWeight * driver->axisAngle2NormalVec[0]) + ((8 - blendWeight) * driver->normalVecUp.x)) >> 3;
    blendY = ((blendWeight * driver->axisAngle2NormalVec[1]) + ((8 - blendWeight) * driver->normalVecUp.y)) >> 3;
    blendZ = ((blendWeight * driver->axisAngle2NormalVec[2]) + ((8 - blendWeight) * driver->normalVecUp.z)) >> 3;

    if (driver->hazardTimer > 0) {
        s32 addX;
        s32 addY;
        s32 addZ;

        tableWord = D_800845A0[(driver->hazardTimer * 0xC) & 0x3FF];
        addX = (s16)(tableWord >> 16);
        addZ = (s16)tableWord;
        if (((driver->hazardTimer * 0xC) & 0x400) == 0) {
            addX = addZ;
            addZ = tableWord >> 16;
            if (((driver->hazardTimer * 0xC) & 0x800) != 0) {
                addX = -addX;
                addZ = -addZ;
            }
        } else if (((driver->hazardTimer * 0xC) & 0x800) == 0) {
            addZ = -addZ;
        } else {
            addX = -addX;
        }
        addX = (addX * 0x19) >> 10;
        addZ = (addZ * 0x19) >> 10;

        gte_ldVXY0((u32)(u16)addX);
        gte_ldVZ0(addZ);
        gte_rtv0();
        read_mt(addX, addY, addZ);

        blendX += addX;
        blendY += addY;
        blendZ += addZ;
    }

    vecLength = VehCalc_FastSqrt((blendX * blendX) + (blendY * blendY) + (blendZ * blendZ), 0x18) >> 0xC;
    if (vecLength != 0) {
        driver->axisAngle2NormalVec[0] = (s16)((blendX << 0xC) / vecLength);
        driver->axisAngle2NormalVec[1] = (s16)((blendY << 0xC) / vecLength);
        driver->axisAngle2NormalVec[2] = (s16)((blendZ << 0xC) / vecLength);
    }

    tableWord = D_800845A0[(u16)driver->angle & 0x3FF];
    spinX = (s16)tableWord;
    spinZ = tableWord >> 16;
    if (((u16)driver->angle & 0x400) == 0) {
        vecX = spinX;
        vecZ = spinZ;
        if (((u16)driver->angle & 0x800) != 0) {
            vecX = -vecX;
            vecZ = -vecZ;
        }
    } else {
        vecX = spinZ;
        vecZ = -spinX;
        if (((u16)driver->angle & 0x800) == 0) {
        } else {
            vecX = -vecX;
            vecZ = spinX;
        }
    }
    driver->rotCurr[2] = ratan2(((-driver->axisAngle2NormalVec[0] * vecZ) + (driver->axisAngle2NormalVec[2] * vecX)) >> 12, driver->axisAngle2NormalVec[1]);

    if (driver->hazardTimer < 1) {
        if ((driver->actionsFlagSet & 1) != 0) {
            absSpeed = driver->speed;
            if (absSpeed < 0) {
                absSpeed = -absSpeed;
            }
            if (absSpeed > 0x1000) {
                absScreenOffset = driver->screenOffsetY;
                if (absScreenOffset < 0) {
                    absScreenOffset = -absScreenOffset;
                }
                if ((absScreenOffset < 4) && ((M2C_FIELD(driver->terrainMeta1, u32 *, 4) & 1) != 0)) {
                    driver->distanceFromGround = 4;
                }
                goto afterDistanceUpdate;
            }
        }

        driver->distanceFromGround = 0;
    } else {
        absScreenOffset = driver->screenOffsetY;
        if (absScreenOffset < 0) {
            absScreenOffset = -absScreenOffset;
        }
        if (absScreenOffset < 4) {
            driver->distanceFromGround = 4;
            if ((driver->kartState != 3) && (driver->screenOffsetY > 0)) {
                OtherFX_Play(0x10, 1);
            }
        }
    }

afterDistanceUpdate:
    absScreenOffset = driver->screenOffsetY;
    if (absScreenOffset < 0) {
        absScreenOffset = -absScreenOffset;
    }
    if (absScreenOffset > 9) {
        driver->distanceFromGround = 0;
    }

    if (driver->distanceFromGround == 0) {
        s32 newScreenOffset;

        newScreenOffset = driver->screenOffsetY - 4;
        if (driver->screenOffsetY > 0) {
            driver->screenOffsetY = (s8)newScreenOffset;
            if (newScreenOffset < 1) {
                driver->screenOffsetY = 0;
                if ((M2C_FIELD(driver->terrainMeta1, u32 *, 4) & 0x20) != 0) {
                    soundFlags = 0x808080;
                    if ((driver->actionsFlagSet & 0x10000) != 0) {
                        soundFlags = 0x1808080;
                    }

                    OtherFX_Play_LowLevel(M2C_FIELD(driver->terrainMeta1, u16 *, 0x32), 0, soundFlags);
                }
            }
        }

        newScreenOffset = driver->screenOffsetY - 4;
        driver->screenOffsetY = (s8)newScreenOffset;
        if (newScreenOffset < 0) {
            driver->screenOffsetY = 0;
        }
    } else {
        driver->distanceFromGround -= 1;
        driver->screenOffsetY += 3;
    }

    if ((driver->posCurr.y < -0x8000) && ((M2C_FIELD(gameTracker->level1, u32 *, 0xDC) & 2) != 0)) {
        driver->unkAA |= 1;
    }

    if ((driver->kartState != 5) &&
        ((driver->unkAA & 1) != 0) &&
        (driver->lastValid != NULL) &&
        ((HudAndDebugFlags & 0x1000) == 0) &&
        ((driver->stepFlagSet & 8) == 0)) {
        VehStuckProc_MaskGrab_Init(thread, driver);
    }
}
