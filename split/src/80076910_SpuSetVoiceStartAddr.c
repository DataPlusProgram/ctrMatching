typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK _spu_FsetRXXa(s32 arg0);
M2C_UNK func_80076960(void);

void SpuSetVoiceStartAddr(s32 arg0) {
    volatile s32 stack0;
    volatile s32 stack1;

    _spu_FsetRXXa((arg0 << 3) | 3);

    stack1 = 1;
    stack0 = 0;

    func_80076960();
}