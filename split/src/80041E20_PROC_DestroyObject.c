typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK LIST_AddFront(); /* extern */
extern s32 D_8008D2AC;

void PROC_DestroyObject(s32 arg0, s32 arg1) {
    register s32 tempV0 asm("v0");
    s32 tempV1;

    if (arg0 != 0) {
        tempV0 = arg1;
        tempV1 = tempV0 & 0x300;
        arg1 = arg0 - 8;

        if (tempV1 == 0x100) {
            goto case100;
        }

        if (tempV1 == 0x200) {
            goto case200;
        }

        goto caseDefault;

case100:
        arg0 = D_8008D2AC;
        arg0 += 0x1970;
        goto call;

case200:
        arg0 = D_8008D2AC;
        arg0 += 0x1948;
        goto call;

caseDefault:
        arg0 = D_8008D2AC;
        arg0 += 0x1920;

call:
        LIST_AddFront(arg0, arg1);
    }
}