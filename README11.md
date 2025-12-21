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

Para la resolucion de este problema se ha decidido implementar tanta `grafos`, como se ha mencionado en el apartado anterior, ya que la estructura de dispositivos con salidas dirigidas, es en sí la estructura de un `grafo`. Además también se ha implementado la estructura de `Tabla Hash` 

## Descripción de la resolución del problema



## Alternativas rechazadas



## Valoración personal 




