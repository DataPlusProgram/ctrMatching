typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK ThTick_SetAndExec();       /* extern */
void *VehPickupItem_MaskUseWeapon(); /* extern */
extern void BOTS_ThTick_RevEngine();
extern void *NavPath_ptrHeader[];
extern void *NavPath_ptrNavFrameArray[];

void BOTS_MaskGrab(void *arg0) {
    s16 temp_v1_2;
    s16 temp_v1_4;
    s32 temp_a1_2;
    s32 temp_a2_2;
    s32 temp_v0_2;
    s32 temp_v1_3;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 pathZ;
    s32 nextZ;
    s32 deltaZ;
    s32 flags2C8;
    u32 var_a3;
    s32 navIndex;
    void *navFrame;
    void *temp_s0;
    void *temp_v0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x30);
    navIndex = M2C_FIELD(temp_s0, s16 *, 0x5B8);
    navFrame = M2C_FIELD(temp_s0, void **, 0x5A4);
    var_a3 = (u32) navFrame + 0x14;

    if (var_a3 >= (u32) M2C_FIELD(NavPath_ptrHeader[navIndex], u32 *, 8)) {
        var_a3 = (u32) NavPath_ptrNavFrameArray[navIndex];
    }

    M2C_FIELD(temp_s0, s8 *, 0x376) = 5;
    M2C_FIELD(temp_s0, s32 *, 0x5A8) = (s32) (((s16) M2C_FIELD(navFrame, u16 *, 0xC) / 2) << 8);

    temp_v1_2 = M2C_FIELD(navFrame, s16 *, 0);
    temp_v1_3 = (temp_v1_2 + ((s32) (M2C_FIELD(var_a3, s16 *, 0) - temp_v1_2) / 2)) << 8;
    M2C_FIELD(temp_s0, s32 *, 0x5F0) = temp_v1_3;
    M2C_FIELD(temp_s0, s32 *, 0x2E0) = temp_v1_3;

    temp_v1_4 = M2C_FIELD(navFrame, s16 *, 2);
    temp_v1_5 = (temp_v1_4 + ((s32) (M2C_FIELD(var_a3, s16 *, 2) - temp_v1_4) / 2)) << 8;
    M2C_FIELD(temp_s0, s32 *, 0x5F4) = temp_v1_5;
    M2C_FIELD(temp_s0, s32 *, 0x2E4) = temp_v1_5;
    M2C_FIELD(temp_s0, s32 *, 0x2D0) = temp_v1_5;

    pathZ = M2C_FIELD(navFrame, s16 *, 4);
    flags2C8 = M2C_FIELD(temp_s0, s32 *, 0x2C8);
    nextZ = M2C_FIELD(var_a3, s16 *, 4);
    M2C_FIELD(temp_s0, s32 *, 0x5D4) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x5D0) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x5CC) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x5EC) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x5E8) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x5E4) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x2C8) = flags2C8 | 1;
    M2C_FIELD(temp_s0, s32 *, 0x5B0) = (s32) (M2C_FIELD(temp_s0, s32 *, 0x5B0) & -80);

    deltaZ = nextZ - pathZ;
    temp_a1_2 = (pathZ + (deltaZ / 2)) << 8;
    M2C_FIELD(temp_s0, s32 *, 0x5F8) = temp_a1_2;
    M2C_FIELD(temp_s0, s32 *, 0x2E8) = temp_a1_2;

    M2C_FIELD(temp_s0, s16 *, 0x2EC) = (s16) (M2C_FIELD(navFrame, u8 *, 6) * 0x10);
    M2C_FIELD(temp_s0, s16 *, 0x2EE) = (s16) (M2C_FIELD(navFrame, u8 *, 7) * 0x10);
    M2C_FIELD(temp_s0, s16 *, 0x2F0) = (s16) (M2C_FIELD(navFrame, u8 *, 8) * 0x10);
    M2C_FIELD(temp_s0, s32 *, 0x5C8) = 0;

    M2C_FIELD(temp_s0, s16 *, 0x5C0) = 0;
    M2C_FIELD(temp_s0, s16 *, 0x3DC) = 0;
    M2C_FIELD(temp_s0, s16 *, 0x3E2) = 0;
    M2C_FIELD(temp_s0, s16 *, 0xC) = 0;
    M2C_FIELD(temp_s0, s16 *, 0x404) = 0;
    M2C_FIELD(temp_s0, s16 *, 0x3DE) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x4C) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x4D) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x2C8) = (s32) (M2C_FIELD(temp_s0, s32 *, 0x2C8) & 0xFFF7FFBF);

    if (M2C_FIELD(arg0, s16 *, 0x44) != 0x4B) {
        M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) & ~0x1000);
    }

    temp_v0_2 = M2C_FIELD(temp_s0, s32 *, 0x5F0);
    temp_v1_6 = M2C_FIELD(temp_s0, s32 *, 0x5F4);
    temp_a2_2 = M2C_FIELD(temp_s0, s32 *, 0x5F8);
    M2C_FIELD(temp_s0, s32 *, 0x2D4) = temp_v0_2;
    M2C_FIELD(temp_s0, s32 *, 0x2D8) = temp_v1_6;
    M2C_FIELD(temp_s0, s32 *, 0x2DC) = temp_a2_2;
    M2C_FIELD(temp_s0, s32 *, 0x2D8) = M2C_FIELD(temp_s0, s32 *, 0x2D8) + 0x10000;

    temp_v0 = VehPickupItem_MaskUseWeapon(temp_s0, 1, temp_a2_2, (void *) var_a3);
    M2C_FIELD(temp_s0, void **, 0x620) = temp_v0;

    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s16 *, 6) = 0x1E00;
        M2C_FIELD(temp_v0, u16 *, 4) = (u16) (M2C_FIELD(temp_v0, u16 *, 4) | 1);
    }

    ThTick_SetAndExec(arg0, BOTS_ThTick_RevEngine);
}