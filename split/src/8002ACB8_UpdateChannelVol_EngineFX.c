typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

typedef struct {
	char pad0[0x1];
	u8 unk1;
} M2cUpdateChannelVolEngineFXArg0;

M2C_UNK Channel_SetVolume();   /* extern */
u8 ptrHowlHeader;

void UpdateChannelVol_EngineFX(M2cUpdateChannelVolEngineFXArg0 *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    Channel_SetVolume(arg1, (u32) (ptrHowlHeader * arg0->unk1 * arg2) >> 0xA, arg3);
}