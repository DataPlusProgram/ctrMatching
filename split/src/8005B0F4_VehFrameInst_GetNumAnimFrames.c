#include "../../common.h"

s32 VehFrameInst_GetNumAnimFrames(Instance *inst, s32 animIndex)
{
    Model *model;
    ModelHeader *header;
    ModelAnim *anim;

    model = inst->model;
	
    if (model == NULL)
    {
        return 0;
    }

    if (model->numHeaders <= 0)
    {
        return 0;
    }

    header = model->headers;
    if (header == NULL)
    {
        return 0;
    }

    if (header->numAnimations <= animIndex)
    {
        return 0;
    }

    if (header->ptrAnimations == NULL)
    {
        return 0;
    }

    anim = header->ptrAnimations[animIndex];
    if (anim == NULL)
    {
        return 0;
    }

    return anim->numFrames & 0x7FFF;
}
