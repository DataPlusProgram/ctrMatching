typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK UpdateChannelVol_Music(); /* extern */

extern s32 D_8008FC6C[];
extern u8 D_8008FCCC[];
extern u8 D_800902CC[];
extern void *D_8009056C;

void UpdateChannelVol_Music_All(void) {
    s32 *tempV1;
    void *varS0;
    s32 *baseS3;
    u8 *baseS2;
    u8 *baseS1;
    s32 tempV0;
    s32 tempV1Byte;

    varS0 = D_8009056C;
    if (varS0 != NULL) {
        baseS3 = D_8008FC6C;
        baseS2 = D_8008FCCC;
        baseS1 = D_800902CC;

        do {
            tempV1Byte = M2C_FIELD(varS0, u8 *, 0xB);
            tempV0 = 2;

            if (tempV1Byte == tempV0) {
                tempV1 = (s32 *)((s8 *)baseS3 + (M2C_FIELD(varS0, u8 *, 9) << tempV0));
                *tempV1 |= 0x40;

                UpdateChannelVol_Music(
                    baseS1 + (M2C_FIELD(varS0, s32 *, 0x18) * 0x1C),
                    baseS2 + (M2C_FIELD(varS0, u8 *, 9) << 4),
                    M2C_FIELD(varS0, u8 *, 0xD),
                    M2C_FIELD(varS0, u8 *, 0xF)
                );
            }

            varS0 = M2C_FIELD(varS0, void **, 0);
        } while (varS0 != NULL);
    }
}