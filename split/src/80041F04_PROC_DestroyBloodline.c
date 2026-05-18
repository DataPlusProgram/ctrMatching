typedef signed char s8;
typedef int s32;

#define NULL 0
#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void PROC_DestroySelf(void *);
void PROC_DestroyBloodline(void *arg0);

void PROC_DestroyBloodline(void *arg0)
{
    void *child;
    void *next;
    void *self;
    void *varS0;

    varS0 = arg0;

    if (varS0 != NULL) {
        do {
            child = M2C_FIELD(varS0, void **, 0x14);

            if (child != NULL) {
                PROC_DestroyBloodline(child);
            }

            self = varS0;
            next = M2C_FIELD(self, void **, 0x10);
            PROC_DestroySelf(self);

            varS0 = next;
        } while (varS0 != NULL);
    }
}