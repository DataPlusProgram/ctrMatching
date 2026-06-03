typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	s32 unk0;
	char pad4[0xE];
	u8 unk12;
} M2cMainInitDriversArg0;

M2C_UNK BOTS_Adv_AdjustDifficulty();                /* extern */
M2C_UNK BOTS_Driver_Init();                      /* extern */
M2C_UNK EngineAudio_InitOnce();     /* extern */
M2C_UNK GhostReplay_Init1();                        /* extern */
M2C_UNK GhostReplay_Init2();                        /* extern */
M2C_UNK GhostTape_Start();                          /* extern */
s32 LOAD_IsOpen_RacingOrBattle();                   /* extern */
s32 VehBirth_Player();                           /* extern */
M2C_UNK func_800ABFEC();                            /* extern */
void *s_OTMem;

void MainInit_Drivers(M2cMainInitDriversArg0 *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s1_2;
    u8 temp_a0;
    u8 var_s0_4;
    u8 var_s0_5;
    void *var_s1;
    void *var_s1_3;
    void *var_v0;

    var_s0 = 7;
    var_v0 = arg0 + 0x1C;
    do {
        M2C_FIELD(var_v0, s32 *, 0x24EC) = 0;
        var_s0 -= 1;
        var_v0 -= 4;
    } while (var_s0 >= 0);
    M2C_FIELD(s_OTMem, u8 *, 0x1CAB) = 0U;
    if (!(arg0->unk0 & 0x20102000)) {
        BOTS_Adv_AdjustDifficulty();
    }
    GhostReplay_Init1();
    if (LOAD_IsOpen_RacingOrBattle() != 0) {
        func_800ABFEC();
    }
    var_s0_2 = arg0->unk12 - 1;
    if (var_s0_2 >= 0) {
        var_s1 = (var_s0_2 * 4) + arg0;
        do {
            temp_v0 = VehBirth_Player(var_s0_2);
            if (temp_v0 != 0) {
                M2C_FIELD(var_s1, s32 *, 0x24EC) = temp_v0;
            }
            var_s0_2 -= 1;
            var_s1 -= 4;
        } while (var_s0_2 >= 0);
    }
    if (!(arg0->unk0 & 0x2C122020) && (M2C_FIELD(s_OTMem, u8 *, 0x1CA8) != 3)) {
        temp_v1 = M2C_FIELD(s_OTMem, s32 *, 0);
        if (temp_v1 & 0x480000) {
            if (temp_v1 < 0) {
                BOTS_Driver_Init(1);
            } else if ((temp_v1 & 0x10000000) && (var_s0_3 = 1, (M2C_FIELD(s_OTMem, s32 *, 0x1E58) == 4))) {
loop_18:
                BOTS_Driver_Init(var_s0_3);
                var_s0_3 += 1;
                if (var_s0_3 < 5) {
                    goto loop_18;
                }
            } else {
                temp_a0 = arg0->unk12;
                if (temp_a0 != 1) {
                    var_s1_2 = 4;
                    if (temp_a0 == 2) {
                        var_s1_2 = 6;
                    }
                } else {
                    var_s1_2 = 8;
                }
                var_s0_4 = temp_a0;
                if ((s32) var_s0_4 < var_s1_2) {
                    do {
                        BOTS_Driver_Init((s32) var_s0_4);
                        var_s0_4 += 1;
                    } while ((s32) var_s0_4 < var_s1_2);
                }
            }
        }
    }
    if (M2C_FIELD(s_OTMem, u8 *, 0x1CAB) != 0) {
        EngineAudio_InitOnce(0x10, 0x8080);
        EngineAudio_InitOnce(0x11, 0x8080);
    }
    if (arg0->unk0 & 0x2000) {
        var_s0_5 = M2C_FIELD(s_OTMem, u8 *, 0x1CA8);
        if ((s32) var_s0_5 < 4) {
            var_s1_3 = (var_s0_5 * 4) + arg0;
            do {
                temp_v0_2 = VehBirth_Player((s32) var_s0_5);
                if (temp_v0_2 != 0) {
                    M2C_FIELD(var_s1_3, s32 *, 0x24EC) = temp_v0_2;
                }
                var_s0_5 += 1;
                var_s1_3 += 4;
            } while ((s32) var_s0_5 < 4);
        }
    }
    if ((M2C_FIELD(s_OTMem, s32 *, 0) & 0x20022000) == 0x20000) {
        GhostReplay_Init2();
        GhostTape_Start();
    }
}