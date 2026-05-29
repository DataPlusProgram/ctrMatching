typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK CdReadCallback();                    /* extern */
s32 ptrHubAlloc;

void LOAD_HowlCallback(s32 arg0) {
    CdReadCallback(0);
    if ((arg0 & 0xFF) == 2) {
        ptrHubAlloc = 0;
        return;
    }
    ptrHubAlloc = -1;
}