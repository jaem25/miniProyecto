#include "videojuegosmarket.h"
#include <iostream>
using namespace std;

void registrarVideojuego(Videojuego inventario[], int &total) 
{
    if (total >= MAX_VIDEOJUEGOS) 
    {
        cout << endl << "ERROR inventario esta lleno" << endl;
        return;
    }
    string codigoBuscado;
    cout << endl << "----- REGISTRAR NUEVO VIDEOJUEGO -----" << endl;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigoBuscado;
    bool codigoRepetido = false;
    for (int i = 0; i < total; i++) 
    {
        if (inventario[i].codigo == codigoBuscado) 
        {
            codigoRepetido = true;
        }
    }
    if (codigoRepetido == true) 
    {
        cout << "ERROR Ese codigo ya pertenece a otro videojuego" << endl;
        return;
    }
    inventario[total].codigo = codigoBuscado;
    
    cout << "Ingrese el nombre (use guiones en vez de espacios, por favor): ";
    cin >> inventario[total].nombre;
    
    cout << "Ingrese el precio: $";
    cin >> inventario[total].precio;
    
    cout << "Ingrese la cantidad inicial en stock: ";
    cin >> inventario[total].cantidad;

    total = total + 1;
    cout << endl << "El videojuego ha sido registrado correctamente" << endl;
}
void mostrarInventario(const Videojuego inventario[], int total) 
{
    if (total == 0) 
    {
        cout << endl << "El inventario esta vacio" << endl;
        return;
    }
    cout << endl << "----- INVENTARIO DE PRODUCTOS -----" << endl;
    cout << "CODIGO | NOMBRE | PRECIO | STOCK" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < total; i++) 
    {
        cout << inventario[i].codigo << " | " << inventario[i].nombre << " | $" 
            << inventario[i].precio << " | " << inventario[i].cantidad << endl;
    }
    cout << "---------------------------------------" << endl;
}
void buscarVideojuego(const Videojuego inventario[], int total) 
{
    string codigoBuscado;
    cout << endl << "Ingrese el codigo del videojuego que busca: ";
    cin >> codigoBuscado;
    bool encontrado = false;
    for (int i = 0; i < total; i++) 
    {
        if (inventario[i].codigo == codigoBuscado) 
        {
            cout << endl << "----- DETALLES DEL VIDEOJUEGO -----" << endl;
            cout << "Codigo: " << inventario[i].codigo << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Precio: $" << inventario[i].precio << endl;
            cout << "Stock: " << inventario[i].cantidad << " unidades" << endl;
            encontrado = true;
        }
    }
    if (encontrado == false) 
    {
        cout << endl << "ERROR Videojuego no encontrado :(" << endl;
    }
}
void registrarVenta(Videojuego inventario[], int total) 
{
    string codigoBuscado;
    cout << endl << "----- REGISTRAR VENTA -----" << endl;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigoBuscado;
    bool encontrado = false;
    for (int i = 0; i < total; i++) 
    {
        if (inventario[i].codigo == codigoBuscado) 
        {
            encontrado = true;
            int cantidadAVender;
            cout << "Producto: " << inventario[i].nombre << " (Tenemos disponibles: " << inventario[i].cantidad << "unidades)" << endl;
            cout << "Ingrese la cantidad a vender: ";
            cin >> cantidadAVender;
            if (cantidadAVender <= 0) 
            {
                cout << "ERROR Cantidad invalida." << endl;
            } else if (cantidadAVender > inventario[i].cantidad) 
            {
                cout << "No hay suficientes unidades en inventario... lo sentimos mucho :(" << endl;
            } else 
            {
                inventario[i].cantidad = inventario[i].cantidad - cantidadAVender;
                double totalPagar = cantidadAVender * inventario[i].precio;
                cout << endl << "VENTA REALIZADA CON EXITO" << endl;
                cout << "Total a pagar: $" << totalPagar << endl;
                cout << "Inventario actualizado: " << inventario[i].cantidad << " unidades." << endl;
            }
        }
    }
    if (encontrado == false) 
    {
        cout << "ERROR El codigo no existe en el sistema" << endl;
    }
}
void reabastecerInventario(Videojuego inventario[], int total) 
{
    string codigoBuscado;
    cout << endl << "----- REABASTECER INVENTARIO -----" << endl;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigoBuscado;

    bool encontrado = false;

    for (int i = 0; i < total; i++) 
    {
        if (inventario[i].codigo == codigoBuscado) 
        {
            encontrado = true;
            int nuevaCantidad;
            
            cout << "Producto: " << inventario[i].nombre << " (Stock actual: " << inventario[i].cantidad << ")" << endl;
            cout << "Ingrese la cantidad de unidades que van a ingresar: ";
            cin >> nuevaCantidad;
            if (nuevaCantidad <= 0) 
            {
                cout << "ERROR Cantidad ingresada invalida" << endl;
            } else {
                inventario[i].cantidad = inventario[i].cantidad + nuevaCantidad;
                cout << endl << "El inventario fue actualizado. Nuevo stock: " << inventario[i].cantidad << endl;
            }
        }
    }
    if (encontrado == false) 
    {
        cout << "ERROR El videojuego no esta registrado" << endl;
    }
}
void mostrarEstadisticas(const Videojuego inventario[], int total) 
{
    if (total == 0) 
    {
        cout << endl << "No hay datos en el sistema para calcular estadisticas" << endl;
        return;
    }
    int totalUnidades = 0;
    int indiceMayor = 0;
    for (int i = 0; i < total; i++) 
    {
        totalUnidades = totalUnidades + inventario[i].cantidad;
        
        if (inventario[i].cantidad > inventario[indiceMayor].cantidad) 
        {
            indiceMayor = i;
        }
    }
    cout << endl << "----- ESTADISTICAS DE VIDEOJUEGOS MARKET -----" << endl;
    cout << "Modelos de videojuegos en catalogo: " << total << endl;
    cout << "Total de productos fisicos en tienda: " << totalUnidades << endl;
    cout << "Juego con mas existencias en tienda: " << inventario[indiceMayor].nombre 
        << " (" << inventario[indiceMayor].cantidad << " unidades)" << endl;
}