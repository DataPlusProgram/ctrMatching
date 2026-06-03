typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

#define NULL 0

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void INSTANCE_Birth();
void *JitPool_Add();
extern void *gT; 

void *INSTANCE_Birth2D(s32 arg0, M2C_UNK arg1, M2C_UNK arg2)
{
    void *temp_v0;
    void *tempGT;
    void *var_a0;
    void *var_a1;
    s32 var_v1;
    s32 playerCount;

    temp_v0 = JitPool_Add(gT + 0x18F8);

    if (temp_v0 != NULL) {
        INSTANCE_Birth(temp_v0, arg0, arg1, arg2, 0x40F);
    }

    tempGT = gT;
    M2C_FIELD(temp_v0, void **, 0x74) = tempGT + 0x1388;

    playerCount = M2C_FIELD(tempGT, u8 *, 0x1CA8);
    var_v1 = 1;

    if (var_v1 < playerCount) {
        var_a1 = tempGT;
        var_a0 = temp_v0 + 0x88;

        do {
            M2C_FIELD(var_a0, s32 *, 0x74) = 0;
            playerCount = M2C_FIELD(var_a1, u8 *, 0x1CA8);
            var_a0 += 0x88;
        } while (++var_v1 < playerCount);
    }

    return temp_v0;
}