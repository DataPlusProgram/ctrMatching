typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
	char pad0[0xE3];
	u8 unkE3;
	char padE4[0x5];
	u8 unkE9;
	char padEA[0x2];
	u16 unkEC;
} M2cPadGetActSizeArg0;

s32 _padGetActSize(M2cPadGetActSizeArg0 *arg0) {
	s32 tempE3 = arg0->unkE3;
	s32 tempE9 = arg0->unkE9;
	s32 tempEC = arg0->unkEC;
	s32 left;
	s32 right;

	left = tempE3 + 1;
	left >>= 1;
	left <<= 2;

	right = tempE9 << 2;
	right += tempE9;
	right += 3;
	right &= 0xFFC;
	right += 4;

	return left + right + tempEC;
}