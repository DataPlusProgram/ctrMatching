typedef int s32;

s32 VehCalc_InterpBySpeed(s32 val, s32 step, s32 target)
{
    if (target < val)
    {
        val -= step;
        if (val < target)
        {
            return target;
        }
    }

    if (val < target)
    {
        val += step;
        if (target < val)
        {
            return target;
        }
    }

    return val;
}


