# Advent of Code 2025 — Día 4: Printing Department

## Componentes del grupo 

- Sonia S Galeas
- Marcos Mérida Bustamante 
- Lucía Remolar
- Marta Ros

## Descripción del problema

El problema consiste en analizar un gran almacén donde los rollos de papel (`@`) están dispuestos en una cuadrícula. Cada posición de la cuadrícula puede estar vacía (`.`) o contener un rollo de papel. El acceso a un rollo depende de las siguientes reglas:

- Solo se puede acceder a un rollo si en las ocho posiciones adyacentes hay menos de 4 rollos de papel, si lo cumple se considera accesible.

El objetivo es contabilizar cuántos rollos son accesibles.

Ejemplo visual:
```
..@@.@@@@.
@@@.@.@.@@
@@@@@.@.@@
@.@@@@..@.
@@.@@@@.@@
.@@@@@@@.@
.@.@.@.@@@
@.@@@.@@@@
.@@@@@@@@.
@.@.@@@.@.
```

## Justificación de la elección del problema
Elegimos este problema del Advent of Code porque nos pareció interesante desde el punto de vista algorítmico y nos permitía aplicar estructuras estudiadas en la asignatura, especialmente los grafos. Además, consideramos que suponía un reto adecuado para el grupo, tanto por su complejidad como por la búsqueda conjunta de una solución eficiente.

##  Técnicas y estructuras de datos empleadas
En cuanto a las técnicas y estructuras que se han implementado, han sido las siguientes: Para la lectura de archivos se ha utilizado `ifstream` y `getline()`. También se ha usado una matriz de string, que nos permitía usar el documento como una matriz. Para mirar los rollos vecinos, se ha usado desplazamientos(`df, dc`) que representaban las 8 direcciones alrededor de la celda. Esta técnica se ha usado como un grafo implícito, donde cada celda es un nodo y las aristas son las adyacencias.

## Descripción de la resolución del problema
El objetivo del problema era determinar a cuántos rollos se podían acceder que cumplieran la condición de que el total de adyacentes en las 8 direcciones que tuvieran un rollo fuera menos que 4. 

Para la lectura de archivos se ha utilizado `ifstream`, para recorrer cada línea del fichero (mediante un `getline()`) que contiene la representación de la cuadrícula con rollos ( `@` ) y espacios ( `.` ). Después se ha transformado el documento en una matriz de string. 

Para mirar los rollos vecinos, se ha usado desplazamientos(`df, dc`, implementados en la función comprobar) que representaban las 8 direcciones alrededor de la celda. Para comprobar cuántas adyacencias tiene un vecino se ha usado la función comprobar que devuelve `true` si había menos de 4 adyacencias. 

Por último se recorren todas las posiciones de la matriz y se aplica la función comprobar a cada celda que contiene un rollo ( `@` ) y se van contando todas aquellas que cumplen la condición, para sacar el número por pantalla. 

## Alternativas rechazadas
Por otro lado, también se había optado por intentar realizar el problema entero con un grafo explícito, en el que cada celda se consideraba un nodo y las adyacencias eran las aristas de este. En la primera parte se observaba las adyacencias que tuvieran un rollo y se añadían a un contador, que utilizamos al final para ver si cumplía con la condición de ser menor que 4. Sin embargo, esto añadía una complejidad que finalmente se consideró innecesaria ya que la cuadrícula ya actuaba como un grafo implícito.

## Valoración grupal 
Finalmente, todos los miembros del grupo han coincidido en que la resolución de este problema nos permitió aplicar conceptos vistos en clase, como lo pueden ser los grafos. Durante la resolución surgió la duda de que manera implementar grafos en este problema sería la más óptima (implícita o explícita), sin embargo finalmente optamos por la implícita, por su claridad y efectividad, esto nos ayudó a comprender mejor las estructuras. En conjunto, el grupo lo considera como un buen problema para poder afianzar conocimientos.
