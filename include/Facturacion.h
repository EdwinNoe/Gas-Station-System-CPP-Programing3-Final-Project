#ifndef FACTURACION_H
#define FACTURACION_H

#include <iostream>
#include <fstream>
#include <string>

#include "./Combustible.h" 

using namespace std;

class Facturacion {
    private:
        static double totalGanancias;
        static string combustibleMasVendido;

    public:
        // Constructor
        Facturacion();

        // Getters
        double getTotalGanancias();
        string getCombustibleMasVendido();

        // Setters
        void setTotalGanancias(double ganancias);
        void setCombustibleMasVendido( string combustible);

        // Métodos personalizados
        void imprimirFactura( string nombreCliente,  string tipoCliente, string nombreCombustible, double litrosComprados, double descuento, double precioGasolina);
        void verUltimafactura() ;
        void calcularCombustibleMasVendido( Combustible gasolina1,  Combustible gasolina2,  Combustible gasolina3);
        bool CalcularSiCuentaConCombustible( Combustible gasolina) ;
};

#endif 