# Counting DNA Nucleotides
## Proyecto 4 - Tópicos especiales en telemática
High Performance Computing
## Estudiantes
- Alejandro Cano Múnera
- Luis Javier Palacio Mesa
- Sebastián Giraldo Gómez
### Universidad EAFIT
## Videosustentaciones
#### Alejandro Cano Múnera
link: 
#### Luis Javier Palacio Mesa
link: 
#### Sebastián Giraldo Gómez
link: 
## Problema o caso de estudio a resolver
El ADN es una biomolécula que contiene la información necesaria para generar un organismo. Está compuesta por muchas unidades llamadas nucleótidos los cuales están formados de un grupo fosfato, una molécula de azúcar de cinco carbonos y una base nitrogenada.
</br>
Existen cuatro bases nitrogenadas: adenina (A), citosina (C), guanina (G) y timina (T). La adenina siempre se aparea con la timina y la guanina con la citosina.


![adn](https://github.com/alejocano22/TETproject4/blob/master/images/ADNestructura.png)
Una cadena es una colección ordenada de símbolos seleccionados de algún alfabeto y formados en una palabra, la longitud de una cadena es el número de símbolos que contiene, esta secuencia de ADN puede ser 3200’000.000 de letras de longitud y es que un trozo de ADN de 1 mm de longitud contiene una secuencia de pares de bases de más de 3 millones de letras.
Para comprender la magnitud del problema establezcamos el siguiente comparativo: Si desenrollamos todo el ADN de las células de un cuerpo humano, cubriremos la distancia de la Tierra a la Luna 7.000 veces. Veamos los cálculos: el total de células del cuerpo humano (2 billones = 2 x 10^12 células) y la longitud equivale al recorrido de 7.000 viajes de ida y vuelta a la Luna (distancia Tierra – Luna = 300.000 Km)
</br>
Un ejemplo de una cadena de ADN de longitud 21 es "ATGCTTCAGATAGGTCTTACG".
</br>
Ahora dada una cadena s de ADN  de longitud como máximo 1000 nt (Nucleótidos), se deben regresar cuatro enteros separados por espacios que cuentan el número respectivo de veces que aparecen los símbolos 'A', 'C', 'G' y 'T' en la cadena s.

Ejemplo:
</br>
Conjunto de datos de muestra</br>
AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC
</br>
Salida de muestra</br>
20 12 17 21

## Objetivos y alcance
### Objetivos
- Utilizar computación alto desempeño para resolver problemas de lectura de cadenas de ADN.
- Comparar el impacto que tiene ejecutar estos problemas en una sóla máquina.
- Comparar el impacto que tiene ejecutar estos problemas usando múltiples hilos.
- Comparar el impacto que tiene ejecutar estos problemas en 1,2,3 y 4 nodos.
- Comparar el impacto que tiene ejecutar estos problema en múltiples nodos e hilos.

### Alcance
Establecer un comparativo entre las diferentes formas de resolver un problema  e identificar el desempeño computacional de cada una de ellas para finalmente poder analizar una cadena de ADN la cual puede ser muy larga y por tanto muy exigente en cuanto a recursos computacionales.

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
