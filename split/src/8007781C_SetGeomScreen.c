#define M2C_ERROR(desc) (0)

void SetGeomScreen(int arg0) {
    asm("ctc2 $a0,$26");
}