# Finding a Most Likely Common Ancestor
## Proyecto 4 - Tópicos especiales en telemática
High Performance Computing
## Estudiantes
- Alejandro Cano Múnera
- Luis Javier Palacio Mesa
- Sebastián Giraldo Gómez
### Universidad EAFIT
## Drive
https://drive.google.com/drive/u/0/folders/1uW9rhO2C9FwYsvD1Fl9Fjj6um4ayzVk4

## Videosustentaciones
#### Alejandro Cano Múnera
link: https://youtu.be/1WKTg3dfKNk

#### Luis Javier Palacio Mesa
link: 

#### Sebastián Giraldo Gómez
link: https://youtu.be/txfBX3f5Br0

## Problema o caso de estudio a resolver
El ADN es una biomolécula que contiene la información necesaria para generar un organismo. Está compuesta por muchas unidades llamadas nucleótidos los cuales están formados de un grupo fosfato, una molécula de azúcar de cinco carbonos y una base nitrogenada.
</br>
Existen cuatro bases nitrogenadas: adenina (A), citosina (C), guanina (G) y timina (T). La adenina siempre se aparea con la timina y la guanina con la citosina.


![adn](https://github.com/alejocano22/TETproject4/blob/master/images/ADNestructura.png)

Una cadena es una colección ordenada de símbolos seleccionados de algún alfabeto y formados en una palabra, la longitud de una cadena es el número de símbolos que contiene, esta secuencia de ADN puede ser 3200’000.000 de letras de longitud y es que un trozo de ADN de 1 mm de longitud contiene una secuencia de pares de bases de más de 3 millones de letras.
Para comprender la magnitud del problema establezcamos el siguiente comparativo: Si desenrollamos todo el ADN de las células de un cuerpo humano, cubriremos la distancia de la Tierra a la Luna 7.000 veces. Veamos los cálculos: el total de células del cuerpo humano (2 billones = 2 x 10^12 células) y la longitud equivale al recorrido de 7.000 viajes de ida y vuelta a la Luna (distancia Tierra – Luna = 300.000 Km)

</br>

Una matriz es una tabla rectangular de valores dividida en filas y columnas. Una matriz m × n tiene m filas y n columnas. Dada una matriz A, escribimos A i,j para indicar el valor encontrado en la intersección de la fila i y la columna j.

Digamos que tenemos una colección de cadenas de ADN, todas con la misma longitud n. Su matriz de perfil es una matriz 4 × n P en la cual P1, j representa el número de veces que 'A' ocurre en la posición j de una de las cadenas, P2, j representa el número de veces que C ocurre en la posición j , y así sucesivamente (ver más abajo).

Una cadena de consenso c es una cadena de longitud n formada a partir de nuestra colección tomando el símbolo más común en cada posición; el símbolo j de c corresponde, por lo tanto, al símbolo que tiene el valor máximo en la columna j-ésima de la matriz de perfil. Por supuesto, puede haber más de un símbolo más común, lo que lleva a múltiples posibles cadenas de consenso.

##### Datos de entrada:
Archivo de texto plano (.txt) con y cadenas de ADN y x nucleótidos (caracteres) que las conforman. </br>
Los caracteres validos son: A T G C 

##### Datos de salida:
Archivo de texto plano (.txt) con la cadena de ADN de consenso que indica el caracter que más se repite por columna entre las cadenas de ADN dadas.

##### Ejemplo:
![EjemploProblema](https://github.com/alejocano22/TETproject4/blob/master/images/Problem2.jpg)

## Objetivos y alcance
### Objetivos
- Utilizar computación alto desempeño para resolver problemas de lectura de cadenas de ADN.
- Comparar el impacto que tiene ejecutar estos problemas en una sóla máquina.
- Comparar el impacto que tiene ejecutar estos problemas usando múltiples hilos.
- Comparar el impacto que tiene ejecutar estos problemas en 1,2,3 y 4 nodos.
- Comparar el impacto que tiene ejecutar estos problema en múltiples nodos e hilos.

### Alcance
Establecer un comparativo entre las diferentes formas de resolver un problema  e identificar el desempeño computacional de cada una de ellas para finalmente poder analizar un conjunto de cadenas de ADN las cuales pueden ser muy largas y por tanto muy exigentes en cuanto a recursos computacionales.

## Requerimientos técnicos
- Linux
- C++
- OpenMP
- MPI
- Conocimiento de arquitecturas Intel
- Conocimiento básico de estructura de cadenas de ADN.
- Conocimiento básico de funcionamiento de hilos y procesos.

## Plan de trabajo
1. Definir y entender bien el problema a resolver. </br>

2. Diseñar e Implementar un algoritmo secuencial  y tomar el tiempo de procesamiento (Ts). </br>

3. Diseñar e implementar el algoritmo paralelo en el paradigma o combinación de ellos, según sea el caso (OpenMP, MPI). Hallar el tiempo de procesamiento paralelo con diferentes recursos (Tp(P)) y hallar el SpeedUp y Eficiencia.</br>

    a. Implementar el algoritmo paralelo según sea el caso (OpenMP, MPI). Determinar un balance entre partes del algoritmo que se desarrollarán en OpenMP, coprocesamiento y partes con MPI.</br>

    b. Aplicar la técnica de diseño de algoritmo PCAM (particionamiento, comunicación, aglomeración, mapeo a UE), en donde defina   claramente el mecanismo de particionamiento (funcional y/o datos), mecanismos de comunicación entre tareas, optimización o aglomeración y finalmente el mapeo a unidades de ejecución (cores de procesamiento).</br>

    c. Realizar el análisis del SpeedUp y Eficiencia para varios escenarios de recursos.</br>

4. Implementar el algoritmo en la plataforma MPI dispuesta para el curso.  </br>

5. Realizar el análisis de rendimiento con varios números de procesadores (1: secuencial,
paralelo: 2, 3 y 4 procesadores). SpeedUp y Eficiencia. Hacer conclusiones.</br>

## Pseudocódigo
```sh
for(int col = 0; col < totalColumnas; col+=1){
  for (int row = 0; row < totalRows; row+=1) {
    if (strings[row][col] == "A") {
      count[A][col] +=1

    }else if (strings[row][col] == "T"){
      count[T][col] +=1

    }else if (strings[row][col] == "G"){
      count[G][col] +=1

    }else if (strings[row][col] == "C"){
      count[C][col] +=1

    }
  }
}

for (int col = 0; col < totalColumnas; col+=1){
  argMax = searchMax(count[col])
  resultBuffer[col] = argMax
}

save resultBuffer
```

## Compilación y ejecución
Realizar cada uno de los siguientes comandos en el folder corresponiente
```sh
make
```
```sh
make queue
```
Para visualizar los resultados:
```sh
cat dnastring.o<id>
```
Para visualizar la cadena de salida del programa:
```sh
cat result.txt
```
### Serial
```sh
cd src/serial/arrayVersion
```
### Threads
```sh
cd src/threads
```
### MPI
```sh
cd src/mpi
```
## MPI with threads
```sh
cd src/mpi-threads
```

## Análisis de resultados
Para comprobar el correcto funcionamiento del programa se utilizo una cadena de ADN corta (de 8 nucleótidos).
Sin embargo, para exigir los programas computacionalmente se genero un archivo de prueba de 10.000 cadenas de ADN, con 10.000 nucleótidos cada una. Los resultados se presentaran a continuación.

### Serial
![serial-1](https://github.com/alejocano22/TETproject4/blob/master/images/Problem2.jpg)
![serial](https://github.com/alejocano22/TETproject4/blob/master/images/Serial/Array/Serial_10k.PNG)

### Threads
![threads-1](https://github.com/alejocano22/TETproject4/blob/master/images/Threads.jpg)
![threads](https://github.com/alejocano22/TETproject4/blob/master/images/Threads/Threads_10k.PNG)

### MPI con 4 nodos
![mpi-1](https://github.com/alejocano22/TETproject4/blob/master/images/MPI.jpg)
![mpi](https://github.com/alejocano22/TETproject4/blob/master/images/MPI/MPI4_10k.PNG)

## MPI con 4 nodos y threads
![mpi-threads-1](https://github.com/alejocano22/TETproject4/blob/master/images/MPI_Threads.jpg)
![mpi-threads](https://github.com/alejocano22/TETproject4/blob/master/images/MPI-Threads/MPI4_Threads_10k.PNG)

### Comparativo
![tablas](https://github.com/alejocano22/TETproject4/blob/master/images/Tablas.PNG)
Como se puede observar hay una evidente mejora entre el código serial versus el código con MPI ejecutado en 4 nodos y con hilos, presentando un SpeedUp de 35.63, por otra parte el código serial versus el código con hilos presenta un SpeedUp de 21.88. </br>
La eficiencia entre el código serial frente a el código con MPI ejecutado en 4 nodos y con hilos es de 8.91, sin embargo, si analizamos la eficiencia entre MPI en 1 nodo con hilos y MPI en 4 nodo con hilos la cual da como resultado 0.37, nos da a entender que no es eficiente resolver el problema en n nodos, como se ve a continuación a medida que se aumentan los nodos disminuye el tiempo de ejecución, pero cada mejora es mínima y no representa  un cambio considerable a tener en cuenta frente al aumento de nodos. Por lo tanto se concluye que el mejor algoritmo es MPI con hilos ejecutado en un solo nodo.

![mpinodes](https://github.com/alejocano22/TETproject4/blob/master/images/MPI%20with%20threads.PNG)


## Código de honor
Idea de problema tomada de: http://rosalind.info/problems/cons/ </br>
Se utilizó código fuente e ideas del curso Fundamentals of Parallelism on Intel Architecture desarrollado en Coursera. </br>

Alejandro Cano Múnera </br>
- Implementación de solución serial con Arrays.
- Implementación de estructura de datos para evitar la concurrencia de hilos en una sección crítica.
- Adecuación de archivo main.cpp para ejecución con MPI y escritura de archivos de salida.

Luis Javier Palacio Mesa </br>
- Implementación de solución serial con Mapas.
- Implementación de solución con hilos (OpenMP).
- Implementación de solución con MPI.

Sebastián Giraldo Gómez </br>
- Optimización a solución serial con Arrays.
- Análisis de sección critica e implementación de hilos con MPI
- Idea e implementación del Allgather en MPI para recopilar los resultados de los nodos.

Lo anterior descrito no implica que fueran tareas excluyentes dado que todos los estudiantes se apoyaron mutuamente en la implementación y análisis del problema y la solución dada.
