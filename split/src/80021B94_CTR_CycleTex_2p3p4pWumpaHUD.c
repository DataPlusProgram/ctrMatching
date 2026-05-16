typedef signed char s8;
typedef int s32;

void CTR_CycleTex_2p3p4pWumpaHUD(s32 *arg0, s32 *arg1, s32 arg2) {
    *arg1 = *arg0;
    *arg0 = (s32) (((s8 *) arg1 + (arg2 * 4)) - 4) & 0xFFFFFF;
}