# Sistema de Gestión de Inventario en C++

Este es un proyecto de consola desarrollado en C++ que simula un sistema básico de inventario. El objetivo principal fue poner en práctica y reforzar conceptos fundamentales del lenguaje, como el manejo de memoria, estructuras de datos y algoritmos de ordenamiento.

## 🚀 Conceptos Practicados

Este proyecto fue un ejercicio para aplicar los siguientes pilares de C++:

* **Estructuras (`struct`):** Se utilizó para crear un tipo de dato personalizado `Producto`, agrupando sus propiedades (ID, nombre, precio, cantidad).
* **Arreglos (usando `std::vector`):** Se usó `std::vector` como un arreglo dinámico moderno para almacenar la colección de todos los productos en el inventario.
* **Funciones:** El código está modularizado en funciones, cada una con una responsabilidad única (mostrar, buscar, ordenar, etc.), lo que facilita su lectura y mantenimiento.
* **Punteros:** Una parte clave del proyecto. Las funciones de búsqueda (`buscarPorID`, `buscarPorNombre`) devuelven un puntero al producto encontrado dentro del vector. Esto permite que la función `modificarInventario` trabaje directamente sobre el objeto original, alterando el inventario de forma eficiente.
* **Algoritmos de Ordenamiento:** Se implementó el **Método de Burbuja** desde cero para ordenar el inventario, ya sea por precio o por cantidad disponible.
* **Manejo de Excepciones (`try...catch`):** Se utiliza para gestionar errores de forma controlada. Por ejemplo, si un usuario busca un ID que no existe, el programa lanza (`throw`) una excepción que es capturada (`catch`) en el menú principal, evitando que el programa termine abruptamente.

## 📋 Funcionalidades

El programa presenta un menú interactivo con las siguientes opciones:

1.  **Mostrar Inventario Completo:** Lista todos los productos registrados, su precio y cantidad.
2.  **Buscar Producto por ID:** Pide un ID numérico y muestra los datos del producto si se encuentra.
3.  **Buscar Producto por Nombre:** Pide un nombre y muestra los datos del producto correspondiente.
4.  **Modificar Cantidad:** Pide el ID de un producto y permite al usuario actualizar la cantidad en stock.
5.  **Ordenar por Precio:** Ordena y muestra la lista completa de productos del más barato al más caro.
6.  **Ordenar por Cantidad:** Ordena y muestra la lista completa de productos del que tiene menor stock al que tiene mayor stock.
7.  **Salir:** Termina la ejecución del programa.

## 💻 Ejemplo de Interfaz

Aquí hay un ejemplo de una sesión de uso que muestra varias funcionalidades:

```bash
--- SISTEMA DE GESTION DE INVENTARIO ---
1. Mostrar Inventario Completo
2. Buscar Producto por ID
...
0. Salir
------------------------------------------
Seleccione una opcion: 2

# El usuario busca un producto por ID
Ingrese el ID del producto a buscar: 103

--- Resultado de la Busqueda ---
 | 103   | Huevos (docena)      | $40.00      | 100      |

Presione Enter para continuar...

--- SISTEMA DE GESTION DE INVENTARIO ---
...
0. Salir
------------------------------------------
Seleccione una opcion: 2

# El usuario busca un ID que no existe (Manejo de Excepciones)
Ingrese el ID del producto a buscar: 999

--- Resultado de la Busqueda ---
Error: Producto no encontrado con ese ID.

Presione Enter para continuar...

--- SISTEMA DE GESTION DE INVENTARIO ---
...
0. Salir
------------------------------------------
Seleccione una opcion: 5

# El usuario ordena los productos por precio
Ordenando por Precio...
 ----------------------------------------------------------------
 | ID    | Nombre               | Precio     | Cantidad |
 ----------------------------------------------------------------
 | 102   | Pan                  | $5.00       | 300      |
 | 108   | Arroz (kg)           | $22.00      | 200      |
 | 101   | Leche                | $25.50      | 150      |
 ... (resto de la lista) ...
 ----------------------------------------------------------------
Inventario ordenado por precio.

Presione Enter para continuar...

--- SISTEMA DE GESTION DE INVENTARIO ---
...
0. Salir
------------------------------------------
Seleccione una opcion: 0

Saliendo del sistema...
