typedef int s32;

void AddPrim(s32 *arg0, s32 *arg1) {
    register s32 mask00FFFFFF asm("a2");
    register s32 maskFF000000 asm("a3");

    mask00FFFFFF = 0xFFFFFF;
    maskFF000000 = 0xFF000000;

    *arg1 = (*arg1 & maskFF000000) | (*arg0 & mask00FFFFFF);
    *arg0 = (*arg0 & maskFF000000) | ((s32) arg1 & mask00FFFFFF);
}