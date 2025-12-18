# Advent of Code 2025 — Día 9: Movie Theater

## Componentes del grupo 

- Sonia S Galeas
- Marcos Mérida  
- Lucía Remolar
- Marta Ros

### Descripción del problema
El reto consiste en analizar un suelo de baldosas dispuesto en una cuadrícula. Algunas baldosas están marcadas como rojas y se nos pide encontrar `el rectángulo de mayor área que tenga dos baldosas rojas como esquinas opuestas`. Ejemplo visual del enunciado: 

```
..............
.......#...#..
..............
..#....#......
..............
..#......#....
..............
.........#.#..
..............
```

En la segunda parte del problema, la restricción aumenta: el rectángulo no solo debe tener esquinas rojas, sino que `todas las baldosas que lo conforman deben ser rojas o verdes`. Las verdes se generan automáticamente como conexiones entre las rojas, formando un contorno cerrado que delimita la zona válida. Ejemplo visual del problema:

```
..............
.......#XXX#..
.......X...X..
..#XXXX#...X..
..X........X..
..#XXXXXX#.X..
.........X.X..
.........#X#..
..............
```

En resumen, se trata de un problema de geometría discreta sobre una cuadrícula, donde debemos calcular áreas máximas bajo condiciones de validez.

## Justificación de la elección del problema
Este problema fue elegido porque combina varios aspectos interesantes:

- Visualización geométrica: trabajar con coordenadas en una cuadrícula y representar áreas rectangulares.

- Optimización: encontrar la solución máxima, es decir, el rectángulo más grande posible.

- Incremento de dificultad: la segunda parte introduce restricciones adicionales, obligando a refinar la solución.

Además, es un reto que permite aplicar estructuras de datos y algoritmos de forma práctica, reforzando conceptos de programación vistos en clase.

### Técnicas y estructuras de datos empleadas
Para la resolución final se ha optado por un engoque matemático y geométrico, prescindiendo de la simulación pixel a pixel, dado que se trabaja con una gran cantidad de datos e incluso, se llega a exceder la memoria disponible. 

#### Estructuras de Datos:
`struct Point`: una estructura personalizada ligera para manejar coordenadas `(x, y)`. Se ha utilizado el tipo de dato long long para evitar desbordamientos de buffer (overflow), dado que el cálculo del área (`ancho * alto`) puede superar el límite de un entero de 32 bits.

`std::vector`: utilizado para almacenar secuencialmente los vértices que definen el polígono (el borde rojo/verde). Permite un acceso rápido e iterativo para las comprobaciones geométricas.

#### Técnicas Algorítmicas:
- Geometría Vectorial: en lugar de tratar el mapa como una imagen de bits, lo tratamos como un conjunto de vectores.

- Detección de Intersección de Segmetos: lógica para verificar si alguna línea del borde del polígono 'corta' o atraviesa el rectángulo considerado.

/*
- Conjuntos (hash set): para comprobar rápidamente si una coordenada pertenece al conjunto de baldosas rojas o verdes.

- Generación de rectángulos: se iteraron todas las posibles parejas de baldosas rojas como esquinas opuestas, calculando el área del rectángulo definido por ellas.

- Validación de rectángulos:
  - En la primera parte, bastaba con calcular el área.
  - En la segunda parte, se verificó que todas las baldosas dentro del rectángulo pertenecieran al conjunto de baldosas válidas (rojas o verdes).
*/

### Descripción de la resolución del problema
El abordaje del problema se dividió en tres fases claras:

- `Lectura y Normalización`: Se procesa el archivo de entrada para extraer las coordenadas de los azulejos rojos, que actúan como vértices del polígono. Estos se almacenan en orden secuencial para reconstruir el perímetro.
- `Generación de Candidatos`: Dado que el rectángulo de área máxima debe tener vértices rojos en esquinas opuestas, iteramos sobre todos los pares posibles de puntos $(P_i, P_j)$. Esto reduce el espacio de búsqueda drásticamente en comparación con probar coordenadas aleatorias.
- `Validación Geométrica`: Para cada par que forma un rectángulo con un área mayor al máximo actual encontrado (poda de optimización), realizamos dos verificaciones:
  - `Verificación de Cortes`: Comprobamos cada segmento del polígono. Si algún segmento atraviesa el interior del rectángulo (entra por un lado y sale por otro), el rectángulo se descarta, ya que contendría puntos que no son válidos.
  - `Verificación de Inclusión`: Si no hay cortes, verificamos si el rectángulo está dentro del bucle usando Ray Casting sobre su punto central. Si el número de intersecciones del rayo con el borde es impar, el rectángulo es válido.

### Alternativas probadas y descartadas
- Brute force completo con matriz bidimensional: se intentó representar toda la cuadrícula como una matriz de caracteres, pero resultó ineficiente para tamaños grandes.

- Algoritmos de barrido (sweep line): se consideró recorrer filas y columnas buscando rectángulos válidos, pero la validación de la segunda parte era más sencilla con conjuntos.

- Optimización con preprocesamiento de áreas: se pensó en usar estructuras tipo segment tree para validar áreas rápidamente, pero la complejidad añadida no compensaba frente al enfoque directo con conjuntos.

### Valoración personal y personaje
1 por qué habéis elegido ese problema
2 qué técnica o estructura de datos (o las dos) se emplean
3 la descripción de cómo se ha abordado la resolución del problema
4 alternativas que se han probado y descartado o que se podrían plantear para mejorar la resolución
5 valoración personal sobre qué se ha aprendido y porqué ha sido significativo
