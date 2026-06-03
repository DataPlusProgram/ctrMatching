#include "../../common.h"

void PushBuffer_Init(PushBuffer *pushBuffer, s32 cameraId, s32 numPlayers)
{
	pushBuffer->cameraId = cameraId;
	pushBuffer->fadeFromBlackCurrentValue = 0x1000;
	pushBuffer->fadeFromBlackDesiredResult = 0x1000;
	pushBuffer->fadeStep = 0x88;
	pushBuffer->unk88 = 0x1C71;

	pushBuffer->unk8A = 0;
	pushBuffer->unk8C = 0;
	pushBuffer->unk8E = 0;
	pushBuffer->unk90 = 0x1000;
	pushBuffer->unk92 = 0;
	pushBuffer->unk94 = 0;
	pushBuffer->unk96 = 0;
	pushBuffer->unk98 = 0x1000;
	pushBuffer->unk9C = 0;
	pushBuffer->unkA0 = 0;
	pushBuffer->unkA4 = 0;

	switch (numPlayers)
	{
		case 1:
			pushBuffer->rectW = 0x200;
			pushBuffer->rectH = 0xD8;
			pushBuffer->distanceToScreenPrev = 0x100;
			pushBuffer->distanceToScreenCurr = 0x100;
			pushBuffer->unk24 = 4;
			pushBuffer->rectX = 0;
			pushBuffer->rectY = 0;
			pushBuffer->unk26 = 3;
			return;

		case 2:
			switch (cameraId)
			{
				case 0:
					pushBuffer->rectW = 0x200;
					pushBuffer->rectH = 0x6A;
					pushBuffer->distanceToScreenPrev = 0x100;
					pushBuffer->distanceToScreenCurr = 0x100;
					pushBuffer->unk24 = 8;
					pushBuffer->rectX = 0;
					pushBuffer->rectY = 0;
					pushBuffer->unk26 = 3;
					return;

				case 1:
					pushBuffer->rectY = 0x6E;
					pushBuffer->rectW = 0x200;
					pushBuffer->rectH = 0x6A;
					pushBuffer->distanceToScreenPrev = 0x100;
					pushBuffer->distanceToScreenCurr = 0x100;
					pushBuffer->unk24 = 8;
					pushBuffer->rectX = 0;
					pushBuffer->unk26 = 3;
					return;
			}
			return;

		case 3:
		case 4:
			switch (cameraId)
			{
				case 0:
					pushBuffer->rectW = 0xFD;
					pushBuffer->rectH = 0x6A;
					pushBuffer->distanceToScreenPrev = 0x80;
					pushBuffer->distanceToScreenCurr = 0x80;
					pushBuffer->unk24 = 4;
					pushBuffer->rectX = 0;
					pushBuffer->rectY = 0;
					pushBuffer->unk26 = 3;
					return;

				case 1:
					pushBuffer->rectX = 0x103;
					pushBuffer->rectW = 0xFD;
					pushBuffer->rectH = 0x6A;
					pushBuffer->distanceToScreenPrev = 0x80;
					pushBuffer->distanceToScreenCurr = 0x80;
					pushBuffer->unk24 = 4;
					pushBuffer->rectY = 0;
					pushBuffer->unk26 = 3;
					return;

				case 2:
					pushBuffer->rectY = 0x6E;
					pushBuffer->rectW = 0xFD;
					pushBuffer->rectH = 0x6A;
					pushBuffer->distanceToScreenPrev = 0x80;
					pushBuffer->distanceToScreenCurr = 0x80;
					pushBuffer->unk24 = 4;
					pushBuffer->rectX = 0;
					pushBuffer->unk26 = 3;
					return;

				case 3:
					pushBuffer->rectX = 0x103;
					pushBuffer->rectY = 0x6E;
					pushBuffer->rectW = 0xFD;
					pushBuffer->rectH = 0x6A;
					pushBuffer->distanceToScreenPrev = 0x80;
					pushBuffer->distanceToScreenCurr = 0x80;
					pushBuffer->unk24 = 4;
					pushBuffer->unk26 = 3;
					return;
			}
			return;
	}
}
