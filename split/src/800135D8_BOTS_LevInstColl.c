typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK COLL_FIXED_BotsSearch();
void *COLL_LevModelMeta();
extern void *D_8008D2AC;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

void BOTS_LevInstColl(void *arg0)
{
    Vec3s sp10;
    Vec3s sp18;
    M2C_UNK (*temp_v0_3)(s32, void *, M2C_UNK);
    s32 temp_s0;
    s32 temp_model;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_s0Ptr;
    void *temp_modelPtr;

    temp_s0Ptr = (void *)0x1F800108;
    temp_modelPtr = M2C_FIELD(D_8008D2AC, void **, 0x160);
    temp_v1 = M2C_FIELD(arg0, void **, 0x30);
    temp_model = M2C_FIELD(temp_modelPtr, s32 *, 0);

    M2C_FIELD(temp_s0Ptr, u16 *, 0x22) = 1U;
    M2C_FIELD(temp_s0Ptr, s16 *, 0xC) = 0x3F;
    M2C_FIELD(temp_s0Ptr, s32 *, 0x24) = 0;
    M2C_FIELD(temp_s0Ptr, s32 *, 0x28) = 0;
    M2C_FIELD(temp_s0Ptr, s16 *, 6) = 0x19;
    M2C_FIELD(temp_s0Ptr, s32 *, 0x2C) = temp_model;

    sp10.x = (s16) ((s32) M2C_FIELD(temp_v1, s32 *, 0x2D4) >> 8);
    sp10.y = ((s32) M2C_FIELD(temp_v1, s32 *, 0x2D8) >> 8) + 0x19;
    sp10.z = (s16) ((s32) M2C_FIELD(temp_v1, s32 *, 0x2DC) >> 8);

    sp18.x = (s16) ((s32) M2C_FIELD(temp_v1, s32 *, 0x2E0) >> 8);
    sp18.y = ((s32) M2C_FIELD(temp_v1, s32 *, 0x2E4) >> 8) + 0x19;
    sp18.z = (s16) ((s32) M2C_FIELD(temp_v1, s32 *, 0x2E8) >> 8);

    COLL_FIXED_BotsSearch(&sp10, &sp18, temp_s0Ptr);

    if (M2C_FIELD(temp_s0Ptr, u16 *, 0x42) != 0) {
        temp_v1_2 = M2C_FIELD(temp_s0Ptr, void **, 0x48);
        M2C_FIELD(temp_s0Ptr, u16 *, 0x22) = M2C_FIELD(temp_s0Ptr, u16 *, 0x22) & 0xFFF7;
        if (M2C_FIELD(temp_v1_2, u8 *, 0) & 0x80) {
            temp_v0 = M2C_FIELD(temp_v1_2, void **, 0x1C);
            temp_s0 = M2C_FIELD(temp_v0, s32 *, 0x2C);
            if (temp_s0 != 0) {
                temp_v0_2 = COLL_LevModelMeta(M2C_FIELD(temp_v0, s16 *, 0x3C));
                if (temp_v0_2 != NULL) {
                    temp_v0_3 = M2C_FIELD(temp_v0_2, M2C_UNK (**)(s32, void *, M2C_UNK), 8);
                    if (temp_v0_3 != NULL) {
                        temp_v0_3(temp_s0, arg0, temp_s0Ptr);
                    }
                }
            }
        }
    }
}