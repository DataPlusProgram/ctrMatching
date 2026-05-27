#include "../../common.h"


typedef char undefined;
typedef short undefined2;
typedef int undefined4;
typedef void code(int);
typedef void (*VehicleFuncPtr)(Thread *thread, Driver *driver);

typedef struct MainFrameThreadBucket
{
    Thread *thread;
    s32 unk4;
    s32 unk8;
    u32 flags;
    s32 unk10;
}
MainFrameThreadBucket;

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

M2C_UNK Audio_Update1();
M2C_UNK BOTS_UpdateGlobals();
M2C_UNK CTR_CycleTex_AllModels();
M2C_UNK DISPLAY_Blur_Main();
M2C_UNK ElimBG_Deactivate();
s32 GAMEPAD_GetNumConnected();
M2C_UNK GhostTape_WriteMoves();
s32 LOAD_IsOpen_RacingOrBattle();
s32 MainFrame_HaveAllPads();
M2C_UNK MainFrame_TogglePauseAudio();
M2C_UNK MainFreeze_IfPressStart();
M2C_UNK MainFreeze_SafeAdvDestroy();
M2C_UNK OtherFX_Play();
M2C_UNK OtherFX_Play_LowLevel();
M2C_UNK PROC_CheckAllForDead();
M2C_UNK Particle_UpdateAllParticles();
M2C_UNK RECTMENU_ClearInput();
M2C_UNK RECTMENU_Hide();
M2C_UNK RECTMENU_Show();
s32 RaceFlag_IsFullyOnScreen();
M2C_UNK SelectProfile_ToggleMode();
s16 SubmitName_DrawMenu();
M2C_UNK ThTick_RunBucket();
s32 Timer_GetTime_Elapsed();
M2C_UNK UI_VsQuipDrawAll();
M2C_UNK UI_VsWaitForPressX();
M2C_UNK VehPickupItem_ShootOnCirclePress();
M2C_UNK FUN_800b25b8();
M2C_UNK FUN_800b39dc();

extern s32 AnyPlayerTap;
void *D_8008D884;
extern s16 DAT_8008d874;
s16 boolDraw3D_AdvMask;
extern s16 boolSaveCupProgress;
extern void *DAT_800b518c;
extern void *menuRacingWheelConfig;
extern void *menuWarning2;
extern void *ptrActiveMenu;
GameTracker *s_OTMem;

void MainFrame_GameLogic(GameTracker *gGT, GamepadSystem *gamepads)
{
    volatile s16 wasOutsideGameplay;
    s16 menuResult;
    s32 elapsedTime;
    s32 numConnected;
    s32 i;
    s32 j;
    s32 spreadValue;
    u32 gameMode1;
    u32 blurAmount;
    u8 *pushBuffer;
    Thread *thread;
    Driver *driver;
    Driver *leadDriver;
    Driver *chaseDriver;
    VehicleFuncPtr vehicleFunc;
    MainFrameThreadBucket *threadBuckets;
    GamepadSystem *savedGamepads;

    wasOutsideGameplay = true;
    savedGamepads = gamepads;

    if ((gGT->gameMode1 & 0xf) == 0)
    {
        wasOutsideGameplay = false;
        pushBuffer = (u8 *)s_OTMem->pushBuffer;

        for (thread = ((MainFrameThreadBucket *)s_OTMem->threadBuckets)[0].thread; thread != NULL; thread = thread->siblingThread)
        {
            driver = thread->object;

            if (driver->clockSend != 0)
            {
                driver->clockSend--;
            }

            if ((u8)driver->clockFlash != 0)
            {
                blurAmount = (u8)driver->clockFlash;
                DISPLAY_Blur_Main(pushBuffer, -blurAmount);
                driver->clockFlash--;
            }
            else
            {
                if (driver->clockReceive != 0)
                {
                    if ((driver->actionsFlagSet & 0x2000000) != 0)
                    {
                        driver->clockReceive = 0;
                    }

                    blurAmount = (s16)driver->clockReceive;
                    DISPLAY_Blur_Main(pushBuffer, blurAmount);
                }
                else
                {
                    blurAmount = driver->clockSend;

                    if (blurAmount != 0)
                    {
                        DISPLAY_Blur_Main(pushBuffer, blurAmount);
                    }
                    else
                    {
                        if ((M2C_FIELD(s_OTMem, u16 *, 0x2570) & 1) != 0)
                        {
                            DISPLAY_Blur_Main(pushBuffer, 10000);
                        }
                    }
                }
            }

            pushBuffer += 0x110;
        }

        gGT->timer++;
        gGT->framesInThisLEV++;
        M2C_FIELD(s_OTMem, s32 *, 0x1CD4) = 0;

        elapsedTime = Timer_GetTime_Elapsed(gGT->clockFrameStart, &gGT->clockFrameStart);
        gGT->elapsedTimeMS = (elapsedTime << 5) / 100;

        if (gGT->elapsedTimeMS < 0)
        {
            gGT->elapsedTimeMS = 0x20;
        }

        if (gGT->elapsedTimeMS > 0x40)
        {
            gGT->elapsedTimeMS = 0x40;
        }

        if ((s_OTMem->gameMode1PrevFrame & 0xf) != 0)
        {
            gGT->elapsedTimeMS = 0x20;
        }

        gGT->msInThisLEV += gGT->elapsedTimeMS;

        if (gGT->trafficLightsTimer > 0)
        {
            gGT->elapsedEventTime = 0;
        }
        else if ((s_OTMem->gameMode1 & 0x10) == 0)
        {
            if (gGT->frozenTimeRemaining > 0)
            {
                gGT->frozenTimeRemaining -= gGT->elapsedTimeMS;

                if (gGT->frozenTimeRemaining < 0)
                {
                    gGT->frozenTimeRemaining = 0;
                }
                else if ((s_OTMem->timer % 6U) == 0)
                {
                    if ((s_OTMem->timer % 12U) == 0)
                    {
                        OtherFX_Play_LowLevel(0x40, 0, 0x8c9080);
                    }
                    else
                    {
                        OtherFX_Play_LowLevel(0x40, 0, 0x8c8880);
                    }
                }
            }
            else if ((s_OTMem->gameMode1 & 0x200000) == 0)
            {
                gGT->elapsedEventTime += gGT->elapsedTimeMS;
            }
        }

        CTR_CycleTex_AllModels(-1, D_8008D884, gGT->timer);
        CTR_CycleTex_AllModels(
            M2C_FIELD(gGT->level1, undefined4 *, 0x14),
            M2C_FIELD(gGT->level1, undefined4 *, 0x18),
            gGT->timer);

        leadDriver = NULL;
        chaseDriver = NULL;

        for (thread = ((MainFrameThreadBucket *)s_OTMem->threadBuckets)[0].thread; thread != NULL; thread = thread->siblingThread)
        {
            driver = thread->object;

            if (driver->driverId == 0)
            {
                leadDriver = driver;
            }
            else
            {
                if (driver->driverId == 1)
                {
                    chaseDriver = driver;
                }

                if ((u8)driver->numTimesAttacking < (u8)leadDriver->numTimesAttacking)
                {
                    chaseDriver = leadDriver;
                    leadDriver = driver;
                }
            }
        }

        if (leadDriver != NULL)
        {
            if (chaseDriver != NULL)
            {
                spreadValue = (u8)chaseDriver->numTimesAttacking - (u8)leadDriver->numTimesAttacking;

                if (leadDriver->quip2 < spreadValue)
                {
                    leadDriver->quip2 = spreadValue;
                }
            }
        }

        threadBuckets = (MainFrameThreadBucket *)s_OTMem->threadBuckets;

        for (i = 0; i < 0x11; i++)
        {
            if ((((s_OTMem->gameMode1 & 0x10) == 0) || ((threadBuckets[i].flags & 1) != 0)) &&
                (threadBuckets[i].thread != NULL))
            {
                if (i == 0)
                {
                    for (thread = threadBuckets[0].thread; thread != NULL; thread = thread->siblingThread)
                    {
                        VehPickupItem_ShootOnCirclePress(thread->object);
                    }

                    for (j = 0; j < 0xd; j++)
                    {
                        for (thread = threadBuckets[0].thread; thread != NULL; thread = thread->siblingThread)
                        {
                            if (thread->funcThTick == NULL)
                            {
                                driver = thread->object;
                                vehicleFunc = (VehicleFuncPtr)driver->funcPtrs[j];

                                if (vehicleFunc != NULL)
                                {
                                    vehicleFunc(thread, driver);
                                }
                            }
                        }
                    }
                }

                ThTick_RunBucket(threadBuckets[i].thread);
            }
        }

        BOTS_UpdateGlobals(s_OTMem);
        GhostTape_WriteMoves(0);
        M2C_FIELD(s_OTMem, u32 *, 0x1CD4) = ((u32)M2C_FIELD(s_OTMem, s32 *, 0x1CD4) * 10000U) / 0x147eU;
        Particle_UpdateAllParticles();
    }
    else
    {
        if (M2C_FIELD(gGT, Thread **, 0x1C44) != NULL)
        {
            ThTick_RunBucket(M2C_FIELD(gGT, Thread **, 0x1C44));
        }
    }

    if (LOAD_IsOpen_RacingOrBattle() != 0)
    {
        if ((s_OTMem->gameMode1 & 0xf) == 0)
        {
            FUN_800b39dc();
        }

        if (M2C_FIELD(s_OTMem, s32 *, 0x1BB8) != 0)
        {
            FUN_800b25b8();
        }
    }

    PROC_CheckAllForDead();

    if ((s_OTMem->gameMode1 & 0xf) == 0)
    {
        Audio_Update1();
    }

    gGT->gameMode1PrevFrame = gGT->gameMode1;
    numConnected = GAMEPAD_GetNumConnected(M2C_FIELD(s_OTMem, GamepadSystem **, 4));
    gameMode1 = s_OTMem->gameMode1;

    if ((gameMode1 & 0x200000) != 0)
    {
        if (s_OTMem->timerEndOfRaceVS == 0)
        {
            if ((s_OTMem->gameModeEnd & 0x1000000) == 0)
            {
                if ((s_OTMem->gameModeEnd & 0x8000000) == 0)
                {
                    if (s_OTMem->unkTimerCooldownSimilarTo1D36 == 0)
                    {
                        return;
                    }
                }
                else if (s_OTMem->unkTimerCooldownSimilarTo1D36 == 0)
                {
                    if ((s_OTMem->gameModeEnd & 2) == 0)
                    {
                        return;
                    }

                    menuResult = SubmitName_DrawMenu(0x140);

                    if (menuResult == 0)
                    {
                        return;
                    }

                    if (menuResult == 1)
                    {
                        boolSaveCupProgress = 0;
                        SelectProfile_ToggleMode(0x41);
                        RECTMENU_Show(&menuWarning2);
                        s_OTMem->gameModeEnd |= 0x1000000;
                        return;
                    }

                    s_OTMem->newHighScoreIndex = -1;
                    s_OTMem->gameModeEnd &= 0xf3ffffff;
                    return;
                }

                s_OTMem->unkTimerCooldownSimilarTo1D36--;
            }
        }
        else if ((gameMode1 & 0x400000) == 0)
        {
            if (s_OTMem->timerEndOfRaceVS < 0x96)
            {
                UI_VsQuipDrawAll();
                UI_VsWaitForPressX();
            }

            if (s_OTMem->timerEndOfRaceVS > 0x1e)
            {
                s_OTMem->timerEndOfRaceVS--;
            }
        }
        else
        {
            s_OTMem->timerEndOfRaceVS = 0;
        }

        return;
    }

    if (wasOutsideGameplay || ((gGT->gameMode1 & 0xf) != 0))
    {
        if (s_OTMem->cooldownfromPauseUntilUnpause == 0)
        {
            if ((ptrActiveMenu != &menuRacingWheelConfig) &&
                (ptrActiveMenu != &DAT_800b518c) &&
                ((AnyPlayerTap & 0x1000) != 0))
            {
                RECTMENU_ClearInput();
                s_OTMem->gameMode1 &= 0xfffffffe;
                MainFrame_TogglePauseAudio(0);
                OtherFX_Play(1, 1);
                MainFreeze_SafeAdvDestroy();
                ElimBG_Deactivate(s_OTMem);
                RECTMENU_Hide(ptrActiveMenu);
                s_OTMem->cooldownFromUnpauseUntilPause = 5;
            }
        }
        else
        {
            s_OTMem->cooldownfromPauseUntilUnpause--;
        }

        return;
    }

    if (s_OTMem->cooldownFromUnpauseUntilPause == 0)
    {
        if (((gameMode1 & 0x20202000) == 0) &&
            (ptrActiveMenu == NULL) &&
            (boolDraw3D_AdvMask == 0) &&
            (RaceFlag_IsFullyOnScreen() == 0) &&
            (gGT->numPlyrCurrGame != 0))
        {
            for (i = 0; i < (u8)gGT->numPlyrCurrGame; i++)
            {
                if ((((numConnected != 0) &&
                    (MainFrame_HaveAllPads(s_OTMem->numPlyrNextGame) == 0) &&
                    ((gGT->gameMode1 & 0xf) == 0)) ||
                    ((savedGamepads->gamepad[i].buttonsTapped & 0x1000) != 0)) &&
                    (M2C_FIELD(s_OTMem, u8 *, 0x2541) != 0xff))
                {
                    s_OTMem->gameModeEnd = (s_OTMem->gameMode1 & 0x3e0020) | 1;
                    MainFreeze_IfPressStart();
                    s_OTMem->cooldownfromPauseUntilUnpause = 5;
                }
            }
        }
    }
    else
    {
        s_OTMem->cooldownFromUnpauseUntilPause--;
    }
}