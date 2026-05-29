typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK SpuSetReverb();                      
M2C_UNK SpuSetReverbModeDepth();            
M2C_UNK SpuSetReverbModeParam();             
u16 bankLoadStage;
extern M2C_UNK distortConst_Engine;

void SetReverbMode(u16 arg0) {
    u32 temp_s1;
    void *temp_s0;

    temp_s1 = arg0 & 0xFFFF;
    if (temp_s1 >= 5U) {
        if (bankLoadStage != 5) {
            SpuSetReverbModeDepth(0, 0);
            SpuSetReverb(0);
            bankLoadStage = 5;
        }
    } else if (bankLoadStage != temp_s1) {
        SpuSetReverbModeDepth(0, 0);
        SpuSetReverb(1);
        temp_s0 = (void *) ((s8 *) &distortConst_Engine + (temp_s1 * 0x14));
        SpuSetReverbModeParam(temp_s0);
        SpuSetReverbModeDepth(M2C_FIELD(temp_s0, s16 *, 8), M2C_FIELD(temp_s0, s16 *, 0xA));
        bankLoadStage = arg0;
    }
}