typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    char pad3[0x1];
    u8 unk4;
    u8 unk5;
    char pad6[0x2];
    u8 unk8;
    u8 unk9;
} M2cCseqOpcode05NoteonArg0;

void *Channel_AllocSlot();        /* extern */
M2C_UNK howl_InitChannelAttr_Music(); /* extern */
extern u8 D_8008D7CC;
extern M2C_UNK songPool;

void cseq_opcode05_noteon(M2cCseqOpcode05NoteonArg0 *arg0) {
    M2C_UNK sp10;
    void *temp_s1;
    void *temp_v0;

    if ((D_8008D7CC != 0) && (arg0->unk5 != 0) &&
        (M2C_FIELD(((s8 *)&songPool + (M2C_FIELD(arg0, u8 *, 0xB) * 0x7C)), u8 *, 0x18) != 0)) {
        temp_s1 = M2C_FIELD(arg0, void **, 0x18);
        howl_InitChannelAttr_Music(&sp10, M2C_FIELD(temp_s1, u8 *, 1), M2C_FIELD(temp_s1, u8 *, 2));
        temp_v0 = Channel_AllocSlot(0x7C, &sp10);
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, u8 *, 8) = (u8) (M2C_FIELD(temp_v0, u8 *, 8) | 0xE);
            M2C_FIELD(temp_v0, s8 *, 0xB) = 2;
            M2C_FIELD(temp_v0, s8 *, 0xC) = 0;
            M2C_FIELD(temp_v0, u8 *, 0xA) = (u8) arg0->unk2;
            M2C_FIELD(temp_v0, u8 *, 0xE) = (u8) arg0->unk4;
            M2C_FIELD(temp_v0, u8 *, 0xF) = (u8) M2C_FIELD(temp_s1, u8 *, 2);
            M2C_FIELD(temp_v0, u8 *, 0x10) = (u8) arg0->unk8;
            M2C_FIELD(temp_v0, u8 *, 0x11) = (u8) arg0->unk9;
            M2C_FIELD(temp_v0, s16 *, 0x16) = 0;
            M2C_FIELD(temp_v0, u8 *, 0xD) = (u8) M2C_FIELD(temp_s1, u8 *, 1);
            M2C_FIELD(temp_v0, s32 *, 0x18) = (s32) arg0->unk1;
            M2C_FIELD(arg0, u8 *, 0xA) = M2C_FIELD(arg0, u8 *, 0xA) + 1;
        }
    }
}
