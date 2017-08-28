// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

@i
M = 1

// default value for R2
@R2
M = 0

(LOOP)
	// not condition for i <= R1 is i - R1 > 0
	@R1			// A = R1
	D = M		// D = RAM[R1]
	@i			// A = i
	D = M - D	// D = i - RAM[R1]

	@END		// A = END
	D; JGT		// if (i - R1 > 0) goto END


	// code block 1

	// add R0 to R2
	@R0			// A = R0
	D = M		// D = RAM[R0]
	@R2			// A = R2
	M = M + D	// RAM[R2] = RAM[R2] + RAM[R0]

	// increment 'i'
	@i			// A = i
	M = M + 1	// RAM[i] = RAM[i] + 1


	@LOOP
	0; JMP
(END)
	// code block 2
	@END
	0; JMP