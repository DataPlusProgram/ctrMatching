#include "../../common.h"

typedef struct LevModelMeta {
    u8 pad[8];
    s32 (*collisionFunc)(void *modelData, void *collider, void *scratch);
} LevModelMeta;

extern LevModelMeta *COLL_LevModelMeta(s32 levelId);
extern s32 COLL_MOVED_ScrubImpact(Driver *driver, void *collider, void *scratch, s32 surfaceType, Vec3 *velocity);
extern void COLL_SearchBSP_CallbackPARAM(void *bspRoot, void *bbox, void *callback, void *scratch);
extern void COLL_Unknown_80020334(void *hit, s32 hitType, void *scratch);
extern s32 VehAfterColl_GetSurface(s32 terrainType);
extern void COLL_MOVED_BSPLEAF_TestQuadblocks(void);
extern GameTracker *gT;

typedef struct COLL_MOVED_PlayerSearchScratch {
    s16 endX;
    s16 endY;
    s16 endZ;
    s16 bboxRadius;
    s32 bboxHeight;
    s16 scrubMeta;
    u16 terrainFlagMask;
    s16 startX;
    s16 startY;
    s16 startZ;
    s16 startRadius;
    s32 startHeight;
    s16 hitPosX;
    s16 hitPosY;
    s16 hitPosZ;
    u16 collisionFlags;
    s32 collisionScale;
    s32 unk28;
    s32 levelRootValue;
    s16 bboxMinX;
    s16 bboxMinY;
    s16 bboxMinZ;
    s16 bboxMaxX;
    s16 bboxMaxY;
    s16 bboxMaxZ;
    s16 touchedWall;
    s16 foundQuadblock;
    s16 foundInstance;
    s16 foundHitType;
    u8 pad44[4];
    void *hitInstance;
    u8 pad4C[0x68 - 0x4C];
    SVec3 hitPos;
    s16 hitPosPad;
    SVec3 normalVec;
    u8 pad76[0x7F - 0x76];
    u8 quadblockHitType;
    QuadBlock *quadblockHit;
    s32 collisionLerp;
    void *seenInstances[15];
    s32 seenInstanceCount;
    u8 padC8[0x1A4 - 0xC8];
    s32 stepFlags;
} COLL_MOVED_PlayerSearchScratch;

void COLL_MOVED_PlayerSearch(void *collider, Driver *driver)
{
    GameTracker *gGT;
    COLL_MOVED_PlayerSearchScratch *scratch;
    void *colliderLocal;
    u16 collisionFlags;
    s16 startX;
    s16 startY;
    s16 endX;
    s16 endY;
    s16 hitModelId;
    s32 hitType;
    s32 moveX;
    s32 moveY;
    s32 moveZ;
    s32 motionScale;
    s32 terrainType;
    s32 collisionResult;
    s32 iterationCount;
    void *bspRoot;
    void *instanceData;
    LevModelMeta *levModelMeta;
    QuadBlock *quadBlock;

    colliderLocal = collider;
    gGT = gT;
    scratch = (COLL_MOVED_PlayerSearchScratch *)0x1F800108;

    scratch->bboxRadius = 0x19;
    scratch->bboxHeight = 0x271;
    scratch->startRadius = 0x19;
    scratch->startHeight = 0x271;
    scratch->collisionScale = 0x3000;
    scratch->unk28 = 0;
    scratch->collisionFlags = 1;
    scratch->levelRootValue = *(s32 *)gGT->level1;

    if ((u8)gGT->numPlyrCurrGame < 3) {
        scratch->collisionFlags = 3;
    }

    motionScale = 0x1000;
    scratch->seenInstanceCount = 0;
    scratch->scrubMeta = 0x18;
    scratch->stepFlags = 0;
    COLL_Unknown_80020334(NULL, 0, scratch);

    iterationCount = 0xF;

    while (iterationCount != 0) {
        moveX = ((driver->velocity.x * gGT->elapsedTimeMS) >> 5) * motionScale >> 12;
        moveY = ((driver->velocity.y * gGT->elapsedTimeMS) >> 5) * motionScale >> 12;
        moveZ = ((driver->velocity.z * gGT->elapsedTimeMS) >> 5) * motionScale >> 12;

        scratch->touchedWall = 0;
        scratch->foundQuadblock = 0;
        scratch->foundInstance = 0;
        scratch->foundHitType = 0;
        scratch->collisionFlags |= 1;
        scratch->collisionLerp = 0x1000;

        startX = driver->originToCenter.x + (driver->posCurr.x >> 8);
        startY = driver->originToCenter.y + (driver->posCurr.y >> 8);

        scratch->startX = startX;
        scratch->startY = startY;
        scratch->startZ = driver->originToCenter.z + (driver->posCurr.z >> 8);

        endX = driver->originToCenter.x + ((driver->posCurr.x + moveX) >> 8);
        endY = driver->originToCenter.y + ((driver->posCurr.y + moveY) >> 8);

        scratch->endX = endX;
        scratch->endY = endY;
        scratch->endZ = driver->originToCenter.z + ((driver->posCurr.z + moveZ) >> 8);

        if ((scratch->endX == scratch->startX) &&
            (scratch->endY == scratch->startY) &&
            (scratch->endZ == scratch->startZ)) {
            collisionFlags = scratch->collisionFlags;
            break;
        }

        hitType = scratch->startX - scratch->startRadius;
        if ((scratch->endX - scratch->bboxRadius) < hitType) {
            hitType = scratch->endX - scratch->bboxRadius;
        }
        scratch->bboxMinX = hitType;

        hitType = scratch->startY - scratch->startRadius;
        if ((scratch->endY - scratch->bboxRadius) < hitType) {
            hitType = scratch->endY - scratch->bboxRadius;
        }
        scratch->bboxMinY = hitType;

        hitType = scratch->startZ - scratch->startRadius;
        if ((scratch->endZ - scratch->bboxRadius) < hitType) {
            hitType = scratch->endZ - scratch->bboxRadius;
        }
        scratch->bboxMinZ = hitType;

        hitType = scratch->startX + scratch->startRadius;
        if (hitType < (scratch->endX + scratch->bboxRadius)) {
            hitType = scratch->endX + scratch->bboxRadius;
        }
        scratch->bboxMaxX = hitType;

        hitType = scratch->startY + scratch->startRadius;
        if (hitType < (scratch->endY + scratch->bboxRadius)) {
            hitType = scratch->endY + scratch->bboxRadius;
        }
        scratch->bboxMaxY = hitType;

        hitType = scratch->startZ + scratch->startRadius;
        if (hitType < (scratch->endZ + scratch->bboxRadius)) {
            hitType = scratch->endZ + scratch->bboxRadius;
        }
        scratch->bboxMaxZ = hitType;

        scratch->hitPosX = scratch->endX;
        scratch->hitPosY = scratch->endY;
        scratch->hitPosZ = scratch->endZ;

        if (scratch->foundQuadblock == 0) {
            scratch->collisionFlags = (scratch->collisionFlags | 1) & 0xFFF7;

            bspRoot = gGT->level1;
            if (bspRoot != NULL) {
                bspRoot = M2C_FIELD(bspRoot, void **, 0x0);
                if (bspRoot != NULL) {
                    bspRoot = M2C_FIELD(bspRoot, void **, 0x18);
                    if (bspRoot != NULL) {
                        COLL_SearchBSP_CallbackPARAM(bspRoot, &scratch->bboxMinX, COLL_MOVED_BSPLEAF_TestQuadblocks, scratch);
                    }
                }
            }
        }

        if (scratch->foundQuadblock != 0) {
            M2C_FIELD(driver, u16 *, 0xAA) |= 4;
        }

        if (scratch->collisionLerp > 0) {
            driver->posCurr.x += (moveX * scratch->collisionLerp) >> 12;
            driver->posCurr.y += (moveY * scratch->collisionLerp) >> 12;
            driver->posCurr.z += (moveZ * scratch->collisionLerp) >> 12;
        }

        if (scratch->foundHitType != 0) {
            scratch->collisionFlags &= 0xFFF7;
            M2C_FIELD(driver, u16 *, 0xAA) &= 0xFFFD;

            collisionResult = 1;
            instanceData = scratch->hitInstance;

            if (((*(u8 *)instanceData) & 0x80) != 0) {
                instanceData = M2C_FIELD(instanceData, void **, 0x1C);
                if (instanceData != NULL) {
                    levModelMeta = M2C_FIELD(instanceData, LevModelMeta **, 0x2C);
                    if ((levModelMeta != NULL) && ((M2C_FIELD(levModelMeta, u32 *, 0x28) & 0xF) != 0)) {
                        hitModelId = M2C_FIELD(instanceData, s16 *, 0x3C);
                        levModelMeta = COLL_LevModelMeta(hitModelId);
                        if ((levModelMeta != NULL) && (levModelMeta->collisionFunc != NULL)) {
                            collisionResult = levModelMeta->collisionFunc(instanceData, colliderLocal, scratch);
                        }
                    }
                }
            } else if (((*(u8 *)instanceData) & 0x10) != 0) {
                instanceData = M2C_FIELD(instanceData, void **, 0x1C);
                if (instanceData != NULL) {
                    hitModelId = M2C_FIELD(M2C_FIELD(instanceData, void **, 0x18), s16 *, 0x10);
                    levModelMeta = COLL_LevModelMeta(hitModelId);
                    if ((levModelMeta != NULL) && (levModelMeta->collisionFunc != NULL)) {
                        collisionResult = levModelMeta->collisionFunc(instanceData, colliderLocal, scratch);
                    }
                }
            }

            if ((collisionResult == 2) || (M2C_FIELD(scratch->hitInstance, u8 *, 0x1) == 4)) {
                scratch->seenInstances[scratch->seenInstanceCount] = scratch->hitInstance;
                scratch->seenInstanceCount += 1;
            } else {
                COLL_Unknown_80020334(scratch->hitInstance, 0, scratch);
                scratch->terrainFlagMask += 0x200;

                terrainType = VehAfterColl_GetSurface(M2C_FIELD(scratch->hitInstance, u8 *, 0x1));
                if ((M2C_FIELD(scratch->hitInstance, u8 *, 0x1) == 4) ||
                    ((collisionResult = COLL_MOVED_ScrubImpact(driver, colliderLocal, scratch, terrainType, &driver->velocity)) == 0)) {
                    scratch->seenInstances[scratch->seenInstanceCount] = scratch->hitInstance;
                    scratch->seenInstanceCount += 1;
                }

                if (collisionResult == 2) {
                    return;
                }
            }
        } else {
            if (scratch->foundQuadblock == 0) {
                break;
            }

            quadBlock = scratch->quadblockHit;
            if ((quadBlock->quadFlags & 0x200) != 0) {
                M2C_FIELD(driver, u16 *, 0xAA) |= 1;
            }

            COLL_Unknown_80020334(quadBlock, scratch->quadblockHitType, scratch);

            if ((quadBlock->quadFlags & 0x1000) == 0) {
                terrainType = 0;
                if ((quadBlock->quadFlags & 1) != 0) {
                    terrainType = 6;
                }
            } else {
                if ((quadBlock != driver->underDriver) && ((quadBlock->quadFlags & 8) != 0)) {
                    driver->underDriver = NULL;
                }

                driver->currBlockTouching = quadBlock;
                driver->normalVecUp.x = scratch->normalVec.x;
                driver->normalVecUp.y = scratch->normalVec.y;
                driver->normalVecUp.z = scratch->normalVec.z;
                driver->axisAngle1NormalVec.x = scratch->normalVec.x;
                driver->axisAngle1NormalVec.y = scratch->normalVec.y;
                driver->axisAngle1NormalVec.z = scratch->normalVec.z;
                M2C_FIELD(driver, u16 *, 0xAA) |= 8;
                terrainType = 5;
            }

            terrainType = VehAfterColl_GetSurface(terrainType);
            M2C_FIELD(driver, u16 *, 0xAA) |= 2;

            driver->spsHitPos[0] = scratch->hitPos.x;
            driver->spsHitPos[1] = scratch->hitPos.y;
            driver->spsHitPos[2] = scratch->hitPos.z;
            driver->spsNormalVec[0] = scratch->normalVec.x;
            driver->spsNormalVec[1] = scratch->normalVec.y;
            driver->spsNormalVec[2] = scratch->normalVec.z;

            collisionResult = COLL_MOVED_ScrubImpact(driver, colliderLocal, scratch, terrainType, &driver->velocity);
            if (collisionResult == 2) {
                return;
            }

            if (scratch->collisionLerp > 0) {
                motionScale -= (motionScale * scratch->collisionLerp) >> 12;
                collisionFlags = scratch->collisionFlags;
                if (motionScale < 100) {
                    break;
                }
            }

            scratch->collisionFlags |= 8;
        }

        iterationCount -= 1;
        collisionFlags = scratch->collisionFlags;
    }

    scratch->collisionFlags = collisionFlags;
    driver->stepFlagSet = scratch->stepFlags;
}