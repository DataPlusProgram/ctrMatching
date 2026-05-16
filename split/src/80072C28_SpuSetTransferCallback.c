typedef int s32;

extern s32 D_8008C3EC;

void SpuSetTransferCallback(s32 arg0) {
    if (arg0 != D_8008C3EC) {
        D_8008C3EC = arg0;
    }
}