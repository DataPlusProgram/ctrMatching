#include "../../common.h"

typedef struct DriverSpawnPoint {
  s16 pos[3];
  s16 rot[3];
} DriverSpawnPoint;

typedef struct LevelSpawnView {
  u8 pad0[0x6C];
  DriverSpawnPoint driverSpawn[8];
} LevelSpawnView;


s16 SquareRoot0_stub();
s32 ratan2();
extern GameTracker *D_8008D2AC;

void BOTS_SetRotation(Driver *driver, s32 arg1)
{
  s16 temp_v0;
  s16 temp_posX;
  s16 temp_posY;
  s16 temp_posZ;
  s16 temp_xRead;
  s16 temp_yRead;
  s16 temp_zRead;
  s32 temp_lo;
  s32 temp_lo_2;
  s32 temp_s0;
  s32 temp_s5;
  s32 temp_s7;
  NavFrame *temp_s6;

  temp_posX = (s16) (driver->posCurr.x >> 8);
  temp_posY = (s16) (driver->posCurr.y >> 8);
  temp_s6 = driver->botData.botNavFrame;
  driver->botData.aiVelAxis[2] = 0;
  driver->botData.aiVelAxis[1] = 0;
  driver->botData.estimatePos[0] = temp_posX;
  temp_posZ = (s16) (driver->posCurr.z >> 8);
  driver->botData.estimatePos[1] = temp_posY;
  driver->botData.estimatePos[2] = temp_posZ;
  driver->botData.aiVelAxis[0] = 0;

  temp_xRead = driver->botData.estimatePos[0];
  temp_s7 = temp_s6->pos[0] - temp_xRead;
  temp_lo = temp_s7 * temp_s7;

  temp_zRead = driver->botData.estimatePos[2];
  temp_s5 = temp_s6->pos[2] - temp_zRead;
  temp_lo_2 = temp_s5 * temp_s5;

  temp_yRead = driver->botData.estimatePos[1];
  temp_s0 = temp_s6->pos[1] - temp_yRead;

  driver->botData.distToNextNavXz = SquareRoot0_stub(temp_lo + temp_lo_2);
  driver->botData.distToNextNavXyz = SquareRoot0_stub((temp_lo + (temp_s0 * temp_s0)) + temp_lo_2);
  driver->botData.estimateRotCurrY = (s8) (ratan2(temp_s0 << 0xC, driver->botData.distToNextNavXz << 0xC) >> 4);
  driver->botData.unk5A8 = 0;

  if ((arg1 << 0x10) != 0) {
    driver->botData.estimateRotNav[1] = (u8) ((s32) (((LevelSpawnView *) D_8008D2AC->level1)->driverSpawn[0].rot[1] + 0x400) >> 4);
  } else {
    driver->botData.estimateRotNav[0] = temp_s6->rot[0];
    driver->botData.estimateRotNav[1] = (u8) ((s32) (ratan2(-temp_s7, -temp_s5) + 0x800) >> 4);
    driver->botData.estimateRotNav[2] = temp_s6->rot[2];
  }

  temp_v0 = driver->botData.estimateRotNav[1] * 0x10;
  driver->botData.aiRotY608 = temp_v0;
  driver->angle = temp_v0;
  driver->rotCurr[1] = temp_v0;
  driver->rotPrev[1] = temp_v0;
  driver->botData.aiRot4[1] = temp_v0;
  driver->botData.botFlags = driver->botData.botFlags | 1;
}
