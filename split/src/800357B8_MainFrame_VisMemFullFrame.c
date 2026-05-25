// basic psx types
typedef signed char     s8;
typedef unsigned char   u8;
typedef signed short    s16;
typedef unsigned short  u16;
typedef signed int      s32;
typedef unsigned int    u32;

#define NULL 0
// Forward declarations
extern void func_80021DA0(s32 arg0, s32 arg1);
extern void func_80035684(void *arg0, s32 arg1);
extern void func_80077CB8(s32 arg0, s32 arg1, s32 arg2);

struct mesh_info {
    s32 numQuadBlock;
    u8 pad04[0x8];
    struct QuadBlock *ptrQuadBlockArray;
    u8 pad10[0xC];
    s32 numBspNodes;
};

struct Level {
    struct mesh_info *ptr_mesh_info;
    u8 pad04[0x24];
    s32 unk5;
    u8 pad2C[0x08];
    s32 numWaterVertices;
    u8 pad38[0xA4];
    s32 configFlags;
    u8 padE0[0x90];
    s32 unk_170;
    s32 numSCVert;
};

struct PVS {
    s32 visLeafSrc;
    s32 visFaceSrc;
    s32 visInstSrc;
};

struct QuadBlock {
    u8 pad0[0x44];
    struct PVS *pvs;
};

struct Driver {
    u8 pad0[0x350];
    struct QuadBlock *underDriver;
};

struct VisMem {
    s32 visLeafList[4];
    s32 visFaceList[4];
    s32 visOVertList[4];
    s32 visSCVertList[4];
    s32 visLeafSrc[4];
    s32 visFaceSrc[4];
    s32 visOVertSrc[4];
    s32 visSCVertSrc[4];
};

struct CameraDC {
    u8 pad00[0x20];
    s32 visLeafSrc;
    s32 visFaceSrc;
    s32 visInstSrc;
    s32 visOVertSrc;
    s32 visSCVertSrc;
    u8 pad34[0x3C];
    s32 flags;
    u8 pad74[0x26];
    s16 cameraMode;
    u8 pad9C[0x40];
};

struct GameTracker {
    u8 pad000[0x160];
    struct Level *level1;
    u8 pad164[0x1334];
    struct CameraDC cameraDC[4];
    u8 pad1574[0x230];
    struct VisMem *visMem1;
    u8 pad1A3C[0x26C];
    u8 numPlyrCurrGame;
    u8 pad1CA9[3];
    u8 pad1CAC[0x24EC - 0x1CAC];
    struct Driver *drivers[4];
};

typedef struct
{
    u8 pad[23];   
}struct_size_23;

void func_800357B8(struct GameTracker *gGT, struct Level *level) {
    struct CameraDC *cDC;
    struct Driver *d;
    struct mesh_info *mesh;
    s32 i;
    s32 temp_count;

    if ((gGT->visMem1 == NULL) || (level == NULL)) {
        return;
    }

    mesh = level->ptr_mesh_info;
    for (i = 0; i < gGT->numPlyrCurrGame; i++) {
        cDC = &gGT->cameraDC[i];
        d = gGT->drivers[i];
        cDC->flags &= ~0x4000;

        if (cDC->visLeafSrc == NULL) {
            if (d->underDriver != NULL && d->underDriver->pvs != NULL) {
                if (d->underDriver->pvs->visLeafSrc != NULL) {
                    gGT->visMem1->visLeafSrc[i] = d->underDriver->pvs->visLeafSrc;
                    if ((d->underDriver->pvs->visLeafSrc & 1) != 0) {
                        //decompress compressed vis data (?) unknown function
                        func_80021DA0(gGT->visMem1->visLeafList[i], d->underDriver->pvs->visLeafSrc & -4);
                    } else {
                        //memcpy
                        func_80077CB8(gGT->visMem1->visLeafList[i], d->underDriver->pvs->visLeafSrc,
                                      ((mesh->numBspNodes + 0x1F) >> 5) * 4);
                    }
                }
            }
        } else {
            if (gGT->visMem1->visLeafSrc[i] != cDC->visLeafSrc) {
                gGT->visMem1->visLeafSrc[i] = cDC->visLeafSrc;
                if ((cDC->visLeafSrc & 1) != 0) {
                    //decompress compressed vis data (?) unknown function
                    func_80021DA0(gGT->visMem1->visLeafList[i], cDC->visLeafSrc & -4);
                } else {
                    //memcpy
                    func_80077CB8(gGT->visMem1->visLeafList[i], cDC->visLeafSrc,
                                  ((mesh->numBspNodes + 0x1F) >> 5) * 4);
                } 
            }
        }

        if (cDC->visFaceSrc == NULL) {
            if (d->underDriver != NULL && d->underDriver->pvs != NULL) {
                if (d->underDriver->pvs->visFaceSrc != NULL) {
                    gGT->visMem1->visFaceSrc[i] = d->underDriver->pvs->visFaceSrc;
                    if ((d->underDriver->pvs->visFaceSrc & 1) != 0) {
                        //decompress compressed vis data (?) unknown function
                        func_80021DA0(gGT->visMem1->visFaceList[i], d->underDriver->pvs->visFaceSrc & -4);
                    } else {
                        //memcpy
                        func_80077CB8(gGT->visMem1->visFaceList[i], d->underDriver->pvs->visFaceSrc,
                                      ((mesh->numQuadBlock + 0x1F) >> 5) * 4);
                    }
                }
            }
        } else {
            if (gGT->visMem1->visFaceSrc[i] != cDC->visFaceSrc) {
                gGT->visMem1->visFaceSrc[i] = cDC->visFaceSrc;
                if ((cDC->visFaceSrc & 1) != 0) {
                    //decompress compressed vis data (?) unknown function
                    func_80021DA0(gGT->visMem1->visFaceList[i], cDC->visFaceSrc & -4);
                } else {
                    //memcpy
                    func_80077CB8(gGT->visMem1->visFaceList[i], cDC->visFaceSrc,
                                  ((mesh->numQuadBlock + 0x1F) >> 5) * 4);
                }
                
                if ((d->underDriver != NULL) &&
                    (d->underDriver->pvs != NULL) &&
                    (d->underDriver->pvs->visLeafSrc != NULL) &&
                    (d->underDriver->pvs->visFaceSrc != NULL) &&
                    (d->underDriver->pvs->visInstSrc != NULL)) {

                    //idk what does this means but is parsing these qb pointers as 23 bytes structs
                    temp_count = (struct_size_23*)d->underDriver -
                               (struct_size_23*)gGT->level1->ptr_mesh_info->ptrQuadBlockArray;


                    {
                        s32 shift_raw = temp_count >> 2;
                        s32 visGroupIndex = (temp_count >> 7) * 4;
                        s32 *visGroupPtr = (s32 *)(visGroupIndex + gGT->visMem1->visFaceList[i]);
                        s32 visGroup = visGroupPtr[0];
                        s32 mask = 1 << (shift_raw & 0x1F);
                        if ((visGroup & mask) != 0) {
                            cDC->flags &= ~0x2000;
                        } else {
                            cDC->flags |= 0x2000;
                        }
                    }
                } else {
                    cDC->flags &= ~0x2000;
                }
                if ((cDC->flags & 0x2000) != 0) {
                    func_80035684(gGT, i);
                    cDC->flags |= 0x4000;
                }
            }
        }

        if (
            (cDC->flags & 0x1000) != 0 &&
            (cDC->flags & 0x4000) == 0
            )         
        {
            func_80035684(gGT, i);
        }

        if ((cDC->cameraMode == 0) && ((cDC->flags & 0x2000) != 0)) {
            if (d->underDriver != NULL && d->underDriver->pvs != NULL) {
                if (d->underDriver->pvs->visInstSrc != NULL) {
                    cDC->visInstSrc = d->underDriver->pvs->visInstSrc;
                }
            }
        }

        if ((level->configFlags & 4) == 0) {
            if (gGT->visMem1->visOVertSrc[i] != cDC->visOVertSrc) {
                gGT->visMem1->visOVertSrc[i] = cDC->visOVertSrc;
                if ((cDC->visOVertSrc & 1) != 0) {
                    //decompress compressed vis data (?) unknown function
                    func_80021DA0(gGT->visMem1->visOVertList[i], cDC->visOVertSrc & -4);
                } else {
                    //memcpy
                    func_80077CB8(gGT->visMem1->visOVertList[i], cDC->visOVertSrc,
                                  ((level->numWaterVertices + 0x1F) >> 5) * 4);
                }
            } else if (gGT->visMem1->visOVertSrc[i] == 0) {
                //memcpy
                func_80077CB8(gGT->visMem1->visOVertList[i], level->unk5, ((level->numWaterVertices + 0x1F) >> 5) * 4);
            }
        } else {
            if (gGT->visMem1->visSCVertSrc[i] != cDC->visSCVertSrc) {
                gGT->visMem1->visSCVertSrc[i] = cDC->visSCVertSrc;
                if ((cDC->visSCVertSrc & 1) != 0) {
                    //decompress compressed vis data (?) unknown function
                    func_80021DA0(gGT->visMem1->visSCVertList[i], cDC->visSCVertSrc & -4);
                } else {
                    //memcpy
                    func_80077CB8(gGT->visMem1->visSCVertList[i], cDC->visSCVertSrc,
                                  ((level->numSCVert + 0x1F) >> 5) * 4);
                }
            } else if (gGT->visMem1->visSCVertSrc[i] == NULL) {
                //memcpy
                func_80077CB8(gGT->visMem1->visSCVertList[i], level->unk_170, ((level->numSCVert + 0x1F) >> 5) * 4);
            }
        }
    }
}