typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK ThTick_SetAndExec();       /* extern */
M2C_UNK VehEmitter_DriverMain();      /* extern */
M2C_UNK VehFrameProc_Driving();       /* extern */
M2C_UNK VehPhysForce_TranslateMatrix(); /* extern */
extern M2C_UNK BOTS_ThTick_Drive;
extern void *D_8008D2AC;

void BOTS_ThTick_RevEngine(void *arg0) {
    s32 temp_v1;
    void *temp_a0;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x30);
    temp_v1 = M2C_FIELD(temp_s0, s32 *, 0x2D8);
    temp_a0 = M2C_FIELD(temp_s0, void **, 0x620);
    if (M2C_FIELD(temp_s0, s32 *, 0x5F4) >= temp_v1) {
        if (temp_a0 != NULL) {
            M2C_FIELD(temp_a0, s16 *, 0x12) = 0x1000;
            M2C_FIELD(temp_a0, s16 *, 6) = 0;
            M2C_FIELD(temp_a0, u16 *, 4) = (u16) (M2C_FIELD(temp_a0, u16 *, 4) & 0xFFFE);
        }
        M2C_FIELD(temp_s0, void **, 0x620) = NULL;
        M2C_FIELD(temp_s0, s8 *, 0x376) = 4;
        M2C_FIELD(temp_s0, s16 *, 0xC) = 0;
        M2C_FIELD(temp_s0, s16 *, 0x404) = 0;
        ThTick_SetAndExec(arg0, &BOTS_ThTick_Drive);
        return;
    }
    M2C_FIELD(temp_s0, s32 *, 0x2D8) = (s32) (temp_v1 - ((s32) (M2C_FIELD(D_8008D2AC, s32 *, 0x1D04) << 9) >> 5));
    if (temp_a0 != NULL) {
        M2C_FIELD(temp_a0, s16 *, 0xC) = (s16) ((s32) M2C_FIELD(temp_s0, s32 *, 0x2D4) >> 8);
        M2C_FIELD(temp_a0, s16 *, 0xE) = (s16) ((s32) M2C_FIELD(temp_s0, s32 *, 0x2D8) >> 8);
        M2C_FIELD(temp_a0, s16 *, 0x10) = (s16) ((s32) M2C_FIELD(temp_s0, s32 *, 0x2DC) >> 8);
    }
    VehPhysForce_TranslateMatrix(arg0, temp_s0);
    VehFrameProc_Driving(arg0, temp_s0);
    VehEmitter_DriverMain(arg0, temp_s0);
}