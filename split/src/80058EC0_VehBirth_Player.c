typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

void *PROC_BirthWithObject();
M2C_UNK VehBirth_NonGhost();
M2C_UNK memset();

extern s32 D_8008D2AC;
extern M2C_UNK D_8008D614;
extern M2C_UNK VehPhysProc_Driving_Init;

void VehBirth_Player(s32 arg0) {
    void *procObj;
    void *work;
    void *tempV0;
    s32 tempA0;
    M2C_UNK *tempV1;

    procObj = PROC_BirthWithObject(0x062C0100, 0, &D_8008D614, 0);
    work = *((void **)(((s8 *)procObj) + 0x30));
    tempV0 = work;

    memset(tempV0, 0, 0x62C);
    VehBirth_NonGhost(procObj, arg0);

    tempA0 = D_8008D2AC + arg0;
    tempA0 = *((s8 *)(((s8 *)tempA0) + 0x1DA4));
    tempV1 = &VehPhysProc_Driving_Init;

    *((M2C_UNK **)(((s8 *)tempV0) + 0x54)) = tempV1;
    *((s32 *)(((s8 *)tempV0) + 0x4E8)) = tempA0;
}