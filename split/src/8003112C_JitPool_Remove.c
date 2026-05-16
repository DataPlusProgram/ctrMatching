typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK LIST_AddFront();                /* extern */
M2C_UNK LIST_RemoveMember();                     /* extern */

void JitPool_Remove(s32 arg0, M2C_UNK arg1) {
    LIST_RemoveMember(arg0 + 0xC);
    LIST_AddFront(arg0, arg1);
}