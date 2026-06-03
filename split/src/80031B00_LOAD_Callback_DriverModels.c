typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	s32 unk0;
} M2cLOADCallbackDriverModelsArg0;

extern M2C_UNK levBigLodIndex;
s32 ptrBigfileCdPos_2;

void LOAD_Callback_DriverModels(M2cLOADCallbackDriverModelsArg0 *arg0) {
    M2C_FIELD(&levBigLodIndex, s32 *, 4) = 0;
    ptrBigfileCdPos_2 = arg0->unk0;
}