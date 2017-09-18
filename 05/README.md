
# 1.1, 1.2)

	TYPE-A INSTRUCTION
	0111111111111111		@32767
							A = 32767

	TYPE-C INSTRUCTION
	111 0 110000 010 000	D = A
							D = 32767

	TYPE-A INSTRUCTION
	0000000000000001		@1
							A = 1

	TYPE-C INSTRUCTION
	111 0 000010 010 000	D = D + A
							D = 32767 + 1
							D = 32768

	TYPE-A INSTRUCTION
	0000000000000000		@0
							A = 0

	TYPE-C INSTRUCTION
	111 0 001100 001 000	M = D
							M[0] = 32768

---
	
	// Solution name: AsmToC, file name: main.cpp
	
	#define MEM (*(volatile __int16*)0x0u)
	
	int main(void)
	{
		MEM = 32767 + 1;
		return 0;
	}
	
    /*
    tested with
    cl.exe -v -> 19.10.25019 for x86
    result:
    
    Excepción producida en 0x00BE1AA3 en AsmToC.exe: 0xC0000005: Infracción de acceso al escribir en la ubicación 0x00000000.
    */

---

# 1.3) ¿Qué hace el programa?
El programa le suma a `32767` un `1` y almacena el resultado en la dirección `0x0` de la memoria `RAM`.

#1.4) ¿El resultado del programa es el esperado? Explique la razón por la cual se presenta este resultado.

En la memoria `RAM[0]`se almacena un `-32768` Sin embargo si es el valor esperado, pues `CPU Emulator` interpreta los números binarios como si se tratara de complemento a 2.
