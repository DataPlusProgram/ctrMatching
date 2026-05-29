typedef short s16;

s16 D_8008D48C;
s16 memcardAction;

void RefreshCard_StopMemcardAction(void) {
    memcardAction = 1;
    D_8008D48C = 2;
}