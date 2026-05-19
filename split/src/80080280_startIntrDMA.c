typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK InterruptCallback();      /* extern */
M2C_UNK startIntrDMA_Unknown_800804F8(); /* extern */
extern s32 *D_8008CB04;
extern M2C_UNK D_8008CB08;
extern M2C_UNK startIntrDMA_Unknown_800802CC;
extern M2C_UNK startIntrDMA_Unknown_8008044C;

M2C_UNK *startIntrDMA(void) {
    startIntrDMA_Unknown_800804F8(&D_8008CB08, 8);
    *D_8008CB04 = 0;
    InterruptCallback(3, &startIntrDMA_Unknown_800802CC);
    return &startIntrDMA_Unknown_8008044C;
}