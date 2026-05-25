// basic psx types
typedef signed char     s8;
typedef unsigned char   u8;
typedef signed short    s16;
typedef unsigned short  u16;
typedef signed int      s32;
typedef unsigned int    u32;

#define NULL 0
    
typedef struct {
    s32 unk0;           
    s32 unk4;            
} Sub;


typedef struct {
    u8  pad0[0x44];      
    Sub* unk44;          
} Mid;

typedef struct {
    u8  pad0[0x350];     
    Mid* unk350;         
} Slot;


typedef struct {
    s32 unk0;            
    u8  pad4[0x18];      
    s32 unk1C;           
} Dim;


typedef struct {
    void* unk0[1];       
    u8    pad4[0xC];     
    void* unk10[1];      
} Entry;


typedef struct {
    u8     pad0[0x160];     
    Dim**  unk160;           
    u8     pad164[0x1A38 - 0x164];
    Entry* unk1A38;          
    u8     pad1A3C[0x24EC - 0x1A3C];
    Slot*  unk24EC[1];       
} Base;

void func_80021E1C(void* a, s32 b);            
void func_80021EA8(void* a, s32 b, s32 c);     

void func_80035684(Base* arg0, s32 arg1) {
    Slot* slot;
    Sub* temp_v0;
    Mid* temp_v1;
    Dim* s3;
    s32 flags1;
    s32 flags2;

    s3 = arg0->unk160[0];
    slot = arg0->unk24EC[arg1];
    temp_v1 = slot->unk350;

    if (temp_v1 != NULL)
    {
        temp_v0 = temp_v1->unk44;
    
        if (temp_v0 != NULL)
        {
            flags1 = temp_v0->unk0;
            if (flags1 != 0) {
                if (flags1 & 1) {
                    func_80021E1C(arg0->unk1A38->unk0[arg1], flags1 & 0xFFFFFFFC);
                } else {
                    func_80021EA8(arg0->unk1A38->unk0[arg1], flags1,
                                  ((s32)(s3->unk1C + 0x1F) >> 5) * 4);
                }
            }
            flags2 = slot->unk350->unk44->unk4;
            if (flags2 != 0) {
                if (flags2 & 1) {
                    func_80021E1C(arg0->unk1A38->unk10[arg1], flags2 & 0xFFFFFFFC);
                } else {
                    func_80021EA8(arg0->unk1A38->unk10[arg1], flags2,
                                  ((s32)(s3->unk0 + 0x1F) >> 5) * 4);
                }
            }
        }
    }
}