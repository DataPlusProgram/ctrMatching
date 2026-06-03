#include "../../common.h"

extern s32 D_800845A0[];

void VehPhysForce_CounterSteer(Driver *driver)
{
    s32 speedAbs;
    s32 steerDelta;
    s32 maxCounterSteer;
    s32 tableWord;
    s32 counterSteerSin;
    s32 counterSteerForce;

    s32 counterSteerRatio;
	s32 counterSteerInput;
	s32 counterSteerOutput;

    speedAbs = abs(driver->speedApprox);

    driver->accel.x = 0;
    driver->accel.y = 0;
    driver->accel.z = 0;

    if (speedAbs < 0x301) {
        return;
    }

    if (driver->kartState == 1) {
        return;
    }

    if (driver->actionsFlagSet & 0x4000) {
        return;
    }

    if (driver->set0xF0OnWallRub != 0) {
        return;
    }

    if ((driver->actionsFlagSet & 1) == 0) {
        return;
    }

    counterSteerRatio = driver->terrainMeta1->counterSteerRatio;
    if (counterSteerRatio == 0) {
        return;
    }

    counterSteerForce = -0x1F40;
    counterSteerForce = (counterSteerRatio * counterSteerForce) >> 8;

    steerDelta = driver->turnAngleCurr - driver->turnAnglePrev;
    maxCounterSteer = (u8)driver->angleMaxCounterSteer;

    if (maxCounterSteer < steerDelta) {
        steerDelta = maxCounterSteer;
    }

    if (steerDelta < -maxCounterSteer) {
        steerDelta = -maxCounterSteer;
    }

    tableWord = D_800845A0[steerDelta & 0x3FF];

    if ((steerDelta & 0x400) == 0) {
        tableWord <<= 0x10;
    }

    counterSteerSin = tableWord >> 0x10;

    if (steerDelta & 0x800) {
        counterSteerSin = -counterSteerSin;
    }

    counterSteerForce = (counterSteerForce * counterSteerSin) >> 12;
	counterSteerInput = (u16)counterSteerForce;

	gte_ldVXY0(counterSteerInput);
	gte_ldVZ0(0);
	gte_rtv0();

	__asm__ volatile ("mfc2 %0, $25" : "=r"(counterSteerOutput) : : "memory");
	__asm__ volatile ("nop");
	driver->accel.x = counterSteerOutput;

	__asm__ volatile ("mfc2 %0, $26" : "=r"(counterSteerOutput) : : "memory");
	__asm__ volatile ("nop");
	driver->accel.y = counterSteerOutput;

	__asm__ volatile ("mfc2 %0, $27" : "=r"(counterSteerOutput) : : "memory");
	__asm__ volatile ("nop");
	driver->accel.z = counterSteerOutput;
}
