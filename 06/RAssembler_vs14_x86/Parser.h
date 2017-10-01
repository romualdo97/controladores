#pragma once

// c standard libs
#include <stdio.h>
#include <stdlib.h>

// needed for stream operations
#include <iostream>
#include <fstream>
#include <sstream>

// regex dependencies
#include <regex>
#include "RegexUtilities.h"

// precompilation constans
#define AUTOVALIDATE
#define CURRENT_COMMAND_BUFF_SIZE 256 // how many character for line?

// command types
enum cmdType
{
	A_COMMAND, C_COMMAND, L_COMMAND, UNDEFINED
};

/*
Encapsulates access to the input code. Reads an assembly language command,
parses it, and provides convenient access to the command’s components
(fields and symbols). In addition, removes all white space and comments.
*/
class Parser
{
public:
	/*Opens the input file/stream and
	gets ready to parse it.*/
	Parser(char const *filename);

	/*Are there more commands in the
	input ?*/
	bool hasMoreCommand();

	/*Reads the next command from
	the input and makes it the current
	command. Should be called only
	if hasMoreCommands() is true.
	Initially there is no current command.*/
	void advance();

	/*Returns the type of the current
	command:*/
	cmdType commandType();

	/*Returns the symbol or decimal
	Xxx of the current command
	@Xxx or (Xxx). Should be called
	only when commandType() is
	A_COMMAND or L_COMMAND.*/
	std::string symbol();

	/*Returns the dest mnemonic in
	the current C-command (8 possibilities).
	Should be called only
	when commandType() is C_COMMAND.*/
	std::string dest();

	/*Returns the comp mnemonic in
	the current C-command (28 possibilities).
	Should be called only
	when commandType() is
	C_COMMAND.*/
	std::string comp();

	/*Returns the jump mnemonic in
	the current C-command (8 possibilities).
	Should be called only
	when commandType() is
	C_COMMAND.*/
	std::string jump();

	bool isFileOpen();
	std::string getCurrentCommand();

	~Parser();

private:
	RegexUtilities rgxUtils;
	bool isFileLoaded = false;
	std::stringstream asmCode;
	//std::string asmCode_str;
	//char const *asmCode_cstr;
	char currentCommand[CURRENT_COMMAND_BUFF_SIZE];
};

