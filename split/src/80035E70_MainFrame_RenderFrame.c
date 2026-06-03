#include "../../common.h"

typedef unsigned char byte;
typedef unsigned char undefined;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

typedef int bool;

typedef struct
{
    s16 unk0;
    s16 unk2;
} M2cUILerp2DLinearArg0;

typedef struct
{
    u8 pad00[0x18];
    s32 unk18;
} MeshInfo;

typedef struct
{
    s32 visLeafList[4];
    s32 visFaceList[4];
    s32 visOVertList[4];
    s32 visSCVertList[4];
    s32 visLeafSrc[4];
    s32 visFaceSrc[4];
    s32 visOVertSrc[4];
    s32 visSCVertSrc[4];
} VisMem;

struct Level
{
    MeshInfo *meshInfo;          // 0x00
    void *skybox;                // 0x04
    s32 unk08;                   // 0x08
    s32 unk0C;                   // 0x0C
    s32 unk10;                   // 0x10
    u8 pad14[0x34 - 0x14];
    s32 unk34;                   // 0x34
    s32 unk38;                   // 0x38
    u8 pad3C[0x44 - 0x3C];
    s32 unk44;                   // 0x44
    u8 skyboxGlow[0xDC - 0x48];  // 0x48
    s32 configFlags;             // 0xDC
    u8 padE0[0x170 - 0xE0];
    s32 unk170;                  // 0x170
    s32 unk174;                  // 0x174
    s32 unk178;                  // 0x178
};

typedef struct
{
    GameTracker *gameTracker;
    GamepadSystem *gamepadSystem;
} OtMemPair;

typedef struct
{
    u8 pad00[0x80];
    void *nextPrim;
} DbPrimCursor;

typedef struct
{
    u32 tag;
    u8 r0;
    u8 g0;
    u8 b0;
    u8 code;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    s16 x3;
    s16 y3;
} PrimPolyF4;

u8 *s_OTMem;
extern u8 *PTR_gamepadSystem_8008d2b0;
extern s32 lngStrings;
extern s16 lngIndex_gamepadUnplugged[];
extern s16 errorMessagePosIndex;
extern s16 errorPosY[];
extern u16 finalLapTextTimer[4];
extern s32 stage;
extern s16 AkuHint_RequestedHint;
extern s16 AkuHint_boolInterruptWarppad;
extern s32 boolDebugDispEnv;
extern s32 boolPlayVideoSTR;
extern s32 vsyncTillFlip;
extern s16 frameCounter;
extern s16 videoSTR_dst_vramX;
extern s16 videoSTR_dst_vramY;
extern s32 videoSTR_src_vramRect;
extern u8 D_8008D2D0[];
extern s32 D_800845A0[];
extern M2C_UNK D_800B4540;
extern void *ptrActiveMenu;
extern u8 blank_debug_DispEnv;
extern s32 menuRowHighlight_Normal;
extern s32 menuRowHighlight_Green;
extern s32 ptrColor[];

static s32 DAT_1f800014;
static s32 DAT_1f800018;
static s32 DAT_1f80001c;
static s32 DAT_1f800020;
static s32 DAT_1f800024;
static s32 DAT_1f800028;
static s32 DAT_1f80002c;

M2C_UNK AddPrim();                       /* extern */
M2C_UNK AnimateQuad();                   /* extern */
M2C_UNK AnimateWater1P();                /* extern */
M2C_UNK AnimateWater2P();                /* extern */
M2C_UNK AnimateWater3P();                /* extern */
M2C_UNK AnimateWater4P();                /* extern */
M2C_UNK BreakDraw();                     /* extern */
M2C_UNK CAM_ClearScreen();               /* extern */
M2C_UNK CAM_SkyboxGlow();                /* extern */
M2C_UNK CTR_ClearRenderLists_1P2P();     /* extern */
M2C_UNK CTR_ClearRenderLists_3P4P();     /* extern */
M2C_UNK CTR_CycleTex_LEV();              /* extern */
M2C_UNK DecalFont_DrawLine();            /* extern */
M2C_UNK DecalFont_DrawLineOT();          /* extern */
M2C_UNK DecalMP_01();                    /* extern */
M2C_UNK DecalMP_02();                    /* extern */
M2C_UNK DecalMP_03();                    /* extern */
M2C_UNK DotLights_AudioAndVideo();       /* extern */
M2C_UNK DrawConfetti();                  /* extern */
M2C_UNK DrawOTag();                      /* extern */
M2C_UNK DrawSky_Full();                  /* extern */
M2C_UNK DrawSync();                      /* extern */
M2C_UNK DrawTires_Reflection();          /* extern */
M2C_UNK DrawTires_Solid();               /* extern */
M2C_UNK DropRain_MakeSound();            /* extern */
M2C_UNK ElimBG_HandleState();            /* extern */
M2C_UNK INSTANCE_LevDelayedLInBs();      /* extern */
s32 LOAD_IsOpen_AdvHub();                /* extern */
s32 LOAD_IsOpen_MainMenu();              /* extern */
s32 LOAD_IsOpen_Podiums();               /* extern */
s32 LOAD_IsOpen_RacingOrBattle();        /* extern */
M2C_UNK LOAD_OvrThreads();               /* extern */
s32 MainFrame_HaveAllPads();             /* extern */
M2C_UNK MainFrame_VisMemFullFrame();     /* extern */
M2C_UNK MoveImage();                     /* extern */
M2C_UNK Particle_RenderList();           /* extern */
M2C_UNK PickupBots_Update();             /* extern */
M2C_UNK PlayLevel_UpdateLapStats();      /* extern */
M2C_UNK PushBuffer_FadeAllWindows();     /* extern */
M2C_UNK PushBuffer_SetDrawEnv_Normal();  /* extern */
M2C_UNK PushBuffer_UpdateFrustum();      /* extern */
M2C_UNK PutDispEnv();                    /* extern */
M2C_UNK PutDrawEnv();                    /* extern */
M2C_UNK RECTMENU_CollectInput();         /* extern */
M2C_UNK RECTMENU_DrawInnerRect();        /* extern */
M2C_UNK RECTMENU_DrawOuterRect_LowLevel(); /* extern */
M2C_UNK RECTMENU_ProcessState();         /* extern */
M2C_UNK RaceFlag_DrawSelf();             /* extern */
M2C_UNK RedBeaker_RenderRain();          /* extern */
M2C_UNK RefreshCard_Entry();             /* extern */
M2C_UNK RenderBucket_Execute();          /* extern */
s32 RenderBucket_QueueLevInstances();    /* extern */
undefined4 *RenderBucket_QueueNonLevInstances(); /* extern */
s32 RenderLists_Init1P2P();              /* extern */
s32 RenderLists_Init3P4P();              /* extern */
M2C_UNK RenderLists_PreInit();           /* extern */
M2C_UNK RenderStars();                   /* extern */
M2C_UNK RenderWeather();                 /* extern */
s32 Timer_GetTime_Elapsed();             /* extern */
s32 Timer_GetTime_Total();               /* extern */
M2C_UNK Torch_Main();                    /* extern */
M2C_UNK UI_CupStandings_InputAndDraw();  /* extern */
M2C_UNK UI_Lerp2D_Linear();              /* extern */
M2C_UNK UI_RaceStart_IntroText1P();      /* extern */
M2C_UNK UI_RenderFrame_AdvHub();         /* extern */
M2C_UNK UI_RenderFrame_CrystChall();     /* extern */
M2C_UNK UI_RenderFrame_Racing();         /* extern */
M2C_UNK UI_RenderFrame_Wumpa3D_2P3P4P(); /* extern */
M2C_UNK VSync();                         /* extern */
M2C_UNK VehGroundShadow_Main();          /* extern */
M2C_UNK VehGroundSkids_Main();           /* extern */
M2C_UNK VehTurbo_ProcessBucket();        /* extern */
M2C_UNK func_8009F704();                 /* extern */
M2C_UNK func_8009F710();                 /* extern */
M2C_UNK func_8009F718();                 /* extern */
M2C_UNK func_8009FDC8();                 /* extern */
M2C_UNK func_800A01D8();                 /* extern */
M2C_UNK func_800A0CBC();                 /* extern */
M2C_UNK func_800ABBDC();                 /* extern */
M2C_UNK func_800AC178();                 /* extern */
M2C_UNK func_800B0B38();                 /* extern */
M2C_UNK func_800B0DBC();                 /* extern */
M2C_UNK func_800B0E68();                 /* extern */
M2C_UNK func_800B1714();                 /* extern */
M2C_UNK func_800B1BD8();                 /* extern */
M2C_UNK func_800B1C90();                 /* extern */
M2C_UNK func_800B3DD8();                 /* extern */
M2C_UNK func_800B6674();                 /* extern */
M2C_UNK func_800B6D58();                 /* extern */
M2C_UNK func_800B95FC();                 /* extern */
M2C_UNK func_800B9DD8();                 /* extern */

static void ghidraTrap(s32 code)
{
  (void)code;
}

#define trap(code) ghidraTrap(code)
#define FUN_8009f704 func_8009F704
#define FUN_8009f710 func_8009F710
#define FUN_8009f718 func_8009F718
#define FUN_8009fdc8 func_8009FDC8
#define FUN_800a01d8 func_800A01D8
#define FUN_800abbdc func_800ABBDC
#define FUN_800b0b38 func_800B0B38
#define FUN_800b0dbc func_800B0DBC
#define FUN_800b0e68 func_800B0E68
#define FUN_800b1714 func_800B1714
#define FUN_800b1bd8 func_800B1BD8
#define FUN_800b1c90 func_800B1C90
#define FUN_800b3dd8 func_800B3DD8
#define FUN_800b6674 func_800B6674
#define FUN_800b6d58 func_800B6D58
#define FUN_800b95fc func_800B95FC
#define FUN_800b9dd8 func_800B9DD8
#define FUN_800ac178 func_800AC178
#define FUN_800a0cbc func_800A0CBC
#define DAT_800845a0 D_800845A0
#define uRam800b4548 M2C_FIELD(ptrActiveMenu, s32 *, 8)
#define LOD D_8008D2D0

void MainFrame_RenderFrame(uint *param_1)

{
  uint *puVar1;
  byte bVar2;
  bool bVar3;
  undefined *puVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  short sVar11;
  int iVar12;
  uint uVar13;
  undefined *puVar14;
  int iVar15;
  uint *puVar16;
  PrimPolyF4 *pvVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  uint *puVar21;
  int iVar22;
  int iVar23;
  short sVar24;
  GameTracker *gGT;
  Level *level;
  MeshInfo *meshInfo;
  VisMem *visMem;
  PushBuffer *pushBufferView0;
  PushBuffer *pushBufferView;
  DB *backBuffer;
  DB *frontBuffer;
  uint *pushBuffer0;
  uint *pushBufferUi;
  LevRenderList *levRenderList0;
  uint *cameraDc0;
  s32 firstPushBufferOt;
  DbPrimCursor *dbPrimCursor;
  int iVar26;
  undefined2 local_40;
  short local_3e;
  undefined2 local_3c;
  short local_3a;
  short local_38;
  short local_36;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  iVar26 = 0;
  gGT = (GameTracker *)param_1;
  level = (Level *)M2C_FIELD(gGT, Level **, 0x160);
  meshInfo = (MeshInfo *)0x0;
  bVar3 = false;
  iVar7 = LOAD_IsOpen_MainMenu();
  if ((iVar7 != 0) && (ptrActiveMenu == &D_800B4540))
  {
    bVar3 = (uRam800b4548 & 0x10) == 0;
  }
  if (((((*(u32 *)s_OTMem & 0x20000000) == 0) &&
       (sVar6 = MainFrame_HaveAllPads((uint)s_OTMem[0x1ca9]), sVar6 == 0)) &&
      (s_OTMem[0x1d32] == '\0')) && (!bVar3))
      {
    sVar6 = errorPosY[videoSTR_dst_vramY];
    sVar24 = 0xe;
    if (((*(u8 **)(s_OTMem + 4))[0x2d1] == 0x80) ||
        (sVar11 = 0, 2 < s_OTMem[0x1ca9]))
        {
      sVar11 = 2;
    }
    iVar7 = 0;
    if (s_OTMem[0x1ca9] != '\0')
    {
      iVar22 = 0;
      sVar24 = 0xe;
      do
      {
        puVar4 = *(undefined **)(*(u8 **)(s_OTMem + 4) + iVar22 + 0x20);
        if ((puVar4 == (undefined *)0x0) || (*puVar4 != '\0'))
           {
          iVar18 = (int)sVar6;
          sVar24 = sVar24 + 8;
          sVar6 = sVar6 + 8;
          DecalFont_DrawLine(*(undefined4 *)(lngStrings + (lngIndex_gamepadUnplugged[iVar7 + sVar11] * 4)),0x100,iVar18,2,0xffff8000);
        }
        iVar7 = iVar7 + 1;
        iVar22 = iVar22 + 0x50;
      } while (iVar7 < (int)(uint)s_OTMem[0x1ca9]);
    }
    DecalFont_DrawLine(*(undefined4 *)(lngStrings + 0xac),0x100,(int)sVar6,2,0xffff8000);
    local_40 = 0xffec;
    local_3c = 0x228;
    local_3e = errorPosY[videoSTR_dst_vramY] - 3;
    local_3a = sVar24;
    RECTMENU_DrawInnerRect(&local_40,1,*(undefined4 *)(*(int *)(s_OTMem + 0x10) + 0xa0));
  }
  iVar22 = 0;
  iVar18 = 0;
  iVar23 = 0x168;
  iVar7 = iVar18;
  sVar11 = 10;
  do
  {
    if (*(short *)((int)&finalLapTextTimer + iVar22) != 0)
    {
      pushBufferView = (PushBuffer *)(s_OTMem + iVar23);
      iVar12 = (int)((0x5a - (uint)*(ushort *)((int)&finalLapTextTimer + iVar22)) * 0x10000) >> 0x10;
      if (0x50 < iVar12)
      {
        iVar12 = iVar12 + -0x50;
        iVar15 = (int)((uint)pushBufferView->rectW << 0x10) >> 0x11;
        iVar19 = (int)((uint)pushBufferView->rectH << 0x10) >> 0x12;
        iVar20 = -100;
      }
      else if (10 < iVar12)
      {
        iVar12 = iVar12 + -10;
        iVar15 = (int)((uint)pushBufferView->rectW << 0x10) >> 0x11;
        iVar19 = (int)((uint)pushBufferView->rectH << 0x10) >> 0x12;
        iVar20 = iVar15;
      }
      else
      {
        iVar15 = (int)((pushBufferView->rectW + 100) * 0x10000) >> 0x10;
        iVar19 = (int)((uint)pushBufferView->rectH << 0x10) >> 0x12;
        iVar20 = (int)((uint)pushBufferView->rectW << 0x10) >> 0x11;
      }
      UI_Lerp2D_Linear(&local_38,iVar15,iVar19,iVar20,iVar19,iVar12,sVar11);
      DecalFont_DrawLineOT(*(undefined4 *)(lngStrings + 0x8cc),(int)local_38,(int)local_36,1,0xffff8000,*(undefined4 *)(s_OTMem + iVar7 + 0x25c));
      *(short *)((int)&finalLapTextTimer + iVar22) =
           *(short *)((int)&finalLapTextTimer + iVar22) + -1;
    }
    iVar22 = iVar22 + 2;
    iVar7 = iVar7 + 0x110;
    iVar18 = iVar18 + 1;
    iVar23 = iVar23 + 0x110;
  } while (iVar18 < 4);
  ElimBG_HandleState(s_OTMem);
  if (level != (Level *)0x0)
  {
    meshInfo = level->meshInfo;
    iVar26 = (int)meshInfo;
  }
  if ((gGT->renderFlags & 0x21) != 0)
  {
    MainFrame_VisMemFullFrame(param_1,level);
  }
  if ((((gGT->renderFlags & 1) != 0) && (*(int *)(s_OTMem + 0x1a38) != 0)) &&
     (level != (Level *)0x0))
     {
    CTR_CycleTex_LEV(level->unk08,gGT->timer);
  }
  if ((ptrActiveMenu != 0) || ((*(uint *)s_OTMem & 0x200000) != 0))
  {
    RECTMENU_CollectInput();
  }
  if ((ptrActiveMenu != 0) && (stage == -1))
  {
    RECTMENU_ProcessState();
  }
  iVar7 = 0;
  if (gGT->numPlyrCurrGame != '\0')
  {
    iVar22 = 0x168;
    puVar21 = param_1;
    puVar16 = param_1;
    do
    {
      PushBuffer_UpdateFrustum((int)param_1 + iVar22);
      if (*(uint *)((int)puVar21 + 0x14b4) != 0)
      {
        uVar8 = (uint)*(byte *)(*(uint *)((int)puVar21 + 0x14b4) + 0x39);
        uVar13 = (uint)(byte)gGT->numPlyrCurrGame;
        if (uVar13 == 0)
        {
          trap(0x1c00);
        }
        if ((uVar13 == 0xffffffff) && (uVar8 == 0x20000000))
        {
          trap(0x1800);
        }
        *(short *)((int)puVar16 + 0x1a44) = (short)((uVar8 << 2) / uVar13);
        uVar8 = (uint)(byte)gGT->numPlyrCurrGame;
        if (uVar8 == 0)
        {
          trap(0x1c00);
        }
        if ((uVar8 == 0xffffffff) && (*(byte *)(*(uint *)((int)puVar21 + 0x14b4) + 0x3a) == 0x20000000))
        {
          trap(0x1800);
        }
        *(short *)((int)puVar16 + 0x1a46) =
             (short)(((uint)*(byte *)(*(uint *)((int)puVar21 + 0x14b4) + 0x3a) << 2) / uVar8);
      }
      puVar16 = (uint *)((int)puVar16 + 0x30);
      puVar21 = (uint *)((int)puVar21 + 0xdc);
      iVar7 = iVar7 + 1;
      iVar22 = iVar22 + 0x110;
    } while (iVar7 < (int)(uint)(byte)gGT->numPlyrCurrGame);
  }
  DropRain_MakeSound(param_1);
  uVar8 = (int)frameCounter << 7;
  iVar7 = D_800845A0[uVar8 & 0x3ff];
  if ((uVar8 & 0x400) == 0)
  {
    iVar7 = iVar7 << 0x10;
  }
  iVar7 = iVar7 >> 0x10;
  if ((uVar8 & 0x800) != 0)
  {
    iVar7 = -iVar7;
  }
  iVar7 = (iVar7 << 6) >> 0xc;
  menuRowHighlight_Normal = (iVar7 + 0x40) * 0x100 | 0x80;
  menuRowHighlight_Green = (iVar7 + 0xa0) * 0x100 | 0x400040;
  if (((gGT->renderFlags & 2) != 0) && (s_OTMem[0x1ca8] < 2))
  {
    RenderWeather(s_OTMem + 0x168,*(int *)(s_OTMem + 0x10) + 0x74,s_OTMem + 0x1a40,s_OTMem[0x1ca8],*(uint *)s_OTMem & 0xf);
  }
  if (((gGT->renderFlags & 4) != 0) && (iVar7 = 0, 0 < *(int *)(s_OTMem + 0x2568)))
  {
    do
    {
      iVar22 = *(int *)(s_OTMem + iVar7 * 4 + 0x2558);
      DrawConfetti(s_OTMem + iVar22 * 0x110 + 0x168,*(int *)(s_OTMem + 0x10) + 0x74,s_OTMem + 0x1b00,*(int *)(s_OTMem + 0x1cf0),*(uint *)s_OTMem & 0xf);
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(s_OTMem + 0x2568));
  }
  if (((gGT->renderFlags & 8) != 0) && (*(short *)(s_OTMem + 0x1b0c) != 0))
  {
    RenderStars(s_OTMem + 0x168,*(int *)(s_OTMem + 0x10) + 0x74,s_OTMem + 0x1b0c,s_OTMem[0x1ca8]);
  }
  if (((gGT->renderFlags & 0x100) != 0) && (1 < s_OTMem[0x1ca8]))
  {
    DecalMP_01(param_1);
  }
  if (((s_OTMem[0x1d31] & 8) != 0) && (s_OTMem[0x1ca8] == '\x01') &&
     ((*(uint *)s_OTMem & 0x40) != 0))
  {
    UI_RaceStart_IntroText1P();
  }
  else
  {
    bVar2 = s_OTMem[0x1d31];
    if ((bVar2 & 1) == 0)
    {
      if ((bVar2 & 4) != 0)
      {
        UI_CupStandings_InputAndDraw();
      }
    }
    else
    {
      uVar8 = *(uint *)s_OTMem;
      if ((uVar8 & 0x100000) != 0)
      {
        if ((1 < (byte)s_OTMem[0x2579]) &&
           (s_OTMem[0x2579] = s_OTMem[0x2579] - 1, s_OTMem[0x2579] == '\x01'))
           {
          LOAD_OvrThreads(2);
        }
        iVar7 = LOAD_IsOpen_AdvHub();
        if (iVar7 != 0)
        {
          if (0xfff < *(s16 *)(s_OTMem + 0x139A))
          {
            FUN_800b1c90();
            if (AkuHint_RequestedHint != -1)
            {
              FUN_800b3dd8((int)AkuHint_RequestedHint,(int)AkuHint_boolInterruptWarppad);
              AkuHint_RequestedHint = -1;
              AkuHint_boolInterruptWarppad = 0;
            }
          }
          if (s_OTMem[0x2579] != '\0')
          {
            INSTANCE_LevDelayedLInBs(level->unk10,level->unk0C);
            puVar14 = s_OTMem;
            puVar21 = (uint *)(s_OTMem + 8);
            s_OTMem[0x2579] = 0;
            puVar4 = s_OTMem;
            *(uint *)(puVar14 + 8) = *puVar21 & 0xfffffeff;
            *(undefined2 *)(s_OTMem + 0x139C) = 0x1000;
            *(undefined2 *)(s_OTMem + 0x139E) = 0x2aa;
          }
        }
        else
        {
          if (0xfff < *(s16 *)(s_OTMem + 0x139A))
          {
            UI_RenderFrame_AdvHub();
          }
        }
      }
      else
      {
        if ((uVar8 & 0x200000) != 0)
        {
          if (gGT->timerEndOfRaceVS == 0)
          {
            if (1 < stage + 5U)
            {
              if ((uVar8 & 0x8000000) != 0)
              {
                FUN_8009f710();
              }
              else if ((uVar8 & 0x20000) != 0)
              {
                FUN_8009fdc8();
              }
              else if ((uVar8 & 0x400000) != 0)
              {
                FUN_8009f704();
              }
              else if ((uVar8 & 0x4000000) != 0)
              {
                FUN_800a01d8();
              }
              else if ((uVar8 & 0x80000) != 0)
              {
                FUN_8009f704();
              }
              else if ((gGT->gameMode2 & 0x10) != 0)
              {
                gGT->hudFlags = bVar2 & 0xfe;
                gGT->hudFlags = gGT->hudFlags | 4;
              }
              else
              {
                FUN_8009f718();
              }
            }
          }
          else
          {
            if ((uVar8 & 0x8000000) != 0)
            {
              UI_RenderFrame_CrystChall();
            }
            else
            {
              UI_RenderFrame_Racing();
            }
          }
        }
        else
        {
          if ((uVar8 & 0x8000000) != 0)
          {
            UI_RenderFrame_CrystChall();
          }
          else
          {
            UI_RenderFrame_Racing();
          }
        }
      }
    }
  }
  if (((gGT->renderFlags & 0x10) != 0) && (s_OTMem[0x1ca8] < 3))
  {
    RedBeaker_RenderRain((u8 *)param_1 + 0x168,*(int *)((int)param_1 + 0x10) + 0x74,s_OTMem + 0x19e8,s_OTMem[0x1ca8],*(uint *)s_OTMem & 0xf);
  }
  iVar7 = LOAD_IsOpen_Podiums();
  if ((iVar7 != 0) && (gGT->levelID == 0x29))
  {
    FUN_800b0b38();
  }
  if ((gGT->renderFlags & 0x20) != 0)
  {
    backBuffer = gGT->backBuffer;
    cameraDc0 = (uint *)gGT->cameraDC[0];
    uVar8 = s_OTMem[0x1ca8] - 1;
    if ((*(uint *)s_OTMem & 0x4000000) != 0)
    {
      uVar8 = uVar8 | 4;
    }
    uVar9 = RenderBucket_QueueLevInstances(cameraDc0,(int)backBuffer + 0x90,*(undefined4 *)(s_OTMem + 0x1c94),LOD[uVar8],s_OTMem[0x1ca8],*(uint *)s_OTMem & 0xf);
    uVar8 = s_OTMem[0x1ca8] - 1;
    if ((*(uint *)s_OTMem & 0x4000000) != 0)
    {
      uVar8 = uVar8 | 4;
    }
    puVar10 = (undefined4 *)
              RenderBucket_QueueNonLevInstances(*(undefined4 *)(s_OTMem + 0x1904),(int)backBuffer + 0x90,uVar9,LOD[uVar8],s_OTMem[0x1ca8],*(uint *)s_OTMem & 0xf);
    *puVar10 = 0;
  }
  if ((gGT->renderFlags & 0x200) != 0)
  {
    if (gGT->numPlyrCurrGame != '\0')
    {
      iVar7 = 0;
      iVar22 = 0x168;
      do
      {
        Particle_RenderList((int)param_1 + iVar22,*(undefined4 *)(s_OTMem + 0x1c9c));
        iVar22 = iVar22 + 0x110;
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)(uint)(byte)gGT->numPlyrCurrGame);
    }
  }
  iVar7 = 0;
  if (gGT->numPlyrCurrGame != '\0')
  {
    iVar22 = 0x168;
    puVar21 = param_1;
    do
    {
      PushBuffer_SetDrawEnv_Normal(*(uint *)((int)puVar21 + 0x25c) + 0xffc,(uint *)((int)param_1 + iVar22),*(uint *)((int)param_1 + 0x10),0,0);
      iVar22 = iVar22 + 0x110;
      puVar21 = (uint *)((int)puVar21 + 0x110);
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)(uint)(byte)gGT->numPlyrCurrGame);
  }
  if (((gGT->renderFlags & 0x100) != 0) && (1 < (byte)s_OTMem[0x1ca8]))
  {
    DecalMP_02(param_1);
  }
  if ((gGT->renderFlags & 0x40) != 0)
  {
    iVar7 = LOAD_IsOpen_RacingOrBattle();
    if (iVar7 != 0)
    {
      FUN_800b0dbc();
      FUN_800b0e68();
      FUN_800b1bd8(*(undefined4 *)(s_OTMem + 0x1bb8));
      FUN_800b1714(*(undefined4 *)(s_OTMem + 0x1bcc));
      FUN_800b95fc(*(undefined4 *)(s_OTMem + 0x1bf4),(u8 *)param_1 + 0x168);
      FUN_800b6d58(*(undefined4 *)(s_OTMem + 0x1c08));
      FUN_800b9dd8(*(undefined4 *)(s_OTMem + 0x1c1c));
    }
    iVar7 = LOAD_IsOpen_AdvHub();
    if ((iVar7 != 0) && ((*(uint *)s_OTMem & 0x100000) != 0))
    {
      FUN_800abbdc();
    }
    iVar7 = 0;
    VehTurbo_ProcessBucket(*(undefined4 *)(s_OTMem + 0x1be0));
    if (gGT->numPlyrCurrGame != '\0')
    {
      iVar22 = 0x168;
      do
      {
        iVar18 = (int)param_1 + iVar22;
        VehGroundSkids_Main(*(undefined4 *)(s_OTMem + 0x1b2c),iVar18);
        iVar22 = iVar22 + 0x110;
        VehGroundSkids_Main(*(undefined4 *)(s_OTMem + 0x1b40),iVar18);
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)(uint)(byte)gGT->numPlyrCurrGame);
    }
  }
  if (((*(uint *)s_OTMem & 0x2000) != 0) && (iVar7 = LOAD_IsOpen_MainMenu(), iVar7 != 0))
  {
    FUN_800ac178();
  }
  if ((gGT->renderFlags & 0x20) != 0)
  {
    RenderBucket_Execute(*(undefined4 *)(s_OTMem + 0x1c94),*(int *)(s_OTMem + 0x10) + 0x74);
  }
  if ((gGT->renderFlags & 0x80) != 0)
  {
    if (*(int *)(s_OTMem + 0x1b2c) != 0)
    {
      DrawTires_Solid(*(int *)(s_OTMem + 0x1b2c),*(int *)(s_OTMem + 0x10) + 0x74,gGT->numPlyrCurrGame);
      DrawTires_Reflection(*(undefined4 *)(s_OTMem + 0x1b2c),*(int *)(s_OTMem + 0x10) + 0x74,gGT->numPlyrCurrGame);
    }
    if (s_OTMem[0x1cab] != '\0')
    {
      DrawTires_Solid(*(undefined4 *)(s_OTMem + 0x1b40),*(int *)(s_OTMem + 0x10) + 0x74,gGT->numPlyrCurrGame);
      DrawTires_Reflection(*(undefined4 *)(s_OTMem + 0x1b40),*(int *)(s_OTMem + 0x10) + 0x74,gGT->numPlyrCurrGame);
    }
    if (*(int *)(s_OTMem + 0x1b54) != 0)
    {
      DrawTires_Solid(*(int *)(s_OTMem + 0x1b54),*(int *)(s_OTMem + 0x10) + 0x74,gGT->numPlyrCurrGame);
      DrawTires_Reflection(*(undefined4 *)(s_OTMem + 0x1b54),*(int *)(s_OTMem + 0x10) + 0x74,gGT->numPlyrCurrGame);
    }
  }
  if ((gGT->renderFlags & 0x400) != 0)
  {
    VehGroundShadow_Main();
  }
  if ((gGT->renderFlags & 0x800) != 0)
  {
    Torch_Main(*(undefined4 *)(s_OTMem + 0x1ca0),(uint *)((int)param_1 + 0x168),*(int *)(s_OTMem + 0x10) + 0x74,gGT->numPlyrCurrGame,*(int *)(s_OTMem + 0xc) * 0x128);
  }
  PushBuffer_FadeAllWindows();
  if (((gGT->renderFlags & 1) != 0) && (iVar26 != 0))
  {
    visMem = (VisMem *)M2C_FIELD(gGT, VisMem **, 0x1A38);
    backBuffer = gGT->backBuffer;
    pushBuffer0 = (uint *)((int)param_1 + 0x168);
    pushBufferView0 = &gGT->pushBuffer[0];
    levRenderList0 = &gGT->levRenderLists[0];
    firstPushBufferOt = M2C_FIELD(gGT, s32 *, 0x25C);
    bVar2 = s_OTMem[0x1ca8];
    if (bVar2 == 2)
    {
      CTR_ClearRenderLists_1P2P(param_1,2);
      if ((level->configFlags & 4) == 0)
      {
        AnimateWater2P(gGT->timer,level->unk34,level->unk38,level->unk44,visMem->visOVertList[0],visMem->visOVertList[1]);
      }
      iVar22 = 0;
      RenderLists_PreInit();
      gGT->bspLeafsDrawn = 0;
      iVar18 = 0x1808;
      iVar7 = 0x168;
      do
      {
        iVar23 = (int)param_1 + iVar7;
        puVar10 = &visMem->visLeafList[iVar22];
        iVar12 = (int)param_1 + iVar18;
        iVar18 = iVar18 + 0x30;
        iVar7 = iVar7 + 0x110;
        iVar23 = RenderLists_Init1P2P(meshInfo->unk18,*puVar10,iVar23,iVar12,puVar10[0x20],gGT->numPlyrCurrGame);
        iVar22 = iVar22 + 1;
        gGT->bspLeafsDrawn = gGT->bspLeafsDrawn + iVar23;
      } while (iVar22 < 2);
      iVar7 = 0;
      iVar22 = 0x168;
      FUN_800a0cbc(levRenderList0,pushBuffer0,iVar26,(int)backBuffer + 0x74,visMem->visFaceList[0],visMem->visFaceList[1],level->unk44);
      puVar21 = param_1;
      do
      {
        iVar26 = (int)param_1 + iVar22;
        puVar16 = puVar21 + 0x97;
        puVar21 = puVar21 + 0x44;
        iVar22 = iVar22 + 0x110;
        iVar7 = iVar7 + 1;
        CAM_SkyboxGlow(level->skyboxGlow,iVar26,(int)backBuffer + 0x74,*puVar16 + 0xffc);
      } while (iVar7 < 2);
    }
    else if (bVar2 == 1)
    {
      CTR_ClearRenderLists_1P2P(param_1,1);
        if (((level->configFlags & 4U) == 0) && (level != (Level *)0x0))
        {
          AnimateWater1P(gGT->timer,level->unk34,level->unk38,level->unk44,visMem->visOVertList[0]);
        }
        else
        {
          AnimateQuad(gGT->timer << 7,level->unk174,level->unk178,visMem->visSCVertList[0]);
        }
        iVar7 = pushBufferView0->distanceToScreenPrev;
        if ((*(int *)(s_OTMem + 0x1a10) == 0x28) ||
           (((*(uint *)s_OTMem & 0x20000000) != 0 && (*(int *)(s_OTMem + 0x1a10) != 0x25))))
           {
          DAT_1f800014 = 0x1e00;
          DAT_1f800018 = 0x640;
          DAT_1f80001c = 0x640;
          DAT_1f800020 = 0x500;
          DAT_1f800024 = 0x280;
          DAT_1f800028 = 0x140;
          DAT_1f80002c = 0x780;
        }
        else
        {
          iVar22 = iVar7 * 0x2080;
          if (iVar22 < 0)
          {
            iVar22 = iVar22 + 0xff;
          }
          DAT_1f800024 = iVar7 * 7;
          iVar18 = iVar7 * 0x380;
          DAT_1f800014 = iVar22 >> 8;
          DAT_1f800020 = iVar7 * 0xc;
          DAT_1f800018 = iVar7 * 0x1a;
          DAT_1f80001c = iVar7 * 0x18;
          if (iVar18 < 0)
          {
            iVar18 = iVar18 + 0xff;
          }
          DAT_1f800028 = iVar18 >> 8;
          DAT_1f80002c = DAT_1f800018 + 0x140;
        }
        RenderLists_PreInit();
        puVar21 = pushBuffer0;
        uVar8 = RenderLists_Init1P2P(meshInfo->unk18,visMem->visLeafList[0],puVar21,levRenderList0,visMem->visLeafSrc[0],gGT->numPlyrCurrGame);
        gGT->bspLeafsDrawn = uVar8;
        FUN_800a0cbc(levRenderList0,puVar21,(int)level->meshInfo,(int)backBuffer + 0x74,visMem->visFaceList[0],level->unk44);
        DrawSky_Full(level->skybox,puVar21,(int)backBuffer + 0x74);
      if ((level->configFlags & 1U) != 0)
      {
        CAM_SkyboxGlow(level->skyboxGlow,puVar21,(int)backBuffer + 0x74,firstPushBufferOt + 0xffc);
      }
    }
    else if (bVar2 == 3)
    {
      CTR_ClearRenderLists_3P4P(param_1,3);
      if ((level->configFlags & 4U) == 0)
      {
        AnimateWater3P(gGT->timer,level->unk34,level->unk38,level->unk44,visMem->visOVertList[0],visMem->visOVertList[1],visMem->visOVertList[2]);
      }
      iVar22 = 0;
      RenderLists_PreInit();
      gGT->bspLeafsDrawn = 0;
      iVar18 = 0x1808;
      iVar7 = 0x168;
      do
      {
        iVar23 = (int)param_1 + iVar7;
        iVar12 = (int)param_1 + iVar18;
        puVar10 = &visMem->visLeafList[iVar22];
        iVar18 = iVar18 + 0x30;
        iVar7 = iVar7 + 0x110;
        iVar23 = RenderLists_Init3P4P(meshInfo->unk18,*puVar10,iVar23,iVar12,puVar10[0x20]);
        iVar22 = iVar22 + 1;
        gGT->bspLeafsDrawn = gGT->bspLeafsDrawn + iVar23;
      } while (iVar22 < 3);
      iVar7 = 0;
      iVar22 = 0x168;
      FUN_800a0cbc(levRenderList0,pushBuffer0,iVar26,(int)backBuffer + 0x74,visMem->visFaceList[0],visMem->visFaceList[1],visMem->visFaceList[2],level->unk44);
      puVar21 = param_1;
      do
      {
        iVar26 = (int)param_1 + iVar22;
        puVar16 = puVar21 + 0x97;
        puVar21 = puVar21 + 0x44;
        iVar22 = iVar22 + 0x110;
        iVar7 = iVar7 + 1;
        CAM_SkyboxGlow(level->skyboxGlow,iVar26,(int)backBuffer + 0x74,*puVar16 + 0xffc);
      } while (iVar7 < 3);
    }
    else if (bVar2 == 4)
    {
      CTR_ClearRenderLists_3P4P(param_1,4);
      if ((level->configFlags & 4U) == 0)
      {
        AnimateWater4P(gGT->timer,level->unk34,level->unk38,level->unk44,visMem->visOVertList[0],visMem->visOVertList[1],visMem->visOVertList[2],visMem->visOVertList[3]);
      }
      iVar22 = 0;
      RenderLists_PreInit();
      gGT->bspLeafsDrawn = 0;
      iVar18 = 0x1808;
      iVar7 = 0x168;
      do
      {
        iVar23 = (int)param_1 + iVar7;
        iVar12 = (int)param_1 + iVar18;
        puVar10 = &visMem->visLeafList[iVar22];
        iVar18 = iVar18 + 0x30;
        iVar7 = iVar7 + 0x110;
        iVar23 = RenderLists_Init3P4P(meshInfo->unk18,*puVar10,iVar23,iVar12,puVar10[0x20]);
        iVar22 = iVar22 + 1;
        gGT->bspLeafsDrawn = gGT->bspLeafsDrawn + iVar23;
      } while (iVar22 < 4);
      iVar7 = 0;
      iVar22 = 0x168;
      FUN_800a0cbc(levRenderList0,pushBuffer0,iVar26,(int)backBuffer + 0x74,visMem->visFaceList[0],visMem->visFaceList[1],visMem->visFaceList[2],visMem->visFaceList[3],level->unk44);
      puVar21 = param_1;
      do
      {
        iVar26 = (int)param_1 + iVar22;
        puVar16 = puVar21 + 0x97;
        puVar21 = puVar21 + 0x44;
        iVar22 = iVar22 + 0x110;
        iVar7 = iVar7 + 1;
        CAM_SkyboxGlow(level->skyboxGlow,iVar26,(int)backBuffer + 0x74,*puVar16 + 0xffc);
      } while (iVar7 < 4);
    }
    iVar7 = 0;
    if (gGT->numPlyrCurrGame != '\0')
    {
      iVar26 = 0x168;
      puVar16 = pushBuffer0;
      puVar21 = param_1;
      do
      {
        iVar26 = iVar26 + 0x110;
        puVar1 = puVar21 + 0x97;
        puVar21 = puVar21 + 0x44;
        PushBuffer_SetDrawEnv_Normal(*puVar1 + 0xffc,puVar16,(uint)backBuffer,0,0);
        iVar7 = iVar7 + 1;
        puVar16 = (uint *)((int)param_1 + iVar26);
      } while (iVar7 < (int)(uint)(byte)gGT->numPlyrCurrGame);
    }
    if (((s_OTMem[0x1d31] & 1) != 0) && (1 < s_OTMem[0x1ca8]))
    {
      UI_RenderFrame_Wumpa3D_2P3P4P(param_1);
    }
    if (((gGT->renderFlags & 0x100) != 0) && (1 < s_OTMem[0x1ca8]))
    {
      DecalMP_03(param_1);
    }
    if (((*param_1 & 0x20102000) == 0) && (stage != -4))
    {
      DotLights_AudioAndVideo(param_1);
    }
    if ((gGT->renderFlags & 0x8000) != 0)
    {
      if ((((*(uint *)s_OTMem & 0x20) != 0) && (2 < s_OTMem[0x1ca8])) &&
         (iVar7 = 0, s_OTMem[0x1ca8] != '\0'))
         {
        iVar26 = 0;
        do
        {
          local_30 = *(undefined2 *)(s_OTMem + iVar26 + 0x184);
          local_2e = *(undefined2 *)(s_OTMem + iVar26 + 0x186);
          local_2c = *(undefined2 *)(s_OTMem + iVar26 + 0x188);
          local_2a = *(undefined2 *)(s_OTMem + iVar26 + 0x18a);
          RECTMENU_DrawOuterRect_LowLevel(&local_30,4,2,ptrColor[*(int *)(*(int *)(s_OTMem + iVar7 * 4 + 0x24ec) + 0x4e8) + 0x18],0,*(int *)(s_OTMem + 0x147c) + 0xc);
          iVar7 = iVar7 + 1;
          iVar26 = iVar26 + 0x110;
        } while (iVar7 < (int)(uint)s_OTMem[0x1ca8]);
      }
      if (1 < s_OTMem[0x1ca8])
      {
        pvVar17 = *(PrimPolyF4 **)(*(int *)(s_OTMem + 0x10) + 0x80);
        M2C_FIELD(pvVar17, undefined1 *, 3) = 5;
                    /* Probable PsyQ macro: setPolyF4() */
        pvVar17->code = 0x28;
        pvVar17->b0 = 0;
        pvVar17->g0 = 0;
        pvVar17->r0 = 0;
        puVar14 = s_OTMem;
        pvVar17->x0 = 0;
        pvVar17->y0 = 0x6a;
        pvVar17->x1 = 0x200;
        pvVar17->y1 = 0x6a;
        pvVar17->x2 = 0;
        pvVar17->y2 = 0x6e;
        pvVar17->x3 = 0x200;
        pvVar17->y3 = 0x6e;
        AddPrim((void *)(*(int *)(puVar14 + 0x147c) + 0xc),pvVar17);
        *(int *)(*(int *)(s_OTMem + 0x10) + 0x80) =
             *(int *)(*(int *)(s_OTMem + 0x10) + 0x80) + 0x18;
      }
      if (2 < s_OTMem[0x1ca8])
      {
        pvVar17 = *(PrimPolyF4 **)(*(int *)(s_OTMem + 0x10) + 0x80);
        M2C_FIELD(pvVar17, undefined1 *, 3) = 5;
                    /* Probable PsyQ macro: setPolyF4() */
        pvVar17->code = 0x28;
        pvVar17->b0 = 0;
        pvVar17->g0 = 0;
        pvVar17->r0 = 0;
        puVar14 = s_OTMem;
        pvVar17->x0 = 0xfd;
        pvVar17->y0 = 0;
        pvVar17->x1 = 0x103;
        pvVar17->y1 = 0;
        pvVar17->x2 = 0xfd;
        pvVar17->y2 = 0xd8;
        pvVar17->x3 = 0x103;
        pvVar17->y3 = 0xd8;
        AddPrim((void *)(*(int *)(puVar14 + 0x147c) + 0xc),pvVar17);
        *(int *)(*(int *)(s_OTMem + 0x10) + 0x80) =
             *(int *)(*(int *)(s_OTMem + 0x10) + 0x80) + 0x18;
      }
      if (s_OTMem[0x1ca8] == '\x03')
      {
        pvVar17 = *(PrimPolyF4 **)(*(int *)(s_OTMem + 0x10) + 0x80);
        M2C_FIELD(pvVar17, undefined1 *, 3) = 5;
                    /* Probable PsyQ macro: setPolyF4() */
        pvVar17->code = 0x28;
        pvVar17->b0 = 0;
        pvVar17->g0 = 0;
        pvVar17->r0 = 0;
        pvVar17->x0 = 0x100;
        pvVar17->x2 = 0x100;
        puVar14 = s_OTMem;
        pvVar17->y0 = 0x6c;
        pvVar17->x1 = 0x200;
        pvVar17->y1 = 0x6c;
        pvVar17->y2 = 0xd8;
        pvVar17->x3 = 0x200;
        pvVar17->y3 = 0xd8;
        AddPrim((void *)(*(int *)(puVar14 + 0x147c) + 0xc),pvVar17);
        *(int *)(*(int *)(s_OTMem + 0x10) + 0x80) =
             *(int *)(*(int *)(s_OTMem + 0x10) + 0x80) + 0x18;
      }
    }
    if (stage == -1)
    {
      if ((*(uint *)s_OTMem & 0xf) == 0)
      {
        PickupBots_Update();
      }
      PlayLevel_UpdateLapStats();
    }
  }
  if ((*(uint *)s_OTMem & 0x302000) != 0)
  {
    RefreshCard_Entry();
  }
  if (((gGT->renderFlags & 0x2000) != 0) &&
     ((*(char *)(*(int *)((int)param_1 + 0x160) + 0x163) != '\0' || (*(char *)(*(int *)((int)param_1 + 0x160) + 0x167) != '\0'))))
     {
    CAM_ClearScreen(param_1);
  }
  if ((gGT->renderFlags & 0x1000) != 0)
  {
    RaceFlag_DrawSelf();
  }
  PushBuffer_SetDrawEnv_Normal(M2C_FIELD(gGT, s32 *, 0x147C) + 0x10,(uint *)((int)param_1 + 0x1388),*(uint *)((int)param_1 + 0x10),0,0);
  uVar8 = Timer_GetTime_Total();
  puVar14 = s_OTMem;
  *(uint *)((int)param_1 + 0x1cdc) = uVar8;
  if ((gGT->renderFlags & 0x1000) != 0)
  {
    VSync(0);
  }
  cVar5 = gGT->boolDrawOTagInProgress;
  while( true )
  {
    if ((cVar5 == '\0') && (vsyncTillFlip < 1)) goto LAB_800378d0;
    if (6 < gGT->vSyncBetweenDrawSync) break;
    cVar5 = gGT->boolDrawOTagInProgress;
  }
  BreakDraw();
LAB_800378d0:
  if (boolPlayVideoSTR == 1)
  {
    FUN_800b6674(1);
    MoveImage(&videoSTR_src_vramRect,(int)videoSTR_dst_vramX,(int)videoSTR_dst_vramY);
    DrawSync(0);
  }
  uVar8 = Timer_GetTime_Elapsed(gGT->clockDurationStall,0);
  gGT->clockDurationStall = uVar8;
  frontBuffer = gGT->frontBuffer;
  if (frontBuffer != (DB *)0x0)
  {
    vsyncTillFlip = 2;
    uVar8 = boolDebugDispEnv & 1;
    M2C_FIELD(gGT, undefined4 *, 0x1CD8) = M2C_FIELD(gGT, undefined4 *, 0x1CC4);
    if (uVar8 == 0)
    {
      puVar14 = (undefined *)((int)frontBuffer + 0x5c);
    }
    else
    {
      puVar14 = &blank_debug_DispEnv;
    }
    PutDispEnv(puVar14);
    PutDrawEnv(frontBuffer);
    gGT->frontBuffer = (DB *)0x0;
    frontBuffer = (DB *)0x0;
  }
  puVar14 = s_OTMem;
  gGT->frontBuffer = (DB *)((int)param_1 - (gGT->swapchainIndex * 0xa4 + -0xbc));
  puVar14[0x1d30] = 1;
  firstPushBufferOt = M2C_FIELD(gGT, s32 *, 0x25C);
  DrawOTag(firstPushBufferOt + 0xffc);
  gGT->frameTimerNotPaused = gGT->frameTimerVsyncCallback;
  return;
}
