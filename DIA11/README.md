# Advent of Code 2025 — Día 11: Reactor 

## Componentes del grupo 

- Sonia S Galeas
- Marcos Mérida Bustamante 
- Lucía Remolar
- Marta Ros

## Descripción del problema

El problema consiste en analizar un sistema de dispositivos conectados entre sí mediante salidas dirigidas.

Cada línea del archivo input define un dispositivo electrónico y la lista de otros dispositivos a los que envía datos. Por ejemplo, la instrucción `aaa: you hhh`, indica que el dispositivo `aaa` tiene dos salidas válidas, una hacia `you` y otra hacia `hhh`.

Ejemplo de la lista de dispositivos
```
aaa: you hhh
you: bbb ccc
bbb: ddd eee
ccc: ddd eee fff
ddd: ggg               <- Los dispositivos pueden tener listas más largas o menos que otras
eee: out                  Ruta válida: you-> bbb-> ddd-> ggg-> out
fff: out
ggg: out
hhh: ccc fff iii
iii: out
```

Las reglas del sistema serían las siguientes:

- Los datos solo pueden ir hacia adelante, no pueden ir en sentido inverso.
- Un camino se considera válido si se construye desde `you` hasta `out`.

El objetivo final es el de contabilizar cuántos caminos distintos existen entre el dispositivo inicial (`you`) hasta el dispositivo final (`out`).

## Justificación de la elección del problema

Este problema fue seleccionado ya que, aunque el planteamiento pueda entenderse como sencillo, permite aplicar diferentes estructuras útiles para el desarrollo de este trabajo. Como lo pueden ser grafos (el problema en sí tiene forma de grafo por lo que esta estructura ha sido implementada directamente).

## Técnicas y estructuras de datos empleadas

Para la resolución de este problema se ha decidido implementar tanto **grafos**, como se ha mencionado en el apartado anterior, ya que la estructura de dispositivos con salidas dirigidas, es en sí la estructura de un grafo. Además también se ha implementado la estructura de **Tabla Hash** para poder almacenar y buscar dispositivos por nombre. También se ha implementado la recursividad para poder explorar todos los caminos desde `you` hasta `out`.

## Descripción de la resolución del problema

Para la resolución de este problema se han implementado dos estructuras:

- `struct Nodo` que contiene una variable que guarda el nombre del dispositivo, un vector de punteros llamado `salidas` que guarda los dispositivos a los que se puede dirigir y un último puntero `next` que maneja las colisiones en la Tabla Hash.
- `struct Hash`, que contiene un array de punteros a nodos, a este se le ha fijado un tamaño fijo de 400.

Por otro lado se han implementado otra serie de funciones, las cuales serían:

- `iniciarTabla(Hash &h)`, esta inicializa la Tabla Hash, poniendo todos los punteros vacíos (`nullptr`).
- `int nombre_a_numero(const char *nombre)`, esta convierte el nombre de un dispositivo en un índice para la Tabla Hash, de manera que sumo los valores *ASCII* y aplica el módulo con el tamaño de la tabla (`tam`).
- `buscar_nombre(Hash &h, const char *nombre)`, esta función busca si existe un nodo con ese nombre en la tabla, de manera que calcula su índice, recorre la lista y hace uso de `next` si se diera una colisión.
- `crear_nodo(Hash &h, const char *nombre)`, esta función crea un nodo si no existe, sino devuelve el existente, crea un nuevo nodo (`new Nodo`), copia el nombre y lo inserta haciendo uso de `next` para manejar las colisiones.
- `crear_grafo(Hash &h, ifstream &archivo)`, esta función es la encargada de construir el grafo, leyendo el archivo input línea a línea gracias a `getline()`. Se divide la línea en `origen: destino1 destino2...`, crea el nodo de origen y sus nodos destino y añade las conexiones con `salidas`.
- `definitivo(Nodo *inicio, Nodo *fin)`, por último esta función contabiliza cuántos caminos distintos existen entre inicio y fin, de manera que si el nodo actual es destino devuelve 1, es decir ha encontrado un camino, si no, recorre todas las salidas y llama recursivamente a `definitivo`, acumulando el resultado de cada llamada.

En el `main`, se procede a abrir el archivo, construir el grafo, llamando a `crear_grafo`, busca los nodos de `you` y `out` en la Tabla Hash y llama a definitivo para calcular todos los caminos existentes, este resultado se guarda en la variable total, que se imprime por pantalla con `cout`.

## Alternativas rechazadas

En el planteamiento de este problema se pensó en solucionarlo únicamente con grafos o de manera directa, ya que era lo más evidente en un principio, sin embargo, al final se optó por introducir una Tabla Hash ya que esta reducía la búsqueda de los nodos de inicio y fin.

## Valoración grupal 

Finalmente, todos los miembros del equipo coincidimos en que este problema ha sido una buena elección, ya que nos permitió implementar dos estructuras (grafos y Tabla Hash), pese a que durante el desarrollo surgieran dudas sobre la implementación de un solo tipo de estructura, la decisión final de combinarlas fue acertada y nos permitió aprender más sobre ambas estructuras.
