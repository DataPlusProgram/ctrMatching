typedef int s32;

s32 MEMCARD_GetNextHwEvent();                       /* extern */
s32 MEMCARD_GetNextSwEvent();                       /* extern */

s32 MEMCARD_SkipEvents(void) {
    do {

    } while (MEMCARD_GetNextSwEvent() != 7);
    do {

    } while (MEMCARD_GetNextHwEvent() != 7);
    return 7;
}