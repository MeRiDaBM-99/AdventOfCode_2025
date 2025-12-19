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



## Alternativas para mejorar la resolución



## Valoración personal 
