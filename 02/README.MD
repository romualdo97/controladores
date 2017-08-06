> ### **PROJECT 02 |** BUILDING ALU
> Se garantiza qué este proyecto
>
> - Cumple el código de honor.
> - Cumple en su totalidad el listado de conceptos.
> - Explica cada uno de los circuitos.
> - Tiene el diagrama de compuertas de cada circuito.
> - Explica el código de cada circuito
> - Diligenció la [auto-evaluación](https://cdn.rawgit.com/romualdo97/controladores/5282adb6/02/report_src/Autoevaluacion.xlsx).
> - Reporta el [tiempo de dedicación](https://github.com/romualdo97/controladores/blob/master/02/report_src/project_report.pdf).

LISTADO DE CONCEPTOS
===================

## 1.A ) Exprese en complemento a 2 con 8 bits en base 2 los siguientes números: 1, 0, -1, -128, 127, 128, -130

Base 10  | Base 2
-------- | ---
1		 | 0 0 0 0 0 0 0 1
0		 | 0 0 0 0 0 0 0 0
-1       | 1 1 1 1 1 1 1 1
-128	 | 1 0 0 0 0 0 0 0
127		 | 0 1 1 1 1 1 1 1
128      | **Not in Range**
-130     | **Not in Range**


## 1.B ) ¿Que tienen en común las representaciones del número -1 con 8 y 16 bits?

En ocho bits -1 se representa con una secuencia de 8 unos seguidos y en 16 es una secuencia de 16 unos seguidos.

-1 en 8 bits    | -1 en 16 bits
--------        | ---
1 1 1 1 1 1 1 1 | 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

## 1.C ) ¿Cuál es el rango de números enteros con signo que se puede representar en complemento a 2 con 8, 16 y 32 bits?

Número de bits  | Rango
-------- | ---
8		 | [-128, 127]
16		 | [-32768, 32767]
32       | [-4294967296, 4294967295]

## 1.D ) Haga una tabla con cuatro columnas. En la primer columna escriba los número en base 10 del 0 al 15, en la segunda lo propio en base 2, en la tercera igualmente pero en base 16 y en la cuarta en complemento a 2 con 4 bits.

| Base 10 | Base 2 | Base 16 |  Complemento a 2 con 4 bits
| ------- | ---- | --- | ---
| 0| 0 |  0    | 0000
| 1| 1 |  1   |0001
| 2| 10    |  2  |0010
| 3| 11 |  3    | 0011
| 4| 100 |  4   |0100
| 5| 101    |  5|0101
| 6| 110|  6    | 0110
| 7| 111   |  7|0111
| 8| 1000|  8|1000
| 9| 1001|  9    | 1001
| 10| 1010 |  A   |1010
| 11| 1011    |  B|1011
| 12| 1100|  C| 1100
| 13| 1101 |  D|1101
| 14| 1110    |  E|1110
| 15| 1111|  F| 1111

## 1.E ) Represente los números -1 y 2 en complemento a 2 de 4 bits en base 2. Sume los números. ¿Cuál es el resultado?

    1111 + 0010 = 0001 // -1 + 2 = 1 (en complemento a 2)

## 1.F ) Escriba los números 15 y 2 en base 2 con 4 bits. Sume los números. ¿Cuál es el resultado?

	1111 + 0010 = 0001 // 15 + 2
	
## 1.G ) ¿Qué relación encuentra entre los puntos 5 y 6? ¿Qué puede concluir?

El número 15 binario se usa para representar el -1 en complemento a 2.

## 1.H ) ¿Por qué razón cree usted, en base a lo anterior, que los computadores utilizan la representación en complemento a 2? Justifique su respuesta en relación a la operación suma.

Una de las razones de utilizar complemento a 2 es la capacidad de representar restas usando sumas.

## 1.I ) ¿Cuál es la diferencia entre un Half adder y un full adder?

El half adder tiene dos buses de entrada mientras el full adder tres, siendo el bus adicional de gran utilidad para considerar el termino carry  de otro half adder cualquiera. Dicha funcionalidad permite encadenar muchos half adders.

## 1.J ) ¿Qué significa que una suma ha generado un carry?

La suma no puede ser representada usando la misma cantidad de dígitos de los sumandos.

## 1.K ) En relación a la unidad aritmético lógica implementada, muestre un ejemplo que ilustre cada una de las operaciones que ésta puede realizar. Para ello, muestre en un diagrama en bloques de la ALU los valores intermedios de cada uno de los chips que la componen.

## FUNCIÓN ZERO

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/a_mux_fun_zero.png)

## FUNCIÓN ONE

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/b_mux_fun_one.png)

## FUNCIÓN -1

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/c_mux_fun_minus_one.png)

El output es una secuencia de bits de longitud n representando el uno, donde n el número de bits de la arquitectura. Sin embargo la siguiente imagen solo puede representar un único bit de dicha secuencia de bits.

## FUNCIÓN X

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/d_mux_fun_x.png)

## FUNCIÓN Y

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/e_mux_fun_y.png)

## FUNCIÓN !X

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/f_mux_fun_notx.png)

## FUNCIÓN !Y

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/g_mux_fun_noty.png)

## FUNCIÓN -X

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/fa_mux_fun_minus_x.png)

## FUNCIÓN Y

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/e_mux_fun_y.png)

El esquema solo puede representar una entrada de un bit, y el bit menos significativo de la salida. Evaluando la función en 4 bits f(x = 0001) = 1111, tenemos que el bit menos significativo del resultado es efectivamente un uno. Sin embargo lo anteriormente mencionado es solo una prueba parcial del correcto funcionamiento de la ALU, para efectos prácticos consideraremos que la evaluación es correcta en su totalidad aunque no tengamos evidencia de los otros tres bits de la salida ni de la entrada.

## FUNCIÓN -Y

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/ga_mux_fun_minus_y.png)

Las limitaciones del esquema no permiten evidenciar un funcionamiento completo de la ALU.

## FUNCIÓN X+1

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/h_mux_fun_x_plus_one.png)

*f(x = 0) = 1*

## FUNCIÓN Y+1

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/i_mux_fun_y_plus_one.png)

*f(y = 0) = 1*

## FUNCIÓN X-1

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/j_mux_fun_x_minus_one.png)

*f(x = 1) = 0*

## FUNCIÓN Y-1

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/k_mux_fun_y_minus_one.png)

*f(y = 1) = 0*

## FUNCIÓN X+Y

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/l_mux_fun_x_plus_y.png)

*f(x = 0, y = 1) = 1*

## FUNCIÓN X-Y

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/9346afb9/02/report_src/imgs/mux_funcs/m_mux_fun_x_minus_y.png)

*f(x = 1, y = 1) = 0*

## FUNCIÓN Y-X

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/cf357c21/02/report_src/imgs/mux_funcs/m_mux_fun_y_minus_x.png)

*f(x = 1, y = 1) = 0*

## FUNCIÓN X & Y

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/cf357c21/02/report_src/imgs/mux_funcs/n_mux_fun_x_and_y.png)


## FUNCIÓN X | Y

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/cf357c21/02/report_src/imgs/mux_funcs/o_mux_fun_x_or_y.png)

---

DESCIFRANDO LA ALU
===================

Demuestre cómo es posible que la ALU pueda realizar con el hardware que tenemos las siguientes operaciones: *-X, X+1, X-Y, X or Y*

## DEMOSTRANDO -X

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/0166bc61/02/report_src/imgs/descifrando_alu/a_mux_fun_minus_x.png)

---

![enter image description here](https://latex.codecogs.com/gif.latex?-x&space;=&space;%5Csim&space;%28x&space;&plus;&space;%28-1%29%29%29)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7Bx-1%7D=%5Csim&space;%28x-1%29)

![enter image description here](https://latex.codecogs.com/gif.latex?C_2%5E%7Bx-1%7D=C_1%5E%7Bx-1%7D&space;&plus;&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_2%5E%7Bx-1%7D=2%5En&space;-&space;%28x-1%29)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7Bx-1%7D=C_2%5E%7Bx-1%7D&space;-&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7Bx-1%7D=2%5En&space;-&space;%28x-1%29&space;-&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7Bx-1%7D=2%5En&space;-x&space;&plus;1&space;-&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7Bx-1%7D=2%5En&space;-&space;x&space;=&space;C_2%5E%7Bx%7D)


## DEMOSTRANDO X+1

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/0166bc61/02/report_src/imgs/descifrando_alu/b_mux_fun_x_plus_one.png)

---

![a](https://latex.codecogs.com/gif.latex?x&plus;1=%5Csim%28%5Csim&space;x&plus;%28-1%29%29)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7B%5Csim&space;x-1%7D&space;=&space;%5Csim&space;%28%5Csim&space;x&space;-&space;1%29)

![enter image description here](https://latex.codecogs.com/gif.latex?C_2%5E%7B%5Csim&space;x-1%7D&space;=&space;C_1%5E%7B%5Csim&space;x-1%7D&space;&plus;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_2%5E%7B%5Csim&space;x-1%7D&space;=&space;2%5En&space;-&space;%28%5Csim&space;x&space;-&space;1%29)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7B%5Csim&space;x-1%7D&space;=&space;C_2%5E%7B%5Csim&space;x-1%7D&space;&plus;&space;1)

---

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7Bx%7D&space;=&space;%5Csim&space;x)

![enter image description here](https://latex.codecogs.com/gif.latex?C_2%5E%7Bx%7D&space;=&space;C_1%5E%7Bx%7D&space;&plus;&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7Bx%7D&space;=&space;C_2%5E%7Bx%7D&space;-&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_2%5E%7Bx%7D&space;=&space;2%5En-x)

---

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7B%5Csim&space;x&space;-&space;1%7D&space;=&space;2%5En&space;-&space;%28C_2%5E%7Bx%7D&space;-&space;1&space;-&space;1%29&space;-&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7B%5Csim&space;x&space;-&space;1%7D&space;=&space;2%5En&space;-2%5En&space;&plus;&space;x&space;&plus;&space;2&space;-&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7B%5Csim&space;x&space;-&space;1%7D&space;=&space;x&space;&plus;&space;1)

## DEMOSTRANDO X-Y

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/0166bc61/02/report_src/imgs/descifrando_alu/c_mux_fun_x_minus_y.png)

---

![enter image description here](https://latex.codecogs.com/gif.latex?x-y&space;=&space;%5Csim&space;%28%5Csim&space;x&space;&plus;&space;y%29)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7B%5Csim&space;x&space;&plus;&space;y%7D&space;=&space;%5Csim&space;%28%5Csim&space;x&space;&plus;&space;y%29)

![enter image description here](https://latex.codecogs.com/gif.latex?C_2%5E%7B%5Csim&space;x&space;&plus;&space;y%7D&space;=&space;C_1%5E%7B%5Csim&space;x&space;&plus;&space;y%7D&space;&plus;&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_2%5E%7B%5Csim&space;x&space;&plus;&space;y%7D&space;=&space;2%5En&space;-&space;%28%5Csim&space;x&space;&plus;&space;y%29)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7B%5Csim&space;x&space;&plus;&space;y%7D&space;=&space;2%5En&space;-&space;%28%5Csim&space;x&space;&plus;&space;y%29&space;-&space;1)

---

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5Ex&space;=&space;%5Csim&space;x)

![enter image description here](https://latex.codecogs.com/gif.latex?C_2%5Ex&space;=&space;C_1%5Ex&space;&plus;&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_2%5Ex&space;=&space;2%5En&space;-&space;x)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5Ex&space;=&space;2%5En&space;-&space;x&space;-&space;1)

---

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7B%5Csim&space;x&space;&plus;&space;y%7D&space;=&space;2%5En&space;-&space;%282%5En&space;-&space;x&space;-&space;1&space;&plus;&space;y%29&space;-&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7B%5Csim&space;x&space;&plus;&space;y%7D&space;=&space;2%5En&space;-2%5En&space;&plus;&space;x&space;&plus;&space;1&space;-&space;y&space;-&space;1)

![enter image description here](https://latex.codecogs.com/gif.latex?C_1%5E%7B%5Csim&space;x&space;&plus;&space;y%7D&space;=&space;x&space;-&space;y)

## DEMOSTRANDO X OR Y

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/0166bc61/02/report_src/imgs/descifrando_alu/d_mux_fun_x_or_y.png)

Se sabe por la ley de Morgan qué:

    Not(A & B) = Not(A) | Not(B)
    Not(A | B) = Not(A) & Not(B)

De tal forma:

    Not(x) & Not(y) = Not(x | y)
    Not(Not(x | y)) = x | y

EXPLICACIÓN DE CHIPS
===================

## HALF-ADDER

Suma dos buses de *n bit*s y devuelve el resultado junto al **carry**.

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/0166bc61/02/report_src/imgs/a_half_adder.png)

## FULL-ADDER

Suma tres buses de *n bits* (el bus adicional se usa como ***carry in***) y devuelve el respectivo resultado junto al ***carry***.

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/0166bc61/02/report_src/imgs/b_full_adder.png)

## ADDER

Suma dos buses de *n bits*, de tal forma que cada bus represente un número con signo en complemento a 2. Por lo tanto la función Adder posee solo una salida que representa el resultado de la suma sin tener en cuenta el overflow.

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/0166bc61/02/report_src/imgs/c_adder.png)

## INCREMENTER

Suma a un bus de ***n bits*** un 1 usando representación de signos con complemento a 2.

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/0166bc61/02/report_src/imgs/d_incrementer.png)

## ALU

Permite realizar operaciones aritméticas y lógicas sobre dos buses de ***n bits*** dependiendo de la configuración establecida en los bits de control.

![enter image description here](https://cdn.rawgit.com/romualdo97/controladores/0166bc61/02/report_src/imgs/e_alu.png)
