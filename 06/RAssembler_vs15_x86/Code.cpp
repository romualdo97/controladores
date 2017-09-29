#include "Code.h"

//===============================================

Code::Code()
{
	// DESTINE MAP
	dest_map["NULL"] = "000";
	dest_map["M"] = "001";
	dest_map["D"] = "010";
	dest_map["MD"] = "011";
	dest_map["A"] = "100";
	dest_map["AM"] = "101";
	dest_map["AD"] = "110";
	dest_map["AMD"] = "111";

	// COMPUTATION MAP
	// when a = 0
	comp_map["0"] = "0101010";
	comp_map["1"] = "0111111";
	comp_map["-1"] = "0111010";
	comp_map["D"] = "0001100";
	comp_map["A"] = "0110000";
	comp_map["!D"] = "0001101";
	comp_map["!A"] = "0110001";
	comp_map["-D"] = "0001111";
	comp_map["-A"] = "0110011";
	comp_map["D+1"] = "0011111";
	comp_map["A+1"] = "0110111";
	comp_map["D-1"] = "0001110";
	comp_map["A-1"] = "0110010";
	comp_map["D+A"] = "0000010";
	comp_map["D-A"] = "0010011";
	comp_map["A-D"] = "0000111";
	comp_map["D&A"] = "0000000";
	comp_map["D|A"] = "0010101";
	// when a = 1
	comp_map["M"] = "1110000";
	comp_map["!M"] = "1110001";
	comp_map["-M"] = "1110011";
	comp_map["M+1"] = "1110111";
	comp_map["M-1"] = "1110010";
	comp_map["D+M"] = "1000010";
	comp_map["D-M"] = "1010011";
	comp_map["M-D"] = "1000111";
	comp_map["D&M"] = "1000000";
	comp_map["D|M"] = "1010101";

	// JUMP MAP
	jump_map["NULL"] = "000";
	jump_map["JGT"] = "001";
	jump_map["JEQ"] = "010";
	jump_map["JGE"] = "011";
	jump_map["JLT"] = "100";
	jump_map["JNE"] = "101";
	jump_map["JLE"] = "110";
	jump_map["JMP"] = "111";
}

//===============================================

std::string Code::dest(std::string mnemonic)
{
	// is mnemonic into the map?
	if (dest_map.find(mnemonic) == dest_map.end()) return dest_map.find("NULL")->second;

	//std::string r(dest_map.find(mnemonic)->second);
	return dest_map.find(mnemonic)->second;
}

//===============================================

std::string Code::comp(std::string mnemonic)
{
	// is mnemonic into the map?
	if (comp_map.find(mnemonic) == comp_map.end()) return comp_map.find("0")->second;

	//std::string r(dest_map.find(mnemonic)->second);
	return comp_map.find(mnemonic)->second;
}

//===============================================

std::string Code::jump(std::string mnemonic)
{
	// is mnemonic into the map?
	if (jump_map.find(mnemonic) == jump_map.end()) return jump_map.find("NULL")->second;

	//std::string r(dest_map.find(mnemonic)->second);
	return jump_map.find(mnemonic)->second;
}

//===============================================

std::string Code::symb(std::string constant)
{
	// https://stackoverflow.com/questions/22746429/c-decimal-to-binary-converting
	if (!isInteger(constant)) return "";

	int n = std::stoi(constant);
	if (n > 32767) n = 32767;
	if (n < 0) n = 0;
	std::string r;
	//while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
	int i = 0;
	while (i < 15) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; i++; }
	return r;

}

//===============================================

bool Code::isInteger(const std::string & s)
{
	// https://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

//===============================================

Code::~Code()
{
}
