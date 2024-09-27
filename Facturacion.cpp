#include "../TercerAvanceProyecto/include/Facturacion.h"

// Inicialización de miembros estáticos
double Facturacion::totalGanancias = 0;
string Facturacion::combustibleMasVendido = "No hay ventas";

// Constructor
Facturacion::Facturacion() {}

// Getters
double Facturacion::getTotalGanancias()  {
    return totalGanancias;
}

string Facturacion::getCombustibleMasVendido()  {
    return combustibleMasVendido;
}

// Setters
void Facturacion::setTotalGanancias(double ganancias) {
    totalGanancias = ganancias;
}

void Facturacion::setCombustibleMasVendido(string combustible){
    combustibleMasVendido=combustible;
}

// Métodos personalizados
void Facturacion::imprimirFactura( string nombreCliente, string tipoCliente, string nombreCombustible, double litrosComprados, double descuento, double precioGasolina) {
    double total = litrosComprados * precioGasolina;
    double totalConDescuento = total - descuento;  // Ahora se resta el descuento en lugar de multiplicar por un porcentaje

    cout << "===============================" << endl;
    cout << "         FACTURA DE COMPRA       " << endl;
    cout << "===============================" << endl;
    cout << "Nombre del Cliente: " << nombreCliente << endl;
    cout << "Tipo de Cliente: " << tipoCliente << endl;
    cout << "Nombre de Combustible: " << nombreCombustible << endl;
    cout << "Litros Comprados: " << litrosComprados << " litros" << endl;
    cout << "Precio por Litro: $" << precioGasolina << endl;
    cout << "Descuento Aplicado: $" << descuento << endl;
    cout << "Total a Pagar sin Descuento: $" << total << endl;
    cout << "Total a Pagar con Descuento: $" << totalConDescuento << endl;
    cout << "===============================" << endl;
    
    // Guardar la última factura en un archivo TXT
    ofstream escribirFactura("UltimaFactura.txt");
    escribirFactura << "===============================" << endl;
    escribirFactura << "         FACTURA DE COMPRA       " << endl;
    escribirFactura << "===============================" << endl;
    escribirFactura << "Nombre del Cliente: " << nombreCliente << endl;
    escribirFactura << "Tipo de Cliente: " << tipoCliente << endl;
    escribirFactura << "Nombre de Combustible: " << nombreCombustible << endl;
    escribirFactura << "Litros Comprados: " << litrosComprados << " litros" << endl;
    escribirFactura << "Precio por Litro: $" << precioGasolina << endl;
    escribirFactura << "Descuento Aplicado: $" << descuento << endl;
    escribirFactura << "Total a Pagar sin Descuento: $" << total << endl;
    escribirFactura << "Total a Pagar con Descuento: $" << totalConDescuento << endl;
    escribirFactura << "===============================" << endl;
    escribirFactura.close();
}

void Facturacion::verUltimafactura() {
    ifstream leerFactura("UltimaFactura.txt");
    string linea;
    while (getline(leerFactura, linea)) {
        cout << linea << endl;
    }
}

void Facturacion::calcularCombustibleMasVendido( Combustible gasolina1,  Combustible gasolina2,  Combustible gasolina3) {
    int ventas1 = gasolina1.getTotalVentasGasolinaUnitaria();
    int ventas2 = gasolina2.getTotalVentasGasolinaUnitaria();
    int ventas3 = gasolina3.getTotalVentasGasolinaUnitaria();

    if (ventas1 >= ventas2 && ventas1 >= ventas3) {
        if (ventas1 == ventas2 && ventas1 == ventas3) {
            combustibleMasVendido = "Empate entre: " + gasolina1.getNombreCombustible() + ", " + gasolina2.getNombreCombustible() + ", " + gasolina3.getNombreCombustible();
        } else if (ventas1 == ventas2) {
            combustibleMasVendido = "Empate entre: " + gasolina1.getNombreCombustible() + " y " + gasolina2.getNombreCombustible();
        } else if (ventas1 == ventas3) {
            combustibleMasVendido = "Empate entre: " + gasolina1.getNombreCombustible() + " y " + gasolina3.getNombreCombustible();
        } else {
            combustibleMasVendido = gasolina1.getNombreCombustible();
        }
    } else if (ventas2 >= ventas1 && ventas2 >= ventas3) {
        if (ventas2 == ventas3) {
            combustibleMasVendido = "Empate entre: " + gasolina2.getNombreCombustible() + " y " + gasolina3.getNombreCombustible();
        } else {
            combustibleMasVendido = gasolina2.getNombreCombustible();
        }
    } else {
        combustibleMasVendido = gasolina3.getNombreCombustible();
    }
    cout << "Se actualizo el tipo de gasolina mas vendido " << endl;
}

bool Facturacion::CalcularSiCuentaConCombustible( Combustible gasolina)  {
    return gasolina.getCantidadDisponible() != 0;
}