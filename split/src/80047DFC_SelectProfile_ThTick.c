typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK ConvertRotToMatrix();            /* extern */
M2C_UNK Vector_SpecLightSpin3D();        /* extern */
extern M2C_UNK D_80085C64;
extern M2C_UNK LoadSave_SpinRateY;

typedef struct
{
    u16 x;
    u16 y;
    u16 z;
} Vec3u16;

void SelectProfile_ThTick(void *arg0)
{
    Vec3u16 sp10;
    s16 temp_s0;
    s16 var_s4;
    s32 *var_s3;
    void *temp_v0;
    void *var_s2;

    var_s4 = 0;
    var_s3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 **, 4);
    var_s2 = var_s3 + 4;

    do
    {
        temp_s0 = var_s4 % 3;

        M2C_FIELD(var_s2, u16 *, 2) =
            (u16)(M2C_FIELD(var_s2, u16 *, 2) +
            *((temp_s0 * 2) + &LoadSave_SpinRateY));

        ConvertRotToMatrix(*var_s3 + 0x30, var_s2);

        if (temp_s0 != 1)
        {
            temp_v0 = (var_s4 * 0xE) + &D_80085C64;

            sp10.x = M2C_FIELD(temp_v0, u16 *, 4);
            sp10.y = M2C_FIELD(temp_v0, u16 *, 6);
            sp10.z = M2C_FIELD(temp_v0, u16 *, 8);

            Vector_SpecLightSpin3D(*var_s3, var_s2, &sp10);
        }

        var_s4 += 1;
        var_s2 += 0xC;
        var_s3 += 0xC;
    } while ((u32)(var_s4 & 0xFFFF) < 0xCU);
}