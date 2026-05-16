
typedef int s32;
s32 EngineSound_VolumeAdjust(s32 arg0, s32 arg1, s32 arg2)
{
  int new_var;
  s32 temp_v1;
  s32 var_v0;
  temp_v1 = arg0 - arg1;
  new_var = temp_v1 < 0;
  var_v0 = temp_v1;
  if (new_var)
  {
    var_v0 = -var_v0;
    var_v0 = var_v0;
  }
  if (arg2 < var_v0)
  {
    if (temp_v1 > 0)
    {
      return arg1 + arg2;
    }
    return (var_v0 = arg1) - arg2;
  }
  return arg0;
}
