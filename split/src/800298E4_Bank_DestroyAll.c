typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK Bank_DestroyLast();                         /* extern */
u8 ptrLastBank;

void Bank_DestroyAll(void)
{
  while (ptrLastBank != '\0') {
    Bank_DestroyLast();
  }
  return;
}