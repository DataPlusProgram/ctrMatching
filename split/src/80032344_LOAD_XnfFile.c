typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

typedef struct {
    char name[8];
    s32 size;
    s32 pos;
} CdlFILE;

M2C_UNK CDSYS_SetMode_StreamData(); /* extern */
M2C_UNK CdControl();                /* extern */
s32 CdRead();                       /* extern */
s32 CdReadSync();                   /* extern */
s32 CdSearchFile();                 /* extern */
M2C_UNK LOAD_StringToUpper();       /* extern */
s32 MEMPACK_AllocMem();             /* extern */
M2C_UNK MEMPACK_ReallocMem();       /* extern */

s32 LOAD_XnfFile(s32 arg0, s32 arg1, s32 *arg2) {
    CdlFILE file;
    CdlFILE file2;
    s32 originalMem;
    s32 size;
    s32 numSectors;

    originalMem = arg1;

    LOAD_StringToUpper();
    CDSYS_SetMode_StreamData();

    if (CdSearchFile(&file, arg0) == 0) {
        return arg1;
    }

    size = file.size;
    *arg2 = size;

    if (arg1 == 0) {
        numSectors = (size + 0x7FFU) >> 0xB;
        arg1 = MEMPACK_AllocMem(numSectors << 0xB, arg0);

        if (arg1 == 0) {
            return 0;
        }
    }

    CdControl(2, &file, &file2);

    numSectors = (file.size + 0x7FFU) >> 0xB;
    if (CdRead(numSectors, arg1, 0x80) == 0) {
        return 0;
    }

    if (CdReadSync(0, 0) != 0) {
        return 0;
    }

    if (originalMem == 0) {
        MEMPACK_ReallocMem(file.size);
    }

    return arg1;
}