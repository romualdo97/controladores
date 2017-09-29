#include "RegexUtilities.h"



RegexUtilities::RegexUtilities()
{
	// UTILITIES
	symbol_rgx = "[\$_\.:a-z|A-Z|0-9]+";
	dest_rgx = "\=";

	// TYPE-A
	TYPE_As_rgx = "^@[a-z|A-Z|_\.\$:][[:w:]_\.\$:]*$";
	TYPE_A_rgx = "^@[[:digit:]]*$";

	// TYPE-C
	TYPE_C_comp3_rgx = "^[DAM][&\|\+\-][DAM1]$"; // ERROR CON OR
	TYPE_C_comp2_rgx = "^[\-!DAM][DAM1]$";
	TYPE_C_comp1_rgx = "^[DAM01]$";
	TYPE_C_destComp3_rgx = "^[DAM][DAM]?[DAM]?\=[DAM][&|\+\-][DAM1]$";
	TYPE_C_destComp2_rgx = "^[DAM][DAM]?[DAM]?\=[\-!DAM][DAM1]$";
	TYPE_C_destComp1_rgx = "^[DAM][DAM]?[DAM]?\=[DAM01]$";
	TYPE_C_comp3Jmp_rgx = "^[DAM][&|\+\-][DAM1];J[MGEGLN][PTQE]$";
	TYPE_C_comp2Jmp_rgx = "^[\-!DAM][DAM1];J[MGEGLN][PTQE]$";
	TYPE_C_comp1Jmp_rgx = "^[DAM01];J[MGEGLN][PTQE]$";
	TYPE_C_destComp3Jmp_rgx = "^[DAM][DAM]?[DAM]?\=[DAM][&|\+\-][DAM1];J[MGEGLN][PTQE]$";
	TYPE_C_destComp2Jmp_rgx = "^[DAM][DAM]?[DAM]?\=[\-!DAM][DAM1];J[MGEGLN][PTQE]$";
	TYPE_C_destComp1Jmp_rgx = "^[DAM][DAM]?[DAM]?\=[DAM01];J[MGEGLN][PTQE]$";
	std::string bbita("Bebita te amo mucho, recides dentro del corazon de RAsembler 1.0");

	// TYPE-L
	TYPE_L_rgx = "^[\(][a-z|A-Z|_\.\$:][[:w:]_\.\$:]*[\)]$";
}

bool RegexUtilities::isComp_op(char *str)
{
	return std::regex_match(str, TYPE_C_comp3_rgx) ||
		std::regex_match(str, TYPE_C_comp2_rgx) ||
		std::regex_match(str, TYPE_C_comp1_rgx);
}

bool RegexUtilities::isDestComp_op(char *str)
{
	return std::regex_match(str, TYPE_C_destComp3_rgx) ||
		std::regex_match(str, TYPE_C_destComp2_rgx) ||
		std::regex_match(str, TYPE_C_destComp1_rgx);
}

bool RegexUtilities::isCompJmp_op(char *str)
{
	return std::regex_match(str, TYPE_C_comp3Jmp_rgx) ||
		std::regex_match(str, TYPE_C_comp2Jmp_rgx) ||
		std::regex_match(str, TYPE_C_comp1Jmp_rgx);
}

bool RegexUtilities::isDestCompJmp_op(char *str)
{
	return std::regex_match(str, TYPE_C_destComp3Jmp_rgx) ||
		std::regex_match(str, TYPE_C_destComp2Jmp_rgx) ||
		std::regex_match(str, TYPE_C_destComp1Jmp_rgx);
}

bool RegexUtilities::isOnlyComp_op(char *str)
{
	return isComp_op(str) &&
		!isCompJmp_op(str) &&
		!isDestComp_op(str) &&
		!isDestCompJmp_op(str);
}

bool RegexUtilities::isOnlyCompJmp_op(char *str)
{
	return !isComp_op(str) &&
		isCompJmp_op(str) &&
		!isDestComp_op(str) &&
		!isDestCompJmp_op(str);
}

bool RegexUtilities::isOnlyDestComp_op(char *str)
{
	return !isComp_op(str) &&
		!isCompJmp_op(str) &&
		isDestComp_op(str) &&
		!isDestCompJmp_op(str);
}

bool RegexUtilities::isOnlyDestCompJmp_op(char *str)
{
	return !isComp_op(str) &&
		!isCompJmp_op(str) &&
		!isDestComp_op(str) &&
		isDestCompJmp_op(str);
}

bool RegexUtilities::isTypeA(char *str)
{
	return std::regex_match(str, TYPE_A_rgx) ||
		std::regex_match(str, TYPE_As_rgx);
}

bool RegexUtilities::isTypeC(char *str)
{
	return isComp_op(str) || isDestComp_op(str) || isCompJmp_op(str) || isDestCompJmp_op(str);
}

bool RegexUtilities::isTypeL(char *str)
{
	return std::regex_match(str, TYPE_L_rgx);
}

RegexUtilities::~RegexUtilities()
{
}
