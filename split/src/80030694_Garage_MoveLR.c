typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    u8 unk0;
    s8 pad1[3];
    s16 unk4;
    s8 pad6[6];
} GarageSoundPoolEntry;

extern GarageSoundPoolEntry garageSoundPool[];

void Garage_MoveLR(s32 arg0) {
    GarageSoundPoolEntry *var_v1;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 temp_t0;

    var_a3 = arg0 - 1;
    if (arg0 < 8) {
        var_a2 = arg0 + 1;
        if (var_a3 < 0) {
            var_a3 = 7;
        }
        if (var_a2 >= 8) {
            var_a2 = 0;
        }
        var_a1 = 0;
        temp_t0 = 3;
        var_v1 = garageSoundPool;
        do {
            if (var_a1 == arg0) {
                var_v1->unk0 = 0U;
            } else if (var_a1 == var_a3) {
                if (var_v1->unk0 == temp_t0) {
                    var_v1->unk4 = 0x3C;
                }
                var_v1->unk0 = 1U;
            } else if (var_a1 == var_a2) {
                if (var_v1->unk0 == temp_t0) {
                    var_v1->unk4 = 0xC3;
                }
                var_v1->unk0 = 2U;
            } else {
                var_v1->unk0 = temp_t0;
            }
            var_a1 += 1;
            var_v1 += 1;
        } while (var_a1 < 8);
    }
}