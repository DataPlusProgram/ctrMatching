typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    u8 unk0;
    u8 unk1;
    char pad2[0x1];
    u8 unk3;
    char pad4[0x4];
    u8 unk8;
    char pad9[0xF];
    void *unk18;
} M2cCseqOpcode0aArg0;

s16 howl_InstrumentPitch(); /* extern */

extern M2C_UNK ChannelUpdateFlags;
extern s32 boolNeedXASeek;
extern M2C_UNK channelAttrNew;
extern void *channelTaken;
extern s32 distortConst_OtherFX[];
extern s32 howl_metaOtherFX;

void cseq_opcode0a(M2cCseqOpcode0aArg0 *arg0) {
    void *varS0;
    s8 *attrBase;
    s32 *updateBase;
    s32 *distortBase;

    arg0->unk8 = M2C_FIELD(arg0->unk18, u8 *, 1);

    varS0 = channelTaken;
    if (varS0 != NULL) {
        attrBase = (s8 *)&channelAttrNew;
        distortBase = distortConst_OtherFX;
        updateBase = (s32 *)&ChannelUpdateFlags;

        do {
            if ((M2C_FIELD(varS0, u8 *, 0xB) == 2) && (M2C_FIELD(varS0, s32 *, 0x18) == arg0->unk1)) {
                if (arg0->unk0 & 4) {
                    void *meta;
                    u8 pitch;

                    meta = (void *)(howl_metaOtherFX + (M2C_FIELD(varS0, u8 *, 0xD) * 8));
                    pitch = arg0->unk8;

                    if (pitch != 0x80) {
                        M2C_FIELD(attrBase + (M2C_FIELD(varS0, u8 *, 9) * 0x10), s16 *, 8) =
                            (s16)((u32)(M2C_FIELD(meta, u16 *, 2) * distortBase[pitch]) >> 0x10);
                    } else {
                        M2C_FIELD(attrBase + (M2C_FIELD(varS0, u8 *, 9) * 0x10), u16 *, 8) =
                            M2C_FIELD(meta, u16 *, 2);
                    }
                } else {
                    M2C_FIELD(attrBase + (M2C_FIELD(varS0, u8 *, 9) * 0x10), s16 *, 8) =
                        howl_InstrumentPitch(
                            M2C_FIELD(boolNeedXASeek + (arg0->unk3 * 0xC), u16 *, 4),
                            M2C_FIELD(varS0, u8 *, 0xD),
                            arg0->unk8
                        );
                }

                updateBase[M2C_FIELD(varS0, u8 *, 9)] |= 0x10;
            }

            varS0 = M2C_FIELD(varS0, void **, 0);
        } while (varS0 != NULL);
    }
}