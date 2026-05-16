#include "common.h"

typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int uint;

typedef struct VECTOR VECTOR;

struct VECTOR {
    s32 vx;
    s32 vy;
    s32 vz;
};

extern void *PTR_DAT_8008d2ac;

extern void FUN_800264c0(s32 param_1, s32 param_2, s32 param_3);
extern void FUN_80026440(s32 param_1, s32 param_2, s32 param_3);
extern s32 FUN_80058f54(s32 param_1, s32 param_2, s32 param_3);

void FUN_8005e214(s32 param_1, VECTOR *param_2)
{
    char cVar1;
    undefined2 uVar2;
    s32 iVar3;
    uint uVar4;
    s32 iVar5;
    s32 iVar6;
    uint uVar7;
    uint uVar8;
    uint uVar9;
    uint uVar10;
    uint uVar11;
    uint uVar12;
    s32 iVar13;
    uint unaff_s3;
    uint unaff_s5;
    undefined1 *puVar14;
    s32 unaff_s8;
    s32 iVar15;
    s32 iVar16;
    undefined1 auStack_48[16];

    puVar14 = auStack_48;

    uVar8 = *(uint *)(param_1 + 0x310);
    uVar7 = *(uint *)(param_1 + 0x314);
    uVar10 = *(uint *)(param_1 + 0x318);
    uVar9 = *(uint *)(param_1 + 0x31c);

    gte_ldR11R12(uVar8);
    gte_ldR13R21(uVar7);
    gte_ldR22R23(uVar10);
    gte_ldR31R32(uVar9);
    gte_ldR33((s32)*(s16 *)(param_1 + 800));

    gte_ldL11L12((uVar8 & 0xffff) | (uVar7 & 0xffff0000));
    uVar8 = uVar8 & 0xffff0000;
    gte_ldL13L21((uVar9 & 0xffff) | uVar8);
    gte_ldL22L23((uVar10 & 0xffff) | (uVar9 & 0xffff0000));
    uVar7 = (uVar7 & 0xffff) | (uVar10 & 0xffff0000);
    gte_ldL31L32(uVar7);
    gte_ldL33((s32)*(s16 *)(param_1 + 800));

    gte_ldVXY0(((uint)(u16)param_2->vx) | (param_2->vy << 0x10));
    gte_ldVZ0(param_2->vz);
    gte_llv0();
    read_mt(unaff_s5, unaff_s8, unaff_s3);

    iVar3 = -(s32)*(s16 *)(param_1 + 0x416);
    iVar5 = *(s32 *)((s8 *)PTR_DAT_8008d2ac + 0x1d04);
    iVar6 = iVar5;

    if ((*(u16 *)(*(s32 *)(param_1 + 0x350) + 0x12) & 2) != 0) {
        iVar6 = *(s16 *)(param_1 + 0x416) * -0x29;
        iVar3 = iVar6 >> 0x1f;
        iVar6 = iVar6 / 100 + iVar3;
        iVar3 = iVar6 - iVar3;
    }

    gte_ldVXY0((iVar3 * iVar5 >> 5) << 0x10);
    gte_ldVZ0(0);
    gte_llv0();
    read_mt(uVar7, uVar8, iVar6);

    if (((iVar6 < 0) && (0 < *(s16 *)(param_1 + 0x3b2))) ||
        ((0 < iVar6) && (*(s16 *)(param_1 + 0x3b2) < 0))) {
        iVar6 = 0;
    }

    uVar10 = *(uint *)(param_1 + 0x2c8);
    iVar3 = (s32)*(s16 *)(param_1 + 0x38e);
    uVar9 = (uint)*(s16 *)(param_1 + 0x39c);

    if ((((uVar10 & 8) != 0) || ((0 < (s32)uVar9) && (iVar3 < 0))) ||
        (((s32)uVar9 < 0) && (0 < iVar3))) {
        uVar7 = 0;
        iVar6 = 0;
    }

    iVar15 = unaff_s8 + uVar8;
    uVar11 = (s32)*(s16 *)(param_1 + 0x39e) + (s32)*(s16 *)(param_1 + 0x47e);
    uVar8 = unaff_s3 + iVar6;

    if (((s32)uVar11 < (s32)(unaff_s3 + iVar6)) &&
        (uVar8 = unaff_s3, (s32)unaff_s3 < (s32)uVar11)) {
        uVar8 = uVar11;
    }

    uVar11 = (s32)*(s16 *)(param_1 + 0x39e) - ((s32)*(s16 *)(param_1 + 0x47e) >> 1);

    if (((s32)uVar8 < (s32)uVar11) &&
        (uVar8 = unaff_s3, (s32)uVar11 < (s32)unaff_s3)) {
        uVar8 = uVar11;
    }

    uVar12 = (uint)*(s16 *)(param_1 + 0x480);
    uVar4 = *(uint *)(*(s32 *)(param_1 + 0x358) + 4);
    uVar11 = unaff_s5 + uVar7;

    if (((s32)(unaff_s5 + uVar7) <= (s32)uVar12) ||
        (uVar11 = uVar12, uVar7 = unaff_s5, (s32)unaff_s5 < (s32)uVar12)) {
        uVar7 = uVar11;
    }

    uVar12 = -uVar12;

    if (((s32)uVar7 < (s32)uVar12) &&
        (uVar7 = unaff_s5, (s32)uVar12 < (s32)unaff_s5)) {
        uVar7 = uVar12;
    }

    iVar6 = (s32)*(s16 *)(param_1 + 0x442);

    if (((iVar15 < 0) && ((uVar4 & 0x80) != 0)) &&
        (iVar6 = 0x100, unaff_s8 < -0x100)) {
        unaff_s8 = -0x100;
    }

    if ((iVar15 <= iVar6) ||
        (iVar15 = iVar6, iVar16 = unaff_s8, unaff_s8 < iVar6)) {
        iVar16 = iVar15;
    }

    iVar6 = -iVar6;

    if ((iVar16 < iVar6) &&
        (iVar16 = unaff_s8, iVar6 < unaff_s8)) {
        iVar16 = iVar6;
    }

    cVar1 = *(char *)(param_1 + 0x376);

    if (cVar1 == '\x05') {
        uVar7 = 0;
        uVar8 = 0;
    } else if ((((*(uint *)(param_1 + 0x2cc) & 1) != 0) || (cVar1 == '\x06')) ||
               ((*(s16 *)(param_1 + 0x3c4) < *(s16 *)(param_1 + 0x38e)) &&
                (*(s32 *)(*(s32 *)(param_1 + 0x35c) + 8) < 0x100))) {
        if ((uVar10 & 8) == 0) {
            if (uVar9 == 0) {
                iVar15 = (s32)*(s16 *)(param_1 + 0x41e);
                iVar6 = (s32)*(s16 *)(param_1 + 0x420);

                if (*(s16 *)(param_1 + 0x50a) == 5) {
                    iVar15 = (s32)*(s16 *)(param_1 + 0x422) << 4;
                    iVar6 = iVar15;
                }
            } else {
                iVar6 = iVar3;

                if (iVar3 < 0) {
                    iVar6 = -iVar3;
                }

                if ((iVar6 < 0x301) ||
                    ((((s32)uVar9 < 1 || (-1 < iVar3)) &&
                     ((-1 < (s32)uVar9 || (iVar3 < 1)))))) {
                    if (cVar1 == '\x02') {
                        iVar15 = (s32)*(s16 *)(param_1 + 0x424);
                        iVar6 = (s32)*(s16 *)(param_1 + 0x426);
                    } else {
                        if (iVar3 < 0) {
                            iVar3 = -iVar3;
                        }

                        iVar15 = (s32)*(s16 *)(param_1 + 0x41a);
                        iVar6 = (s32)*(s16 *)(param_1 + 0x41c);

                        if (0x300 < iVar3) {
                            uVar11 = uVar9;

                            if ((s32)uVar9 < 0) {
                                uVar11 = -uVar9;
                            }

                            if (iVar3 < (s32)uVar11 >> 1) {
                                uVar10 = uVar10 | 0x800;
                            }
                        }
                    }
                } else {
                    if (iVar3 < 0) {
                        iVar3 = -iVar3;
                    }

                    iVar15 = (s32)*(s16 *)(param_1 + 0x41a);
                    iVar6 = (s32)*(s16 *)(param_1 + 0x422);

                    if (0x300 < iVar3) {
                        uVar10 = uVar10 | 0x800;
                    }
                }
            }
        } else {
            if (iVar3 < 0) {
                iVar3 = -iVar3;
            }

            if (0x300 < iVar3) {
                uVar10 = uVar10 | 0x800;
            }

            iVar3 = (uint)*(u16 *)(param_1 + 0x422) << 0x10;
            iVar15 = iVar3 >> 0x10;

            if (*(s16 *)(param_1 + 0x50a) == 5) {
                iVar15 = iVar15 << 4;
                iVar6 = iVar15;
            } else if (cVar1 == '\x06') {
                iVar15 = iVar15 * 3 >> 2;
                iVar6 = iVar15;
            } else {
                iVar6 = iVar15;

                if (cVar1 == '\x03') {
                    iVar15 = iVar3 >> 0x11;
                    iVar6 = iVar15;
                }
            }
        }

        iVar13 = *(s32 *)(*(s32 *)(param_1 + 0x358) + 0x20);
        iVar3 = iVar15 * iVar5 >> 5;
        iVar6 = iVar6 * iVar5 >> 5;

        if (iVar13 != 0x100) {
            iVar3 = iVar13 * iVar3 >> 8;
            iVar6 = iVar13 * iVar6 >> 8;
        }

        iVar15 = (s32)*(s16 *)(param_1 + 0x414);

        if (iVar15 < 0) {
            uVar11 = uVar7;

            if (iVar15 == -0x140) {
                if ((s32)uVar7 < 0) {
                    uVar11 = -uVar7;
                }

                iVar3 = (s32)uVar11 >> 1;
            } else {
                iVar3 = iVar3 + (iVar3 * *(s16 *)(param_1 + 0x444) >> 8);

                if (iVar3 < 0) {
                    iVar3 = 0;
                }

                if ((s32)uVar7 < 0) {
                    uVar11 = -uVar7;
                }
            }

            if (0 < (s32)uVar11) {
                uVar10 = uVar10 | 0x1800;
                FUN_800264c0(param_1, 4, 0x7f);
                FUN_80026440(param_1, 4, 0);
            }

            iVar15 = iVar15 + iVar5;

            if (0 < iVar15) {
                iVar15 = 0;
            }

            *(s16 *)(param_1 + 0x414) = (s16)iVar15;
        } else if (0 < iVar15) {
            iVar15 = iVar15 - iVar5;

            if (iVar15 < 0) {
                iVar15 = 0;
            }

            iVar3 = iVar3 + (iVar3 * *(s16 *)(param_1 + 0x444) >> 8);
            *(s16 *)(param_1 + 0x414) = (s16)iVar15;

            if (iVar3 < 0) {
                iVar3 = 0;
            }
        }

        if (((uVar10 & 0x800000) == 0) &&
            (iVar5 = (s32)uVar7 >> 3, (uVar4 & 0x80) != 0)) {
            if (iVar5 < 0) {
                iVar5 = -iVar5;
            }

            if (iVar3 < iVar5) {
                iVar3 = iVar5;
            }

            if (((uVar8 == 0) || (uVar9 == 0)) || (-1 < (s32)(uVar8 ^ uVar9))) {
                if ((((s32)uVar9 <= (s32)uVar8) || (0 < (s32)uVar8)) &&
                    (((s32)uVar8 <= (s32)uVar9 || ((s32)uVar8 < 0)))) {
                    goto LAB_8005e8d8;
                }

                iVar5 = uVar8 - uVar9;

                if (iVar5 < 0) {
                    iVar5 = -iVar5;
                }

                iVar5 = iVar5 >> 1;
            } else {
                iVar5 = (s32)uVar8 >> 1;

                if (iVar5 < 0) {
                    iVar5 = -iVar5;
                }
            }

            if (iVar6 < iVar5) {
                iVar6 = iVar5;
            }
        }

LAB_8005e8d8:
        if (((uVar4 & 0x100) == 0) ||
            (iVar5 = iVar3 * 3 >> 2, iVar3 = iVar6, iVar5 < iVar6)) {
            iVar5 = iVar3;
        }

        uVar7 = FUN_80058f54(uVar7, iVar5, 0);
        uVar8 = FUN_80058f54(uVar8, iVar6, 0);
    }

    gte_ldVXY0((uVar7 & 0xffff) | (iVar16 << 0x10));
    gte_ldVZ0(uVar8);
    gte_rtv0();
    gte_stlvnl(param_2);

    *(uint *)(param_1 + 0x2c8) = uVar10;

    if ((uVar10 & 0x80000) == 0) {
        if ((*(char *)(param_1 + 0x449) != '\0') && (uVar8 != 0)) {
            uVar2 = 1;

            if ((s32)uVar8 < 0) {
                uVar2 = 0xffff;
            }

            *(undefined2 *)(param_1 + 1000) = uVar2;
            *(undefined1 *)(param_1 + 0x449) = 0;
            goto LAB_8005e9d8;
        }

        if (*(s32 *)(puVar14 + 0x10) < 0) {
LAB_8005e9cc:
            if (-1 < (s32)uVar8) {
                *(undefined2 *)(param_1 + 1000) = 1;
            }

            goto LAB_8005e9d8;
        }

        if ((s32)uVar8 < 0) {
            *(undefined2 *)(param_1 + 1000) = 0xffff;
        }

        if (*(s32 *)(puVar14 + 0x10) < 1) {
            goto LAB_8005e9cc;
        }

LAB_8005e9e8:
        if ((s32)uVar8 < 0) {
            goto LAB_8005ea08;
        }

        if (0 < *(s32 *)(puVar14 + 0x10)) {
            return;
        }
    } else {
LAB_8005e9d8:
        if (-1 < *(s32 *)(puVar14 + 0x10)) {
            goto LAB_8005e9e8;
        }
    }

    if ((s32)uVar8 < 1) {
        return;
    }

LAB_8005ea08:
    if (*(s16 *)(param_1 + 0x408) != 0) {
        *(s16 *)(param_1 + 0x40a) = *(s16 *)(param_1 + 0x40a) + 1;
    }

    *(undefined2 *)(param_1 + 0x408) = 0x280;
}