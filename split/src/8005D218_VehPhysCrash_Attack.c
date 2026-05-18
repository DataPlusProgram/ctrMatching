typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
typedef char undefined;
typedef short undefined2;
typedef int undefined4;

extern short D_80086E84[];
int D_8008D9F4 = 0;

extern void OtherFX_DriverCrashing(uint p1, int p2);
extern void Voiceline_RequestPlay(int p1, int p2, int p3);
extern void OtherFX_Play(int p1, int p2);

int VehPhysCrash_Attack(int param_1, int param_2, int param_3, int param_4)
{
    int iVar1;

    if ((*(uint *)(param_1 + 0x2C8) & 0x800000) == 0) {
        if ((*(uint *)(param_2 + 0x2C8) & 0x800000) != 0) {
            *(undefined *)(param_1 + 0x4FF) = 2;
            *(undefined *)(param_1 + 0x504) = 6;
            *(int *)(param_1 + 0x500) = param_2;

            if (((param_3 != 0) && (*(char *)(param_1 + 0x376) != '\x06')) && (*(int *)(param_1 + 0x24) == 0)) {
                OtherFX_DriverCrashing((uint)*(ushort *)(param_1 + 0x2CA) & 1, 0xFF);
                Voiceline_RequestPlay(1, (int)(short)D_80086E84[*(byte *)(param_1 + 0x4A)], 0x10);
            }
        }

        if ((*(int *)(param_2 + 0x14) != 0) && (*(int *)(param_1 + 0x14) == 0)) {
            iVar1 = *(int *)(*(int *)(*(int *)(param_2 + 0x14) + 0x6C) + 0x30);
            *(ushort *)(iVar1 + 6) = *(ushort *)(iVar1 + 6) | 8;
            *(undefined4 *)(param_2 + 0x14) = 0;
            *(undefined *)(param_1 + 0x4FF) = 2;
            *(undefined *)(param_1 + 0x504) = 0;
            *(int *)(param_1 + 0x500) = param_2;

            if ((param_3 != 0) && ((*(char *)(param_1 + 0x376) != '\x06' && (*(int *)(param_1 + 0x24) == 0)))) {
                OtherFX_DriverCrashing((uint)*(ushort *)(param_1 + 0x2CA) & 1, 0xFF);

                if (param_4 != 0) {
                    OtherFX_Play(0x4F, 1);
                }

                Voiceline_RequestPlay(1, (int)(short)D_80086E84[*(byte *)(param_1 + 0x4A)], 0x10);
            }
        }

        if ((((0xA00 < D_8008D9F4) && (*(short *)(param_2 + 0x3E2) != 0)) &&
             ((*(uint *)(param_2 + 0x2C8) & 0x200) != 0)) &&
            (*(short *)(param_1 + 0x3E2) == 0)) {
            *(undefined *)(param_2 + 0x366) = 2;
            *(undefined *)(param_1 + 0x4FF) = 3;
            *(undefined *)(param_1 + 0x504) = 5;
            *(int *)(param_1 + 0x500) = param_2;
        }
    }

    return param_3;
}