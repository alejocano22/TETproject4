# Problema
![Problema](https://github.com/alejocano22/TETproject4/blob/master/images/Problem1.jpg)</br>
Una matriz es una tabla rectangular de valores dividida en filas y columnas. Una matriz m × n tiene m filas y n columnas. Dada una matriz A, escribimos A i,j para indicar el valor encontrado en la intersección de la fila i y la columna j.

Digamos que tenemos una colección de cadenas de ADN, todas con la misma longitud n. Su matriz de perfil es una matriz 4 × n P en la cual P1, j representa el número de veces que 'A' ocurre en la posición j de una de las cadenas, P2, j representa el número de veces que C ocurre en la posición j , y así sucesivamente (ver más abajo).

Una cadena de consenso c es una cadena de longitud n formada a partir de nuestra colección tomando el símbolo más común en cada posición; el símbolo j de c corresponde, por lo tanto, al símbolo que tiene el valor máximo en la columna j-ésima de la matriz de perfil. Por supuesto, puede haber más de un símbolo más común, lo que lleva a múltiples posibles cadenas de consenso.

##### Datos de entrada:
Archivo de texto plano (.txt) con y cadenas de ADN y x nucleótidos (caracteres) que las conforman. </br>
Los caracteres validos son: A T G C 

##### Datos de salida:
Archivo de texto plano (.txt) con la cadena de ADN de consenso que indica el caracter que más se repite por columna entre las cadenas de ADN dadas.

##### Ejemplo:
![Problema](https://github.com/alejocano22/TETproject4/blob/master/images/Problem2.jpg)

# PCAM
![PCAM](https://github.com/alejocano22/TETproject4/blob/master/images/PCAM.gif)
## 1. Particionado
Se realiza un particionado por datos. </br>
T1 se encargará de contar la cantidad de veces que aparece cada nucléotido en determinada posición (una determinada columna) entre todas las cadenas de ADN. Es decir, hará un recorrido en filas para cierta columna.

T2 se encargará de ejecutar tareas t1 para contar la cantidad de veces que aparece cada nucleótido en cierta cantidad de columnas entre todas las cadenas de ADN y así armar una submatriz de perfil.

T3 se encargará de obtener una subcadena de consenso a partir de analizar los nucléotidos que más se repiten dentro de la submatriz de perfil de la tarea T2

T4 Se encargará de recopilar los resultados en un único host para obtener la cadena completa de consenso.

![Particionado](https://github.com/alejocano22/TETproject4/blob/master/images/Diagrama.jpg)

## 2. Comunicación
La tarea T1 se puede comunicar con T2 usando memoria compartida. </br>
La tarea T2 se puede comunicar con T3  usando memoria compartida.  </br>
La tarea T3 se puede comunicar con T4 a través de MPI_Allgather  </br>

La tarea candidata para fuertemente acoplado puede ser T1 y T2 puesto que se pueden tirar varios hilos cada uno con la tarea T1 para que procese cada hilo una solo columna, o a un hilo se le pueden dar varias tareas T1, es decir que cada hilo procese varias columnas.  </br>

La tarea candidata para débilmente acoplado puede ser T4 porque incluye la tarea T3 y esta a su vez la tarea T2 que inicia tareas T1. El tiempo de procesamiento de T4 es igual al tiempo de procesamiento de todas las Tareas T3 más el tiempo que demora en comunicar. Se puede pedir a varios nodos que ejecuten la tarea T3. El procesamiento sería colPerProcess^2, entonces el tiempo del procesamiento sería mayor que el tiempo de las comunicaciones, dónde los resultados no tardarían mucho en transmitirse (T4) puesto que se trata de un solo arreglo, en comparación al procesamiento.

## 3. Aglomeración
A cada hilo se le puede asignar varias tareas T1 para que cada hilo de un mejor rendimiento.
![aglomeracion](https://github.com/alejocano22/TETproject4/blob/master/images/MPI_Threads.jpg)

## 4. Mapeo
La cantidad de Workers con las que se cuenta en el cluster colfax es de 4. El nodo 0 es el encargado de asignar los datos particionados y de escribir en el archivo de salida. Esto se realiza a través del método Allgather( ... ) 
