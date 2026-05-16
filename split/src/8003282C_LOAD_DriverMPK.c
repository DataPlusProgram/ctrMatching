#include "../../common.h"

struct BigFile
{
  s32 unk0;  
};

//InitBotModels 2P
//last parameter is arg2 from driverMPK
void LOAD_Robots2P(struct BigFile*, s16 P1_charID,
                   s16 P2_charID, s32 unk);

//Load_AppendQueue
void LOAD_AppendQueue(struct BigFile*, s32 fileType,
                   s32 bigfileIndex, s32* savethere, s32 unk);

extern s32 D_80083A10[];
extern s16 D_80086E84[];
extern struct GameTracker* D_8008D2AC;
#define NULL 0

static inline s32 get_ret(void) {
    s32 r;
    asm volatile("lw %0, 284($gp)" : "=r"(r));
    return r;
}

#define ADV_PURPLE_CUP 4
#define data_characterIDs D_80086E84

enum Characters
{
	PINSTRIPE = 8,
	PAPU_PAPU,
	RIPPER_ROO,
	KOMODO_JOE,
};

enum GameMode1
{
	MAIN_MENU           = 0x2000,
	TIME_TRIAL          = 0x20000,
	ADVENTURE_ARENA     = 0x100000,
	ADVENTURE_CUP       = 0x10000000,
	GAME_CUTSCENE      	= 0x20000000,
	ADVENTURE_BOSS      = 0x80000000
};

enum LevelLOD
{
	LOD_HI = 1, //1P
	LOD_MED, //2P
	LOD_LOW_3P,
	LOD_LOW_4P, //should be the same than 3P
	LOD_RELIC_TT = 8
};

#define gGT D_8008D2AC
// read with patching table at the end
#define LT_DRAM 2

//levelID
#define ADVENTURE_GARAGE 0x28

#define data_driverModelExtras D_80083A10

//gameMode2 flag
#define CREDITS 0x80



s32 func_8003282C(struct BigFile* bigfilePtr, s32 lodLevel, s32 arg2) {
    s32 gameMode1;

    if (lodLevel == LOD_LOW_3P || lodLevel == LOD_LOW_4P) {
        
        //Load_AppendQueue
        //Third parameter is bigfile index
        //load the model
        LOAD_AppendQueue(bigfilePtr, LT_DRAM,
                      data_characterIDs[0] + 0x14C,
                      &data_driverModelExtras[0], -2);
        
        LOAD_AppendQueue(bigfilePtr, LT_DRAM,
                      data_characterIDs[1] + 0x14C,
                      &data_driverModelExtras[1], -2);
        
        LOAD_AppendQueue(bigfilePtr, LT_DRAM,
                      data_characterIDs[2] + 0x14C,
                      &data_driverModelExtras[2], -2);

        //load the mpk
        LOAD_AppendQueue(bigfilePtr, LT_DRAM,
                      data_characterIDs[3] + 0x15C,
                      NULL, arg2);

        //return sdata->ptrMPK
        return get_ret();
    }
    
    if (lodLevel == LOD_HI) {
        
        gameMode1 = gGT->gameMode1;
        
        if (
            ((gameMode1 & TIME_TRIAL) != 0) &&
            ((gameMode1 & MAIN_MENU) == 0)
        ) 
        {
            goto block_test;
        }
        
        if (
            ((gameMode1 & (GAME_CUTSCENE | ADVENTURE_ARENA)) != 0) ||
            ((gGT->gameMode2 & CREDITS) != 0) ||
            (gGT->levelID == ADVENTURE_GARAGE))
        {
            //just load the mpk, no model
            LOAD_AppendQueue(bigfilePtr, LT_DRAM,
                          data_characterIDs[0] + 0x114,
                          NULL, arg2);
            //return sdata->ptrMPK
            return get_ret();
        }

        if ((gameMode1 & ADVENTURE_BOSS) != 0) {
            goto do_F2_124;
        }
        
        if (
            ((gameMode1 & ADVENTURE_CUP) != 0) &&
            gGT->cupID == ADV_PURPLE_CUP
        )
        {
            //load model
            LOAD_AppendQueue(bigfilePtr, LT_DRAM,
                          data_characterIDs[0] + 0xF2,
                          &data_driverModelExtras[0], -2);
            
            //load the mpk
            LOAD_AppendQueue(bigfilePtr, LT_DRAM,
                          0x14B,
                          NULL, arg2);
            
            data_characterIDs[1] = RIPPER_ROO;
            data_characterIDs[2] = PAPU_PAPU;
            data_characterIDs[3] = KOMODO_JOE;
            data_characterIDs[4] = PINSTRIPE;
            //return sdata->ptrMPK
            return get_ret();
        }
        
        if (
            ((gGT->gameMode1 & TIME_TRIAL) != 0) || 
            ((gGT->gameMode1 & MAIN_MENU) == 0)
        )
        {
            //InitBots1P ?? 
            LOAD_Robots1P(data_characterIDs[0]);
        }

        //load only the mpk
        LOAD_AppendQueue(bigfilePtr, LT_DRAM, data_characterIDs[0] + 0x104, NULL, arg2);

        //return sdata->ptrMPK
        return get_ret();
    }
    
block_test:

    if (lodLevel == LOD_RELIC_TT ||
        ((gGT->gameMode1 & TIME_TRIAL) != 0))
    {        
    do_F2_124:

        //load model
        LOAD_AppendQueue(bigfilePtr, LT_DRAM,
                      data_characterIDs[0] + 0xF2,
                      &data_driverModelExtras[0], -2);

        //load mpk
        LOAD_AppendQueue(bigfilePtr, LT_DRAM,
                      data_characterIDs[1] + 0x124,
                      NULL, arg2);
        
        //return sdata->ptrMPK
        return get_ret();
    }

    //load model
    LOAD_AppendQueue(bigfilePtr, LT_DRAM,
                  data_characterIDs[0] + 0x134,
                  &data_driverModelExtras[0], -2);

    //load model
    LOAD_AppendQueue(bigfilePtr, LT_DRAM,
                  data_characterIDs[1] + 0x134,
                  &data_driverModelExtras[1], -2);

    //InitBots2P
    LOAD_Robots2P(bigfilePtr, data_characterIDs[0],
                  data_characterIDs[1], arg2);

    //return sdata->ptrMPK
    return get_ret();
}