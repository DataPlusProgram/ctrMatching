#include "../../common.h"

M2C_UNK DeliverEvent();

void CdInit_Unknown_80072104(void) {
    DeliverEvent(0xF0000003, 0x40);
}