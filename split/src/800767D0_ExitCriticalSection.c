#define M2C_ERROR(desc) (0)

void ExitCriticalSection(void) {
    __asm__ volatile(
        "li $a0, 2\n"
        "syscall\n"
    );
}