typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern void *D_8008D2AC;

s32 CAM_Path_GetNumPoints(void) {
	void *camera;
	void *path;
	s16 *points;
	s16 total;
	s32 count;
	s32 signedCount;
	s32 step;

	camera = *(void **)((s8 *)D_8008D2AC + 0x160);
	total = 0;

	if (camera != 0) {
		path = *(void **)((s8 *)camera + 0x134);

		if (*(s32 *)((s8 *)path + 0) >= 3) {
			points = *(s16 **)((s8 *)path + 0x10);
			step = points != 0;

			if (step) {
				goto firstLoad;

loop:
				total += count;
				signedCount = (s16)count;
				step = signedCount * 3;
				step <<= 2;
				points = (s16 *)((s8 *)points + step);

firstLoad:
				count = (u16)points[0];

				if (points[0] != 0) {
					points = (s16 *)((s8 *)points + 4);
					goto loop;
				}
			}
		}
	}

	return total;
}