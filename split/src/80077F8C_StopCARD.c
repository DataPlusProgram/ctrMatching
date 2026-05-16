#include "../../common.h"

M2C_UNK StopCARD2();
M2C_UNK _ExitCard();

void StopCARD(void) {
    StopCARD2();
    _ExitCard();
}