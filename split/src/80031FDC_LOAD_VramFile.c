typedef short s16;
typedef int s32;

#define NULL 0

typedef struct VramLoadInfo {
    s32 fileId;
    s16 unk4;
    s16 unk6;
    s32 vramDest;
    s32 result;
    s32 size;
    s32 unk14;
} VramLoadInfo;

s32 LOAD_ReadFile();
void LOAD_VramFileCallback();
void MEMPACK_PopState();
void MEMPACK_PushState();
void VSync();

extern s32 D_80083A48;
s32 boolFirstBoot;

s32 LOAD_VramFile(s32 fileId, s32 vramDest, s32 *outFile, s32 *outSize, s32 mode)
{
    VramLoadInfo loadInfo;
    s32 result;

    if (outFile == NULL) {
        MEMPACK_PushState();
    }

    if (mode == -1) {
        loadInfo.fileId = fileId;
        loadInfo.unk4 = 0;
        loadInfo.unk6 = 3;
        loadInfo.vramDest = vramDest;

        result = LOAD_ReadFile(fileId, 3, vramDest, outFile, outSize, NULL);

        loadInfo.result = result;
        loadInfo.size = *outSize;
        loadInfo.unk14 = 0;

        LOAD_VramFileCallback(&loadInfo);
        VSync(2);

        boolFirstBoot = 0;

        if (outFile == NULL) {
            MEMPACK_PopState();
        }

        return loadInfo.result;
    }

    if (mode == -2) {
        result = LOAD_ReadFile(fileId, 3, vramDest, NULL, outSize, LOAD_VramFileCallback);
        D_80083A48 = result;
        *outFile = result;
        return result;
    }

    return LOAD_ReadFile(fileId, 3, vramDest, outFile, outSize, LOAD_VramFileCallback);
}