typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define NULL 0
typedef struct NavFrame {
    s16 pos[3];
    u8 rot[4];
    s16 unk[2];
    s16 flags;
    s16 pathChangeOpcode;
    u8 goBackCount;
    u8 specialBits;
} NavFrame;

typedef struct DriverBotData {
    u8 item[8];
    s32 unk5A0;
    NavFrame *botNavFrame;
    s32 unk5A8;
    s32 unk5AC;
    u32 botFlags;
    s32 botAccel;
    s16 botPath;
    s16 unk5BA;
    s16 rotXz;
    s16 driftUnk1;
    s16 aiMulDrift;
    s16 aiSimpTurnState;
    s16 aiTurboMeter;
    s16 aiFireLevel;
    s32 aiSquishCooldown;
    s32 unk5CC;
    s32 aiSpeedY;
    s32 aiSpeedLinear;
    s32 aiAccelAxis[3];
    s32 aiVelAxis[3];
    s32 aiPosBackup[3];
    s16 aiRot4[4];
    s32 aiProgressCooldown;
    s16 aiRotY608;
    s16 aiQuadblockCheckpointIndex;
    s16 estimatePos[3];
    u8 estimateRotNav[3];
    s8 estimateRotCurrY;
    s16 distToNextNavXyz;
    s16 distToNextNavXz;
    u8 pad61A[6];
    void *maskObj;
} DriverBotData;

typedef struct DriverVec3 {
    s32 x;
    s32 y;
    s32 z;
} DriverVec3;

typedef struct DriverView {
    u8 pad0[0xC];
    s16 clockReceive;
    u8 pad0E[0x3E];
    u8 matrixAnimState;
    u8 matrixAnimFrame;
    u8 pad4E[0x27A];
    u32 actionsFlagSet;
    s32 quadBlockHeight;
    DriverVec3 posCurr;
    DriverVec3 posPrev;
    s16 rotCurr[4];
    u8 pad2F4[0x82];
    u8 kartState;
    u8 pad377[0x65];
    s16 turboMeterRoomLeft;
    s16 turboOutsideTimer;
    u8 pad3E0[2];
    s16 reserves;
    u8 pad3E4[0x20];
    s16 squishTimer;
    u8 pad406[0x192];
    DriverBotData botData;
} DriverView;

typedef struct ThreadBotView {
    u8 pad0[0x1C];
    u32 flags;
    u8 pad20[0x10];
    DriverView *object;
    u8 pad34[0x10];
    s16 modelIndex;
} ThreadBotView;

typedef struct MaskHeadWeaponView {
    u16 rot[3];
    s16 duration;
} MaskHeadWeaponView;

typedef struct NavPathHeaderView {
    u8 pad0[8];
    NavFrame *last;
} NavPathHeaderView;

s32 ThTick_SetAndExec();       /* extern */
MaskHeadWeaponView *VehPickupItem_MaskUseWeapon(); /* extern */
extern void BOTS_ThTick_RevEngine();
extern NavPathHeaderView *NavPath_ptrHeader[];
extern NavFrame *NavPath_ptrNavFrameArray[];

void BOTS_MaskGrab(ThreadBotView *botThread) {
    s32 midpoint;
    s32 flags2C8;
    s32 navIndex;
    DriverView *bot;
    NavFrame *navFrame;
    NavFrame *nextFrame;
    MaskHeadWeaponView *mask;

    bot = botThread->object;
    navIndex = bot->botData.botPath;
    navFrame = bot->botData.botNavFrame;
    nextFrame = navFrame + 1;

    if (NavPath_ptrHeader[navIndex]->last <= nextFrame) {
        nextFrame = NavPath_ptrNavFrameArray[navIndex];
    }

    bot->kartState = 5;
    bot->botData.unk5A8 = (s32) (((s16) navFrame->unk[1] / 2) << 8);

    midpoint = (navFrame->pos[0] + ((s32) (nextFrame->pos[0] - navFrame->pos[0]) / 2)) << 8;
    bot->botData.aiPosBackup[0] = midpoint;
    bot->posPrev.x = midpoint;

    midpoint = (navFrame->pos[1] + ((s32) (nextFrame->pos[1] - navFrame->pos[1]) / 2)) << 8;
    bot->botData.aiPosBackup[1] = midpoint;
    bot->posPrev.y = midpoint;
    bot->quadBlockHeight = midpoint;

    flags2C8 = bot->actionsFlagSet;
    bot->botData.aiSpeedLinear = 0;
    bot->botData.aiSpeedY = 0;
    bot->botData.unk5CC = 0;
    bot->botData.aiVelAxis[2] = 0;
    bot->botData.aiVelAxis[1] = 0;
    bot->botData.aiVelAxis[0] = 0;
    bot->actionsFlagSet = flags2C8 | 1;
    bot->botData.botFlags = bot->botData.botFlags & -80;

    midpoint = (navFrame->pos[2] + ((s32) (nextFrame->pos[2] - navFrame->pos[2]) / 2)) << 8;
    bot->botData.aiPosBackup[2] = midpoint;
    bot->posPrev.z = midpoint;

    bot->rotCurr[0] = (s16) (navFrame->rot[0] * 0x10);
    bot->rotCurr[1] = (s16) (navFrame->rot[1] * 0x10);
    bot->rotCurr[2] = (s16) (navFrame->rot[2] * 0x10);
    bot->botData.aiSquishCooldown = 0;

    bot->botData.aiMulDrift = 0;
    bot->turboMeterRoomLeft = 0;
    bot->reserves = 0;
    bot->clockReceive = 0;
    bot->squishTimer = 0;
    bot->turboOutsideTimer = 0;
    bot->matrixAnimState = 0;
    bot->matrixAnimFrame = 0;
    bot->actionsFlagSet = (s32) (bot->actionsFlagSet & 0xFFF7FFBF);

    if (botThread->modelIndex != 0x4B) {
        botThread->flags = (s32) (botThread->flags & ~0x1000);
    }

    bot->posCurr.x = bot->botData.aiPosBackup[0];
    bot->posCurr.y = bot->botData.aiPosBackup[1] + 0x10000;
    bot->posCurr.z = bot->botData.aiPosBackup[2];

    mask = VehPickupItem_MaskUseWeapon(bot, 1, midpoint, nextFrame);
    bot->botData.maskObj = mask;

    if (mask != NULL) {
        mask->duration = 0x1E00;
        mask->rot[2] = (u16) (mask->rot[2] | 1);
    }

    ThTick_SetAndExec(botThread, BOTS_ThTick_RevEngine);
}
