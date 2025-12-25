# Advent of Code 2025 — Dia 7: Laboratories 

## Componentes del grupo 

- Sonia S Galeas
- Marcos Mérida Bustamante 
- Lucía Remolar
- Marta Ros

## Descripción del problema

El problema consiste en analizar el comportamiento de un *manifold de taquiones* dentro de un laboratorio de teletrasportación. El sistema recibe un haz de taquiones que entra por una posición inicial (`S`) y se desplaza hacia abajo.

Este haz atraviesa las posiciones vacías (`.`), pero cuando encuentra un *splitter* (`^`), se divide en dos nuevos haces, uno continúa hacia el lado izquierdo, mientras que el otro continúa por el lado derecho. Esto se repite cada vez que el haz se encuentra con el *splitter*, generando múltiples haces.

Ejemplo visual:
```
.......S.......
.......|.......
......|^|......
...............
......^.^......
...............
.....^.^.^.....
...............
....^.^...^....
...............
...^.^...^.^...
...............
..^...^.....^..
...............
.^.^.^.^.^...^.
...............
```
El objetivo del problema sería determinar cuantas posibles combinaciones existen después de que el taquión haya recorrido todas las posibles trayectorias.

## Justificación de la elección del problema
La elección de este problema se fundamenta en su idoneidad para aplicar las estrategias algorítmicas estudiadas durante el curso. El desafío del Día 7 permite demostrar el dominio sobre estructuras de datos complejas y la capacidad de adaptación: se comienza con una exploración de estados y se evoluciona hacia un problema de optimización combinatoria.

## Técnicas y estructuras de datos empleadas
Para la resocución del problema utilizamos la propia matriz de entrada,  dado que el problema exigía contar la totalidad de caminos posibles (lo que implica combinatoria), la estrategia usada ha sido **Programación Dinámica**. Implementamos un enfoque utilizando una tabla auxiliar M inicializada en -1. Esto permite almacenar el número de caminos desde una posición dada hasta el final; si el algoritmo revisita esa posición, recupera el valor calculado previamente en $O(1)$ en lugar de recalcular toda la rama, optimizando drásticamente el tiempo de ejecución.

## Descripción de la resolución del problema
Nos centramos en la segunda parte del problema, que consiste en calcular cuántas trayectorias posibles puede seguir el taquión.
Para resolverlo implementamos un enfoque recursivo con programación dinámica:
- Tras leer el mapa `input.txt`y localizar la posición inicial S, definimos una función caminos() que calcula cuántas trayectorias válidas existen desde una posición concreta hasta el final del mapa.

- Adaptamos la solución a un esquema recursivo con memoria. La función principal ahora retorna la suma de caminos válidos. Al encontrar un divisor, la función se llama recursivamente para las ramas izquierda y derecha, y almacena la suma de ambos resultados en la tabla de memoria. Se definieron casos base estrictos:
  Si la posición sale por los laterales, el camino es inválido y retorna 0.
  Si la posición supera la última fila, el camino es válido y retorna 1.
  Si la celda ya fue calculada previamente, se recupera el valor almacenado en la tabla M.
  Si la celda contiene un divisor ^, la función se bifurca recursivamente hacia izquierda y derecha.
  Si la celda es un espacio vacío ., la función continúa hacia abajo.
El valor final es número total de líneas temporales posibles.
## Alternativas rechazadas
A continuación se justifica porque no se ha elegido el resto de técnicas dadas como posibles soluciones.
* Divide y vencerás, no era una opción posible al tratarse de un ejercicio plenamente secuencial, en ambas partes.
* Árboles binarios, como lo que hemos dado en clase son árboles binarios (dos ramas) se complicaba su implementación, sobre todo cuando se converge entre sí los rayos.
* Tabla Hash, aunque se hace uso de un 'mapa' para indicar los lugares visitados, esta técnica no se pasa como una posible implementación para este problema.

## Valoración grupal
El grupo decidió tener en cuenta este día del AoC, ya que embarca como soluciones el emplear las técnicas dadas en clase. Además se piensa que se ha elegido las soluciones más adecuadas, observando las diferencias cuando se pide 'explorar' y cuando se pide 'analizar combinaciones'.



