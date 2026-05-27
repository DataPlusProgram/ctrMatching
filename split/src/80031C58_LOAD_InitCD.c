typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK CDSYS_Init();

void LOAD_InitCD(void) {
    CDSYS_Init(1);
}