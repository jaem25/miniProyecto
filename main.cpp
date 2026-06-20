#include <iostream>
#include "videojuegosmarket.h"

using namespace std;

int main() {
    Videojuego inventario[MAX_VIDEOJUEGOS];
    int totalVideojuegos = 0; 
    int opcion;

    do {
        cout << endl << "--------------------------------" << endl;
        cout << "         VIDEOJUEGOS MARKET          " << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Registrar un videojuego" << endl;
        cout << "2. Mostrar el inventario" << endl;
        cout << "3. Buscar un videojuego" << endl;
        cout << "4. Registrar una venta" << endl;
        cout << "5. Reabastecer el inventario" << endl;
        cout << "6. Ver estadisticas generales" << endl;
        cout << "7. Salir del programa" << endl;
        cout << "-----------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVideojuego(inventario, totalVideojuegos);
                break;
            case 2:
                mostrarInventario(inventario, totalVideojuegos);
                break;
            case 3:
                buscarVideojuego(inventario, totalVideojuegos);
                break;
            case 4:
                registrarVenta(inventario, totalVideojuegos);
                break;
            case 5:
                reabastecerInventario(inventario, totalVideojuegos);
                break;
            case 6:
                mostrarEstadisticas(inventario, totalVideojuegos);
                break;
            case 7:
                cout << endl << "Saliendo del programa... Gracias por usar Videojuegos Market" << endl;
                break;
            default:
                cout << endl << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);

    return 0;
}