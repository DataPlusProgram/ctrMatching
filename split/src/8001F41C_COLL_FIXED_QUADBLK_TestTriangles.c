typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))
#define M2C_ERROR(desc) (0)

M2C_UNK COLL_FIXED_QUADBLK_GetNormVecs_HiLOD(); /* extern */
M2C_UNK COLL_FIXED_QUADBLK_GetNormVecs_LoLOD(); /* extern */
M2C_UNK COLL_FIXED_TRIANGL_TestPoint();             /* extern */

void COLL_FIXED_QUADBLK_TestTriangles(void *arg0, void *arg1) {
    s16 temp_v1;
    s16 temp_v1_2;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_t1_3;
    u32 temp_t0;
    u32 temp_t0_2;

    M2C_FIELD(arg1, void **, 0x64) = arg0;
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x12);
    if ((M2C_FIELD(arg1, s32 *, 0x24) & temp_v1) && (temp_t1 = M2C_FIELD(arg0, s32 *, 0x2C), ((M2C_FIELD(arg1, s32 *, 0x28) & temp_v1) == 0)) && (((temp_t1 >> 0x10) - M2C_FIELD(arg1, s16 *, 0x38)) <= 0) && (temp_t1_2 = M2C_FIELD(arg0, s32 *, 0x30), (((s16) temp_t1 - M2C_FIELD(arg1, s16 *, 0x36)) <= 0)) && ((M2C_FIELD(arg1, s16 *, 0x30) - (temp_t1_2 >> 0x10)) <= 0) && (temp_t1_3 = M2C_FIELD(arg0, s32 *, 0x34), (((s16) temp_t1_2 - M2C_FIELD(arg1, s16 *, 0x3A)) <= 0)) && ((M2C_FIELD(arg1, s16 *, 0x34) - (temp_t1_3 >> 0x10)) <= 0) && (temp_v1_2 = M2C_FIELD(arg1, s16 *, 0x22), ((M2C_FIELD(arg1, s16 *, 0x32) - (s16) temp_t1_3) <= 0))) {
        if (temp_v1_2 & 2) {
            if (!(temp_v1_2 & 8)) {
                COLL_FIXED_QUADBLK_GetNormVecs_HiLOD(arg1, arg0);
            }
            COLL_FIXED_TRIANGL_TestPoint();
            COLL_FIXED_TRIANGL_TestPoint();
            COLL_FIXED_TRIANGL_TestPoint();
            COLL_FIXED_TRIANGL_TestPoint();
            temp_t0 = M2C_FIELD(arg0, u32 *, 4);
            if ((temp_t0 >> 0x10) != (temp_t0 & 0xFFFF)) {
                COLL_FIXED_TRIANGL_TestPoint();
                COLL_FIXED_TRIANGL_TestPoint();
                COLL_FIXED_TRIANGL_TestPoint();
                COLL_FIXED_TRIANGL_TestPoint();
            }
        } else {
            COLL_FIXED_QUADBLK_GetNormVecs_LoLOD(arg1, arg0);
            COLL_FIXED_TRIANGL_TestPoint();
            temp_t0_2 = M2C_FIELD(arg0, u32 *, 4);
            if ((temp_t0_2 >> 0x10) != (temp_t0_2 & 0xFFFF)) {
                COLL_FIXED_TRIANGL_TestPoint();
            }
        }
    }
}
