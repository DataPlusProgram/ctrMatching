typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK _card_write();         /* extern */
M2C_UNK _new_card();                                /* extern */

void _card_clear(s32 arg0) {
    _new_card();
    _card_write(arg0, 0x3F, 0);
}