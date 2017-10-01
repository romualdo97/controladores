
> ### **PROJECT 06 |** RASSEMBLER
> Se garantiza qué este proyecto
>
> - Cumple el código de honor.
> - Reporta el [tiempo de dedicación](https://github.com/romualdo97/controladores/blob/master/06/report_src/time_report.pdf).


# RAssembler notes

La `R` de `RAssembler` significa `RomualdoAssembler` y es una versión de ensamblador para hack machines escrito en c++.
Este ensamblador expone su `API` de la forma propuesta en el libro `nand2tetris/chapter 06` pero ademas incorpora un `modulo` adicional para realizar validaciones de código `assembly` usando expresiones regulares, el modulo se ha decidido nombrar `RegexUtilities`. A continuación se dará una explicación general de la aplicación.

### **RAssembler.exe** myAsmProgram

Las archivos que genera `RAssembler` tienen el mismo nombre que el programa ensamblador de entrada pero con una extensión`.hack` ademas **no se debe escribir la extensión del archivo assembly en el argumento de entrada** dado que la aplicación supone internamente un archivo de extensión `.asm` como entrada.
La aplicación en general consta de dos partes, una primera que busca símbolos definidos por el usuario y los almacena en una tabla de símbolos y una segunda encargada de resolver dichos símbolos. 
Ademas la aplicación puede devolver el binario en dos formatos dependiendo de la variable de pre-compilacion `DEBUG_OUTPUT` declarada en el inicio del punto de entrada de la aplicación.


### **RAssembler.exe** in debug mode

Cuando la constante `DEBUG_OUTPUT` esta presente en el proceso de compilación el programa genera tres archivos, uno de ellos siendo oculto para el sistema operativo, razón por la cual no es visible sin la configuración adecuada. 
El primer archivo es el programa ensamblado, el segundo archivo con sufijo `_Debug` es el programa ensamblado con comentarios adicionales, **este programa no es apto para usarse en una hack machine** pero si es una excelente herramienta de detección de errores.
La función del archivo oculto es almacenar el programa de entrada formateado, de tal forma que no contenga ni espacios, ni comentarios ni operaciones no definidas en las `hack machines`. El archivo oculto es el punto de entrada de la segunda parte del ensamblador `RAssembler` encargado de traducir comandos validos del set de instrucciones de las `hack machines` a código binario *(Aunque el archivo de salido esta en representación ASCII)*

**Ejemplo de ensamblado**

    0000000000000000
	1110101010000000
	0111111111111111
	0000000000000000
	0000000000000001
	0000000000010000
	1110000010101111
	1110000010111010
	1110001111000111
	0000000000010001
	0000000000010010
	0011000001000010
	1110010101000000
	1110110001000000
	1110101010100110

**Ejemplo de ensamblado con respectivos comentarios**

    SEEKING SYMBOLS:

	0 		(IFCOND) => creating label 'IFCOND' for rom[0]
	0 		@IFCOND
	1 		A|D
	2 		@32767
	3 		@0
	4 		@1
	5 		@sdfsdf => creating label 'sdfsdf' for memory[16]
	6 		(Labl) => creating label 'Labl' for rom[6]
	6 		AM=D+A;JMP
	7 		AMD=D+A;JEQ
	8 		-D;JMP
	9 		@$_:$.123 => creating label '$_:$.123' for memory[17]
	10 		@a => creating label 'a' for memory[18]
	11 		@12354
	12 		(Symbol) => creating label 'Symbol' for rom[12]
	12 		D|A
	13 		($_:LABEL.) => creating label '$_:LABEL.' for rom[13]
	13 		!A
	14 		(LABEL) => creating label 'LABEL' for rom[14]
	14 		A=0;JLE
	15 		D=-D;JEQ

    TRANSLATING ASSEMBLY:

	0 		0 000000000000000 => @IFCOND (symbolic A_COMMAND; replaced by @0)
	1 		111 0101010 000 000 => A|D (C_COMMAND)
	2 		0 111111111111111 => @32767 (numeric A_COMMAND)
	3 		0 000000000000000 => @0 (numeric A_COMMAND)
	4 		0 000000000000001 => @1 (numeric A_COMMAND)
	5 		0 000000000010000 => @sdfsdf (symbolic A_COMMAND; replaced by @16)
	6 		111 0000010 101 111 => AM=D+A;JMP (C_COMMAND)
	7 		111 0000010 111 010 => AMD=D+A;JEQ (C_COMMAND)
	8 		111 0001111 000 111 => -D;JMP (C_COMMAND)
	9 		0 000000000010001 => @$_:$.123 (symbolic A_COMMAND; replaced by @17)
	10 		0 000000000010010 => @a (symbolic A_COMMAND; replaced by @18)
	11 		0 011000001000010 => @12354 (numeric A_COMMAND)
	12 		111 0010101 000 000 => D|A (C_COMMAND)
	13 		111 0110001 000 000 => !A (C_COMMAND)
	14 		111 0101010 100 110 => A=0;JLE (C_COMMAND)
	15 		111 0001111 010 010 => D=-D;JEQ (C_COMMAND)

### **RAssembler.exe** in release mode

`RAssembler` en **release mode** solo devuelve un archivo de salida que es el programa `assembly` original ensamblado, ademas `RAssembler` al finalizar la ejecución borra el archivo oculto que almacena el programa 'assembly' original formateado.
