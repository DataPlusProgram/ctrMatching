typedef int s32;

s32 VehCalc_MapToRange(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

s32 VehCalc_SteerAccel(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    s32 temp;
    s32 result;

    if (arg0 < arg1) {
        result = VehCalc_MapToRange(arg0, 0, arg1, arg4, arg5);
        return result;
    }

    temp = arg1 + arg2;

    if (temp >= arg0) {
        return arg5;
    }

    return VehCalc_MapToRange(arg0, temp, arg3, arg5, 0);
}