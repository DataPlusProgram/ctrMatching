#include "../../common.h"


typedef struct BigFile {
    s32 unk0;
} BigFile;

typedef struct MetaDataLEV {
    s32 unk0;
    char *levName;
    u8 pad8[0x10];
} MetaDataLEV;

void Cutscene_VolumeBackup(void);
void Cutscene_VolumeRestore(void);
void CDSYS_XAPauseRequest(void);
void MainInit_VRAMDisplay(void);
void MainInit_PrimMem(GameTracker *gT);
void MainInit_OTMem(GameTracker *gT);
void MainInit_JitPoolsNew(void);
void LOAD_OvrEndRace(s32 arg0);
void LOAD_OvrLOD(s32 arg0);
void LOAD_OvrThreads(s32 arg0);
void Music_Restart(void);
void Music_Stop(void);
void CseqMusic_StopAll(void);
void Music_LoadBanks(void);
s32 Music_AsyncParseBanks(void);
void LibraryOfModels_Clear(GameTracker *gT);
void LibraryOfModels_Store(GameTracker *gT, s32 modelCountOrMinusOne, void **modelList);
void LOAD_GlobalModelPtrs_MPK(void);
void DecalGlobal_Clear(GameTracker *gT);
void DecalGlobal_Store(GameTracker *gT, void *arg1);
s32 DebugFont_Init(GameTracker *gT);
s32 MainInit_StringToLevID(char *arg0);
s32 LOAD_VramFile(BigFile *bigfilePtr, s32 fileId, s32 *outFile, s32 *outSize, s32 mode);
s32 MEMPACK_PushState(void);
void MEMPACK_PopToState(s32 state);
void MEMPACK_SwapPacks(s32 index);
s32 MEMPACK_AllocMem(s32 size, char *name);
void MEMPACK_NewPack(s32 addr, s32 size);
s32 MEMPACK_GetFreeBytes(void);
void *MEMPACK_AllocHighMem(s32 size, char *name);
s32 LOAD_GetAdvPackIndex(void);
s32 LOAD_GetBigfileIndex(LevelId levelId, s32 lodIndex, s32 bigfileIndexBase);
void LOAD_AppendQueue(BigFile *bigfilePtr, s32 loadType, s32 bigfileIndex, void *destination, void *callback);
void *LOAD_DriverMPK(BigFile *bigfilePtr, s32 lodLevel, void *callback);
void LOAD_Callback_DriverModels(void);
void LOAD_Callback_LEV(void);
void LOAD_Callback_PatchMem(void *arg0);
void LOAD_Callback_Podiums(void);
void Audio_SetState_Safe(s32 arg0);
s32 RaceFlag_IsFullyOffScreen(void);
void RaceFlag_BeginTransition(s32 arg0);
void ElimBG_Deactivate(void *arg0);
void FUN_800B4364(void);
void FUN_800B446C(void);
void FUN_800B4430(void);
void FUN_800B43F4(void);
void FUN_800B8558(void);
void FUN_800B44A8(BigFile *bigfilePtr);
void *DecalGlobal_FindInLEV(void *arg0, char *arg1);
void *DecalGlobal_FindInMPK(void *arg0, char *arg1);
void DrawSync(s32 arg0);

extern s32 boolFirstBoot;
extern s32 bookmarkID;
extern s32 load_inProgress;
extern void *queueReady;
extern s32 levBigLodIndex;
extern s32 mainMenuState;
extern s32 ptrHubAlloc;
extern s32 PatchMem_Size;
extern void *PatchMem_Ptr;
extern void *DAT_8008D08C;
extern s16 DAT_8008D83C;
extern s16 DAT_8008D83E;
extern void *ptrLevelFile;
extern void *AkuAkuHintState;
extern void *podiumModel_firstPlace;
extern void *DAT_80083A14;
extern void *DAT_80083A18;
extern void *DAT_80083A1C;
extern void *DAT_80083A20;
extern void *DAT_80083A24;
extern void *DAT_80083A28;
extern void *podiumModel_dingoFire;
extern MetaDataLEV metaDataLEV[];
extern char s_ndi[4];
extern char s_ending_8008D0C4[7];
extern char s_intro_8008D0CC[6];
extern char s_screen_8008D0D4[7];
extern char s_garage_8008D0DC[7];
extern char DAT_8008D0E4[4];
extern char s_credit_8008D0E8[7];

s32 LOAD_TenStages(GameTracker *gT, s32 loadingStage, BigFile *bigfilePtr)
{
    u8 savedNextGame;
    u8 *gtBytes;
    s16 packIndex;
    s32 i;
    s32 hubPackSize1;
    s32 hubPackSize2;
    s32 levelId;
    void *levelFilePtr;
    s32 menuState;
    s32 outSize[2];
    void **modelPtr;
    u32 gameMode1;
    void *tempPtr;

    gtBytes = (u8 *)gT;
    levelFilePtr = DAT_8008D08C;

    if (M2C_FIELD(&levBigLodIndex, s32 *, 4) != 0)
    {
        return loadingStage;
    }

    if ((u32)loadingStage >= 10U)
    {
        return loadingStage;
    }

    switch (loadingStage)
    {
        case 0:
            levelId = gT->levelID;

            if ((u32)(levelId - ADVENTURE_GARAGE) > 1U)
            {
                Cutscene_VolumeBackup();
            }

            CDSYS_XAPauseRequest();

            if (boolFirstBoot == 0)
            {
                MEMPACK_SwapPacks(0);
                DAT_8008D83E = (s16)MainInit_StringToLevID((char *)gtBytes + 0x1A14);
                MEMPACK_PopToState(bookmarkID);
            }
            else
            {
                boolFirstBoot = 0;
                LOAD_VramFile(bigfilePtr, 0x1FE, NULL, outSize, -1);
                MainInit_VRAMDisplay();
                M2C_FIELD(gT, u8 *, 0x30) = 0;
                M2C_FIELD(gT, u8 *, 0xD4) = 0;
            }

            gT->hudFlags &= 0xFE;
            M2C_FIELD(gT, u32 *, 0x256C) &= 0x1000;
            gT->hudFlags &= 0xF7;
            gT->level1 = NULL;
            gT->level2 = NULL;
            savedNextGame = (u8)gT->numPlyrNextGame;
            gT->visMem1 = NULL;
            gT->visMem2 = NULL;
            gT->numPlyrCurrGame = savedNextGame;

            strcpy((char *)gtBytes + 0x1A14, metaDataLEV[gT->levelID].levName);
            bookmarkID = MEMPACK_PushState();
            DrawSync(0);

            M2C_FIELD(gT, u8 *, 0x2579) = 0;
            gameMode1 = gT->gameMode1 & 0xDFCFDFFF;
            gT->gameMode1 = gameMode1;
            gT->gameMode2 &= 0xFFFFFE5F;
            gT->visMem1 = NULL;
            gT->visMem2 = NULL;

            if ((strncmp((char *)gtBytes + 0x1A14, s_ndi, 3) == 0) ||
                (strncmp((char *)gtBytes + 0x1A14, s_ending_8008D0C4, 6) == 0))
            {
                gT->gameMode1 |= 0x20000000;
                gT->hudFlags &= 0xFE;
            }
            else if (strncmp((char *)gtBytes + 0x1A14, s_intro_8008D0CC, 5) == 0)
            {
                gT->hudFlags &= 0xFE;
                gT->gameMode1 |= 0x20000000;
                gT->gameMode2 |= 0x20;
            }
            else if ((strncmp((char *)gtBytes + 0x1A14, s_screen_8008D0D4, 6) == 0) ||
                     (strncmp((char *)gtBytes + 0x1A14, s_garage_8008D0DC, 6) == 0))
            {
                gT->hudFlags &= 0xFE;
                gT->gameMode1 |= 0x2000;
                gT->numPlyrNextGame = gT->numPlyrCurrGame;
                gT->numPlyrCurrGame = 4;

                if (strncmp((char *)gtBytes + 0x1A14, s_garage_8008D0DC, 6) == 0)
                {
                    gT->numPlyrCurrGame = 1;
                    mainMenuState = 4;
                }
            }
            else if (strncmp((char *)gtBytes + 0x1A14, DAT_8008D0E4, 3) == 0)
            {
                gT->numPlyrNextGame = 1;
                gT->numPlyrCurrGame = 1;
                gT->gameMode1 |= 0x100000;
                gT->gameMode2 |= 0x20;
                gT->hudFlags &= 0xFE;
            }
            else if (strncmp((char *)gtBytes + 0x1A14, s_credit_8008D0E8, 6) == 0)
            {
                gT->numPlyrNextGame = 1;
                gT->numPlyrCurrGame = 1;
                gT->gameMode1 |= 0x20000000;
                gT->gameMode2 |= 0xA0;
                gT->hudFlags &= 0xFE;
            }
            else
            {
                gT->hudFlags &= 0xFE;
            }

            gT->hudFlags |= 2;
            M2C_FIELD(gT, u8 *, 0x253F) = 1;

            DAT_8008D83C = 1;
            if (((gT->gameMode1 & 0x2000) == 0) && ((gT->gameMode1 & 0x4020000) == 0))
            {
                DAT_8008D83C = (u8)gT->numPlyrCurrGame;
            }
            else
            {
                DAT_8008D83C = 8;
            }

            MainInit_PrimMem(gT);
            MainInit_OTMem(gT);

            if (((gT->gameMode1 & 0x20100000) != 0) || ((gT->gameMode2 & 0x80) != 0))
            {
                MainInit_JitPoolsNew();
                return loadingStage + 1;
            }
            break;

        case 1:
            if (XA_State == 4)
            {
                return loadingStage;
            }

            gameMode1 = gT->gameMode1;
            if ((gameMode1 & 0x8000000) != 0)
            {
                LOAD_OvrEndRace(0);
                return loadingStage + 1;
            }

            if ((gameMode1 & 0x20000) != 0)
            {
                LOAD_OvrEndRace(3);
                return loadingStage + 1;
            }

            if ((gameMode1 & 0x400000) != 0)
            {
                LOAD_OvrEndRace(1);
                return loadingStage + 1;
            }

            if ((gameMode1 & 0x4000000) != 0)
            {
                LOAD_OvrEndRace(2);
                return loadingStage + 1;
            }

            if ((gameMode1 & 0x80000) != 0)
            {
                LOAD_OvrEndRace(1);
                return loadingStage + 1;
            }

            if ((gT->gameMode2 & 0x10) == 0)
            {
                LOAD_OvrEndRace(4);
                return loadingStage + 1;
            }
            break;

        case 2:
            LOAD_OvrLOD((u8)gT->numPlyrCurrGame);
            break;

        case 3:
            if (((gT->gameMode1 & 0x2000) != 0) && (gT->levelID != ADVENTURE_GARAGE))
            {
                LOAD_OvrThreads(0);
                return loadingStage + 1;
            }

            if ((gT->gameMode1 & 0x100000) != 0)
            {
                menuState = 3;
                if (M2C_FIELD(gT, s16 *, 0x2572) == 0)
                {
                    menuState = 2;
                }
                LOAD_OvrThreads(menuState);
                return loadingStage + 1;
            }

            if ((M2C_FIELD(gT, s16 *, 0x2572) != 0) ||
                ((gT->gameMode1 & 0x20000000) != 0) ||
                ((gT->gameMode2 & 0x80) != 0) ||
                (gT->levelID == ADVENTURE_GARAGE))
            {
                LOAD_OvrThreads(3);
                return loadingStage + 1;
            }

            menuState = 1;
            if (M2C_FIELD(gT, u8 *, 0x2541) == 1)
            {
                break;
            }

            LOAD_OvrThreads(menuState);
            return loadingStage + 1;

        case 4:
            if ((u32)(gT->levelID - ADVENTURE_GARAGE) > 1U)
            {
                Music_Restart();
            }

            if ((gT->gameMode1 & 0x2000) != 0)
            {
                switch (mainMenuState)
                {
                    case 0: FUN_800B4364(); break;
                    case 1: FUN_800B446C(); break;
                    case 2: FUN_800B4430(); break;
                    case 3: FUN_800B43F4(); break;
                    case 4: FUN_800B8558(); break;
                    case 5: FUN_800B44A8(bigfilePtr); break;
                }
            }

            podiumModel_firstPlace = 0;
            DAT_80083A14 = 0;
            DAT_80083A18 = 0;
            ptrLevelFile = NULL;
            M2C_FIELD(&levBigLodIndex, s32 *, 4) = 1;
            LOAD_DriverMPK(bigfilePtr, (s16)DAT_8008D83C, LOAD_Callback_DriverModels);
            break;

        case 5:
            LibraryOfModels_Clear(gT);

            if (ptrLevelFile != NULL)
            {
                AkuAkuHintState = (s8 *)ptrLevelFile + 4;
            }
            else
            {
                AkuAkuHintState = NULL;
            }

            LOAD_GlobalModelPtrs_MPK();
            DecalGlobal_Clear(gT);

            if ((ptrLevelFile == NULL) || (M2C_FIELD(ptrLevelFile, s32 *, 0) == 0))
            {
                gT->mpkIcons = NULL;
            }
            else
            {
                DecalGlobal_Store(gT, M2C_FIELD(ptrLevelFile, void **, 0));
                gT->mpkIcons = M2C_FIELD(ptrLevelFile, void **, 0);
            }

            if ((u32)(gT->levelID - ADVENTURE_GARAGE) > 1U)
            {
                Music_Stop();
                CseqMusic_StopAll();
                Music_LoadBanks();
                return loadingStage + 1;
            }
            break;

        case 6:
            if ((u32)(gT->levelID - ADVENTURE_GARAGE) > 1U)
            {
                if (Music_AsyncParseBanks() == 0)
                {
                    return loadingStage;
                }

                Cutscene_VolumeRestore();
            }

            for (i = 0, modelPtr = &podiumModel_firstPlace; i < 3; i++, modelPtr++)
            {
                if (*modelPtr != NULL)
                {
                    *modelPtr = (s8 *)*modelPtr + 4;
                }
            }

            if ((gT->gameMode2 & 0x20) != 0)
            {
                hubPackSize1 = 0x6B000;
                if ((gT->gameMode1 & 0x100000) != 0)
                {
                    hubPackSize1 = 0x68800;
                }

                hubPackSize2 = 0x40000;
                if ((gT->gameMode1 & 0x100000) != 0)
                {
                    hubPackSize2 = 0x68800;
                }

                ptrHubAlloc = MEMPACK_AllocMem(hubPackSize1 + hubPackSize2, "HUB ALLOC");
                MEMPACK_SwapPacks(1);
                MEMPACK_NewPack(ptrHubAlloc, hubPackSize1);
                MEMPACK_SwapPacks(2);
                MEMPACK_NewPack(ptrHubAlloc + hubPackSize1, hubPackSize2);

                packIndex = 1;
                if ((gT->gameMode1 & 0x100000) != 0)
                {
                    packIndex = (s16)(3 - LOAD_GetAdvPackIndex());
                }

                M2C_FIELD(gT, s16 *, 0x254A) = packIndex;
                M2C_FIELD(gT, s16 *, 0x254C + (packIndex * 2)) = (s16)gT->levelID;
                M2C_FIELD(gT, s16 *, 0x254C + ((3 - packIndex) * 2)) = -1;

                MEMPACK_SwapPacks(0);
                PatchMem_Size = MEMPACK_GetFreeBytes();
                PatchMem_Ptr = MEMPACK_AllocHighMem(PatchMem_Size, "Patch Table Memory");
                MEMPACK_SwapPacks(packIndex);
            }

            M2C_FIELD(&levBigLodIndex, s32 *, 4) = 1;
            levelId = LOAD_GetBigfileIndex((LevelId)gT->levelID, (s16)DAT_8008D83C, 0);
            LOAD_AppendQueue(bigfilePtr, 3, levelId, NULL, NULL);

            levelId = gT->levelID;
            if (((u32)(levelId - 0x19) < 0xE) || ((u32)(levelId - 0x2C) < 0x14))
            {
                hubPackSize1 = LOAD_GetBigfileIndex((LevelId)levelId, (s16)DAT_8008D83C, 1);
                LOAD_AppendQueue(bigfilePtr, 2, hubPackSize1, NULL, LOAD_Callback_LEV);
                hubPackSize2 = LOAD_GetBigfileIndex((LevelId)gT->levelID, (s16)DAT_8008D83C, 2);
                LOAD_AppendQueue(bigfilePtr, 1, hubPackSize2, PatchMem_Ptr, LOAD_Callback_PatchMem);
            }
            else
            {
                hubPackSize1 = LOAD_GetBigfileIndex((LevelId)levelId, (s16)DAT_8008D83C, 1);
                LOAD_AppendQueue(bigfilePtr, 2, hubPackSize1, NULL, LOAD_Callback_LEV);
            }
            break;

        case 7:
            gT->level1 = (Level *)queueReady;
            gT->visMem1 = M2C_FIELD(queueReady, void **, 0x190);

            if (gT->level1 != NULL)
            {
                DecalGlobal_Store(gT, M2C_FIELD(gT->level1, void **, 0x3C));
            }

            DebugFont_Init(gT);

            if (gT->level1 != NULL)
            {
                LibraryOfModels_Store(gT, M2C_FIELD(gT->level1, s32 *, 0x14), M2C_FIELD(gT->level1, void ***, 0x18));
                gT->ptrCircle = DecalGlobal_FindInLEV(gT->level1, "circle");
                gT->ptrClod = DecalGlobal_FindInLEV(gT->level1, "clod");
                gT->ptrDustpuff = DecalGlobal_FindInLEV(gT->level1, "dustpuff");
                gT->ptrSmoking = DecalGlobal_FindInLEV(gT->level1, "smokering");
                gT->ptrSparkle = DecalGlobal_FindInLEV(gT->level1, "sparkle");
            }

            if (gT->mpkIcons != NULL)
            {
                tempPtr = M2C_FIELD(gT->mpkIcons, void **, 4);
                gT->trafficLightIconRedOff = DecalGlobal_FindInMPK(tempPtr, "lightredoff");
                gT->trafficLightIconRedOn = DecalGlobal_FindInMPK(tempPtr, "lightredon");
                gT->trafficLightIconGreenOff = DecalGlobal_FindInMPK(tempPtr, "lightgreenoff");
                gT->trafficLightIconGreenOn = DecalGlobal_FindInMPK(tempPtr, "lightgreenon");
            }

            gT->gameMode1PrevFrame = 1;

            if (((gT->gameMode1 & 0x20100000) == 0) && ((gT->gameMode2 & 0x80) == 0))
            {
                MainInit_JitPoolsNew();
                return loadingStage + 1;
            }

            if (M2C_FIELD(gT, s16 *, 0x2572) != 0)
            {
                DAT_80083A1C = 0;
                DAT_80083A20 = 0;
                DAT_80083A24 = 0;
                DAT_80083A28 = 0;
                DAT_80083A14 = 0;
                DAT_80083A18 = 0;
                podiumModel_firstPlace = 0;
                podiumModel_dingoFire = 0;

                i = LOAD_GetAdvPackIndex();
                MEMPACK_SwapPacks(3 - M2C_FIELD(gT, s16 *, 0x254A));
                M2C_FIELD(&levBigLodIndex, s32 *, 4) = 1;
                LOAD_AppendQueue(bigfilePtr, 3, i + 0x16B, NULL, NULL);

                if ((M2C_FIELD(gT, u8 *, 0x2575) != 0) && (M2C_FIELD(gT, u8 *, 0x2575) != 0x8D))
                {
                    LOAD_AppendQueue(bigfilePtr, 2, i + ((M2C_FIELD(gT, u8 *, 0x2575) - 0x7E) * 2) + 0x16D, &DAT_80083A1C, (void *)-2);
                }

                if (M2C_FIELD(gT, u8 *, 0x2576) != 0)
                {
                    LOAD_AppendQueue(bigfilePtr, 2, i + ((M2C_FIELD(gT, u8 *, 0x2576) - 0x7E) * 2) + 0x18D, &DAT_80083A20, (void *)-2);
                }

                if (M2C_FIELD(gT, u8 *, 0x2577) != 0)
                {
                    LOAD_AppendQueue(bigfilePtr, 2, i + ((M2C_FIELD(gT, u8 *, 0x2577) - 0x7E) * 2) + 0x18D, &DAT_80083A24, (void *)-2);
                }

                LOAD_AppendQueue(bigfilePtr, 2, i + ((M2C_FIELD(gT, u8 *, 0x2578) - 0x8F) * 2) + 0x1AD, &DAT_80083A28, (void *)-2);

                if (M2C_FIELD(gT, s8 *, 0x2575) == -0x7D)
                {
                    LOAD_AppendQueue(bigfilePtr, 2, i + 0x1BD, &podiumModel_dingoFire, (void *)-2);
                }

                LOAD_AppendQueue(bigfilePtr, 2, i + 0x1BF, NULL, LOAD_Callback_Podiums);
                gT->gameMode2 |= 0x100;
            }
            break;

        case 8:
            if (((gT->gameMode1 & 0x100000) != 0) && (M2C_FIELD(gT, s16 *, 0x2572) != 0))
            {
                for (i = 0, modelPtr = &DAT_80083A1C; i < 8; i++, modelPtr++)
                {
                    if (*modelPtr != NULL)
                    {
                        if (i < 7)
                        {
                            *modelPtr = (s8 *)*modelPtr + 4;
                        }

                        if (M2C_FIELD(*modelPtr, s16 *, 0x10) != -1)
                        {
                            M2C_FIELD((s8 *)gT + (M2C_FIELD(*modelPtr, s16 *, 0x10) << 2), void **, 0x2160) = *modelPtr;
                        }
                    }
                }

                MEMPACK_SwapPacks(M2C_FIELD(gT, s16 *, 0x254A));
            }

            levelId = gT->levelID;
            if (levelId == MAIN_MENU_LEVEL)
            {
                Audio_SetState_Safe(7);
                return loadingStage + 1;
            }

            if ((u32)(levelId - 0x19) < 5U)
            {
                menuState = 6;
                if (M2C_FIELD(gT, s16 *, 0x2572) == 0)
                {
                    menuState = 5;
                }

                Audio_SetState_Safe(menuState);
                return loadingStage + 1;
            }

            if (levelId == INTRO_OXIDE)
            {
                Audio_SetState_Safe(3);
                return loadingStage + 1;
            }

            if (levelId == CREDITS_CRASH)
            {
                Audio_SetState_Safe(2);
                return loadingStage + 1;
            }

            if (levelId == NAUGHTY_DOG_CRATE)
            {
                Audio_SetState_Safe(4);
                return loadingStage + 1;
            }

            if ((u32)(levelId - OXIDE_ENDING) < 2U)
            {
                Audio_SetState_Safe(1);
                return loadingStage + 1;
            }
            break;

        case 9:
            if (XA_State != 2)
            {
                if (((gT->gameMode1 & 0x2000) == 0) || (gT->levelID == ADVENTURE_GARAGE))
                {
                    if ((gT->gameMode2 & 0x80) == 0)
                    {
                        M2C_FIELD(gT, u32 *, 0x256C) |= 0xFFFFEFFF;
                    }
                    else
                    {
                        M2C_FIELD(gT, u32 *, 0x256C) = (M2C_FIELD(gT, u32 *, 0x256C) & 0x1000) | 0x20;
                    }
                }
                else
                {
                    M2C_FIELD(gT, u32 *, 0x256C) = (M2C_FIELD(gT, u32 *, 0x256C) & 0x1000) | 0x20;
                    if (RaceFlag_IsFullyOffScreen() == 1)
                    {
                        RaceFlag_BeginTransition(1);
                    }
                }

                gT->hudFlags |= 8;
                gT->framesInThisLEV = 0;
                gT->msInThisLEV = 0;
                ElimBG_Deactivate(gT);
                return -2;
            }
            return loadingStage;

    }

    return loadingStage + 1;
}
