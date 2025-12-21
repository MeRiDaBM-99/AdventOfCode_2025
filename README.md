# Advent of Code 2025 — Día 5: Cafetería 

## Componentes del grupo 

- Sonia S Galeas
- Marcos Mérida Bustamante 
- Lucía Remolar
- Marta Ros

## Descripción del problema

El problema consiste en analizar un sistema de **gestión de inventario** con el fin de determinar que ingredientes se consideran frescos a partir de unas reglas definidas.
El sistema se basa en dos tipos de datos:
- **Rangos de identificadores** de ingredientes frescos, los cuales indican intervalos en los que se podrían encontrar los identificadores de los alimentos frescos (ambos extremos incluidos).
- Una **lista de identificadores** de ingredientes (id), estos representan cada ingrediente.

Un ingrediente se considera fresco si se encuentra dentro de los rangos. Estos rangos pueden solaparse entre sí, por lo que, la pertenencia a al menos un intervalo será suficiente para ser clasificado como fresco.

El input se trata de un documento de texto, el cual consta de **dos bloques** definidos separados por una línea en blanco (*empty line*).
- En el primer bloque se encuentran todos los rangos, definidos como valores de mínimo y máximo [*min, max*].
- El segundo bloque contiene los id de cada uno de los ingredientes a comprobar.

Ejemplo visual:
```
3-5
10-14
16-20
12-18
           <- (Linea en blanco)
1
5
8
11
17
32
```

El objetivo final se basa en **contabilizar cuantos ingredientes del segundo bloque se consideran frescos**.

## Justificación de la elección del problema

El problema fue seleccionado ya que, pese a sus sencillez conceptual, presenta características que lo hacían apto para integrar estructuras más complejas que nos podían ser útil para la entrega de este trabajo.

En particular, tanto los rangos como los ids abarcaban números muy grandes, lo que implicaba el uso de `long long`, con el cual si intentábamos resolverlas por métodos directos podía tener un alto coste.

Por este motivo, el problema se prestaba para la utilización de árboles, específicamente un árbol de intervalos (*Interval Trees*).

## Técnicas y estructuras de datos empleadas

Para la resolución de este problema, se ha empleado, como se ha mencionado anteriormente, la estructura de árbol de intervalos, así como también se ha usado la técnica de recursividad para implementar algunas de las funciones de la clase `BSTree`.

## Descripción de la resolución del problema

Para la resolución de este problema se ha implementado una **estructura de árbol basada en intervalos**, de manera que se han creado dos archivos.h.

Por un lado tenemos **BSNode.h**, el cual contiene la clase **BSNode**, que implementa un nodo. Para este problema era necesario tener la capacidad de guardar rangos por lo que se procedió a crear dos variables (`inicio, fin`), los cuales marcaban los extremos del intervalo.

Por otro lado también se ha creado el archivo **BSTree.h**, el cual contiene la clase **BSTree**, que implementa un árbol de intervalos (se dice que es de intervalos ya que, el nodo no solo contiene un elemento sino el intervalo antes mencionado en BSNode). En esta clase se encuentran las funciones `insert` y `search`:

- `search`: esta se trata de un función booleana a la cual se le pasa como argumento un valor (identificador) y un nodo. Lo que realiza internamente es comparar el identificador con los rangos del nodo, si no coincide, comprueba si el hijo izquierdo existe y si su maxfin es mayor o igual al identificador, si lo es, explora el lado izquierdo, en el caso contrario explora el lado derecho. Cuando encuentra una coincidencia devuelve *True* sino devuelve *False*.
- `insert`: a esta función se le pasa un rango como argumento y dependiendo del valor de estos se inserta en el árbol (compara los valores del nuevo rango con los de los nodos actuales para saber si desplazarse a la izquierda o a la derecha). Después actualiza la variable maxfin del nodo.

Para la lectura del archivo input (en el `main`) se utilizó tanto `ifstream` como `getline()` para poder leer línea a línea el documento. Este, como ya se ha dicho en apartados anteriores, está dividido en dos bloques, lo que ha mejorado su lectura. Sabiendo que el primer bloque eran los rangos, se ha procedido a crear una variable booleana que indicase cuando se estuvieran leyendo rangos y cuando no, es decir cuando se estuviera leyendo identificadores. Esta variable se inicializa en un principio a *True* ya que al principio del documento se encuentran los rangos, cuando se encuentra con una línea en blanco (*empty line*) esta variable pasa a estar a *False*, lo que indica que empiezan los identificadores.

- Cuando `rangos == True` se llama a la función insert y se inserta el lugar correspondiente del nodo con los intervalos en el árbol (previamente inicializado).
- Por otro lado cuando `rangos == False` se llama a la función search, la cual busca si el identificador de la línea leida se encuentra en algún rango, si esto se da, la variable `definitivos` se incrementa (`definitivos++`), esta es la variable que lleva la cuenta de los alimentos frescos encontrados y se inicializa previamente en 0. Si no el identificador no se encuentra continua con la siguiente línea. 

Por último se imprime por pantalla la variable definitivos con un `cout`.

## Alternativas rechazadas

En este problema se habían propuesto otras alternativas de solución. Como se ha mencionado en apartados anteriores, en un principio existía la posibilidad de realizar la búsqueda de manera directa con arrays y vectores, sin embargo, al ver la longitud del documento y los datos, se optó por descartarla ya que haría la búsqueda muy pesada. Además concluimos en que este sería un problema en el cual se podría implementar árboles, lo que favorecía al trabajo.

## Valoración personal 

Finalmente, todos los miembros del grupo han coincidido en que la resolución de este problema ha permitido aplicar conceptos vistos en clase, como lo pueden ser los árboles. Durante la resolución surgió la duda de si era un buen método implementar los árboles o aumentaría el coste, sin embargo finalmente optamos por implementarlo, ya que, al tener que leer archivos grandes con datos también grandes creímos necesario la implementación de un árbol, lo que nos ayudó también a comprender mejor las estructuras y reutilizar plantillas de las clases prácticas (los archivos.h son códigos modificados de las clases implementadas en las prácticas). En conjunto, el grupo lo considera como un buen problema para poder afianzar conocimientos. 

