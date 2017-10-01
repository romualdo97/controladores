#include "SymbolTable.h"



SymbolTable::SymbolTable()
{
	symb_map["SP"] = 0;
	symb_map["LCL"] = 1;
	symb_map["ARG"] = 2;
	symb_map["THIS"] = 3;
	symb_map["THAT"] = 4;
	symb_map["SCREEN"] = 16384;
	symb_map["KBD"] = 24576;
	std::string r("r");
	for (int i = 0; i < 15; i++)
	{
		symb_map[r + std::to_string(i)] = i;
	}
}

void SymbolTable::addEntry(std::string key, int val)
{
	symb_map.insert( std::pair<std::string, int>(key, val) );
}

bool SymbolTable::contains(std::string symbol)
{
	if (symb_map.find(symbol) == symb_map.end()) return false;
	return true;
}

int SymbolTable::getAddress(std::string symbol)
{
	if (!contains(symbol)) return -1;
	return symb_map.find(symbol)->second;
}

SymbolTable::~SymbolTable()
{
}
