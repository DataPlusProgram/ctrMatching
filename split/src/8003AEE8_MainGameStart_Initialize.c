typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK Music_Stop();                         /* extern */
M2C_UNK VehBirth_TeleportAll();               /* extern */
M2C_UNK howl_StopAudio();                     /* extern */
s32 *s_OTMem;

void MainGameStart_Initialize(void *arg0, s32 arg1) {
    s32 var_v0;

    if (*s_OTMem & 0x20002000) {
        M2C_FIELD(arg0, s32 *, 0x1D0C) = 0;
        var_v0 = M2C_FIELD(arg0, s32 *, 0) & ~0x40;
    } else {
        M2C_FIELD(arg0, s32 *, 0x1D0C) = 0xF00;
        var_v0 = M2C_FIELD(arg0, s32 *, 0) | 0x40;
        M2C_FIELD(arg0, s32 *, 0) = var_v0;
    }

    M2C_FIELD(arg0, s32 *, 0) = var_v0 & 0xFFDFFFFF;

    if (arg1 == 0) {
        Music_Stop();
        howl_StopAudio(0, 0, 1);
    }

    VehBirth_TeleportAll(arg0, 2);
}