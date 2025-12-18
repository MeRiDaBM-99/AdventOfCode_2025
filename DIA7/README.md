# Advent of Code 2025 — Day 7: Laboratories 

## Componentes del grupo 

- Sonia S Galeas
- Marcos Mérida Bustamante 
- Lucía Remolar
- Marta Ros

## ELECCIÓN
La elección de este problema se fundamenta en su idoneidad para aplicar las estrategias algorítmicas estudiadas durante el curso. El desafío del Día 7 permite, a través de sus dos partes, demostrar el dominio sobre estructuras de datos complejas y la capacidad de adaptación: se comienza con una exploración de estados (grafos) y se evoluciona hacia un problema de optimización combinatoria.

## TÉCNICA EMPLEADA
Para la primera parte, se ha optado por modelar el problema mediante Grafos Implícitos. En lugar de crear una estructura de nodos enlazados en memoria, utilizamos la propia matriz de entrada como el grafo, donde cada celda es un nodo y las transiciones (bajar o bifurcarse en ^) son las aristas. La estrategia concreta es una Búsqueda en Anchura (BFS). Esta elección es ideal para la simulación física del problema (un rayo que desciende capa por capa). Al no buscar una ruta óptima sino simplemente contar eventos y simular el flujo, la BFS garantiza un recorrido ordenado y sin redundancias gracias al control de visitados.

Para la segunda parte, dado que el problema exigía contar la totalidad de caminos posibles (lo que implica combinatoria), la estrategia cambia a Programación Dinámica. Implementamos un enfoque utilizando una tabla auxiliar M inicializada en -1. Esto permite almacenar el número de caminos desde una posición dada hasta el final; si el algoritmo revisita esa posición, recupera el valor calculado previamente en $O(1)$ en lugar de recalcular toda la rama, optimizando drásticamente el tiempo de ejecución.

## RESOLUCIÓN DEL PROBLEMA
En la Parte 1, tras la lectura del input.txt y la localización del punto de partida 'S', enfrentamos el problema de la convergencia de rayos. Para evitar bucles o procesamiento redundante, implementamos una matriz booleana de "visitados". El avance se gestiona mediante una cola extraemos la posición actual y calculamos la siguiente. Si es un espacio vacío, el rayo desciende; si es un divisor (^), bifurcamos el flujo añadiendo las coordenadas izquierda y derecha a la cola e incrementamos el contador de solución. El proceso termina cuando la cola se vacía.

En la Parte 2, adaptamos la solución a un esquema recursivo con memoria. La función principal ahora retorna la suma de caminos válidos. Al encontrar un divisor, la función se llama recursivamente para las ramas izquierda y derecha, y almacena la suma de ambos resultados en la tabla de memoria. Se definieron casos base estrictos: si el rayo sale de los límites laterales, retorna 0 (camino inválido); si llega al final de la matriz, retorna 1 (camino válido). El resultado final es la suma acumulada en la primera bifurcación almacenada en la tabla.

## ALTERNATIVAS RECHAZADAS
A continuación se justifica porque no se ha elegido el resto de técnicas dadas como posibles soluciones.
* Divide y vencerás, no era una opción posible al tratarse de un ejercicio plenamente secuencial, en ambas partes.
* Árboles binarios, como lo que hemos dado en clase son árboles binarios (dos ramas) se complicaba su implementación, sobre todo cuando se converge entre sí los rayos.
* Tabla Hash, aunque se hace uso de un 'mapa' para indicar los lugares visitados, esta técnica no se pasa como una posible implementación para este problema.

## Otras alternativas.
Realizar un grafo explícito dificultaba un poco la tarea, sobre todo a la hora de los problemas del AoC que suelen ser a muy gran escala, haciendo que se tarde en cargar el ouput con la solución. Además de tener que implementar las clases y funciones necesarias para su funcionamiento.

## VALORACIÓN GRUPAL
El grupo decidió tener en cuenta este día del AoC, ya que en sus dos problemas embarcan como soluciones el emplear dos de las técnicas dadas en clase y no solo una o ninguna en su caso. Además se piensa que se ha elegido las soluciones más adecuadas para ambas partes, observando las diferencias cuando se pide 'explorar' y cuando se pide 'analizar combinaciones'.



