typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#define PTR(base, offset) (((s8 *) (base)) + (offset))
#define S16(base, offset) (*((s16 *) PTR(base, offset)))
#define U8(base, offset) (*((u8 *) PTR(base, offset)))
#define S32(base, offset) (*((s32 *) PTR(base, offset)))
#define VOIDP(base, offset) (*((void **) PTR(base, offset)))

s16 SquareRoot0_stub();
s32 ratan2();
extern void *D_8008D2AC;

void BOTS_SetRotation(void *arg0, s32 arg1)
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
  void *temp_s6;

  temp_posX = (s16) (S32(arg0, 0x2D4) >> 8);
  temp_posY = (s16) (S32(arg0, 0x2D8) >> 8);
  temp_s6 = VOIDP(arg0, 0x5A4);
  S32(arg0, 0x5EC) = 0;
  S32(arg0, 0x5E8) = 0;
  S16(arg0, 0x60C) = temp_posX;
  temp_posZ = (s16) (S32(arg0, 0x2DC) >> 8);
  S16(arg0, 0x60E) = temp_posY;
  S16(arg0, 0x610) = temp_posZ;
  S32(arg0, 0x5E4) = 0;

  temp_xRead = S16(arg0, 0x60C);
  temp_s7 = S16(temp_s6, 0) - temp_xRead;
  temp_lo = temp_s7 * temp_s7;

  temp_zRead = S16(arg0, 0x610);
  temp_s5 = S16(temp_s6, 4) - temp_zRead;
  temp_lo_2 = temp_s5 * temp_s5;

  temp_yRead = S16(arg0, 0x60E);
  temp_s0 = S16(temp_s6, 2) - temp_yRead;

  S16(arg0, 0x618) = SquareRoot0_stub(temp_lo + temp_lo_2);
  S16(arg0, 0x616) = SquareRoot0_stub((temp_lo + (temp_s0 * temp_s0)) + temp_lo_2);
  *((s8 *) PTR(arg0, 0x615)) = (s8) (ratan2(temp_s0 << 0xC, S16(arg0, 0x618) << 0xC) >> 4);
  S32(arg0, 0x5A8) = 0;

  if ((arg1 << 0x10) != 0) {
    U8(arg0, 0x613) = (u8) ((s32) (S16(VOIDP(D_8008D2AC, 0x160), 0x74) + 0x400) >> 4);
  } else {
    U8(arg0, 0x612) = U8(temp_s6, 6);
    U8(arg0, 0x613) = (u8) ((s32) (ratan2(-temp_s7, -temp_s5) + 0x800) >> 4);
    U8(arg0, 0x614) = U8(temp_s6, 8);
  }

  temp_v0 = U8(arg0, 0x613) * 0x10;
  S16(arg0, 0x608) = temp_v0;
  S16(arg0, 0x39A) = temp_v0;
  S16(arg0, 0x2EE) = temp_v0;
  S16(arg0, 0x2F6) = temp_v0;
  S16(arg0, 0x5FE) = temp_v0;
  S32(arg0, 0x5B0) = S32(arg0, 0x5B0) | 1;
}