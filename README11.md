# Advent of Code 2025 — Día 11: Reactor 

## Componentes del grupo 

- Sonia S Galeas
- Marcos Mérida Bustamante 
- Lucía Remolar
- Marta Ros

## Descripción del problema

El problema consiste en analizar un sistema de dispositivos conectados entre sí mediante salidas dirigidas.

Cada linea del archivo input define un dispositovo electronico y la lista de otros dispositivos a los que envia datos. Por ejemplo, la instruccion `aaa: you hhh`, indica que el dispositivo `aaa` tiene dos salidas validas, una hacia `you` y otra hacia `hhh`.

Ejemplo de la lista de dispositivos
```
aaa: you hhh
you: bbb ccc
bbb: ddd eee
ccc: ddd eee fff
ddd: ggg               <- Los dispositivos pueden tener listas mas largas o menos que otras
eee: out                  Ruta valida: you-> bbb-> ddd-> ggg-> out
fff: out
ggg: out
hhh: ccc fff iii
iii: out
```

La reglas del sistema serian las siguientes:

- Los datos solo pueden ir hacia adelante, no pueden ir en sentido inverso.
- Un camino se considera valido si se contruye desde `you` hasta `out`.

El objetivo final es el de contabilizar cuantos caminos distintos existen entre el dispositivo inicial (`you`) hasta el dispositivo final (`out`).

## Justificación de la elección del problema

Este problema fue seleccionado ya que, aunque el planteamiento pueda entenderse como sencillo, permite aplicar diferentes estructuras utiles para el desarrollo de este trabajo. Como lo pueden ser grafos (el problema en sí tiene forma de grafo por lo que esta estructura ha sido implementada directamente).

## Técnicas y estructuras de datos empleadas

Para la resolucion de este problema se ha decidido implementar tanta **grafos**, como se ha mencionado en el apartado anterior, ya que la estructura de dispositivos con salidas dirigidas, es en sí la estructura de un grafo. Además también se ha implementado la estructura de **Tabla Hash** para poder almacenar y buscar dispositivos por nombre. También se ha implementado la recursividad para poder explorar todos los caminos desde `you` hasta `out`.

## Descripción de la resolución del problema

Para la resolución de este problema se impelemtado dos estructuras:

- `struct Nodo` que contine una varible que guarda el nombre del dispositivo, un vector de punteros llamado `salidas` que guarda lo dispositivos a los que se puede dirigir y un último puntero `next` que maneja las colisiones en la Tabla Hash.
- `struct Hash`, que contine un array de punteros a nodos, a este se le ha fijado un tamaño fijo de 400.

Por otro lado se han implementado otra serie de funciones, las cuales serían:

- `iniciarTabla(Hash &h)`, esta inicializa la Tabla Hash, poniendo todos los punteros vacios (`nullptr`).
- `int nombre_a_numero(const char *nombre)`, esta convierte el nombre de un dispositivo en un índice para la Tabla Hash, de manera que sumo los valores *ASCII* y aplica el modulo con el tamaño de la tabla (`tam`).
- `buscar_nombre(Hash &h, const char *nombre)`, esta función busca si existe un nodo con el ese nombre en la tabla, de manera que calcula su indice, recorre la lista y hace uso de `next` si se diera una colisión.
- `crear_nodo(Hash &h, const char *nombre)`, esta función crea un nodo si no existe, sino devuelve el existente, crea un nuevo nodo (`new Nodo`), copia el nombre y lo inserta haciendo uso de `next`para manejar las colisiones.
- `crear_grafo(Hash &h, ifstream &archivo)`, esta función es la encargada de contruir el grafo, leyendo el archivo input liena a linea gracias a `getline()`. Se divide la linea en `origen: destino1 destino2...`, crea el nodo de origen y sus nodos destino y añade las conexiones con `salidas`.
- `definitivo(Nodo *inicio, Nodo *fin)`, por último esta funcion contabiliza cuantos caminos distintos existen entre inicio y fin, de manera que si el nodo actual es destino devuelve 1, es decir ha encontrado un camino, si no, recorre todas las salidas y llama recursivamente a `definitivo`, acumulando el resultado de cada llamada.

En el `main`, se procede a abrir el archivo, contruir el grafo, llamando a `crear_grafo`, busca los nodos de `you` y `out` en la Tabla Hash y llama a definitivo para calcular todos los caminos existentes, este resultado se guarda en la variable total, que se imprime por pantalla con `cout`.

## Alternativas rechazadas

En el planteamiento de este problema se pensó en solucionarlo unicamente con grafos o de manera directa, ya que era lo mas evidente en un principio, sin embargo, al final se opto por introducir una Tabla Hash ya que esta reducia la busqueda de los nodos de inicio y fin.

## Valoración grupal 

Finalmente, todos los miembros del equipo coincidimos en que este problema ha sido una buena elección, ya que nos permitió implementar dos estructuras (grafos y Tabla Hash), pese a que durante el desrrollo surgieran dodas sobre la implementacion de un solo tipo de estructura, la decision final de combinarlas fue acertada y nos permitió aprender más sobre ambas estructuras.
