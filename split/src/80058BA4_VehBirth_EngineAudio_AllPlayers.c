typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} M2cEngineAudioTableEntry;

M2C_UNK EngineAudio_InitOnce();         /* extern */
extern M2cEngineAudioTableEntry D_80086D84[];
extern s16 D_80086E84[];
extern void *gGamepads;

void VehBirth_EngineAudio_AllPlayers(void) {
    u8 temp_v1;
    void *var_s0;

    var_s0 = M2C_FIELD(gGamepads, void **, 0x1B2C);
    if (var_s0 != NULL) {
        do {
            temp_v1 = M2C_FIELD(M2C_FIELD(var_s0, void **, 0x30), u8 *, 0x4A);
            EngineAudio_InitOnce(((D_80086D84[D_80086E84[temp_v1]].unkC * 4) + temp_v1) & 0xFFFF, 0x8080);
            var_s0 = M2C_FIELD(var_s0, void **, 0x10);
        } while (var_s0 != NULL);
    }
}