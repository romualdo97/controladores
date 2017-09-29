#pragma once

#include <iostream>
#include <string>
#include <map>

class SymbolTable
{
public:
	SymbolTable();
	void addEntry(std::string key, int val);
	bool contains(std::string symbol);
	int getAddress(std::string symbol);
	~SymbolTable();

private:
	std::map<std::string, int> symb_map;
};

