typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern s16 D_80085B76[];
extern u16 D_8008FBD2[];
extern void *gT;

void SelectProfile_GetTrackID(void)
{
    void *tracker;
    s32 temp;

    D_80085B76[0] = 1;

    tracker = gT;
    temp = M2C_FIELD(tracker, u16 *, 0x1A10);

    D_8008FBD2[0] = temp;
}