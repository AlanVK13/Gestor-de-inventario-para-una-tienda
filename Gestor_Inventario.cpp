

// --- LIBRERÍAS ---
// Para entrada y salida en consola (cout, cin)
#include <iostream>
// Para usar el tipo de dato string
#include <string>
// Para usar 'vectores' (arreglos dinámicos modernos)
#include <vector>
// Para manejo de errores (excepciones estándar)
#include <stdexcept>
// Para formatear la salida (setw, left)
#include <iomanip>
// Para std::numeric_limits (usado para limpiar el buffer de cin)
#include <limits>
// Para std::swap (usado en el ordenamiento)
#include <algorithm>

// Usar los nombres estándar para no escribir std:: a cada rato
using namespace std;

// --- REQUERIMIENTO 1: ESTRUCTURAS ---
// Definimos la plantilla para nuestros productos.
// 'struct' es un tipo de dato que agrupa otras variables.
struct Producto {
    int id;
    string nombre;
    double precio;
    int cantidad;
};

// --- ALMACÉN DE DATOS (Arreglo) ---
// Usamos un vector de 'Producto'. Es como un arreglo pero más
// flexible y moderno. Este será nuestro inventario global.
vector<Producto> inventario;

// --- PROTOTIPOS DE FUNCIONES ---
// Le decimos al compilador qué funciones existen.
// La implementación (el código) está más abajo.
void inicializarInventario();
void mostrarProducto(const Producto& p);
void mostrarInventario(const vector<Producto>& inv);
Producto* buscarPorID(int id);
Producto* buscarPorNombre(const string& nombre);
void modificarInventario(Producto* productoPtr);
void ordenarPorPrecio();
void ordenarPorCantidad();
void limpiarBufferEntrada();
void esperarEnter();