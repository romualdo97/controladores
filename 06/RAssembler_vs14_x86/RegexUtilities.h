#include <regex>

#pragma once
class RegexUtilities
{
public:
	// METHODS
	RegexUtilities();

	bool isComp_op(char *str);
	bool isDestComp_op(char *str);
	bool isCompJmp_op(char *str);
	bool isDestCompJmp_op(char *str);

	bool isOnlyComp_op(char *str);
	bool isOnlyDestComp_op(char *str);
	bool isOnlyCompJmp_op(char *str);
	bool isOnlyDestCompJmp_op(char *str);

	bool isTypeA(char *str);
	bool isTypeC(char *str);
	bool isTypeL(char *str);
	~RegexUtilities();

	// ATTRIBUTES

	// TYPE-A EXPRESSION VALIDATION
	// ^@[a-z|A-Z|_\.\$:][\w_\.\$:]*$
	// ^@[a-z|A-Z|_\.\$:][[:w:]_\.\$:]*$
	std::regex TYPE_As_rgx;
	// ^@\d*$
	// ^@[:d:]*$
	// ^@[[:digit:]]$
	std::regex TYPE_A_rgx; // type A expression using constant

	// TYPE-C EXPRESION VALIDATION

	// possible operation combinations
	// comp
	// dest + comp
	// comp + jmp
	// dest + comp + jmp


	// there is computation with mnemonic of 3 bytes?
	// ^[DAM][\+\-&|][DAM1]$
	std::regex TYPE_C_comp3_rgx;
	// there is computation with mnemonic of 2 bytes?
	// ^[\-!DAM][DAM1]$
	std::regex TYPE_C_comp2_rgx;
	// there is computation with mnemonic of 1 byte?
	// ^[DAM01]$
	std::regex TYPE_C_comp1_rgx;

	// ^[DAM][DAM]?[DAM]?\=$ -> just dest operation
	// there is dest + comp_3byte operation?
	std::regex TYPE_C_destComp3_rgx;
	// there is dest + comp_2byte operation?
	std::regex TYPE_C_destComp2_rgx;
	// there is dest + comp_1byte operation?
	std::regex TYPE_C_destComp1_rgx;

	// ^;J[MGEGLN][PTQE]$ -> just jmp operation
	// there is comp_3byte + jmp operation?
	std::regex TYPE_C_comp3Jmp_rgx;
	// there is comp_2byte + jmp operation?
	std::regex TYPE_C_comp2Jmp_rgx;
	// there is comp_1byte + jmp operation?
	std::regex TYPE_C_comp1Jmp_rgx;

	// there is dest + comp3_byte + jmp operation?
	std::regex TYPE_C_destComp3Jmp_rgx;
	// there is dest + comp2_byte + jmp operation?
	std::regex TYPE_C_destComp2Jmp_rgx;
	// there is dest + comp1_byte + jmp operation?
	std::regex TYPE_C_destComp1Jmp_rgx;

	// TYPE TYPE-L EXPRESSION VALIDATION
	std::regex TYPE_L_rgx;

	// UTILITIES
	std::regex symbol_rgx;
	std::regex dest_rgx;
};

