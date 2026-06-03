#include "../../common.h"

void *Channel_AllocSlot_AntiSpam(u16 soundId, u8 count, s32 flags, void *channelAttr);
s32 Channel_FindSound(u16 soundId);
u16 CountSounds(void);
void Smart_EnterCriticalSection(void);
void Smart_ExitCriticalSection(void);
void howl_InitChannelAttr_OtherFX(void *otherFxMeta, void *channelAttr, u8 leftVolume, u8 rightVolume, u8 pitch);

extern u8 boolAudioEnabled;
extern u8 *howl_metaOtherFX;
extern u8 *howl_spuAddrs;
extern void *ptrHowlHeader;

s32 OtherFX_Play_LowLevel(s32 soundId, s32 count, u32 flags)
{
    u8 channelAttr[0xC];
    void *channel;
    u8 *otherFxMeta;
    u16 soundId16;
    u8 leftVolume;
    u8 rightVolume;
    u8 pitch;
    u8 extraFlag;

    if (boolAudioEnabled == 0) {
        return 0;
    }

    soundId16 = soundId & 0xFFFF;
    if (soundId16 >= M2C_FIELD(ptrHowlHeader, u32 *, 0x14)) {
        return 0;
    }

    otherFxMeta = howl_metaOtherFX + (soundId16 << 3);
    if (M2C_FIELD(howl_spuAddrs, u16 *, M2C_FIELD(otherFxMeta, u16 *, 4) << 2) == 0) {
        return 0;
    }

    leftVolume = (flags >> 0x10) & 0xFF;
    rightVolume = flags & 0xFF;
    pitch = (flags >> 8) & 0xFF;
    extraFlag = flags >> 0x18;

    howl_InitChannelAttr_OtherFX(otherFxMeta, channelAttr, leftVolume, rightVolume, pitch);
    M2C_FIELD(channelAttr, s16 *, 0xA) = extraFlag;

    Smart_EnterCriticalSection();

    if (((count & 0xFF) == 2) && (Channel_FindSound(soundId16) != 0)) {
        Smart_ExitCriticalSection();
        return 0;
    }

    channel = Channel_AllocSlot_AntiSpam(soundId16, count & 0xFF, 0x7C, channelAttr);
    if (channel != NULL) {
        if (M2C_FIELD(otherFxMeta, u8 *, 0) & 2) {
            M2C_FIELD(channel, u8 *, 8) |= 4;
        }

        M2C_FIELD(channel, u8 *, 0xB) = 1;
        M2C_FIELD(channel, u8 *, 0xC) = 0;
        M2C_FIELD(channel, s8 *, 0xE) = extraFlag;
        M2C_FIELD(channel, s8 *, 0xF) = leftVolume;
        M2C_FIELD(channel, s8 *, 0x10) = pitch;
        M2C_FIELD(channel, s8 *, 0x11) = rightVolume;
        M2C_FIELD(channel, u16 *, 0x16) = M2C_FIELD(otherFxMeta, u16 *, 6);
        M2C_FIELD(channel, s32 *, 0x18) = (CountSounds() << 0x10) | soundId16;
        M2C_FIELD(channel, s32 *, 0x1C) = M2C_FIELD(gT, s32 *, 0x1CF8);
    }

    Smart_ExitCriticalSection();
    return M2C_FIELD(channel, s32 *, 0x18);
}
