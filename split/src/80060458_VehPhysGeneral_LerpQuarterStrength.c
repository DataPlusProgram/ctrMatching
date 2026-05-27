typedef int s32;

s32 VehPhysGeneral_LerpQuarterStrength(s32 value, s32 strength)
{
    s32 lerpValue;
    s32 isBelowStrength;

    lerpValue = value;
    if (strength != 0) {
        strength = strength >> 2;
        isBelowStrength = lerpValue < strength;
        if (strength == 0) {
            strength = 1;
            goto checkStrength;
        }
    } else {
checkStrength:
        isBelowStrength = lerpValue < strength;
    }

    if (isBelowStrength == 0) {
        lerpValue = strength;
    }

    return lerpValue;
}
