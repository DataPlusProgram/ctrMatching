typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK BOTS_GotoStartingLine();              /* extern */
M2C_UNK LIST_AddFront();         /* extern */
void *PROC_BirthWithObject(); /* extern */
M2C_UNK VehBirth_NonGhost();             /* extern */
M2C_UNK memset();           /* extern */
extern M2C_UNK BOTS_ThTick_Drive;
extern M2C_UNK D_8008CF78;
extern M2C_UNK NavPath_ptrHeader;
extern M2C_UNK NavPath_ptrNavFrameArray;
extern void *gT;
extern M2C_UNK navBotList;
extern M2C_UNK s_robotcar;

void *BOTS_Driver_Init(s32 arg0) {
    s16 var_v0;
    s32 temp_a2_2;
    s32 var_a1;
    s32 var_v1;
    s8 temp_a2;
    s8 temp_v0;
    s8 var_s1;
    void *temp_v0_2;
    void *var_s2;

    var_s2 = NULL;
    var_s1 = (s8) *(arg0 + &D_8008CF78);
    var_a1 = 0;
    var_v0 = M2C_FIELD(*(((s32) (var_s1 << 0x10) >> 0xE) + &NavPath_ptrHeader), s16 *, 2);
    temp_a2 = var_s1;
loop_5:
    temp_v0 = var_s1 - 1;
    if (var_v0 >= 2) {
        var_a1 = 1;
    } else {
        var_s1 = temp_v0;
        var_v1 = var_s1 << 0x10;
        if (temp_v0 & 0x8000) {
            var_s1 = 2;
            var_v1 = 2 << 0x10;
        }
        if (var_v1 != (temp_a2 << 0x10)) {
            var_v0 = M2C_FIELD(*(((var_v1 >> 0x10) * 4) + &NavPath_ptrHeader), s16 *, 2);
            goto loop_5;
        }
    }
    if (var_a1 != 0) {
        temp_v0_2 = PROC_BirthWithObject(0x062C0101, &BOTS_ThTick_Drive, &s_robotcar, 0);
        var_s2 = M2C_FIELD(temp_v0_2, void **, 0x30);
        memset(var_s2, 0, 0x62C);
        VehBirth_NonGhost(temp_v0_2, arg0);
        temp_a2_2 = arg0 * 4;
        M2C_FIELD((gT + temp_a2_2), void **, 0x24EC) = (void *) M2C_FIELD(temp_v0_2, void **, 0x30);
        M2C_FIELD(temp_v0_2, s16 *, 0x44) = 0x3F;
        M2C_FIELD(var_s2, s16 *, 0x5B8) = (s16) var_s1;
        M2C_FIELD(var_s2, s32 *, 0x2C8) = (s32) (M2C_FIELD(var_s2, s32 *, 0x2C8) | 0x100000);
        M2C_FIELD(var_s2, s32 *, 0x5A4) = (s32) *(((s16) var_s1 * 4) + &NavPath_ptrNavFrameArray);
        LIST_AddFront(((s16) var_s1 * 0xC) + &navBotList, var_s2 + 0x598, temp_a2_2);
        M2C_FIELD(gT, u8 *, 0x1CAB) = (u8) (M2C_FIELD(gT, u8 *, 0x1CAB) + 1);
        BOTS_GotoStartingLine(var_s2);
    }
    return var_s2;
}