#include "../../common.h"

extern u8 D_80086E84[];

void Podium_InitModels(void *arg0) {
	s32 i;
	void **modelPtr;
	void *model;
	s32 modelType;
	u8 color;

	i = 0;
	modelPtr = (void **)((s8 *)arg0 + 0x24EC);

	M2C_FIELD(arg0, u8 *, 0x2575) = 0;
	M2C_FIELD(arg0, u8 *, 0x2576) = 0;
	M2C_FIELD(arg0, u8 *, 0x2577) = 0;
	M2C_FIELD(arg0, u8 *, 0x2578) = 143;

	do {
		model = *modelPtr;

		if (model != 0) {
			modelType = M2C_FIELD(model, s16 *, 0x482);

			if (modelType == 1) {
				goto type1;
			}

			if (!(modelType < 2)) {
				if (modelType == 2) {
					goto type2;
				}
				goto next;
			}

			if (modelType == 0) {
				goto type0;
			}

			goto next;

type0:
			color = D_80086E84[M2C_FIELD(model, u8 *, 0x4A) * 2] + 126;
			M2C_FIELD(arg0, u8 *, 0x2575) = color;

			switch (color) {
			case 126:
			case 127:
			case 128:
				M2C_FIELD(arg0, u8 *, 0x2578) = 144;
				break;

			case 129:
			case 130:
			case 131:
				M2C_FIELD(arg0, u8 *, 0x2578) = 145;
				break;

			case 132:
			case 133:
				M2C_FIELD(arg0, u8 *, 0x2578) = 146;
				break;
			}

			goto next;

type1:
			color = D_80086E84[M2C_FIELD(model, u8 *, 0x4A) * 2] + 126;
			M2C_FIELD(arg0, u8 *, 0x2576) = color;
			goto next;

type2:
			color = D_80086E84[M2C_FIELD(model, u8 *, 0x4A) * 2] + 126;
			M2C_FIELD(arg0, u8 *, 0x2577) = color;
		}

next:
		i++;
		modelPtr++;
	} while (i < 8);
}