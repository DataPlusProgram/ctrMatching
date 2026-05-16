typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))
#define GET_PLAYER(ptr, index) M2C_FIELD((s8 *)(ptr) + ((index) * 4), void **, 0x24EC)

extern void DecalFont_DrawLine(s32, s16, s16, s16, s32);
extern void MainGameEnd_Initialize(s32, void *);
extern s32 RECTMENU_DrawTime(s32);
extern void *D_8008D2AC;

void UI_DrawLimitClock(s16 arg0, s16 arg1, s16 arg2) {
    s32 temp_s0;
    s32 var_s1;
    s32 var_v0;
    s32 var_v1;
    s32 var_a0;
    void *gameTracker;
    void *temp_v1;

    temp_s0 = M2C_FIELD(D_8008D2AC, s32 *, 0x1D84) - M2C_FIELD(D_8008D2AC, s32 *, 0x1D10);

    if (temp_s0 < 0) {
        var_s1 = RECTMENU_DrawTime(0);
        gameTracker = D_8008D2AC;
        var_v0 = temp_s0 < 0x3840;

        if (!(M2C_FIELD(gameTracker, s32 *, 0) & 0x200000)) {
            var_a0 = 0;

            if (M2C_FIELD(gameTracker, u8 *, 0x1CA8) != 0) {
                do {
                    temp_v1 = GET_PLAYER(gameTracker, var_a0);
                    M2C_FIELD(temp_v1, s32 *, 0x2C8) = M2C_FIELD(temp_v1, s32 *, 0x2C8) | 0x02000000;
                    var_a0 += 1;
                } while (var_a0 < M2C_FIELD(gameTracker, u8 *, 0x1CA8));
            }

            MainGameEnd_Initialize(var_a0, gameTracker);
            var_v0 = temp_s0 < 0x3840;
        }
    } else {
        var_s1 = RECTMENU_DrawTime(temp_s0);
        var_v0 = temp_s0 < 0x3840;
    }

    var_v1 = 0x1C;
    if (var_v0 != 0) {
        var_v1 = 4;
        if (M2C_FIELD(D_8008D2AC, s32 *, 0x1CEC) & 1) {
            var_v1 = 0x1C;
        }
    }

    DecalFont_DrawLine(var_s1, arg0, arg1, arg2, var_v1);
}