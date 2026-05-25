typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s32 strlen();   /* extern */
s32 strncmp();  /* extern */

extern M2C_UNK metaDataLEV;

s32 MainInit_StringToLevID(s32 arg0) {
    void *varS0;
    s32 varS1;
    s32 varV0;

    varS1 = 0;
    varS0 = (void *)((s8 *)&metaDataLEV + varS1);

loop:
    varV0 = varS1;

    if (strncmp(M2C_FIELD(varS0, s32 *, 4), arg0, strlen(M2C_FIELD(varS0, s32 *, 4))) != 0) {
        varS1 += 1;
        if (varS1 >= 0x41) {
            return 0;
        }

        varS0 = (void *)((s8 *)varS0 + 0x18);
        goto loop;
    }

    return varV0;
}