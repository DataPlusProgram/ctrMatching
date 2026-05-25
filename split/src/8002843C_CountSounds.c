typedef unsigned short u16;

u16 audioAllocPtr;

u16 CountSounds(void) {
    u16 temp_v0;

    temp_v0 = audioAllocPtr + 1;
    audioAllocPtr = temp_v0;
    if (!(temp_v0 & 0xFFFF)) {
        audioAllocPtr = 1;
    }
    return audioAllocPtr;
}