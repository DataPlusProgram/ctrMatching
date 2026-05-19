typedef signed char s8;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

typedef struct {
    s8 bytes[4];
} UnalignedS32;

typedef struct {
    UnalignedS32 unk0;
    UnalignedS32 unk4;
} M2cFLAREInitArg0;

void *PROC_BirthWithObject();
extern M2C_UNK D_80011074;
extern M2C_UNK FLARE_ThTick;

void FLARE_Init(M2cFLAREInitArg0 *arg0) {
    void *tempV0;
    void *tempV0_2;

    tempV0 = PROC_BirthWithObject(0xC030D, &FLARE_ThTick, &D_80011074, 0);
    if (tempV0 != NULL) {
        tempV0_2 = *(void **)((s8 *)tempV0 + 0x30);
        *(s32 *)((s8 *)tempV0_2 + 0) = 0;
        *(UnalignedS32 *)((s8 *)tempV0_2 + 4) = arg0->unk0;
        *(UnalignedS32 *)((s8 *)tempV0_2 + 8) = arg0->unk4;
    }
}