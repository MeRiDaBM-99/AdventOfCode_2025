# Advent of Code 2025 — Día 5: Cafetería 

## Componentes del grupo 

- Sonia S Galeas
- Marcos Mérida Bustamante 
- Lucía Remolar
- Marta Ros

## Descripción del problema

El problema consiste en analizar un sistema de **gestion de inventario** con el fin de determinar que ingredientes se consideran frescos a partir de unas reglas definidas.
El sistema se basa en dos tipos de datos:
- **Rangos de identificadores** de ingradientes frescos, los cuales indican intervalos en los que se podrian encontrar los identificadores de los alimentos frescos (ambos extremos incluidos).
- Una **lista de identificadoes** de ingredientes (id), estos representan cada ingrediente.

Un ingrediente se considera frescos si se encuentra dentro de los rangos. Estos rangos pueden solaparte entre si, por lo que, la pertenecia a al menos un intervalo sera suficiente para ser clasificado como fresco.

El input se trata de un documento de texto, el cual consta de **dos bloques** definidos separados por una linea en blanco (*empty line*).
- En el primer bloque se encuentran todos los rangos, definidos como valores de minimo y maximo [*min, max*].
- El segundo bloque contiene los id de cada uno de los ingredientes a comprobar.

El objetivo final se basa en **contabilizar cuantos ingredientes del segundo bloque se consideran frescos**.

## Justificación de la elección del problema

El problema fue seleccionado ya que, pese a sus sencillez conceptual, presenta caracteristicas que lo hacian apto para integrar estructuras mas complejas que nos podian ser util para la entrega de este trabajo.

En particular, tanto los rangos como los ids abarcaban numeros muy grandes, lo que implicaba el uso de `long long`, con el cual si intentabamos resolverlas por metodos directos podia tener un alto coste.

Por este motivo, el problema se prestaba para la utilizacion de arboles, especificamente un arbol de intervalos (*Interval Trees*).

## Técnicas y estructuras de datos empleadas

Para la resolucion de este problema, se ha empleado, como se ha mencionado anteriormente, la estructura de arbol de intervalos, asi como tambien se ha usado la tecnica de recursividad para implementar algunas de las funciones de la clase `BSTree`.

## Descripción de la resolución del problema

Para la resolcución de este problema se ha implementado una estructura de arbol basado en intervalos, de ma era que se ha creado dos archivos.h.

Por un lado tenemos BSNode.h, el cual contiene la clase BSNode, que implementa un nodo. Para este problema era necesario tener la capacidad de guardar rangos por lo que se procedio a crear dos variables (inicio, fin), los cuales marcaban los extremos del intervalo.

Por otro lado tambien se ha creado el archivo BSTree.h, el cual contiene la clase BSTree, que implementa un arbol de intervalos (se dice que es de intervalos ya que, el nodo no solo contine un elemente sino el intervalo antes mencionado en BSNode). En esta clase se encuentran las funciones insert y search:

- Seach: esta se trada de un funcion booleana a la cual se le paso como argumento un valor (identificador) y un nodo. Lo que realiza internamente es comparar el identificador con los rangos del nodo y dependiendo si es mayot o menor, explora el lado izquierdo o derecho del arbol. Cuando encuetra una coincidencia devuelve True sino devuekve False.
- Insert: a esta funcion se le pasa un rango como argumento y dependiendo del valor de estos se inserta en el arbol (compara los valores del nuevo rango con los de los nodos actuales para saber si desplazarse a la izquierda o a la derecha).

Para la lectura del archivo input (en el main) se utilizafo tanto ifstream como getline() para poder leer linea a linea el documento. Este, como ya se ha dicho en apartados anteriores, esta dividido en dos bloques, lo que ha mejorado su lectura. Sabiendo que el primer bloque eran los rangos, se ha procedido a crar una variable booleana que indicase cuando se estuvieran leyendo rangos y cuando no, es decir cuando se estuviera leyendo identificadores. Esta variable se inicializa en un principio a True ya que al principio del documento se encuentran los rangos, cuando se encuentra con una linea en blanco (empty line) esta variable pasa a estar a False, lo que indica que empizan los identificadores.

- Cuando rangos == True se llama a la funcion insert y se inserta el el lugar correspondiente el nodo con los intervalor en el arbol (previamente inicializado).
- Por otro lado cuando rangos == False se llama a la funcion seach, la cual busca si el identificador de la linea leida se encuentra en algun rango, si esto se da, la varible definitivo se incrementa (definitivo++), esta es la variable que lleva la cuenta de los alimentos frescos encontrados y se inicializa previamente en 0. Si no el identificador no se encuentra continua con la siguente linea. 

Por último se imprime por pantalla la variable definitivos con un cout.

## Alternativas para mejorar la resolución

En este problema se habian propuesto otras alternativas de solución. Como se ha mencionado en apartados anteriores, en un principio existia la posibilidad de realizar la busqueda de manera directa con arrays y vectores, sin embargo, al ver la longitud del documento y los datos, se opto por descartala ya que haria la busqueda muy pesada. Ademas concluimos en que este problema sería una problema en el cual se podria implementar arboles, lo que favorecia al trabajo.

## Valoración personal 


