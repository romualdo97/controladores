//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <map>

#include <Windows.h>

#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

//#define DEBUG_MODE
#define DEBUG_OUTPUT

#define TMP_FILENAME ".symbseeker_tmp"

// num of line of cde
// ^(?!(\s*\*))(?!(\s*\-\-\>))(?!(\s*\<\!\-\-))(?!(\s*\n))(?!(\s*\*\/))(?!(\s*\/\*))(?!(\s*\/\/\/))(?!(\s*\/\/))(?!(\s*\}))(?!(\s*\{))(?!(\s(using))).*$


int main(int argc, char **arg)
{

	if (argc != 2)
	{
		std::cout << "\n\t[ERROR: ] Usage: RAssembler.exe [assembly_input_file]\n";
		return -1;
	}

	// fn stands for FileName
	std::string fn(arg[1]);
	std::string fn_asm = fn + ".asm";
	std::string fn_hack = fn + ".hack";

	// SYMBOL SEEKER
	Parser mySymbSeeker(fn_asm.c_str());

	if (!mySymbSeeker.isFileOpen()) return -1;
	std::ofstream outSeeker_tmp; // file for store output of symbol seeker
	outSeeker_tmp.open(TMP_FILENAME);

	// make the temp file hidden
	DWORD tmp_attr = GetFileAttributes(TMP_FILENAME);
	SetFileAttributes(TMP_FILENAME, tmp_attr + FILE_ATTRIBUTE_HIDDEN);

#ifdef DEBUG_OUTPUT
	std::string fn_dbg = fn + "_Debug.hack";
	std::ofstream outDebug;
	outDebug.open(fn_dbg);
#endif // DEBUG_OUTPUT

	Code myTranscriptor;
	SymbolTable mySymbTable;

	int _iram_addrs = 16; // where to store new var labels?
	int _irom_addrs = 0; // rom address

#ifdef DEBUG_OUTPUT
	outDebug << "SEEKING SYMBOLS:\n\n";
#endif // DEBUG_OUTPUT

	int lineNum = 1;
	while (mySymbSeeker.hasMoreCommand())
	{
		mySymbSeeker.advance();

		if (mySymbSeeker.commandType() == cmdType::UNDEFINED) continue;

		std::string symb = mySymbSeeker.symbol();
		std::string comp = mySymbSeeker.comp();
		std::string dest = mySymbSeeker.dest();

#ifdef DEBUG_OUTPUT
		outDebug << "\t";
		outDebug << _irom_addrs << " \t\t" << mySymbSeeker.getCurrentCommand();
#endif // DEBUG_OUTPUT

		if (mySymbSeeker.commandType() == L_COMMAND)
		{
			mySymbTable.addEntry(symb, _irom_addrs);
#ifdef DEBUG_OUTPUT
			outDebug << " => creating label '" << symb;
			outDebug << "' for rom[" << mySymbTable.getAddress(symb) << "]\n";
#endif // DEBUG_OUTPUT
			continue; // ignore L commands
		}

		if (mySymbSeeker.commandType() == A_COMMAND &&
			!myTranscriptor.isInteger(symb) &&
			!mySymbTable.contains(symb))
		{
			mySymbTable.addEntry(symb, _iram_addrs);
#ifdef DEBUG_OUTPUT
			outDebug << " => creating label '" << symb;
			outDebug << "' for memory[" << mySymbTable.getAddress(symb) << "]";
#endif // DEBUG_OUTPUT
			_iram_addrs++;
		}

#ifdef DEBUG_OUTPUT
		outDebug << std::endl;
#endif // DEBUG_OUTPUT

		// write in temp file
		outSeeker_tmp << mySymbSeeker.getCurrentCommand() << std::endl;

		_irom_addrs++;
		lineNum++;
	}
	outSeeker_tmp.close();

	// open the seeker_tmp
	Parser myParser(TMP_FILENAME);
	if (!myParser.isFileOpen()) return -1;

	std::ofstream outFile;
	outFile.open(fn_hack);

#ifdef DEBUG_OUTPUT
	outDebug << "\nTRANSLATING ASSEMBLY:\n\n";
#endif // DEBUG_OUTPUT

	lineNum = 0;
	while (myParser.hasMoreCommand())
	{
		myParser.advance();

		if (myParser.commandType() == cmdType::UNDEFINED) continue;

		std::string symb = myParser.symbol();
		std::string dest = myParser.dest();
		std::string comp = myParser.comp();
		std::string jump = myParser.jump();
		std::string type = "UNDEFINED";

		std::string bSymb = myTranscriptor.symb(symb);
		std::string bDest = myTranscriptor.dest(dest);
		std::string bComp = myTranscriptor.comp(comp);
		std::string bJump = myTranscriptor.jump(jump);

		// write output
		if (myParser.commandType() == C_COMMAND)
		{
			type = "C_COMMAND";
			outFile << "111" << bComp << bDest << bJump << std::endl;
#ifdef DEBUG_OUTPUT
			outDebug << "\t" << lineNum << " \t\t";
			outDebug << "111 " << bComp;
			outDebug << " " << bDest << " " << bJump << " => " << myParser.getCurrentCommand();
			outDebug << " (" << type << ")" << std::endl;
#endif // DEBUG_OUTPUT
		}
		else if (myParser.commandType() == A_COMMAND ||
				myParser.commandType() == L_COMMAND)
		{
			if (myTranscriptor.isInteger(symb))
			{
				type = "numeric A_COMMAND";
				outFile << "0" << bSymb << std::endl;
#ifdef DEBUG_OUTPUT
				outDebug << "\t" << lineNum << " \t\t";
				outDebug << "0 " << bSymb;
				outDebug << " => " << myParser.getCurrentCommand();
				outDebug << " (" << type << ")" << std::endl;
#endif // DEBUG_OUTPUT
			}
			else if (mySymbTable.contains(symb))
			{
				type = "symbolic A_COMMAND";
				symb = std::to_string(mySymbTable.getAddress(symb));
				bSymb = myTranscriptor.symb(symb);
				outFile << "0" << bSymb << std::endl;

				//std::cout << "symbolic A_COMMAND; replaced by @" << mySymbTable.getAddress(symb) << "\n";
				// Para la bebesita mas hermosha y divina de este
				// mundo, que tiene un gran curazons y ama mucho
				// a su bbito programador ocupado
#ifdef DEBUG_OUTPUT
				outDebug << "\t" << lineNum << " \t\t";
				outDebug << "0 " << bSymb;
				outDebug << " => " << myParser.getCurrentCommand();
				outDebug << " (" << type << "; replaced by @" << symb << ")" << std::endl;
#endif // DEBUG_OUTPUT
			}
			if (myParser.commandType() == L_COMMAND)
			{
				type = "L_COMMAND";
			}
		}


#ifdef DEBUG_MODE
		std::cout << ">> Current command is: " << myParser.getCurrentCommand() << "\n";
		std::cout << "\t-- Line num: " << lineNum << "\n";
		std::cout << "\t-- Type is: " << type << "\n";
		std::cout << "\t-- Symb is: " << symb << "\n";
		std::cout << "\t-- Dest is: " << dest << "\n";
		std::cout << "\t-- Comp is: " << comp << "\n";
		std::cout << "\t-- Jump is: " << jump << "\n";
		std::cout << "\t-- Binary symb is: " << bSymb << "\n";
		std::cout << "\t-- Binary dest is: " << bDest << "\n";
		std::cout << "\t-- Binary comp is: " << bComp << "\n";
		std::cout << "\t-- Binary jump is: " << bJump << "\n";
#endif // DEBUG_MODE

		lineNum++;
	}

	outFile.close();
#ifdef DEBUG_OUTPUT
	outDebug.close();
#else
	remove(TMP_FILENAME);
#endif // DEBUG_OUTPUT

	std::cout << "\n\t'" << fn_asm << "' was successfully assembled\n";

	return 0;
}