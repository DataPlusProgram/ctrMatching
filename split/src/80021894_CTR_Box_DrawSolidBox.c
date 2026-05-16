typedef struct {
    short x;
    short y;
    short w;
    short h;
} RECT;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
} unknown;

typedef struct {
    unknown *unk0;
    unknown *unk4;
    unknown *unk8;
    unknown *unkC;
    unknown *unk10;
} args3Struct;

void func_80021894(RECT *rect, int *arg1, int *arg2, args3Struct *arg3) {
    unknown *temp_v1;
    unknown *var_t0_puVar2;

    temp_v1 = arg3->unkC;
    var_t0_puVar2 = 0;

    if (temp_v1 <= arg3->unk10) {
        var_t0_puVar2 = temp_v1;
        arg3->unkC = (var_t0_puVar2 + 1);
    }

    if (var_t0_puVar2 != 0) {
        var_t0_puVar2->unk4 = (*arg1 & 0xFFFFFF) | 0x28000000;
        var_t0_puVar2->unk8 = ((unsigned short) rect->x) | (rect->y << 0x10);
        var_t0_puVar2->unkC = ((rect->x + rect->w) & 0xFFFF) | (rect->y << 0x10);
        var_t0_puVar2->unk10 = ((unsigned short) rect->x) | ((rect->y + rect->h) << 0x10);
        var_t0_puVar2->unk14 = ((rect->x + rect->w) & 0xFFFF) | ((rect->y + rect->h) << 0x10);
        var_t0_puVar2->unk0 = (*arg2 & 0xFFFFFF) | 0x05000000;

        *arg2 = 0xFFFFFF & (int) var_t0_puVar2;
    }
}
