> ### **PROJECT 03 |** BUILDING MEMORY
> Se garantiza qué este proyecto
>
> - Cumple el código de honor.
> - Cumple en su totalidad el listado de conceptos.
> - Explica cada uno de los circuitos.
> - Tiene el diagrama de compuertas de cada circuito.
> - Explica el código de cada circuito
> - Diligenció la [auto-evaluación](https://cdn.rawgit.com/romualdo97/controladores/7a9ff32a/01/report_src/Autoevaluacion.xlsx)
> - Reporta el [tiempo de dedicación](https://cdn.rawgit.com/romualdo97/controladores/7a9ff32a/01/report_src/project_report.pdf).

LISTADO DE CONCEPTOS
===================

## 1.A ) Realice una gráfica de una señal de reloj. Identifique las fases tick y tock, un flanco de bajada y otro de subida, el periodo, la frecuencia.

Se realiza una gráfica de señal de reloj usando la función digital.

![enter image description here](https://latex.codecogs.com/gif.latex?ceil%28sin%28x%29%29%29)

**[FOTO: a_digital_function]**

![enter image description here](https://latex.codecogs.com/gif.latex?sin%28x%29) **vs**  ![enter image description here](https://latex.codecogs.com/gif.latex?ceil%28sin%28x%29%29%29)

**[FOTO: a_digital_function_and_sine_function]**

Identificamos las fases ticks mediante la siguiente expresión.

![enter image description here](https://latex.codecogs.com/gif.latex?tick%28x%29&space;=&space;%5Cleft&space;%5C%7B&space;x&space;%5Cin&space;Ti&space;:&space;ceil%28sin%28x%29%29&space;=&space;0&space;%5Cright&space;%5C%7D) 

Identificamos las fases tocks mediante la siguiente expresión.

![enter image description here](https://latex.codecogs.com/gif.latex?tock%28x%29&space;=&space;%5Cleft&space;%5C%7B&space;x&space;%5Cin&space;To&space;:&space;ceil%28sin%28x%29%29&space;=&space;1&space;%5Cright&space;%5C%7D)

Así mismo, en la siguiente imagen podemos identificar los flancos de bajada en los tiempos ![enter image description here](https://latex.codecogs.com/gif.latex?%5Cpi,&space;3%5Cpi,&space;5%5Cpi), mientras que los flancos de subida se encuentran en los instantes ![enter image description here](https://latex.codecogs.com/gif.latex?0,&space;2%5Cpi,&space;4%5Cpi).

**[FOTO: a_flancos_subida_y_bajada]**

Basado en la imagen anterior podemos calcular el tiempo que tarda el reloj en completar un ciclo tick tock, es decir el periodo de la función digital que describe los ciclos del reloj.

![enter image description here](https://latex.codecogs.com/gif.latex?3%5Cpi&space;-&space;%5Cpi&space;=&space;2%5Cpi)

También podemos calcular el número de ciclos que completa el reloj por unidad de tiempo.

![enter image description here](https://latex.codecogs.com/gif.latex?1&space;/&space;T&space;=&space;1&space;/&space;2%5Cpi)

## 1.B ) La figura 3.5 del texto guía, muestra un diagrama de tiempo para el PC. Basado en ese diagrama de tiempo realice uno, para cada chip, que explique el funcionamiento de:

### Flip-flop tipo D 

**[FOTO: b_DFF_time_scheme]**

### 1 Bit register

**[FOTO: b_bit_register_time_scheme]**

### Registro

**[FOTO: bc_register_time_scheme]**

### RAM8

**[FOTO: bd_ram8_time_scheme]**

**CICLO CERO:**
La RAM8 carga el registro en la dirección ocho en modo escritura, con los bits 0 y 15 del bus de entrada igual a 1.

**CICLO UNO:**
La ram se configura en modo lectura para el registro en la dirección 8. 
Los bits en el bus de entrada son despreciables en este ciclo.
La ram devuelve mediante el bus de salida los valores en el registro 8 que fueron escritos durante el ciclo cero.

**CICLO DOS:**
La ram se configura en modo lectura para el registro en la dirección cero.
La ram devuelve los últimos valores que tomó el registro.
En este caso los bits 0 y 15 del registro cero se igualaron a cero en la ultima operación de escritura que realizó la ram sobre dicho registro.

**CICLO TRES:**
La ram se configura en modo escritura para el registro en la dirección 5.
Los valores del bus de entrada en ram se escribirán en el registro 5 durante el siguiente ciclo (ciclo 4).
Mientras tanto el bus de salida de la ram devolverá los valores del registro cinco durante el ciclo anterior (ciclo 2).

**CICLO CUATRO:**
La ram se configura en modo lectura para el registro en la dirección cero.
La ram retorna a través del bus de salida el contenido del registro cero en el ciclo anterior (ciclo 3).

## 1.C ) Explique los diagramas que se encuentran en slide 14 de [este archivo](http://nand2tetris.org/lectures/PDF/lecture%2003%20sequential%20logic.pdf): 

**[FOTO: ca_diagram_14]**

La figura de la izquierda nos muestra como la salida de un circuito combinacional depende de la forma en que combinemos las entradas del mismo, es decir, el circuito combinacional está en función de sus entradas. 

Mientras tanto un circuito secuencial se encuentra principalmente en función del tiempo, aunque necesita entradas, Las cuales pueden ser provistas por circuitos combinacionales, de este mismo modo, las salidas del circuito secuencial pueden estar dirigidas hacia otro circuito combinacional.

## 1.D ) ¿Cuáles son las diferencias fundamentales entre un circuito lógico secuencial y uno combinacional?

**[FOTO: da_flip_flop]**

El circuito lógico combinacional está en función de sus entradas, y no puede nunca recibir como entrada alguna de sus salidas, pues se produciría un problema de indeterminación. Por otro lado el circuito lógico secuencial soluciona esta cuestión usando algún flip flop particular que permita al circuito estar en función del tiempo, de otras entradas cualquieras y de sus propias salidas en tiempos anteriores.

## 1.E ) En relación a las memorias RAM implementadas, se puede decir que las operaciones de escritura son secuenciales y las de lectura son combinacionales. 

### ¿Concuerda con esta afirmación? Explique claramente su respuesta.

Se entiende el proceso de lectura como una operación propia de lógica secuencial, pues es en estos circuitos que encontramos funciones  que dependen de si mismas evaluadas en un instante de tiempo inmediatamente anterior. 

Mientras que la operación de escritura depende únicamente de una combinación particular de los valores de entrada, es decir,  se trata de una función que depende de los valores que toman sus variables de entrada, sin embargo el resultado no se ve reflejado al instante sino un ciclo inmediatamente después, por esta razón podemos considerar que el proceso de escritura es una combinación de circuito combinacional con secuencial, pues la salida de la función combinacional se evalúa luego en el circuito secuencial.

En otras palabras, no es correcto decir que las operaciones de escritura son secuenciales y las de lecturas son combinacionales, pues se trata de una combinación muy ingeniosa de ambos tipos de circuitos.

### Ejemplo:

En la siguiente imagen la operación de escribir un uno en el bit de salida `out` será cuestión solo de modificar la combinación de los bits de entrada, esto es, hacer que los bits `load` e `in` sean igual a uno, el resultado de este circuito combinacional es transmitido luego a un circuito secuencial, que en este caso se constituye solo de un `data flip-flop`. Así podemos observar como la operación de escribir se compone de un circuito combinacional y uno secuencial. Lo mismo ocurre cuando se intenta leer un bit.

**[FOTO: ea_example]**

## 1.F ) Explique la diferencia entre una dirección de memoria y el contenido de esa dirección

La dirección de memoria nos indica donde podremos encontrar un registro determinado dentro de alguna arquitectura de memoria, mientras que el contenido no ofrece los valores que el registro en una dirección particular esta almacenando.

## 1.G ) Si una memoria RAM (como las implementadas en el proyecto) posee un bus de direcciones de n bits y en cada posición o registro de la memoria se pueden guardar m bits. Calcule el tamaño en bits de la memoria. Explique su respuesta.

Se sabe que:

![enter image description here](https://latex.codecogs.com/gif.latex?%5Clog_2%28b%29&space;=&space;n)

Por tanto.

![enter image description here](https://latex.codecogs.com/gif.latex?2%5En&space;=&space;b)

Donde `b` es el número de registros en la memoria. Y como se sabe qué `m` es el número de bits que puede almacenar cada registro de la memoria, entonces tenemos que:

![enter image description here](https://latex.codecogs.com/gif.latex?size%28n,&space;m%29&space;=&space;b&space;*&space;m&space;=&space;2%5En*m)

## 1.H ) Explique la razón por la cual al cambiar el bit de load en un registro, su efecto no se ve inmediatamente reflejado en la salida.

Dado que los registros implementados son circuitos secuenciales que dependen fuertemente de un `D flip-flop` y como sabemos que la salida de un `D flip-flop` es la entrada en un ciclo anterior, nos terminamos encontrando que todos los sistemas que construyamos sobre esta arquitectura tendrán de forma natural ese efecto de retardo.

## 1.G ) Explique para qué puede servir el registro PC en un computador 

El registro PC es una herramienta indispensable para leer software, este registro sera el encargado de ejecutar luego las operaciones indicadas por el programador en un sistema de computo.


----------

SOBRE LOS RETARDOS DE PROPAGACIÓN
===================

## ¿Qué implicaciones tiene para el funcionamiento de un circuito combinacional?

Los retardos en la propagación de señales en un circuito combinacional implican que dicho circuito va a devolver resultados no esperados, o resultados basura hasta que haya ocurrido el tiempo necesario para que la señal retardada llegue al lugar necesario.

## ¿Qué implicaciones tiene para el funcionamiento de un circuito secuencial?

El problema anterior puede ser resuelto en circuitos secuenciales en la etapa de diseño, se resuelve teniendo en cuenta la distancia mas larga que tendrá que viajar alguna señal en el circuito y midiendo el tiempo de viaje, para luego hacer que los ciclos del reloj tarden no menos que dicho tiempo.


----------


DIAGRAMAS DE CHIPS
===================

## 1 bit register

## 16 bit register

## RAM8

## RAM64

## RAM512

## RAM4K

## RAM16K

## PC
