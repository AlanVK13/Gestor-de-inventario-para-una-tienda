** Sistema de Gestión de Inventario en C++ **

Este es un proyecto de consola desarrollado en C++ con el objetivo de practicar conceptos fundamentales de programación y lógica. El programa simula un sistema básico de inventario donde se pueden registrar, buscar, modificar y ordenar productos.

🚀 Conceptos Practicados

El objetivo principal de este proyecto fue aplicar y reforzar los siguientes elementos del lenguaje C++:

Estructuras (struct): Para definir un tipo de dato personalizado Producto que agrupa ID, nombre, precio y cantidad.

Arreglos (usando std::vector): Para almacenar la colección de productos en el inventario.

Funciones: Para modularizar el código en bloques lógicos (inicializar, mostrar, buscar, ordenar, etc.).

Punteros: Utilizados en las funciones de búsqueda (buscarPorID, buscarPorNombre) para devolver la dirección de memoria del producto encontrado. Esto permite que la función modificarInventario afecte directamente al objeto original en el vector.

Ordenamiento: Implementación del algoritmo Método de Burbuja para ordenar el inventario por precio y por cantidad.

Manejo de Excepciones (try...catch, throw): Para un manejo robusto de errores, especialmente cuando un producto buscado no se encuentra.

Manejo de Entrada/Salida (iostream, iomanip): Para crear un menú interactivo y formatear la salida de datos en una tabla limpia.

📋 Funcionalidades

Mostrar Inventario Completo: Lista todos los productos en el inventario con su ID, nombre, precio y cantidad.

Buscar por ID: Busca un producto específico usando su ID.

Buscar por Nombre: Busca un producto específico usando su nombre exacto.

Modificar Inventario: Permite cambiar la cantidad de un producto existente, buscándolo primero por su ID.

Ordenar por Precio: Muestra el inventario ordenado del producto más barato al más caro.

Ordenar por Cantidad: Muestra el inventario ordenado del producto con menor cantidad al con mayor cantidad.

Validación de Entrada: El programa maneja entradas no numéricas en el menú.
