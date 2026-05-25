#ifndef COMMON_H
#define COMMON_H

typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;
typedef unsigned char u8;
typedef signed char s8;

typedef struct Driver Driver;
typedef struct ObjRef ObjRef;
typedef struct Vec3 Vec3;
typedef struct SVec3 SVec3;
typedef struct GameTracker GameTracker;
typedef struct Icon Icon;
typedef struct Instance Instance;
typedef struct QuadBlock QuadBlock;
typedef struct Terrain Terrain;
typedef struct Thread Thread;
typedef struct GhostTape GhostTape;
typedef struct DB DB;
typedef struct Level Level;
typedef struct RainBuffer RainBuffer;
typedef struct ControllerPacket ControllerPacket;
typedef struct MultitapPacket MultitapPacket;
typedef struct RacingWheelData RacingWheelData;
typedef struct GamepadBuffer GamepadBuffer;
typedef struct GamepadSystem GamepadSystem;

typedef s32 M2C_UNK;

#ifndef NULL
#define NULL 0
#endif

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
};

struct SVec3 {
    s16 x;
    s16 y;
    s16 z;
};

struct ObjRef {
    char pad0[0x38];
    u8 terrain_type;
};

struct Thread {
    Thread *next;                  // 0x000
    Thread *prev;                  // 0x004
    char *name;                    // 0x008
    Thread *parentThread;          // 0x00C
    Thread *siblingThread;         // 0x010
    Thread *childThread;           // 0x014
    s32 cooldownFrameCount;        // 0x018
    u32 flags;                     // 0x01C
    s32 timesDestroyed;            // 0x020
    void (*funcThDestroy)(Thread *self); // 0x024
    void (*funcThCollide)(Thread *self); // 0x028
    void (*funcThTick)(Thread *self);    // 0x02C
    void *object;                  // 0x030
    Instance *inst;                // 0x034
    s32 driverUnk1;                // 0x038
    s16 driverUnk2;                // 0x03C
    s16 driverUnk3E;               // 0x03E
    s16 driverUnk3;                // 0x040
    s16 driverHitRadius;           // 0x042
    s16 modelIndex;                // 0x044
    s16 padding;                   // 0x046
};

struct RacingWheelData {
    u16 gamepadCenter;             // 0x000
    s16 deadZone;                  // 0x002
    s16 range;                     // 0x004
};

struct GamepadBuffer {
    s16 unk0;                      // 0x000
    s16 unk1;                      // 0x002
    s16 stickLX;                   // 0x004
    s16 stickLY;                   // 0x006
    s16 stickLxDontUse1;           // 0x008
    s16 stickLyDontUse1;           // 0x00A
    s16 stickRX;                   // 0x00C
    s16 stickRY;                   // 0x00E
    s32 buttonsHeldCurrFrame;      // 0x010
    s32 buttonsTapped;             // 0x014
    s32 buttonsReleased;           // 0x018
    s32 buttonsHeldPrevFrame;      // 0x01C
    ControllerPacket *ptrControllerPacket; // 0x020
    s16 gamepadId;                 // 0x024
    s16 gamepadType;               // 0x026
    u16 framesSinceLastInput;      // 0x028
    char motorDesired[2];          // 0x02A
    char motorPower[2];            // 0x02C
    char motorSubmit[2];           // 0x02E
    s32 shockFrameFreq;            // 0x030
    s32 shockFrameForce1;          // 0x034
    s32 shockFrameForce2;          // 0x038
    s32 shockValFreq;              // 0x03C
    s8 shockValForce1;             // 0x040
    s8 shockValForce2;             // 0x041
    s8 unk42;                      // 0x042
    s8 unk43;                      // 0x043
    s8 unk44;                      // 0x044
    s8 unk45;                      // 0x045
    s16 unk46;                     // 0x046
    s16 unk48;                     // 0x048
    s16 padding4A;                 // 0x04A
    RacingWheelData *rwd;          // 0x04C
};

struct GamepadSystem {
    GamepadBuffer gamepad[8];      // 0x000
    s16 unk280;                    // 0x280
    char unk282[0x0E];             // 0x282
    u32 anyoneHeldCurr;            // 0x290
    u32 anyoneTapped;              // 0x294
    u32 anyoneReleased;            // 0x298
    u32 anyoneHeldPrev;            // 0x29C
    char unk2A0[0x22];             // 0x2A0
    s16 unk2C2;                    // 0x2C2
    s32 unk2C4;                    // 0x2C4
    s32 unk2C8;                    // 0x2C8
    s32 unk2CC;                    // 0x2CC
    MultitapPacket *slotBuffer;    // 0x2D0
    s32 numGamepadsConnected;      // 0x2D4 or later builds after inline slot buffer
    u32 gamepadsConnectedByFlag;   // 0x2D8 or later builds after inline slot buffer
};

struct RainBuffer {
    s32 numParticlesCurr;          // 0x000
    s16 numParticlesMax;           // 0x004
    s16 vanishRate;                // 0x006
    u8 unk8[0x10];                 // 0x008
    s16 cameraPos[3];              // 0x018
    s16 unk22;                     // 0x01E
    u32 colorRgbaTop;              // 0x020
    u32 colorRgbaBottom;           // 0x024
    s32 fillMode;                  // 0x028
    s32 offsetOt;                  // 0x02C
};

typedef struct DriverPickupTimeboxHud {
    s32 cooldown;
    s16 startX;
    s16 startY;
} DriverPickupTimeboxHud;

typedef struct DriverPickupWumpaHud {
    s32 cooldown;
    s16 startX;
    s16 startY;
    s32 numCollected;
} DriverPickupWumpaHud;

typedef struct DriverPickupLetterHud {
    s16 cooldown;
    s16 modelId;
    s16 startX;
    s16 startY;
    s32 numCollected;
} DriverPickupLetterHud;

typedef struct DriverBattleHud {
    s32 cooldown;
    s16 startX;
    s16 startY;
    s32 unk;
    s32 scoreDelta;
    s32 juicedUpCooldown;
    s32 numLives;
    s32 teamId;
} DriverBattleHud;

typedef struct DriverBotData {
    u8 item[8];
    s32 unk5A0;
    void *botNavFrame;
    s32 unk5A8;
    s32 unk5AC;
    s32 botFlags;
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
    s8 estimateRotNav[3];
    s8 estimateRotCurrY;
    s16 distToNextNavXyz;
    s16 distToNextNavXz;
    s16 unk61A;
    s32 unk61C;
    void *maskObj;
    s16 weaponCooldown;
    u8 unk626;
    u8 desiredPathBossOnly;
    s32 unk628;
} DriverBotData;

typedef union DriverKartStateData {
    struct {
        s16 numFramesDrifting;
        s16 driftBoostTimeMs;
        s16 driftTotalTimeMs;
        s8 numBoostsAttempted;
        s8 numBoostsSuccess;
        u8 pad[0x18 - 0x8];
    } drifting;

    struct {
        s16 driftSpinRate;
        s16 spinDir;
        u8 pad[0x18 - 0x4];
    } spinning;

    struct {
        void *maskObj;
        s32 boostMeter;
        s32 fireLevel;
        s16 timeMs;
        s16 unk58E;
        s16 unk590;
        u8 unk592[2];
        s32 boolMaskGrab;
    } revEngine;

    struct {
        void *maskObj;
        s16 angleAxisNormalVec[3];
        s16 animFrame;
        s8 boolParticlesSpawned;
        s8 boolStillFalling;
        s8 boolLiftingPlayer;
        s8 boolWhistle;
        u8 unused[8];
    } maskGrab;

    struct {
        s32 timer;
        s32 heightOffset;
        s32 quadHeight;
        s32 numParticle;
        s32 beamHeight;
    } warp;

    u8 raw[0x18];
} DriverKartStateData;

struct Driver {
    Icon **wheelSprites;                 // 0x000
    u16 wheelSize;                       // 0x004
    s16 wheelRotation;                   // 0x006
    u32 tireColor;                       // 0x008
    s16 clockReceive;                    // 0x00C
    s16 hazardTimer;                     // 0x00E
    Instance *instBombThrow;             // 0x010
    Instance *instBubbleHold;            // 0x014
    Instance *instTntRecv;               // 0x018
    Instance *instSelf;                  // 0x01C
    Instance *instTntSend;               // 0x020
    s32 invincibleTimer;                 // 0x024
    s32 invisibleTimer;                  // 0x028
    u32 instFlagsBackup;                 // 0x02C
    s8 numWumpas;                        // 0x030
    s8 numCrystals;                      // 0x031
    s8 numTimeCrates;                    // 0x032
    s8 accelConst;                       // 0x033
    s8 turnConst;                        // 0x034
    s8 turboConst;                       // 0x035
    s8 heldItemId;                       // 0x036
    s8 numHeldItems;                     // 0x037
    s16 superEngineTimer;                // 0x038
    s16 itemRollTimer;                   // 0x03A
    s16 noItemTimer;                     // 0x03C
    s16 unkNoItemTimerLapTime;           // 0x03E
    s32 lapTime;                         // 0x040
    u8 lapIndex;                         // 0x044
    u8 clockSend;                        // 0x045
    s16 jumpMeter;                       // 0x046
    s16 jumpMeterTimer;                  // 0x048
    u8 driverId;                         // 0x04A
    s8 simpTurnState;                    // 0x04B
    u8 matrixArray;                      // 0x04C
    u8 matrixIndex;                      // 0x04D
    s16 numTurbos;                       // 0x04E
    u16 frameAgainstWall;                // 0x050
    u16 pad52;                           // 0x052

    void *funcPtrs[13];                  // 0x054

    Vec3 velocity;                       // 0x088
    Vec3 originToCenter;                 // 0x094
    QuadBlock *currBlockTouching;        // 0x0A0
    SVec3 normalVecUp;                   // 0x0A4
    s16 unkAA;                           // 0x0AA
    s16 spsHitPos[4];                    // 0x0AC
    s16 spsNormalVec[4];                 // 0x0B4
    u32 stepFlagSet;                     // 0x0BC
    s16 ampTurnState;                    // 0x0C0
    s8 currentTerrain;                   // 0x0C2
    s8 skidmarkFrameIndex;               // 0x0C3
    u8 skidmarks[0x200];                 // 0x0C4
    u32 skidmarkEnableFlags;             // 0x2C4
    u32 actionsFlagSet;                  // 0x2C8
    u32 actionsFlagSetPrevFrame;         // 0x2CC
    s32 quadBlockHeight;                 // 0x2D0
    Vec3 posCurr;                        // 0x2D4
    Vec3 posPrev;                        // 0x2E0
    s16 rotCurr[4];                      // 0x2EC
    s16 rotPrev[4];                      // 0x2F4
    s32 sfxDistortOffset;                // 0x2FC
    void *driverAudioPtrs[4];            // 0x300
    u8 matrixMovingDir[0x20];            // 0x310
    u8 matrixFacingDir[0x20];            // 0x330
    QuadBlock *underDriver;              // 0x350
    QuadBlock *lastValid;                // 0x354
    Terrain *terrainMeta1;               // 0x358
    Terrain *terrainMeta2;               // 0x35C

    SVec3 axisAngle1NormalVec;           // 0x360
    s8 forcedJumpTrampoline;             // 0x366
    s8 clockFlash;                       // 0x367
    s16 axisAngle2NormalVec[3];          // 0x368
    s16 unk36E;                          // 0x36E
    s16 axisAngle3NormalVec[3];          // 0x370
    s8 kartState;                        // 0x376
    s8 screenOffsetY;                    // 0x377
    s16 axisAngle4NormalVec[3];          // 0x378
    s16 unk37E;                          // 0x37E
    s8 normalVecId;                      // 0x380
    s8 unk381;                           // 0x381
    s16 buttonUsedToStartDrift;          // 0x382
    s16 posWallColl[3];                  // 0x384
    s16 scrubMeta8;                      // 0x38A
    s16 speed;                           // 0x38C
    s16 speedApprox;                     // 0x38E
    s16 jumpHeightCurr;                  // 0x390
    s16 jumpHeightPrev;                  // 0x392
    s16 axisRotationY;                   // 0x394
    s16 axisRotationX;                   // 0x396
    s16 unk398;                          // 0x398
    s16 angle;                           // 0x39A
    s16 baseSpeed;                       // 0x39C
    s16 fireSpeed;                       // 0x39E
    s32 xSpeed;                          // 0x3A0
    s32 ySpeed;                          // 0x3A4
    s32 zSpeed;                          // 0x3A8
    s16 unkVectorX;                      // 0x3AC
    s16 unkVectorY;                      // 0x3AE
    s16 unkVectorZ;                      // 0x3B0
    s16 unk3B2;                          // 0x3B2
    s16 rotationSpinRate;                // 0x3B4
    s16 engineSoundData[2];              // 0x3B6
    s16 japanTurboUnknown;               // 0x3BA
    s16 unkSpeedValue1;                  // 0x3BC
    s16 unkSpeedValue2;                  // 0x3BE
    s16 mashingXMakesItBig;              // 0x3C0
    s16 mashXUnknown;                    // 0x3C2
    s16 unknownDriverBaseSpeed;          // 0x3C4
    s16 turnAngleCurr;                   // 0x3C6
    s16 turnAnglePrev;                   // 0x3C8
    s16 unk3CA;                          // 0x3CA
    SVec3 accel;                         // 0x3CC
    s16 unkLerpToForwards;               // 0x3D2
    s16 unk3D4[3];                       // 0x3D4
    s16 multDrift;                       // 0x3DA
    s16 turboMeterRoomLeft;              // 0x3DC
    s16 turboOutsideTimer;               // 0x3DE
    s16 vehFireAudioCooldown;            // 0x3E0
    s16 reserves;                        // 0x3E2
    s16 fireSpeedCap;                    // 0x3E4
    s16 numFramesSpentSteering;          // 0x3E6
    s16 forwardDir;                      // 0x3E8
    s16 previousFrameMultDrift;          // 0x3EA
    s16 timeUntilDriftSpinout;           // 0x3EC
    s16 distanceFromGround;              // 0x3EE
    s16 jumpTenBuffer;                   // 0x3F0
    s16 jumpCooldownMs;                  // 0x3F2
    s16 jumpCoyoteTimerMs;               // 0x3F4
    s16 jumpForcedMs;                    // 0x3F6
    s16 jumpInitialVelY;                 // 0x3F8
    s16 jumpUnknown;                     // 0x3FA
    s16 jumpLandingBoost;                // 0x3FC
    s16 set0xF0OnWallRub;                // 0x3FE
    s16 noInputTimer;                    // 0x400
    s16 burnTimer;                       // 0x402
    s16 squishTimer;                     // 0x404
    s16 startDriving0x60;                // 0x406
    s16 startRollback0x280;              // 0x408
    s16 unknownTraction;                 // 0x40A
    s16 jumpSquishStretch;               // 0x40C
    s16 unk40E;                          // 0x40E
    s16 jumpSquishStretch2;              // 0x410
    s16 unk412;                          // 0x412
    s16 fillerShort;                     // 0x414

    s16 constGravity;                    // 0x416
    s16 constJumpForce;                  // 0x418
    s16 constPedalFrictionPerpendicular; // 0x41A
    s16 constPedalFrictionForward;       // 0x41C
    s16 constNoPedalFrictionPerpendicular; // 0x41E
    s16 constNoPedalFrictionForward;     // 0x420
    s16 constBrakeFriction;              // 0x422
    s16 constDriftCurve;                 // 0x424
    s16 constDriftFriction;              // 0x426
    s16 constAccelClassStat;             // 0x428
    s16 constAccelReserves;              // 0x42A
    s16 constSpeedClassStat;             // 0x42C
    s16 constAccelSpeedClassStat;        // 0x42E
    s16 constSingleTurboSpeed;           // 0x430
    s16 constSacredFireSpeed;            // 0x432
    s16 constBackwardSpeed;              // 0x434
    s16 constMaskSpeed;                  // 0x436
    s16 constDamagedSpeed;               // 0x438
    s8 constTurnRate;                    // 0x43A
    s8 constBackwardTurnRate;            // 0x43B
    s16 constTurnDecreaseRate;           // 0x43C
    s16 constTurnInputDelay;             // 0x43E
    s16 constUnk440;                     // 0x440
    s16 constTerminalVelocity;           // 0x442
    s16 constUnk444;                     // 0x444
    s8 constSteerAccelStage4FirstFrame;  // 0x446
    s8 constSteerAccelStage2FirstFrame;  // 0x447
    s8 constSteerAccelStage2FrameLength; // 0x448
    s8 boolFirstFrameSinceRevEngine;     // 0x449
    s16 constSteerAccelStage1MaxSteer;   // 0x44A
    s16 constSteerAccelStage1MinSteer;   // 0x44C
    s16 unk44E;                          // 0x44E
    s16 unk450;                          // 0x450
    s16 constModelRotVelMax;             // 0x452
    s16 constModelRotVelMin;             // 0x454
    s8 unusedPadding;                    // 0x456
    s8 angleMaxCounterSteer;             // 0x457
    u8 unk458;                           // 0x458
    s8 unk459;                           // 0x459
    s8 unk45A;                           // 0x45A
    s8 unk45B;                           // 0x45B
    s8 constTurnResistMin;               // 0x45C
    s8 constTurnResistMax;               // 0x45D
    s8 constSteerVelDriftSwitchWay;      // 0x45E
    s8 constSteerVelDriftStandard;       // 0x45F
    s8 powerSlideVal;                           // 0x460
    s8 unk461;                           // 0x461
    s8 unk462;                           // 0x462
    s8 constDriftingFramesTillSpinout;   // 0x463
    s16 unk464;                          // 0x464
    s16 unk466;                          // 0x466
    s16 constDriftingCameraSpinRate;     // 0x468
    s8 unk46A;                           // 0x46A
    s8 unk46B;                           // 0x46B
    s16 unk46C;                          // 0x46C
    s16 unk46E;                          // 0x46E
    s16 unk470;                          // 0x470
    s16 unk472;                          // 0x472
    s16 unk474;                          // 0x474
    s8 constTurboMaxRoom;                // 0x476
    s8 constTurboLowRoomWarning;         // 0x477
    s8 constTurboFullBarReserveGain;     // 0x478
    s8 unk479;                           // 0x479
    s8 unk47A;                           // 0x47A
    s8 unk47B;                           // 0x47B
    s16 unk47C;                          // 0x47C
    s16 unk47E;                          // 0x47E
    s16 unk480;                          // 0x480
    s16 driverRank;                      // 0x482
    s32 constPrototypeKey;               // 0x484

    u32 distanceToFinishCurr;            // 0x488
    u32 distanceToFinishCheckpoint;      // 0x48C
    u32 distanceDrivenBackwards;         // 0x490
    u8 unknownLapRelated[2];             // 0x494
    u16 engineVol;                       // 0x496
    Instance *instBigNum;                // 0x498
    Instance *instFruitDisp;             // 0x49C
    Thread *thCloud;                     // 0x4A0
    Thread *thTrackingMe;                // 0x4A4
    Thread *plantEatingMe;               // 0x4A8
    s32 damageColorTimer;                // 0x4AC

    DriverPickupTimeboxHud pickupTimeboxHud; // 0x4B0
    DriverPickupWumpaHud pickupWumpaHud;     // 0x4B8
    DriverPickupLetterHud pickupLetterHud;   // 0x4C4
    DriverBattleHud battleHud;               // 0x4D0

    s32 framesSinceRaceEndedForThisDriver; // 0x4EC
    s16 quip1;                           // 0x4F0
    s16 quip2;                           // 0x4F2
    s16 quip3;                           // 0x4F4
    s16 quip4;                           // 0x4F6
    Instance *wakeInst;                  // 0x4F8
    s16 wakeScale;                       // 0x4FC
    s8 revEngineState;                   // 0x4FE
    s8 changeStateParam2;                // 0x4FF
    s32 changeStateParam3;               // 0x500
    s32 changeStateParam4;               // 0x504
    s16 alphaScaleBackup;                // 0x508
    s16 driverRankItemValue;             // 0x50A
    s8 numTimesAttackingPlayer[8];       // 0x50C
    s32 timeElapsedInRace;               // 0x514
    s32 distanceDriven;                  // 0x518
    s32 timeSpentWithHighSpeed;          // 0x51C
    s32 timeSpentReversing;              // 0x520
    s32 timeSpentInMud;                  // 0x524
    s32 timeSpentInLastPlace;            // 0x528
    s32 timeSpentInTenWumpa;             // 0x52C
    s32 timeSpentAgainstWall;            // 0x530
    s32 timeSpentUsingReserves;          // 0x534
    s32 timeSpentDrifting;               // 0x538
    s32 timeSpentJumping;                // 0x53C
    s32 timeSpentSpinningOut;            // 0x540
    s32 timeSpentSquished;               // 0x544
    s32 timeSpentEaten;                  // 0x548
    s32 timeSpentBurnt;                  // 0x54C
    s16 highestJump;                     // 0x550
    s16 longestShot;                     // 0x552
    s16 numberOfJumps;                   // 0x554
    s8 numTimesMovingPotionHitSomeone;   // 0x556
    s8 numTimesMissileHitSomeone;        // 0x557
    s8 numTimesClockWeaponUsed;          // 0x558
    s8 numTimesAttacking;                // 0x559
    s8 numTimesBombsHitSomeone;          // 0x55A
    s8 numTimesSquishedSomeone;          // 0x55B
    s8 numTimesMissileLaunched;          // 0x55C
    s8 numTimesMissileHitYou;            // 0x55D
    s8 numTimesBombHitYou;               // 0x55E
    s8 numTimesMotionlessPotionHitYou;   // 0x55F
    s8 numTimesAttackedByPlayer[8];      // 0x560
    s8 numTimesHitWeaponBox;             // 0x568
    s8 numTimesWumpa;                    // 0x569
    s8 numTimesMaskGrab;                 // 0x56A
    s8 unusedAlignment56B;               // 0x56B
    s16 *endOfRaceCommentPtrQuip;        // 0x56C
    s32 endOfRaceCommentCharacterId;     // 0x570
    s32 numMissilesComparedToNumAttacks; // 0x574
    s32 timeWinningDriverSpentLastPlace; // 0x578
    s32 numTimesAttacked;                // 0x57C

    DriverKartStateData kartStates;      // 0x580
    DriverBotData botData;               // 0x598

    GhostTape *ghostTape;                // 0x62C
    s16 ghostId;                         // 0x630
    s16 ghostBoolInit;                   // 0x632
    s16 ghostBoolStarted;                // 0x634
    s16 unk636;                          // 0x636
};

struct GameTracker {
    s32 gameMode1;                    // 0x000
    s32 gameMode1PrevFrame;           // 0x004
    s32 gameMode2;                    // 0x008
    s32 swapchainIndex;               // 0x00C
    DB *backBuffer;                   // 0x010
    DB *frontBuffer;                  // 0x014
    u8 db[0x148];                     // 0x018
    Level *level1;                    // 0x160
    Level *level2;                    // 0x164
    u8 unk168[0x18A8];                // 0x168
    s32 levelID;                      // 0x1A10
    char levelName[0x24];             // 0x1A14
    void *visMem1;                    // 0x1A38
    void *visMem2;                    // 0x1A3C
    RainBuffer rainBuffer[4];         // 0x1A40
    u8 unk1B00[0x1A8];                // 0x1B00
    char numPlyrCurrGame;             // 0x1CA8
    char numPlyrNextGame;             // 0x1CA9
    char numBotsCurrGame;             // 0x1CAA
    char numBotsNextGame;             // 0x1CAB
    u8 unk1CAC[0x1AC];                // 0x1CAC
    s32 cupID;                        // 0x1E58
};

#define gte_SetColorMatrix(r0) __asm__ volatile ( \
    "lw     $12, 0(%0);"                          \
    "lw     $13, 4(%0);"                          \
    "ctc2   $12, $16;"                            \
    "ctc2   $13, $17;"                            \
    "lw     $12, 8(%0);"                          \
    "lw     $13, 12(%0);"                         \
    "lw     $14, 16(%0);"                         \
    "ctc2   $12, $18;"                            \
    "ctc2   $13, $19;"                            \
    "ctc2   $14, $20"                             \
    :                                             \
    : "r"(r0)                                     \
    : "$12", "$13", "$14" )

#define gte_ldv0_xy(xy) __asm__ volatile ( \
    "mtc2 %0, $0"                          \
    :                                      \
    : "r"(xy) )

#define gte_ldv0_z(z) __asm__ volatile ( \
    "mtc2 %0, $1"                         \
    :                                     \
    : "r"(z) )

#define gte_lcv0() __asm__ volatile ( \
    "nop\n\t"                         \
    "nop\n\t"                         \
    ".word 0x4A4C6012"                \
)

#define gte_stmac1(r0) __asm__ volatile ( \
    "swc2 $25, 0(%0)"                     \
    :                                     \
    : "r"(r0)                             \
    : "memory" )

#define gte_stmac2(r0) __asm__ volatile ( \
    "swc2 $26, 0(%0)"                     \
    :                                     \
    : "r"(r0)                             \
    : "memory" )

#define gte_stmac3(r0) __asm__ volatile ( \
    "swc2 $27, 0(%0)"                     \
    :                                     \
    : "r"(r0)                             \
    : "memory" )

#define gte_ldVXY0(x) gte_ldv0_xy(x)
#define gte_ldVZ0(z) gte_ldv0_z(z)

#define gte_ldR11R12(v) __asm__ volatile ( \
    "ctc2 %0, $0"                          \
    :                                      \
    : "r"(v) )

#define gte_ldR13R21(v) __asm__ volatile ( \
    "ctc2 %0, $1"                          \
    :                                      \
    : "r"(v) )

#define gte_ldR22R23(v) __asm__ volatile ( \
    "ctc2 %0, $2"                          \
    :                                      \
    : "r"(v) )

#define gte_ldR31R32(v) __asm__ volatile ( \
    "ctc2 %0, $3"                          \
    :                                      \
    : "r"(v) )

#define gte_ldR33(v) __asm__ volatile ( \
    "ctc2 %0, $4"                       \
    :                                   \
    : "r"(v) )

#define gte_ldL11L12(v) __asm__ volatile ( \
    "ctc2 %0, $8"                          \
    :                                      \
    : "r"(v) )

#define gte_ldL13L21(v) __asm__ volatile ( \
    "ctc2 %0, $9"                          \
    :                                      \
    : "r"(v) )

#define gte_ldL22L23(v) __asm__ volatile ( \
    "ctc2 %0, $10"                         \
    :                                      \
    : "r"(v) )

#define gte_ldL31L32(v) __asm__ volatile ( \
    "ctc2 %0, $11"                         \
    :                                      \
    : "r"(v) )

#define gte_ldL33(v) __asm__ volatile ( \
    "ctc2 %0, $12"                      \
    :                                   \
    : "r"(v) )

#define gte_llv0() __asm__ volatile ( \
    "nop\n\t"                       \
    "nop\n\t"                       \
    ".word 0x4A4A6012"              \
)

#define gte_rtv0() __asm__ volatile ( \
    "nop\n\t"                       \
    "nop\n\t"                       \
    ".word 0x4A486012"              \
)

#define gte_stlvnl(v) __asm__ volatile ( \
    "swc2 $25, 0(%0);"                   \
    "swc2 $26, 4(%0);"                   \
    "swc2 $27, 8(%0)"                    \
    :                                    \
    : "r"(v)                             \
    : "memory" )

#define read_mt(x, y, z) do { \
    gte_stmac1(&(x));         \
    gte_stmac2(&(y));         \
    gte_stmac3(&(z));         \
}while (0)

#define gte_ldR11R12_mem(v) __asm__ volatile ( \
    "ctc2 %0, $0"                              \
    :                                          \
    : "r"(v)                                   \
    : "memory" )

#define gte_ldR13R21_mem(v) __asm__ volatile ( \
    "ctc2 %0, $1"                              \
    :                                          \
    : "r"(v)                                   \
    : "memory" )

#define gte_lcv0_exact() __asm__ volatile ( \
    "nop\n\t"                               \
    "nop\n\t"                               \
    ".word 0x4A406012"                      \
    :                                       \
    :                                       \
    : "memory" )

#define gte_mfc2_mac1(r0) __asm__ volatile ( \
    "mfc2 %0, $25"                           \
    : "=r"(r0)                               \
    :                                        \
    : "memory" )

extern s32 XA_State; //D_8008D708

struct SDATA
{
	short mcStart; // 8008d478
	int unk8008d964;
};

extern struct SDATA *sData;


#endif
