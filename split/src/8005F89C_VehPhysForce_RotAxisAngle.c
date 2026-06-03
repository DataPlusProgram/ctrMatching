#include "../../common.h"

extern s32 D_800845A0[];

typedef struct RotMatrix3x3 {
    s16 m[3][3];
} RotMatrix3x3;

void VehPhysForce_RotAxisAngle(RotMatrix3x3 *matrix, s16 *axisAngleNormalVec, s16 angle)
{
    SVec3 *axisVector;
    SVec3 localVector;
    s32 axisX;
    s32 axisY;
    s32 axisZ;
    u32 axisXRaw;
    u32 axisYRaw;
    u32 axisZRaw;
    s32 tableValue;
    s32 sineValue;
    s32 cosineValue;
    s32 axisXSquared;
    s32 axisZSquared;
    s32 axisXTimesNegAxisZ;
    s32 axisXZLengthSquared;
    s32 localXBase;
    s32 localZBase;
    s32 localY;
    s32 localOutX;
    s32 localOutZ;
    s32 leadingZeroCount;
    u32 normalizationShift;
    s32 crossX;
    s32 crossY;
    s32 crossZ;

    axisVector = (SVec3 *)axisAngleNormalVec;

    axisXRaw = (u16)axisVector->x;
    matrix->m[0][1] = axisXRaw;
    axisX = (s16)axisXRaw;

    axisYRaw = (u16)axisVector->y;
    matrix->m[1][1] = axisYRaw;
    axisY = (s16)axisYRaw;

    axisZRaw = (u16)axisVector->z;
    matrix->m[2][1] = axisZRaw;
    axisZ = (s16)axisZRaw;

    //tableValue = D_800845A0[angle & 0x3FF];
	   tableValue = D_800845A0[(angle + axisX - axisX + axisY - axisY + axisZ - axisZ) & 0x3FF];//?


    if ((angle & 0x400) != 0) {
        cosineValue = (s16)tableValue;
        sineValue = tableValue >> 16;

        if ((angle & 0x800) == 0) {
            cosineValue = -cosineValue;
        }
    } else {
        sineValue = (s16)tableValue;
        cosineValue = tableValue >> 16;

        if ((angle & 0x800) != 0) {
            sineValue = -sineValue;
            cosineValue = -cosineValue;
        }
    }

    axisXSquared = axisX * axisX;
    axisZSquared = axisZ * axisZ;
    axisXTimesNegAxisZ = axisX * -axisZ;
    axisXZLengthSquared = axisXSquared + axisZSquared;

    localXBase = (sineValue * axisY) >> 12;
    localZBase = (cosineValue * axisY) >> 12;

    gte_ldlzc(axisXZLengthSquared);
    gte_nop();
    gte_nop();

    __asm__ volatile ("mfc2\t%0, $31" : "=r"(leadingZeroCount));

    if (axisXZLengthSquared == 0) {
        localY = (-(sineValue * axisX + cosineValue * axisZ)) >> 12;
        if (axisVector->y < 0) {
            localXBase = -localXBase;
        }

        localOutX = localXBase;
        localOutZ = localZBase;
    } else {
        normalizationShift = 0x14 - leadingZeroCount;

        if ((s32)normalizationShift > 0) {
            axisXSquared >>= (normalizationShift & 0x1F);
            axisZSquared >>= (normalizationShift & 0x1F);
            axisXTimesNegAxisZ >>= (normalizationShift & 0x1F);
            axisXZLengthSquared >>= (normalizationShift & 0x1F);
        }

        localOutX = localXBase + (
            ((sineValue - localXBase) * axisZSquared + (cosineValue - localZBase) * axisXTimesNegAxisZ) /
            axisXZLengthSquared
        );
        localOutZ = localZBase + (
            ((sineValue - localXBase) * axisXTimesNegAxisZ + (cosineValue - localZBase) * axisXSquared) /
            axisXZLengthSquared
        );
        localY = (-(cosineValue * axisZ + sineValue * axisX)) >> 12;
    }

    localVector.x = localOutX;
    matrix->m[0][2] = localOutX;
    localVector.y = localY;
    matrix->m[1][2] = localY;
    localVector.z = localOutZ;
    matrix->m[2][2] = localOutZ;

    gte_ldopv1SV(axisVector);
    gte_ldopv2SV(&localVector);

    ND_GTE_OP12();
    read_mt(crossX, crossY, crossZ);

    matrix->m[0][0] = crossX;
    matrix->m[1][0] = crossY;
    matrix->m[2][0] = crossZ;
}
