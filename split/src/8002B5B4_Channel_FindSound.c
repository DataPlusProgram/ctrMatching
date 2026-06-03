typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Channel {
    struct Channel *next;
    u8 pad4[7];
    u8 active;
    u8 padC[0xC];
    u16 soundId;
} Channel;

extern Channel *channelTaken[];

s32 Channel_FindSound(u16 soundId) {
    Channel *channel;
    Channel *nextChannel;

    channel = channelTaken[0];
    if (channel != 0) {
        do {
            nextChannel = channel->next;
            if ((channel->active == 1) && (channel->soundId == soundId)) {
                return 1;
            }
            channel = nextChannel;
        } while (channel != 0);
    }

    return 0;
}
