

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

/**
 * @brief Función Principal - Punto de entrada del programa
 */
int main() {
    // Llenamos el inventario con datos de prueba
    inicializarInventario();

    int opcion = -1;
    do {
        // --- MENÚ PRINCIPAL ---
        cout << "\n--- SISTEMA DE GESTION DE INVENTARIO ---" << endl;
        cout << "1. Mostrar Inventario Completo" << endl;
        cout << "2. Buscar Producto por ID" << endl;
        cout << "3. Buscar Producto por Nombre" << endl;
        cout << "4. Modificar Cantidad de Inventario (por ID)" << endl;
        cout << "5. Ordenar Inventario por Precio" << endl;
        cout << "6. Ordenar Inventario por Cantidad" << endl;
        cout << "0. Salir" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Seleccione una opcion: ";

        // Leemos la opción del usuario
        cin >> opcion;

        // Validamos si la entrada fue un número
        if (cin.fail()) {
            cout << "Error: Por favor ingrese solo numeros." << endl;
            cin.clear(); // Limpia el estado de error
            limpiarBufferEntrada(); // Descarta la entrada incorrecta
            continue; // Vuelve al inicio del bucle
        }

        // Limpiamos el buffer de entrada después de leer un número
        // para que no interfiera con futuros 'getline'
        limpiarBufferEntrada();

        // --- REQUERIMIENTO 6: MANEJO DE EXCEPCIONES ---
        // Usamos try-catch para manejar errores controlados (ej: producto no encontrado)
        try {
            switch (opcion) {
                case 1:
                    cout << "\n--- Inventario Actual ---" << endl;
                    mostrarInventario(inventario);
                    break;
                case 2: { // Buscar por ID
                    int id;
                    cout << "Ingrese el ID del producto a buscar: ";
                    cin >> id;
                    limpiarBufferEntrada();
                    
                    cout << "\n--- Resultado de la Busqueda ---" << endl;
                    Producto* p = buscarPorID(id); // Lanza excepción si no lo encuentra
                    mostrarProducto(*p); // Muestra el producto encontrado
                    break;
                }
                case 3: { // Buscar por Nombre
                    string nombre;
                    cout << "Ingrese el Nombre del producto a buscar: ";
                    getline(cin, nombre); // Leemos el nombre completo

                    cout << "\n--- Resultado de la Busqueda ---" << endl;
                    Producto* p = buscarPorNombre(nombre); // Lanza excepción si no lo encuentra
                    mostrarProducto(*p);
                    break;
                }
                case 4: { // --- REQUERIMIENTO 5: USO DE PUNTEROS ---
                    int idModificar;
                    cout << "Ingrese el ID del producto a modificar: ";
                    cin >> idModificar;
                    limpiarBufferEntrada();

                    // 1. Buscamos el producto y obtenemos un puntero
                    Producto* pModificar = buscarPorID(idModificar);
                    
                    // 2. Pasamos ese puntero a la función de modificar
                    modificarInventario(pModificar);
                    break;
                }
                case 5: // --- REQUERIMIENTO 3: ORDENAMIENTO ---
                    cout << "\nOrdenando por Precio..." << endl;
                    ordenarPorPrecio();
                    mostrarInventario(inventario);
                    cout << "Inventario ordenado por precio." << endl;
                    break;
                case 6: // --- REQUERIMIENTO 3: ORDENAMIENTO ---
                    cout << "\nOrdenando por Cantidad..." << endl;
                    ordenarPorCantidad();
                    mostrarInventario(inventario);
                    cout << "Inventario ordenado por cantidad." << endl;
                    break;
                case 0:
                    cout << "Saliendo del sistema..." << endl;
                    break;
                default:
                    cout << "Opcion no valida. Intente de nuevo." << endl;
                    break;
            }
        }
        // Capturamos cualquier excepción 'runtime_error' (como "No encontrado")
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
        // Capturamos cualquier otra excepción inesperada
        catch (...) {
            cout << "Ocurrio un error inesperado." << endl;
        }

        if (opcion != 0) {
            esperarEnter();
        }

    } while (opcion != 0);

    return 0; // Termina el programa
}

// --- IMPLEMENTACIÓN DE FUNCIONES ---

/**
 * @brief Limpia el buffer de entrada de cin.
 * Se usa después de leer un número (con 'cin >>')
 * para evitar problemas al leer texto (con 'getline').
 */
void limpiarBufferEntrada() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Pausa la ejecución hasta que el usuario presione Enter.
 */
void esperarEnter() {
    cout << "\nPresione Enter para continuar...";
    // No es necesario limpiar el buffer aquí porque
    // el 'limpiarBufferEntrada' del bucle principal ya lo hizo.
    // Si no fuera así, aquí iría un cin.get() o similar.
}


/**
 * @brief REQUERIMIENTO: REGISTRO DE 10 PRODUCTOS
 * Añade 10 productos de ejemplo a nuestro vector 'inventario'.
 */
void inicializarInventario() {
    inventario.push_back({101, "Leche", 25.50, 150});
    inventario.push_back({102, "Pan", 5.00, 300});
    inventario.push_back({103, "Huevos (docena)", 40.00, 100});
    inventario.push_back({104, "Jamon (kg)", 120.75, 50});
    inventario.push_back({105, "Queso (kg)", 99.90, 60});
    inventario.push_back({106, "Manzanas (kg)", 45.20, 80});
    inventario.push_back({107, "Refresco (2L)", 32.00, 120});
    inventario.push_back({108, "Arroz (kg)", 22.00, 200});
    inventario.push_back({109, "Frijol (kg)", 28.50, 180});
    inventario.push_back({110, "Aceite (1L)", 55.00, 90});
}

/**
 * @brief Muestra un solo producto con formato.
 * @param p Producto a mostrar (pasado por referencia constante).
 */
void mostrarProducto(const Producto& p) {
    cout << " | " << left << setw(5) << p.id
         << " | " << left << setw(20) << p.nombre
         << " | $" << left << setw(10) << fixed << setprecision(2) << p.precio
         << " | " << left << setw(8) << p.cantidad << " |" << endl;
}

/**
 * @brief REQUERIMIENTO: FUNCIÓN PARA MOSTRAR
 * Recorre el vector e imprime todos los productos.
 * @param inv El vector de inventario a mostrar.
 */
void mostrarInventario(const vector<Producto>& inv) {
    cout << " ----------------------------------------------------------------" << endl;
    cout << " | " << left << setw(5) << "ID"
         << " | " << left << setw(20) << "Nombre"
         << " | " << left << setw(11) << "Precio"
         << " | " << left << setw(8) << "Cantidad" << " |" << endl;
    cout << " ----------------------------------------------------------------" << endl;
    for (const Producto& p : inv) {
        mostrarProducto(p);
    }
    cout << " ----------------------------------------------------------------" << endl;
}

/**
 * @brief REQUERIMIENTO: BÚSQUEDA POR ID
 * Busca un producto por su ID en el inventario global.
 * @param id El ID del producto a buscar.
 * @return Un PUNTERO al producto encontrado dentro del vector.
 * @throws runtime_error si el producto no se encuentra.
 */
Producto* buscarPorID(int id) {
    for (int i = 0; i < inventario.size(); ++i) {
        if (inventario[i].id == id) {
            // Devuelve la dirección de memoria (puntero) del producto
            // encontrado DENTRO del vector.
            return &inventario[i];
        }
    }
    // REQUERIMIENTO: MANEJO DE EXCEPCIONES
    throw runtime_error("Producto no encontrado con ese ID.");
}

/**
 * @brief REQUERIMIENTO: BÚSQUEDA POR NOMBRE
 * Busca un producto por su Nombre en el inventario global.
 * @param nombre El Nombre del producto a buscar.
 * @return Un PUNTERO al producto encontrado.
 * @throws runtime_error si el producto no se encuentra.
 */
Producto* buscarPorNombre(const string& nombre) {
    for (int i = 0; i < inventario.size(); ++i) {
        if (inventario[i].nombre == nombre) {
            return &inventario[i]; // Devuelve el puntero
        }
    }
    // REQUERIMIENTO: MANEJO DE EXCEPCIONES
    throw runtime_error("Producto no encontrado con ese Nombre.");
}

/**
 * @brief REQUERIMIENTO: USO DE PUNTEROS PARA MODIFICAR
 * Modifica la cantidad de un producto usando un puntero.
 * @param productoPtr Un puntero al producto que se va a modificar.
 */
void modificarInventario(Producto* productoPtr) {
    // El puntero ya fue validado por la excepción en 'buscarPorID'
    // pero una buena práctica sería: if (productoPtr == nullptr) return;

    cout << "\n--- Modificando Producto ---" << endl;
    mostrarProducto(*productoPtr); // Muestra el producto actual

    int nuevaCantidad;
    cout << "Ingrese la nueva cantidad en inventario: ";
    cin >> nuevaCantidad;
    limpiarBufferEntrada();

    if (cin.fail() || nuevaCantidad < 0) {
        cout << "Cantidad no valida." << endl;
        cin.clear();
        limpiarBufferEntrada();
        return;
    }

    // Usamos el puntero (con el operador '->') para
    // modificar directamente el objeto original en el vector.
    productoPtr->cantidad = nuevaCantidad;

    cout << "¡Inventario actualizado con exito!" << endl;
    mostrarProducto(*productoPtr);
}

/**
 * @brief REQUERIMIENTO: ORDENAMIENTO (MÉTODO DE BURBUJA)
 * Ordena el vector 'inventario' global por precio (menor a mayor).
 */
void ordenarPorPrecio() {
    int n = inventario.size();
    // Bucle externo: controla cuántas pasadas hacemos
    for (int i = 0; i < n - 1; ++i) {
        // Bucle interno: hace las comparaciones y swaps
        // 'j' va desde el inicio hasta el final *menos* los que ya están ordenados (i)
        for (int j = 0; j < n - i - 1; ++j) {
            // Comparamos el elemento actual con el siguiente
            if (inventario[j].precio > inventario[j + 1].precio) {
                // Si están en el orden incorrecto, los intercambiamos
                swap(inventario[j], inventario[j + 1]);
            }
        }
    }
}

/**
 * @brief REQUERIMIENTO: ORDENAMIENTO (MÉTODO DE BURBUJA)
 * Ordena el vector 'inventario' global por cantidad (menor a mayor).
 */
void ordenarPorCantidad() {
    int n = inventario.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // La única diferencia es la variable que comparamos
            if (inventario[j].cantidad > inventario[j + 1].cantidad) {
                swap(inventario[j], inventario[j + 1]);
            }
        }
    }
}