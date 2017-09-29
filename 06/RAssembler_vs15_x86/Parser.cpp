#include "Parser.h"

//===============================================

Parser::Parser(char const *filename)
{

	std::fstream asmFile;

	// ensure ifstream objects can throw exceptions:
	asmFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	/*
	Stream is a serial representation of data (no random-access capabilities)
		stringstream
			uses stringbuf
				that inherites from streambuf
		fstream
			uses filebuf
				that inherites from streambuf
	*/
	try
	{
		// open asm file
		asmFile.open(filename);
		asmCode << asmFile.rdbuf();
		asmFile.close();
		isFileLoaded = true;
	}
	catch (std::ifstream::failure e)
	{
		printf("\nERROR::PARSER::NOT_ASM_FILE\n");
		printf("\tAssembly file %s not succesfully loaded.\n", filename);
	}

}

//===============================================

bool Parser::hasMoreCommand()
{
	// is 'end of file' reached
	// note that eof is represented by a -1 and not
	// an ASCII NULL char 0
	return !asmCode.eof();
}

//===============================================

void Parser::advance()
{

	if (!hasMoreCommand())
	{
		//printf("There are no more commands\n");
		return;
	}

	currentCommand[0] = 0; // restart buffer
	//int c = asmCode.get();
	int c = asmCode.get();
	int i = 0;
	// c != NewLine & c != EndOfFile
	while (c != 0x0A && c != -1 && i < CURRENT_COMMAND_BUFF_SIZE)
	{
		// printf("%d : ", c);
		// ignore spaces \s
		// 0x20 == space == 32
		if (c == 0x20 || c == 0x09)
		{
			c = asmCode.get();
			continue;
		}
		currentCommand[i] = c;
		//printf("%s\n", currentCommand);
		c = asmCode.get();
		i++;
	}
	currentCommand[i] = 0;

	// prepare for delete comments if are
	std::stringstream noComments;

	std::string str(currentCommand);
	std::regex comments_regex("\/\/.*"); // (\/\/.*)
	std::smatch r;

	// line has comments?
	if (std::regex_search(str, r, comments_regex))
	{
		noComments << r.prefix() << std::endl;
		noComments.getline(currentCommand, CURRENT_COMMAND_BUFF_SIZE);
	}

	// printf("%s\n", currentCommand);
}

//===============================================

cmdType Parser::commandType()
{
	// ECMAScript regex sintax: http://www.cplusplus.com/reference/regex/ECMAScript/

	if (rgxUtils.isTypeA(currentCommand))
	{
		//printf("A_COMMAND detected\n");
		return cmdType::A_COMMAND;
	}

	//if (isComp_operation || isDestComp_operation || isCompJmp_operation || isDestCompJmp_operation)
	if (rgxUtils.isTypeC(currentCommand))
	{
		//printf("C_COMMAND detected\n");
		return cmdType::C_COMMAND;
	}


	if (rgxUtils.isTypeL(currentCommand))
	{
		//printf("L_COMMAND detected\n");
		return cmdType::L_COMMAND;
	}

	//printf("UNDEFINED_COMMAND detected\n");
	return cmdType::UNDEFINED;
}

//===============================================

std::string Parser::symbol()
{
	// validations
#ifdef AUTOVALIDATE
	if (commandType() != cmdType::A_COMMAND && commandType() != cmdType::L_COMMAND)
	{
		return "";
	}
#endif // AUTOVALIDATE

	std::string str(currentCommand);
	std::smatch r;

	if (!std::regex_search(str, r, rgxUtils.symbol_rgx)) return "";

	//printf("%s\n", currentCommand);
	str = r.str();
	//std::cout << "Symbol value is: " << str << std::endl;
	//printf("Simbol is: %s\n", str.c_str());
	return str;
}

//===============================================

std::string Parser::dest()
{
#ifdef AUTOVALIDATE
	if (commandType() != cmdType::C_COMMAND)
	{
		return "";
	}
#endif // AUTOVALIDATE

	std::string str(currentCommand);
	std::smatch r;

	if (!std::regex_search(str, r, rgxUtils.dest_rgx)) return "";
	//printf("%s\n", currentCommand);
	str = r.prefix();
	return str;
}

//===============================================

std::string Parser::comp()
{
#ifdef AUTOVALIDATE
	if (commandType() != cmdType::C_COMMAND)
	{
		return "";
	}
#endif // AUTOVALIDATE

	std::string str(currentCommand);
	std::smatch r;

	if (rgxUtils.isOnlyComp_op(currentCommand))
	{
		str = currentCommand;
	}
	else if (rgxUtils.isOnlyCompJmp_op(currentCommand))
	{
		std::regex rgx(";");

		std::regex_search(str, r, rgx);
		str = r.prefix();

		/*if (std::regex_search(str, r, rgx))
		{
			//std::cout << "comp + jmp operation : ";
			str = r.prefix();
			//std::cout << str << std::endl;
		}*/
	}
	else if (rgxUtils.isOnlyDestComp_op(currentCommand))
	{
		std::regex rgx("\=");

		std::regex_search(str, r, rgx);
		str = r.suffix();

		/*if (std::regex_search(str, r, rgx))
		{
			//std::cout << "dest + comp operation : ";
			str = r.suffix();
			//std::cout << str << std::endl;
		}*/
	}
	else if (rgxUtils.isOnlyDestCompJmp_op(currentCommand))
	{
		std::regex semicolon_rgx(";");
		std::regex eq_rgx("\=");

		std::regex_search(str, r, eq_rgx);
		str = r.suffix();
		std::regex_search(str, r, semicolon_rgx);
		str = r.prefix();

		/*if (std::regex_search(str, r, eq_rgx))
		{
			str = r.suffix();
			if (std::regex_search(str, r, semicolon_rgx))
			{
				//std::cout << "dest + comp + jmp operation : ";
				str = r.prefix();
				//std::cout << str << std::endl;
			}

		}*/
	}

	return str;
}

//===============================================

std::string Parser::jump()
{
#ifdef AUTOVALIDATE
	if (commandType() != cmdType::C_COMMAND)
	{
		return "";
	}
#endif // AUTOVALIDATE

	std::string str(currentCommand);
	std::smatch r;

	if (!rgxUtils.isCompJmp_op(currentCommand) && !rgxUtils.isDestCompJmp_op(currentCommand))
		return "";

	std::regex rgx(";");
	std::regex_search(str, r, rgx);
	str = r.suffix();

	return str;

}

//===============================================

bool Parser::isFileOpen()
{
	return isFileLoaded;
}

//===============================================

std::string Parser::getCurrentCommand()
{
	std::string str(currentCommand);
	return str;
}

//===============================================

Parser::~Parser()
{
}
