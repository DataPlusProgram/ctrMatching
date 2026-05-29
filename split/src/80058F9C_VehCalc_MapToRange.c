typedef int s32;

s32 VehCalc_MapToRange(s32 value, s32 inMin, s32 inMax, s32 outMin, s32 outMax) {
     if (value <= inMin)
        return outMin;

    if (value >= inMax)
        return outMax;

    return outMin + (value - inMin) * (outMax - outMin) / (inMax - inMin);
}