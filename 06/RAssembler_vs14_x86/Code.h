#pragma once

#include <iostream>
#include <sstream>
#include <map>

class Code
{
public:
	Code();

	std::string dest(std::string mnemonic);
	std::string comp(std::string mnemonic);
	std::string jump(std::string mnemonic);
	std::string symb(std::string constant);
	bool isInteger(const std::string & s);

	~Code();
private:
	std::map<std::string, std::string> dest_map;
	std::map<std::string, std::string> comp_map;
	std::map<std::string, std::string> jump_map;
};

