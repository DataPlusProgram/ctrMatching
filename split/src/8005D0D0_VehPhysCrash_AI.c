typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
typedef signed char s8;
typedef int s32;

typedef struct NavFrame {
    short pos[3];
    byte rot[4];
    short unk[2];
    short flags;
    short pathChangeOpcode;
    byte goBackCount;
    byte specialBits;
} NavFrame;

typedef struct DriverBotData {
    byte item[8];
    int unk5A0;
    NavFrame *botNavFrame;
    int unk5A8;
    int unk5AC;
    uint botFlags;
    int botAccel;
    short botPath;
    short unk5BA;
    short rotXz;
    short driftUnk1;
    short aiMulDrift;
    short aiSimpTurnState;
    short aiTurboMeter;
    short aiFireLevel;
    int aiSquishCooldown;
    int unk5CC;
    int aiSpeedY;
    int aiSpeedLinear;
    int aiAccelAxis[3];
} DriverBotData;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

ushort D_8008D9EC = 0;
ushort D_8008D9EE = 0;
ushort D_8008D9F0 = 0;

extern ushort D_8009AE38[3][3];
extern int D_8009AE28[3];

extern void ConvertRotToMatrix(int *, int *);

void VehPhysCrash_AI(int param_1, int *param_2)
{
    int iVar1;
    int iVar2;
    int *new_var;

    D_8008D9EC = ((ushort)(*((byte *)((*((int *)(param_1 + 0x5A4))) + 6)))) << 4;
    D_8008D9EE = ((ushort)(*((byte *)((*((int *)(param_1 + 0x5A4))) + 7)))) << 4;
    D_8008D9F0 = ((ushort)(*((byte *)((*((int *)(param_1 + 0x5A4))) + 8)))) << 4;

    ConvertRotToMatrix((int *)D_8009AE38, (int *)(&D_8008D9EC));

    D_8009AE28[0] = ((D_8009AE38[0][2]) << 0x10) >> 0x14;
    D_8009AE28[1] = ((D_8009AE38[1][2]) << 0x10) >> 0x14;
    D_8009AE28[2] = ((D_8009AE38[2][2]) << 0x10) >> 0x14;

    iVar1 = (((D_8009AE28[0] * (*param_2)) + (D_8009AE28[1] * param_2[1])) + (D_8009AE28[2] * param_2[2])) >> 8;

    M2C_FIELD(param_1, DriverBotData *, 0x598).aiSpeedLinear = iVar1;
    M2C_FIELD(param_1, DriverBotData *, 0x598).aiAccelAxis[0] = (*param_2) - ((D_8009AE28[0] * (*(new_var = &iVar1))) >> 8);

    iVar1 = D_8009AE28[2] * iVar1;
    iVar2 = param_2[2];

    M2C_FIELD(param_1, DriverBotData *, 0x598).botFlags = M2C_FIELD(param_1, DriverBotData *, 0x598).botFlags | 8;
    M2C_FIELD(param_1, DriverBotData *, 0x598).aiAccelAxis[2] = iVar2 - (iVar1 >> 8);
}
