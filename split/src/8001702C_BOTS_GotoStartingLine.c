typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

void VehBirth_TeleportSelf(s32 arg0, s32 arg1, s32 arg2);
void BOTS_SetRotation(s32 arg0, s32 arg1);
s32 RngDeadCoed(void *arg0);

extern s32 D_8008D698;
extern u8 D_8008D69C[];
extern u8 D_8008D680[];
extern s32 D_8008DAE0[];
extern s32 D_8008CF80;
extern s32 D_8008D668;

void FUN_8001702c(s32 param_1)
{
    u8 temp_byte;
    s32 temp_posX;
    s32 temp_posY;
    s32 temp_posZ;
    s32 temp_model;
    s32 temp_index;
    s32 temp_rng;
    s32 temp_rot;
    s32 temp_flags;
    s32 temp_mult;
    s32 var_s1;

    D_8008D698 = 0;
    VehBirth_TeleportSelf(param_1, 3, 0);

    temp_byte = *((u8 *) (((s8 *) param_1) + 0x4A));
    temp_posZ = *((s32 *) (((s8 *) param_1) + 0x2DC));
    var_s1 = D_8008D69C[temp_byte];
    temp_posX = *((s32 *) (((s8 *) param_1) + 0x2D4));
    temp_posY = *((s32 *) (((s8 *) param_1) + 0x2D8));

    *((s32 *) (((s8 *) param_1) + 0x5F8)) = temp_posZ;
    *((s32 *) (((s8 *) param_1) + 0x5EC)) = 0;
    *((s32 *) (((s8 *) param_1) + 0x5E8)) = 0;
    *((s32 *) (((s8 *) param_1) + 0x5E4)) = 0;
    *((s32 *) (((s8 *) param_1) + 0x5E0)) = 0;
    *((s32 *) (((s8 *) param_1) + 0x5DC)) = 0;
    *((s32 *) (((s8 *) param_1) + 0x5D8)) = 0;
    *((s32 *) (((s8 *) param_1) + 0x5D4)) = 0;
    *((s32 *) (((s8 *) param_1) + 0x5D0)) = 0;
    *((s32 *) (((s8 *) param_1) + 0x5CC)) = 0;
    *((s32 *) (((s8 *) param_1) + 0x5F4)) = temp_posY;
    *((s32 *) (((s8 *) param_1) + 0x5F0)) = temp_posX;

    temp_index = *((s16 *) (((s8 *) param_1) + 0x5B8));
    temp_model = D_8008DAE0[temp_index];
    *((s32 *) (((s8 *) param_1) + 0x5A8)) = 0;
    *((s32 *) (((s8 *) param_1) + 0x5A4)) = temp_model;

    BOTS_SetRotation(param_1, 1);

    var_s1 = (s32) (&D_8008D680[var_s1]);
    temp_byte = *((u8 *) var_s1);
    temp_mult = D_8008CF80 * temp_byte;

    *((s16 *) (((s8 *) param_1) + 0x2F0)) = 0;
    *((s16 *) (((s8 *) param_1) + 0x2F8)) = 0;
    *((s16 *) (((s8 *) param_1) + 0x600)) = 0;
    *((s16 *) (((s8 *) param_1) + 0x2EC)) = 0;
    *((s16 *) (((s8 *) param_1) + 0x2F4)) = 0;
    *((s16 *) (((s8 *) param_1) + 0x5FC)) = 0;

    temp_flags = *((s32 *) (((s8 *) param_1) + 0x2C8));
    temp_rot = *((u8 *) (((s8 *) param_1) + 0x613)) << 4;

    *((s16 *) (((s8 *) param_1) + 0x3C6)) = 0;
    *((s32 *) (((s8 *) param_1) + 0x2C8)) = temp_flags | 0x100000;

    *((s16 *) (((s8 *) param_1) + 0x608)) = temp_rot;
    *((s16 *) (((s8 *) param_1) + 0x39A)) = temp_rot;
    *((s16 *) (((s8 *) param_1) + 0x2EE)) = temp_rot;
    *((s16 *) (((s8 *) param_1) + 0x2F6)) = temp_rot;
    *((s16 *) (((s8 *) param_1) + 0x5FE)) = temp_rot;

    *((s32 *) (((s8 *) param_1) + 0x5B4)) = temp_mult;

    temp_rng = RngDeadCoed(&D_8008D668);
    temp_rng = (temp_rng >> 8) & 0xFF;
    *((u16 *) (((s8 *) param_1) + 0x624)) = temp_rng + 300;
}