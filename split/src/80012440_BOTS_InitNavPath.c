typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern M2C_UNK NavPath_ptrHeader;
extern M2C_UNK NavPath_ptrNavFrameArray;
extern M2C_UNK blank_NavHeader;
extern void *gGamepads;
M2C_UNK kartSpawnOrderArray;
M2C_UNK unk_paddingAfterKartSpawn;

void BOTS_InitNavPath(s32 unused, s32 arg1)
{
    s32 index;
    void *navPtr;
    void **headerPtr;
    void **framePtr;
    void *header;
    u16 frameIndex;
    s32 frameOffset;
    void *spawnPtr;

    index = arg1;

    navPtr = M2C_FIELD(M2C_FIELD(gGamepads, void **, 0x160), void **, 0x188);
    if (navPtr != NULL)
    {
        navPtr = M2C_FIELD(navPtr, void **, index * 4);
    }
    else
    {
        navPtr = NULL;
    }

    if (navPtr != NULL)
    {
        headerPtr = (void **)((s8 *)&NavPath_ptrHeader + (index * 4));
        framePtr = (void **)((s8 *)&NavPath_ptrNavFrameArray + (index * 4));

        *headerPtr = navPtr;
        *framePtr = (s8 *)navPtr + 0x4C;

        header = *headerPtr;
        if (M2C_FIELD(header, u16 *, 0) != 0xECFD)
        {
            M2C_FIELD(header, s16 *, 2) = 0;
        }
    }
    else
    {
        headerPtr = (void **)((s8 *)&NavPath_ptrHeader + (index * 4));
        framePtr = (void **)((s8 *)&NavPath_ptrNavFrameArray + (index * 4));

        *headerPtr = &blank_NavHeader;
        *framePtr = (s8 *)&blank_NavHeader + 0x4C;

        M2C_FIELD(*headerPtr, s16 *, 2) = 0;
    }

    headerPtr = (void **)((s8 *)&NavPath_ptrHeader + (index * 4));
    framePtr = (void **)((s8 *)&NavPath_ptrNavFrameArray + (index * 4));

    header = *headerPtr;
    frameIndex = M2C_FIELD(header, u16 *, 2);
    frameOffset = (s16)frameIndex;
    frameOffset = (frameOffset * 5) * 4;

    spawnPtr = (s8 *)*framePtr + frameOffset;
    M2C_FIELD(header, s32 *, 8) = (s32)spawnPtr;

    M2C_FIELD(&unk_paddingAfterKartSpawn, u16 *, 4) = frameIndex;
    M2C_FIELD(&kartSpawnOrderArray, s32 *, 4) = (s32)spawnPtr;
    M2C_FIELD(&kartSpawnOrderArray, s32 *, 0) = (s32)*framePtr;
}
