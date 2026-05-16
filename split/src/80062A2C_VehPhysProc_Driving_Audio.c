typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK EngineSound_Player(); /* extern */

void VehPhysProc_Driving_Audio(M2C_UNK arg0, M2C_UNK arg1) {
    EngineSound_Player(arg1);
}