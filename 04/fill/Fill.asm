// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

// Whenever a key is pressed on the physical keyboard, its 16-bit ASCII code appears in RAM[24576]. When no key is pressed, the code 0 appears in this location.
// if (RAM[24576] > 0) key is pressed

// The screen’s contents are represented by an 8K memory map that starts at RAM address 16384 (0x4000).
// The Hack computer includes a black-and-white screen organized as 256 rows of 512 pixels per row
// Each row in the physical screen, starting at the screen’s top left corner, is represented in the RAM by 32 consecutive 16-bit words.

// int i = 0;
@i
M = 0
// while true
// while (i < 8192) OR
// while (i - 8192 < 0)
// NOT CONDITION IS (i - 8192 > 0)
// {
//		if (KBD == 0)
//		{
//  		*(SCREEN + i) = 0;
//			SCREEN[i] = 0;	
//		}
//		else
//		{
//  		*(SCREEN + i) = -1;
//			SCREEN[i] = -1;
//		}
//  	i += 1;
// }

(INFINITE_LOOP)

	(SCREEN_LOOP)
		@8192
		D = A
		@i
		D = M - D

		@END_SCREEN_LOOP
		D; JGT

		// IF	(KBD == 0)
		@KBD
		D = M
		@IF
		D; JEQ

		// ELSE
		@i
		D = M
		@SCREEN
		A = D + A
		M = -1

		@ENDIF
		0; JMP

		(IF) // KBD == 0
		@i
		D = M
		@SCREEN
		A = D + A
		M = 0

		(ENDIF)

		@i
		M = M + 1

		@SCREEN_LOOP
		0; JMP

	(END_SCREEN_LOOP)

	@i
	M = 0
	@INFINITE_LOOP
	0; JMP
