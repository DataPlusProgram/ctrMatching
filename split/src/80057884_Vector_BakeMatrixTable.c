#include "../../common.h"

typedef struct MatrixAnimFrame {
    s16 pos[3];
    s16 pad6;
    s16 rotData[12];
} MatrixAnimFrame;

typedef struct MatrixAnimSet {
    MatrixAnimFrame *frames;
    s32 frameCount;
} MatrixAnimSet;

extern u8 D_8008D5A4;
extern MatrixAnimSet D_80087EF4[];
extern MatrixAnimSet D_80087F24;

extern void ConvertRotToMatrix(void *output, void *rotData);
extern void MatrixRotate(void *output, void *baseMatrix, void *rotationData);

void Vector_BakeMatrixTable(void)
{
    MatrixNd baseMatrix;
    MatrixNd rotationMatrix;
    MatrixAnimFrame *frame;
    MatrixAnimSet *animSet;
    s32 frameCount;
    s32 frameIndex;
    s32 setIndex;
    s32 sinValue;
    s32 tempX;
    s32 tempY;
    s32 tempZ;
    s32 trans[3];
    s32 phaseAngle;
    s32 waveAngle;

    if (D_8008D5A4 != 0) {
        return;
    }

    D_8008D5A4 = 1;
    frameCount = D_80087F24.frameCount;

    if (frameCount > 0) {
        waveAngle = 0;

        for (frameIndex = 0; frameIndex < frameCount; frameIndex++) {
            frame = &D_80087F24.frames[frameIndex];
            phaseAngle = frameIndex << 0xD;

            frame->rotData[2] = phaseAngle / frameCount;
            frame->rotData[0] = (s16)(-MATH_Sin(waveAngle / frameCount) / 7);
            frame->rotData[4] = (s16)(((MATH_Sin(phaseAngle / frameCount) * 6) / 40) + 0x1000);
            frame->rotData[6] = (s16)(((MATH_Sin(phaseAngle / frameCount) * 6) / 40) + 0x1000);

            sinValue = MATH_Sin(phaseAngle / frameCount);
            if (sinValue < 0) {
                sinValue += 3;
            }

            frame->rotData[4] = (s16)((sinValue >> 2) + 0x1000);
            waveAngle += 0x3000;
        }
    }

    *(s32 *)&baseMatrix.m[0][0] = 0;
    *(s32 *)&baseMatrix.m[0][2] = 0;
    *(s32 *)&baseMatrix.m[1][1] = 0;
    *(s32 *)&baseMatrix.m[2][0] = 0;
    *(s32 *)&baseMatrix.m[2][2] = 0;
    *(s32 *)&baseMatrix.t[0] = 0;
    *(s32 *)&baseMatrix.t[1] = 0;
    *(s32 *)&baseMatrix.t[2] = 0;

    for (setIndex = 0; setIndex < 0x14; setIndex++) {
        animSet = &D_80087EF4[setIndex];

        if ((animSet->frames == NULL) || (animSet->frameCount <= 0)) {
            continue;
        }

        for (frameIndex = 0; frameIndex < animSet->frameCount; frameIndex++) {
            frame = &animSet->frames[frameIndex];
            ConvertRotToMatrix(&rotationMatrix, frame->rotData);

            baseMatrix.m[0][0] = frame->rotData[4];
            baseMatrix.m[1][1] = frame->rotData[5];
            baseMatrix.m[2][2] = frame->rotData[6];

            MatrixRotate(frame->rotData, &baseMatrix, &rotationMatrix);
        }
    }

    frameCount = D_80087F24.frameCount;
    if (frameCount <= 0) {
        return;
    }

    trans[0] = 0;
    trans[1] = 0x2000;
    trans[2] = 0;

    for (frameIndex = 0; frameIndex < frameCount; frameIndex++) {
        frame = &D_80087F24.frames[frameIndex];

        gte_SetRotMatrix(frame->rotData);
        gte_ldtr(trans[0], trans[1], trans[2]);
        gte_ldVXY0(0xE0000000U);
        gte_ldVZ0(0);
        gte_rtv0();
        read_mt(tempX, tempY, tempZ);

        frame->pos[0] = (s16)tempX;
        frame->pos[1] = (s16)tempY;
        frame->pos[2] = (s16)tempZ;
    }
}
