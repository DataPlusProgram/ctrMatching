typedef int s32;
typedef unsigned int u32;

s32 _spu_FsetRXXa();

s32 SpuSetIRQAddr(u32 arg0) {
    if (arg0 > 0x7FFF8U) {
        return 0;
    }

    return _spu_FsetRXXa(0xD2, arg0);
}