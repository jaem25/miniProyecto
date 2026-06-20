#ifndef VIDEOJUEGOSMARKET_H
#define VIDEOJUEGOSMARKET_H

#include <string>

const int MAX_VIDEOJUEGOS = 100;

struct Videojuego {
    std::string codigo;
    std::string nombre;
    double precio;
    int cantidad;
};

// Declaracion de las funciones del sistema
int buscarPorCodigo(const Videojuego inventario[], int total, std::string codigo);
void registrarVideojuego(Videojuego inventario[], int &total);
void mostrarInventario(const Videojuego inventario[], int total);
void buscarVideojuego(const Videojuego inventario[], int total);
void registrarVenta(Videojuego inventario[], int total);
void reabastecerInventario(Videojuego inventario[], int total);
void mostrarEstadisticas(const Videojuego inventario[], int total);

#endif