typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK OtherFX_Play_LowLevel();

void OtherFX_Play(s32 arg0, s32 arg1) {
    OtherFX_Play_LowLevel(arg0 & 0xFFFF, arg1 & 0xFF, 0xFF8080);
}