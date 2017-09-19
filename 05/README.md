TODO: PONER LAS DIAGRAMAS DE LA CPU Y LA CPU-S2

# 1.1, 1.2)

    TYPE-A INSTRUCTION
    0111111111111111        @32767
                            A = 32767

    TYPE-C INSTRUCTION
    111 0 110000 010 000    D = A
                            D = 32767

    TYPE-A INSTRUCTION
    0000000000000001        @1
                            A = 1

    TYPE-C INSTRUCTION
    111 0 000010 010 000    D = D + A
                            D = 32767 + 1
                            D = 32768

    TYPE-A INSTRUCTION
    0000000000000000        @0
                            A = 0

    TYPE-C INSTRUCTION
    111 0 001100 001 000    M = D
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

---

#1.4) ¿El resultado del programa es el esperado? Explique la razón por la cual se presenta este resultado.

En la memoria `RAM[0]`se almacena un `-32768` Sin embargo si es el valor esperado, pues `CPU Emulator` interpreta los números binarios como si se tratara de complemento a 2.

---

# 2.1) Complete el circuito del tal manera que pueda implementar el set de instrucciones del computador Hack visto en clase.

A continuación una ilustración de la arquitectura implementada, las declaraciones `HDL` se encuentran en el directorio `report_src`.

---

# 2.2) Considere que la implementación de la CPU tiene un error. 
Dicho error ocurre al ejecutar la instrucción 0000 0011 0000 0110 que está almacenada en la posición de memoria 16. Luego de ejecutar la instrucción el programa continúa en la posición de memoria 32. Indique qué valores podrían tener los registros A, D y PC justo antes y justo después de ejecutar la instrucción.

WHEN EXECUTING **ROM[15]**

    A = 32
    D = A = 32
    PC = 15

WHEN EXECUTING  **ROM[16]**

    A = 774
    D = 32
    // inLoad = (where j1 will be replaced by j3 and viceversa)
    // making JUMP COND = JGE (if out >= 0 then JUMP)
    PC(in=outALU, load=inLoad) = 16

WHEN EXECUTING **ROM[32]**

    A = 774
    D = 32
    PC = 32

---

# 2.3) Implemente un circuito que genere el error anterior.

Para ver la implementación completa, revisar el archivo `report_src/ALU-ERROR.hdl`.
A continuación lo único que se hace es remplazar todas las coincidencias del bit de control `j1` por `j3`  y viceversa, así mismo se eliminó el checkeo de tipo de operación `i`.

    // MUX8WAY

    Xor(a=instruction[2], b=instruction[1], out=xorab);
    Xor(a=xorab, b=instruction[0], out=xoro);

    Mux(a=JGT, b=JEQ, sel=instruction[1], out=muxa);
    Mux(a=JLT, b=JUMP, sel=instruction[2], out=muxb);
    Mux(a=muxb, b=muxa, sel=xorab, out=muxabo);

    Xor(a=instruction[1], b=instruction[0], out=xorcd);

    Mux(a=JGE, b=JNE, sel=instruction[0], out=muxc);
    Mux(a=false, b=JLE, sel=instruction[1], out=muxd);
    Mux(a=muxd, b=muxc, sel=xorcd, out=muxcdo);

    Mux(a=muxcdo, b=muxabo, sel=xoro, out=oo);

    Or(a=instruction[2], b=instruction[1], out=aa);
    Or(a=aa, b=instruction[0], out=aaa);
    And(a=aaa, b=instruction[15], out=isJumpCond);

    Mux(a=false, b=oo, sel=isJumpCond, out=canJUMP);

    PC(in=ALUo, load=canJUMP, inc=true, reset=reset, out[0..14]=pc);

---

# 3.1) Invente una nueva instrucción para el procesador.

Se define la instrucción `swap` que se codificará de la siguiente manera.

    i s n a n n n n n n n n n n n n

Donde la `n` es cualquier valor (no relevante para la instrucción), mientras que `a` especifica si hacer `swap` entre el `registro D` y `M` o el `registro D` y el `registro A`

---

# 3.2) Describa en HDL y por medio de un diagrama el circuito que implemente dicha instrucción.

El HDL de la `CPU` con instrucciones `tipo-S` se encontrará en la carpeta `report_src` con el nombre `CPU-S2.hdl..`

# 3.3) Realice un programa ejemplo que ilustre el funcionamiento de la nueva instrucción
El siguiente programa de prueba se encuentra también en el directorio `report_src` bajo el nombre de `CPU-S2.tst`

    load CPU-S2.hdl,
    output-file CPU-S2.out,
    output-list time%S0.4.0 inM%D0.6.0 instruction%B0.16.0 reset%B2.1.2 outM%D1.6.0 writeM%B3.1.3 addressM%D0.5.0 pc%D0.5.0 DRegister[]%D1.6.1;
    
    
    set instruction %B0011000000111001, // @12345
    tick, output, tock, output;
    
    set instruction %B1110110000010000, // D=A
    tick, output, tock, output;
    
    set instruction %B0101101110100000, // @23456
    tick, output, tock, output;
    
    set instruction %B1010000000000000,
    tick, output, tock, output;
    
    set instruction %B1010000000000000,
    tick, output, tock, output;
    
    set reset 1;
    tick, output, tock, output;
    
    set instruction %B0111111111111111, // @32767
    set reset 0;
    tick, output, tock, output;

Es posible comprobar la compatibilidad de la mejora corriendo el `script` de prueba `CPU.tst`
