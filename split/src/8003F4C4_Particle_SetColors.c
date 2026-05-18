typedef int s32;

s32 Particle_BitwiseClampByte(); /* extern */

s32 Particle_SetColors(s32 arg0, s32 arg1, s32 arg2) {
	s32 tempS0;
	s32 tempS3;
	s32 tempV0;

	if (arg0 & 0x80) {
		tempS0 = Particle_BitwiseClampByte(arg2 + 0x5C);
		tempS3 = tempS0;

		if (arg0 & 0x100) {
			tempV0 = Particle_BitwiseClampByte(arg2 + 0x64) << 8;
		} else {
			tempV0 = tempS0 << 8;
		}

		tempS0 = tempS0 | tempV0;

		if (arg0 & 0x200) {
			tempV0 = Particle_BitwiseClampByte(arg2 + 0x6C) << 0x10;
		} else {
			tempV0 = tempS3 << 0x10;
		}

		tempS0 = tempS0 | tempV0;

		if (arg1 & 0x80) {
			tempS0 |= 0x02000000;
		}
	} else {
		if (arg1 & 0x80) {
			tempS0 = 0x03000000;
		} else {
			tempS0 = 0x01000000;
		}
	}

	return tempS0;
}