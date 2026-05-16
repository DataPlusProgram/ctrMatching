#ifndef COMMON_H

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

typedef s32 M2C_UNK;

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

struct Driver {
    char pad00[0x88];
    Vec3 velocity;
    Vec3 originToCenter;
    s32 unkA0;
    s32 unkA4;
    s16 unkA8;
    s16 unkAA;
    char padAC[0x2D8 - 0xAC];
    s32 posCurrY;
    char pad2DC[0x330 - 0x2DC];
    u32 unk330[5];
    char pad344[0x350 - 0x344];
    ObjRef* underDriver;
    char pad354[0x360 - 0x354];
    s32 unk360;
    s16 unk364;
    char pad366[0x38C - 0x366];
    s16 speed;
    char pad38E[0x394 - 0x38E];
    s16 unk394;
    s16 unk396;
    char pad398[0x3CC - 0x398];
    SVec3 accel;
};

struct GameTracker
{
    s32 gameMode1;
    s32 unk4;
    s32 gameMode2;
    u8 unkC[0x1A04];
    s32 levelID;
    u8 unk1A14[0x444];
    s32 cupID;
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

#define COMMON_H

#endif



extern XA_State; //D_8008D708;