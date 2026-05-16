typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008C3B4;

void _spu_setReverbAttr(void *arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0);
    temp_a2 = temp_a1 == 0;
    if ((temp_a2 != 0) || (temp_a1 & 1)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1C0) = (u16) M2C_FIELD(arg0, u16 *, 4);
    }
    if ((temp_a2 != 0) || (temp_a1 & 2)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1C2) = (u16) M2C_FIELD(arg0, u16 *, 6);
    }
    if ((temp_a2 != 0) || (temp_a1 & 4)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1C4) = (u16) M2C_FIELD(arg0, u16 *, 8);
    }
    if ((temp_a2 != 0) || (temp_a1 & 8)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1C6) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1C8) = (u16) M2C_FIELD(arg0, u16 *, 0xC);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1CA) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1CC) = (u16) M2C_FIELD(arg0, u16 *, 0x10);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x80)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1CE) = (u16) M2C_FIELD(arg0, u16 *, 0x12);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x100)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1D0) = (u16) M2C_FIELD(arg0, u16 *, 0x14);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x200)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1D2) = (u16) M2C_FIELD(arg0, u16 *, 0x16);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x400)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1D4) = (u16) M2C_FIELD(arg0, u16 *, 0x18);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x800)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1D6) = (u16) M2C_FIELD(arg0, u16 *, 0x1A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x1000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1D8) = (u16) M2C_FIELD(arg0, u16 *, 0x1C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x2000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1DA) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x4000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1DC) = (u16) M2C_FIELD(arg0, u16 *, 0x20);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x8000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1DE) = (u16) M2C_FIELD(arg0, u16 *, 0x22);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1E0) = (u16) M2C_FIELD(arg0, u16 *, 0x24);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1E2) = (u16) M2C_FIELD(arg0, u16 *, 0x26);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1E4) = (u16) M2C_FIELD(arg0, u16 *, 0x28);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x80000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1E6) = (u16) M2C_FIELD(arg0, u16 *, 0x2A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x100000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1E8) = (u16) M2C_FIELD(arg0, u16 *, 0x2C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x200000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1EA) = (u16) M2C_FIELD(arg0, u16 *, 0x2E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x400000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1EC) = (u16) M2C_FIELD(arg0, u16 *, 0x30);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x800000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1EE) = (u16) M2C_FIELD(arg0, u16 *, 0x32);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x01000000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1F0) = (u16) M2C_FIELD(arg0, u16 *, 0x34);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x02000000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1F2) = (u16) M2C_FIELD(arg0, u16 *, 0x36);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x04000000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1F4) = (u16) M2C_FIELD(arg0, u16 *, 0x38);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x08000000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1F6) = (u16) M2C_FIELD(arg0, u16 *, 0x3A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10000000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1F8) = (u16) M2C_FIELD(arg0, u16 *, 0x3C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20000000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1FA) = (u16) M2C_FIELD(arg0, u16 *, 0x3E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40000000)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1FC) = (u16) M2C_FIELD(arg0, u16 *, 0x40);
    }
    if ((temp_a2 != 0) || (temp_a1 < 0)) {
        M2C_FIELD(D_8008C3B4, u16 *, 0x1FE) = (u16) M2C_FIELD(arg0, u16 *, 0x42);
    }
}