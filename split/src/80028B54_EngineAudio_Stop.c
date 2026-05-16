#include "../../common.h"

M2C_UNK Channel_SearchFX_Destroy();
M2C_UNK Smart_EnterCriticalSection();              
M2C_UNK Smart_ExitCriticalSection();               
extern u8 D_8008D05C;
extern void *D_8008D7C0;

void EngineAudio_Stop(s32 arg0) {
    u32 temp_s0;

    if (D_8008D05C != 0) {
        temp_s0 = arg0 & 0xFFFF;
        if (temp_s0 < (u32) M2C_FIELD(D_8008D7C0, u32 *, 0x18)) {
            Smart_EnterCriticalSection();
            Channel_SearchFX_Destroy(0, temp_s0, -1);
            Smart_ExitCriticalSection();
        }
    }
}