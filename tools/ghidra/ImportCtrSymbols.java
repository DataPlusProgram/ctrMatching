// Imports CTR symbol files into the current Ghidra program.
// Supported input format:
// SymbolName = 0x800123E0; // type:func
// SymbolName = 0x80010018; // type:u32 size:180
// @category CTR

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;

public class ImportCtrSymbols extends GhidraScript {

	private static final Pattern symbolPattern = Pattern.compile(
		"^\\s*([A-Za-z0-9_.$@?]+)\\s*=\\s*(0x[0-9A-Fa-f]+)\\s*;\\s*(?://\\s*(.*))?$");

	private static class ParsedSymbol {
		String symbolName;
		long addressValue;
		String metadataText;
		boolean isFunction;
	}

	private static class ImportSummary {
		int parsedLines;
		int createdFunctions;
		int renamedFunctions;
		int existingFunctions;
		int createdLabels;
		int existingLabels;
		int failedFunctions;
		int missingAddresses;
		int skippedLines;
		int errorLines;
	}

	@Override
	public void run() throws Exception {
		File symbolFile = askFile("Select CTR symbol file", "Import");
		ImportSummary summary = importSymbolsFromFile(symbolFile);

		println("");
		println("Import finished for: " + symbolFile.getAbsolutePath());
		println("Parsed lines: " + summary.parsedLines);
		println("Created functions: " + summary.createdFunctions);
		println("Renamed functions: " + summary.renamedFunctions);
		println("Existing functions: " + summary.existingFunctions);
		println("Created labels: " + summary.createdLabels);
		println("Existing labels: " + summary.existingLabels);
		println("Failed functions: " + summary.failedFunctions);
		println("Missing addresses: " + summary.missingAddresses);
		println("Skipped lines: " + summary.skippedLines);
		println("Error lines: " + summary.errorLines);
	}

	private ParsedSymbol parseSymbolLine(String lineText) {
		Matcher matchResult = symbolPattern.matcher(lineText);
		if (!matchResult.matches()) {
			return null;
		}

		ParsedSymbol parsedSymbol = new ParsedSymbol();
		parsedSymbol.symbolName = matchResult.group(1);
		parsedSymbol.addressValue = Long.decode(matchResult.group(2)).longValue();
		parsedSymbol.metadataText = matchResult.group(3);
		if (parsedSymbol.metadataText == null) {
			parsedSymbol.metadataText = "";
		}
		parsedSymbol.isFunction = parsedSymbol.metadataText.contains("type:func");
		return parsedSymbol;
	}

	private String ensureFunctionAt(Address symbolAddress, String symbolName) throws Exception {
		Function functionObject = getFunctionAt(symbolAddress);

		if (functionObject != null) {
			String oldName = functionObject.getName();
			if (!oldName.equals(symbolName)) {
				functionObject.setName(symbolName, SourceType.IMPORTED);
				return "renamedFunction";
			}
			return "existingFunction";
		}

		if (getInstructionAt(symbolAddress) == null) {
			disassemble(symbolAddress);
		}

		Function createdFunction = createFunction(symbolAddress, symbolName);
		if (createdFunction != null) {
			return "createdFunction";
		}

		return "failedFunction";
	}

	private String ensureLabelAt(Address symbolAddress, String symbolName) throws Exception {
		Symbol existingSymbol = currentProgram.getSymbolTable().getSymbol(symbolName, symbolAddress, null);
		if (existingSymbol != null) {
			return "existingLabel";
		}

		createLabel(symbolAddress, symbolName, true, SourceType.IMPORTED);
		return "createdLabel";
	}

	private ImportSummary importSymbolsFromFile(File symbolFile) throws Exception {
		ImportSummary summary = new ImportSummary();

		BufferedReader reader = new BufferedReader(new FileReader(symbolFile));
		try {
			String rawLineText;
			int lineIndex = 0;

			while ((rawLineText = reader.readLine()) != null) {
				lineIndex += 1;

				if (monitor.isCancelled()) {
					break;
				}

				String lineText = rawLineText.trim();
				if (lineText.isEmpty() || lineText.startsWith("//") || lineText.startsWith("#")) {
					continue;
				}

				ParsedSymbol parsedSymbol = parseSymbolLine(lineText);
				if (parsedSymbol == null) {
					summary.skippedLines += 1;
					println("Skipped line " + lineIndex + ": " + lineText);
					continue;
				}

				summary.parsedLines += 1;

				Address symbolAddress = toAddr(parsedSymbol.addressValue);
				if (symbolAddress == null || !currentProgram.getMemory().contains(symbolAddress)) {
					summary.missingAddresses += 1;
					println("Missing address for " + parsedSymbol.symbolName + " at " + Long.toHexString(parsedSymbol.addressValue));
					continue;
				}

				try {
					if (parsedSymbol.isFunction) {
						String functionResult = ensureFunctionAt(symbolAddress, parsedSymbol.symbolName);
						if ("createdFunction".equals(functionResult)) {
							summary.createdFunctions += 1;
						}
						else if ("renamedFunction".equals(functionResult)) {
							summary.renamedFunctions += 1;
						}
						else if ("existingFunction".equals(functionResult)) {
							summary.existingFunctions += 1;
						}
						else {
							summary.failedFunctions += 1;
							String labelResult = ensureLabelAt(symbolAddress, parsedSymbol.symbolName);
							if ("createdLabel".equals(labelResult)) {
								summary.createdLabels += 1;
							}
							else {
								summary.existingLabels += 1;
							}
						}
					}
					else {
						String labelResult = ensureLabelAt(symbolAddress, parsedSymbol.symbolName);
						if ("createdLabel".equals(labelResult)) {
							summary.createdLabels += 1;
						}
						else {
							summary.existingLabels += 1;
						}
					}
				}
				catch (Exception exceptionObject) {
					summary.errorLines += 1;
					println("Error on line " + lineIndex + ": " + exceptionObject.getMessage());
				}
			}
		}
		finally {
			reader.close();
		}

		return summary;
	}
}
