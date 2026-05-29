#include "../../common.h"

typedef struct VehBirthConstValueTable {
    u8 pad0[0xC];
    s32 unkC;
} VehBirthConstValueTable;

typedef struct VehBirthConstEntry {
    s32 unk0;
    s32 driverOffset;
    u32 dataType;
    u8 values[0x10];
} VehBirthConstEntry;

extern VehBirthConstValueTable D_80086D84[];
extern s16 D_80086E84[];
extern VehBirthConstEntry D_80088A0C[];

void VehBirth_SetConsts(Driver *driver)
{
    u32 i;
    u32 dataType;
    s32 valueOffset;
    s32 driverOffset;
    VehBirthConstEntry *entry;

    i = 0;
    entry = D_80088A0C;

    do
    {
        dataType = entry->dataType;

        if (dataType == 2)
        {
            valueOffset = D_80086D84[D_80086E84[driver->driverId]].unkC * 4;
            driverOffset = entry->driverOffset;
            M2C_FIELD(driver, u16 *, driverOffset) = *(u16 *)&entry->values[valueOffset];
        }
        else if (dataType < 3)
        {
            if (dataType == 1)
            {
                valueOffset = D_80086D84[D_80086E84[driver->driverId]].unkC * 4;
                driverOffset = entry->driverOffset;
                M2C_FIELD(driver, u8 *, driverOffset) = entry->values[valueOffset];
            }
        }
        else if (dataType == 4)
        {
            valueOffset = D_80086D84[D_80086E84[driver->driverId]].unkC * 4;
            driverOffset = entry->driverOffset;
            M2C_FIELD(driver, u32 *, driverOffset) = *(u32 *)&entry->values[valueOffset];
        }

        entry++;
        i++;
    } while (i < 0x41);
}