typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK _SpuSetAnyVoice(); /* extern */

void SpuSetReverbVoice(s32 arg0, s32 arg1) {
    _SpuSetAnyVoice(arg0, arg1, 0xCC, 0xCD);
}