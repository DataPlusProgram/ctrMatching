from pathlib import Path
import re


repoRoot = Path(__file__).resolve().parent.parent
symbolMapPath = repoRoot / "syms" / "funcs_SCUS_94426.txt"
generatedSymbolMapPath = repoRoot / "syms" / "funcs_SCUS_94426_generated.txt"
outputConfigPath = repoRoot / "executable_cfg.yaml"


def formatOffsetName(romStart: int, functionName: str) -> str:
    vramStart = (romStart - 0x800) + 0x80010000
    return f"{vramStart:08X}_{functionName}"


def getFunctionEntries() -> list[tuple[int, str, str]]:
    functionEntries = []
    symbolPattern = re.compile(r"^\s*([A-Za-z0-9_]+)\s*=\s*0x([0-9A-Fa-f]+);")

    for line in symbolMapPath.read_text(encoding="utf-8").splitlines():
        match = symbolPattern.match(line)
        if match is None:
            continue

        functionName = match.group(1)
        vramStart = int(match.group(2), 16)
        romStart = (vramStart - 0x80010000) + 0x800
        functionEntries.append((romStart, functionName, formatOffsetName(romStart, functionName)))

    functionEntries.sort(key=lambda entry: entry[0])
    return functionEntries


def writeGeneratedSymbolMap(functionEntries: list[tuple[int, str, str]]) -> None:
    generatedLines = ["func_80011D60 = 0x80011D60; // type:func filename:80011D60_func_80011D60"]

    for romStart, functionName, fileName in functionEntries:
        vramStart = (romStart - 0x800) + 0x80010000
        generatedLines.append(
            f"{functionName} = 0x{vramStart:08X}; // type:func filename:{fileName}"
        )

    generatedSymbolMapPath.write_text("\n".join([*generatedLines, ""]), encoding="utf-8")


def buildConfigText() -> str:
    functionEntries = getFunctionEntries()
    writeGeneratedSymbolMap(functionEntries)

    yamlLines = [
        "options:",
        "  platform: psx",
        "  basename: CrashTeamRacing",
        "  target_path: ../SCUS_944.26",
        "  base_path: split",
        "  disassemble_all: true",
        '  generated_c_preamble: "#include \\"../../common.h\\""',
        "  symbol_addrs_path:",
        "    - ../syms/funcs_SCUS_94426_generated.txt",
        "",
        "segments:",
        "  - name: main",
        "    type: code",
        "    start: 0x800",
        "    vram: 0x80010000",
        "    subsegments:",
        "      - [0x800, .rodata, SCUS-94426]",
        "      - [0x2560, c, 80011D60_func_80011D60]",
        "      - [0x2570, asm, 80011D70_BOTS_EmptyFuncData]",
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
