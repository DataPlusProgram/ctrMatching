#include "../../common.h"

extern int ratan2(int, int);

void VehPhysCrash_ConvertVecToSpeed(Driver *driver, Vec3 *vec)
{
    int extraoutVar00;
    int extraoutVar01;
    int x;
    int projX;
    int projY;
    int projZ;
    int projOnMovingDirAxis;

    projOnMovingDirAxis = VehCalc_FastSqrt((vec->x * vec->x) + (vec->z * vec->z), 16);
    
	x = projOnMovingDirAxis;
    driver->speed = (u32)VehCalc_FastSqrt(((vec->x * vec->x) + (vec->y * vec->y)) + (vec->z * vec->z), 0x10) >> 8;
    
	x = ratan2(vec->y << 8, x);
    driver->axisRotationY = x;
   
	x = ratan2(vec->x, vec->z);
    driver->axisRotationX = x;
    
	projOnMovingDirAxis = (((vec->x * driver->matrixMovingDir.m[0][1]) + (vec->y * driver->matrixMovingDir.m[1][1])) + (vec->z * driver->matrixMovingDir.m[2][1])) >> 0xC;
    
	projX = (driver->matrixMovingDir.m[0][1] * projOnMovingDirAxis) >> 0xC;
    projY = (driver->matrixMovingDir.m[1][1] * projOnMovingDirAxis) >> 0xC;
    projZ = (driver->matrixMovingDir.m[2][1] * projOnMovingDirAxis) >> 0xC;
    
	extraoutVar00 = (u32)VehCalc_FastSqrt(((projX * projX) + (projY * projY)) + (projZ * projZ), 0x10) >> 8;
    
	driver->jumpHeightCurr = extraoutVar00;
    
	if (projOnMovingDirAxis < 0)
    {
        driver->jumpHeightCurr = -extraoutVar00;
    }
	
    projX = vec->x - projX;
    projY = vec->y - projY;
    projZ = vec->z - projZ;
    
	extraoutVar01 = (u32)VehCalc_FastSqrt(((projX * projX) + (projY * projY)) + (projZ * projZ), 0x10) >> 8;
    
	driver->speedApprox = extraoutVar01;
	
    if ((((projX * driver->matrixMovingDir.m[0][2]) + (projY * driver->matrixMovingDir.m[1][2])) + (projZ * driver->matrixMovingDir.m[2][2])) < 0)
    {
        driver->speedApprox = -extraoutVar01;
    }
}
