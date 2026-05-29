typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK CDSYS_XAPauseForce();                /* extern */
M2C_UNK CdControl();          /* extern */
M2C_UNK CdReadyCallback();                   /* extern */
M2C_UNK CdSyncCallback();                    /* extern */
 s32 XA_MaxSampleNumSaved;
s32 XA_VolumeDeduct;
 s32 irqAddr;
 s32 ptrArray_firstXaIndex;

void CDSYS_SetMode_StreamData(void) {
    s8 sp10;

    if ((irqAddr != 0) && (XA_MaxSampleNumSaved != 0)) {
        if (XA_VolumeDeduct != 0) {
            CDSYS_XAPauseForce(0xE);
        }
        sp10 = 0x80;
        CdControl(0xE, &sp10, 0);
        ptrArray_firstXaIndex = 0;
        XA_MaxSampleNumSaved = 0;
        if (XA_VolumeDeduct != 0) {
            CdSyncCallback(0);
            CdReadyCallback(0);
        }
    }
}