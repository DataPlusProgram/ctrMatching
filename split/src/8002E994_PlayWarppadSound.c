typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK CalculateVolumeFromDistance(); /* extern */
extern M2C_UNK D_800962D0;

void PlayWarppadSound(s32 arg0) {
    CalculateVolumeFromDistance(&D_800962D0, 0x98, arg0);
}