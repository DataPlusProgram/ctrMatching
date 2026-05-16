typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

typedef struct UnalignedS32 {
    s32 value;
} __attribute__((packed)) UnalignedS32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))
#define M2C_UNALIGNED32_LOAD(expr) (((UnalignedS32 *)(expr))->value)
#define M2C_UNALIGNED32_STORE(expr, val) (((UnalignedS32 *)(expr))->value = (val))

s32 howl_ModeGet();
s32 howl_VolumeGet();

extern s32 *D_8008D2AC;
extern s8 D_8008E6E8[];
extern s8 D_800841FC[];
extern s8 D_8008FB82[];

void RaceConfig_SaveGameOptions(void) {
    s16 temp_v0;
    s16 var_s1;
    s32 temp_s0;
    s32 var_s0;
    s8 *temp_s0_2;
    s8 *temp_s2;
    register s8 *fb82Base asm("s0");
    register s8 *src asm("a3");
    register s8 *dst asm("a2");
    register s32 copy0 asm("v1");
    register s32 copy1 asm("a1");

    var_s1 = 0;
    temp_s2 = D_8008E6E8;

    do {
        var_s0 = var_s1 << 0x10;
        temp_s0 = var_s0 >> 0x10;

        M2C_FIELD(temp_s2 + (temp_s0 * 2), s16 *, 0x1494) = howl_VolumeGet(temp_s0) & 0xFF;

        temp_v0 = var_s1 + 1;
        var_s1 = temp_v0;
    } while (temp_v0 < 3);

    fb82Base = D_8008FB82;
    dst = fb82Base;
    src = D_800841FC;

    copy0 = M2C_UNALIGNED32_LOAD(src + 0x00);
    copy1 = M2C_UNALIGNED32_LOAD(src + 0x04);
    M2C_UNALIGNED32_STORE(dst + 0x00, copy0);
    M2C_UNALIGNED32_STORE(dst + 0x04, copy1);

    copy0 = M2C_UNALIGNED32_LOAD(src + 0x08);
    copy1 = M2C_UNALIGNED32_LOAD(src + 0x0C);
    M2C_UNALIGNED32_STORE(dst + 0x08, copy0);
    M2C_UNALIGNED32_STORE(dst + 0x0C, copy1);

    copy0 = M2C_UNALIGNED32_LOAD(src + 0x10);
    copy1 = M2C_UNALIGNED32_LOAD(src + 0x14);
    M2C_UNALIGNED32_STORE(dst + 0x10, copy0);
    M2C_UNALIGNED32_STORE(dst + 0x14, copy1);

    temp_s0_2 = fb82Base - 0x149A;
    M2C_FIELD(temp_s0_2, s32 *, 0x14B4) = *D_8008D2AC & 0xF00;
    M2C_FIELD(temp_s0_2, s16 *, 0x14B8) = (howl_ModeGet() & 0xFF) != 0;
}