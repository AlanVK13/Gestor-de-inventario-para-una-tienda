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

## 🛠️ Cómo Compilar y Ejecutar

Este proyecto está escrito en C++ estándar y puede ser compilado con `g++` (MinGW).

1.  **Clonar el repositorio (o descargar el archivo `inventario.cpp`):**
    ```bash
    git clone [https://github.com/TU_USUARIO/TU_REPOSITORIO.git](https://github.com/TU_USUARIO/TU_REPOSITORIO.git)
    cd TU_REPOSITORIO
    ```

2.  **Compilar el programa:**
    Abre una terminal (como GitBash) en la carpeta del proyecto y ejecuta el siguiente comando:
    ```bash
    g++ inventario.cpp -o inventario.exe
    ```
    *Esto creará un archivo ejecutable llamado `inventario.exe`.*

3.  **Ejecutar el programa:**
    ```bash
    ./inventario.exe
    ```

## 💻 Ejemplo de Interfaz

Al ejecutar el programa, se desplegará el siguiente menú:
