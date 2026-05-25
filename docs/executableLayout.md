| Start | End | Size | Section | Description |
|---:|---:|---:|---|---|
| `0x000000` | `0x000800` | `2,048 bytes` | SONY HEADER | Header data |
| `0x000800` | `0x002BE0` | `9,184 bytes` | `.rodata` | Const variables |
| `0x002BE0` | `0x0711A0` | `452,032 bytes` | `.text` | ASM / functions |
| `0x0711A0` | `0x07DE68` | `52,424 bytes` | `.data` | Initialized non-const variables |
| `0x07DE68` | `0x07E000` | `408 bytes` | `.bss` | Zero-initialized variables |
