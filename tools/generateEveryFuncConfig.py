from pathlib import Path
import re


repoRoot = Path(__file__).resolve().parent.parent
symbolMapPath = repoRoot / "syms" / "funcs_SCUS_94426.txt"
outputConfigPath = repoRoot / "executable_cfg.yaml"
srcPath = repoRoot / "split" / "src"


def formatOffsetName(romStart: int, functionName: str) -> str:
    vramStart = (romStart - 0x800) + 0x80010000
    return f"{vramStart:08X}_{functionName}"


def getExistingFileNamesByVram() -> dict[int, str]:
    existingFileNamesByVram = {}
    fileNamePattern = re.compile(r"^([0-9A-Fa-f]{8})_(.+)\.c$")

    for path in srcPath.glob("*.c"):
        match = fileNamePattern.match(path.name)
        if match is None:
            continue

        vramStart = int(match.group(1), 16)
        existingFileNamesByVram[vramStart] = path.stem

    return existingFileNamesByVram


def getFunctionEntries() -> list[tuple[int, str, str]]:
    functionEntries = []
    existingFileNamesByVram = getExistingFileNamesByVram()
    symbolPattern = re.compile(r"^\s*([A-Za-z0-9_]+)\s*=\s*0x([0-9A-Fa-f]+);")

    for line in symbolMapPath.read_text(encoding="utf-8").splitlines():
        match = symbolPattern.match(line)
        if match is None:
            continue

        functionName = match.group(1)
        vramStart = int(match.group(2), 16)
        romStart = (vramStart - 0x80010000) + 0x800
        fileName = existingFileNamesByVram.get(vramStart, formatOffsetName(romStart, functionName))
        functionEntries.append((romStart, functionName, fileName))

    functionEntries.sort(key=lambda entry: entry[0])
    return functionEntries


def buildConfigText() -> str:
    functionEntries = getFunctionEntries()

    yamlLines = [
        "options:",
        "  platform: psx",
        "  basename: CrashTeamRacing",
        "  target_path: ../SCUS_944.26",
        "  base_path: split",
        "  disassemble_all: true",
        "  gp_value: 0x8008CF80",
        '  generated_c_preamble: "#include \\\"../../common.h\\\""',
        "  symbol_addrs_path:",
        "    - ../syms/manual_SCUS_94426.txt",
        "    - ../syms/funcs_SCUS_94426.txt",
        "",
        "segments:",
        "  - name: main",
        "    type: code",
        "    start: 0x800",
        "    vram: 0x80010000",
        "    subsegments:",
        "      - [0x800, .rodata, SCUS-94426]",
    ]

    for romStart, _, fileName in functionEntries:
        yamlLines.append(f"      - [0x{romStart:X}, c, {fileName}]")

    yamlLines.extend(
        [
            "      - [0x711A0, .data, SCUS-94426]",
            "      - [0x7DE68, .bss, SCUS-94426]",
            "",
            "  - [0x7E000]",
            "",
        ]
    )

    return "\n".join(yamlLines)


def main() -> None:
    outputConfigPath.write_text(buildConfigText(), encoding="utf-8")
    print(outputConfigPath)


if __name__ == "__main__":
    main()
