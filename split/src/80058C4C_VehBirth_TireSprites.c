//headers
//
typedef struct
{
    short x;
    short y;
    short z;
    
}SVec3;

struct Terrain
{
    int dummy;    
};

struct Icon
{
    int dummy;
};

struct Driver{
    struct Icon** wheelSprites;
    short wheelSize;
    unsigned char unk6[0x2];
    int tireColor;
    unsigned char unkC[0x2A];
    unsigned char heldItemID;
    unsigned char unk37[0x3];
    unsigned char unk3A[0x10];
    unsigned char driverID;
    unsigned char unk4E[0x30A];
    struct Terrain* terrainMeta1;
    unsigned char unk35C[0x6];
    SVec3 AxisAngle1_normalVec;
    unsigned char unk366[0x2];
    SVec3 AxisAngle2_normalVec;
    unsigned char unk36E[0x4C];
    short unkSpeedValue1;
    unsigned char unk3BE[0x2];
    unsigned char unk3C0[0x26];
    short numFramesSpentSteering;
    unsigned char unk3EA[0x2A];
    short unk412;
    unsigned char unk414[2];
    unsigned char unk416[0x65];
    unsigned char unk47B;
    unsigned char unk47F[0x65];
    int numLives;
    int teamID;
    unsigned char unk4EC[0x4];
    short quip1;
    unsigned char unk4F2[0x2];
    short quip2;   
    unsigned char unk4F6[0x2];
    


};

struct Thread
{
    unsigned char unk0[0x30];
    struct Driver* object;
};


struct GameTracker {
    unsigned char unk0[0x1a10];
    int levelID;
    unsigned char unk1A14[0x36C];
    int battleLifeLimit;
    unsigned char unk1D84[0x390];
    int* ptr_iconGroup;

};



struct gamedata
{
    short characterIDs[8];
};

extern struct GameTracker* D_8008D2AC;

//required for renaming
#define gGT D_8008D2AC
#define GET_ICON_ARRAY(val) ((struct Icon**)((unsigned char*)&val + 0x14))

extern struct gamedata D_80086E84;

#define data D_80086E84

enum CharIDs
{
    NITROS_OXIDE = 0xf
};

enum itemIDs
{
    NO_ITEM = 0xf
};

enum levelIDs
{
    MAIN_MENU_LEVEL = 0x27
};


void func_80058C4C(struct Thread* t) {
    struct Driver* d;
    d = t->object;
    d->wheelSprites = GET_ICON_ARRAY(gGT->ptr_iconGroup[0]);
    
    d->wheelSize = 0xCCC;
    
    
    if ((data.characterIDs[d->driverID] == NITROS_OXIDE) &&
        (gGT->levelID != MAIN_MENU_LEVEL)) {
        d->wheelSize = 0;
    }
    
    d->tireColor = 0x2E808080;
    d->unkSpeedValue1 = 0xA00;
    d->heldItemID = NO_ITEM;
    d->unk47B = 2;
    d->AxisAngle1_normalVec.x = 0x1000;
    d->AxisAngle2_normalVec.x = 0x1000;
    d->unk412 = 0x600;
    d->numFramesSpentSteering = 0x2710;   
    d->terrainMeta1 = (struct Terrain*)func_80057C68(0xA);   //TerrainVehAfterColl_GetTerrain

    
    d->numLives =  gGT->battleLifeLimit;

    d->teamID = d->driverID;
    d->quip1 = -1;
    d->quip2 = -1;
}


