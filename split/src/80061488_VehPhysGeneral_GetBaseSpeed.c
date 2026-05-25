#include "../../common.h"

s32 func_80061488(struct Driver *driver)
{
  struct Driver *d;
  s32 boost;
  s32 turboConst;
  s32 boostStep;
  s32 speedStat;
  s32 slow;

  d = driver;
  boost = d->numWumpas;
  if (boost >= 10)
  {
    boost = 9;
  }

  turboConst = d->turboConst;
  if (turboConst >= 6)
  {
    turboConst = 5;
  }

  boostStep = (((d->constAccelSpeedClassStat - d->constSpeedClassStat) << 12) / 5) - 1;

  boost = (boost * boostStep) / 10;
  boost = (boost + (turboConst * boostStep)) >> 12; // divided by 4096

  speedStat = d->constSpeedClassStat;

  if (d->actionsFlagSet & 0x800000)
  {
    boost += d->constMaskSpeed;
  }

  if (d->reserves != 0)
  {
    s32 reserveCap;

    reserveCap = d->constSingleTurboSpeed;
    speedStat += d->fireSpeedCap;
    reserveCap += (d->constSacredFireSpeed - reserveCap) * 2;
    reserveCap -= d->fireSpeedCap;

    if (reserveCap < 0)
    {
      reserveCap = 0;
    }

    if (reserveCap < boost)
    {
      boost = reserveCap;
    }
  }

  speedStat += boost;
  slow = 0;

  if (d->instTntRecv != 0)
  {
    slow = (((u16) d->constDamagedSpeed) << 16) >> 17;
  }

  if (((d->burnTimer != 0) || (d->squishTimer != 0)) || (d->driverRankItemValue == 0))
  {
    slow = d->constDamagedSpeed;
  }

  if (d->clockReceive != 0)
  {
    s32 clockSlow;

    clockSlow = (d->constDamagedSpeed * (0x14 - d->driverRank)) >> 4;
    if (slow < clockSlow)
    {
      slow = clockSlow;
    }
  }

  speedStat -= slow;

  if (speedStat >= 25601)
  {
    speedStat = 25600;
  }

  return speedStat;
}