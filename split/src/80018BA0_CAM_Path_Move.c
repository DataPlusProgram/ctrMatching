typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} M2cCAMPathMoveArg1;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cCAMPathMoveArg2;

s32 CAM_Path_GetNumPoints();
extern void *D_8008D2AC;

s32 CAM_Path_Move(s16 arg0, M2cCAMPathMoveArg1 *arg1, M2cCAMPathMoveArg2 *arg2, u16 *arg3)
{
    s16 temp_a0;
    s16 var_s1;
    s32 temp_v0;
    u16 *temp_a1_2;
    u16 var_a2;
    u16 var_v1;
    void *temp_a1;
    void *temp_v1;
    void *temp_v1_2;
    void *var_a1;

    var_s1 = arg0;
    temp_v0 = CAM_Path_GetNumPoints() << 0x10;

    if ((s16) arg0 >= 0) {
        if ((s16) arg0 < (temp_v0 >> 0x10)) {
            temp_a1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(D_8008D2AC, void **, 0x160), void **, 0x134), void **, 0x10);

            var_v1 = M2C_FIELD(temp_a1, u16 *, 0);
            temp_a1 = ((s8 *) temp_a1) + 2;
            var_a2 = M2C_FIELD(temp_a1, u16 *, 0);
            var_a1 = ((s8 *) temp_a1) + 2;

            if ((s16) arg0 >= (s16) var_v1) {
                do {
                    temp_a0 = var_s1 - var_v1;
                    var_s1 = temp_a0;

                    temp_a1_2 = (u16 *) (((s8 *) var_a1) + (((s16) var_v1 * 3) << 2));
                    var_v1 = M2C_FIELD(temp_a1_2, u16 *, 0);
                    temp_a1_2 = (u16 *) (((s8 *) temp_a1_2) + 2);
                    var_a2 = M2C_FIELD(temp_a1_2, u16 *, 0);
                    var_a1 = ((s8 *) temp_a1_2) + 2;
                } while ((temp_a0 << 0x10) >= (var_v1 << 0x10));
            }

            temp_a1 = var_a1;
            temp_v1 = ((s8 *) temp_a1) + (((s16) var_s1 * 3) << 2);
            *arg3 = var_a2;

            arg1->unk0 = M2C_FIELD(temp_v1, u16 *, 0);
            arg1->unk2 = M2C_FIELD(temp_v1, u16 *, 2);
            temp_v1_2 = ((s8 *) temp_v1) + 6;
            arg1->unk4 = M2C_FIELD(temp_v1, u16 *, 4);

            arg2->unk0 = (s16) ((((s32) (M2C_FIELD(temp_v1_2, u16 *, 0) << 0x10) >> 0x14) + 0x800) & 0xFFF);
            arg2->unk2 = (s16) (M2C_FIELD(temp_v1_2, u16 *, 2) >> 4);
            arg2->unk4 = (s16) (M2C_FIELD(temp_v1_2, u16 *, 4) >> 4);

            return 1;
        }

        return 0;
    }

    return 0;
}