#include "../TercerAvanceProyecto/include/Combustible.h"  // Archivo,h

// Inicialización del miembro estático
int Combustible::totalVentasGasolinaGeneral = 0;

// Constructor
Combustible::Combustible(string constNombreCombustible, double constCantidadDisponible, double constPrecio) {
    nombreCombustible = constNombreCombustible;
    cantidadDisponible = constCantidadDisponible;
    precio = constPrecio;
}

// Getters
string Combustible::getNombreCombustible() { return nombreCombustible; }
double Combustible::getCantidadDisponible() { return cantidadDisponible; }
int Combustible::getTotalVentasGasolinaUnitaria() { return totalVentasGasolinaUnitaria; }
int Combustible::getTotalVentasGasolinaGeneral() { return totalVentasGasolinaGeneral; }
double Combustible::getPrecio() { return precio; }

// Setters
void Combustible::setNombreCombustible(string nombre) { nombreCombustible = nombre; }
void Combustible::setCantidadDisponible(double cantidad) { cantidadDisponible = cantidad; }
void Combustible::setTotalVentasGasolinaUnitaria(int ventas) { totalVentasGasolinaUnitaria = ventas; }
void Combustible::setTotalVentasGasolinaGeneral(int ventas) { totalVentasGasolinaGeneral = ventas; }
void Combustible::setPrecio(double nuevoPrecio) { precio = nuevoPrecio; }

// Métodos personalizados
void Combustible::SumarVentaGasolinaGeneral() {
    totalVentasGasolinaGeneral += 1;
}

void Combustible::SumarVentaGasolinaUnitaria() {
    totalVentasGasolinaUnitaria += 1;
}

void Combustible::imprimirInfoCombustibe() {
    cout << "Nombre de Combustible: " << nombreCombustible << endl;
    cout << "Cantidad Disponible: " << cantidadDisponible << " litros" << endl;
    cout << "Precio por Litro: $" << precio << endl;
    cout << "Total Ventas Gasolina Unitaria: " << totalVentasGasolinaUnitaria << endl;
    cout << "Total Ventas Gasolina en General: " << totalVentasGasolinaGeneral << endl;
}

void Combustible::ActualizarinstanciaEnArchivo(string nombreupdate) {
    ifstream leerArchivo("Combustible.txt");
    ofstream tempArchivo("temp.txt");

    if (!leerArchivo || !tempArchivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string nombreModificar;
    double cantidadModificar;
    double precioModificar;

    bool found = false;

    while (leerArchivo >> nombreModificar >> cantidadModificar >> precioModificar) {
        if (nombreModificar == nombreupdate) {
            // Modificar los datos del cliente
            nombreModificar=getNombreCombustible();
            cantidadModificar=getCantidadDisponible();
            precioModificar=getPrecio();
            found = true;
        }
        // Guardar los datos en el archivo temporal, ya sea modificados o no
        tempArchivo << nombreModificar << " " << cantidadModificar << " " << precioModificar << "\n";
    }

    leerArchivo.close();
    tempArchivo.close();


    remove("Combustible.txt");
    rename("temp.txt", "Combustible.txt");

    if (found) {
        cout << "Cantidad Combustible modificado exitosamente." << endl;
    } else {
        cout << "gasolina no  encontrada." << endl;
    }
}


