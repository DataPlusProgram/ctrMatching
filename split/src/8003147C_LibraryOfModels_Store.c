typedef signed char s8;
typedef short s16;
typedef int s32;

void LibraryOfModels_Store(s32 arg0, s32 arg1, void **arg2)
{
    s32 invalid = -1;
    void *model;
    s16 id;
    int newVar;

    if (arg1 != 0) {
        do {
            model = *arg2;
            newVar = 4;

            if (model == 0) {
                return;
            }

            id = *((s16 *)(((s8 *)model) + 0x10));

            if (id != invalid) {
                *((void **)(((s8 *)(arg0 + (id * newVar))) + 0x2160)) = model;
            }

            arg1--;
            arg2++;
        } while (arg1 != 0);
    }
}